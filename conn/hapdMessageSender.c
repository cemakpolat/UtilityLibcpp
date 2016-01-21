/*
 * hapdMessageSender.c
 *
 *  Created on: Apr 23, 2013
 *      Author: cem
 */


#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
//#include "util.c"
#define SOCKET_PATH "/var/run/hostapd_socket"

#define BUFFLEN 4000

void sendMessage(char *MAC,char *Message){
	char *buf;
	asprintf(&buf,"MAC:%s,Message:%s",MAC, Message);
	printf("buf %s",buf);
	sendall(buf);
	free(buf);
}
void sendall(char *buf) {
	/*Define parameters*/
	char *str = buf;
	struct sockaddr_un strAddr;
	socklen_t lenAddr;
	int fdSock;

	if ((fdSock = socket(PF_UNIX, SOCK_STREAM, 0)) < 0) {
		perror("socket");
		exit(1);
	}

	strAddr.sun_family = AF_UNIX;/* Unix domain */
	strcpy(strAddr.sun_path, SOCKET_PATH);
	lenAddr = sizeof(strAddr.sun_family) + strlen(strAddr.sun_path);

	if (connect(fdSock, (struct sockaddr*) &strAddr, lenAddr) != 0) {
		perror("connect");
		exit(1);
	}
	printf("\nConnected to Server ... sending data ...\n");

	if (send(fdSock, str, strlen(str), 0) == -1) {
		perror("send");
		exit(1);
	}
	close(fdSock);
	//free(str);
}


/*
 * Sample Usage
 */
//int main(int argc, char *argv[]) {
//	while(1){
//		sleep(1);
//		char *message="Authentication Message, Dissaociation Message";
//		sendMessage(message);
//	}
