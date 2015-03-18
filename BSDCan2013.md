# MCLinker for BSD #

## <font color='red'><b>Call for Participation!</b> </font>  ##
[Using MCLinker as the system linker](http://www.bsdcan.org/2013/schedule/events/390.en.html), <br>
<a href='http://www.bsdcan.org/2013/'>BSDCan 2013</a>, <br>
May 17, 2013 <br>
Ottawa, Canada<br>
<br>
<h2>Abstract</h2>
FreeBSD has moved the toolchain forward since the 2010 BSDCan Toolchain Summit. As the clang and llvm compiler infrastructure is imported into FreeBSD, a BSD-like licensed linker is essentially needed to complete the BSD toolchain infrastructure. This talk will introduce MCLinker, the first practical BSD licensed linker, with its current status and future possibilities in BSD.<br>
<br>
MCLinker is a toolchain infrastructure designed for optimizing programs in all stages of linking. Currently, the particular focus of MCLinker is on on-device linking. Compared to the traditional linkers (e.g., GNU ld), MCLinker performs much faster linking with lower memory usage. MCLinker has been one of the standard linkers in Android since the Jelly Bean release. We are currently working on the linking of FreeBSD based system.<br>
<br>
<h2>Presenter</h2>
Chinyen Chou, <a href='http://www.mediatek.com/en/index.php'>MediaTek, Inc</a>.<br>
<br>
One of the major developers in the MCLinker project. Chinyen Chou currently focuses on linker implementation and optimization.