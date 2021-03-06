#ifndef CONNEXIONMANAGER_H
#define CONNEXIONMANAGER_H

#include <QByteArray>

class ConnexionManager
{    
    protected:
         static quint16 crc16(QByteArray *byteArray, int pos);
         enum PIDSettings {PID_off_50ms=0b00000000,PID_off_10ms=0b00001000,PID_on_50ms=0b10100000,PID_on_10ms=0b10101000};

    public:
        ConnexionManager();
        virtual void send(QByteArray* sendingByteArray) = 0;
        virtual void receive() = 0;
        virtual bool connect(QString botHost, QString port) = 0;
        virtual void disconnect() = 0;
        PIDSettings pidMode;
};

#endif // CONNEXIONMANAGER_H
