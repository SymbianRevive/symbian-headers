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


#ifndef QCONTACTDETAILDEFINITION_H
#define QCONTACTDETAILDEFINITION_H

#include <QStringList>
#include <QString>
#include <QSharedDataPointer>
#include <QVariant>

#include "qtcontactsglobal.h"
#include "qcontactdetailfielddefinition.h"

QTM_BEGIN_NAMESPACE

class QContactDetailDefinitionData;
class Q_CONTACTS_EXPORT QContactDetailDefinition
{
    friend class QContactManager;

public:
    // default constructor: produces an invalid QContactFieldDefinition.
    QContactDetailDefinition();
    ~QContactDetailDefinition();

    /* copy ctor & assignment */
    QContactDetailDefinition(const QContactDetailDefinition& other);
    QContactDetailDefinition& operator=(const QContactDetailDefinition& other);

    /* Comparator (for use in lists) */
    bool operator==(const QContactDetailDefinition& other) const;
    bool operator!=(const QContactDetailDefinition& other) const {return !operator==(other);}

    /* Check emptiness */
    bool isEmpty() const;

    /* name (identifier) of the definition */
    void setName(const QString& definitionName);
    QString name() const;

    /* can you have more than one detail of this definition? */
    void setUnique(bool unique);
    bool isUnique() const;

    /* Mapping of field key to fields allowed in details of this definition */
    void setFields(const QMap<QString, QContactDetailFieldDefinition>& fields);
    QMap<QString, QContactDetailFieldDefinition> fields() const;
    void insertField(const QString& key, const QContactDetailFieldDefinition& field);
    void removeField(const QString& key);

private:
    QSharedDataPointer<QContactDetailDefinitionData> d;

#if defined(SIMULATOR_APPLICATION) || defined(QT_SIMULATOR)
    friend QDataStream &operator<<(QDataStream &, const QContactDetailDefinition &);
    friend QDataStream &operator>>(QDataStream &, QContactDetailDefinition &);
#endif
};

QTM_END_NAMESPACE

Q_DECLARE_TYPEINFO(QTM_PREPEND_NAMESPACE(QContactDetailDefinition), Q_MOVABLE_TYPE);

#endif
