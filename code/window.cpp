#include "window.h"

void Window::sendMsg(short fn, short value)
{
    if(shn_send_msg){
        shn_send_msg = false;
        return;
    }

    //max scroll value / max finger bend value
    float mtm = 0.2;
    char* num_str = new char[4];
    num_str[0] = 's';
    num_str[1] = (char)fn;
    num_str[2] = (char)(value*mtm);
    num_str[3] = 'f';
    if(com->isWritable()){
        com->write(num_str, 4);
        cout << "Success " << (short)num_str[2] << endl;
    }
}

void Window::initSerialPort()
{
    com = new QSerialPort("COM3", this);
    com->setBaudRate(QSerialPort::Baud115200);
    com->setParity(QSerialPort::NoParity);
    com->setDataBits(QSerialPort::Data8);
    com->setStopBits(QSerialPort::OneStop);
    com->setFlowControl(QSerialPort::NoFlowControl);
    if(!com->open(QIODevice::ReadWrite))
    {
        cout << "---\tError: com port\t---" << endl;
        com->error();
        label->setText(com->errorString());
    }
    connect(com, SIGNAL(readyRead()), this, SLOT(getMsg()));
}

void Window::initFingersScrolls()
{
    hand[0] = new QScrollBar(Qt::Horizontal, this);
    hand[0]->setGeometry(20, 450, 170, 20);
    connect(hand[0], SIGNAL(valueChanged(int)), this, SLOT(moveHand0()));

    hand[1] = new QScrollBar(this);
    hand[1]->setGeometry(210, 100, 20, 360);
    connect(hand[1], SIGNAL(valueChanged(int)), this, SLOT(moveHand1()));

    hand[2] = new QScrollBar(this);
    hand[2]->setGeometry(240, 80, 20, 380);
    connect(hand[2], SIGNAL(valueChanged(int)), this, SLOT(moveHand2()));

    hand[3] = new QScrollBar(this);
    hand[3]->setGeometry(270, 60, 20, 400);
    connect(hand[3], SIGNAL(valueChanged(int)), this, SLOT(moveHand3()));

    hand[4] = new QScrollBar(this);
    hand[4]->setGeometry(300, 70, 20, 390);
    connect(hand[4], SIGNAL(valueChanged(int)), this, SLOT(moveHand4()));
}



Window::Window(QWidget *parent): QWidget(parent)
{
    this->setFixedSize(600,600);
    pwin = new QPalette(QColor(200, 80, 60, 100));
    pwin->setColor(QPalette::ColorRole::Foreground, QColor(100, 100, 100, 0));
    this->setPalette(*pwin);
    initFingersScrolls();
    initSerialPort();

    file.open("Stat.txt");

    shn_send_msg = false;
}

void Window::moveHand0()
{
    sendMsg(0, hand[0]->value());
}

void Window::moveHand1()
{
    sendMsg(1, hand[1]->value());
}

void Window::moveHand2()
{
    sendMsg(2, hand[2]->value());
}

void Window::moveHand3()
{
    sendMsg(3, hand[3]->value());
}

void Window::moveHand4()
{
    sendMsg(4, hand[4]->value());
}

void Window::getMsg()
{
    const char* msg = new char[10];
    msg = com->readAll().toStdString().c_str();
    if(msg[0] == 'r' && msg[3] == 'f')    //we have msg from device
    {
        shn_send_msg = true;
        hand[(int)msg[1]]->setValue((int)msg[2]*5);
        cout << "hand[" << (int)msg[1] << "]->setValue(" << (int)msg[2] << ")\n";
    }
}
