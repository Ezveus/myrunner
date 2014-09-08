//
// Runner_options.hpp for project MyRunner_v2
//
// Made by Matthieu Ciappara
// Mail : <ciappam@gmail.com>
//
// Started by Matthieu Ciappara on Thu Jun  9 22:12:26 2011
//

#include <QObject>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QDialog>
#include <QFile>
#include <QList>
#include "myrunner.hpp"
#include "runner_show_alias.hpp"

#ifndef RUNNER_OPTIONS_HPP_
# define RUNNER_OPTIONS_HPP_

class R_options : public QDialog {
    Q_OBJECT
public:
    R_options();

    public slots:
    void about();
    void add_alias();
    void rm_alias();
    void show_alias();

private:
    QGridLayout *agw_grid;
    QPushButton *apb_about;
    QPushButton *apb_close;
    QPushButton *apb_alias_add;
    QPushButton *apb_alias_rm;
    QPushButton *apb_alias_show;
    QLineEdit *ale_alias;
    QFile *afl_alias;
    R_show_aliases *arsa_show_alias;
};

#endif // !RUNNER_OPTIONS_HPP_
