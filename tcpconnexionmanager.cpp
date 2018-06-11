#include "tcpconnexionmanager.h"

TCPConnexionManager::TCPConnexionManager(){
    sendingByteArray = new QByteArray();
    tcpSocket = new QTcpSocket();
    sendingTimer = new QTimer();
    sendingTimer->setInterval(1500);
}

void TCPConnexionManager::send(int LSpeed, int RSpeed){
   quint32 Lvalue=qMin(qAbs(LSpeed),1000);
   quint32 Rvalue=qMin(qAbs(RSpeed),1000);
   qDebug() << Lvalue << " ; " << Rvalue;

   sendingByteArray->clear();
   sendingByteArray->append((char)0xff);
   qDebug() << "Bytes : " << sendingByteArray;
   sendingByteArray->append((char)0x07);
   sendingByteArray->append((char)(Lvalue*240/1000));
   sendingByteArray->append((char)0x00);
   sendingByteArray->append((char)(Rvalue*240/1000));
   sendingByteArray->append((char)0x00);
   sendingByteArray->append(((char)pidMode&0b10101000)|(LSpeed<0?0b00000000:0b01000000)|(RSpeed<0?0b00000000:0b00010000));

   quint16 crcValue = ConnexionManager::crc16(sendingByteArray,1);
   qDebug() << crcValue;

   sendingByteArray->append((char)(crcValue));
   sendingByteArray->append((char)(crcValue>>8));

   qDebug() << sendingByteArray;

   tcpSocket->write(*sendingByteArray);
   receive();
}

void TCPConnexionManager::receive(){

}

void TCPConnexionManager::connect(QString botHost, QString port){
    tcpSocket->connectToHost(botHost,port.toUInt());
    if(tcpSocket->waitForConnected(20)){
        sendingTimer->start();
        qDebug() << "Connection done";
    }else{
        qDebug() << "Connection failed";
    }
}

void TCPConnexionManager::disconnect(){

}

