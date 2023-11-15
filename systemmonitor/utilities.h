/**
* Copyright (c) 2004-2009 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:
* Filename: Utilities.h
* 
*
*/


 
#if !(defined __UTILITIES_H__)
#define __UTILITIES_H__

 /*******************************************************************************
 *
 * User Includes
 *
 ******************************************************************************/
 
#include "systemmonitor/eventlog.h"
#include "systemmonitor/configuration.h"

 /**
GetChunkL: Used by the InstrumentationHandler and the SystemMonitor to get a 
pointer to the global chunk. If it does not exist it is created.

@param aChunk, the pointer to be initialised with the adress of the chunk
@param aSystemMonitorError , any errors are posted to the error stack class
@param aCreatedChunk, set to true if the chunk was created. 
@leave KErrNoMemory
@return None

@publishedAll
@test
*/

IMPORT_C void GetChunkL(RChunk* aChunk,CSystemMonitorError* aSystemMonitorError,TBool* aCreatedChunk,TInt aBufferSize);

 /**
InitialiseChunkL: Initialises the shared global memory.
to store instrumentation record information.
@param aConfiguration, the pointer to be area where the configuration data will be.
@param aGlobalEventLogVars , pointer initilised to where the global variables will be.
@param aRecordsStart , pointer initilised to the start of the the record store.
@param aEndAddress , pointer initilised to the end of the the record store.
@param aRecordBufferSize , set to the size of the record buffer.
@leave KErrNoMemory
@return None

@publishedAll
@test
*/

IMPORT_C void InitialiseChunkL(CConfiguration* aConfiguration,CGlobalEventLogVars** aGlobalEventLogVars,TInstrumentationEventInformation** aRecordsStart,unsigned char* aEndAddress,TInt* aRecordBufferSize);
	
#endif

