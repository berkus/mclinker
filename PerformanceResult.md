# Performance Result #

#### Linking Speed ####
Comparing to GNU ld, MCLinker steadily runs about x2 faster. With -S option, MCLinker is the fastest linker. This is because MCLinker is designed for on-device linking: has better memory locality and does not perform unnecessary functions.

<img src='http://mclinker.googlecode.com/files/perf-comparison-w-S.png' height='300' />

So far, MCLinker does not strip unused debug info. This makes MCLinker emits larger output than Google gold and GNU ld, and slows down the linking time. We will support this feature at the after releases soon. The following data is the performance comparison without -S option.

<img src='http://mclinker.googlecode.com/files/perf-comparision-wo-S.png' height='300' />

Without -S option, MCLinker emits larger output and becomes slower than Google gold, but still about x2 faster than GNU ld.

#### MCLinker 2.0 **RockBull** vs 1.6 **Tarako** ####
There are two reasons that we strongly recommend you move forward on MCLinker 2.0 RockBull.
  1. 2.0 is x30 faster than 1.6
  1. 2.0 provides more APIs for using MCLinker as a modular linker.

In order to eliminate the developing cost, MCLinker before version 1.6 used a slow but easy section merging algorithm.

<img src='http://mclinker.googlecode.com/files/perf-2.0-vs-1.6.JPG' height='300' />