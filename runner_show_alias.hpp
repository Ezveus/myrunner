//
// Runner_show_alias.hpp for project MyRunner_v2
//
// Made by Matthieu Ciappara
// Mail : <ciappam@gmail.com>
//
// Started by Matthieu Ciappara on Wed Jul  6 21:59:36 2011
//

#include <QObject>
#include <QDialog>
#include <QTextEdit>
#include <QPushButton>
#include <QGridLayout>

#ifndef RUNNER_SHOW_ALIASES_HPP_
# define RUNNER_SHOW_ALIASES_HPP_

class R_show_aliases : public QDialog {
    Q_OBJECT

public:
    R_show_aliases();
    R_show_aliases(QString);
    R_show_aliases(char *);
    void setText(QString);
    void setText(char *);
    void setReadOnly(bool);

private:
    QTextEdit *ate_alias_file;
    QPushButton *apb_close;
    QGridLayout *agw_grid;
};

#endif // RUNNER_SHOW_ALIASES_HPP_
