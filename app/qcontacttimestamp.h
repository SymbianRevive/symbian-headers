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

#ifndef QCONTACTTIMESTAMP_H
#define QCONTACTTIMESTAMP_H

#include <QString>

#include "qtcontactsglobal.h"
#include "qcontactdetail.h"
#include "qcontact.h"

QTM_BEGIN_NAMESPACE

/* Leaf class */
class Q_CONTACTS_EXPORT QContactTimestamp : public QContactDetail
{
public:
#ifdef Q_QDOC
    static const QLatin1Constant DefinitionName;
    static const QLatin1Constant FieldModificationTimestamp;
    static const QLatin1Constant FieldCreationTimestamp;
#else
    Q_DECLARE_CUSTOM_CONTACT_DETAIL(QContactTimestamp, "Timestamp")
    Q_DECLARE_LATIN1_CONSTANT(FieldModificationTimestamp, "ModificationTimestamp");
    Q_DECLARE_LATIN1_CONSTANT(FieldCreationTimestamp, "CreationTimestamp");
#endif

    void setLastModified(const QDateTime& timestamp) {setValue(FieldModificationTimestamp, timestamp);}
    QDateTime lastModified() const {return value<QDateTime>(FieldModificationTimestamp);}
    void setCreated(const QDateTime& timestamp) {setValue(FieldCreationTimestamp, timestamp);}
    QDateTime created() const {return value<QDateTime>(FieldCreationTimestamp);}
};

QTM_END_NAMESPACE

#endif
