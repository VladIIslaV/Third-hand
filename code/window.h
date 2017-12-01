#ifndef WINDOW_H
#define WINDOW_H

#include <QObject>
#include <QtWidgets>
#include <iostream>
#include <fstream>
#include <QtSerialPort/QSerialPort>
#include <QtConcurrent/QtConcurrent>

using namespace std;

class Window: public QWidget
{
    Q_OBJECT

    void sendMsg(short, short);
    void initSerialPort();
    void initFingersScrolls();
public:
    explicit Window(QWidget *parent = 0);

public slots:
    void moveHand0();
    void moveHand1();
    void moveHand2();
    void moveHand3();
    void moveHand4();
    void getMsg();
private:
    QScrollBar *hand[5];
    QSerialPort *com;
    QLabel *label;
    QPalette *pwin;
    ofstream file;

    bool shn_send_msg;  //flag has TRUE value when you should not send message to device
};

#endif // WINDOW_H
