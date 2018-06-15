#include "tcpconnexionmanager.h"

TCPConnexionManager::TCPConnexionManager(){
    sendingByteArray = new QByteArray();
    tcpSocket = new QTcpSocket();
    sendingTimer = new QTimer();
    sendingTimer->setInterval(1500);
}

void TCPConnexionManager::send(int LSpeed, int RSpeed){
   quint32 Lvalue=qMin(qAbs(LSpeed),CAMERAPORCENT);
   quint32 Rvalue=qMin(qAbs(RSpeed),CAMERAPORCENT);

   sendingByteArray->clear();
   sendingByteArray->append((char)0xff);
   sendingByteArray->append((char)0x07);
   sendingByteArray->append((char)(Lvalue*240/CAMERAPORCENT));
   sendingByteArray->append((char)0x00);
   sendingByteArray->append((char)(Rvalue*240/CAMERAPORCENT));
   sendingByteArray->append((char)0x00);
   sendingByteArray->append(((char)pidMode&0b10101000)|(LSpeed<0?0b00000000:0b01000000)|(RSpeed<0?0b00000000:0b00010000));

   quint16 crcValue = ConnexionManager::crc16(sendingByteArray,1);

   sendingByteArray->append((char)(crcValue));
   sendingByteArray->append((char)(crcValue>>8));

   tcpSocket->write(*sendingByteArray);
   receive();
}

void TCPConnexionManager::receive(){

}

bool TCPConnexionManager::connect(QString botHost, QString port){
    qDebug() << "Demande de connexion à "+botHost+":"+port+ " !";
    tcpSocket->connectToHost(botHost,port.toUInt());
    if(tcpSocket->waitForConnected(20)){
        sendingTimer->start();
        qDebug() << "Connection done";
        return true;
    }else{
        qDebug() << "Connection failed";
        return false;
    }
}

void TCPConnexionManager::disconnect(){

}

