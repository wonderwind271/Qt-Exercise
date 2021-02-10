#ifndef WIDGET2_H
#define WIDGET2_H

#include <QWidget>
#include <QPushButton>
#include <QString>

class widget2 : public QWidget
{
    Q_OBJECT
private:
    QPushButton* b1;
public:
    explicit widget2(QWidget *parent = nullptr);

signals:
    //define manual signal here, no need to implement
    //can overload or have para, but return type is void.
    //use syntax: emit [signal name] to send signals
    void SendSignal();
    void SendSignal(int, QString);

public slots:
    void SendSignalSlot();


};

#endif // WIDGET2_H
