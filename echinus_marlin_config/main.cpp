/***************************************************************************
 * All files in this archive are subject to the GNU General Public License.
 * See the file COPYING in the source tree root for full license agreement.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ****************************************************************************/

#include <QtGui>
#include "echinus_config.h"


int main( int argc, char ** argv ) {
   
    QApplication app( argc, argv );

    Echinus_Config window(0);
    window.show();

    return app.exec();

}
