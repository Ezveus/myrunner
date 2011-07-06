##
## MyRunner_v2.pro for project MyRunner_v2
## 
## Made by Matthieu Ciappara
## Mail : <ciappam@gmail.com>
## 
## Started by Matthieu Ciappara on Thu Apr 14 16:17:03 2011
##

##
## Copyright (C) <2011> <Ciappara> <Matthieu>
## This program is free software; you can redistribute it and/or
## modify it under the terms of the GNU Lesser General Public
## License as published by the Free Software Foundation; either
## version 2.1 of the License, or (at your option) any later version.
## 
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
## Lesser General Public License for more details.
## 
## You should have received a copy of the GNU Lesser General Public
## License along with this program; if not, write to the Free Software
## Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
##

TEMPLATE = app
TARGET = MyRunner_v2
DEPENDPATH += . ./src ./class
INCLUDEPATH += . ./hdr

HEADERS += ./hdr/MyRunner_v2.hpp ./hdr/Runner.hpp ./hdr/Runner_options.hpp ./hdr/Runner_show_alias.hpp
SOURCES += main.cpp Runner.cpp Runner_options.cpp Runner_show_alias.cpp
#RESOURCES += ./rsrcs/rsrcs.qrc

OBJECTS_DIR = ./output
MOC_DIR = ./output
RCC_DIR = ./output

#TRANSLATIONS = ./lang/MyRunner_v2_fr.ts ./lang/MyRunner_v2_de.ts

## EOF
