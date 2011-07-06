//
// Runner_show_alias.cpp for project MyRunner_v2
// 
// Made by Matthieu Ciappara
// Mail : <ciappam@gmail.com>
// 
// Started by Matthieu Ciappara on Wed Jul  6 22:16:10 2011
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

#include	"Runner_show_alias.hpp"

R_show_aliases::R_show_aliases()
{
  agw_grid = new QGridLayout;
  ate_alias_file = new QTextEdit;
  apb_close = new QPushButton("Close");
  connect(apb_close, SIGNAL(clicked()), this, SLOT(close()));

  agw_grid->addWidget(ate_alias_file, 0, 0);
  agw_grid->addWidget(apb_close, 1, 0);
  this->setLayout(agw_grid);
}

R_show_aliases::R_show_aliases(QString text)
{
  agw_grid = new QGridLayout;
  ate_alias_file = new QTextEdit(text);
  apb_close = new QPushButton("Close");
  connect(apb_close, SIGNAL(clicked()), this, SLOT(close()));

  agw_grid->addWidget(ate_alias_file, 0, 0);
  agw_grid->addWidget(apb_close, 1, 0);
  this->setLayout(agw_grid);
}

R_show_aliases::R_show_aliases(char *text)
{
  agw_grid = new QGridLayout;
  ate_alias_file = new QTextEdit(QString(text));
  apb_close = new QPushButton("Close");
  connect(apb_close, SIGNAL(clicked()), this, SLOT(close()));

  agw_grid->addWidget(ate_alias_file, 0, 0);
  agw_grid->addWidget(apb_close, 1, 0);
  this->setLayout(agw_grid);
}

void	R_show_aliases::setText(QString text)
{
  ate_alias_file->setText(text);
}

void	R_show_aliases::setText(char *text)
{
  ate_alias_file->setText(QString(text));
}

void	R_show_aliases::setReadOnly(bool b)
{
  ate_alias_file->setReadOnly(b);
}
