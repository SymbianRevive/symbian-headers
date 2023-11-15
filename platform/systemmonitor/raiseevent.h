/**
* Copyright (c) 2005-2009 Nokia Corporation and/or its subsidiary(-ies).
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
* Filename: RaiseEvent.h
* Using This File
* This file allows the developer to raise instrumentation events in 
* code through the use of the InstrumentationHandler object.
* The events are typically collected by a TEF output file and are 
* used to create an accurate event timestamp.
* Specifying The Macro Directive
* In your MMP project file, insert these lines at the top of the file:
* MACRO USE_IH_RAISE_EVENT
* #define USE_IH_RAISE_EVENT
* Comment and uncomment the lines as necessary to declare or 
* not-declare the macro directive.
* Using The Macro Directive
* In the library section of your MMP file, insert this line:
* #ifdef USE_IH_RAISE_EVENT
* LIBRARY			instrumentationhandler.lib
* #endif // USE_IH_RAISE_EVENT
* In your source files include this header file.
* To raise an event, you should:
* 1. Use the macro IH_DECLARE once to declare an object pointer
* of type *CInstrumentationHandler.
* 2. Use the macro IH_CREATE once to create the InstrumentationHandler.
* 3. Use the macro IH_RAISE_EVENT any number of times to raise a 
* timestamped event.
* 4. Use the macro IH_DELETE when you are finished to 
* delete the InstrumentationHandler.
* For example:
* IH_DECLARE( lInstrumentationHandler );
* IH_CREATE( lInstrumentationHandler );
* IH_RAISE_EVENT( lInstrumentationHandler, aEventValue );
* IH_DELETE( lInstrumentationHandler );
* To measure the time taken for a feature to execute,
* use two timestamps.  Use the appropriate macros to ensure the
* times are accurate.
* For example:
* IH_DECLARE( lInstrumentationHandler );
* IH_CREATE( lInstrumentationHandler );
* IH_RAISE_EVENT_BEFORE( lInstrumentationHandler, aEventValue );
* MyFunctionToMeasure();
* IH_RAISE_EVENT_AFTER( lInstrumentationHandler, aEventValue );
* IH_DELETE( lInstrumentationHandler );
* 
*
*/



#ifdef USE_IH_RAISE_EVENT
	#include <systemmonitor/instrumentationhandler.h>
#endif // ifdef USE_IH_RAISE_EVENT

#ifdef USE_IH_RAISE_EVENT
	#define IH_DECLARE( instHand )				CInstrumentationHandler	*instHand;
	#define IH_CREATE( instHand )				instHand =	CInstrumentationHandler::NewL();
	#define IH_RAISE_EVENT( instHand, event )	instHand->RaiseEventNotificationAfter( event );
	#define IH_RAISE_EVENT_BEFORE( instHand, event )	instHand->RaiseEventNotification( event );
	#define IH_RAISE_EVENT_AFTER( instHand, event )		instHand->RaiseEventNotificationAfter( event );
	#define IH_DELETE( instHand )				delete ( instHand ); instHand  =	NULL;
#else // ifdef USE_IH_RAISE_EVENT
	#define IH_DECLARE( instHand )				void(0);
	#define IH_CREATE( instHand )				void(0);
	#define IH_RAISE_EVENT( instHand, event ) 	void(0);
	#define IH_RAISE_EVENT_BEFORE( instHand, event )	void(0);
	#define IH_RAISE_EVENT_AFTER( instHand, event )		void(0);
	#define IH_DELETE( instHand )				void(0);
#endif // ifdef USE_IH_RAISE_EVENT

/***********************************************************************************
 * Creating Event Identifiers
 *
 * Please contact the Engineering Tools team to allocate unique event 
 * identifiers for your events.
 *
 **********************************************************************************/

const TInt	SM_FIRST_EVENT =	0;

const TInt	SM_START_EVENT =	1;

const TInt	SM_FIRST_PLATTEST_EVENT =	2;
const TInt	SM_LAST_PLATTEST_EVENT =	9999;
