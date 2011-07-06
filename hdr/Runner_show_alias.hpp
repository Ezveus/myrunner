//
// Runner_show_alias.hpp for project MyRunner_v2
// 
// Made by Matthieu Ciappara
// Mail : <ciappam@gmail.com>
// 
// Started by Matthieu Ciappara on Wed Jul  6 21:59:36 2011
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
#include	<QDialog>
#include	<QTextEdit>
#include	<QPushButton>
#include	<QGridLayout>

#ifndef		RUNNER_SHOW_ALIASES_HPP_
# define	RUNNER_SHOW_ALIASES_HPP_

class R_show_aliases : public QDialog
{
  Q_OBJECT
public:
		R_show_aliases();
		R_show_aliases(QString);
		R_show_aliases(char *);
  void		setText(QString);
  void		setText(char *);
  void		setReadOnly(bool
);

private:
  QTextEdit	*ate_alias_file;
  QPushButton	*apb_close;
  QGridLayout	*agw_grid;
};

#endif		// RUNNER_SHOW_ALIASES_HPP_
