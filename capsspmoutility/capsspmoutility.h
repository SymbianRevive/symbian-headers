/*
* ==============================================================================
*  Description: This is the public client API for the Caps Spmo Utility
*               Library.
*
*  Copyright © 2008-2009 Nokia. All rights reserved.
*  This material, including documentation and any related 
*  computer programs, is protected by copyright controlled by 
*  Nokia. All rights are reserved. Copying, including 
*  reproducing, storing, adapting or translating, any 
*  or all of this material requires the prior written consent of 
*  Nokia. This material also contains confidential 
*  information which may not be disclosed to others without the 
*  prior written consent of Nokia.
* ==============================================================================
*/


/**
 @file
 @publishedAll
 @released
*/

#ifndef CAPS_SPMO_UTILITY_H__
#define CAPS_SPMO_UTILITY_H__

#include <e32base.h>
#include <f32file.h>

class CCapsSpmoImpl;

namespace CapsSpmoUtility 
	{

class CCapsSpmo;
class MCapsSpmoObserver;

/**
@publishedAll
@released

The Caps Spmo utility.

These classes provides functions to work with Scalado SpeedView objects (Spmo).
The CCapsSpmoUtility class can be considered as a factory class creating CCapsSpmo instance.
The CCapsSpmo class provides API to work with spmo data located in a JPEG data or in a external storage.
It also allows to create new spmo based on input JPEG data.

The two simple use cases below step by step explains how the API should be used:
-# Reading Spmo from a JPEG file.

	-# New CCapsSpmo instance is created using CCapsSpmoUtility::NewSpmoL().
	-# JPEG file is set as an input by calling CCapsSpmo::SetInputL(const TDesC& aJpegFileName).
	-# Spmo buffer is extracted from the file by calling CCapsSpmo::ReadFromInputL()
	-# The spmo data is retrieved with CCapsSpmo::BufferL() call. 
	.
	
-# Creating of new Spmo.
	-# New CCapsSpmo instance is created using CCapsSpmoUtility::NewSpmoL(const TSize& aOptimalSize).
	-# Jpeg file is set as an input by calling CCapsSpmo::SetInputL(const TDesC& aJpegFileName).
	-# Spmo buffer is generated based on the input file data by calling CCapsSpmo::GenerateFromInputL(MCapsSpmoObserver* aCapsSpmoObserver)
	-# The spmo data is inserted in to the input file with CCapsSpmo::InsertIntoInputL() call.
	.
.	 
*/

class CCapsSpmoUtility : public CBase
	{
public:
	// ownership of Spmo object is transferred to the client
	IMPORT_C static CCapsSpmo* NewSpmoL();
	IMPORT_C static CCapsSpmo* NewSpmoL(const TSize& aOptimalSize);
	// these functions should be called if jpeg header in a file/buffer with spmo has been updated (exif app block has been added for example)
	IMPORT_C static void UpdateSpmoChecksumInFileL(const TDesC& aJpegFileName);
	IMPORT_C static void UpdateSpmoChecksumInBufferL(TDesC8& aJpegBuffer);
	
private:
	CCapsSpmoUtility();
	~CCapsSpmoUtility();
	};

/**
@publishedAll
@released
*/

class CCapsSpmo : public CBase  
	{
public:
	IMPORT_C void SetInputL(TDesC8& aJpegBuffer);
	IMPORT_C void SetInputL(RBuf8& aJpegBuffer);
	IMPORT_C void SetInputL(const TDesC& aJpegFileName);
	IMPORT_C void SetInputL(RFile& aJpegFile);

	IMPORT_C void SetOptimalSizeL(TSize& aOptimalSize);// ignored if client reads existing Spmo

	IMPORT_C void BeginInputStreamL();
	IMPORT_C void ContinueInputStreamL(TDesC8& aBuffer); 
	IMPORT_C void EndInputStreamL();

	IMPORT_C void Reset();

	IMPORT_C void ReadFromInputL();
	IMPORT_C void GenerateFromInputL();
	IMPORT_C void GenerateFromInputL(MCapsSpmoObserver* aCapsSpmoObserver);
	
	IMPORT_C void AddToBufferL(RBuf8& aJpegBuffer);
	IMPORT_C void AddToFileL(const TDesC& aJpegFileName);
	IMPORT_C void InsertIntoInputL();

	// getters
	IMPORT_C TPtr8 BufferL(); // ownership of the buffer remains with CCapsSpmo instance
	IMPORT_C TSize OptimalSizeL();

	IMPORT_C ~CCapsSpmo();

private:
	friend class CCapsSpmoUtility;
	CCapsSpmo(CCapsSpmoImpl* aCapsSpmoImpl);
	CCapsSpmoImpl* iCapsSpmoImpl;
	};
	
	}
#endif //CAPS_SPMO_UTILITY_H__