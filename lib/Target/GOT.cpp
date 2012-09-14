//===- GOT.cpp ------------------------------------------------------------===//
//
//                     The MCLinker Project
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#include <llvm/Support/Casting.h>

#include <mcld/LD/LDSection.h>
#include <mcld/Target/GOT.h>
#include <mcld/Support/MsgHandling.h>

#include <cstring>
#include <cstdlib>

using namespace mcld;

//===----------------------------------------------------------------------===//
// GOT::Entry
//===----------------------------------------------------------------------===//
GOT::Entry::Entry(uint64_t pContent, size_t pEntrySize, SectionData* pParent)
  : TargetFragment(Fragment::Target, pParent),
    f_Content(pContent),
    m_EntrySize(pEntrySize) {
}

GOT::Entry::~Entry()
{
}

//===----------------------------------------------------------------------===//
// GOT
//===----------------------------------------------------------------------===//
GOT::GOT(LDSection& pSection,
         SectionData& pSectionData,
         size_t pEntrySize)
  : m_Section(pSection),
    m_SectionData(pSectionData),
    f_EntrySize(pEntrySize),
    m_pLast(NULL) {
}

GOT::~GOT()
{
}

size_t GOT::getEntrySize() const
{
  return f_EntrySize;
}

void GOT::reserve(size_t pNum)
{
  Entry* entry = NULL;

  for (size_t i = 0; i < pNum; i++) {
    entry = new Entry(0, f_EntrySize, &m_SectionData);
  }
}

GOT::Entry* GOT::consume()
{
  if (NULL == m_pLast) {
    assert(!empty() && "Consume empty GOT entry!");
    m_pLast = llvm::cast<Entry>(&m_SectionData.front());
    return m_pLast;
  }

  m_pLast = llvm::cast<Entry>(m_pLast->getNextNode());
  return m_pLast;
}

void GOT::finalizeSectionSize()
{
  m_Section.setSize(m_SectionData.size() * f_EntrySize);
}

