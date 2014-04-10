/********************************************************************************
** Form generated from reading UI file 'echinus_config_frm.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ECHINUS_CONFIG_FRM_H
#define UI_ECHINUS_CONFIG_FRM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Echinus_Config_frm
{
public:
    QAction *actionEmpty_local_download_cache;
    QAction *actionInstall_Rockbox_Utility_on_player;
    QAction *action_Configure;
    QAction *actionE_xit;
    QAction *action_About;
    QAction *actionAbout_Qt;
    QAction *action_Help;
    QAction *actionInfo;
    QAction *actionComplete_Installation;
    QAction *actionSmall_Installation;
    QAction *actionInstall_Bootloader;
    QAction *actionInstall_Rockbox;
    QAction *actionFonts_Package;
    QAction *actionInstall_Themes;
    QAction *actionInstall_Game_Files;
    QAction *actionInstall_Voice_File;
    QAction *actionCreate_Talk_Files;
    QAction *actionRemove_bootloader;
    QAction *actionUninstall_Rockbox;
    QAction *actionRead_PDF_manual;
    QAction *actionRead_HTML_manual;
    QAction *actionDownload_PDF_manual;
    QAction *actionDownload_HTML_manual_zip;
    QAction *actionCreate_Voice_File;
    QAction *action_System_Info;
    QAction *action_Trace;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *flash_group;
    QGridLayout *gridLayout_2;
    QPushButton *disconnect;
    QTabWidget *tabWidget;
    QWidget *widget;
    QGridLayout *gridLayout_10;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_9;
    QGroupBox *motorGroup;
    QGridLayout *gridLayout_3;
    QDoubleSpinBox *maxFeedrate1;
    QLabel *label_8;
    QDoubleSpinBox *maxFeedrate3;
    QLabel *label_7;
    QDoubleSpinBox *maxFeedrate2;
    QLabel *label_4;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QLabel *label_11;
    QFrame *line;
    QLabel *label_3;
    QDoubleSpinBox *stepsPerMm1;
    QCheckBox *invertDir1;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QDoubleSpinBox *stepsPerMm2;
    QDoubleSpinBox *stepsPerMm3;
    QDoubleSpinBox *stepsPerMm4;
    QCheckBox *invertDir2;
    QCheckBox *invertDir3;
    QCheckBox *invertDir4;
    QFrame *line_19;
    QDoubleSpinBox *maxFeedrate4;
    QLabel *label_5;
    QSpinBox *maxAccel1;
    QSpinBox *maxAccel4;
    QSpinBox *maxAccel3;
    QSpinBox *maxAccel2;
    QLabel *label_6;
    QCheckBox *invertDir5;
    QWidget *tab;
    QGridLayout *gridLayout_12;
    QGroupBox *pidGroup;
    QGridLayout *gridLayout_5;
    QFrame *line_16;
    QDoubleSpinBox *pidD1;
    QLabel *label_30;
    QLabel *label_31;
    QFrame *line_17;
    QDoubleSpinBox *pidI1;
    QFrame *line_14;
    QLabel *label_29;
    QDoubleSpinBox *pidP1;
    QDoubleSpinBox *pidC1;
    QFrame *line_15;
    QLabel *label_22;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_7;
    QWidget *tab_4;
    QGridLayout *gridLayout_14;
    QGroupBox *accelerationGroup;
    QGridLayout *gridLayout_7;
    QLabel *label_41;
    QFrame *line_24;
    QFrame *line_25;
    QLabel *label_42;
    QDoubleSpinBox *acceleration;
    QDoubleSpinBox *acceleration_retract;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer_5;
    QWidget *tab_5;
    QGridLayout *gridLayout_15;
    QGroupBox *ExtruderOffsetGroup;
    QGridLayout *gridLayout_4;
    QLabel *label_9;
    QFrame *line_5;
    QLabel *label_10;
    QFrame *line_6;
    QLabel *label_15;
    QFrame *line_7;
    QDoubleSpinBox *extruderOffsetX;
    QDoubleSpinBox *extruderOffsetY;
    QDoubleSpinBox *extruderOffsetZ;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QWidget *tab_6;
    QGridLayout *gridLayout_16;
    QGroupBox *advancedGroup;
    QGridLayout *gridLayout_6;
    QLabel *label_21;
    QFrame *line_10;
    QDoubleSpinBox *minFeedrate;
    QDoubleSpinBox *maxZjerk;
    QFrame *line_13;
    QLabel *label_20;
    QLabel *label_19;
    QDoubleSpinBox *maxXYJerk;
    QLabel *label_17;
    QFrame *line_8;
    QDoubleSpinBox *minTravelFeedrate;
    QLabel *label_16;
    QFrame *line_9;
    QDoubleSpinBox *maxEjerk;
    QFrame *line_12;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_3;
    QWidget *tab_2;
    QGridLayout *gridLayout_11;
    QGroupBox *preheatGroupAbs;
    QGridLayout *gridLayout_9;
    QFrame *line_21;
    QFrame *line_22;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QFrame *line_23;
    QSpinBox *hotendtempAbs;
    QSpinBox *bedTempAbs;
    QSpinBox *fanSpeedAbs;
    QGroupBox *preheatGroupPla;
    QGridLayout *gridLayout_8;
    QFrame *line_18;
    QFrame *line_20;
    QLabel *label_18;
    QLabel *label_23;
    QLabel *label_24;
    QFrame *line_11;
    QSpinBox *HotendTempPla;
    QSpinBox *bedTempPla;
    QSpinBox *fanSpeedPla;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *saveConfig;
    QComboBox *com_port;
    QLabel *firmware_version;
    QLabel *label;
    QPushButton *export_config;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *import_config;
    QPushButton *connect;
    QPushButton *reloadDefaults;
    QMenuBar *menubar;
    QMenu *menuAbout;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Echinus_Config_frm)
    {
        if (Echinus_Config_frm->objectName().isEmpty())
            Echinus_Config_frm->setObjectName(QStringLiteral("Echinus_Config_frm"));
        Echinus_Config_frm->resize(757, 448);
        Echinus_Config_frm->setTabShape(QTabWidget::Rounded);
        actionEmpty_local_download_cache = new QAction(Echinus_Config_frm);
        actionEmpty_local_download_cache->setObjectName(QStringLiteral("actionEmpty_local_download_cache"));
        actionInstall_Rockbox_Utility_on_player = new QAction(Echinus_Config_frm);
        actionInstall_Rockbox_Utility_on_player->setObjectName(QStringLiteral("actionInstall_Rockbox_Utility_on_player"));
        action_Configure = new QAction(Echinus_Config_frm);
        action_Configure->setObjectName(QStringLiteral("action_Configure"));
        actionE_xit = new QAction(Echinus_Config_frm);
        actionE_xit->setObjectName(QStringLiteral("actionE_xit"));
        action_About = new QAction(Echinus_Config_frm);
        action_About->setObjectName(QStringLiteral("action_About"));
        actionAbout_Qt = new QAction(Echinus_Config_frm);
        actionAbout_Qt->setObjectName(QStringLiteral("actionAbout_Qt"));
        action_Help = new QAction(Echinus_Config_frm);
        action_Help->setObjectName(QStringLiteral("action_Help"));
        actionInfo = new QAction(Echinus_Config_frm);
        actionInfo->setObjectName(QStringLiteral("actionInfo"));
        actionComplete_Installation = new QAction(Echinus_Config_frm);
        actionComplete_Installation->setObjectName(QStringLiteral("actionComplete_Installation"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/bootloader_btn.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionComplete_Installation->setIcon(icon);
        actionSmall_Installation = new QAction(Echinus_Config_frm);
        actionSmall_Installation->setObjectName(QStringLiteral("actionSmall_Installation"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/rbinstall_btn.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSmall_Installation->setIcon(icon1);
        actionInstall_Bootloader = new QAction(Echinus_Config_frm);
        actionInstall_Bootloader->setObjectName(QStringLiteral("actionInstall_Bootloader"));
        actionInstall_Bootloader->setIcon(icon);
        actionInstall_Rockbox = new QAction(Echinus_Config_frm);
        actionInstall_Rockbox->setObjectName(QStringLiteral("actionInstall_Rockbox"));
        actionInstall_Rockbox->setIcon(icon1);
        actionFonts_Package = new QAction(Echinus_Config_frm);
        actionFonts_Package->setObjectName(QStringLiteral("actionFonts_Package"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/font_btn.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFonts_Package->setIcon(icon2);
        actionInstall_Themes = new QAction(Echinus_Config_frm);
        actionInstall_Themes->setObjectName(QStringLiteral("actionInstall_Themes"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/themes_btn.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionInstall_Themes->setIcon(icon3);
        actionInstall_Game_Files = new QAction(Echinus_Config_frm);
        actionInstall_Game_Files->setObjectName(QStringLiteral("actionInstall_Game_Files"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/doom_btn.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionInstall_Game_Files->setIcon(icon4);
        actionInstall_Voice_File = new QAction(Echinus_Config_frm);
        actionInstall_Voice_File->setObjectName(QStringLiteral("actionInstall_Voice_File"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icons/talkfile_btn.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionInstall_Voice_File->setIcon(icon5);
        actionCreate_Talk_Files = new QAction(Echinus_Config_frm);
        actionCreate_Talk_Files->setObjectName(QStringLiteral("actionCreate_Talk_Files"));
        actionCreate_Talk_Files->setIcon(icon5);
        actionRemove_bootloader = new QAction(Echinus_Config_frm);
        actionRemove_bootloader->setObjectName(QStringLiteral("actionRemove_bootloader"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/icons/rembootloader_btn.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRemove_bootloader->setIcon(icon6);
        actionUninstall_Rockbox = new QAction(Echinus_Config_frm);
        actionUninstall_Rockbox->setObjectName(QStringLiteral("actionUninstall_Rockbox"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/icons/remrb_btn.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUninstall_Rockbox->setIcon(icon7);
        actionRead_PDF_manual = new QAction(Echinus_Config_frm);
        actionRead_PDF_manual->setObjectName(QStringLiteral("actionRead_PDF_manual"));
        actionRead_HTML_manual = new QAction(Echinus_Config_frm);
        actionRead_HTML_manual->setObjectName(QStringLiteral("actionRead_HTML_manual"));
        actionDownload_PDF_manual = new QAction(Echinus_Config_frm);
        actionDownload_PDF_manual->setObjectName(QStringLiteral("actionDownload_PDF_manual"));
        actionDownload_HTML_manual_zip = new QAction(Echinus_Config_frm);
        actionDownload_HTML_manual_zip->setObjectName(QStringLiteral("actionDownload_HTML_manual_zip"));
        actionCreate_Voice_File = new QAction(Echinus_Config_frm);
        actionCreate_Voice_File->setObjectName(QStringLiteral("actionCreate_Voice_File"));
        actionCreate_Voice_File->setIcon(icon5);
        action_System_Info = new QAction(Echinus_Config_frm);
        action_System_Info->setObjectName(QStringLiteral("action_System_Info"));
        action_Trace = new QAction(Echinus_Config_frm);
        action_Trace->setObjectName(QStringLiteral("action_Trace"));
        centralwidget = new QWidget(Echinus_Config_frm);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(-1, -1, -1, 0);
        flash_group = new QGroupBox(centralwidget);
        flash_group->setObjectName(QStringLiteral("flash_group"));
        gridLayout_2 = new QGridLayout(flash_group);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        disconnect = new QPushButton(flash_group);
        disconnect->setObjectName(QStringLiteral("disconnect"));

        gridLayout_2->addWidget(disconnect, 0, 3, 1, 1);

        tabWidget = new QTabWidget(flash_group);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        widget = new QWidget();
        widget->setObjectName(QStringLiteral("widget"));
        gridLayout_10 = new QGridLayout(widget);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_10->addItem(verticalSpacer_4, 1, 0, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_10->addItem(horizontalSpacer_9, 0, 1, 1, 1);

        motorGroup = new QGroupBox(widget);
        motorGroup->setObjectName(QStringLiteral("motorGroup"));
        motorGroup->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(motorGroup->sizePolicy().hasHeightForWidth());
        motorGroup->setSizePolicy(sizePolicy);
        gridLayout_3 = new QGridLayout(motorGroup);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        maxFeedrate1 = new QDoubleSpinBox(motorGroup);
        maxFeedrate1->setObjectName(QStringLiteral("maxFeedrate1"));
        maxFeedrate1->setMaximum(100000);

        gridLayout_3->addWidget(maxFeedrate1, 2, 6, 1, 1);

        label_8 = new QLabel(motorGroup);
        label_8->setObjectName(QStringLiteral("label_8"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(label_8, 0, 6, 1, 1);

        maxFeedrate3 = new QDoubleSpinBox(motorGroup);
        maxFeedrate3->setObjectName(QStringLiteral("maxFeedrate3"));
        maxFeedrate3->setMaximum(100000);

        gridLayout_3->addWidget(maxFeedrate3, 4, 6, 1, 1);

        label_7 = new QLabel(motorGroup);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(label_7, 0, 4, 1, 1);

        maxFeedrate2 = new QDoubleSpinBox(motorGroup);
        maxFeedrate2->setObjectName(QStringLiteral("maxFeedrate2"));
        maxFeedrate2->setMaximum(100000);

        gridLayout_3->addWidget(maxFeedrate2, 3, 6, 1, 1);

        label_4 = new QLabel(motorGroup);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(label_4, 0, 1, 1, 1);

        line_2 = new QFrame(motorGroup);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_2, 0, 3, 1, 1);

        line_3 = new QFrame(motorGroup);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_3, 0, 5, 1, 1);

        line_4 = new QFrame(motorGroup);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_4, 0, 10, 1, 1);

        label_11 = new QLabel(motorGroup);
        label_11->setObjectName(QStringLiteral("label_11"));
        sizePolicy1.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(label_11, 0, 12, 1, 1);

        line = new QFrame(motorGroup);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line, 1, 1, 1, 12);

        label_3 = new QLabel(motorGroup);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_3->addWidget(label_3, 2, 1, 1, 1);

        stepsPerMm1 = new QDoubleSpinBox(motorGroup);
        stepsPerMm1->setObjectName(QStringLiteral("stepsPerMm1"));
        stepsPerMm1->setMaximum(9999);

        gridLayout_3->addWidget(stepsPerMm1, 2, 4, 1, 1);

        invertDir1 = new QCheckBox(motorGroup);
        invertDir1->setObjectName(QStringLiteral("invertDir1"));

        gridLayout_3->addWidget(invertDir1, 2, 12, 1, 1);

        label_12 = new QLabel(motorGroup);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_3->addWidget(label_12, 3, 1, 1, 1);

        label_13 = new QLabel(motorGroup);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_3->addWidget(label_13, 4, 1, 1, 1);

        label_14 = new QLabel(motorGroup);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_3->addWidget(label_14, 5, 1, 1, 1);

        stepsPerMm2 = new QDoubleSpinBox(motorGroup);
        stepsPerMm2->setObjectName(QStringLiteral("stepsPerMm2"));
        stepsPerMm2->setMaximum(100000);

        gridLayout_3->addWidget(stepsPerMm2, 3, 4, 1, 1);

        stepsPerMm3 = new QDoubleSpinBox(motorGroup);
        stepsPerMm3->setObjectName(QStringLiteral("stepsPerMm3"));
        stepsPerMm3->setMaximum(100000);

        gridLayout_3->addWidget(stepsPerMm3, 4, 4, 1, 1);

        stepsPerMm4 = new QDoubleSpinBox(motorGroup);
        stepsPerMm4->setObjectName(QStringLiteral("stepsPerMm4"));
        stepsPerMm4->setMaximum(100000);

        gridLayout_3->addWidget(stepsPerMm4, 5, 4, 1, 1);

        invertDir2 = new QCheckBox(motorGroup);
        invertDir2->setObjectName(QStringLiteral("invertDir2"));

        gridLayout_3->addWidget(invertDir2, 3, 12, 1, 1);

        invertDir3 = new QCheckBox(motorGroup);
        invertDir3->setObjectName(QStringLiteral("invertDir3"));

        gridLayout_3->addWidget(invertDir3, 4, 12, 1, 1);

        invertDir4 = new QCheckBox(motorGroup);
        invertDir4->setObjectName(QStringLiteral("invertDir4"));

        gridLayout_3->addWidget(invertDir4, 5, 12, 1, 1);

        line_19 = new QFrame(motorGroup);
        line_19->setObjectName(QStringLiteral("line_19"));
        line_19->setFrameShape(QFrame::VLine);
        line_19->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_19, 0, 8, 1, 1);

        maxFeedrate4 = new QDoubleSpinBox(motorGroup);
        maxFeedrate4->setObjectName(QStringLiteral("maxFeedrate4"));
        maxFeedrate4->setMaximum(100000);

        gridLayout_3->addWidget(maxFeedrate4, 5, 6, 1, 1);

        label_5 = new QLabel(motorGroup);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_3->addWidget(label_5, 0, 9, 1, 1);

        maxAccel1 = new QSpinBox(motorGroup);
        maxAccel1->setObjectName(QStringLiteral("maxAccel1"));
        maxAccel1->setMaximum(9999);

        gridLayout_3->addWidget(maxAccel1, 2, 9, 1, 1);

        maxAccel4 = new QSpinBox(motorGroup);
        maxAccel4->setObjectName(QStringLiteral("maxAccel4"));
        maxAccel4->setMaximum(99999);

        gridLayout_3->addWidget(maxAccel4, 5, 9, 1, 1);

        maxAccel3 = new QSpinBox(motorGroup);
        maxAccel3->setObjectName(QStringLiteral("maxAccel3"));
        maxAccel3->setMaximum(99999);

        gridLayout_3->addWidget(maxAccel3, 4, 9, 1, 1);

        maxAccel2 = new QSpinBox(motorGroup);
        maxAccel2->setObjectName(QStringLiteral("maxAccel2"));
        maxAccel2->setMaximum(99999);

        gridLayout_3->addWidget(maxAccel2, 3, 9, 1, 1);

        label_6 = new QLabel(motorGroup);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_3->addWidget(label_6, 6, 1, 1, 1);

        invertDir5 = new QCheckBox(motorGroup);
        invertDir5->setObjectName(QStringLiteral("invertDir5"));

        gridLayout_3->addWidget(invertDir5, 6, 12, 1, 1);


        gridLayout_10->addWidget(motorGroup, 0, 0, 1, 1);

        tabWidget->addTab(widget, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_12 = new QGridLayout(tab);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        pidGroup = new QGroupBox(tab);
        pidGroup->setObjectName(QStringLiteral("pidGroup"));
        pidGroup->setEnabled(false);
        gridLayout_5 = new QGridLayout(pidGroup);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        line_16 = new QFrame(pidGroup);
        line_16->setObjectName(QStringLiteral("line_16"));
        line_16->setFrameShape(QFrame::VLine);
        line_16->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_16, 0, 2, 1, 1);

        pidD1 = new QDoubleSpinBox(pidGroup);
        pidD1->setObjectName(QStringLiteral("pidD1"));
        pidD1->setMaximum(100000);

        gridLayout_5->addWidget(pidD1, 2, 5, 1, 1);

        label_30 = new QLabel(pidGroup);
        label_30->setObjectName(QStringLiteral("label_30"));

        gridLayout_5->addWidget(label_30, 0, 3, 1, 1);

        label_31 = new QLabel(pidGroup);
        label_31->setObjectName(QStringLiteral("label_31"));

        gridLayout_5->addWidget(label_31, 0, 5, 1, 1);

        line_17 = new QFrame(pidGroup);
        line_17->setObjectName(QStringLiteral("line_17"));
        line_17->setFrameShape(QFrame::VLine);
        line_17->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_17, 0, 4, 1, 1);

        pidI1 = new QDoubleSpinBox(pidGroup);
        pidI1->setObjectName(QStringLiteral("pidI1"));
        pidI1->setMaximum(100000);

        gridLayout_5->addWidget(pidI1, 2, 3, 1, 1);

        line_14 = new QFrame(pidGroup);
        line_14->setObjectName(QStringLiteral("line_14"));
        line_14->setFrameShape(QFrame::HLine);
        line_14->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_14, 1, 0, 1, 8);

        label_29 = new QLabel(pidGroup);
        label_29->setObjectName(QStringLiteral("label_29"));

        gridLayout_5->addWidget(label_29, 0, 1, 1, 1);

        pidP1 = new QDoubleSpinBox(pidGroup);
        pidP1->setObjectName(QStringLiteral("pidP1"));
        pidP1->setMaximum(100000);

        gridLayout_5->addWidget(pidP1, 2, 1, 1, 1);

        pidC1 = new QDoubleSpinBox(pidGroup);
        pidC1->setObjectName(QStringLiteral("pidC1"));
        pidC1->setMaximum(1e+06);

        gridLayout_5->addWidget(pidC1, 2, 7, 1, 1);

        line_15 = new QFrame(pidGroup);
        line_15->setObjectName(QStringLiteral("line_15"));
        line_15->setFrameShape(QFrame::VLine);
        line_15->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_15, 0, 6, 1, 1);

        label_22 = new QLabel(pidGroup);
        label_22->setObjectName(QStringLiteral("label_22"));

        gridLayout_5->addWidget(label_22, 0, 7, 1, 1);


        gridLayout_12->addWidget(pidGroup, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_12->addItem(verticalSpacer, 1, 0, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_12->addItem(horizontalSpacer_7, 0, 1, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        gridLayout_14 = new QGridLayout(tab_4);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        accelerationGroup = new QGroupBox(tab_4);
        accelerationGroup->setObjectName(QStringLiteral("accelerationGroup"));
        accelerationGroup->setEnabled(false);
        gridLayout_7 = new QGridLayout(accelerationGroup);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        label_41 = new QLabel(accelerationGroup);
        label_41->setObjectName(QStringLiteral("label_41"));

        gridLayout_7->addWidget(label_41, 0, 0, 1, 1);

        line_24 = new QFrame(accelerationGroup);
        line_24->setObjectName(QStringLiteral("line_24"));
        line_24->setFrameShape(QFrame::HLine);
        line_24->setFrameShadow(QFrame::Sunken);

        gridLayout_7->addWidget(line_24, 1, 0, 1, 5);

        line_25 = new QFrame(accelerationGroup);
        line_25->setObjectName(QStringLiteral("line_25"));
        line_25->setFrameShape(QFrame::VLine);
        line_25->setFrameShadow(QFrame::Sunken);

        gridLayout_7->addWidget(line_25, 0, 1, 1, 2);

        label_42 = new QLabel(accelerationGroup);
        label_42->setObjectName(QStringLiteral("label_42"));

        gridLayout_7->addWidget(label_42, 0, 3, 1, 1);

        acceleration = new QDoubleSpinBox(accelerationGroup);
        acceleration->setObjectName(QStringLiteral("acceleration"));
        acceleration->setMaximum(100000);

        gridLayout_7->addWidget(acceleration, 2, 0, 1, 1);

        acceleration_retract = new QDoubleSpinBox(accelerationGroup);
        acceleration_retract->setObjectName(QStringLiteral("acceleration_retract"));
        acceleration_retract->setMaximum(100000);

        gridLayout_7->addWidget(acceleration_retract, 2, 3, 1, 1);


        gridLayout_14->addWidget(accelerationGroup, 0, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_14->addItem(verticalSpacer_5, 1, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_14->addItem(horizontalSpacer_5, 0, 1, 1, 1);

        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        gridLayout_15 = new QGridLayout(tab_5);
        gridLayout_15->setObjectName(QStringLiteral("gridLayout_15"));
        ExtruderOffsetGroup = new QGroupBox(tab_5);
        ExtruderOffsetGroup->setObjectName(QStringLiteral("ExtruderOffsetGroup"));
        ExtruderOffsetGroup->setEnabled(false);
        gridLayout_4 = new QGridLayout(ExtruderOffsetGroup);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_9 = new QLabel(ExtruderOffsetGroup);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_4->addWidget(label_9, 0, 0, 1, 1);

        line_5 = new QFrame(ExtruderOffsetGroup);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_5, 0, 1, 1, 1);

        label_10 = new QLabel(ExtruderOffsetGroup);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_4->addWidget(label_10, 0, 2, 1, 1);

        line_6 = new QFrame(ExtruderOffsetGroup);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_6, 0, 3, 1, 1);

        label_15 = new QLabel(ExtruderOffsetGroup);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_4->addWidget(label_15, 0, 4, 1, 1);

        line_7 = new QFrame(ExtruderOffsetGroup);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_7, 1, 0, 1, 5);

        extruderOffsetX = new QDoubleSpinBox(ExtruderOffsetGroup);
        extruderOffsetX->setObjectName(QStringLiteral("extruderOffsetX"));
        extruderOffsetX->setMinimum(-99999);
        extruderOffsetX->setMaximum(100000);

        gridLayout_4->addWidget(extruderOffsetX, 2, 0, 1, 1);

        extruderOffsetY = new QDoubleSpinBox(ExtruderOffsetGroup);
        extruderOffsetY->setObjectName(QStringLiteral("extruderOffsetY"));
        extruderOffsetY->setMinimum(-99999);
        extruderOffsetY->setMaximum(100000);

        gridLayout_4->addWidget(extruderOffsetY, 2, 2, 1, 1);

        extruderOffsetZ = new QDoubleSpinBox(ExtruderOffsetGroup);
        extruderOffsetZ->setObjectName(QStringLiteral("extruderOffsetZ"));
        extruderOffsetZ->setMinimum(-99999);
        extruderOffsetZ->setMaximum(100000);

        gridLayout_4->addWidget(extruderOffsetZ, 2, 4, 1, 1);


        gridLayout_15->addWidget(ExtruderOffsetGroup, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_15->addItem(verticalSpacer_2, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_15->addItem(horizontalSpacer_2, 0, 1, 1, 1);

        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        gridLayout_16 = new QGridLayout(tab_6);
        gridLayout_16->setObjectName(QStringLiteral("gridLayout_16"));
        advancedGroup = new QGroupBox(tab_6);
        advancedGroup->setObjectName(QStringLiteral("advancedGroup"));
        advancedGroup->setEnabled(false);
        gridLayout_6 = new QGridLayout(advancedGroup);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        label_21 = new QLabel(advancedGroup);
        label_21->setObjectName(QStringLiteral("label_21"));

        gridLayout_6->addWidget(label_21, 1, 8, 1, 1);

        line_10 = new QFrame(advancedGroup);
        line_10->setObjectName(QStringLiteral("line_10"));
        line_10->setFrameShape(QFrame::VLine);
        line_10->setFrameShadow(QFrame::Sunken);

        gridLayout_6->addWidget(line_10, 0, 3, 3, 1);

        minFeedrate = new QDoubleSpinBox(advancedGroup);
        minFeedrate->setObjectName(QStringLiteral("minFeedrate"));
        minFeedrate->setMaximum(100000);

        gridLayout_6->addWidget(minFeedrate, 4, 0, 1, 1);

        maxZjerk = new QDoubleSpinBox(advancedGroup);
        maxZjerk->setObjectName(QStringLiteral("maxZjerk"));
        maxZjerk->setMaximum(100000);

        gridLayout_6->addWidget(maxZjerk, 4, 6, 1, 1);

        line_13 = new QFrame(advancedGroup);
        line_13->setObjectName(QStringLiteral("line_13"));
        line_13->setFrameShape(QFrame::VLine);
        line_13->setFrameShadow(QFrame::Sunken);

        gridLayout_6->addWidget(line_13, 0, 7, 3, 1);

        label_20 = new QLabel(advancedGroup);
        label_20->setObjectName(QStringLiteral("label_20"));

        gridLayout_6->addWidget(label_20, 1, 6, 1, 1);

        label_19 = new QLabel(advancedGroup);
        label_19->setObjectName(QStringLiteral("label_19"));

        gridLayout_6->addWidget(label_19, 1, 4, 1, 1);

        maxXYJerk = new QDoubleSpinBox(advancedGroup);
        maxXYJerk->setObjectName(QStringLiteral("maxXYJerk"));
        maxXYJerk->setMaximum(1e+06);

        gridLayout_6->addWidget(maxXYJerk, 4, 4, 1, 1);

        label_17 = new QLabel(advancedGroup);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_6->addWidget(label_17, 1, 2, 1, 1);

        line_8 = new QFrame(advancedGroup);
        line_8->setObjectName(QStringLiteral("line_8"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        gridLayout_6->addWidget(line_8, 3, 0, 1, 9);

        minTravelFeedrate = new QDoubleSpinBox(advancedGroup);
        minTravelFeedrate->setObjectName(QStringLiteral("minTravelFeedrate"));
        minTravelFeedrate->setMaximum(100000);

        gridLayout_6->addWidget(minTravelFeedrate, 4, 2, 1, 1);

        label_16 = new QLabel(advancedGroup);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout_6->addWidget(label_16, 1, 0, 1, 1);

        line_9 = new QFrame(advancedGroup);
        line_9->setObjectName(QStringLiteral("line_9"));
        line_9->setFrameShape(QFrame::VLine);
        line_9->setFrameShadow(QFrame::Sunken);

        gridLayout_6->addWidget(line_9, 0, 1, 3, 1);

        maxEjerk = new QDoubleSpinBox(advancedGroup);
        maxEjerk->setObjectName(QStringLiteral("maxEjerk"));
        maxEjerk->setMaximum(100000);

        gridLayout_6->addWidget(maxEjerk, 4, 8, 1, 1);

        line_12 = new QFrame(advancedGroup);
        line_12->setObjectName(QStringLiteral("line_12"));
        line_12->setFrameShape(QFrame::VLine);
        line_12->setFrameShadow(QFrame::Sunken);

        gridLayout_6->addWidget(line_12, 0, 5, 3, 1);


        gridLayout_16->addWidget(advancedGroup, 0, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_16->addItem(horizontalSpacer_3, 0, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_16->addItem(verticalSpacer_3, 1, 0, 1, 1);

        tabWidget->addTab(tab_6, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_11 = new QGridLayout(tab_2);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        preheatGroupAbs = new QGroupBox(tab_2);
        preheatGroupAbs->setObjectName(QStringLiteral("preheatGroupAbs"));
        preheatGroupAbs->setEnabled(false);
        gridLayout_9 = new QGridLayout(preheatGroupAbs);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        line_21 = new QFrame(preheatGroupAbs);
        line_21->setObjectName(QStringLiteral("line_21"));
        line_21->setFrameShape(QFrame::VLine);
        line_21->setFrameShadow(QFrame::Sunken);

        gridLayout_9->addWidget(line_21, 0, 1, 2, 1);

        line_22 = new QFrame(preheatGroupAbs);
        line_22->setObjectName(QStringLiteral("line_22"));
        line_22->setFrameShape(QFrame::VLine);
        line_22->setFrameShadow(QFrame::Sunken);

        gridLayout_9->addWidget(line_22, 0, 3, 2, 2);

        label_25 = new QLabel(preheatGroupAbs);
        label_25->setObjectName(QStringLiteral("label_25"));

        gridLayout_9->addWidget(label_25, 1, 0, 1, 1);

        label_26 = new QLabel(preheatGroupAbs);
        label_26->setObjectName(QStringLiteral("label_26"));

        gridLayout_9->addWidget(label_26, 1, 2, 1, 1);

        label_27 = new QLabel(preheatGroupAbs);
        label_27->setObjectName(QStringLiteral("label_27"));

        gridLayout_9->addWidget(label_27, 1, 4, 1, 2);

        line_23 = new QFrame(preheatGroupAbs);
        line_23->setObjectName(QStringLiteral("line_23"));
        line_23->setFrameShape(QFrame::HLine);
        line_23->setFrameShadow(QFrame::Sunken);

        gridLayout_9->addWidget(line_23, 2, 0, 1, 6);

        hotendtempAbs = new QSpinBox(preheatGroupAbs);
        hotendtempAbs->setObjectName(QStringLiteral("hotendtempAbs"));
        hotendtempAbs->setMaximum(400);

        gridLayout_9->addWidget(hotendtempAbs, 3, 0, 1, 1);

        bedTempAbs = new QSpinBox(preheatGroupAbs);
        bedTempAbs->setObjectName(QStringLiteral("bedTempAbs"));
        bedTempAbs->setMaximum(400);

        gridLayout_9->addWidget(bedTempAbs, 3, 2, 1, 1);

        fanSpeedAbs = new QSpinBox(preheatGroupAbs);
        fanSpeedAbs->setObjectName(QStringLiteral("fanSpeedAbs"));
        fanSpeedAbs->setMaximum(255);

        gridLayout_9->addWidget(fanSpeedAbs, 3, 5, 1, 1);


        gridLayout_11->addWidget(preheatGroupAbs, 0, 1, 1, 1);

        preheatGroupPla = new QGroupBox(tab_2);
        preheatGroupPla->setObjectName(QStringLiteral("preheatGroupPla"));
        preheatGroupPla->setEnabled(false);
        gridLayout_8 = new QGridLayout(preheatGroupPla);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        line_18 = new QFrame(preheatGroupPla);
        line_18->setObjectName(QStringLiteral("line_18"));
        line_18->setFrameShape(QFrame::VLine);
        line_18->setFrameShadow(QFrame::Sunken);

        gridLayout_8->addWidget(line_18, 0, 1, 2, 1);

        line_20 = new QFrame(preheatGroupPla);
        line_20->setObjectName(QStringLiteral("line_20"));
        line_20->setFrameShape(QFrame::VLine);
        line_20->setFrameShadow(QFrame::Sunken);

        gridLayout_8->addWidget(line_20, 0, 3, 2, 2);

        label_18 = new QLabel(preheatGroupPla);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout_8->addWidget(label_18, 1, 0, 1, 1);

        label_23 = new QLabel(preheatGroupPla);
        label_23->setObjectName(QStringLiteral("label_23"));

        gridLayout_8->addWidget(label_23, 1, 2, 1, 1);

        label_24 = new QLabel(preheatGroupPla);
        label_24->setObjectName(QStringLiteral("label_24"));

        gridLayout_8->addWidget(label_24, 1, 4, 1, 2);

        line_11 = new QFrame(preheatGroupPla);
        line_11->setObjectName(QStringLiteral("line_11"));
        line_11->setFrameShape(QFrame::HLine);
        line_11->setFrameShadow(QFrame::Sunken);

        gridLayout_8->addWidget(line_11, 2, 0, 1, 6);

        HotendTempPla = new QSpinBox(preheatGroupPla);
        HotendTempPla->setObjectName(QStringLiteral("HotendTempPla"));
        HotendTempPla->setMaximum(400);

        gridLayout_8->addWidget(HotendTempPla, 3, 0, 1, 1);

        bedTempPla = new QSpinBox(preheatGroupPla);
        bedTempPla->setObjectName(QStringLiteral("bedTempPla"));
        bedTempPla->setMaximum(400);

        gridLayout_8->addWidget(bedTempPla, 3, 2, 1, 1);

        fanSpeedPla = new QSpinBox(preheatGroupPla);
        fanSpeedPla->setObjectName(QStringLiteral("fanSpeedPla"));
        fanSpeedPla->setMaximum(255);

        gridLayout_8->addWidget(fanSpeedPla, 3, 5, 1, 1);


        gridLayout_11->addWidget(preheatGroupPla, 0, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_11->addItem(verticalSpacer_6, 1, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_11->addItem(horizontalSpacer_4, 0, 2, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout_2->addWidget(tabWidget, 3, 0, 1, 8);

        saveConfig = new QPushButton(flash_group);
        saveConfig->setObjectName(QStringLiteral("saveConfig"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(saveConfig->sizePolicy().hasHeightForWidth());
        saveConfig->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(saveConfig, 0, 7, 1, 1);

        com_port = new QComboBox(flash_group);
        com_port->setObjectName(QStringLiteral("com_port"));

        gridLayout_2->addWidget(com_port, 0, 1, 1, 1);

        firmware_version = new QLabel(flash_group);
        firmware_version->setObjectName(QStringLiteral("firmware_version"));

        gridLayout_2->addWidget(firmware_version, 1, 1, 1, 1);

        label = new QLabel(flash_group);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        export_config = new QPushButton(flash_group);
        export_config->setObjectName(QStringLiteral("export_config"));

        gridLayout_2->addWidget(export_config, 1, 5, 1, 1);

        label_2 = new QLabel(flash_group);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 4, 1, 1);

        import_config = new QPushButton(flash_group);
        import_config->setObjectName(QStringLiteral("import_config"));

        gridLayout_2->addWidget(import_config, 0, 5, 1, 1);

        connect = new QPushButton(flash_group);
        connect->setObjectName(QStringLiteral("connect"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(connect->sizePolicy().hasHeightForWidth());
        connect->setSizePolicy(sizePolicy3);

        gridLayout_2->addWidget(connect, 0, 2, 1, 1);

        reloadDefaults = new QPushButton(flash_group);
        reloadDefaults->setObjectName(QStringLiteral("reloadDefaults"));

        gridLayout_2->addWidget(reloadDefaults, 1, 7, 1, 1);


        gridLayout->addWidget(flash_group, 0, 0, 1, 1);

        Echinus_Config_frm->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Echinus_Config_frm);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 757, 24));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        Echinus_Config_frm->setMenuBar(menubar);
        statusbar = new QStatusBar(Echinus_Config_frm);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Echinus_Config_frm->setStatusBar(statusbar);

        menubar->addAction(menuAbout->menuAction());
        menuAbout->addAction(action_About);
        menuAbout->addAction(actionAbout_Qt);

        retranslateUi(Echinus_Config_frm);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Echinus_Config_frm);
    } // setupUi

    void retranslateUi(QMainWindow *Echinus_Config_frm)
    {
        Echinus_Config_frm->setWindowTitle(QApplication::translate("Echinus_Config_frm", "Echinus Config Marlin", 0));
        actionEmpty_local_download_cache->setText(QApplication::translate("Echinus_Config_frm", "Empty local download cache", 0));
        actionInstall_Rockbox_Utility_on_player->setText(QApplication::translate("Echinus_Config_frm", "Install Rockbox Utility on player", 0));
        action_Configure->setText(QApplication::translate("Echinus_Config_frm", "&Configure", 0));
        actionE_xit->setText(QApplication::translate("Echinus_Config_frm", "E&xit", 0));
        actionE_xit->setShortcut(QApplication::translate("Echinus_Config_frm", "Ctrl+Q", 0));
        action_About->setText(QApplication::translate("Echinus_Config_frm", "&About", 0));
        actionAbout_Qt->setText(QApplication::translate("Echinus_Config_frm", "About &Qt", 0));
        action_Help->setText(QApplication::translate("Echinus_Config_frm", "&Help", 0));
        actionInfo->setText(QApplication::translate("Echinus_Config_frm", "Info", 0));
        actionComplete_Installation->setText(QApplication::translate("Echinus_Config_frm", "&Complete Installation", 0));
        actionSmall_Installation->setText(QApplication::translate("Echinus_Config_frm", "&Minimal Installation", 0));
        actionInstall_Bootloader->setText(QApplication::translate("Echinus_Config_frm", "Install &Bootloader", 0));
        actionInstall_Rockbox->setText(QApplication::translate("Echinus_Config_frm", "Install &Rockbox", 0));
        actionFonts_Package->setText(QApplication::translate("Echinus_Config_frm", "Install &Fonts Package", 0));
        actionInstall_Themes->setText(QApplication::translate("Echinus_Config_frm", "Install &Themes", 0));
        actionInstall_Game_Files->setText(QApplication::translate("Echinus_Config_frm", "Install &Game Files", 0));
        actionInstall_Voice_File->setText(QApplication::translate("Echinus_Config_frm", "&Install Voice File", 0));
        actionCreate_Talk_Files->setText(QApplication::translate("Echinus_Config_frm", "Create &Talk Files", 0));
        actionRemove_bootloader->setText(QApplication::translate("Echinus_Config_frm", "Remove &bootloader", 0));
        actionUninstall_Rockbox->setText(QApplication::translate("Echinus_Config_frm", "Uninstall &Rockbox", 0));
        actionRead_PDF_manual->setText(QApplication::translate("Echinus_Config_frm", "Read PDF manual", 0));
        actionRead_HTML_manual->setText(QApplication::translate("Echinus_Config_frm", "Read HTML manual", 0));
        actionDownload_PDF_manual->setText(QApplication::translate("Echinus_Config_frm", "Download PDF manual", 0));
        actionDownload_HTML_manual_zip->setText(QApplication::translate("Echinus_Config_frm", "Download HTML manual (zip)", 0));
        actionCreate_Voice_File->setText(QApplication::translate("Echinus_Config_frm", "Create &Voice File", 0));
        actionCreate_Voice_File->setIconText(QApplication::translate("Echinus_Config_frm", "Create Voice File", 0));
        action_System_Info->setText(QApplication::translate("Echinus_Config_frm", "&System Info", 0));
        action_Trace->setText(QApplication::translate("Echinus_Config_frm", "System &Trace", 0));
        flash_group->setTitle(QApplication::translate("Echinus_Config_frm", "Echinus Config", 0));
        disconnect->setText(QApplication::translate("Echinus_Config_frm", "Disconnect", 0));
        motorGroup->setTitle(QApplication::translate("Echinus_Config_frm", "Motor options", 0));
        label_8->setText(QApplication::translate("Echinus_Config_frm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Maximum</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">feed rate</span></p></body></html>", 0));
        label_7->setText(QApplication::translate("Echinus_Config_frm", "Steps per mm", 0));
        label_4->setText(QApplication::translate("Echinus_Config_frm", "Axis", 0));
        label_11->setText(QApplication::translate("Echinus_Config_frm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Invert </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">direction</span></p></body></html>", 0));
        label_3->setText(QApplication::translate("Echinus_Config_frm", "X:", 0));
        invertDir1->setText(QString());
        label_12->setText(QApplication::translate("Echinus_Config_frm", "Y:", 0));
        label_13->setText(QApplication::translate("Echinus_Config_frm", "Z:", 0));
        label_14->setText(QApplication::translate("Echinus_Config_frm", "E:", 0));
        invertDir2->setText(QString());
        invertDir3->setText(QString());
        invertDir4->setText(QString());
        label_5->setText(QApplication::translate("Echinus_Config_frm", "<html><head/><body>Maximum <br/> acceleration</body></html>", 0));
        label_6->setText(QApplication::translate("Echinus_Config_frm", "X2:", 0));
        invertDir5->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(widget), QApplication::translate("Echinus_Config_frm", "Motors", 0));
        pidGroup->setTitle(QApplication::translate("Echinus_Config_frm", "PID options", 0));
        label_30->setText(QApplication::translate("Echinus_Config_frm", "I Value", 0));
        label_31->setText(QApplication::translate("Echinus_Config_frm", "D Value", 0));
        label_29->setText(QApplication::translate("Echinus_Config_frm", "P Value", 0));
        label_22->setText(QApplication::translate("Echinus_Config_frm", "C Value", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Echinus_Config_frm", "PID", 0));
        accelerationGroup->setTitle(QApplication::translate("Echinus_Config_frm", "Acceleration options", 0));
        label_41->setText(QApplication::translate("Echinus_Config_frm", "Acceleration", 0));
        label_42->setText(QApplication::translate("Echinus_Config_frm", "Retract acceleration", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("Echinus_Config_frm", "Acceleration", 0));
        ExtruderOffsetGroup->setTitle(QApplication::translate("Echinus_Config_frm", "Extruder Offsets", 0));
        label_9->setText(QApplication::translate("Echinus_Config_frm", "X direction", 0));
        label_10->setText(QApplication::translate("Echinus_Config_frm", "Y direction", 0));
        label_15->setText(QApplication::translate("Echinus_Config_frm", "Z direction", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("Echinus_Config_frm", "Extruder Offsets", 0));
        advancedGroup->setTitle(QApplication::translate("Echinus_Config_frm", "Advanced Variables", 0));
        label_21->setText(QApplication::translate("Echinus_Config_frm", "Max E jerk", 0));
        label_20->setText(QApplication::translate("Echinus_Config_frm", "Max. Z jerk", 0));
        label_19->setText(QApplication::translate("Echinus_Config_frm", "Max. XY jerk", 0));
        label_17->setText(QApplication::translate("Echinus_Config_frm", "Min. Travel Feedrate", 0));
        label_16->setText(QApplication::translate("Echinus_Config_frm", "Min. Feedrate", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("Echinus_Config_frm", "Advanced Variables", 0));
        preheatGroupAbs->setTitle(QApplication::translate("Echinus_Config_frm", "Preheat ABS config", 0));
        label_25->setText(QApplication::translate("Echinus_Config_frm", "Hotend Temp", 0));
        label_26->setText(QApplication::translate("Echinus_Config_frm", "Bed Temp", 0));
        label_27->setText(QApplication::translate("Echinus_Config_frm", "Fan Speed", 0));
        preheatGroupPla->setTitle(QApplication::translate("Echinus_Config_frm", "Preheat PLA config", 0));
        label_18->setText(QApplication::translate("Echinus_Config_frm", "Hotend Temp", 0));
        label_23->setText(QApplication::translate("Echinus_Config_frm", "Bed Temp", 0));
        label_24->setText(QApplication::translate("Echinus_Config_frm", "Fan Speed", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Echinus_Config_frm", "Preheat Config", 0));
        saveConfig->setText(QApplication::translate("Echinus_Config_frm", "Save Permanent", 0));
        firmware_version->setText(QApplication::translate("Echinus_Config_frm", "not connected", 0));
        label->setText(QApplication::translate("Echinus_Config_frm", "Select Com Port", 0));
        export_config->setText(QApplication::translate("Echinus_Config_frm", "Export Config", 0));
        label_2->setText(QApplication::translate("Echinus_Config_frm", "Firmware version: ", 0));
        import_config->setText(QApplication::translate("Echinus_Config_frm", "Import Config", 0));
        connect->setText(QApplication::translate("Echinus_Config_frm", "Connect", 0));
        reloadDefaults->setText(QApplication::translate("Echinus_Config_frm", "Reload Defaults", 0));
        menuAbout->setTitle(QApplication::translate("Echinus_Config_frm", "&Help", 0));
    } // retranslateUi

};

namespace Ui {
    class Echinus_Config_frm: public Ui_Echinus_Config_frm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ECHINUS_CONFIG_FRM_H
