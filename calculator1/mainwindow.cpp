#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QListWidget>
#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui->setupUi(this);

    QGridLayout *gridlayout = new QGridLayout(this);
    gridlayout->setSpacing(15);

    QLineEdit *display = new QLineEdit(this);
    display->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    display->setReadOnly(true);
    display->setStyleSheet("QLineEdit{background-color: #BCBCBC}");
    display->setAlignment(Qt::AlignRight);
    display->setMaxLength(15);

    QPushButton *zero = new QPushButton("0", this);
    zero->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    zero->setStyleSheet("QPushButton{font: bold 22px; background-color: #CACACA}");

    QPushButton *comma = new QPushButton(",", this);
    comma->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    comma->setStyleSheet("QPushButton{font: bold 22px; background-color: #CACACA}");

    QPushButton *result = new QPushButton("=", this);
    result->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    result->setStyleSheet("QPushButton{font: bold 22px; background-color: #E99922}");

    QPushButton *backspase = new QPushButton("<=", this);
    backspase->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    backspase->setStyleSheet("QPushButton{font: bold 22px; background-color: #E99922}");

    QPushButton *C = new QPushButton("C", this);
    C->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    C->setStyleSheet("QPushButton{font: bold 22px; background-color: #FD2E2E}");

    QPushButton *leftBracket = new QPushButton("(", this);
    leftBracket->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    leftBracket->setStyleSheet("QPushButton{font: bold 22px; background-color: #E99922}");

    QPushButton *rightBracket = new QPushButton(")", this);
    rightBracket->setStyleSheet("QPushButton{font: bold 22px; background-color: #E99922}");
    rightBracket->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QPushButton *percent = new QPushButton("%", this);
    percent->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    percent->setStyleSheet("QPushButton{font: bold 22px; background-color: #E99922}");


    QList<QString> valuesDigits(
                { "1", "2", "3",
                  "4", "5", "6",
                  "7", "8", "9"
                });

    QPushButton *digitButtons[9];
    for (int i=0; i<valuesDigits.length(); i++){
        digitButtons[i] = new QPushButton();
        digitButtons[i]->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        digitButtons[i]->setText(valuesDigits[i]);
        digitButtons[i]->setStyleSheet("QPushButton{font: bold 22px; background-color: #CACACA}");

    }

    int pos = 0;
    for (int i = 4; i > 1; i--) {
        for (int j = 0; j < 3; j++) {
            digitButtons[pos]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            gridlayout->addWidget(digitButtons[pos], i, j);
            pos++;
        }
    }

    QList<QString> extraOperands(
                {"/", "x^y", "srqt",
                  "*", "x!", "ln",
                  "-", "sin", "cos",
                  "+", "tg", "ctg"
                });

    QPushButton *extraOperandsButtons[12];
    for (int i=0; i<extraOperands.length(); i++){
        extraOperandsButtons[i] = new QPushButton();
        extraOperandsButtons[i]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        extraOperandsButtons[i]->setText(extraOperands[i]);
        extraOperandsButtons[i]->setStyleSheet("QPushButton{font: bold 22px; background-color: #E99922}");
    }

    pos = 0;
    for (int i = 2; i < 6; i++) {
        for (int j = 3; j < 6; j++) {
            extraOperandsButtons[pos]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            gridlayout->addWidget(extraOperandsButtons[pos], i, j);
            pos++;
        }
    }
    ui->centralwidget->setLayout(gridlayout);
    gridlayout->addWidget(display, 0, 0, 1, 6);
    gridlayout->addWidget(zero, 5, 0);
    gridlayout->addWidget(comma, 5, 1);
    gridlayout->addWidget(result, 5, 2);
    gridlayout->addWidget(backspase, 1, 3);
    gridlayout->addWidget(C, 1, 4, 1, 2);
    gridlayout->addWidget(leftBracket, 1, 1);
    gridlayout->addWidget(rightBracket, 1, 2);
    gridlayout->addWidget(percent, 1, 0);
}

MainWindow::~MainWindow()
{
    delete ui;
}
