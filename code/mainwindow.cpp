#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtBluetooth/qbluetooth.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    agent = new QBluetoothDeviceDiscoveryAgent;
    ui->setupUi(this);

    connect(agent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)), this, SLOT(deviceDiscovered(QBluetoothDeviceInfo)));
    agent->start();
    socket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol);
    connect(socket, SIGNAL(error(QBluetoothSocket::SocketError)), this, SLOT(socketErrorOutput(QBluetoothSocket::SocketError)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sendMsg(int fn, int value)
{
    char* message = new char[5];
    message[0] = 's';
    message[1] = 0x30 + fn;
    message[2] = 0x30 + value;
    message[3] = 'f';
    message[4] = '\0';
    socket->write(message, 5);
}

void MainWindow::on_finger4_valueChanged(int value)
{
    sendMsg(4, value);
}

void MainWindow::on_finger3_valueChanged(int value)
{
    sendMsg(3, value);
}

void MainWindow::on_finger2_valueChanged(int value)
{
    sendMsg(2, value);
}

void MainWindow::on_finger1_valueChanged(int value)
{
    sendMsg(1, value);
}

void MainWindow::on_finger0_valueChanged(int value)
{
    sendMsg(0, value);
}

void MainWindow::deviceDiscovered(const QBluetoothDeviceInfo &device)
{
    ui->comboBox->addItem(device.address().toString());
}


void MainWindow::on_pushButton_2_clicked()
{
    static const QString serviceUuid(QStringLiteral("00001101-0000-1000-8000-00805F9B34FB"));
    socket->connectToService(QBluetoothAddress(string), QBluetoothUuid(serviceUuid));
    ui->lineEdit->setText(QString("Connecting to ") + string);
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    string = arg1;
}

void MainWindow::socketErrorOutput()
{
    ui->lineEdit->setText("Error. Try to connect again");
}

void MainWindow::readMsg()
{
    ui->lineEdit->setText(QString(socket->read(10)));
}

void MainWindow::on_pushButton_5_clicked()
{
    emit close();
}

void MainWindow::socketSuccessOutput()
{
    ui->lineEdit->setText("Successful connection");
}

void MainWindow::on_pushButton_clicked()    //showKnuckle
{
    ui->finger0->setValue(19);
    ui->finger1->setValue(19);
    ui->finger2->setValue(19);
    ui->finger3->setValue(19);
    ui->finger4->setValue(19);
}

void MainWindow::on_pushButton_6_clicked()  //showHand
{
    ui->finger0->setValue(0);
    ui->finger1->setValue(0);
    ui->finger2->setValue(0);
    ui->finger3->setValue(0);
    ui->finger4->setValue(0);
}

void MainWindow::on_pushButton_7_clicked()  //showRock
{
    ui->finger0->setValue(19);
    ui->finger1->setValue(0);
    ui->finger2->setValue(19);
    ui->finger3->setValue(19);
    ui->finger4->setValue(0);
}

void MainWindow::on_pushButton_6_pressed()  //showSurprise
{
    ui->finger0->setValue(0);
    ui->finger1->setValue(19);
    ui->finger2->setValue(0);
    ui->finger3->setValue(19);
    ui->finger4->setValue(19);
}
