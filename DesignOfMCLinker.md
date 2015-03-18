# The Design of MCLinker #

To design a fast and efficient linker, the linking algorithms of MCLinker are mainly following Google gold. Moreover, to support various formats of object files, MCLinker has an intermediate representation (IR) of input files, which adopts Machine Code (MC) layer of LLVM. The procedure which called _**Normalization**_ in MCLinker presents the translation from input files to MCLinker IR.



To simplify the logic of linking, MCLinker separates linking into three stages:

  * Stage1: Read and load input files. Check formats.

  * Stage2: Symbol resolution

  * Stage3: Perform relocation

![https://lh5.googleusercontent.com/-lLYZQeejfLE/TqobA4f_LTI/AAAAAAAAAbY/M7Tk6879MYQ/s800/mclinker.png](https://lh5.googleusercontent.com/-lLYZQeejfLE/TqobA4f_LTI/AAAAAAAAAbY/M7Tk6879MYQ/s800/mclinker.png)

MCLinker reads all input files before starting symbol resolution and relocation. In the first stage, the input files and all the becoming included files (recognized from options or ldscript) are read and checked.



### Normalization ###

MCLinker maintains a tree of input files to record all the input files. Each vertex of the tree represents an input file and records the file path. MCLinker first reads input files from command lines and form the tree. Then, it recognizes link scripts and archives from input files which may bring more input files and general options. MCLinker read the link scripts or archives to create another tree. At the end, MCLinker merges all trees into one. By traversing the tree, the information of sections and symbol tables are extracted and form the MCLinker IR, which saves the becoming linking processes from the differential formats of object files.


### Architecture ###

MCLinker is an integrated linker for LLVM. "Integrated" means MCLinker has an adapter to LLVM. MC Layer uses a function pass, called **AsmPrinter**, as an adapter to the standard compilation flow. Like MC Layer, MCLinker also provides a function pass, called **SectLinker**, to be integrated into the last stage of the standard compilation flow.

Traditional toolchain has a linker driver to prepare parameters for linker. In GCC, collect2 is one of such tools to prepare parameters such as _sysroot_, the path of glibc, and so on. In MCLinker, **MCLDDriver** plays the same role as collect2 to prepare all implicit parameters for MCLinker.

**MCLinker**, a class with the same name as the project, provides numerous APIs to perform major linking tasks, such as symbol resolution, applying relocations, sections merge, and so on. These APIs are defined at high level abstraction which is target and format independent. Those target and format dependent operations are encapsulated in another class, called **TargetLDBackend**. Therefore, MCLinker can perform linking at a high level abstraction without the concern about targets and formats.

In order to simplify linking and improve performance, MCLinker defines its own symbol data structures, called **LDSymbol**, instead of using MCSymbol directly. Symbols defined in LLVM are separated into two different classes – MCSymbol and MCSymbolData, and they are very different from the symbols' definition in most object files. If a linker adopts them as the data structure of symbols, it needs extra overhead to convert symbols of object files into MCSymbol and MCSymbolData. In order to overcome this problem, the definition of LDSymbol is close to the symbols' definition in the object files, and the overhead of conversion is low. Actually, not only reading object files, symbol resolution also becomes faster and easier due to shifting the definition of symbols to LDSymbol.

MCLinker also defines a unified representation for relocation entries, called **LDRelocation**, since LLVM does not provide it. The design of relocation in MCLinker is similar to the other portable linkers. Readers of different formats convert format-dependent relocation entries into general LDRelocations. All targets need to provide functions for applying relocations. MCLinker connects the functions with corresponding LDRelocations during the initialization.

Please refer to [Downloads](http://code.google.com/p/mclinker/downloads/list) for more information about the design of MCLinker.