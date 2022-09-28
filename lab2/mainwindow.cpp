#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QApplication>
#include <QGridLayout>
#include <QTimer>
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
, ui(new Ui::MainWindow)
{
ui->setupUi(this);
main_box = new QGridLayout(this);
label = new QLabel(text, this);
label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
label->setStyleSheet("font-size: 16px");
label->setWordWrap(true);

main_box->addWidget(label);
ui->centralwidget->setLayout(main_box);

timer = new QTimer();
connect(timer, SIGNAL(timeout()), this, SLOT(slotTimerAlarm()));
timer->start(1);
}

void MainWindow::keyPressEvent(QKeyEvent *event){
label->setText(label->text() + event->text());
}

void MainWindow::slotTimerAlarm()
{
this->setWindowTitle(QTime::currentTime().toString("hh:mm:ss:ms"));
}

MainWindow::~MainWindow()
{
delete ui;
}
