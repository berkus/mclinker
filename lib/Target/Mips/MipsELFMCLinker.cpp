//===- MipsELFMCLinker.cpp ------------------------------------------------===//
//
//                     The MCLinker Project
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#include "MipsELFMCLinker.h"

#include <mcld/CodeGen/SectLinkerOption.h>

using namespace mcld;

MipsELFMCLinker::MipsELFMCLinker(SectLinkerOption &pOption,
                                 TargetLDBackend &pLDBackend,
                                 mcld::Module& pModule,
                                 MemoryArea& pOutput)
  : MCLinker(pOption, pLDBackend, pModule, pOutput) {
  LinkerConfig &config = pOption.config();
  // set up target-dependent constraints of attibutes
  config.attrFactory().constraint().enableWholeArchive();
  config.attrFactory().constraint().enableAsNeeded();
  config.attrFactory().constraint().setSharedSystem();

  // set up the predefined attributes
  config.attrFactory().predefined().unsetWholeArchive();
  config.attrFactory().predefined().unsetAsNeeded();
  config.attrFactory().predefined().setDynamic();
}

MipsELFMCLinker::~MipsELFMCLinker()
{
}
