//
// Runner.cpp for project MyRunner_v2
// 
// Made by Matthieu Ciappara
// Mail : <ciappam@gmail.com>
// 
// Started by Matthieu Ciappara on Thu Apr 14 16:22:35 2011
//

//
// Copyright (C) <2011> <Ciappara> <Matthieu>
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
//

#include <QMessageBox>
#include <QProcess>
#include <QApplication>
#include "Runner.hpp"

Runner::Runner()
{
  apb_run = new QPushButton(tr("&Run"));
  connect(apb_run, SIGNAL(clicked()), this, SLOT(run()));
  apb_cancel = new QPushButton(tr("&Cancel"));
  connect(apb_cancel, SIGNAL(clicked()), qApp, SLOT(quit()));
  apb_about = new QPushButton(tr("&About..."));
  connect(apb_about, SIGNAL(clicked()), this, SLOT(about()));
  ale_input = new QLineEdit;
  agw_grid = new QGridLayout;

  setWindowTitle("MyRunner_v2");

  ale_input->setPlaceholderText(tr("Enter a command here..."));

  agw_grid->addWidget(ale_input, 0, 0, 1, 4);
  agw_grid->addWidget(apb_run, 1, 3, 1, 1);
  agw_grid->addWidget(apb_cancel, 1, 2, 1, 1);
  agw_grid->addWidget(apb_about, 1, 0, 1, 1);

  this->setLayout(agw_grid);
}

void	Runner::run()
{
  if (!QProcess::startDetached(ale_input->text()))
    QMessageBox::critical(this, tr("Error"), tr("This programm can't be launched<br/>Maybe, it is not installed."));
  else
    this->close();
}

void	Runner::about()
{
  QMessageBox::information(this, QObject::tr("About MyRunner_v2"), QObject::tr("MyRunner_v2<br/>This programm was created by M.Ciappara.<br/>See the SourceForge page for more informations."));
}
