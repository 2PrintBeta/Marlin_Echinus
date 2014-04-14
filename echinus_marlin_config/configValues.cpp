/***************************************************************************
 *
 *   Copyright (C) 2013 by Dominik Wenger
 *
 * All files in this archive are subject to the GNU General Public License.
 * See the file COPYING in the source tree root for full license agreement.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ****************************************************************************/


#include "configValues.h"
#include "qmessagebox.h"
#include "qfiledialog.h"

#if defined(Q_OS_WIN32)
#include <windows.h> // for Sleep
#else
#include <unistd.h>
#endif

#define SERIAL_WAITTIME 50

ConfigValues::ConfigValues()
{
    port = new QextSerialPort();
}

void ConfigValues::serialConnect(QString serialport)
{
    port->close();

    port->setBaudRate(BAUD115200);
    port->setPortName(serialport);
    if(!port->open(QIODevice::ReadWrite))
    {
       QMessageBox::warning(NULL,"Error","Failed to open Com port !");
       return;
    }

    // read in config values
    if(readConfig())
    {
        emit connected();
    }
}

void ConfigValues::serialDisconnect()
{
    port->close();

    emit disconnected();
}

QString ConfigValues::serialCommand(QString cmd)
{
    if(!port->isOpen())
    {
        QMessageBox::warning(NULL,"Error","Not connected");
        return "";
    }

    //read any leftover input
    QString input = port->readAll();

    // write command
    port->write(cmd.toLocal8Bit());
    port->flush();

    input  = "";

    for(int i = 0; i < 50; i++)
    {
#if defined(Q_OS_WIN32)
    Sleep(SERIAL_WAITTIME);
#else
    usleep(1000* SERIAL_WAITTIME);
#endif

       input+= port->readAll();
       if(input.contains("ok"))
           break;
    }
    return input.trimmed();
}


bool ConfigValues::readConfig()
{
    QString input = serialCommand("M115\n");
    if(!input.endsWith("ok"))
    {
        QMessageBox::warning(NULL,"Error",  "could not read Firmware version: " + input);
        return false;
    }
    QRegExp rxFirmware("FIRMWARE_NAME:(.*)FIRMWARE_URL:");
    int pos = rxFirmware.indexIn(input);
    if (pos > -1)
    {
        m_firmwareVersion = rxFirmware.cap(1);
    }
    else
    {
        m_firmwareVersion = "unknown";
    }

    // read config
    input = serialCommand("M503\n");
    if(!input.endsWith("ok"))
    {
       QMessageBox::warning(NULL,"Error",  "could not read configuration: " + input);
       return false;
    }

    //steps / mm
    QRegExp rxSteps("M92 X(\\d*\\.\\d*) Y(\\d*\\.\\d*) Z(\\d*\\.\\d*) E(\\d*\\.\\d*)");
    pos = rxSteps.indexIn(input);
    if (pos > -1)
    {
        motorConfig[0].stepsPerMm = rxSteps.cap(1).toDouble();
        motorConfig[1].stepsPerMm = rxSteps.cap(2).toDouble();
        motorConfig[2].stepsPerMm = rxSteps.cap(3).toDouble();
        motorConfig[3].stepsPerMm = rxSteps.cap(4).toDouble();
    }
    else
    {
        QMessageBox::warning(NULL,"Error",  "could not capture steps/mm");
        return false;
    }

    // max feedrates
    QRegExp rxFeed("M203 X(\\d*\\.\\d*) Y(\\d*\\.\\d*) Z(\\d*\\.\\d*) E(\\d*\\.\\d*)");
    pos = rxFeed.indexIn(input);
    if (pos > -1)
    {
        motorConfig[0].maxFeedrate = rxFeed.cap(1).toDouble();
        motorConfig[1].maxFeedrate = rxFeed.cap(2).toDouble();
        motorConfig[2].maxFeedrate = rxFeed.cap(3).toDouble();
        motorConfig[3].maxFeedrate = rxFeed.cap(4).toDouble();
    }
    else
    {
        QMessageBox::warning(NULL,"Error",  "could not capture maxfeedrates");
        return false;
    }

    //Max acceleration
    QRegExp rxAccel("M201 X(\\d*) Y(\\d*) Z(\\d*) E(\\d*)");
    pos = rxAccel.indexIn(input);
    if (pos > -1)
    {
        motorConfig[0].maxAcceleration = rxAccel.cap(1).toInt();
        motorConfig[1].maxAcceleration = rxAccel.cap(2).toInt();
        motorConfig[2].maxAcceleration = rxAccel.cap(3).toInt();
        motorConfig[3].maxAcceleration = rxAccel.cap(4).toInt();
    }
    else
    {
        QMessageBox::warning(NULL,"Error",  "could not capture max acceleration");
        return false;
    }

    //acceleration
    QRegExp rxAccel2("M204 S(\\d*\\.\\d*) T(\\d*\\.\\d*)");
    pos = rxAccel2.indexIn(input);
    if (pos > -1)
    {
        accelerationConfig.acceleration= rxAccel2.cap(1).toDouble();
        accelerationConfig.retract_accel = rxAccel2.cap(1).toDouble();
    }
    else
    {
        QMessageBox::warning(NULL,"Error",  "could not capture acceleration");
        return false;
    }

    //Advanced
    QRegExp rxAdvanced("M205 S(\\d*\\.\\d*) T(\\d*\\.\\d*) B(\\d*) X(\\d*\\.\\d*) Z(\\d*\\.\\d*) E(\\d*\\.\\d*)");
    pos = rxAdvanced.indexIn(input);
    if (pos > -1)
    {
        advancedConfig.minFeedRate = rxAdvanced.cap(1).toDouble();
        advancedConfig.minTravelFeedrate = rxAdvanced.cap(2).toDouble();
        advancedConfig.minSegmentTime= rxAdvanced.cap(3).toInt();
        advancedConfig.maxXYjerk = rxAdvanced.cap(4).toDouble();
        advancedConfig.maxZjerk = rxAdvanced.cap(5).toDouble();
        advancedConfig.maxEjerk = rxAdvanced.cap(6).toDouble();
    }
    else
    {
        QMessageBox::warning(NULL,"Error",  "could not capture advanced");
        return false;
    }

    //PID
    QRegExp rxPid("M301 P(\\d*\\.\\d*) I(\\d*\\.\\d*) D(\\d*\\.\\d*) C(\\d*\\.\\d*)");
    pos = rxPid.indexIn(input);
    if (pos > -1)
    {
        pidConfig.p= rxPid.cap(1).toDouble();
        pidConfig.i= rxPid.cap(2).toDouble();
        pidConfig.d= rxPid.cap(3).toDouble();
        pidConfig.c= rxPid.cap(4).toDouble();
    }
    else
    {
        QMessageBox::warning(NULL,"Error",  "could not capture pid");
        return false;
    }

    // ExtruderOffset
    QRegExp rxoffset("M218 T1 X(\\d*\\.\\d*) Y(\\d*\\.\\d*) Z(\\d*\\.\\d*)");
    pos = rxoffset.indexIn(input);
    if (pos > -1)
    {
        extruderOffsets.xoffset = rxoffset.cap(1).toDouble();
        extruderOffsets.yoffset = rxoffset.cap(2).toDouble();
        extruderOffsets.zoffset = rxoffset.cap(3).toDouble();
    }
    else
    {
        QMessageBox::warning(NULL,"Error",  "could not capture Extruder Offsets");
        return false;
    }

    // Axis inversions
    QRegExp rxInvert("M215 X(\\d*) B(\\d*) Y(\\d*) Z(\\d*) U(\\d*)");
    pos = rxInvert.indexIn(input);
    if (pos > -1)
    {
        motorConfig[0].inv_dir = rxInvert.cap(1).toInt();
        motorConfig[4].inv_dir = rxInvert.cap(2).toInt();
        motorConfig[1].inv_dir = rxInvert.cap(3).toInt();
        motorConfig[2].inv_dir = rxInvert.cap(4).toInt();
        motorConfig[3].inv_dir = rxInvert.cap(5).toInt();

    }
    else
    {
        QMessageBox::warning(NULL,"Error",  "could not capture Axis inversions");
        return false;
    }

    //Preheat Pla
    QRegExp rxPreheatPla("M216 H(\\d*) B(\\d*) F(\\d*)");
    pos = rxPreheatPla.indexIn(input);
    if (pos > -1)
    {
       preHeatPla.hotendTemp = rxPreheatPla.cap(1).toInt();
       preHeatPla.bedTemp = rxPreheatPla.cap(2).toInt();
       preHeatPla.fanSpeed = rxPreheatPla.cap(3).toInt();

    }
    else
    {
        QMessageBox::warning(NULL,"Error",  "could not capture preheat PLA");
        return false;
    }

    QRegExp rxPreheatAbs("M217 H(\\d*) B(\\d*) F(\\d*)");
    pos = rxPreheatAbs.indexIn(input);
    if (pos > -1)
    {
       preHeatAbs.hotendTemp = rxPreheatAbs.cap(1).toInt();
       preHeatAbs.bedTemp = rxPreheatAbs.cap(2).toInt();
       preHeatAbs.fanSpeed = rxPreheatAbs.cap(3).toInt();

    }
    else
    {
        QMessageBox::warning(NULL,"Error",  "could not capture preheat ABS");
        return false;
    }
    return true;
}

void ConfigValues::saveConfig()
{
    //save general config
    QString input = serialCommand("M500\n");
    if(!input.endsWith("ok"))
    {
        QMessageBox::warning(NULL,"Error",  "could not save Firmware configuration: " + input);
        return;
    }
    QMessageBox::information(NULL,"OK",  "Information was permanently saved! ");
    return;
}

void ConfigValues::importConfig()
{
    if(!port->isOpen())
    {
        QMessageBox::warning(NULL,"Error","Not connected");
        return ;
    }

    QString filename = QFileDialog::getOpenFileName(NULL,"Save filename");
    QSettings settings(filename, QSettings::IniFormat);

    settings.beginGroup("MotorOptions");

    setStepsPerMm(0,settings.value("stepsPerMm0").toDouble());
    setStepsPerMm(1,settings.value("stepsPerMm1").toDouble());
    setStepsPerMm(2,settings.value("stepsPerMm2").toDouble());
    setStepsPerMm(3,settings.value("stepsPerMm3").toDouble());

    setMaxFeedrate(0,settings.value("maxFeedrate0").toDouble());
    setMaxFeedrate(1,settings.value("maxFeedrate1").toDouble());
    setMaxFeedrate(2,settings.value("maxFeedrate2").toDouble());
    setMaxFeedrate(3,settings.value("maxFeedrate3").toDouble());

    setMaxAcceleration(0,settings.value("maxAcceleration0").toInt());
    setMaxAcceleration(1,settings.value("maxAcceleration1").toInt());
    setMaxAcceleration(2,settings.value("maxAcceleration2").toInt());
    setMaxAcceleration(3,settings.value("maxAcceleration3").toInt());

    setInvertDir(0,settings.value("inv_dir0").toBool());
    setInvertDir(1,settings.value("inv_dir1").toBool());
    setInvertDir(2,settings.value("inv_dir2").toBool());
    setInvertDir(3,settings.value("inv_dir3").toBool());
    setInvertDir(4,settings.value("inv_dir4").toBool());
    settings.endGroup();

    settings.beginGroup("PIDOptions");
    setPidP(settings.value("p0").toDouble());
    setPidI(settings.value("i0").toDouble());
    setPidD(settings.value("d0").toDouble());
    setPidC(settings.value("c0").toDouble());
    settings.endGroup();

    settings.beginGroup("AccelerationOptions");
    setRetractAcceleration(settings.value("RetractAcceleration").toDouble());
    setAcceleration(settings.value("Acceleration").toDouble());
    settings.endGroup();

    settings.beginGroup("AdvancedOptions");
    setMinFeedRate(settings.value("MinFeedrate").toDouble()) ;
    setMinTravelFeedrate(settings.value("MinTravelFeedrate").toDouble());
    setMinSegmentTime(settings.value("MinSegmentTime").toInt());
    setMaxXYjerk(settings.value("MaxXYJerk").toDouble());
    setMaxZjerk(settings.value("MaxZJerk").toDouble());
    setMaxEjerk(settings.value("MaxEJerk").toDouble());
    settings.endGroup();

    settings.beginGroup("ExtruderOffsetOptions");
    setExtruderXOffset(settings.value("ExtruderOffsetX").toDouble());
    setExtruderYOffset(settings.value("ExtruderOffsetY").toDouble());
    setExtruderZOffset(settings.value("ExtruderOffsetZ").toDouble());
    settings.endGroup();

    settings.beginGroup("PreheatPlaConfig");
    setPreheatPlaHotend(settings.value("PreheatHotend").toInt());
    setPreheatPlaBed(settings.value("PreheatBed").toInt());
    setPreheatPlaFan(settings.value("PreheatFan").toInt());
    settings.endGroup();

    settings.beginGroup("PreheatAbsConfig");
    setPreheatAbsHotend(settings.value("PreheatHotend").toInt());
    setPreheatAbsBed(settings.value("PreheatBed").toInt());
    setPreheatAbsFan(settings.value("PreheatFan").toInt());
    settings.endGroup();

}

void ConfigValues::exportConfig()
{
    if(!port->isOpen())
    {
        QMessageBox::warning(NULL,"Error","Not connected");
        return ;
    }

    QString filename = QFileDialog::getSaveFileName(NULL,"Save filename");

    QSettings settings(filename, QSettings::IniFormat);

    settings.beginGroup("MotorOptions");

    settings.setValue("stepsPerMm0",motorConfig[0].stepsPerMm);
    settings.setValue("stepsPerMm1",motorConfig[1].stepsPerMm);
    settings.setValue("stepsPerMm2",motorConfig[2].stepsPerMm);
    settings.setValue("stepsPerMm3",motorConfig[3].stepsPerMm);

    settings.setValue("maxFeedrate0",motorConfig[0].maxFeedrate);
    settings.setValue("maxFeedrate1",motorConfig[1].maxFeedrate);
    settings.setValue("maxFeedrate2",motorConfig[2].maxFeedrate);
    settings.setValue("maxFeedrate3",motorConfig[3].maxFeedrate);

    settings.setValue("maxAcceleration0",motorConfig[0].maxAcceleration);
    settings.setValue("maxAcceleration1",motorConfig[1].maxAcceleration);
    settings.setValue("maxAcceleration2",motorConfig[2].maxAcceleration);
    settings.setValue("maxAcceleration3",motorConfig[3].maxAcceleration);

    settings.setValue("inv_dir0",motorConfig[0].inv_dir);
    settings.setValue("inv_dir1",motorConfig[1].inv_dir);
    settings.setValue("inv_dir2",motorConfig[2].inv_dir);
    settings.setValue("inv_dir3",motorConfig[3].inv_dir);
    settings.setValue("inv_dir4",motorConfig[4].inv_dir);
    settings.endGroup();


    settings.beginGroup("PIDOptions");
    settings.setValue("p0",pidConfig.p);
    settings.setValue("i0",pidConfig.i);
    settings.setValue("d0",pidConfig.d);
    settings.setValue("c0",pidConfig.c);
    settings.endGroup();

    settings.beginGroup("AccelerationOptions");
    settings.setValue("RetractAcceleration",accelerationConfig.retract_accel);
    settings.setValue("Acceleration",accelerationConfig.acceleration);
    settings.endGroup();

    settings.beginGroup("AdvancedOptions");
    settings.setValue("MinFeedrate",advancedConfig.minFeedRate);
    settings.setValue("MinTravelFeedrate",advancedConfig.minTravelFeedrate);
    settings.setValue("MinSegmentTime",advancedConfig.minSegmentTime);
    settings.setValue("MaxXYJerk",advancedConfig.maxXYjerk);
    settings.setValue("MaxZJerk",advancedConfig.maxZjerk);
    settings.setValue("MaxEJerk",advancedConfig.maxEjerk);
    settings.endGroup();

    settings.beginGroup("ExtruderOffsetOptions");
    settings.setValue("ExtruderOffsetX",extruderOffsets.xoffset);
    settings.setValue("ExtruderOffsetY",extruderOffsets.yoffset);
    settings.setValue("ExtruderOffsetZ",extruderOffsets.zoffset);
    settings.endGroup();

    settings.beginGroup("PreheatPlaConfig");
    settings.setValue("PreheatHotend",preHeatPla.hotendTemp);
    settings.setValue("PreheatBed",preHeatPla.bedTemp);
    settings.setValue("PreheatFan",preHeatPla.fanSpeed);
    settings.endGroup();

    settings.beginGroup("PreheatAbsConfig");
    settings.setValue("PreheatHotend",preHeatAbs.hotendTemp);
    settings.setValue("PreheatBed",preHeatAbs.bedTemp);
    settings.setValue("PreheatFan",preHeatAbs.fanSpeed);
    settings.endGroup();

    settings.sync();

}

void ConfigValues::reloadDefaults()
{
    QString cmd = "M502\n";
    QString input = serialCommand(cmd);
    if(!input.endsWith("ok"))
    {
        QMessageBox::warning(NULL,"Error",  "Could not load Defaults: " + input);
        return;
    }
    //read config from device
    readConfig();
}

void ConfigValues::setStepsPerMm(int index, double value)
{
    QString cmd;
    switch(index)
    {
        case 0:
            cmd = QString("M92 X%1\n").arg(value);
            break;
        case 1:
            cmd = QString("M92 Y%1\n").arg(value);
            break;
        case 2:
            cmd = QString("M92 Z%1\n").arg(value);
            break;
        case 3:
            cmd = QString("M92 E%1\n").arg(value);
            break;
    }

    QString input = serialCommand(cmd);
    if(!input.startsWith("ok"))
    {
        QMessageBox::warning(NULL,"Error",  "Could not set steps per mm: " + input);
        return;
    }
    motorConfig[index].stepsPerMm = value;
}

void ConfigValues::setMaxFeedrate(int index, double value)
{
    QString cmd;
    switch(index)
    {
        case 0:
            cmd = QString("M203 X%1\n").arg(value);
            break;
        case 1:
            cmd = QString("M203 Y%1\n").arg(value);
            break;
        case 2:
            cmd = QString("M203 Z%1\n").arg(value);
            break;
        case 3:
            cmd = QString("M203 E%1\n").arg(value);
            break;
    }
    QString input = serialCommand(cmd);
    if(!input.startsWith("ok"))
    {
        QMessageBox::warning(NULL,"Error",  "Could not set max feedrate: " + input);
        return;
    }
    motorConfig[index].maxFeedrate = value;
}

void ConfigValues::setMaxAcceleration(int index, int value)
{
    QString cmd;
    switch(index)
    {
        case 0:
            cmd = QString("M201 X%1\n").arg(value);
            break;
        case 1:
            cmd = QString("M201 Y%1\n").arg(value);
            break;
        case 2:
            cmd = QString("M201 Z%1\n").arg(value);
            break;
        case 3:
            cmd = QString("M201 E%1\n").arg(value);
            break;
    }
    QString input = serialCommand(cmd);
    if(!input.startsWith("ok"))
    {
        QMessageBox::warning(NULL,"Error",  "Could not set search feedrate: " + input);
        return;
    }
    motorConfig[index].maxAcceleration = value;
}

void ConfigValues::setInvertDir(int index, bool value)
{
    QString cmd;
    switch(index)
    {
        case 0:
            cmd = QString("M215 X%1\n").arg(value);
            break;
        case 1:
            cmd = QString("M215 Y%1\n").arg(value);
            break;
        case 2:
            cmd = QString("M215 Z%1\n").arg(value);
            break;
        case 3:
            cmd = QString("M215 E%1\n").arg(value);
            break;
        case 4:
            cmd = QString("M215 B%1\n").arg(value);
            break;
    }
    QString input = serialCommand(cmd);
    if(!input.startsWith("ok"))
    {
        QMessageBox::warning(NULL,"Error",  "Could not set invert dir: " + input);
        return;
    }
    motorConfig[index].inv_dir = value;
}

void ConfigValues::setPidP( double value)
{
    QString cmd = QString("M301 P%1\n").arg(value);
    QString input = serialCommand(cmd);
    if(!input.startsWith("ok"))
    {
        QMessageBox::warning(NULL,"Error",  "Could not set pid p value: " + input);
        return;
    }
    pidConfig.p = value;
}

void ConfigValues::setPidI(double value)
{
    QString cmd = QString("M301 I%1\n").arg(value);
    QString input = serialCommand(cmd);
    if(!input.startsWith("ok"))
    {
        QMessageBox::warning(NULL,"Error",  "Could not set pid i value: " + input);
        return;
    }
    pidConfig.i = value;
}

void ConfigValues::setPidD(double value)
{
    QString cmd = QString("M301 D%1\n").arg(value);
    QString input = serialCommand(cmd);
    if(!input.startsWith("ok"))
    {
        QMessageBox::warning(NULL,"Error",  "Could not set pid d value: " + input);
        return;
    }
    pidConfig.d = value;
}

void ConfigValues::setPidC(double value)
{
    QString cmd = QString("M301 C%1\n").arg(value);
    QString input = serialCommand(cmd);
    if(!input.startsWith("ok"))
    {
        QMessageBox::warning(NULL,"Error",  "Could not set pid c value: " + input);
        return;
    }
    pidConfig.c = value;
}

void ConfigValues::setRetractAcceleration(double value)
{
    QString cmd = QString("M204 T%1\n").arg(value);
    QString input = serialCommand(cmd);
    if(!input.startsWith("ok"))
    {
        QMessageBox::warning(NULL,"Error",  "Could not set acceleration type value: " + input);
        return;
    }
    accelerationConfig.retract_accel = value;
}

void ConfigValues::setAcceleration(double value)
{
    QString cmd = QString("M204 S%1\n").arg(value);
    QString input = serialCommand(cmd);
    if(!input.startsWith("ok"))
    {
        QMessageBox::warning(NULL,"Error",  "Could not set acceleration value: " + input);
        return;
    }
    accelerationConfig.acceleration = value;
}

void ConfigValues::setMinFeedRate(double value)
{
    QString cmd = QString("M205 S%1\n").arg(value);
    QString input = serialCommand(cmd);
    if(!input.startsWith("ok"))
    {
        QMessageBox::warning(NULL,"Error",  "Could not set min Feedrate value: " + input);
        return;
    }
    advancedConfig.minFeedRate = value;
}

void ConfigValues::setMinTravelFeedrate(double value)
{
    QString cmd = QString("M205 T%1\n").arg(value);
    QString input = serialCommand(cmd);
    if(!input.startsWith("ok"))
    {
        QMessageBox::warning(NULL,"Error",  "Could not set min Travel Feedrate value: " + input);
        return;
    }
    advancedConfig.minTravelFeedrate = value;
}

void ConfigValues::setMinSegmentTime(int value)
{
    QString cmd = QString("M205 B%1\n").arg(value);
    QString input = serialCommand(cmd);
    if(!input.startsWith("ok"))
    {
        QMessageBox::warning(NULL,"Error",  "Could not set min Segement time value: " + input);
        return;
    }
    advancedConfig.minSegmentTime = value;
}

void ConfigValues::setMaxXYjerk(double value)
{
    QString cmd = QString("M205 X%1\n").arg(value);
    QString input = serialCommand(cmd);
    if(!input.startsWith("ok"))
    {
        QMessageBox::warning(NULL,"Error",  "Could not set maxXYjerk value: " + input);
        return;
    }
    advancedConfig.maxXYjerk = value;
}

void ConfigValues::setMaxZjerk(double value)
{
    QString cmd = QString("M205 Z%1\n").arg(value);
    QString input = serialCommand(cmd);
    if(!input.startsWith("ok"))
    {
        QMessageBox::warning(NULL,"Error",  "Could not set maxZjerk value: " + input);
        return;
    }
    advancedConfig.maxZjerk= value;
}

void ConfigValues::setMaxEjerk(double value)
{
    QString cmd = QString("M205 E%1\n").arg(value);
    QString input = serialCommand(cmd);
    if(!input.startsWith("ok"))
    {
        QMessageBox::warning(NULL,"Error",  "Could not set maxEjerk value: " + input);
        return;
    }
    advancedConfig.maxEjerk= value;
}

void ConfigValues::setExtruderXOffset(double value)
{
    QString cmd = QString("M218 T1 X%1\n").arg(value);
    QString input = serialCommand(cmd);
    if(!input.endsWith("ok"))
    {
        QMessageBox::warning(NULL,"Error",  "Could not set Extruder Offset X value: " + input);
        return;
    }
    extruderOffsets.xoffset= value;
}

void ConfigValues::setExtruderYOffset(double value)
{
    QString cmd = QString("M218 T1 Y%1\n").arg(value);
    QString input = serialCommand(cmd);
    if(!input.endsWith("ok"))
    {
        QMessageBox::warning(NULL,"Error",  "Could not set Extruder Offset Y value: " + input);
        return;
    }
    extruderOffsets.yoffset= value;
}

void ConfigValues::setExtruderZOffset(double value)
{
    QString cmd = QString("M218 T1 Z%1\n").arg(value);
    QString input = serialCommand(cmd);
    if(!input.endsWith("ok"))
    {
        QMessageBox::warning(NULL,"Error",  "Could not set Extruder Offset Z value: " + input);
        return;
    }
    extruderOffsets.zoffset= value;
}

void ConfigValues::setPreheatPlaHotend(int value)
{
    QString cmd = QString("M216 H%1\n").arg(value);
    QString input = serialCommand(cmd);
    if(!input.endsWith("ok"))
    {
        QMessageBox::warning(NULL,"Error",  "Could not set Preheat Pla hotend value: " + input);
        return;
    }
    preHeatPla.hotendTemp= value;
}

void ConfigValues::setPreheatPlaBed(int value)
{
    QString cmd = QString("M216 B%1\n").arg(value);
    QString input = serialCommand(cmd);
    if(!input.endsWith("ok"))
    {
        QMessageBox::warning(NULL,"Error",  "Could not set Preheat Pla bed value: " + input);
        return;
    }
    preHeatPla.bedTemp= value;
}
void ConfigValues::setPreheatPlaFan(int value)
{
   QString cmd = QString("M216 F%1\n").arg(value);
   QString input = serialCommand(cmd);
   if(!input.endsWith("ok"))
   {
        QMessageBox::warning(NULL,"Error",  "Could not set Preheat Pla fan value: " + input);
        return;
   }
   preHeatPla.fanSpeed= value;

}

void ConfigValues::setPreheatAbsHotend(int value)
{
    QString cmd = QString("M217 H%1\n").arg(value);
    QString input = serialCommand(cmd);
    if(!input.endsWith("ok"))
    {
         QMessageBox::warning(NULL,"Error",  "Could not set Preheat Abs hotend value: " + input);
         return;
    }
    preHeatAbs.hotendTemp= value;
}


void ConfigValues::setPreheatAbsBed(int value)
{
    QString cmd = QString("M217 B%1\n").arg(value);
    QString input = serialCommand(cmd);
    if(!input.endsWith("ok"))
    {
         QMessageBox::warning(NULL,"Error",  "Could not set Preheat Abs bed value: " + input);
         return;
    }
    preHeatAbs.bedTemp= value;
}

void ConfigValues::setPreheatAbsFan(int value)
{
    QString cmd = QString("M217 F%1\n").arg(value);
    QString input = serialCommand(cmd);
    if(!input.endsWith("ok"))
    {
         QMessageBox::warning(NULL,"Error",  "Could not set Preheat Abs fan value: " + input);
         return;
    }
    preHeatAbs.fanSpeed= value;
}
