/*===================================================================
APM_PLANNER Open Source Ground Control Station

(c) 2014 APM_PLANNER PROJECT <http://www.diydrones.com>
(c) author: Bill Bonney <billbonney@communistech.com>

This file is part of the APM_PLANNER project

    APM_PLANNER is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    APM_PLANNER is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with APM_PLANNER. If not, see <http://www.gnu.org/licenses/>.

======================================================================*/
#include "QsLog.h"
#include "DroneshareDialog.h"
#include "ui_DroneshareDialog.h"
#include <QMessageBox>
#include <QDesktopServices>
#include <QPushButton>
#include <QSettings>

DroneshareDialog::DroneshareDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DroneshareDialog),
    m_skip(false)
{
    ui->setupUi(this);

    ui->textEdit->setTextInteractionFlags(Qt::TextBrowserInteraction);

    connect(ui->skipPushButton, SIGNAL(clicked()), this, SLOT(skipClicked()));
    connect(ui->laterPushButton, SIGNAL(clicked()), this, SLOT(laterClicked()));
//    connect(ui->uploadPushButton, SIGNAL(clicked()), this, SLOT(uploadClicked()));
}

DroneshareDialog::~DroneshareDialog()
{
    delete ui;
}

void DroneshareDialog::laterClicked()
{
    QLOG_DEBUG() << "Dronshare: remind later";
    deleteLater();
    accept();
}

void DroneshareDialog::skipClicked()
{
    QLOG_DEBUG() << "Droneshare: skip till next update";
    QSettings settings;
    settings.beginGroup("QGC_MAINWINDOW");
    settings.setValue("DRONESHARE_NOTIFICATION_ENABLED", false);
    settings.endGroup();
    settings.sync();

    deleteLater();
    reject();
}

void DroneshareDialog::uploadClicked()
{
    // TODO: add code to launch the Dronehare Upload Dialog
    QLOG_DEBUG() << "Dronshare: launch droneshare upload";
}



