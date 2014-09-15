//
// myrunner.hpp for project MyRunner
//
// Made by Matthieu Ciappara
// Mail : <ciappam@gmail.com>
//
// Started by Matthieu Ciappara on Thu Apr 14 16:19:45 2011
//

#ifndef MYRUNNER_HPP_
#define MYRUNNER_HPP_

#define E_AL_OPEN "Can't open aliases list"

#ifdef WINDOWS_SYSTEM
#define ROOT_CONFIG_DIR (QString(getenv("APPDATA")) + "/")
#endif

#ifdef UNIX_SYSTEM
#define ROOT_CONFIG_DIR (QString(getenv("HOME")) + "/.config/")
#endif

namespace MyRunner {
    QString getConfigLocation();
}

#endif // !MYRUNNER_HPP_
