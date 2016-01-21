/*
 *   C++ sockets on Unix and Windows
 *   Copyright (C) 2002
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "PracticalSocket.h"  // For Socket, ServerSocket, and SocketException
#include <iostream>           // For cerr and cout
#include <cstdlib>            // For atoi()
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <sstream>
//#include "tinyxml.h"
#include "TCPConnection.h"


using namespace std;

 const unsigned int RCVBUFSIZE = 32;   // Size of receive buffer
//unsigned int RCVBUFSIZE=10000000;
void HandleTCPClient(TCPSocket *sock); // TCP client handling function
string getMessage(TCPSocket *sock);
string getAuthenticationMessage(TCPSocket *sock);
void extractAtributesFromXML(string packet);

/*int main(int argc, char *argv[]) {


	//delete obj;
	//cout<<obj["hello"]<<endl;
	TCPConnection *con=new TCPConnection();
  try {
         // Server Socket object
	  TCPServerSocket servSock(12121);
    for (;;) {   // Run forever



      //cout<<"CEM: "<< con->getMessageInSmallChunks(servSock.accept())<<endl;
    //	cout<<"CEM: "<<con->getMessageFirstSizeInInt(servSock.accept())<<endl;
    // cout<<"CEM: "<<con->getMessageFirstSizeInChar(servSock.accept())<<endl;
     // cout<<"Message "<< getAuthenticationMessage(servSock.accept())<<endl;
      //extractAtributesFromXML(getMessage(servSock.accept()));


    }
  } catch (SocketException &e) {
    cerr << e.what() << endl;
    exit(1);
  }
  // NOT REACHED

  return 0;
}*/

/*void extractAtributesFromXML(string packet){

	string s=packet;
	size_t pos=s.find("</flow>");
	//string xml =s.substr(0,(pos+7));
	std::string str=s.substr(0,(pos+7));
	//convert from string to char because xml parser waits for char *
	std::vector<char> writable(str.size() + 1);
	std::copy(str.begin(), str.end(), writable.begin());
//	cout<<"XML "<<&writable[0]<<endl;

	TiXmlDocument doc;
	doc.Parse( &writable[0] );

	if ( doc.Error() )
	{
		printf( "Error in %s: %s\n", doc.Value(), doc.ErrorDesc() );
		exit( 1 );
	}
	TiXmlHandle docHandle(&doc);
	//TiXmlElement* child2 = docHandle.FirstChild( "flow" ).FirstChild( "meta" ).FirstChild( "layer3" ).FirstChild( "src").ToElement();

	//TiXmlHandle textHandle = docHandle.FirstChildElement( "flow" ).FirstChild( "meta" ).FirstChild( "layer3" ).ChildElement( "src", 0 );
	TiXmlText *IP=docHandle.FirstChildElement( "flow" ).FirstChild( "meta" ).FirstChild( "layer3" ).FirstChild("src").FirstChild().Text();
	//TiXmlText *IP=docHandle.FirstChildElement( "flow" ).Child(1).FirstChild( "layer3" ).FirstChild("dst").FirstChild().Text();
	TiXmlText *byteTX=docHandle.FirstChildElement( "flow" ).Child(0).Child(2).Child(1).FirstChild().Text();
	TiXmlText *byteRX=docHandle.FirstChildElement( "flow" ).Child(1).Child(2).Child(1).FirstChild().Text();

	cout<<"IP: "<<IP->Value()<<endl;
	cout<<"TX: "<< byteTX->Value()<<endl;
	cout<<"RX: "<< byteRX->Value()<<endl;
	//doc.SaveFile();
}*/
//const unsigned RECVBUF=10;
//string getMessage(TCPSocket *sock){
//	   char val[RECVBUF];
//		sock->recv(val, sizeof(val));
//		cout<<"HALLO val "<<&val[0]<<endl;
//		int a=atoi(&val[0]);
//		val[RECVBUF]='\0';
//		char echoBuffer2[a];
//		sock->recv(echoBuffer2, a);
//		echoBuffer2[a] = '\0'; //TODO: you should add '\0' end of the line so as to prevent the additional data.
//		cout<<":echo "<<echoBuffer2<<endl;
//		delete sock;
//	  int val[0];
//	  //get first Part
//	  sock->recv(val, sizeof(val[0]));
//	  //char a=val[0];
//	  cout<<"HALLO val "<<val[0]<<endl;
//	//  val[1]='\0';
//	  //get message
//	  //val[0]=20;
//
//	  char echoBuffer2[val[0]];
//	  sock->recv(echoBuffer2, val[0]);
//
//	   cout<<":echo 2 "<<echoBuffer2<<endl;
//	  //send echo
//	  sock->send(echoBuffer2, val[0]);
//	  echoBuffer2[val[0]]='\0';//TODO: you should add '\0' end of the line so as to prevent the addtional data.
//	  cout<<":echo 2 "<<echoBuffer2<<endl;
//	  cout << "userID: "<<sock->getForeignAddress()<< endl;
//	  delete sock;

//	  istringstream jsonString(echoBuffer2);
//	  //Array arrayDocument;
//	  Object jsonObj;
//	  Reader::Read(jsonObj, jsonString);
//	  String& userName1 = jsonObj["userId"];
//	  cout << "userID: "<<userName1.Value() << endl;
//	  return "";
//
//}

//Message size should be defined before sending.
string getAuthenticationMessage(TCPSocket *sock){

	int val[1];
		  //get first Part
	sock->recv(val, RCVBUFSIZE);
    cout<<"val "<<val[0]<<endl;

	char echoBuffer[RCVBUFSIZE];
	int recvMsgSize;
	sock->recv(echoBuffer,RCVBUFSIZE);
	delete sock;
	return echoBuffer;
}
// TCP client handling function
void HandleTCPClient(TCPSocket *sock) {
  cout << "Handling client ";
  try {
    cout << sock->getForeignAddress() << ":";
  } catch (SocketException e) {
    cerr << "Unable to get foreign address" << endl;
  }
  try {
    cout << sock->getForeignPort();
  } catch (SocketException e) {
    cerr << "Unable to get foreign port" << endl;
  }
  cout << endl;

  // Send received string and receive again until the end of transmission


  std::string str;
  char echoBuffer[RCVBUFSIZE];
   int recvMsgSize;
   while ((recvMsgSize = sock->recv(echoBuffer, RCVBUFSIZE)) > 0) { // Zero means
                                                         // end of transmission

    // Echo message back to client
	  //cout<<":received Message Size "<<recvMsgSize<<endl;
	   echoBuffer[RCVBUFSIZE]='\0';
	  cout<<":echo "<<echoBuffer<<endl;
	  str.append(echoBuffer);
	 // strcat (all,echoBuffer);

	//  RCVBUFSIZE=recvMsgSize;
	  sock->send(echoBuffer, recvMsgSize);
  }
   cout<<":all "<<str<<endl;
  delete sock;
}
