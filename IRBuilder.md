# IRBuilder #

MCLinker can be used as a linker library. It provides a set of APIs to achieve the whole linking process.

The linking APIs are collected in IRBuilder in ${MCLinker}/include/mcld/IRBuilder.h

Below is a simple example. The linker command, _ld.mcld --mtriple="armv7-none-linux-gnueabi" -L/usr/local/lib ./hello.o -lc -o hello.out_, is equal to the following series of API calls.

```
#include <mcld/Environment.h>
#include <mcld/Module.h>
#include <mcld/IRBuilder.h>
#include <mcld/Linker.h>
#include <mcld/LinkerConfig.h>
#include <mcld/LinkerScript.h>


using namespace mcld;

/// This example is equal to the command:
/// ld.mcld --mtriple="armv7-none-linux-gnueabi" -L/usr/local/lib ./hello.o -lc -o hello.out
int main(int argc, char* argv[]) {
  
  Initialize();
  Linker linker;
  LinkerScript script;
  Module module("hello", script);
  
  // --mtriple="armv7-none-linux-gnueabi"
  LinkerConfig config("armv7-none-linux-gnueabi"); 
  
  linker.emulate(script, config);
 
  // set output type to executable
  config.setCodeGenType(LinkerConfig::Exec);

  // -L/usr/local/lib
  script.directories().insert("/usr/local/lib");  

  IRBuilder builder(module, config);

  // ./hello.o
  builder.ReadInput("hello", "./hello.o");

  // -lc
  builder.ReadInput("c");

  if (linker.link(module, builder)) {
    // -o hello.out
    linker.emit(module, "hello.out"); 
  }

  Finalize();
}

```