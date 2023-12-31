// Copyright (c) 1995-2009 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of the License "Eclipse Public License v1.0"
// which accompanies this distribution, and is available
// at the URL "http://www.eclipse.org/legal/epl-v10.html".
//
// Initial Contributors:
// Nokia Corporation - initial contribution.
//
// Contributors:
//
// Description:
// e32\include\e32rom.h
// 
// WARNING: This file contains some APIs which are internal and are subject
//          to change without notice. Such APIs should therefore not be used
//          outside the Kernel and Hardware Services package.
//

#ifndef __E32ROM_H__
#define __E32ROM_H__
#include <e32cmn.h>
#include <e32def_private.h>

//

#ifndef __SECURITY_INFO_DEFINED__
#define __SECURITY_INFO_DEFINED__
/**
@internalTechnology
*/
//This struct must be identical in size and offset to the one in e32cmn.h
//Functions need not be duplicated.  But must be same structurally.
struct SCapabilitySet
	{
	enum {ENCapW=2};
	TUint32 iCaps[ENCapW];
	inline const TUint32& operator[] (TInt aIndex) const { return iCaps[aIndex]; }
	inline TUint32& operator[] (TInt aIndex) { return iCaps[aIndex]; }
	};

/**
@internalTechnology
*/
//This struct must be identical in size and offset to the one in e32cmn.h
//Functions need not be duplicated.  But must be same structurally.
struct SSecurityInfo
	{
	TUint32	iSecureId;
	TUint32	iVendorId;
	SCapabilitySet iCaps;	
	};
#endif

/**
@internalTechnology
@prototype
*/
struct SDemandPagingConfig
	{
	TUint16 iMinPages;
	TUint16 iMaxPages;
	TUint16 iYoungOldRatio;
	TUint16 iSpare[3];		// iSpare[0:1] are used for emulated rom paging, 
							// iSpare[2] is used for the old to oldest ratio.
	};

/**
@internalTechnology
@prototype
*/
struct SRomPageInfo
	{
	enum TAttributes
		{
		EPageable = 1<<0
		};
	enum TCompression  // todo: compression type not exclusive to rom pages
		{
		ENoCompression,
		EBytePair,
		};
	TUint32 iDataStart;
	TUint16 iDataSize;
	TUint8  iCompressionType;
	TUint8  iPagingAttributes;
	};

/**
@publishedPartner
@released

Defines the size of the header for a ROM image.

@see TRomHeader
*/
const TUint KRomHeaderSize=0x200;
//


/**
@publishedPartner
@released

The format of the header for a ROM image.

This is retained as part of the ROM image.
It is generated by the rombuild tool, and is used by the Bootstrap and
the kernel.
*/
class TRomHeader
	{
public:
	enum { KDefaultDebugPort = -1 };
	enum { KNumTraceMask = 8 };  // this is also defined in e23const.h

__ASSERT_COMPILE(KNumTraceMask==KNumTraceMaskWords);

public:
    /**
    Reserved for a small amount of Bootstrap code, if required.
    The first 4 bytes of the binary image typically contains
    a branch instruction which jumps to code at offset 0x100.
    */
	TUint8 iJump[124]; 
	
	                                     
    /**
    The restart vector.
    */	                                     
	TLinAddr iRestartVector;
	
	
	/**
	The date and time that the ROM image was built, in microseconds.
	*/
	TInt64 iTime;
	
	
	/**
	The high order 32 bits of the ROM image build date & time.
	*/
	TUint32 iTimeHi;
	
	
	/**
	The virtual address of the base of the ROM.
	*/
	TLinAddr iRomBase;
	
	
	/**
	The size of the ROM image, in bytes.
	
	This includes the second section for sectioned ROMs.
	*/
	TUint32 iRomSize;
	
	
	/**
	The virtual address of the TRomRootDirectoryList structure.

    @see TRomRootDirectoryList 
	*/
	TLinAddr iRomRootDirectoryList;
	
	
	/**
	The virtual address of kernel data, when in RAM.
	*/
	TLinAddr iKernDataAddress;
	
	
	/**
	The virtual address of the top of the kernel region, when in RAM.
	*/
	TLinAddr iKernelLimit;
	
	
	/**
	The virtual address of the primarys ROM file image header.

    @see TRomImageHeader 
	*/
	TLinAddr iPrimaryFile;
	
	
	/**
	The virtual address of the secondarys ROM file image header.
	
	@see TRomImageHeader 
	*/
	TLinAddr iSecondaryFile;
	
	
	/**
	A computed constant that causes the 32-bit checksum of the image to equal
	the value specified by the "romchecksum" keyword.
	*/
	TUint iCheckSum;
	
	
	/**
	A unique number identifying the hardware for which this ROM image
	has been built.

    Note that this is only used for testing purposes.
	*/
	TUint32 iHardware;
	
	
	/**
	A bitmask identifying which of the languages are supported by the ROM image,
	as specified by the "languages" keyword.

    Note that this is only used for testing purposes.
	*/
	TInt64 iLanguage;
	
	
	/**
	Contains the flags that define the security options in force.
	
	@see TKernelConfigFlags
	*/
	TUint32 iKernelConfigFlags;

	/**
	The virtual address of the TRomExceptionSearchTable structure.

	@see TRomExceptionSearchTable
	*/
	TLinAddr iRomExceptionSearchTable;
	
	/**
	Current size of ROM header (Previously iUnused3)
	If value is 0x69966996 then header size = 0x100
	*/
	TUint32 iRomHeaderSize;
	
	
	/**
	The virtual address of the ROM section header, if the ROM is sectioned.
	
	@see TRomSectionHeader
	*/
	TLinAddr iRomSectionHeader;
	
	
	/**
	The total supervisor data size, i.e. the amount of memory mapped for
	the kernel data chunk.
	*/
	TInt iTotalSvDataSize;
	
	
	/**
	The virtual address of the TRomEntry for the Variant file.
	
	@see TRomEntry
	*/
	TLinAddr iVariantFile;

	
	/**
	The virtual address of TRomEntry for the first extension file, if it exists.
	
	If there is more than one extension, then the next extension field in
	the extensions TRomImageHeader points to the TRomEntry for
	that next extension.
	
    @see TRomImageHeader::iNextExtension
   	@see TRomImageHeader
	@see TRomEntry
	*/
	TLinAddr iExtensionFile;
	
	
	/**
	The virtual adress of the first area to be relocated into RAM, as defined
	using the "area" keyword.
	*/
	TLinAddr iRelocInfo;
	
	
	/**
	The old position of the kernel trace mask, see iTraceMask below
	*/
	TUint32  iOldTraceMask;		// The old location of the kernel tracemask
	
	
	/**
	The virtual address of the user data area.
	*/
	TLinAddr iUserDataAddress;	// non-MMU stuff

	
	/**
	The total size of the user data.
	*/
	TInt iTotalUserDataSize;	// non-MMU stuff
	
	
	/**
	A value that is interpreted by the Bootstrap and kernel as the debug port
	to be used.
	*/
	TUint32 iDebugPort;			// semantic is ASSP-specific
	
	
	/**
	The ROM version number.
	*/
	TVersion iVersion;
	
	
	/**
	The type of compression used for the image.
	
	This is a UID, or 0 if there is no compression.
	*/
	TUint32 iCompressionType;	// compression type used
	
	
	/**
	The size of the image after compression.
	*/
	TUint32 iCompressedSize;	// Size after compression
	
	
	/**
	The size of the image before compression.
	*/
	TUint32 iUncompressedSize;	// Size before compression
	
	
	/**
	*/
	TUint32 iDisabledCapabilities[2];   // 2==SSecurityInfo::ENCapW


	/**
	The initial value for the kernel trace masks.
	*/
	TUint32  iTraceMask[KNumTraceMask];  // The kernel debug trace masks

	/**
	Initial values for fast-trace filter.
	*/
	TUint32 iInitialBTraceFilter[8];

	/**
	Initial value for size of fast-trace buffer.
	*/
	TInt iInitialBTraceBuffer;

	/**
	Initial value for size of fast-trace mode.
	*/
	TInt iInitialBTraceMode;

	/**
	Offset, in bytes from ROM start, for the start of the pageable ROM area.
	*/
	TInt iPageableRomStart;

	/**
	Size, in bytes, of the pageable ROM area.
	*/
	TInt iPageableRomSize;

	/**
	Offset, in bytes from ROM start, for the page index. (Array of SRomPageInfo objects.)
	@internalTechnology
	@prototype
	*/
	TInt iRomPageIndex;

	/**
	@internalTechnology
	@prototype
	*/
	SDemandPagingConfig iDemandPagingConfig;

	/**
	Offset, in bytes from ROM start, for the start of compressed un-paged ROM area
	@internalTechnology
	@prototype
	*/
	TUint32 iCompressedUnpagedStart;
	
	
	/**
	Size, in bytes of the un-paged part of image after compression.
	@internalTechnology
	@prototype
	*/
	TUint32 iUnpagedCompressedSize;
	
	
	/**
	Size, in bytes of the un-paged part of image before compression.
	@internalTechnology
	@prototype
	*/
	TUint32 iUnpagedUncompressedSize;
	
	/**
	The virtual address at which the start of the HCR repository file is located in the unpaged part of the Core ROM Image.
	@internalTechnology
	@prototype
	*/
	TUint32 iHcrFileAddress;
	
	/**
	@internalComponent
	*/
	TUint32 iSpare[36];   // spare : force size to be correct

	};

__ASSERT_COMPILE(sizeof(TRomHeader)==KRomHeaderSize);
__ASSERT_COMPILE(SCapabilitySet::ENCapW==2); // TRomHeader::iDisabledCapabilities has hard coded 2 because h2inc.pl does not parse scoped identifiers




/**
@publishedPartner
@released

Contains information about a root directory.

A variable number of these are contained in a TRomRootDirectoryList structure.

@see TRomRootDirectoryList
*/
class TRootDirInfo
	{
public:
    /**
    The hardware variant for this root directory entry.
    */
	TUint iHardwareVariant;
	
	
	/**
	The virtual address of the root directory.
	
	@see TRomDir
	*/
	TLinAddr iAddressLin;
	};




/**
@publishedPartner
@released

A structure that allows you to find the root directories for each hardware
Variant supported by the ROM.

Usually, there is only one Variant and one root directory. However, a ROM can
have multiple root directories and directory trees, one for each hardware Variant
supported by the ROM. This ensures that the file server only sees the files
that are relevant to the hardware on which it is running. In this case, there
are multiple entries in the table describing each root directory.
*/
class TRomRootDirectoryList
	{
public:
    /**
    The number of root directory entries.
    */
	TInt iNumRootDirs;
	
	
	/**
	The root directory entries.

    The number of entries is defined by iNumRootDirs.
	*/
	TRootDirInfo iRootDir[1];
	};




/**
@publishedPartner
@released

The format of a ROM section header.
*/
class TRomSectionHeader
	{
public:

    /**
    The ROM version number.
    */
	TVersion iVersion;
	
	
	/**
	A computed constant that causes the 32-bit checksum of the upper
	section to equal zero.

	Upper sections checksum to zero so that the overall ROM checksum in
	the TRomHeader is unaffected by changes to this section.
	
	@see TRomHeader
	*/
	TUint iCheckSum;
	
	
	/**
	The date and time that the ROM image was built, in microseconds.
	*/
	TInt64 iTime;

	
	/**
	A bitmask identifying which of the languages are supported by the ROM image,
	as specified by the "languages" keyword.
    */
	TInt64 iLanguage;
	};
//




/**
@publishedPartner
@released

A structure that describes a file or a directory.
*/
class TRomEntry
	{
public:
    
     
    /**
    The size of the file.
    */
	TInt iSize;
	
	
	/**
	The virtual address of the file, or of a TRomDir structure if this entry
	describes another directory.
	
	@see TRomDir
	*/
	TUint32 iAddressLin;


	/**
	Attributes.
	*/
	TUint8 iAtt;


	/**
	The length of the file or directory name.
	*/
	TUint8 iNameLength;


	/**
	A variable length field containing the file or directory name.
	*/
	TUint8 iName[2];
	};




/**
@publishedPartner
@released

The size of the fixed part of a TRomEntry structure.
*/
const TInt KRomEntrySize=(sizeof(TRomEntry)-2);




//
class TRomDirSortInfo;

/**
@publishedPartner
@released

A structure that describes the first part of a ROM directory.

This part of a ROM directory is a sequence of variable length entries,
each describing a file or a subdirectory, in the order that the members
were specified in the original obey file; the variable length entries are
the TRomEntry structures that follow the iSize member.

This part of the ROM directory is followed by a structure defined
by TRomDirSortInfo, which contains a pair of sorted tables suitable for
a binary search.

@see TRomDirSortInfo
*/
class TRomDir
	{
public:
	inline const TRomDirSortInfo* SortInfo() const;
	inline const TRomEntry* SortedEntry(TInt aIndex) const;
	inline TInt SubDirCount() const;
	inline TInt FileCount() const;
	inline TInt EntryCount() const;
	TInt BinarySearch(const TDesC& aName, TInt aLengthLimit, TInt aMode, TBool aDir) const;
	const TRomDir* FindLeafDir(const TDesC& aPath) const;
public:

    /**
    The number of bytes occupied by the set of TRomEntry structures
    that follow this field.
    
    @see TRomDir::iEntry
    */
	TInt iSize;

	
	/**
	A variable number of entries, each of which describes a file or a directory.
	
	Each entry is 4-byte aligned, and may have padding to ensure that the entry
	is 4-bye aligned.
	*/
	TRomEntry iEntry;
	};




/**
@publishedPartner
@released

A structure that describes the second part of a ROM directory.

It contains a pair of sorted tables suitable for
a binary search. The sorted tables contain unsigned 16-bit scaled offsets,
which point to the start of the corresponding TRomEntry in the TRomDir.

@see TRomDir
*/
class TRomDirSortInfo
	{
public:

	/**
    The number of subdirectories in this directory.
	*/
	TUint16	iSubDirCount;		// number of subdirectories in this directory
	
	
	/**
	The number of files in this directory.
	*/
	TUint16 iFileCount;			// number of non-directory files in this directory
	
	
	/**
	The two sorted tables:
	
	1. First one is a table of 16-bit scaled offsets to the directory entries.
	
	2. Second one is a table of 16-bit scaled ofsets to the file entries.
	   This table starts at offset 2*iSubDirCount from the start of the first table.
	   
	If the offset is X, then the corresponding TRomEntry is at address:
	@code
	4*X +(char*)address of the first TRomEntry
	@endcode
	For example, the first entry is at offset zero.
	
	The entries are sorted in the order of the UTF-8 representation of
	the names in a case insensitive way (compare the C function stricmp()).
	In effect, this folds upper and lowercase ASCII characters but leaves all
	other Unicode characters unchanged.
	*/
	TUint16 iEntryOffset[1];	// offsets of each entry from TRomDir::iEntry; extend
								// order of offsets is directories first, then files, lexicographic order within each group
	};


/**
Gets a pointer to the start of the second part of the ROM directory,
as described by the TRomDirSortInfo structure.

@return The pointer to the start of the second part of the ROM directory.
*/
inline const TRomDirSortInfo* TRomDir::SortInfo() const
	{ return (const TRomDirSortInfo*)( ((TLinAddr)&iEntry) + ( (iSize+sizeof(TUint32)-1) &~ (sizeof(TUint32)-1) )); }




/**
Gets the TRomEntry corresponding to the file or directory located at
the specified index position within the sorted tables.

@param aIndex The index of the entry within the sorted tables.
              Note that for the purpose of this function, the two tables
              are treated as one single table.
              
@return The required TRomEntry              
*/
inline const TRomEntry* TRomDir::SortedEntry(TInt aIndex) const
	{
	const TRomDirSortInfo* s = SortInfo();
	return (const TRomEntry*)(((TLinAddr)&iEntry) + s->iEntryOffset[aIndex] * sizeof(TUint32));
	}




/**
Gets the number of subdirectories in the directory.

@return The number of subdirectories.
*/
inline TInt TRomDir::SubDirCount() const
	{ return SortInfo()->iSubDirCount; }

	
	
	
/**
Gets the number of files in the directory.

@return The number of files.
*/	
inline TInt TRomDir::FileCount() const
	{ return SortInfo()->iFileCount; }




/**
Gets the total number of files and subdirectories in the directory.

@return The total number of files and subdirectories.
*/	
inline TInt TRomDir::EntryCount() const
	{
	const TRomDirSortInfo* s = SortInfo();
	return s->iSubDirCount + s->iFileCount;
	}




//
// Header of ROM image files under the new scheme. (dlls & exes)
//
/**
@publishedPartner
@released
*/
const TUint32 KRomImageFlagPrimary			=0x80000000u;

/**
@publishedPartner
@released
*/
const TUint32 KRomImageFlagVariant			=0x40000000u;

/**
@publishedPartner
@released
*/
const TUint32 KRomImageFlagExtension		=0x20000000u;

/**
@publishedPartner
@released
*/
const TUint32 KRomImageFlagDevice			=0x10000000u;

/**
@publishedPartner
@released
*/
const TUint32 KRomImageFlagsKernelMask		=0xf0000000u;

/**
@publishedPartner
@released
*/
const TUint32 KRomImageFlagSecondary		=0x08000000u;

/**
@publishedPartner
@released
*/
const TUint32 KRomImageFlagData				=0x04000000u;	// image has data and is not extension or variant

/**
@publishedPartner
@released
*/
const TUint32 KRomImageFlagDataInit			=0x02000000u;	// image or non-EXE dependencies would require data initialisation

/**
@publishedPartner
@released
*/
const TUint32 KRomImageFlagDataPresent		=0x01000000u;	// image or any dependencies have data

/**
@publishedPartner
@released
*/
const TUint32 KRomImageFlagExeInTree		=0x00800000u;	// image depends on EXE

/**
@publishedPartner
@released
*/
const TUint32 KRomImageFlagDll				=0x00000001u;

/**
@publishedPartner
@released
*/
const TUint32 KRomImageFlagFixedAddressExe	=0x00000004u;

/**
@publishedPartner
@released
*/
const TUint32 KRomImageABIMask				=0x00000018u;

/**
@publishedPartner
@released
*/
const TUint32 KRomImageABI_GCC98r2			=0x00000000u;	// for ARM

/**
@publishedPartner
@released
*/
const TUint32 KRomImageABI_EABI				=0x00000008u;	// for ARM

/**
@publishedPartner
@released
*/
const TUint32 KRomImageEptMask				=0x000000e0u;	// entry point type

/**
@publishedPartner
@released
*/
const TInt	  KRomImageEptShift				=5;

/**
@publishedPartner
@released
*/
const TUint32 KRomImageEpt_Eka1				=0x00000000u;

/**
@publishedPartner
@released
*/
const TUint32 KRomImageEpt_Eka2				=0x00000020u;

/**
Flag to indicate the image should not be code paged.
@internalTechnology
@released
*/
const TUint KRomImageFlagCodeUnpaged			=0x00000100u;


/**
Flag to indicate the image should be code paged.
@internalTechnology
@released
*/
const TUint KRomImageFlagCodePaged				=0x00000200u;


/**
@internalTechnology
@released
Flag to indicate when named symbol export data present in image
*/
const TUint KRomImageNmdExpData				=0x00000400u;

/**
@internalTechnology
@released
Flag to indicate debuggability of this image.
*/
const TUint KRomImageDebuggable				=0x00000800u;

/**
Flag to indicate the image will default to not be data paged,
this can be overridden when creating chunks, threads and user heaps.
@internalTechnology
@released
*/
const TUint KRomImageFlagDataUnpaged			= 0x00001000u;

/**
Flag to indicate the image will default to be data paged,
this can be overridden when creating chunks, threads and user heaps.
@internalTechnology
@released
*/
const TUint KRomImageFlagDataPaged			= 0x00002000u;

/**
Mask for the data paging flag bits.
@internalTechnology
@released
*/
const TUint KRomImageDataPagingMask	= KRomImageFlagDataUnpaged | KRomImageFlagDataPaged;

/**
@released
Flag to indicate SMP safety of this image.
*/
const TUint KRomImageSMPSafe			=0x00004000u;

class TDllRefTable;

/**
@publishedPartner
@released

The format of the header for a ROM file image.

The structure of a file image is based on the native image file format,
but this can be compressed in the ROM image, as the relocation information
and the .idata section are discarded once the file is fixed up.

The Import Address Table (IAT) is also removed and each reference to
an IAT entry is converted into a reference to the associated Export Directory
entry in the corresponding DLL.

ROM file images have the following sections:

@code
The header (as described by this structure)
.text  - code
.rdata - constant (read-only) data
.edata - the export directory
.data  - initialised data that is copied to RAM when the executable runs.
The DLL reference table (a TDllRefTable structure), which is a list of DLLs
used by the executable.
@endcode

@see TRomImageHeader::iDllRefTable
@see TDllRefTable
*/
class TRomImageHeader
	{
public:

    /**
    The UID1 for the file.
    
    @see TUidType
    */
	TUint32	iUid1;

	
    /**
    The UID2 for the file.

    @see TUidType
    */
	TUint32	iUid2;

	
    /**
    The UID3 for the file.

    @see TUidType
    */
	TUint32	iUid3;
	
	
	/**
	The checksum of the UIDs
	*/
	TUint32	iUidChecksum;
	
	
	/**
	The entrypoint of this executable, i.e. the offset within this file.
	*/
	TUint32 iEntryPoint;
	
	
	/**
	This executables code address.
	*/
	TUint32 iCodeAddress;


	/**
	This executables data address.
	*/
	TUint32 iDataAddress;

	
	/**
	The size of the code.
	
	This includes the size of the constant data.
	*/
	TInt iCodeSize;
	
	
	/**
	The size of the executable code.
	
	This is the value of (iCodeSize - the size of the constant data).
	*/
	TInt iTextSize;
	
	
	/**
	The data size.
	*/
	TInt iDataSize;
	
	
	/**
	The size of the .bss (the zero-filled data)
	*/
	TInt iBssSize;
	
	
	/**
	The minimum size of the heap.
	*/
	TInt iHeapSizeMin;
	
	
	/**
	The maximum size of the heap.
	*/
	TInt iHeapSizeMax;
	
	
	/**
	The size of the stack.
	*/
	TInt iStackSize;
	
	
	/**
	The address of the DLL reference table.
	
	@see TDllRefTable
	*/
	TDllRefTable* iDllRefTable;
	
	
	/**
	The number of functions exported by this executable.
	*/
	TInt iExportDirCount;
	
	
	/**
	The address of the export directory, which is a simple list of functions
	that can be indexed by ordinal.
	*/
	TUint32 iExportDir;
	
	
	/**
	Security information, details of which are internal to Symbian.
	*/
	SSecurityInfo iS;
	
	
	/**
	The version number of the tools used to generate this file image.
	*/
	TVersion iToolsVersion;
	
	
	/**
	Flags field.
	*/
	TUint32 iFlags;
	
	
	/**
	The priority of the process.
	*/
	TProcessPriority iPriority;
	
	
	/**
	The virtual base address of the data and .bss, where the process expects
	its data chunk to be when it runs.
	*/
	TUint32 iDataBssLinearBase;
	
	
	/**
	The address of the TRomEntry for the next extension file.
	
	This field is only used if there is more than one extension.
	The first extension is found using the TRomHeader.
	
	@see TRomEntry
	@see TRomHeader
	*/
	TLinAddr iNextExtension;
	
	
	/**
	A number denoting the hardware Variant.
	
	It is used to determine whether this executable can run
	on a given system.
	*/
	TUint32 iHardwareVariant;
	
	
	/**
	The total data size, including space reserved for DLLs
	*/
	TInt iTotalDataSize;	// data+bss + space reserved for DLLs
	
	
	/**
	The module version.
	*/
	TUint32 iModuleVersion;

	/**
	The address of the Exception Descriptor if present.
	0 if no Exception descriptor
	*/
	TLinAddr iExceptionDescriptor;
	};	
	
	
	
	
//
// Header for extension ROMs
// Equivalent to TRomHeader
//

/**
@publishedPartner
@released

The format of a ROM extension header.
*/
class TExtensionRomHeader
	{	
public:
    
    /**
    The extension ROM image version number.
    */
	TVersion iVersion;
	
	
	/**
	The virtual address of the base of the extension ROM.
	*/
	TLinAddr iRomBase;
	
	
	/**
	The size of the extension ROM image.
	*/
	TUint32 iRomSize;
	
	
	/**
	The virtual address of the TRomRootDirList structure for
	the combined kernel+extension ROM image.
	
	@see TRomRootDirList
	*/
	TLinAddr iRomRootDirectoryList;
	
	
	/**
	The date and time that the extension ROM image was built, in microseconds.
	*/
	TInt64 iTime;
	
	
	/**
	The extension ROM image checksum
	*/
	TUint iCheckSum;


	//
	/**
	Copy of the kernel ROM image version number.
	*/
	TVersion iKernelVersion;
	
	
	/**
	Copy of the kernel ROM image build date & time.
	*/
	TInt64 iKernelTime;
	
	
	/**
	Copy of the kernel ROM image checksum.
	*/
	TUint iKernelCheckSum;
	//


	/**
	The type of compression used for the image.
	
	This is a UID, or 0 if there is no compression.
	*/
	TUint32 iCompressionType;	// compression type used
	
	
	/**
	The size of the image after compression.
	*/
	TUint32 iCompressedSize;	// Size after compression
	
	
	/**
	The size of the image before compression.
	*/
	TUint32 iUncompressedSize;	// Size before compression
	
	
	/**
	The virtual address of the TRomExceptionSearchTable structure.

	@see TRomExceptionSearchTable
	*/
	TLinAddr iRomExceptionSearchTable;

	
	/**
	Reserved for future use.
	*/
	TUint32 iPad[32-15]; // sizeof(TExtensionRomHeader)=128
	};





/**
@publishedPartner
@released

A list of DLLs that an executable needs in order to run.

Each DLL referenced in this list has a pointer to a TRomImageHeader structure
that describes that DLL. This allows the DLL loader to search
a dependency chain, and ensure that all required DLLs are loaded.

@see TRomImageHeader
*/
class TDllRefTable
	{
public:

    /**
    Flags field.
    */
	TUint16 iFlags;
	
	
	/**
	The number of referenced DLLs in this list.
	*/
	TUint16 iNumberOfEntries;
	
	
	/**
	A set of pointers to the TRomImageHeader structures for each referenced DLL.
	*/
	TRomImageHeader* iEntry[1];
	};

#endif

