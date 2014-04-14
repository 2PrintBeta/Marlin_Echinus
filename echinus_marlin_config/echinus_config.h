/***************************************************************************
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ****************************************************************************/


#ifndef ECHINUS_FLASH_H
#define ECHINUS_FLASH_H

#include "ui_echinus_config_frm.h"

#if defined(Q_OS_WIN32)
#include <windows.h>
#include <setupapi.h>
#include <dbt.h>
#endif
#include <QtGui>
#include "configValues.h"

/*!
 * Structure containing port information.
 */
struct PortInfo {
    QString portName;   ///< Port name.
    QString friendName; ///< Friendly name.
};

class SerialRegistrationWidget;

class Echinus_Config : public QMainWindow
{
    Q_OBJECT

    public:
        Echinus_Config(QWidget *parent = 0);
#if defined(Q_OS_WIN32)
		//wird von der Hilfsklasse aufgerufen wenn sich bei den devices was ändert
        LRESULT onDeviceChange( WPARAM wParam, LPARAM lParam );
#endif
    private:
		//gui
        Ui::Echinus_Config_frm ui;

    private slots:

        //zeige about window
        void about(void);
        void serialConnect();

        void serialConnected();
        void serialDisconnected();

        //reagiere auf änderungen
        void stepPerMmChanged(int index);
        void maxFeedrateChanged(int index);
        void maxAccelerationChanged(int index);
        void invertDirChanged(int index);


    private slots:
        //alle com ports enumerieren
        void enumerate_comports();

        void importConfig();
        void reloadDefaults();
    private:

        void updateUI();

#if defined(Q_OS_WIN32)
        //com port details abrufen
        void getPortDetails( PortInfo* portInfo, HDEVINFO devInfo,
                                          PSP_DEVINFO_DATA devData );
        QTimer *m_timer;
        QStringList m_devices;
        // Ptr zu hilfsfenster
        SerialRegistrationWidget* notificationWidget;
#elif defined(Q_OS_UNIX)
         QTimer *m_timer;
         QStringList m_devices;
#endif
        // classe mit allen config werten
        ConfigValues configValues;

        //signal mappers
        QSignalMapper stepsPerMmNrMapper;
        QSignalMapper maxFeedrateMapper;
        QSignalMapper maxAccelerationMapper;
        QSignalMapper substeppingMapper;
        QSignalMapper invertDirMapper;

        // ui elements
        QDoubleSpinBox* stepPerMm[4];
        QDoubleSpinBox* maxFeedrate[4];
        QSpinBox* maxAcceleration[4];
        QCheckBox* invertDir[5];

};

#if defined(Q_OS_WIN32)
// Hilfsclasse um com port änderungen mitzubekommen
class SerialRegistrationWidget : public QWidget
{
    Q_OBJECT
    public:
        SerialRegistrationWidget( Echinus_Config* qese ) {
            this->qese = qese;
        }
        ~SerialRegistrationWidget( ) { }

    protected:
        Echinus_Config* qese;
        bool nativeEvent(const QByteArray & eventType, void * message, long * result);

        //bool winEvent( MSG* message, long* result );
};
#endif
#endif

