//
// Runner_show_alias.cpp for project MyRunner
//
// Made by Matthieu Ciappara
// Mail : <ciappam@gmail.com>
//
// Started by Matthieu Ciappara on Wed Jul  6 22:16:10 2011
//

#include "runner_show_alias.hpp"

R_show_aliases::R_show_aliases() {
    agw_grid = new QGridLayout;
    ate_alias_file = new QTextEdit;
    apb_close = new QPushButton("Close");
    connect(apb_close, SIGNAL(clicked()), this, SLOT(close()));

    agw_grid->addWidget(ate_alias_file, 0, 0);
    agw_grid->addWidget(apb_close, 1, 0);
    this->setLayout(agw_grid);
}

R_show_aliases::R_show_aliases(QString text) {
    agw_grid = new QGridLayout;
    ate_alias_file = new QTextEdit(text);
    apb_close = new QPushButton("Close");
    connect(apb_close, SIGNAL(clicked()), this, SLOT(close()));

    agw_grid->addWidget(ate_alias_file, 0, 0);
    agw_grid->addWidget(apb_close, 1, 0);
    this->setLayout(agw_grid);
}

R_show_aliases::R_show_aliases(char *text) {
    agw_grid = new QGridLayout;
    ate_alias_file = new QTextEdit(QString(text));
    apb_close = new QPushButton("Close");
    connect(apb_close, SIGNAL(clicked()), this, SLOT(close()));

    agw_grid->addWidget(ate_alias_file, 0, 0);
    agw_grid->addWidget(apb_close, 1, 0);
    this->setLayout(agw_grid);
}

void R_show_aliases::setText(QString text) {
    ate_alias_file->setText(text);
}

void R_show_aliases::setText(char *text) {
    ate_alias_file->setText(QString(text));
}

void R_show_aliases::setReadOnly(bool b) {
    ate_alias_file->setReadOnly(b);
}
