/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_4;
    QFrame *frame_1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QGraphicsView *graphicsView;
    QGroupBox *groupBox_1;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton_1;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_6;
    QRadioButton *radioButton_7;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_6;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_5;
    QSlider *horizontalSlider_1;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_7;
    QSlider *horizontalSlider_2;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_Load;
    QPushButton *pushButton_Save;
    QPushButton *pushButton_Compile;
    QPushButton *pushButton_Exit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(512, 512);
        MainWindow->setMinimumSize(QSize(512, 512));
        MainWindow->setMaximumSize(QSize(512, 512));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_4 = new QHBoxLayout(centralWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        frame_1 = new QFrame(centralWidget);
        frame_1->setObjectName(QStringLiteral("frame_1"));
        frame_1->setFrameShape(QFrame::StyledPanel);
        frame_1->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        graphicsView = new QGraphicsView(frame_1);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setMinimumSize(QSize(320, 240));
        graphicsView->setMaximumSize(QSize(320, 240));
        graphicsView->setFrameShape(QFrame::NoFrame);
        graphicsView->setFrameShadow(QFrame::Plain);
        graphicsView->setLineWidth(-2);
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        horizontalLayout_2->addWidget(graphicsView);

        groupBox_1 = new QGroupBox(frame_1);
        groupBox_1->setObjectName(QStringLiteral("groupBox_1"));
        horizontalLayout = new QHBoxLayout(groupBox_1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        radioButton_1 = new QRadioButton(groupBox_1);
        radioButton_1->setObjectName(QStringLiteral("radioButton_1"));
        radioButton_1->setChecked(true);

        verticalLayout->addWidget(radioButton_1);

        radioButton_2 = new QRadioButton(groupBox_1);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        verticalLayout->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(groupBox_1);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        verticalLayout->addWidget(radioButton_3);

        radioButton_4 = new QRadioButton(groupBox_1);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));

        verticalLayout->addWidget(radioButton_4);

        radioButton_5 = new QRadioButton(groupBox_1);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));

        verticalLayout->addWidget(radioButton_5);

        radioButton_6 = new QRadioButton(groupBox_1);
        radioButton_6->setObjectName(QStringLiteral("radioButton_6"));

        verticalLayout->addWidget(radioButton_6);

        radioButton_7 = new QRadioButton(groupBox_1);
        radioButton_7->setObjectName(QStringLiteral("radioButton_7"));

        verticalLayout->addWidget(radioButton_7);


        horizontalLayout->addLayout(verticalLayout);


        horizontalLayout_2->addWidget(groupBox_1);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_4->addWidget(frame_1);

        frame_3 = new QFrame(centralWidget);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy1);
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_6 = new QHBoxLayout(frame_3);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        groupBox_2 = new QGroupBox(frame_3);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout_5 = new QHBoxLayout(groupBox_2);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSlider_1 = new QSlider(groupBox_2);
        horizontalSlider_1->setObjectName(QStringLiteral("horizontalSlider_1"));
        horizontalSlider_1->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(horizontalSlider_1->sizePolicy().hasHeightForWidth());
        horizontalSlider_1->setSizePolicy(sizePolicy2);
        horizontalSlider_1->setMaximum(100);
        horizontalSlider_1->setSingleStep(5);
        horizontalSlider_1->setPageStep(20);
        horizontalSlider_1->setValue(50);
        horizontalSlider_1->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(horizontalSlider_1);


        horizontalLayout_6->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(frame_3);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        horizontalLayout_7 = new QHBoxLayout(groupBox_3);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSlider_2 = new QSlider(groupBox_3);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        sizePolicy2.setHeightForWidth(horizontalSlider_2->sizePolicy().hasHeightForWidth());
        horizontalSlider_2->setSizePolicy(sizePolicy2);
        horizontalSlider_2->setMaximum(50);
        horizontalSlider_2->setSingleStep(1);
        horizontalSlider_2->setPageStep(20);
        horizontalSlider_2->setSliderPosition(10);
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(horizontalSlider_2);


        horizontalLayout_6->addWidget(groupBox_3);


        verticalLayout_4->addWidget(frame_3);

        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton_Load = new QPushButton(frame_2);
        pushButton_Load->setObjectName(QStringLiteral("pushButton_Load"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton_Load->sizePolicy().hasHeightForWidth());
        pushButton_Load->setSizePolicy(sizePolicy3);

        horizontalLayout_3->addWidget(pushButton_Load);

        pushButton_Save = new QPushButton(frame_2);
        pushButton_Save->setObjectName(QStringLiteral("pushButton_Save"));
        pushButton_Save->setEnabled(false);
        QSizePolicy sizePolicy4(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(pushButton_Save->sizePolicy().hasHeightForWidth());
        pushButton_Save->setSizePolicy(sizePolicy4);

        horizontalLayout_3->addWidget(pushButton_Save);

        pushButton_Compile = new QPushButton(frame_2);
        pushButton_Compile->setObjectName(QStringLiteral("pushButton_Compile"));
        pushButton_Compile->setEnabled(false);
        sizePolicy4.setHeightForWidth(pushButton_Compile->sizePolicy().hasHeightForWidth());
        pushButton_Compile->setSizePolicy(sizePolicy4);

        horizontalLayout_3->addWidget(pushButton_Compile);

        pushButton_Exit = new QPushButton(frame_2);
        pushButton_Exit->setObjectName(QStringLiteral("pushButton_Exit"));
        sizePolicy4.setHeightForWidth(pushButton_Exit->sizePolicy().hasHeightForWidth());
        pushButton_Exit->setSizePolicy(sizePolicy4);

        horizontalLayout_3->addWidget(pushButton_Exit);


        verticalLayout_3->addLayout(horizontalLayout_3);


        verticalLayout_4->addWidget(frame_2);


        horizontalLayout_4->addLayout(verticalLayout_4);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "LineConverter Gr9 v0.5", 0));
        groupBox_1->setTitle(QApplication::translate("MainWindow", "Preview", 0));
        radioButton_1->setText(QApplication::translate("MainWindow", "Original", 0));
        radioButton_2->setText(QApplication::translate("MainWindow", "GTIA", 0));
        radioButton_3->setText(QApplication::translate("MainWindow", "ATARI PAL", 0));
        radioButton_4->setText(QApplication::translate("MainWindow", "Output", 0));
        radioButton_5->setText(QApplication::translate("MainWindow", "Gray", 0));
        radioButton_6->setText(QApplication::translate("MainWindow", "Green", 0));
        radioButton_7->setText(QApplication::translate("MainWindow", "Chroma", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Saturation Level", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Threshold Level", 0));
        pushButton_Load->setText(QApplication::translate("MainWindow", "Load Picture", 0));
        pushButton_Save->setText(QApplication::translate("MainWindow", "Save ASM", 0));
        pushButton_Compile->setText(QApplication::translate("MainWindow", "Save XEX", 0));
        pushButton_Exit->setText(QApplication::translate("MainWindow", "Exit", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
