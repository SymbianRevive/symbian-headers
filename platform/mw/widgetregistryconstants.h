/*
* Copyright (c) 2003, 2004, 2005 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of the License "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description: 
*
*
*/

#ifndef WIDGETREGISTRYCONSTANTS_H
#define WIDGETREGISTRYCONSTANTS_H

#include <e32cmn.h>

// forward declarations
class CWidgetEntry;
class CWidgetInfo;

// Constants
const TUid KWidgetRegistryServerUid = { 0x10282F06 };
const TUid KUidWidgetUi = { 0x10282822 };
const TUid KUidWidgetLauncher = { 0x10282821 };
const TUid KUidWgtWidgetLauncher = { 0x200267DC };


#define WIDGETPROPERTYLISTVERSION 4

const TInt KWidgetPropertyListVersion32 = 1;
const TInt KWidgetPropertyListVersion71 = 3;
const TInt KWidgetPropertyListVersion71CWRT = 4;

// Before changing these, consider that there will be widgets
// installed on removable memory cards according to an allocation
// scheme using these bounds.
const TInt32 KWidgetUidLowerBound = 0x2000DAD2;
const TInt32 KWidgetUidUpperBound = 0x2000DEB9;

// The current allocation scheme splits the range into two so that
// in-device memory uses one range and removable memory cards use a
// separate range.  Eventually, removable memory is probably going to
// have to use a reallocation scheme on insertion.
const TInt32 KWidgetUidInternalMemoryStart = KWidgetUidLowerBound;
const TInt32 KWidgetUidExternalMemoryStart = (KWidgetUidLowerBound + KWidgetUidUpperBound + 1) / 2; // half way
const TInt32 KWidgetUidExternalMemoryStop = KWidgetUidUpperBound;

// Additions for separation of CWRT Widget UID space from WRT Widget UID space
const TInt32 KWidgetUidWRTInternalMemoryStop = (KWidgetUidInternalMemoryStart + KWidgetUidExternalMemoryStart + 1) / 2;
const TInt32 KWidgetUidCWRTInternalMemoryStart = KWidgetUidWRTInternalMemoryStop;
const TInt32 KWidgetUidCWRTInternalMemoryStop = KWidgetUidExternalMemoryStart;
const TInt32 KWidgetUidWRTExternalMemoryStop = (KWidgetUidExternalMemoryStart + KWidgetUidExternalMemoryStop + 1) / 2;
const TInt32 KWidgetUidCWRTExternalMemoryStart = KWidgetUidWRTExternalMemoryStop;
const TInt32 KWidgetUidCWRTExternalMemoryStop = KWidgetUidUpperBound + 1;


const TInt KWidgetRegistryClientVersionMajor = 0;
const TInt KWidgetRegistryClientVersionMinor = 1;
const TInt KWidgetRegistryClientVersionBuild = 1;
const TInt KWidgetRegistryServerAsynchronousSlotCount = 4;
const TInt KWidgetRegistryVal = KMaxFileName;
const TInt KShutdownDelay = 200000;
const TInt KWidgetRegistryGranularity = 100;
const TInt KWidgetRegistryServerStartupAttempts = 2;

// Literal constants
_LIT( KWidgetRegistryName, "!WidgetRegistry" ); // name to connect to
_LIT( KWidgetRegistryImage, "WidgetRegistry" ); // DLL/EXE name
_LIT8( KWidgetMime, "application/x-nokia-widget");
_LIT( KLauncherApp, "widgetlauncher.exe" );
_LIT( KWgtLauncherApp, "wgtwidgetlauncher.exe" );


// Enumerations
enum TWidgetRegistryClientOpCodes
    {
    EOpCodeRegisterWidget = 0,  // do not change, used in capability policy
    EOpCodeDeRegisterWidget = 1,// do not change, used in capability policy
    EOpCodeWidgetExists,
    EOpCodeIsWidget,
    EOpCodeIsWidgetRunning,
    EOpCodeWidgetCount,
    EOpCodeInstalledWidgetsPhase1,
    EOpCodeInstalledWidgetsPhase2,
    EOpCodeRunningWidgetsPhase1,
    EOpCodeRunningWidgetsPhase2,
    EOpCodeGetWidgetBundleId,
    EOpCodeGetWidgetBundleName,
    EOpCodeGetWidgetPropertyValue,
    EOpCodeGetWidgetPath,
    EOpCodeGetWidgetUid,
    EOpCodeGetWidgetUidForUrl,
    EOpCodeGetAvailableUid,
    EOpCodeSetActive,
    EOpCodeWidgetRegistryDisconnect,
    EOpCodeGetLprojName,
    EOpCodeSecurityPolicyId,
    EOpCodeSetWidgetInMiniView,
    EOpCodeIsWidgetInMiniView,
    EOpCodeSetWidgetInFullView,
    EOpCodeIsWidgetInFullView,
    EOpCodeSetWidgetPromptNeeded,
    EOpCodeIsWidgetPromptNeeded,
    EOpWidgetSapiAccessState,
    EOpCodeNotSupported // must be last
    };


enum TWidgetPropertyId
    {
    // version must be first
    EWidgetPropertyListVersion = 0, // int
// increment version when changing list of properties so when properties
// are written to file with a version header then they can be read in
// by backwards compatible future versions

    // begin from bundle XML configuration file
    EBundleIdentifier,          // required; string; ex.: com.nokia.widget.HelloWorld
    EBundleName,                // required; string; example: Hello World
    EBundleDisplayName,         // required; string; example: Hello World
    EMainHTML,                  // required; string; example: HellowWorld.html
    EBundleShortVersion,        // optional; string; example: 1.0
    EBundleVersion,             // optional; string; example: 1.0
    EHeight,                    // optional; integer; example: 100
    EWidth,                     // optional; integer; example: 100
    // TODO remove EAllowFullAccess (grep and remove all mentions)
    EAllowFullAccess,           // optional; int internally 0 or 1
    EAllowNetworkAccess,        // optional; int internally 0 or 1

    // begin internal properties
    EDriveName,                 // string;
    EBasePath,                  // string; install path for widget, includes drive
    EIconPath,                  // string; icon path only
    EUrl,                       // string;
    EFileSize,                  // int
    EUid,                       // TUid
    ENokiaWidget,               // int 0 (not Nokia DTD) or 1 (Nokia DTD)
    // Do not add enums prior to this, if you are adding enums here 
    // take into consideration the compatibility problems, i.e widgets working after firmware update.  

    EMiniViewEnable,            // optional; int internally 0 0r 1
    EBlanketPermGranted,        // optional; int internally 0 0r 1
    EPreInstalled,              // optional; int internally 0 or 1
    
    EProcessUid,                // int (UID of widget execution process)
    EMimeType,

    // end property list, begin special values
    EWidgetPropertyIdCount,     // must be at end of properties
    EWidgetPropertyIdInvalid = 1000    // must be after EWidgetPropertyIdCount
    };
    
enum TWidgetBlanketPermissionState
    {
    EBlanketUnknown = 0,
    EBlanketTrue,
    EBlanketFalse
    };

typedef RArray<TUid>                RUidArray;

typedef RPointerArray<CWidgetInfo>  RWidgetInfoArray;

#endif
