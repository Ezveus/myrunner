//
// Runner_options.hpp for project MyRunner_v2
// 
// Made by Matthieu Ciappara
// Mail : <ciappam@gmail.com>
// 
// Started by Matthieu Ciappara on Thu Jun  9 22:12:26 2011
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

#include	<QObject>
#include	<QPushButton>
#include	<QLineEdit>
#include	<QGridLayout>
#include	<QDialog>
#include	<QFile>
#include	<QList>

#ifndef		RUNNER_OPTIONS_HPP_
# define	RUNNER_OPTIONS_HPP_

class R_options : public QDialog
{
  Q_OBJECT
public:
		R_options();

public slots:
  void		about();
  // int		add_alias();
  // int		rm_alias();

private:
  QGridLayout	*agw_grid;
  QPushButton	*apb_about;
  QPushButton	*apb_close;
  QPushButton	*apb_alias_add;
  QPushButton	*apb_alias_rm;
  QPushButton	*apb_alias_show;
  QLineEdit	*ale_alias;
  // QFile		*afl_alias;
  // QTextStream	*ats_alias;
  // QList<QString>	*als_alias;
};

#endif		// !RUNNER_OPTIONS_HPP_
