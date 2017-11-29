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
    void moveFinger0();
    void moveFinger1();
    void moveFinger2();
    void moveFinger3();
    void moveFinger4();
    void getMsg();
private:

    QScrollBar
        *finger0,
        *finger1,
        *finger2,
        *finger3,
        *finger4;
    QSerialPort *com;
    QLabel *label;
    QPalette *pwin;
    ofstream file;

};

#endif // WINDOW_H
