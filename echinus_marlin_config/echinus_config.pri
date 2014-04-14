#
# All files in this archive are subject to the GNU General Public License.
# See the file COPYING in the source tree root for full license agreement.
#
# This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
# KIND, either express or implied.
#


# common files
SOURCES += \
 echinus_config.cpp \
 main.cpp \
    configValues.cpp

HEADERS += \
 echinus_config.h \
 configValues.h \
 version.h \
    win_defines.h

FORMS += echinus_config_frm.ui \
 aboutbox.ui

RESOURCES += echinus_config.qrc
# windows specific files
win32 {
    RESOURCES += echinus_config-win.qrc
}

# unix specific files
unix {
   RESOURCES += echinus_config-lin.qrc
}




