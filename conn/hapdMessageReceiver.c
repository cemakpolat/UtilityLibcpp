/*
 * hapdMessageReceiver.c
 *
 *  Created on: Apr 23, 2013
 *      Author: cem
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#define SOCKET_PATH "/var/run/hostapd_socket"

#define BUFFLEN 4000


void runHostAPDMessageReceiver(){
	struct sockaddr_un strAddr;
	socklen_t lenAddr;
	int fdSock;
	int fdConn;
	char str[4000];
	/*Open a socket in UNIX domain*/
	if ((fdSock = socket(PF_UNIX, SOCK_STREAM, 0)) < 0) {
		perror("socket");
		//exit(1);
	}
	/*Unlink the path in order to prevent the creation of the conflict on the same file*/
	unlink(SOCKET_PATH);

	/* Unix Domain */
	strAddr.sun_family = AF_UNIX;

	/*Insert Path in parameters*/
	strcpy(strAddr.sun_path, SOCKET_PATH);
	lenAddr = sizeof(strAddr.sun_family) + strlen(strAddr.sun_path);

	/*Bind socket*/
	if (bind(fdSock, (struct sockaddr*) &strAddr, lenAddr) != 0) {
		perror("bind");
		//exit(1);
	}
	/*Start to listen to the clients*/
	if (listen(fdSock, 5) != 0) {
		perror("listen");
		//exit(1);
	}

	for (;;) {
		/*Accept client and build a connection between client and server, and continue to the listen*/
		if ((fdConn = accept(fdSock, (struct sockaddr*) &strAddr, &lenAddr))
				>= 0) {
			printf("\nConnection !!! receiving data ...\n");
			/*Receive data*/
			int n = recv(fdConn, str, sizeof(str), 0);
			if (n <= 0) {
				if (n < 0)
					perror("recv");
			}
			printf("%s", str);
			printf("\n... finished\n");
			/*Close established connection*/
			close(fdConn);
		}
	}
	/*Close the bound connection*/
	close(fdSock);

}

/*
 * Sample Usage
 */

//int main(){
//
//	runHostAPDMessageReceiver();
//	return 0;
//}
/*
int main(int argc, char *argv[]) {
	struct sockaddr_un strAddr;
	socklen_t lenAddr;
	int fdSock;
	int fdConn;

	if ((fdSock = socket(PF_UNIX, SOCK_STREAM, 0)) < 0){
		perror("socket");
		exit(1);
	}

	unlink(SOCKET_PATH);
	strAddr.sun_family = AF_UNIX;

	 Unix Domain
	strcpy(strAddr.sun_path, SOCKET_PATH);
	lenAddr = sizeof(strAddr.sun_family) + strlen(strAddr.sun_path);

	if (bind(fdSock, (struct sockaddr*) &strAddr, lenAddr) != 0){
		perror("bind");
		exit(1);
	}
	if (listen(fdSock, 5) != 0){
		perror("listen");
		exit(1);
	}
	char str[4000];

	for(;;){
	if ((fdConn = accept(fdSock, (struct sockaddr*) &strAddr, &lenAddr)) >= 0) {
		printf("\nConnection !!! receiving data ...\n");

		int n = recv(fdConn, str, sizeof(str), 0);
		if (n <= 0) {
			if (n < 0) perror("recv");
		}
		printf("%s",str);
		printf("\n... finished\n");
		close(fdConn);
	}}
	close(fdSock);
	return 0;
}*/
