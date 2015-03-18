# Related Work #
There are several existing linkers, including GNU ld and Google gold. Both of them are well-known linkers with unique features. We adopt the strengths of both GNU ld and Google gold linker, and fulfill the goal of MCLinker, a fast and format-independent linker with low memory usage.



Generally, the works of a linker can be classified into some steps:

  * Parse options on the command line
  * Parse link scripts to read commands of linking
  * Symbol resolution
  * Relocation of instructions, data, symbols and sections
  * Output the linked file



Different linkers have their own linking algorithms and data structures to achieve these works. Below we discuss the linking flow of GNU ld and Google gold.



### GNU ld ###
GNU ld is designed for the portable manipulation to support various formats of object files. Object files in various formats are represented in a common abstraction, provided by the Binary File Descriptor (BFD) library. The main job of GNU ld is to read and parse link scripts, that is, it behaves as a frontend of the BFD library, and the real linking is done by BFD.

In the linking flow of GNU ld, it does the following steps iteratively:

  * Read and load the input files
  * Do format checking
  * Perform symbol resolution
  * Apply relocation

![https://lh6.googleusercontent.com/-jGIGLJa6m1E/TqobAxOEVMI/AAAAAAAAAbU/hqX2t2eyklw/s800/ld.png](https://lh6.googleusercontent.com/-jGIGLJa6m1E/TqobAxOEVMI/AAAAAAAAAbU/hqX2t2eyklw/s800/ld.png)

If more files are included during above steps, GNU ld iteratively performs linking process upon those files until all files are linked.

BFD allows information lost during canonicalization. Consequently, GNU ld suffers from the extra overhead to restore the lost information. Since BFD is mainly designed for COFF, ELF cannot be supported well in BFD. GNU ld is slower while linking ELF files, because BFD cannot take the advantage from ELF features.

Besides, during the linking flow of GNU ld, it needs more time to walk over the entire symbol table. Consequently, the overall linking time is also increased. For example, GNU ld applies relocations before the final values of symbols are known. So it provides a complicated mechanism which spends a lot of time on walking through the whole symbol table to track the relocations applied to symbols.




### Google gold ###

Google gold is a linker designed especially for ELF format. The main idea of gold is to be a fast linker. Therefore, the architecture of gold is significantly different from GNU ld.


Google gold separates linking processes into two stages:

  * Stage 1: Iteratively do the following steps until all files are read.
    * Read and load input files.
    * Resolve symbols while checking formats of input files.

  * Stage 2: Perform relocation in parallel.

![https://lh5.googleusercontent.com/-4mBnEJWOd8w/TqobAxf3hOI/AAAAAAAAAbQ/Kp4CfWrrduM/s800/gold.png](https://lh5.googleusercontent.com/-4mBnEJWOd8w/TqobAxf3hOI/AAAAAAAAAbQ/Kp4CfWrrduM/s800/gold.png)

The processes of reading and parsing the input files, checking formats and resolving symbols are clearly separated from the relocation. While all the input files are read and all data ready, gold can perform relocation in parallel.



Google gold adopts several methods to improve the performance:

  * Unlike GNU ld, the linking flow of Google gold is well designed for ELF. Google gold applies relocation at the last step of linking and limits the number of times on walking the symbol table.
  * Google gold merges several processes together to reduce the number of walks on the symbol table.
  * Google gold is written in C++. The feature of template specialization offered by C++ helps to avoid the time consuming due to byte swapping.
  * Google gold is designed for multithread. The linking process of gold is split into several tasks with threads for speeding up linking, e.g., reading multiple input symbol tables in the same time. This improves performance in some cases.

### LLVM ObjectFile Project ###
_This field is under construction._

### lld ###
