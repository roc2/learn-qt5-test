/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QGraphicsView *gameView;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLCDNumber *lcdScore;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QPushButton *btnStart;
    QPushButton *btnPause;
    QPushButton *btnStop;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(1011, 600);
        verticalLayout_4 = new QVBoxLayout(Dialog);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        gameView = new QGraphicsView(Dialog);
        gameView->setObjectName(QStringLiteral("gameView"));

        horizontalLayout->addWidget(gameView);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lcdScore = new QLCDNumber(Dialog);
        lcdScore->setObjectName(QStringLiteral("lcdScore"));

        verticalLayout_2->addWidget(lcdScore);

        verticalSpacer = new QSpacerItem(20, 258, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        btnStart = new QPushButton(Dialog);
        btnStart->setObjectName(QStringLiteral("btnStart"));

        verticalLayout->addWidget(btnStart);

        btnPause = new QPushButton(Dialog);
        btnPause->setObjectName(QStringLiteral("btnPause"));

        verticalLayout->addWidget(btnPause);

        btnStop = new QPushButton(Dialog);
        btnStop->setObjectName(QStringLiteral("btnStop"));

        verticalLayout->addWidget(btnStop);


        verticalLayout_3->addLayout(verticalLayout);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", nullptr));
        btnStart->setText(QApplication::translate("Dialog", "\345\274\200\345\247\213", nullptr));
        btnPause->setText(QApplication::translate("Dialog", "\346\232\202\345\201\234", nullptr));
        btnStop->setText(QApplication::translate("Dialog", "\347\273\223\346\235\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
