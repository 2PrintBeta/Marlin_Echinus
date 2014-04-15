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

#ifndef CONFIGVALUES_H
#define CONFIGVALUES_H

#include <QtGui>
#include "qextserial/qextserialport.h"

struct MotorConfig
{
    double stepsPerMm;
    double maxFeedrate;
    int maxAcceleration;
    bool inv_dir;
};

struct PidConfig
{
    double p;
    double i;
    double d;
    double c;
};

struct AccelerationConfig
{
    double acceleration;
    double retract_accel;
};

struct AdvancedConfig
{
    double minFeedRate;
    double minTravelFeedrate;
    int minSegmentTime;
    double maxXYjerk;
    double maxZjerk;
    double maxEjerk;
};

struct ExtruderOffsets
{
    double xoffset;
    double yoffset;
    double zoffset;
};

struct PreHeatConfig
{
    int hotendTemp;
    int bedTemp;
    int fanSpeed;
};


class ConfigValues : public QObject
{
    Q_OBJECT
public:
    ConfigValues();

    QString firmwareVersion() {return m_firmwareVersion; }


    double getStepsPerMm(int index) {return motorConfig[index].stepsPerMm;}
    double getMaxFeedrate(int index) {return motorConfig[index].maxFeedrate;}
    int getMaxAcceleration(int index) {return motorConfig[index].maxAcceleration;}
    bool getInvertDir(int index) {return motorConfig[index].inv_dir;}

    double getPidP() {return pidConfig.p;}
    double getPidI() {return pidConfig.i;}
    double getPidD() {return pidConfig.d;}
    double getPidC() {return pidConfig.c;}

    double getAcceleration() { return accelerationConfig.acceleration; }
    double getRetractAcceleration() { return accelerationConfig.retract_accel; }

    double getMinFeedRate() {return advancedConfig.minFeedRate; }
    double getMinTravelFeedrate() {return advancedConfig.minTravelFeedrate; }
    int getMinSegmentTime() {return advancedConfig.minSegmentTime; }
    double getMaxXYjerk() {return advancedConfig.maxXYjerk; }
    double getMaxZjerk() {return advancedConfig.maxZjerk; }
    double getMaxEjerk() {return advancedConfig.maxEjerk; }

    double getExtruderXOffset() {return extruderOffsets.xoffset; }
    double getExtruderYOffset() {return extruderOffsets.yoffset; }
    double getExtruderZOffset() {return extruderOffsets.zoffset; }

    int getPreheatPlaHotend() {return preHeatPla.hotendTemp;}
    int getPreheatPlaBed() {return preHeatPla.bedTemp;}
    int getPreheatPlaFan() {return preHeatPla.fanSpeed;}

    int getPreheatAbsHotend() {return preHeatAbs.hotendTemp;}
    int getPreheatAbsBed() {return preHeatAbs.bedTemp;}
    int getPreheatAbsFan() {return preHeatAbs.fanSpeed;}

    void setStepsPerMm(int index, double value);
    void setMaxFeedrate(int index, double value);
    void setMaxAcceleration(int index, int value);
    void setInvertDir(int index, bool value);


public slots:

    void saveConfig();
    void importConfig();
    void exportConfig();
    void reloadDefaults();

    void serialConnect(QString serialport);
    void serialDisconnect();


    void setMinFeedRate(double value) ;
    void setMinTravelFeedrate(double value);
    void setMinSegmentTime(int value);
    void setMaxXYjerk(double value);
    void setMaxZjerk(double value);
    void setMaxEjerk(double value);

    void setRetractAcceleration(double value);
    void setAcceleration(double value);

    void setPidP(double value);
    void setPidI(double value);
    void setPidD(double value);
    void setPidC(double value);

    void setExtruderXOffset(double value);
    void setExtruderYOffset(double value);
    void setExtruderZOffset(double value);

    void setPreheatPlaHotend(int value);
    void setPreheatPlaBed(int value);
    void setPreheatPlaFan(int value);

    void setPreheatAbsHotend(int value);
    void setPreheatAbsBed(int value);
    void setPreheatAbsFan(int value);

signals:
    void connected();
    void disconnected();

private:
    bool readConfig();

    QString serialCommand(QString cmd);

    QString m_firmwareVersion;
    MotorConfig motorConfig[7];
    PidConfig pidConfig;
    AccelerationConfig accelerationConfig;
    AdvancedConfig advancedConfig;
    ExtruderOffsets extruderOffsets;
    PreHeatConfig preHeatPla;
    PreHeatConfig preHeatAbs;

    QextSerialPort* port;
};

#endif // CONFIGVALUES_H
