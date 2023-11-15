/*
* ==============================================================================
*  Description: This is the public client API for the Caps image processor
*               extension.
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

#ifndef TCAPS_IMAGE_PROCESSOR_EXTENSION_H__
#define TCAPS_IMAGE_PROCESSOR_EXTENSION_H__

#include <e32base.h>
#include <imageprocessor/imageprocessor_uids.hrh>

const TUid KCapsImageProcessorExtensionUid = {KCapsImageProcessorExtensionUidValue}; //Defines the uid for CAPS imageprocessor extension

class MCapsImageProcessorExtension;

/**
@publishedAll
@released

The Caps image processor extension.

This class provides "underhood" functions for a Caps image processor.
(Caps image processor is an image processor plugin. For more details about image processor API @See CImgProcessor). 
It allows to set/get the Spmo data buffer for/from the Caps image processor input and
to add the Spmo into the Caps image processor output.

It is also possible to get/set Caps session using the API.
*/

class TCapsImageProcessorExtension 
	{
public:
	/**
	Flags to ensure spmo data is coherent with JPEG data.
	*/
	enum TSpmoVerificationMode
		{
		/** No verification will be used to ensure coherent data. 
		This option could be used if the user is absolutely sure that the image haven't been altered since the Spmo was created.
		*/
		ESpmoVerificationModeDisabled,
		
		/** A faster verification mode, which will be sufficient for most cases.
		This is the recommended verification mode. 
		*/
		ESpmoVerificationModeUnsafe,
		
		/** A complete verification to ensure absolute coherency between the Spmo
		and the image. 
		*/
		ESpmoVerificationModeSlowSafe
		};
public:
	IMPORT_C void SetAddSpmoToOutputL(TBool aAddSpmoToOutput, const TSize& aSpmoOptimalSize);
	IMPORT_C void SetSpmoL(TDesC8& aSpmoBuffer, TSpmoVerificationMode aSpmoVerificationMode);

	IMPORT_C TPtr8 SpmoL(const TSize& aSpmoOptimalSize);

private:
	friend class CCapsImageProcessor;
	IMPORT_C TCapsImageProcessorExtension(MCapsImageProcessorExtension& aPlugin);

private:
	MCapsImageProcessorExtension& iImpl;
	TInt iReserved;
	};

#endif //TCAPS_IMAGE_PROCESSOR_EXTENSION_H__
