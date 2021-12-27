#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QUdpSocket>

class widget : public QWidget
{
    Q_OBJECT
public:
    explicit widget(QWidget *parent = nullptr);

signals:

private:
    void slottimeout();

    QPushButton * m_sendBtn;
    QByteArray stPayload;
    QUdpSocket udp;
};

#endif // WIDGET_H
