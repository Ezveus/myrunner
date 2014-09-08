//
// runner_options.cpp for project MyRunner
//
// Made by Matthieu Ciappara
// Mail : <ciappam@gmail.com>
//
// Started by Matthieu Ciappara on Thu Jun  9 22:19:53 2011
//

#include <QMessageBox>
#include <QApplication>
#include <QTextEdit>
#include <QDir>
#include <QTextStream>
#include <QRegExp>
#include <cstdio>
#include "runner_options.hpp"

#define AUTO_CREATED "## This aliases file was automatically created by MyRunner_v2"

R_options::R_options() {
    agw_grid = new QGridLayout;
    apb_about = new QPushButton(tr("&About..."));
    connect(apb_about, SIGNAL(clicked()), this, SLOT(about()));
    ale_alias = new QLineEdit;
    apb_alias_add = new QPushButton(tr("A&dd..."));
    connect(apb_alias_add, SIGNAL(clicked()), this, SLOT(add_alias()));
    apb_alias_show = new QPushButton(tr("&Show..."));
    connect(apb_alias_show, SIGNAL(clicked()), this, SLOT(show_alias()));
    apb_alias_rm = new QPushButton(tr("&Remove..."));
    connect(apb_alias_rm, SIGNAL(clicked()), this, SLOT(rm_alias()));
    apb_close = new QPushButton(tr("&Close..."));
    connect(apb_close, SIGNAL(clicked()), this, SLOT(close()));
    afl_alias = new QFile(QString(getenv("HOME")) + "/.config/MyRunner_v2/aliases");
    arsa_show_alias = new R_show_aliases;
    arsa_show_alias->setModal(true);
    arsa_show_alias->setReadOnly(true);

    setWindowTitle(tr("Options of MyRunner_v2"));

    ale_alias->setPlaceholderText(tr("Alias='Command'")); //Not available with Qt 4.2

    agw_grid->addWidget(ale_alias, 0, 0, 1, 3);
    agw_grid->addWidget(apb_alias_add, 1, 0);
    agw_grid->addWidget(apb_alias_show, 1, 1);
    agw_grid->addWidget(apb_about, 2, 0);
    agw_grid->addWidget(apb_alias_rm, 1, 2);
    agw_grid->addWidget(apb_close, 2, 2);
    this->setLayout(agw_grid);
}

void R_options::about() {
    QMessageBox::information(this, QObject::tr("About MyRunner_v2"), QObject::tr("MyRunner_v2<br/>This programm was created by M.Ciappara.<br/>See the SourceForge page for more informations."));
}

void R_options::show_alias(){
    if (afl_alias->open(QIODevice::ReadOnly)) {
        arsa_show_alias->setText(QString(afl_alias->readAll()));
        afl_alias->close();
        arsa_show_alias->show();
    } else {
        QMessageBox::critical(this, tr("Error"), tr("No aliases were defined."));
    }
}

void R_options::add_alias() {
    QString dirpath(getenv("HOME"));
    dirpath += "/.config/MyRunner_v2/";
    QDir dir(dirpath);

    if (!dir.exists(dirpath)) {
        if (!dir.mkpath(dirpath)) {
            qWarning("Error : Can't create directory\n");
        }
    }
    if (!afl_alias->exists()) {
        FILE *file = fopen(qPrintable(QString(getenv("HOME")) + "/.config/MyRunner_v2/aliases"), "w");

        if (!file) {
            qWarning("Can't create aliases file\n");
        } else {
            fprintf(file, "%s\n", AUTO_CREATED);
            qWarning("File created\n");
            fclose(file);
        }
    }
    if (afl_alias->open(QIODevice::Append)) {
        QTextStream	ts(afl_alias);

        qWarning("File opened in append mode");
        if (ale_alias->text().contains(QRegExp(".=.")) || ale_alias->text().startsWith('#')) {
            ts << ale_alias->text();
            ts << "\n";
            qWarning("Alias wrotten : \"%s\"", qPrintable(ale_alias->text()));
        } else {
            QMessageBox::information(this, tr("Syntax Error"), tr("syntax is :<br />alias=command"));
        }
        ale_alias->setText("");
        afl_alias->close();
        qWarning("File closed\n");
    } else {
        QMessageBox::critical(this, tr("Error"), tr("Can't add alias."));
    }
}

void R_options::rm_alias() {
    QTextStream ts_alias(afl_alias);
    QString tmp;
    QFile *fl_alias_new = new QFile(QString(getenv("HOME")) + "/.config/MyRunner_v2/aliases.tmp");
    QTextStream ts_alias_new(fl_alias_new);

    if (!afl_alias->open(QIODevice::ReadOnly) || !fl_alias_new->open(QIODevice::WriteOnly)) {
        qWarning("%s\n", E_AL_OPEN);
    } else {
        qWarning("Files opened in Read and Write modes.\n");
        while (!ts_alias.atEnd()) {
            tmp = ts_alias.readLine();
            if (tmp.section('=', 0, 0) != ale_alias->text()) {
                ts_alias_new << tmp;
                ts_alias_new << "\n";
            }
        }
        afl_alias->remove();
        fl_alias_new->rename(QString(getenv("HOME")) + "/.config/MyRunner_v2/aliases");
    }
    ale_alias->setText("");
    delete fl_alias_new;
}
