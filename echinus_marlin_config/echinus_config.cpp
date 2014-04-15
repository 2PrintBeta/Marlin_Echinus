/***************************************************************************
 *
 * All files in this archive are subject to the GNU General Public License.
 * See the file COPYING in the source tree root for full license agreement.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ****************************************************************************/



#include "echinus_config.h"
#include "ui_echinus_config_frm.h"
#include "ui_aboutbox.h"
#include "version.h"
#include "qmessagebox.h"


#if defined(Q_OS_LINUX)
#include <stdio.h>
#endif
#if defined(Q_OS_WIN32)
#if defined(UNICODE)
#define _UNICODE
#endif
#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include <Initguid.h>
#include <win_defines.h>


bool SerialRegistrationWidget::nativeEvent(const QByteArray & eventType, void * message, long * result)
{
    qDebug() << "event detected";
    MSG* msg = reinterpret_cast<MSG*>(message);
    if ( msg->message == WM_DEVICECHANGE ) {
        qese->onDeviceChange( msg->wParam, msg->lParam );
        *result = 1;
        return true;
    }
    return false;
}

 #endif

Echinus_Config::Echinus_Config(QWidget *parent) : QMainWindow(parent)
{
    // init gui
    ui.setupUi(this);

    //buttons verbinden
    connect(ui.actionAbout_Qt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    connect(ui.action_About, SIGNAL(triggered()), this, SLOT(about()));
    connect(ui.connect,SIGNAL(clicked()),this,SLOT(serialConnect()));
    connect(ui.disconnect,SIGNAL(clicked()),&configValues,SLOT(serialDisconnect()));
    connect(ui.saveConfig,SIGNAL(clicked()),&configValues,SLOT(saveConfig()));
    connect(ui.import_config,SIGNAL(clicked()),this,SLOT(importConfig()));
    connect(ui.export_config,SIGNAL(clicked()),&configValues,SLOT(exportConfig()));
    connect(ui.reloadDefaults,SIGNAL(clicked()),this,SLOT(reloadDefaults()));

    // auf serial ändungen horchen
    connect(&configValues,SIGNAL(connected()),this,SLOT(serialConnected()));
    connect(&configValues,SIGNAL(disconnected()),this,SLOT(serialDisconnected()));

    // liste von ui elemente befüllen für comfortablen zugriff

    stepPerMm[0] = ui.stepsPerMm1;
    stepPerMm[1] = ui.stepsPerMm2;
    stepPerMm[2] = ui.stepsPerMm3;
    stepPerMm[3] = ui.stepsPerMm4;

    maxFeedrate[0] = ui.maxFeedrate1;
    maxFeedrate[1] = ui.maxFeedrate2;
    maxFeedrate[2] = ui.maxFeedrate3;
    maxFeedrate[3] = ui.maxFeedrate4;

    maxAcceleration[0] = ui.maxAccel1;
    maxAcceleration[1] = ui.maxAccel2;
    maxAcceleration[2] = ui.maxAccel3;
    maxAcceleration[3] = ui.maxAccel4;

    invertDir[0] = ui.invertDir1;
    invertDir[1] = ui.invertDir2;
    invertDir[2] = ui.invertDir3;
    invertDir[3] = ui.invertDir4;
    invertDir[4] = ui.invertDir5;
    invertDir[5] = ui.invertDir6;
    invertDir[6] = ui.invertDir7;

    //UI options verbinden

    for(int i=0; i < 4; i++)
    {
        connect(stepPerMm[i],SIGNAL(valueChanged(double)),&stepsPerMmNrMapper,SLOT(map()));
        stepsPerMmNrMapper.setMapping(stepPerMm[i],i);
    }
    connect(&stepsPerMmNrMapper,SIGNAL(mapped(int)),this,SLOT(stepPerMmChanged(int)));

    for(int i=0; i < 4; i++)
    {
        connect(maxFeedrate[i],SIGNAL(valueChanged(double)),&maxFeedrateMapper,SLOT(map()));
        maxFeedrateMapper.setMapping(maxFeedrate[i],i);
    }
    connect(&maxFeedrateMapper,SIGNAL(mapped(int)),this,SLOT(maxFeedrateChanged(int)));

    for(int i=0; i < 4; i++)
    {
        connect(maxAcceleration[i],SIGNAL(valueChanged(int)),&maxAccelerationMapper,SLOT(map()));
        maxAccelerationMapper.setMapping(maxAcceleration[i],i);
    }
    connect(&maxAccelerationMapper,SIGNAL(mapped(int)),this,SLOT(maxAccelerationChanged(int)));


    for(int i=0; i < 7; i++)
    {
        connect(invertDir[i],SIGNAL(stateChanged(int)),&invertDirMapper,SLOT(map()));
        invertDirMapper.setMapping(invertDir[i],i);
    }
    connect(&invertDirMapper,SIGNAL(mapped(int)),this,SLOT(invertDirChanged(int)));


    connect(ui.acceleration_retract,SIGNAL(valueChanged(double)),&configValues,SLOT(setRetractAcceleration(double)));
    connect(ui.acceleration,SIGNAL(valueChanged(double)),&configValues,SLOT(setAcceleration(double)));

    connect(ui.pidP1,SIGNAL(valueChanged(double)),&configValues,SLOT(setPidP(double)));
    connect(ui.pidI1,SIGNAL(valueChanged(double)),&configValues,SLOT(setPidI(double)));
    connect(ui.pidD1,SIGNAL(valueChanged(double)),&configValues,SLOT(setPidD(double)));
    connect(ui.pidC1,SIGNAL(valueChanged(double)),&configValues,SLOT(setPidC(double)));

    connect(ui.minFeedrate,SIGNAL(valueChanged(double)),&configValues,SLOT(setMinFeedRate(double)));
    connect(ui.minTravelFeedrate,SIGNAL(valueChanged(double)),&configValues,SLOT(setMinTravelFeedrate(double)));
    connect(ui.maxXYJerk,SIGNAL(valueChanged(double)),&configValues,SLOT(setMaxXYjerk(double)));
    connect(ui.maxZjerk,SIGNAL(valueChanged(double)),&configValues,SLOT(setMaxZjerk(double)));
    connect(ui.maxEjerk,SIGNAL(valueChanged(double)),&configValues,SLOT(setMaxEjerk(double)));

    connect(ui.extruderOffsetX,SIGNAL(valueChanged(double)),&configValues,SLOT(setExtruderXOffset(double)));
    connect(ui.extruderOffsetY,SIGNAL(valueChanged(double)),&configValues,SLOT(setExtruderYOffset(double)));
    connect(ui.extruderOffsetZ,SIGNAL(valueChanged(double)),&configValues,SLOT(setExtruderZOffset(double)));

    connect(ui.HotendTempPla,SIGNAL(valueChanged(int)),&configValues,SLOT(setPreheatPlaHotend(int)));
    connect(ui.bedTempPla,SIGNAL(valueChanged(int)),&configValues,SLOT(setPreheatPlaBed(int)));
    connect(ui.fanSpeedPla,SIGNAL(valueChanged(int)),&configValues,SLOT(setPreheatPlaFan(int)));

    connect(ui.hotendtempAbs,SIGNAL(valueChanged(int)),&configValues,SLOT(setPreheatAbsHotend(int)));
    connect(ui.bedTempAbs,SIGNAL(valueChanged(int)),&configValues,SLOT(setPreheatAbsBed(int)));
    connect(ui.fanSpeedAbs,SIGNAL(valueChanged(int)),&configValues,SLOT(setPreheatAbsFan(int)));

    m_timer = new QTimer(this);
    m_timer->setInterval(1000);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(enumerate_comports( )));
    m_timer->start();

    //existierende comports einfügen
    enumerate_comports();

}

void Echinus_Config::stepPerMmChanged(int index)
{
    configValues.setStepsPerMm(index, stepPerMm[index]->value());
}

void Echinus_Config::maxFeedrateChanged(int index)
{
     configValues.setMaxFeedrate(index, maxFeedrate[index]->value());
}

void Echinus_Config::maxAccelerationChanged(int index)
{
     configValues.setMaxAcceleration(index, maxAcceleration[index]->value());
}

void Echinus_Config::invertDirChanged(int index)
{
     configValues.setInvertDir(index, invertDir[index]->isChecked());
}

void Echinus_Config::importConfig()
{
    configValues.importConfig();
    updateUI();
}

void Echinus_Config::reloadDefaults()
{
    configValues.reloadDefaults();
    updateUI();
}

void Echinus_Config::serialConnect()
{
    //Comport holen und prüfen
    QString comport = ui.com_port->itemData(ui.com_port->currentIndex()).toString();
    if(comport.isEmpty())
    {
        QMessageBox::warning(this,"Error","You have to select a com port first.");
        return;
    }

    configValues.serialConnect(comport);
}


void Echinus_Config::serialConnected()
{
    updateUI();

    ui.motorGroup->setEnabled(true);
    ui.pidGroup->setEnabled(true);
    ui.accelerationGroup->setEnabled(true);
    ui.advancedGroup->setEnabled(true);
    ui.ExtruderOffsetGroup->setEnabled(true);
    ui.preheatGroupPla->setEnabled(true);
    ui.preheatGroupAbs->setEnabled(true);
}


void Echinus_Config::updateUI()
{
    ui.firmware_version->setText(configValues.firmwareVersion());

    for(int i=0; i < 4; i++)
    {
        stepPerMm[i]->blockSignals(true);
        stepPerMm[i]->setValue(configValues.getStepsPerMm(i));
        stepPerMm[i]->blockSignals(false);
    }

    for(int i=0; i < 4; i++)
    {
        maxFeedrate[i]->blockSignals(true);
        maxFeedrate[i]->setValue(configValues.getMaxFeedrate(i));
        maxFeedrate[i]->blockSignals(false);
    }

    for(int i=0; i < 4; i++)
    {
        maxAcceleration[i]->blockSignals(true);
        maxAcceleration[i]->setValue(configValues.getMaxAcceleration(i));
        maxAcceleration[i]->blockSignals(false);
    }

    for(int i=0; i < 7; i++)
    {
        invertDir[i]->blockSignals(true);
        invertDir[i]->setChecked(configValues.getInvertDir(i));
        invertDir[i]->blockSignals(false);
    }


    ui.acceleration->blockSignals(true);
    ui.acceleration->setValue(configValues.getAcceleration());
    ui.acceleration->blockSignals(false);

    ui.acceleration_retract->blockSignals(true);
    ui.acceleration_retract->setValue(configValues.getRetractAcceleration());
    ui.acceleration_retract->blockSignals(false);

    ui.minFeedrate->blockSignals(true);
    ui.minFeedrate->setValue(configValues.getMinFeedRate());
    ui.minFeedrate->blockSignals(false);

    ui.minTravelFeedrate->blockSignals(true);
    ui.minTravelFeedrate->setValue(configValues.getMinTravelFeedrate());
    ui.minTravelFeedrate->blockSignals(false);

    ui.maxXYJerk->blockSignals(true);
    ui.maxXYJerk->setValue(configValues.getMaxXYjerk());
    ui.maxXYJerk->blockSignals(false);

    ui.maxZjerk->blockSignals(true);
    ui.maxZjerk->setValue(configValues.getMaxZjerk());
    ui.maxZjerk->blockSignals(false);

    ui.maxEjerk->blockSignals(true);
    ui.maxEjerk->setValue(configValues.getMaxEjerk());
    ui.maxEjerk->blockSignals(false);

    ui.pidP1->blockSignals(true);
    ui.pidP1->setValue(configValues.getPidP());
    ui.pidP1->blockSignals(false);

    ui.pidI1->blockSignals(true);
    ui.pidI1->setValue(configValues.getPidI());
    ui.pidI1->blockSignals(false);

    ui.pidD1->blockSignals(true);
    ui.pidD1->setValue(configValues.getPidD());
    ui.pidD1->blockSignals(false);

    ui.pidC1->blockSignals(true);
    ui.pidC1->setValue(configValues.getPidC());
    ui.pidC1->blockSignals(false);

    ui.extruderOffsetX->blockSignals(true);
    ui.extruderOffsetX->setValue(configValues.getExtruderXOffset());
    ui.extruderOffsetX->blockSignals(false);

    ui.extruderOffsetY->blockSignals(true);
    ui.extruderOffsetY->setValue(configValues.getExtruderYOffset());
    ui.extruderOffsetY->blockSignals(false);

    ui.extruderOffsetZ->blockSignals(true);
    ui.extruderOffsetZ->setValue(configValues.getExtruderZOffset());
    ui.extruderOffsetZ->blockSignals(false);

    ui.HotendTempPla->blockSignals(true);
    ui.HotendTempPla->setValue(configValues.getPreheatPlaHotend());
    ui.HotendTempPla->blockSignals(false);

    ui.bedTempPla->blockSignals(true);
    ui.bedTempPla->setValue(configValues.getPreheatPlaBed());
    ui.bedTempPla->blockSignals(false);

    ui.fanSpeedPla->blockSignals(true);
    ui.fanSpeedPla->setValue(configValues.getPreheatPlaFan());
    ui.fanSpeedPla->blockSignals(false);

    ui.hotendtempAbs->blockSignals(true);
    ui.hotendtempAbs->setValue(configValues.getPreheatAbsHotend());
    ui.hotendtempAbs->blockSignals(false);

    ui.bedTempAbs->blockSignals(true);
    ui.bedTempAbs->setValue(configValues.getPreheatAbsBed());
    ui.bedTempAbs->blockSignals(false);

    ui.fanSpeedAbs->blockSignals(true);
    ui.fanSpeedAbs->setValue(configValues.getPreheatAbsFan());
    ui.fanSpeedAbs->blockSignals(false);
}

void Echinus_Config::serialDisconnected()
{
    ui.firmware_version->setText("not connected");
    ui.motorGroup->setEnabled(false);
    ui.pidGroup->setEnabled(false);

    ui.accelerationGroup->setEnabled(false);
    ui.advancedGroup->setEnabled(false);
    ui.ExtruderOffsetGroup->setEnabled(false);
    ui.preheatGroupPla->setEnabled(false);
    ui.preheatGroupAbs->setEnabled(false);

}

// about anzeigen
void Echinus_Config::about()
{
    QDialog *window = new QDialog(this);
    Ui::aboutBox about;
    about.setupUi(window);
    window->setLayoutDirection(Qt::LeftToRight);
    window->setModal(true);

	// Gpl einfügen
    QFile licence(":/docs/gpl-2.0.html");
    licence.open(QIODevice::ReadOnly);
    QTextStream c(&licence);
    QString cline = c.readAll();
    about.browserLicense->insertHtml(cline);
    about.browserLicense->moveCursor(QTextCursor::Start, QTextCursor::MoveAnchor);
    
	//credits einfügen
	QFile credits(":/docs/CREDITS");
    credits.open(QIODevice::ReadOnly);
    QTextStream r(&credits);
    r.setCodec(QTextCodec::codecForName("UTF-8"));
    while(!r.atEnd()) {
        QString line = r.readLine();
        // filter out header.
        line.remove(QRegExp("^[^A-Z]+.*"));
        line.remove(QRegExp("^People.*"));
        about.browserCredits->append(line);
    }
    about.browserCredits->moveCursor(QTextCursor::Start, QTextCursor::MoveAnchor);
	
	//titel setzten
    QString title = QString("<b>Echinus Config</b><br/>Version %1").arg(FULLVERSION);
    about.labelTitle->setText(title);

    window->show();

}


//alle existierenden Com port abfragen und in combobox einfügen
void Echinus_Config::enumerate_comports()
{
#if defined(Q_OS_WIN32)
    QStringList deviceEntrysFriendly;
    QStringList deviceEntrys;
    HDEVINFO devInfo;
    if( (devInfo = SetupDiGetClassDevs(&GUID_DEVCLASS_PORTS, NULL, NULL, DIGCF_PRESENT)) != INVALID_HANDLE_VALUE)
    {
        SP_DEVINFO_DATA devInfoData;
        devInfoData.cbSize = sizeof(SP_DEVINFO_DATA);
        for(int i = 0; SetupDiEnumDeviceInfo(devInfo, i, &devInfoData); i++)
        {
            PortInfo info;
            getPortDetails( &info, devInfo, &devInfoData );
            deviceEntrysFriendly.append(info.friendName);
            deviceEntrys.append(info.portName);

        }
        SetupDiDestroyDeviceInfoList(devInfo);
    }


    // check if we have new entrys
    for(int i=0; i < deviceEntrysFriendly.size(); i++)
    {
       if(m_devices.contains(deviceEntrysFriendly.at(i)))
       {
          m_devices.removeAt(m_devices.indexOf(deviceEntrysFriendly.at(i)));
       }
       else
       {
         ui.com_port->addItem(deviceEntrysFriendly.at(i),deviceEntrys.at(i));
       }
    }

    //remove old entrys
    for(int i=0; i < m_devices.size(); i++)
    {
       ui.com_port->removeItem(ui.com_port->findText(m_devices.at(i)));
    }

     //rembber current list
     m_devices = deviceEntrysFriendly;
#else

    QStringList deviceEntrys;
    QDir dir = QDir("/dev/serial/by-id");
    if(dir.exists())
    {
       QStringList entrys = dir.entryList();

       //change into device list
       for(int i=0; i < entrys.size();i++)
       {
          if(entrys.at(i) != "." && entrys.at(i) != "..")
          {
              deviceEntrys << QFile::symLinkTarget(dir.filePath(entrys.at(i)));
          }
       }
   }

   // check if we have new entrys
   for(int i=0; i < deviceEntrys.size(); i++)
   {
      if(m_devices.contains(deviceEntrys.at(i)))
      {
         m_devices.removeAt(m_devices.indexOf(deviceEntrys.at(i)));
      }
      else
      {
        ui.com_port->addItem(deviceEntrys.at(i),deviceEntrys.at(i));
      }
   }

   //remove old entrys
   for(int i=0; i < m_devices.size(); i++)
   {
      ui.com_port->removeItem(ui.com_port->findText(m_devices.at(i)));
   }

    //rembber current list
    m_devices = deviceEntrys;


#endif

}

#if defined(Q_OS_WIN32)
//com port details aus system holen
void Echinus_Config::getPortDetails(PortInfo *portInfo, HDEVINFO devInfo, PSP_DEVINFO_DATA devData)
{
    BYTE* buff;
    DWORD buffSize = 0;
    DWORD type;

    // hole benutzerfreundlichen Namen
    SetupDiGetDeviceRegistryProperty(devInfo, devData, SPDRP_FRIENDLYNAME, NULL, NULL, 0, & buffSize);
    buff = new BYTE[buffSize];
    SetupDiGetDeviceRegistryProperty(devInfo, devData, SPDRP_FRIENDLYNAME, NULL, buff, buffSize, NULL);
    portInfo->friendName = TCHARToQString(buff);
    delete [] buff;

    //hole device namen aus registry
    HKEY devKey = SetupDiOpenDevRegKey(devInfo, devData, DICS_FLAG_GLOBAL, 0, DIREG_DEV, KEY_READ);
    RegQueryValueEx(devKey, TEXT("PortName"), NULL, NULL, NULL, & buffSize);
    buff = new BYTE[buffSize];
    if( RegQueryValueEx(devKey, TEXT("PortName"), NULL, &type, buff, & buffSize) == ERROR_SUCCESS )
        portInfo->portName = TCHARToQString(buff);
    RegCloseKey(devKey);
    delete [] buff;

    // wenn nummer größer als 9, name corrigieren
     QRegExp rx("^COM(\\d+)");
     if(portInfo->portName.contains(rx)) {
         int portnum = rx.cap(1).toInt();
         if(portnum > 9) // COM ports greater than 9 need \\.\ prepended
             portInfo->portName.prepend("\\\\.\\");
     }
}

// reagiere auf device änderungen
LRESULT Echinus_Config::onDeviceChange( WPARAM wParam, LPARAM lParam )
{
	//wenn es ein device hinzufügen/ entfernen event ist
    if ( DBT_DEVICEARRIVAL == wParam || DBT_DEVICEREMOVECOMPLETE == wParam )
    {
		//wenn es ein interface device ist
        PDEV_BROADCAST_HDR pHdr = (PDEV_BROADCAST_HDR)lParam;
        if( pHdr->dbch_devicetype == DBT_DEVTYP_DEVICEINTERFACE )
        {
            PDEV_BROADCAST_DEVICEINTERFACE pDevInf = (PDEV_BROADCAST_DEVICEINTERFACE)pHdr;
             // delimiters are different across APIs...change to backslash.  ugh.
            QString deviceID = TCHARToQString(pDevInf->dbcc_name).toUpper().replace("#", "\\");

			// wenn es ein interface von der richtigen classe ist
            DWORD dwFlag = (DBT_DEVICEARRIVAL == wParam) ? DIGCF_PRESENT : DIGCF_ALLCLASSES;
            HDEVINFO devInfo;
            if( (devInfo = SetupDiGetClassDevs(&GUID_DEVCLASS_PORTS,NULL,NULL,dwFlag)) != INVALID_HANDLE_VALUE )
            {
				//passendes device suchen
                SP_DEVINFO_DATA spDevInfoData;
                spDevInfoData.cbSize = sizeof(SP_DEVINFO_DATA);
                for(int i=0; SetupDiEnumDeviceInfo(devInfo, i, &spDevInfoData); i++)
                {
                    DWORD nSize=0 ;
                    TCHAR buf[MAX_PATH];
                    if ( SetupDiGetDeviceInstanceId(devInfo, &spDevInfoData, buf, MAX_PATH, &nSize) &&
                            deviceID.contains(TCHARToQString(buf))) // we found a match
                    {
						//Portinfos holen und in die comboliste einfügen/entfernen
                        PortInfo info;
                        getPortDetails( &info, devInfo, &spDevInfoData );
                        if( wParam == DBT_DEVICEARRIVAL )
                            ui.com_port->addItem(info.friendName,info.portName);
                        else if( wParam == DBT_DEVICEREMOVECOMPLETE )
                            ui.com_port->removeItem(ui.com_port->findText(info.friendName));
                        break;
                    }
                }
                SetupDiDestroyDeviceInfoList(devInfo);
            }
        }
    }
    return 0;
}
#endif
