//===- ELFReader.h --------------------------------------------------------===//
//
//                     The MCLinker Project
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#ifndef MCLD_ELF_READER_INTERFACE_H
#define MCLD_ELF_READER_INTERFACE_H
#ifdef ENABLE_UNITTEST
#include <gtest.h>
#endif

#include <llvm/ADT/StringRef.h>
#include <llvm/Support/ELF.h>
#include <llvm/Support/Host.h>
#include <mcld/MC/MCLDInput.h>
#include <mcld/MC/MCLinker.h>
#include <mcld/LD/ResolveInfo.h>
#include <mcld/LD/LDContext.h>
#include <mcld/Target/GNULDBackend.h>
#include <mcld/Support/MemoryRegion.h>

namespace mcld
{

/** \class ELFReaderIF
 *  \brief ELFReaderIF provides common interface for all kind of ELF readers.
 */
class ELFReaderIF
{
public:
  ELFReaderIF(GNULDBackend& pBackend)
    : m_Backend(pBackend)
  { }

  virtual ~ELFReaderIF() { }

  /// ELFHeaderSize - return the size of the ELFHeader
  virtual size_t getELFHeaderSize() const = 0;

  /// isELF - is this a ELF file
  virtual bool isELF(void* pELFHeader) const = 0;

  /// isMyEndian - is this ELF file in the same endian to me?
  virtual bool isMyEndian(void* pELFHeader) const = 0;

  /// isMyMachine - is this ELF file generated for the same machine.
  virtual bool isMyMachine(void* pELFHeader) const = 0; 

  /// fileType - the file type of this file
  virtual MCLDFile::Type fileType(void* pELFHeader) const = 0;

  /// target - the target backend
  GNULDBackend& target()
  { return m_Backend; }

  /// target - the target backend
  const GNULDBackend& target() const
  { return m_Backend; }

  /// readSectionHeaders - read ELF section header table and create LDSections
  virtual bool readSectionHeaders(Input& pInput,
                                  MCLinker& pLinker,
                                  void* pELFHeader) const = 0;

  /// readSymbols - read ELF symbols and create LDSymbol
  virtual bool readSymbols(Input& pInput,
                           MCLinker& pLinker,
                           const MemoryRegion& pRegion,
                           const char* StrTab) const = 0;

  /// readRela - read ELF rela and create Relocation
  virtual bool readRela(Input& pInput,
                        MCLinker& pLinker,
                        const MemoryRegion& pRegion) const = 0;

  /// readRel - read ELF rel and create Relocation
  virtual bool readRel(Input& pInput,
                       MCLinker& pLinker,
                       const MemoryRegion& pRegion) const = 0;

protected:
  LDFileFormat::Kind getLDSectionKind(uint32_t pType, const char* pName) const;

  ResolveInfo::Desc getSymDesc(uint16_t pShndx) const;

  ResolveInfo::Binding getSymBinding(uint8_t pBinding, uint16_t pShndx) const;

  MCFragmentRef* getSymFragmentRef(Input& pInput,
                                   MCLinker& pLinker,
                                   uint16_t pShndx,
                                   uint32_t pOffset) const;

  ResolveInfo::Visibility getSymVisibility(uint8_t pVis) const;

  /// bswap16 - byte swap 16-bit version
  /// @ref binary utilities - elfcpp_swap
  inline uint16_t bswap16(uint16_t pData) const {
    return ((pData >> 8) & 0xFF) | ((pData & 0xFF) << 8);
  }

  /// bswap32 - byte swap 32-bit version
  /// @ref elfcpp_swap
  inline uint32_t bswap32(uint32_t pData) const {
    return (((pData & 0xFF000000) >> 24) |
            ((pData & 0x00FF0000) >>  8) |
            ((pData & 0x0000FF00) <<  8) |
            ((pData & 0x000000FF) << 24));

  }

  /// bswap64 - byte swap 64-bit version
  /// @ref binary utilities - elfcpp_swap
  inline uint64_t bswap64(uint64_t pData) const {
  return (((pData & 0xFF00000000000000ULL) >> 56) |
          ((pData & 0x00FF000000000000ULL) >> 40) |
          ((pData & 0x0000FF0000000000ULL) >> 24) |
          ((pData & 0x000000FF00000000ULL) >>  8) |
          ((pData & 0x00000000FF000000ULL) <<  8) |
          ((pData & 0x0000000000FF0000ULL) << 24) |
          ((pData & 0x000000000000FF00ULL) << 40) |
          ((pData & 0x00000000000000FFULL) << 56));
  }

private:
  GNULDBackend& m_Backend;
};

/** \class ELFReader
 *  \brief ELFReader is a template scaffolding for partial specification.
 */
template<size_t BIT, bool LITTLEENDIAN>
class ELFReader 
{ };

/** \class ELFReader<32, true>
 *  \brief ELFReader<32, true> is a 32-bit, little endian ELFReader.
 */
template<>
class ELFReader<32, true> : public ELFReaderIF
{
public:
  typedef llvm::ELF::Elf32_Ehdr ELFHeader;
  typedef llvm::ELF::Elf32_Shdr SectionHeader;
  typedef llvm::ELF::Elf32_Sym  Symbol;
  typedef llvm::ELF::Elf32_Rel  Rel;
  typedef llvm::ELF::Elf32_Rela Rela;

public:
  inline ELFReader(GNULDBackend& pBackend);

  inline ~ELFReader();

  /// ELFHeaderSize - return the size of the ELFHeader
  inline size_t getELFHeaderSize() const
  { return sizeof(ELFHeader); }

  /// isELF - is this a ELF file
  inline bool isELF(void* pELFHeader) const;

  /// isMyEndian - is this ELF file in the same endian to me?
  inline bool isMyEndian(void* pELFHeader) const;

  /// isMyMachine - is this ELF file generated for the same machine.
  inline bool isMyMachine(void* pELFHeader) const;

  /// fileType - the file type of this file
  inline MCLDFile::Type fileType(void* pELFHeader) const;

  /// readSectionHeaders - read ELF section header table and create LDSections
  inline bool readSectionHeaders(Input& pInput,
                          MCLinker& pLinker,
                          void* pELFHeader) const;

  /// readSymbols - read ELF symbols and create LDSymbol
  inline bool readSymbols(Input& pInput,
                   MCLinker& pLinker,
                   const MemoryRegion& pRegion,
                   const char* StrTab) const;

  /// readRela - read ELF rela and create Relocation
  inline bool readRela(Input& pInput,
                MCLinker& pLinker,
                const MemoryRegion& pRegion) const;

  /// readRel - read ELF rel and create Relocation
  inline bool readRel(Input& pInput,
                      MCLinker& pLinker,
                      const MemoryRegion& pRegion) const;
};

#include "ELFReader.tcc"

} // namespace of mcld

#endif

