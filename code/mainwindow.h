#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtBluetooth/QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void sendMsg(int, int);

private slots:

    void on_finger4_valueChanged(int value);

    void on_finger3_valueChanged(int value);

    void on_finger2_valueChanged(int value);

    void on_finger1_valueChanged(int value);

    void on_finger0_valueChanged(int value);

    void deviceDiscovered(const QBluetoothDeviceInfo &device);

    void on_pushButton_2_clicked();

    void on_comboBox_activated(const QString &arg1);

    void socketErrorOutput();

    void on_pushButton_5_clicked();

    void socketSuccessOutput();

    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_pressed();

private:
    Ui::MainWindow *ui;
    QBluetoothDeviceDiscoveryAgent *agent;
    QBluetoothSocket *socket;
    QString string;
    void readMsg();
};

#endif // MAINWINDOW_H
