//
// runner.cpp for project MyRunner
//
// Made by Matthieu Ciappara
// Mail : <ciappam@gmail.com>
//
// Started by Matthieu Ciappara on Thu Apr 14 16:22:35 2011
//

#include <QProcess>
#include <QApplication>
#include <QMessageBox>
#include <QTextStream>
#include <QRegExp>
#include <cstdlib>
#include "runner.hpp"

Runner::Runner() {
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
    afl_alias = new QFile(MyRunner::getConfigLocation() + "aliases");
    als_alias = new QList<QString>;

    setWindowTitle("MyRunner");

    ale_input->setPlaceholderText(tr("Enter a command here...")); // Not available with Qt 4.2

    agw_grid->addWidget(ale_input, 0, 0, 1, 4);
    agw_grid->addWidget(apb_run, 1, 3, 1, 1);
    agw_grid->addWidget(apb_cancel, 1, 2, 1, 1);
    agw_grid->addWidget(apb_options, 1, 0, 1, 1);

    this->setLayout(agw_grid);
    fill_aliases(afl_alias, als_alias);
}

void Runner::run() {
    fill_aliases(afl_alias, als_alias);
    if (!QProcess::startDetached(ale_input->text())) {
        if (!search_aliases(ale_input->text())) {
            QMessageBox::critical(this, tr("Error"), tr("The program ") + ale_input->text() + tr(" can't be found."));
        } else {
            this->close();
        }
    } else {
        this->close();
    }
}

void Runner::options() {
    aro_options->show();
}

void Runner::fill_aliases(QFile *fl_alias, QList<QString> *ls_alias) {
    QTextStream ts_alias(fl_alias);
    QString tmp;

    if (!fl_alias->open(QIODevice::ReadOnly)) {
        qWarning("%s\n", E_AL_OPEN);
    } else {
        while (!ts_alias.atEnd()) {
            tmp = ts_alias.readLine();
            if (!tmp.startsWith('#') && tmp.contains(QRegExp(".=."))) {
                ls_alias->append(tmp);
            }
        }
        fl_alias->close();
    }
}

int	Runner::search_aliases(QString prog) {
    for (int i = 0; i < als_alias->size(); i++) {
        if (als_alias->at(i).section('=', 0, 0) == prog) {
        	return(QProcess::startDetached(als_alias->at(i).section('=', 1)));
        }
    }
    return (0);
}
