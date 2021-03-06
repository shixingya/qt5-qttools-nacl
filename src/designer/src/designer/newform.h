/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the Qt Designer of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef NEWFORM_H
#define NEWFORM_H

#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

namespace qdesigner_internal {
    class DeviceProfile;
}

class QDesignerFormEditorInterface;
class QDesignerNewFormWidgetInterface;
class QDesignerWorkbench;

class QCheckBox;
class QAbstractButton;
class QPushButton;
class QDialogButtonBox;
class QImage;
class QIODevice;

class NewForm: public QDialog
{
    Q_OBJECT
    Q_DISABLE_COPY(NewForm)

public:
    NewForm(QDesignerWorkbench *workbench,
            QWidget *parentWidget,
            // Use that file name instead of a temporary one
            const QString &fileName = QString());

    virtual ~NewForm();

    // Convenience for implementing file dialogs with preview
    static QImage grabForm(QDesignerFormEditorInterface *core,
                           QIODevice &file,
                           const QString &workingDir,
                           const qdesigner_internal::DeviceProfile &dp);

private slots:
    void slotButtonBoxClicked(QAbstractButton *btn);
    void recentFileChosen();
    void slotCurrentTemplateChanged(bool templateSelected);
    void slotTemplateActivated();

private:
    QDialogButtonBox *createButtonBox();
    bool openTemplate(QString *ptrToErrorMessage);

    QString m_fileName;
    QDesignerNewFormWidgetInterface *m_newFormWidget;
    QDesignerWorkbench *m_workbench;
    QCheckBox *m_chkShowOnStartup;
    QPushButton *m_createButton;
    QPushButton *m_recentButton;
    QDialogButtonBox *m_buttonBox;
};

QT_END_NAMESPACE

#endif // NEWFORM_H
