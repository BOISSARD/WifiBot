#ifndef CONNEXIONMANAGER_H
#define CONNEXIONMANAGER_H

#include <QByteArray>

class ConnexionManager
{
    public:
        ConnexionManager();
        //ConnexionManager(int ip, int port);
        virtual void send(int LSpeed, int RSpeed) = 0;
        virtual void receive() = 0;
        virtual bool connect(QString botHost, QString port) = 0;
        virtual void disconnect() = 0;

   protected:
        static quint16 crc16(QByteArray *byteArray, int pos);
        enum PIDSettings {PID_off_50ms=0b00000000,PID_off_10ms=0b00001000,PID_on_50ms=0b10100000,PID_on_10ms=0b10101000};
};

#endif // CONNEXIONMANAGER_H
