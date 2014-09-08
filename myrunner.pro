##
## myrunner.pro for project MyRunner
##
## Made by Matthieu Ciappara
## Mail : <ciappam@gmail.com>
##
## Started by Matthieu Ciappara on Thu Apr 14 16:17:03 2011
##

QT += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = myrunner
TEMPLATE = app

HEADERS += myrunner.hpp runner.hpp runner_options.hpp runner_show_alias.hpp
SOURCES += main.cpp runner.cpp runner_options.cpp runner_show_alias.cpp

OBJECTS_DIR = ./output
MOC_DIR = ./output
RCC_DIR = ./output

## EOF
