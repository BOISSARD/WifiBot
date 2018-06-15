#include "tcpconnexionmanager.h"

TCPConnexionManager::TCPConnexionManager(){
    sendingByteArray = new QByteArray();
    tcpSocket = new QTcpSocket();
    sendingTimer = new QTimer();
    sendingTimer->setInterval(1500);
}

void TCPConnexionManager::send(QByteArray* sendingByteArray){
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
    qDebug() << "Déconnexion !";
    tcpSocket->disconnect();
}

