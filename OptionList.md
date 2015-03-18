# Options of MCLinker #

Following is the command line options supported by MCLinker. The options are compatible with gnu-ld. MCLinker is currently under construction and if you require any unsupported options, please report to [Issues](http://code.google.com/p/mclinker/issues).

| **Option** | **Description** |
|:-----------|:----------------|
| -Bdynamic                               | Link against dynamic library |
| -Bgroup                                 | Info the dynamic linker to lookups only inside the group.|
| -Bstatic                                | Link against static library|
| -Bsymbolic                              | Bind references within the shared library.|
| -EB                                     | Link big-endian objects. This affects the output format.|
| -EL                                     | Link little-endian objects. This affects the output format.|
| -F=`<name>`                               | Filter for shared object symbol table|
| -G=`<int>`                                | Set the maximum size of objects to be optimized using GP|
| -L=`<searchdir>`                          | Add [searchdir](searchdir.md) to the list of search paths|
| -M                                      | Print a link map to the standard output.|
| -O=`<char>`                               | Optimization level. [-O0, -O1, -O2, or -O3] (default = '-O2')|
| -Qy                                     | This option is ignored for SVR4 compatibility|
| -T=`<file>`                               | Linker script|
| -Tbss=`<uint>`                            | Set the address of the bss segment|
| -Tdata=`<uint>`                           | Set the address of the data segment|
| -Ttext=`<uint>`                           | Set the address of the text segment|
| -V                                      | Display the version number for MCLinker.|
| -Y=`<default-search-path>`                | Add path to the default library search path|
| -add-needed                             | --add-needed causes DT\_NEEDED tags are always emitted for those libraries from DT\_NEEDED tags. This is the default behavior.|
| -allow-multiple-definition              | Allow multiple definition|
| -as-needed                              | This option affects ELF DT\_NEEDED tags for dynamic libraries mentioned on the command line after the --as-needed option.|
| -b <pre>  =binary</pre>                                     | set input format <br><pre>  read in binary machine code.</pre>  <br>
<tr><td> -build-id=<code>&lt;style&gt;</code>                       </td><td> Request creation of ".note.gnu.build-id" ELF note section.</td></tr>
<tr><td> -color<pre>  =never</pre> <pre>  =always</pre> <pre>  =auto</pre>                                  </td><td> Surround the result strings with the marker <pre>  do not surround result</pre> <pre>  always surround results, even the output is a plain file</pre> <pre>  surround result strings only if the output is a tty</pre></td></tr>
<tr><td> -d                                      </td><td> Define common symbol</td></tr>
<tr><td> -defsym=<code>&lt;symbol=expression&gt;</code>             </td><td> Define a symbol</td></tr>
<tr><td> -discard-all                            </td><td> Delete all local symbols.</td></tr>
<tr><td> -discard-locals                         </td><td> Delete all temporary local symbols.</td></tr>
<tr><td> -dynamic-linker=<code>&lt;Program&gt;</code>               </td><td> Set the name of the dynamic linker.</td></tr>
<tr><td> -e=<code>&lt;entry&gt;</code>                              </td><td> Use the explicit symbol as the entrance of your program.</td></tr>
<tr><td> -eh-frame-hdr                           </td><td> Request creation of ".eh_frame_hdr" section and ELF "PT_GNU_EH_FRAME" segment header.</td></tr>
<tr><td> -enable-new-dtags                       </td><td> Enable use of DT_RUNPATH and DT_FLAGS</td></tr>
<tr><td> -end-group                              </td><td> stop recording a group of archives</td></tr>
<tr><td> -error-limit=<code>&lt;int&gt;</code>                      </td><td> limits the maximum number of erros.</td></tr>
<tr><td> -exclude-libs=<code>&lt;lib1,lib2,...&gt;</code>           </td><td> Exclude libraries from automatic export</td></tr>
<tr><td> -export-dynamic                         </td><td> Export all dynamic symbols</td></tr>
<tr><td> -f=<code>&lt;name&gt;</code>                               </td><td> Auxiliary filter for shared object symbol table</td></tr>
<tr><td> -fatal-warnings                         </td><td> turn all warnings into errors</td></tr>
<tr><td> -filetype=<code>&lt;type&gt;</code>  <pre>  =obj</pre> <pre>  =dso</pre> <pre>  =exe</pre> <pre>  =bin</pre> <pre>  =null</pre>  </td><td> Choose a file type (not all types are supported by all targets): <pre>  Emit a relocatable object ('.o') file </pre><pre>  Emit an dynamic shared object ('.so') file </pre><pre>  Emit an executable ('.exe') file </pre><pre>  Emit a binary file </pre><pre>  Emit nothing for performance testing</pre> </td></tr>
<tr><td> -fix-cortex-a8                          </td><td> Enable Cortex-A8 Thumb-2 branch erratum fix</td></tr>
<tr><td> -fuse-ld=<code>&lt;string&gt;</code>                       </td><td> Ignored for GCC/collect2 linker compatibility.</td></tr>
<tr><td> -gc-sections                            </td><td> Enable garbage collection of unused input sections.</td></tr>
<tr><td> -hash-style <pre>  =sysv</pre> <pre>  =gnu</pre> <pre>  =both</pre>                             </td><td> Set the type of linker's hash table(s). <pre>  classic ELF .hash section</pre> <pre>  new style GNU .gnu.hash section</pre> <pre>  both the classic ELF and new style GNU hash tables</pre></td></tr>
<tr><td> -icf <pre>  =none</pre><pre>  =all</pre><pre>  =safe</pre>                                   </td><td> Identical Code Folding <pre>  do not perform cold folding</pre><pre>  always preform cold folding</pre><pre>  Folds those whose pointers are definitely not taken.</pre></td></tr>
<tr><td> -l=<code>&lt;namespec&gt;</code>                           </td><td> Add the archive or object file specified by namespec to the list of files to link.</td></tr>
<tr><td> -ld-generated-unwind-info               </td><td> Request creation of unwind info for linker generated code sections like PLT.</td></tr>
<tr><td> -m=<code>&lt;emulation&gt;</code>                          </td><td> Set GNU linker emulation</td></tr>
<tr><td> -march=<code>&lt;string&gt;</code>                         </td><td> Architecture to generate code for (see --version)</td></tr>
<tr><td> -mattr=<code>&lt;a1,+a2,-a3,...&gt;</code>                 </td><td> Target specific attributes (-mattr=help for details)</td></tr>
<tr><td> -mcpu=<code>&lt;cpu-name&gt;</code>                        </td><td> Target a specific cpu type (-mcpu=help for details)</td></tr>
<tr><td> -mtriple=<code>&lt;string&gt;</code>                       </td><td> Override target triple for module</td></tr>
<tr><td> -nmagic                                 </td><td> Do not page align data</td></tr>
<tr><td> -no-add-needed                          </td><td> --no-add-needed causes DT_NEEDED tags will never be emitted for those libraries from DT_NEEDED tags</td></tr>
<tr><td> -no-as-needed                           </td><td> Turn off the effect of the --as-needed option for subsequent dynamic libraries</td></tr>
<tr><td> -no-fatal-warnings                      </td><td> do not turn warnings into errors</td></tr>
<tr><td> -no-gc-sections                         </td><td> disable garbage collection of unused input sections.</td></tr>
<tr><td> -no-ld-generated-unwind-info            </td><td> Don't create unwind info for linker generated sections to save size</td></tr>
<tr><td> -no-print-gc-sections                   </td><td> disable --print-gc-sections</td></tr>
<tr><td> -no-undefined                           </td><td> Do not allow unresolved references</td></tr>
<tr><td> -no-warn-mismatch                       </td><td> Allow linking together mismatched input files.</td></tr>
<tr><td> -no-whole-archive                       </td><td> Turn off the effect of the --whole-archive option for subsequent archive files.</td></tr>
<tr><td> -nostdlib                               </td><td> Only search lib dirs explicitly specified on cmdline</td></tr>
<tr><td> -o=<code>&lt;filename&gt;</code>                           </td><td> Output filename</td></tr>
<tr><td> -oformat                                </td><td> set output format</td></tr>
<tr><td>   =binary                               </td><td>   generate binary machine code.</td></tr>
<tr><td> -omagic                                 </td><td> Do not page align data, do not make text readonly</td></tr>
<tr><td> -pie                                    </td><td> Emit a position-independent executable file</td></tr>
<tr><td> -plugin=<code>&lt;plugin&gt;</code>                        </td><td> Load a plugin library.</td></tr>
<tr><td> -plugin-opt=<code>&lt;option&gt;</code>                    </td><td> Pass an option to the plugin.</td></tr>
<tr><td> -portable=<code>&lt;symbol&gt;</code>                      </td><td> Use a portable function fo symbol.</td></tr>
<tr><td> -print-gc-sections                      </td><td> List all sections removed by garbage collection.</td></tr>
<tr><td> -relocatable                            </td><td> Generate relocatable output</td></tr>
<tr><td> -rpath=<code>&lt;dir&gt;</code>                            </td><td> Add a directory to the runtime library search path</td></tr>
<tr><td> -rpath-link=<code>&lt;dir&gt;</code>                       </td><td> Add a directory to the link time library search path</td></tr>
<tr><td> -section-start=<code>&lt;Set address of section&gt;</code> </td><td> Locate a output section at the given absolute address</td></tr>
<tr><td> -shared                                 </td><td> Create a shared library.</td></tr>
<tr><td> -soname=<code>&lt;name&gt;</code>                          </td><td> Set internal name of shared library</td></tr>
<tr><td> -start-group                            </td><td> start to record a group of archives</td></tr>
<tr><td> -strip-all                              </td><td> Omit all symbol information from the output file.</td></tr>
<tr><td> -strip-debug                            </td><td> Omit debugger symbol information from the output file.</td></tr>
<tr><td> -sysroot=<code>&lt;directory&gt;</code>                    </td><td> Use directory as the location of the sysroot</td></tr>
<tr><td> -t                                      </td><td> Print the names of the input files as ld processes them.</td></tr>
<tr><td> -u=<code>&lt;symbol&gt;</code>                             </td><td> Force symbol to be undefined in the output file</td></tr>
<tr><td> -verbose=<code>&lt;int&gt;</code>                          </td><td> Display the version number for ld and list the linker emulations supported.</td></tr>
<tr><td> -version                                </td><td> Display the version of this program</td></tr>
<tr><td> -version-script=<code>&lt;Version script&gt;</code>        </td><td> Version script.</td></tr>
<tr><td> -warn-common                            </td><td> warn common symbol</td></tr>
<tr><td> -warn-shared-textrel                    </td><td> Warn if adding DT_TEXTREL in a shared object.</td></tr>
<tr><td> -warning-limit=<code>&lt;int&gt;</code>                    </td><td> limits the maximum number of warnings.</td></tr>
<tr><td> -whole-archive                          </td><td> For each archive mentioned on the command line after the --whole-archive option, include all object files in the archive.</td></tr>
<tr><td> -wrap=<code>&lt;symbol&gt;</code>                          </td><td> Use a wrap function fo symbol.</td></tr>
<tr><td> -z=<code>&lt;keyword&gt;</code>                            </td><td> The -z options for GNU ld compatibility.</td></tr>