# Getting Started #

## Build MCLinker ##
Follow the steps below to build MCLinker project.

  1. Download MCLinker source code into ${MCLINKER\_SRC} directory. See [Source](http://code.google.com/p/mclinker/source/checkout).
```
  git clone https://code.google.com/p/mclinker/ ${MCLINKER_SRC}
```
  1. Find the specific LLVM revision or branch in `README'. For example, you may download LLVM trunk if you are working on master.
```
  svn co http://llvm.org/svn/llvm-project/llvm/trunk llvm
  cd llvm
```
  1. Build LLVM and install to directory ${LLVM\_INSTALL}
```
  cd ../           #go back to where you started
  mkdir llvm-build
  cd llvm-build
  ../llvm/configure --prefix=${LLVM_INSTALL}
  make all install
```

Since there is a bug in LLVM cmake script, we suggest you using auto-tools rather than cmake. see http://llvm.org/bugs/show_bug.cgi?id=14200

  1. Setup environmnent
```
  cd ${MCLINKER_SRC}
```
  1. Run autogen if there is no `configure' script
```
  ./autogen.sh
```
  1. To configure MCLinker, create a build directory `${MCLINKER_BUILD}` and run the configuration
```
  cd ${MCLINKER_BUILD}
  ${MCLINKER_SRC}/configure --prefix=${MCLINKER_INSTALL} --with-llvm-config=${LLVM_INSTALL}/bin/llvm-config
```
  1. Build and install MCLinker.
```
  make && make install
```

> The configuration argument _--with-llvm-config_ specifies the config of llvm. For more configuration arguments, please refer to ${MCLINKER\_SRC}_/configure --help_.

> Besides, MCLinker provides some candies for developing in _envsetup.sh_. You can simply use command _mk_ to build MCLinker everywhere, even not under your home directory.
```
  source ./scripts/envsetup.sh
  mk
```

## Run ##
MCLinker builds shared objects, executables or partial links objects according to the given options. MCLinker supports several backends. Use _-march_ or _-m_ to specify the target device type.

### synopsis ###
ld.mcld [**options**] _objfile_

### usage ###
Build shared object from object files.
```
  ld.mcld -shared -march=arm ${filename}.o -sysroot=${ANDROID_SYSROOT} -o ${outputfile}.so
```

For more supported options, please refer to _ld.mcld --help_

## Run Unit Test ##
MCLinker contains a set of unit tests inside the MCLinker repository. Unit tests help to test the specific class and its functions in MCLinker without running the whole program.

To build and run unit tests:
```
  cd ${MCLINKER_BUILD}
  make unittests
```

[Unit Test](Unittest.md) gives the tutorial of creating and writing a unit test for MCLinker.

## Run Regression Tests ##
MCLinker also contains a set of regression tests inside the repository,  under ${MCLINKER\_SRC}/test. The regression tests help to verify the specific features of MCLinker. To run the regression tests, simply go into the build directory and run the command _make check_.
```
  cd ${MCLINKER_BUILD}
  make check
```

[Unit Test](Unittest.md) gives the tutorial of creating and writing a unit test for MCLinker.

## Run Coding Style Checker ##
MCLinker follows [Google's C++ style](http://google-styleguide.googlecode.com/svn/trunk/cppguide.xml), and for the include style, it follows [LLVM include style](http://llvm.org/docs/CodingStandards.html#include-style). In MCLinker, cpplint is involved to check the coding style. To run the checker, go into the build directory and run the command _make cpplint_.
```
  cd ${MCLINKER_BUILD}
  make cpplint
```

## Bug Reports ##
Please report bugs and problems to  [Issues](http://code.google.com/p/mclinker/issues). Any suggestion for improvement is also welcome.