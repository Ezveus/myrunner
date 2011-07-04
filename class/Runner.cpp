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

#include	<QProcess>
#include	<QApplication>
#include	<QMessageBox>
#include	<QTextStream>
#include	<cstdlib>
#include	"Runner.hpp"

Runner::Runner()
{
  apb_run = new QPushButton(tr("&Run"));
  connect(apb_run, SIGNAL(clicked()), this, SLOT(run()));
  apb_cancel = new QPushButton(tr("&Cancel"));
  connect(apb_cancel, SIGNAL(clicked()), qApp, SLOT(quit()));
  apb_options = new QPushButton(tr("&Options"));
  connect(apb_options, SIGNAL(clicked()), this, SLOT(options()));
  ale_input = new QLineEdit;
  agw_grid = new QGridLayout;
  aro_options = new R_options;
  aro_options->setModal(true);
  afl_alias = new QFile(QString(getenv("HOME")) + "/.config/MyRunner_v2/aliases");
  als_alias = new QList<QString>;

  setWindowTitle("MyRunner_v2");

  ale_input->setPlaceholderText(tr("Enter a command here..."));

  agw_grid->addWidget(ale_input, 0, 0, 1, 4);
  agw_grid->addWidget(apb_run, 1, 3, 1, 1);
  agw_grid->addWidget(apb_cancel, 1, 2, 1, 1);
  agw_grid->addWidget(apb_options, 1, 0, 1, 1);

  this->setLayout(agw_grid);
  fill_aliases(afl_alias, als_alias);
}

void	Runner::run()
{
  if (!QProcess::startDetached(ale_input->text()))
    if (!search_aliases(ale_input->text()))
      QMessageBox::critical(this, tr("Error"), tr("The programm ") + ale_input->text() + tr(" can't be found."));
    else
      this->close();
  else
    this->close();
}

void	Runner::options()
{
  aro_options->show();
}

void	Runner::fill_aliases(QFile *fl_alias, QList<QString> *ls_alias)
{
  QTextStream	ts_alias(fl_alias);

  if (!fl_alias->open(QIODevice::ReadOnly))
    qWarning("%s\n", E_AL_OPEN);
  else
    {
      while (!ts_alias.atEnd())
	ls_alias->append(ts_alias.readLine());
      fl_alias->close();
    }
}

int	Runner::search_aliases(QString prog)
{
  for (int i = 0; i < als_alias->size(); i++)
    {
      if (als_alias->at(i).at(0) != '#' &&
	  prog == als_alias->at(i).section('=', 0, 0))
	return(QProcess::startDetached(als_alias->at(i).section('=', 1)));
    }
  return (0);
}
