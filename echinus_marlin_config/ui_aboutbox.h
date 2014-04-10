/********************************************************************************
** Form generated from reading UI file 'aboutbox.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTBOX_H
#define UI_ABOUTBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_aboutBox
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *hboxLayout;
    QLabel *label;
    QLabel *labelTitle;
    QSpacerItem *spacerItem;
    QLabel *labelText;
    QTabWidget *tabWidget;
    QWidget *creditsTab;
    QGridLayout *gridLayout1;
    QTextBrowser *browserCredits;
    QWidget *licenceTab;
    QGridLayout *gridLayout2;
    QTextBrowser *browserLicense;
    QSpacerItem *spacerItem1;
    QPushButton *okButton;
    QSpacerItem *spacerItem2;

    void setupUi(QWidget *aboutBox)
    {
        if (aboutBox->objectName().isEmpty())
            aboutBox->setObjectName(QStringLiteral("aboutBox"));
        aboutBox->resize(500, 500);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/rockbox-1.png"), QSize(), QIcon::Normal, QIcon::Off);
        aboutBox->setWindowIcon(icon);
        gridLayout = new QGridLayout(aboutBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        label = new QLabel(aboutBox);
        label->setObjectName(QStringLiteral("label"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/icons/rockbox-5.png")));

        hboxLayout->addWidget(label);

        labelTitle = new QLabel(aboutBox);
        labelTitle->setObjectName(QStringLiteral("labelTitle"));

        hboxLayout->addWidget(labelTitle);

        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);


        gridLayout->addLayout(hboxLayout, 0, 0, 1, 3);

        labelText = new QLabel(aboutBox);
        labelText->setObjectName(QStringLiteral("labelText"));
        labelText->setTextFormat(Qt::RichText);
        labelText->setWordWrap(true);
        labelText->setOpenExternalLinks(true);

        gridLayout->addWidget(labelText, 1, 0, 1, 3);

        tabWidget = new QTabWidget(aboutBox);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        creditsTab = new QWidget();
        creditsTab->setObjectName(QStringLiteral("creditsTab"));
        gridLayout1 = new QGridLayout(creditsTab);
        gridLayout1->setObjectName(QStringLiteral("gridLayout1"));
        browserCredits = new QTextBrowser(creditsTab);
        browserCredits->setObjectName(QStringLiteral("browserCredits"));
        browserCredits->setFocusPolicy(Qt::TabFocus);
        browserCredits->setAcceptDrops(false);
        browserCredits->setAutoFillBackground(true);
        browserCredits->setAutoFormatting(QTextEdit::AutoNone);
        browserCredits->setTabChangesFocus(true);
        browserCredits->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse|Qt::TextBrowserInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        browserCredits->setOpenExternalLinks(true);

        gridLayout1->addWidget(browserCredits, 0, 0, 1, 1);

        tabWidget->addTab(creditsTab, QString());
        licenceTab = new QWidget();
        licenceTab->setObjectName(QStringLiteral("licenceTab"));
        gridLayout2 = new QGridLayout(licenceTab);
        gridLayout2->setObjectName(QStringLiteral("gridLayout2"));
        browserLicense = new QTextBrowser(licenceTab);
        browserLicense->setObjectName(QStringLiteral("browserLicense"));
        browserLicense->setFocusPolicy(Qt::TabFocus);
        browserLicense->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        browserLicense->setTabChangesFocus(true);
        browserLicense->setLineWrapMode(QTextEdit::WidgetWidth);
        browserLicense->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse|Qt::TextBrowserInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout2->addWidget(browserLicense, 0, 0, 1, 1);

        tabWidget->addTab(licenceTab, QString());

        gridLayout->addWidget(tabWidget, 2, 0, 1, 3);

        spacerItem1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem1, 3, 0, 1, 1);

        okButton = new QPushButton(aboutBox);
        okButton->setObjectName(QStringLiteral("okButton"));

        gridLayout->addWidget(okButton, 3, 1, 1, 1);

        spacerItem2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem2, 3, 2, 1, 1);


        retranslateUi(aboutBox);
        QObject::connect(okButton, SIGNAL(clicked()), aboutBox, SLOT(close()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(aboutBox);
    } // setupUi

    void retranslateUi(QWidget *aboutBox)
    {
        aboutBox->setWindowTitle(QApplication::translate("aboutBox", "About Rockbox Utility", 0));
        label->setText(QString());
        labelTitle->setText(QApplication::translate("aboutBox", "Echinus Flash Utillity", 0));
        labelText->setText(QApplication::translate("aboutBox", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Configuration Utillity for the Echinus motioncontroller board with Marlin firmware.<br />\302\251 2013 The 2PrintBeta Team.<br />Released under the GNU General Public License v2.<br /></p></body></html>", 0));
        tabWidget->setTabText(tabWidget->indexOf(creditsTab), QApplication::translate("aboutBox", "&Credits", 0));
        tabWidget->setTabText(tabWidget->indexOf(licenceTab), QApplication::translate("aboutBox", "&License", 0));
        okButton->setText(QApplication::translate("aboutBox", "&Ok", 0));
    } // retranslateUi

};

namespace Ui {
    class aboutBox: public Ui_aboutBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTBOX_H
