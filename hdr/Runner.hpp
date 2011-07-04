//
// Runner.hpp for project MyRunner_v2
// 
// Made by Matthieu Ciappara
// Mail : <ciappam@gmail.com>
// 
// Started by Matthieu Ciappara on Thu Apr 14 16:22:07 2011
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
#include	<QString>
#include	"MyRunner_v2.hpp"
#include	"Runner_options.hpp"

#ifndef		RUNNER_HPP_
# define	RUNNER_HPP_

class Runner : public QDialog
{
  Q_OBJECT
public:
		Runner();
  static void	fill_aliases(QFile *, QList<QString> *);
  int		search_aliases(QString);

public slots:
  void		run();
  void		options();

private:
  QPushButton	*apb_run;
  QPushButton	*apb_cancel;
  QPushButton	*apb_options;
  QLineEdit	*ale_input;
  QGridLayout	*agw_grid;
  R_options	*aro_options;
  QFile		*afl_alias;
  QList<QString>	*als_alias;
};

#endif		// !RUNNER_HPP_
