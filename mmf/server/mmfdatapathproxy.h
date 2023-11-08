// Copyright (c) 2001-2009 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of "Eclipse Public License v1.0"
// which accompanies this distribution, and is available
// at the URL "http://www.eclipse.org/legal/epl-v10.html".
//
// Initial Contributors:
// Nokia Corporation - initial contribution.
//
// Contributors:
//
// Description:
//

#ifndef __MMFDATAPATHPROXY_H__
#define __MMFDATAPATHPROXY_H__

#include <e32base.h>
#include <e32std.h>
#include <ecom/ecom.h>
#include <mmf/server/mmfdatapath.h>
#include <mmf/server/mmfsubthreadbase.h>

#define KMMFDataPathProxyVersion TVersion(8,0,0)

/**
The amount of time that is allowed for the datapath to close down before the its thread is killed.
*/
#define  KMMFDataPathProxyShutdownTimeout TTimeIntervalMicroSeconds32(10000000)


/**
@publishedAll
@released

Mixin class that the user of the class CMMFDataPathEventMonitor must derive from.

@since 7.0s
*/
class MMMFDataPathEventMonitorObserver
	{
public:

	/**
	Handles an event that has been generated by the datapath.

	Called by CMMFDataPathEventMonitor::RunL().

	@param  aEvent
	        The event to be handled.

	@since  7.0s
	*/
	virtual void HandleEvent(const TMMFEvent& aEvent) = 0;
	};

class RMMFDataPathProxy; //forward reference

/**
@publishedAll
@released

Active object utility class that can be used to monitor a datapath that is running in its own
thread for events. If an event occurs, the client will be notified via the
MMMFDataPathEventMonitorObserver interface.

@since  7.0s
*/
class CMMFDataPathEventMonitor : public CActive
	{
public:

	IMPORT_C static CMMFDataPathEventMonitor* NewL(MMMFDataPathEventMonitorObserver& aObserver,
		RMMFDataPathProxy& aMMFDataPathProxy);

	IMPORT_C ~CMMFDataPathEventMonitor();

	IMPORT_C void Start();

	IMPORT_C void RunL();
protected:

	void DoCancel();
private:

	/**
	Constructs a datapath event monitor object.

	@param  aObserver
	        A reference to the observer of the active object. The observer will be
	        notified when an event occurs.
	@param  aMMFDataPathProxy
	        A reference to the datapath proxy class.

	@since  7.0s
	*/
	CMMFDataPathEventMonitor(MMMFDataPathEventMonitorObserver& aObserver, 
		RMMFDataPathProxy& aMMFDataPathProxy);
private:
	MMMFDataPathEventMonitorObserver& iObserver;
	RMMFDataPathProxy& iMMFDataPathProxy;
	TMMFEventPckg iEventPckg;
	};

/**
@publishedAll
@released

Proxy class used to create a datapath in a new subthread.
*/
class RMMFDataPathProxy : public RMMFSubThreadBase

	{
public:

	/**
	Constuctor.
	*/
	RMMFDataPathProxy() : RMMFSubThreadBase(KMMFDataPathProxyShutdownTimeout) {};

	IMPORT_C TInt CreateSubThread();

	IMPORT_C TInt LoadDataPath();

	IMPORT_C TInt LoadDataPath(TMediaId aMediaId);

	IMPORT_C TInt LoadDataPath(TUid aCodecUid); 

	IMPORT_C TInt LoadDataPath(TUid aCodecUid, TMediaId aMediaId);

	IMPORT_C TInt AddDataSource(MDataSource* aSource);

	IMPORT_C TInt AddDataSink(MDataSink* aSink);

	IMPORT_C TInt Prime();

	IMPORT_C TInt Play();

	IMPORT_C TInt Pause();

	IMPORT_C TInt Stop();

	IMPORT_C TInt GetPosition(TTimeIntervalMicroSeconds& aPosition) const;

	IMPORT_C TInt SetPosition(const TTimeIntervalMicroSeconds& aPosition);

	IMPORT_C TInt SetPlayWindow( const TTimeIntervalMicroSeconds& aStart, const TTimeIntervalMicroSeconds& aEnd ) ;

	IMPORT_C TInt ClearPlayWindow() ;

	IMPORT_C TInt State( TInt& aState ) ;

	IMPORT_C void Close();
	};

#ifndef SYMBIAN_ENABLE_SPLIT_HEADERS
#include <mmf/server/mmfdatapathproxyserver.h>
#endif

#endif
