/***************************************************************
 * PRXTool : Utility for PSP executables.
 * (c) TyRaNiD 2k5
 *
 * ProcessElf.h - Definition of a class to process ELF files.
 ***************************************************************/

#ifndef __PROCESS_ELF__
#define __PROCESS_ELF__

#include "types.h"
#include "elftypes.h"

class CProcessElf
{
protected:
	/* Pointers to the original elf and a binary image of the elf */
	u8 *m_pElf;
	u32 m_iElfSize;
	u8 *m_pElfBin;
	u32 m_iBinSize;
	bool m_blElfLoaded;

	char m_szFilename[MAXPATH];

	/* List of sections */
	ElfSection *m_pElfSections;
	/* Number of elf section headers */
	int m_iSHCount;
	/* Pointer to the program headers */
	ElfProgram *m_pElfPrograms;
	/* Number of elf program headers */
	int m_iPHCount;
	/* Pointer to the string table section */
	ElfSection *m_pElfStrtab;
	/* Holds the elf header information */
	ElfHeader m_elfHeader;
	/* List of symbols */
	ElfSymbol *m_pElfSymbols;
	/* Number of symbols */
	int m_iSymCount;

	/* The base address of the ELF */
	u32 m_iBaseAddr;

	const char *GetSymbolName(u32 name, u32 shndx);

	void ElfLoadHeader(const Elf32_Ehdr* pHeader);
	bool ElfValidateHeader();
	void ElfDumpHeader();
	bool BuildBinaryImage();
	bool BuildFakeSections(unsigned int dwDataBase);
	u8* LoadFileToMem(const char *szFilename, u32 &lSize);
	bool LoadPrograms();
	bool FillSection(ElfSection& elfSect, const Elf32_Shdr *pSection);
	void ElfDumpSections();
	bool LoadSections();
	bool LoadSymbols();
	void FreeMemory();
public:
	/** Default constructor */
	CProcessElf();
	/** Virtual destructor */
	virtual ~CProcessElf();
	/** Load an ELF from a file */
	virtual bool LoadFromFile(const char *szFilename);
	/** Load a binary file */
	virtual bool LoadFromBinFile(const char *szFilename, unsigned int dwDataBase);
	/** Find an elf section based on its name */
	ElfSection *ElfFindSection(const char* szName);
	/** Find an elf section based on its address */
	ElfSection *ElfFindSectionByAddr(unsigned int dwAddr);
	/** Determine if a section is a data section */
	bool ElfAddrIsText(unsigned int dwAddr);
	/** Get the base address of the ELF */
	u32 ElfGetBaseAddr();
	/** Get the top address of the ELF */
	u32 ElfGetTopAddr();
	/** Get the size of the loaded ELF (as would be loaded in memory) */
	u32 ElfGetLoadSize();
	/** Get the section headers */
	ElfSection* ElfGetSections(u32 &iSHCount);
	/** Get the file name of the loaded elf */
	const char* GetElfName();
};

#endif
