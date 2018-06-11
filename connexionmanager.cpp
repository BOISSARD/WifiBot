#include "connexionmanager.h"

ConnexionManager::ConnexionManager(){}

quint16 ConnexionManager::crc16(QByteArray* byteArray, int pos){
    quint16 crc = 0xFFFF;
    quint16 Polynome = 0xA001;
    quint16 Parity = 0;
    for(; pos < byteArray->length(); pos++){
        crc ^= (unsigned char)byteArray->at(pos);
        for (unsigned int CptBit = 0; CptBit <= 7 ; CptBit++){
            Parity= crc;
            crc >>= 1;
            if (Parity%2 == true) crc ^= Polynome;
        }
    }
    return crc;
}
