/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the Qt Mobility Components.
**
** $QT_BEGIN_LICENSE:LGPL$
** No Commercial Usage
** This file contains pre-release code and may not be distributed.
** You may use this file in accordance with the terms and conditions
** contained in the Technology Preview License Agreement accompanying
** this package.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
**
**
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/


#ifndef QCONTACTMANAGERENGINEFACTORY_H
#define QCONTACTMANAGERENGINEFACTORY_H

#include <QtPlugin>
#include <QMap>
#include <QString>

#include "qcontactmanager.h"

QTM_BEGIN_NAMESPACE
/* Backend plugin API interface, creates engines for us */
class QContactManagerEngine;
class Q_CONTACTS_EXPORT QContactManagerEngineFactory
{
public:
    // engine factory functions
    virtual QList<int> supportedImplementationVersions() const;
    virtual ~QContactManagerEngineFactory();
    virtual QContactManagerEngine* engine(const QMap<QString, QString>& parameters, QContactManager::Error* error) = 0;
    virtual QString managerName() const = 0;
};
QTM_END_NAMESPACE

QT_BEGIN_NAMESPACE
#define QT_CONTACTS_BACKEND_INTERFACE "com.nokia.qt.mobility.contacts.enginefactory/1.0"
Q_DECLARE_INTERFACE(QtMobility::QContactManagerEngineFactory, QT_CONTACTS_BACKEND_INTERFACE);
QT_END_NAMESPACE

#endif
