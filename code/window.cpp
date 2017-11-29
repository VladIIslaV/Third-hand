#include "window.h"

void Window::sendMsg(short fn, short value)
{
    char* num_str = new char[4];
    num_str[0] = 's';
    num_str[1] = (char)fn;
    num_str[2] = (char)(value*0.2);
    num_str[3] = 'f';
    if(com->isWritable()){
        com->write(num_str, 4);
        cout << "Success " << (short)num_str[2] << endl;
    }


/*
    char* num_str = new char[5];
    num_str[0] = 's';
    num_str[1] = '4';
    num_str[4] = 'f';

    if(def == "stop"){
        num_str[2] = 0;
        num_str[3] = 0;
        while(true)
            if(parent->com->isWritable())
            {
                parent->com->write(num_str);
                cout << "### r "
                     << parent->prev_val
                     << " ###"
                     << endl;
                return;
            }
    }

    while(true)
    {
        if(parent->new_val == parent->prev_val - 1 ||
                parent->new_val == parent->prev_val + 1){
            num_str[2] = '0';
            continue;
        }else
            num_str[2] = 'z';

        if(parent->new_val > parent->prev_val)
        {
            num_str[1] = '0';
            if(parent->com->isWritable())
            {
                parent->com->write(num_str);
                cout << "### l "
                     << parent->prev_val
                     << " ###"
                     << endl;
            }
            parent->prev_val++;
        }else{
            num_str[1] = '1';
            if(parent->com->isWritable())
            {
                parent->com->write(num_str);
                cout << "### r "
                     << parent->prev_val
                     << " ###"
                     << endl;
            }
            parent->prev_val--;
        }
    }*/
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

    finger4 = new QScrollBar(this);
    finger4->setGeometry(100, 100, 20, 360);
    //finger4->setMinimum(0);
    //finger4->setMaximum(20);
    connect(finger4, SIGNAL(sliderReleased()), this, SLOT(moveFinger4()));

    finger3 = new QScrollBar(this);
    finger3->setGeometry(130, 80, 20, 380);
    connect(finger3, SIGNAL(valueChanged(int)), this, SLOT(moveFinger3()));

    finger2 = new QScrollBar(this);
    finger2->setGeometry(160, 60, 20, 400);
    connect(finger2, SIGNAL(valueChanged(int)), this, SLOT(moveFinger2()));

    finger1 = new QScrollBar(this);
    finger1->setGeometry(190, 70, 20, 390);
    connect(finger1, SIGNAL(valueChanged(int)), this, SLOT(moveFinger1()));

    finger0 = new QScrollBar(Qt::Horizontal, this);
    finger0->setGeometry(220, 450, 200, 20);
    connect(finger0, SIGNAL(valueChanged(int)), this, SLOT(moveFinger0()));
}



Window::Window(QWidget *parent): QWidget(parent)
{
    this->setFixedSize(600,600);
    pwin = new QPalette(QColor(200, 80, 60, 100));
//    pwin->setColor(QPalette::ColorRole::Foreground, QColor(100, 100, 100, 0));
    this->setPalette(*pwin);
    initFingersScrolls();
    initSerialPort();

    file.open("Stat.txt");

}

void Window::moveFinger0()
{
    sendMsg(0, finger0->value());
}

void Window::moveFinger1()
{
    sendMsg(1, finger1->value());
}

void Window::moveFinger2()
{
    sendMsg(2, finger2->value());
}

void Window::moveFinger3()
{
    sendMsg(3, finger3->value());
}

void Window::moveFinger4()
{
    sendMsg(4, finger4->value());
}

void Window::getMsg()
{
    /*int tmp = 0, tmp1 = 0;
    cout << com->readAll().toStdString().c_str() << '\n';
    tmp1 = tmp = atoi(com->readAll().toStdString().c_str());
    while(tmp--){
        file << ' ';
    }
    file << tmp1 << endl;*/
}
