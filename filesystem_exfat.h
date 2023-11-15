// Copyright (c) 1995-2009 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This material, including documentation and any related computer
// programs, is protected by copyright controlled by Nokia. All
// rights are reserved. Copying, including reproducing, storing
// adapting or translating, any or all of this material requires the
// prior written consent of Nokia. This material also contains
// confidential information which may not be disclosed to others
// without the prior written consent of Nokia.
//
// Initial Contributors:
// Nokia Corporation - initial contribution.
//
// Contributors:
//
// Description:
//
// Public header file for "exFAT" file system. Contains this file system name and optional file system - specific declarations.
//
//
//


/**
 @file
 @publishedAll
 @released
*/

#if !defined(__FILESYSTEM_EXFAT_H__)
#define __FILESYSTEM_EXFAT_H__


#if !defined(__F32FILE_H__)
#include <f32file.h>
#endif


          
/**
    exFAT filesystem name, which shall be provided to RFs::MountFileSystem() and is returned by RFs::FileSystemName() if 
    this file system is mounted on the drive. The literal is case-insensitive.
    @see RFs::MountFileSystem()
    @see RFs::FileSystemName()
*/
_LIT(KFileSystemName_exFAT, "exFAT");

/*
    exFAT file system doesn't have subtypes. RFs::FileSystemSubType() returns "exFAT" for this file system mounted onthe drive.
    @see RFs::::FileSystemSubType()
*/

//------------------------------------------------------------------------------

namespace FileSystem_EXFAT
{

//------------------------------------------------------------------------------
//-- theoretical limits; see exFAT specs
const TUint64 KMaxSupportedExFatClusterSize = ((TUint64)0x01) << 25;
const TUint64 KMaxSupportedExFatClusters    = (((TUint64)0x01) << 32)-11;

const TUint64 KMaxSupportedExFatFileSize = KMaxSupportedExFatClusterSize*KMaxSupportedExFatClusters;

//------------------------------------------------------------------------------

/** 
    This class describes specific parameters for formatting volume with exFAT file system.
    The parameters are: Number of Sectors per cluster, Number of FAT tables.
    All parameters are optional and if not set, it is up to the file system implementation to decide values.

    This class package (TVolFormatParam_exFATBuf) shall be passed to the RFormat::Open() as "Special format information"

    Please note that some parameters may have invalid combinations and in this case it might not be possible to format volume.
    In this case RFormat::Open() will return corresponding error code (the concrete code depends on file system implementation).

    RFormat::Open() does not modify any data in this structure.

    @see TVolFormatParam_exFAT
    @see RFormat::Open()
*/ 
class TVolFormatParam_exFAT : public TVolFormatParam
{
 public:    
    inline TVolFormatParam_exFAT();
    inline void Init();

    inline void SetSectPerCluster(TUint32 aSpc);
    inline TUint32 SectPerCluster() const;
    //--
    inline void SetNumFATs(TUint32 aNumFATs);
    inline TUint32 NumFATs() const;


 private:
    void SetFileSystemName(const TDesC& aFsName);
    
    enum ///< offsets of the data units in parent class container
        {
        //-- slots 0 & 1 are reserved in order parameters storage be compatible with layout in TVolFormatParam_FAT
        KOffsetRsvd1 = 0,
        KOffsetRsvd2 = 1,
        KOffsetSpc=2,   //-- 2  !! do not change this offset. It must be the same for TVolFormatParam_FAT
        KOffsetNumFATs, //-- 3  !! do not change this offset. It must be the same for TVolFormatParam_FAT
        };



}; //TVolFormatParam_exFAT


/**
    TVolFormatParam_exFAT package buffer to be passed to RFormat::Open().
    @see TVolFormatParam_exFAT
    @see RFormat::Open()
*/ 
typedef TPckgBuf<TVolFormatParam_exFAT> TVolFormatParam_exFATBuf;



//------------------------------------------------------------------------------
//-- inline functions 
//------------------------------------------------------------------------------

TVolFormatParam_exFAT::TVolFormatParam_exFAT() : TVolFormatParam() 
    {
     __ASSERT_COMPILE(sizeof(TVolFormatParam_exFAT) == sizeof(TVolFormatParam));
     __ASSERT_COMPILE(KOffsetSpc == 2);
     __ASSERT_COMPILE(KOffsetNumFATs == 3);
     Init();
    }

//------------------------------------------------------------------------------
/** initialises the data structure with default values for all parameters and automatically sets file system name as "FAT" */
void TVolFormatParam_exFAT::Init() 
    {
    TVolFormatParam::Init(); 
    TVolFormatParam::SetFileSystemName(KFileSystemName_exFAT);
    }


//------------------------------------------------------------------------------
/**
    Set Number of "Sectors per cluster". For valid values see exFAT specs.
    @param  aSpc    Number of "Sectors per cluster". Value 0 means "the file system will decide itself what to use"       
*/
void TVolFormatParam_exFAT::SetSectPerCluster(TUint32 aSpc)
    {
    SetVal(KOffsetSpc, aSpc);
    }

//------------------------------------------------------------------------------
/** @return value previously set by SetSectPerCluster() */
TUint32 TVolFormatParam_exFAT::SectPerCluster() const 
    {
    return GetVal(KOffsetSpc);
    }

//------------------------------------------------------------------------------
/**
    Set Number of FAT tables on the volume. Only values 1 and 2 are supported.
    @param  aNumFATs    Number of FAT tables. Value 0 means "the file system will decide itself what to use"       
*/
void TVolFormatParam_exFAT::SetNumFATs(TUint32 aNumFATs) 
    {
    SetVal(KOffsetNumFATs, aNumFATs);
    }

//------------------------------------------------------------------------------
/** @return value previously set by SetNumFATs() */
TUint32 TVolFormatParam_exFAT::NumFATs() const 
    {
    return GetVal(KOffsetNumFATs);
    } 

//------------------------------------------------------------------------------



}//FileSystem_EXFAT






#endif //__FILESYSTEM_EXFAT_H__















