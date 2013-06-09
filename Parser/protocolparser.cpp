#include "protocolparser.h"
#include "../Exceptions/badpackageexception.h"
#include <iostream>


ProtocolParser::ProtocolParser()
{
//    deserialization = new Deserializacja();
}

ProtocolParser::~ProtocolParser() {
//    delete deserialization;
}

int ProtocolParser::parseIn(QString data) {
    int index = 0;
    int packetType;
    try {
        packetType = this->readPacketType(index,data);
    } catch(BadPackageException* ex ) {
        ex->send();
        delete ex;
        return -1;
    }

    Pakiet packet;

    try {
        switch((PacketType)packetType) {
        case ADD_USER :
            packet = this->parseUserPacket(index,data);
            std::cout<<"Otrzymano pakiet ADD_USER\n";
            break;
        case CHECK_RESTAURANT :
            packet = this->parseCheckRestaurantPacket(index,data);
            std::cout<<"Otrzymano pakiet CHECK_RESTAURANT\n";
            break;
        case GET_RESTAURANT :
            packet = this->parseGetRestaurantPacket(index,data);
            std::cout<<"Otrzymano pakiet GET_RESTAURANT\n";
            break;
        case SEND_NEXT :
            packet = this->parseSendNextPacket();
            std::cout<<"Otrzymano pakiet SEND_NEXT\n";
            break;
        case GET_COMMENTS :
            packet = this->parseGetCommentsPacket(index,data);
            std::cout<<"Otrzymano pakiet GET_COMMENTS\n";
            break;
        case ADD_COMMENT :
            packet = this->parseAddCommentPacket(index,data);
            std::cout<<"Otrzymano pakiet ADD_COMMENT\n";
            break;
        case ADD_RESTAURANT :
            packet = this->parseAddRestaurantPacket(index,data);
            std::cout<<"Otrzymano pakiet ADD_RESTAURANT\n";
            break;
        case DELETE_COMMENT :
            packet = this->parseGetCommentsPacket(index,data);
            std::cout<<"Otrzymano pakiet DELETE_COMMENT\n";
            break;
        default :
            std::cout<<"Obecnie odebranie pakietu jest nie obslugiwane\n";
            return 1;
            break;
        }
    } catch(BadPackageException* ex) {
        ex->send();
        delete ex;
        return -1;
    }

//    deserialization->start(packet);

    return 0;

}

int ProtocolParser::readPacketType(int& index,QString data) {
    QString packetType = data;
    //this->deencryption(data);

    for(index = 0; data[index] != '\n'; ++index) {
        if(data[index] < '0' || data[index] > '9')
            throw new BadPackageException();
        packetType.append(data[index]);
    }
    ++index;


    int value = (PacketType)(packetType.toInt());
    if ( value < 0 || value > 17) throw new BadPackageException();

    return value;
}




AddUserPacket ProtocolParser::parseUserPacket(int index, QString data) {
    AddUserPacket temp;

    for(; data[index] != '\n'; ++index) {
        if( data[index] == ' ' )
            throw new BadPackageException();
        temp.login.append(data[index]);
    }
    ++index;
    for(; data[index] != '\n'; ++index) {
        if( data[index] == ' ' )
            throw new BadPackageException();
        temp.password.append(data[index]);
    }

    return temp;
}


CheckRestaurantPacket ProtocolParser::parseCheckRestaurantPacket(int index, QString data) {
    QString temp;
    CheckRestaurantPacket packet;
    for(; data[index] != '\n'; ++index) {
        if(data[index] < '0' || data[index] > '9')
            throw new BadPackageException();
        temp.append(data[index]);
    }

    packet.localLastRestaurantId = temp.toInt();

    return packet;
}


GetRestaurantPacket ProtocolParser::parseGetRestaurantPacket(int index, QString data) {
    QString temp;
    GetRestaurantPacket packet;
    for(; data[index] != '\n'; ++index) {
        if(data[index] < '0' || data[index] > '9')
            throw new BadPackageException();
        temp.append(data[index]);
    }

    packet.toUpdateRestaurantId = temp.toInt();

    return packet;
}

GetCommentsPacket ProtocolParser::parseGetCommentsPacket(int index, QString data ) {
    QString temp;
    GetCommentsPacket packet;
    for(; data[index] != '\n'; ++index) {
        if(data[index] < '0' || data[index] > '9')
            throw new BadPackageException();
        temp.append(data[index]);
    }

    packet.restaurantId = temp.toInt();
    ++index;

    for(; data[index] != '\n'; ++index) {
        packet.addedDate.append(data[index]);
    }

    return packet;
}


AddCommentPacket ProtocolParser::parseAddCommentPacket(int index, QString data ) {
    QString temp;
    AddCommentPacket packet;
    for(; data[index] != '\n'; ++index) {
        if(data[index] < '0' || data[index] > '9')
            throw new BadPackageException();
        temp.append(data[index]);
    }

    packet.userId = temp.toInt();
    temp.clear();
    ++index;

    for(; data[index] != '\n'; ++index) {
        if(data[index] < '0' || data[index] > '9')
            throw new BadPackageException();
        temp.append(data[index]);
    }

    packet.restaurantId = temp.toInt();
    ++index;

    for(; data[index] != '\n'; ++index) {
        packet.date.append(data[index]);
    }
    ++index;

    for(; data[index] != '\n'; ++index) {
        packet.text.append(data[index]);
    }

    return packet;
}


AddRestaurantPacket ProtocolParser::parseAddRestaurantPacket(int index, QString data ) {
    AddRestaurantPacket packet;

    for(; data[index] != '\n'; ++index) {
        packet.restaurantName.append(data[index]);
    }
    ++index;

    for(; data[index] != '\n'; ++index) {
        if( data[index] == ' ' )
            throw new BadPackageException();
        packet.restaurantAdress.append(data[index]);
    }
    ++index;

    for(; data[index] != '\n'; ++index) {
        if( data[index] == ' ' )
            throw new BadPackageException();
        packet.restaurantType.append(data[index]);
    }

    return packet;
}


DeleteCommentPacket ProtocolParser::parseDeleteCommentPacket(int index, QString data ) {
    QString temp;
    DeleteCommentPacket packet;
    for(; data[index] != '\n'; ++index) {
        if(data[index] < '0' || data[index] > '9')
            throw new BadPackageException();
        temp.append(data[index]);
    }

    packet.commentId = temp.toInt();

    return packet;
}

SendNextPacket ProtocolParser::parseSendNextPacket() {
    return SendNextPacket();
}


//////////////////////////////////////////////////////////////////Out///////////////////////////////////////////////////

int ProtocolParser::parseOut(Pakiet packet) {
    QString toSend;
    switch((PacketType)packet.id) {
        case RESPONSE_ADD_USER:
            toSend = this->parsePacketOut(static_cast<ResponseAddUserPacket&>(packet));
            break;
        case RESPONSE_RESTAURANT:
            toSend = this->parsePacketOut(static_cast<ResponseCheckRestaurantPacket&>(packet));
            break;
        case RESPONSE_GET_RESTAURANT :
            toSend = this->parsePacketOut(static_cast<ResponseGetRestaurantPacket&>(packet));
            break;
        case RESPONSE_GET_COMMENTS :
            toSend = this->parsePacketOut(static_cast<ResponseGetCommentsPacket&>(packet));
            break;
        case RESPONSE_ADD_COMMENT :
            toSend = this->parsePacketOut(static_cast<ResponseAddCommentPacket&>(packet));
            break;
        case RESPONSE_ADD_RESTAURANT :
            toSend = this->parsePacketOut(static_cast<ResponseAddRestaurantPacket&>(packet));
            break;
        case RESPONSE_DELETE_COMMENT :
            toSend = this->parsePacketOut(static_cast<ResponseDeleteCommentPacket&>(packet));
            break;
        case END_OF_DATA :
            toSend = this->parsePacketEndOfData();
            break;
        default :
            std::cout<<"Obecnie wyslanie pakietu jest nie obslugiwane\n";
            break;
    }



    return 0;

}

QString intToStr(int n)
{
     QString tmp, ret;
     if(n < 0) {
          ret = "-";
          n = -n;
     }
     do {
          tmp += n % 10 + 48;
          n -= n % 10;
     }
     while(n /= 10);
     for(int i = tmp.size()-1; i >= 0; i--)
          ret += tmp[i];
     return ret;
}

QString ProtocolParser::parsePacketOut(ResponseAddCommentPacket packet) {
    QString response,temp;
    temp += "13";
    temp += '\n';

    temp += intToStr(packet.commentId);
    temp += '\n';

    response.append(temp.size());
    response += '\n';
    response += temp;
    //this->encryption(response);

    return response;
}

QString ProtocolParser::parsePacketOut(ResponseAddRestaurantPacket packet) {
    QString response,temp;
    temp += "15";
    temp += '\n';

    temp += intToStr(packet.restaurantId);
    temp += '\n';

    response.append(temp.size());
    response += '\n';
    response += temp;
    //this->encryption(response);
    return response;
}

QString ProtocolParser::parsePacketOut(ResponseAddUserPacket packet) {
    QString response,temp;
    response += "3";
    response += '\n';

    response += intToStr(packet.userId);
    response += '\n';

    response.append(temp.size());
    response += '\n';
    response += temp;
    //this->encryption(response);
    return response;
}

QString ProtocolParser::parsePacketOut(ResponseCheckRestaurantPacket packet) {
    QString response,temp;
    response += "5";
    response += '\n';

    response += intToStr(packet.globalLastRestaurantId);
    response += '\n';

    response.append(temp.size());
    response += '\n';
    response += temp;
    //this->encryption(response);
    return response;
}

QString ProtocolParser::parsePacketOut(ResponseGetCommentsPacket packet) {
    QString response,temp;
    response += "11";
    response += '\n';

    response += packet.userLogin;
    response += '\n';

    response += packet.text;
    response += '\n';

    response += packet.date;
    response += '\n';

    response.append(temp.size());
    response += '\n';
    response += temp;
    //this->encryption(response);
    return response;
}

QString ProtocolParser::parsePacketOut(ResponseGetRestaurantPacket packet) {
    QString response,temp;
    response += "7";
    response += '\n';

    response += intToStr(packet.restaurantId);
    response += '\n';

    response += packet.restaurantName;
    response += '\n';

    response += packet.restaurantAdress;
    response += '\n';

    response += packet.restaurantType;
    response += '\n';

    std::cout<<"Wyslano RESPONSEGETRESTAURANT"<<std::endl;

    response.append(temp.size());
    response += '\n';
    response += temp;
    //this->encryption(response);
    return response;
}

QString ProtocolParser::parsePacketOut(PingPacket packet) {
    QString response,temp;
    response += "0";
    response += '\n';

    response += intToStr(packet.userId);
    response += '\n';

    response.append(temp.size());
    response += '\n';
    response += temp;
    //this->encryption(response);
    return response;
}

QString ProtocolParser::parsePacketOut(ResponseDeleteCommentPacket packet) {
    QString response,temp;
    response += "8";
    response += '\n';
    (packet.ifDeleted == true ? response += "1" : response +="0" );
    response += '\n';

    response.append(temp.size());
    response += '\n';
    response += temp;
    //this->encryption(response);
    return response;
}

QString ProtocolParser::parsePacketEndOfData() {
    QString response,temp;
    response +="9";
    response += '\n';
    response +="sth";
    response += '\n';

    std::cout<<"Wyslano END_OF_DATA";
    response.append(temp.size());
    response += '\n';
    response += temp;
    //this->encryption(response);
    return response;
}

QString ProtocolParser::parsePingPacket() {
    QString response,temp;
    response += "1";
    response += '\n';

    return response;
}

void ProtocolParser::deencryption(char* data) {
    int key = 5;

    for(int i=0; i< strlen(data); ++i){
        data[i] = data[i] - key;
    }

}

void ProtocolParser::encryption(QString& data) {
    char* text = (char*) data.toStdString().c_str();
    int key = 5;

    for(int i=0; i< strlen(text); ++i){
        text[i] = text[i] + key;
    }

    data = QString(text);

}

