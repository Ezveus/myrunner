#!/bin/sh
## install.sh for project MyRunner_v2
## 
## Made by Matthieu Ciappara
## Mail : <ciappam@gmail.com>
## 
## Started by Matthieu Ciappara on Tue Jun  7 17:20:48 2011
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

echo "Installation begins"
if [ `which /bin/cp` ]; then
    cp -v MyRunner_v2 -t /usr/bin/
    if [ $? = 0 ]; then
	echo "Installation successfull"
    else
	echo "Installation failed. Copy failed."
    fi
else
    echo "Installation failed. Can't find 'cp'"
fi
echo "Installation terminated"