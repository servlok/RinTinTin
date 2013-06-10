#include "protocolparser.h"
#include "../Exceptions/badpackageexception.h"
#include <QDebug>
#include <iostream>


ProtocolParser::ProtocolParser(TcpSocket *sock)
{
    this->tcpsocket = sock;
    deserialization = new Deserializacja(this);
}

ProtocolParser::~ProtocolParser() {
    delete deserialization;
}

int ProtocolParser::parseIn(std::string data) {
    int index = 0;
    PacketType packetType;
    try {
        packetType = this->readPacketType(index,data);
    } catch(BadPackageException* ex ) {
        ex->send();
        delete ex;
        return -1;
    }

    Pakiet* packet;
    std::cout<<"Idik otrzymanego pakietu "<<packetType<<"\n";
    try {
        switch(packetType) {
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

    deserialization->start(packet);

    return 0;

}

PacketType ProtocolParser::readPacketType(int& index,std::string data) {
    std::string packetType = data;
    //this->deencryption(data);

    for(index = 0; data[index] != '\n'; ++index) {
        if(data[index] < '0' || data[index] > '9')
            throw new BadPackageException();
        packetType += data[index];
    }
    ++index;


    int value = atoi(packetType.c_str());
    if ( value < 0 || value > 17) throw new BadPackageException();

    return (PacketType)value;
}




AddUserPacket* ProtocolParser::parseUserPacket(int index, std::string data) {
    AddUserPacket* temp = new AddUserPacket();

    for(; data[index] != '\n'; ++index) {
        if( data[index] == ' ' )
            throw new BadPackageException();
        temp->login += data[index];
    }
    ++index;
    for(; data[index] != '\n'; ++index) {
        if( data[index] == ' ' )
            throw new BadPackageException();
        temp->password += data[index];
    }

    return temp;
}


CheckRestaurantPacket* ProtocolParser::parseCheckRestaurantPacket(int index, std::string data) {
    std::string temp;
    CheckRestaurantPacket* packet = new CheckRestaurantPacket();
    for(; data[index] != '\n'; ++index) {
        if(data[index] < '0' || data[index] > '9')
            throw new BadPackageException();
        temp += data[index];
    }

    packet->localLastRestaurantId = atoi(temp.c_str());

    return packet;
}


GetRestaurantPacket* ProtocolParser::parseGetRestaurantPacket(int index, std::string data) {
    std::string temp;
    GetRestaurantPacket* packet = new GetRestaurantPacket();
    for(; data[index] != '\n'; ++index) {
        if(data[index] < '0' || data[index] > '9')
            throw new BadPackageException();
        temp += data[index];
    }

    packet->toUpdateRestaurantId = atoi(temp.c_str());

    return packet;
}

GetCommentsPacket* ProtocolParser::parseGetCommentsPacket(int index, std::string data ) {
    std::string temp;
    GetCommentsPacket* packet = new GetCommentsPacket();
    for(; data[index] != '\n'; ++index) {
        if(data[index] < '0' || data[index] > '9')
            throw new BadPackageException();
        temp += data[index];
    }

    packet->restaurantId = atoi(temp.c_str());
    ++index;

    for(; data[index] != '\n'; ++index) {
        packet->addedDate += data[index];
    }

    return packet;
}


AddCommentPacket* ProtocolParser::parseAddCommentPacket(int index, std::string data ) {
    std::string temp;
    AddCommentPacket* packet = new AddCommentPacket();
    for(; data[index] != '\n'; ++index) {
        if(data[index] < '0' || data[index] > '9')
            throw new BadPackageException();
        temp+=data[index];
    }

    packet->userId = atoi(temp.c_str());
    temp.clear();
    ++index;

    for(; data[index] != '\n'; ++index) {
        if(data[index] < '0' || data[index] > '9')
            throw new BadPackageException();
        temp+=data[index];
    }

    packet->restaurantId = atoi(temp.c_str());
    ++index;

    for(; data[index] != '\n'; ++index) {
        packet->date+=data[index];
    }
    ++index;

    for(; data[index] != '\n'; ++index) {
        packet->text+=data[index];
    }

    return packet;
}


AddRestaurantPacket* ProtocolParser::parseAddRestaurantPacket(int index, std::string data ) {
    AddRestaurantPacket* packet = new AddRestaurantPacket();

    for(; data[index] != '\n'; ++index) {
        packet->restaurantName+=data[index];
    }
    ++index;

    for(; data[index] != '\n'; ++index) {
        if( data[index] == ' ' )
            throw new BadPackageException();
        packet->restaurantAdress+=data[index];
    }
    ++index;

    for(; data[index] != '\n'; ++index) {
        if( data[index] == ' ' )
            throw new BadPackageException();
        packet->restaurantType+=data[index];
    }

    return packet;
}


DeleteCommentPacket* ProtocolParser::parseDeleteCommentPacket(int index, std::string data ) {
    std::string temp;
    DeleteCommentPacket* packet = new DeleteCommentPacket();
    for(; data[index] != '\n'; ++index) {
        if(data[index] < '0' || data[index] > '9')
            throw new BadPackageException();
        temp+=data[index];
    }

    packet->commentId = atoi(temp.c_str());

    return packet;
}

SendNextPacket* ProtocolParser::parseSendNextPacket() {
    return new SendNextPacket();
}


//////////////////////////////////////////////////////////////////Out///////////////////////////////////////////////////

std::string intToStr(int n)
{
     std::string tmp, ret;
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

void ProtocolParser::parsePacketOut(ResponseAddCommentPacket packet) {
    std::string response,temp;
    temp += "13";
    temp += '\n';

    temp += intToStr(packet.commentId);
    temp += '\n';

    response += intToStr(temp.size());
    response += '\n';
    response += temp;
    //this->encryption(response);

    tcpsocket->sendPackage(response);
}

void ProtocolParser::parsePacketOut(ResponseAddRestaurantPacket packet) {
    std::string response,temp;
    temp += "15";
    temp += '\n';

    temp += intToStr(packet.restaurantId);
    temp += '\n';

    response += intToStr(temp.size());
    response += '\n';
    response += temp;
    //this->encryption(response);

    tcpsocket->sendPackage(response);
}

void ProtocolParser::parsePacketOut(ResponseAddUserPacket packet) {
    std::string response,temp;
    temp += "3";
    temp += '\n';

    temp += intToStr(packet.userId);
    temp += '\n';

    response += intToStr(temp.size());
    response += '\n';
    response += temp;
    //this->encryption(response);
    std::cout<<"UserId: "<<packet.userId<<" Pakiet do wyslania1 "<<response;

    tcpsocket->sendPackage(response);
}

void ProtocolParser::parsePacketOut(ResponseCheckRestaurantPacket packet) {
    std::string response,temp;
    temp += "5";
    temp += '\n';

    temp += intToStr(packet.globalLastRestaurantId);
    temp += '\n';

    response+= intToStr(temp.size());
    response += '\n';
    response += temp;
    //this->encryption(response);
    tcpsocket->sendPackage(response);
}

void ProtocolParser::parsePacketOut(ResponseGetCommentsPacket packet) {
    std::string response,temp;

    temp += "11";
    temp += '\n';

    temp += packet.userLogin;
    temp += '\n';

    temp += packet.text;
    temp += '\n';

    temp += packet.date;
    temp += '\n';

    response+= intToStr(temp.size());
    response += '\n';
    response += temp;
    //this->encryption(response);
    tcpsocket->sendPackage(response);
}

void ProtocolParser::parsePacketOut(ResponseGetRestaurantPacket packet) {
    std::string response,temp;
    temp += "7";
    temp += '\n';

    temp += intToStr(packet.restaurantId);
    temp += '\n';

    temp += packet.restaurantName;
    temp += '\n';

    temp += packet.restaurantAdress;
    temp += '\n';

    temp += packet.restaurantType;
    temp += '\n';

    std::cout<<"Wyslano RESPONSEGETRESTAURANT"<<std::endl;

    response+=temp.size();
    response += '\n';
    response += temp;
    //this->encryption(response);
    tcpsocket->sendPackage(response);
}

void ProtocolParser::parsePacketOut(PingPacket packet) {
    std::string response,temp;
    temp += "0";
    temp += '\n';

    temp += intToStr(packet.userId);
    temp += '\n';

    response+= intToStr(temp.size());
    response += '\n';
    response += temp;
    //this->encryption(response);
    tcpsocket->sendPackage(response);
}

void ProtocolParser::parsePacketOut(ResponseDeleteCommentPacket packet) {
    std::string response,temp;
    temp += "8";
    temp += '\n';
    (packet.ifDeleted == true ? temp += "1" : temp +="0" );
    temp += '\n';

    response+= intToStr(temp.size());
    response += '\n';
    response += temp;
    //this->encryption(response);
    tcpsocket->sendPackage(response);
}

void ProtocolParser::parsePacketEndOfData() {
    std::string response,temp;
    temp +="9";
    temp += '\n';
    temp +="sth";
    temp += '\n';

    std::cout<<"Wyslano END_OF_DATA";
    response+= intToStr(temp.size());
    response += '\n';
    response += temp;
    //this->encryption(response);
    tcpsocket->sendPackage(response);
}

void ProtocolParser::parsePingPacket() {
    std::string response,temp;
    temp += "1";
    temp += '\n';

    tcpsocket->sendPackage(response);
}

void ProtocolParser::deencryption(char* data) {
    int key = 5;

    for(int i=0; i< strlen(data); ++i){
        data[i] = data[i] - key;
    }

}

void ProtocolParser::encryption(std::string& data) {
//    char* text =  data.c_str();
    char* text;
    int key = 5;

    for(int i=0; i< strlen(text); ++i){
        text[i] = text[i] + key;
    }

    data = std::string(text);

}

