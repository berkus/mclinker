# Tutorial on MCLinker and LLVM #

## <font color='red'><b>Call for Participation!</b> </font>  ##

[CGO, 2013](http://www.cgo.org/cgo2013/), _Tutorial on MCLinker and LLVM_, <br>
February 24, Sunday morning <br>
Shenzhen, China <br>

<h2>Abstract</h2>
The tutorial targets both researchers and students who are interested in using LLVM and MCLinker. This tutorial provides a detailed look at LLVM and MCLinker, esp., how to use them and how they work together.<br>
<br>
<h2>About MCLinker and LLVM</h2>

Generating a program from source code can be simply separated into two processes - compilation and linking.<br>
<br>
LLVM is a compiler infrastructure that is designed for optimizing programs in all stages of compilation, from source code to relocatable objects. It is an integral part of Apple's development tools. It's also the core of several modern languages and compilers, such as Android Renderscript and many OpenCL JIT compilers.<br>
<br>
MCLinker is a toolchain infrastructure for optimizing programs in all stages of linking, from relocatable objects to executable programs. It is one of the standard linkers in Google Android system since Jelly Bean. MCLinker, designed for on-device linking, is the fastest and smallest linker in the open-source area.<br>
<br>
Combining LLVM and MCLinker, we have a versatile tool, or say a Swiss army knife. For example, compiler developers can fully control all stages of compilation and linking of a program. The other example, virtual machine developers can easily leverage operating system's loader. They do not need to handle with all details of linking and loading any more.<br>
<br>
<h2>Tutorial Topics</h2>
A summary of topics to be covered:<br>
<ul><li>the architecture of MCLinker and LLVM,<br>
</li><li>the details of intermediate representations of MCLinker and LLVM, and<br>
</li><li>the interaction between MCLinker and LLVM.</li></ul>

<h2>Target Audience</h2>
<ul><li>Compiler developers<br>
</li><li>Virtual machine developers<br>
</li><li>Researchers in compiler theory and practice, especially those are interested in ahead-of-time compilation<br>
</li><li>Students interested in compiler theory and/or who are taking compiler courses</li></ul>

<h2>Slides</h2>
Click <a href='http://code.google.com/p/mclinker/downloads/detail?name=Tutorial-on-MCLinker-and-LLVM-cgo2013.tar&can=2&q=#makechanges'>here</a> to download the slides<br>
<hr />
<h2>Agenda</h2>
<b>Overall 3 hours</b> (8:30 ~ 12:00)<br>
<br>
<h3>Part I: <font color='#003366'>Introduction to LLVM and MCLinker</font> <sub>(8:30AM - 9:00AM, 30 min)</sub></h3>

The first part of the tutorial provides an overview to LLVM and MCLinker infrastructures.<br>
<ul><li>An overview of compilation and linking Flow<br>
</li><li>From sources to objects - LLVM Machine Code Layer<br>
</li><li>From objects to a program - MCLinker</li></ul>

<h3>Part II: <font color='#003366'>LLVM Intermediate Representation </font><sub>(9:00AM - 10:00AM, 50 min)</sub></h3>

The second part, we focus on LLVM IR and Machine Code Layer. LLVM Machine Code Layer is the integrated assembler of LLVM. It helps LLVM to treat assembly code and object code in the same view. All magics start from here.<br>
<br>
<ul><li>LLVM's lowering flow<br>
</li><li>The intermediate representations (IR) and LLVM IRBuilder<br>
</li><li>LLVM Machine Code Layer</li></ul>

<hr />
<h4><font color='#663300'> Tea Break 10:00AM - 10:30AM </font></h4>
<hr />
<h3>Part III: <font color='#003366'>MCLinker Intermediate Representation </font><sub>(10:30AM ~ 11:20AM, 50 min)</sub></h3>

In this part, we move our concentration on linking and MCLinker. MCLinker came from the idea of reusing LLVM Machine Code Layer, but eventually, MCLinker defines its own IR. We will explain the similarity and difference between MCLinker IR and LLVM Machine Code Layer.<br>
<br>
<ul><li>MCLinker's linking flow<br>
</li><li>The intermediate representations (IR) and MCLinker IRBuilder<br>
</li><li>Experimental Results of MCLinker</li></ul>

<h3>Part IV: <font color='#003366'>A Simplest Ahead-of-Time Compilation Virtual Machine </font><sub>(11:20AM ~ 12:00AM, 40 min)</sub></h3>

The last part gives an example to connect LLVM and MCLinker. We illustrate how to make an ahead-of-time (AOT) virtual machine by connecting LLVM and MCLinker.<br>
<br>
<ul><li>Set up LLVM and MCLinker<br>
</li><li>Connect LLVM and MCLinker<br>
</li><li>Add and read your own metadata<br>
</li><li>Compile, link, and run</li></ul>

<hr />
<h2>Presenter Bio</h2>
Luba Tang, <a href='http://www.mediatek.com/en/index.php'>MediaTek, Inc</a>. The software architect of MCLinker.<br>
<br>
Luba Tang received his M.S. degree in computer science from the National Tsing-Hua University, Taiwan. He has been a Ph.D. student in computer science department of National Tsing-Hua University, Taiwan since 2007. At the same time, he has been working in the compiler groups at Marvell, Inc. and MediaTek, Inc. since 2010. His research interests include both electronic system level (ESL) design and compilers. He had focused on iterative compiler, ahead-of-time compiler, and link-time optimization. His most recent work focus is on dynamic linking and link-time optimization. He was the chief programmer of Starfish DSP simulator, the original author of Marvell iterative compiler, and also the software architect of MCLinker.<br>
<br>
Wei-Ren Chen, Taiwan LLVM enthusiast.<br>
<br>
Wei-Ren Chen received his M.S. degree in computer science from the<br>
National Chiao Tung University, Taiwan. He has been a research assistant<br>
in Institute of Information Science, Academia Sinica, Taiwan (R.O.C.)<br>
since Oct. 2010. His research interests include Programming Language,<br>
Compiler, Operating System and Virtual Machine.<br>
<br>
<h2>Oragnizers</h2>
<ul><li>Luba Tang, <a href='http://www.mediatek.com/en/index.php'>MediaTek, Inc.</a> (Presenter),<br>
</li><li>Wei-Ren Chen, <a href='http://www.sinica.edu.tw/main_e.shtml'>Academia Sinica</a>, and<br>
</li><li>Koan-Sin Tan, PhD, <a href='http://www.mediatek.com/en/index.php'>MediaTek, Inc.</a>