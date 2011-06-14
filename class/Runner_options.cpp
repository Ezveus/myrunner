//
// Runner_options.cpp for project MyRunner_v2
// 
// Made by Matthieu Ciappara
// Mail : <ciappam@gmail.com>
// 
// Started by Matthieu Ciappara on Thu Jun  9 22:19:53 2011
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

#include	<QMessageBox>
#include	<QApplication>
#include	"Runner_options.hpp"

R_options::R_options()
{
  agw_grid = new QGridLayout;
  apb_about = new QPushButton(tr("&About..."));
  connect(apb_about, SIGNAL(clicked()), this, SLOT(about()));
  ale_alias = new QLineEdit;
  apb_alias_add = new QPushButton(tr("A&dd..."));
  //  connect(apb_alias_add, SIGNAL(clicked()), this, SLOT(add_alias()));
  apb_alias_show = new QPushButton(tr("&Show..."));
  //  connect(apb_alias_show, SIGNAL(clicked()), this, SLOT(show_alias()));
  apb_alias_rm = new QPushButton(tr("&Remove..."));
  //  connect(apb_alias_rm, SIGNAL(clicked()), this, SLOT(rm_alias()));
  apb_close = new QPushButton(tr("&Close..."));
  connect(apb_close, SIGNAL(clicked()), this, SLOT(close()));

  setWindowTitle(tr("Options of MyRunner_v2"));

  ale_alias->setPlaceholderText(tr("Alias='Command'"));

  agw_grid->addWidget(ale_alias, 0, 0, 1, 3);
  agw_grid->addWidget(apb_alias_add, 1, 0);
  agw_grid->addWidget(apb_alias_show, 1, 1);
  agw_grid->addWidget(apb_about, 2, 0);
  agw_grid->addWidget(apb_alias_rm, 1, 2);
  agw_grid->addWidget(apb_close, 2, 2);
  this->setLayout(agw_grid);
}

void	R_options::about()
{
  QMessageBox::information(this, QObject::tr("About MyRunner_v2"), QObject::tr("MyRunner_v2<br/>This programm was created by M.Ciappara.<br/>See the SourceForge page for more informations."));
}

