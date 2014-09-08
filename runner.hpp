//
// Runner.hpp for project MyRunner
//
// Made by Matthieu Ciappara
// Mail : <ciappam@gmail.com>
//
// Started by Matthieu Ciappara on Thu Apr 14 16:22:07 2011
//

#include <QObject>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QDialog>
#include <QFile>
#include <QList>
#include <QString>
#include "myrunner.hpp"
#include "runner_options.hpp"

#ifndef RUNNER_HPP_
# define RUNNER_HPP_

class Runner : public QDialog {
    Q_OBJECT

public:
    Runner();
    static void fill_aliases(QFile *, QList<QString> *);
    int search_aliases(QString);

    public slots:
    void run();
    void options();

private:
    QPushButton *apb_run;
    QPushButton *apb_cancel;
    QPushButton *apb_options;
    QLineEdit *ale_input;
    QGridLayout *agw_grid;
    R_options *aro_options;
    QFile *afl_alias;
    QList<QString> *als_alias;
};

#endif // !RUNNER_HPP_
