#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define BUF_SIZE 100	//Chat buffer size
#define MAX_CLNT 256	//Constant to be used as the maximum number of clients

void * handle_clnt(void * arg);	//Used as the main function of the thread
void send_msg(char * user, char * msg, int len);	//Function used to send a message
void error_handling(char * msg);

int clnt_cnt = 0;	//Record client count
int clnt_socks[MAX_CLNT];	//Array to manage and store client sockets
pthread_mutex_t mutx;	//Declare variable to refer to mutex

char person[MAX_CLNT][20];

int main(int argc, char *argv[]) {

	int serv_sock, clnt_sock;	//Server and client sockets
	struct sockaddr_in serv_adr, clnt_adr;	//Address information structure
	int clnt_adr_sz;
	pthread_t t_id;	//Variable to hold the thread id
	if (argc != 2) {
		printf("Usage: %s <port>\n", argv[0]);
		exit(1);
	}

	pthread_mutex_init(&mutx, NULL);	//Mutex creation
	serv_sock = socket(PF_INET, SOCK_STREAM, 0);	//Socket creation

	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family = AF_INET;
	serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_adr.sin_port = htons(atoi(argv[1]));

	if (bind(serv_sock, (struct sockaddr*) &serv_adr, sizeof(serv_adr)) == -1)
		error_handling("bind() error");
	if (listen(serv_sock, 5) == -1)
		error_handling("listen() error");

	while (1) {
		clnt_adr_sz = sizeof(clnt_adr);
		clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_adr, &clnt_adr_sz);

		pthread_mutex_lock(&mutx);	//Critical Zone Start
		clnt_socks[clnt_cnt] = clnt_sock;	//Newly registered client socket management
		read(clnt_sock, person[clnt_cnt++], 20);
		pthread_mutex_unlock(&mutx);	//End of critical area

		pthread_create(&t_id, NULL, handle_clnt, (void*)&clnt_sock);	//Thread creation
		pthread_detach(t_id);
		printf("User @%s has entered the chat \n", person[clnt_cnt - 1]);
	}
	close(serv_sock);
	return 0;
}

void * handle_clnt(void * arg) {	//Serves as the main function of the thread
	int clnt_sock = *((int*)arg);
	int str_len = 0, i;
	char msg[BUF_SIZE];
	char user[20];

	read(clnt_sock, user, sizeof(user));

	while ((str_len = read(clnt_sock, msg, sizeof(msg))) != 0)
		send_msg(user, msg, str_len);

	pthread_mutex_lock(&mutx);	//Clean up file descriptors that are closed
	for (i = 0; i < clnt_cnt; i++) {	//remove disconnected client
		if (clnt_sock == clnt_socks[i]) {	//Rearrange the array. Filling empty client seats-In the meantime, protecting critical areas with mutex
			printf("User @%s has left the chat\n", person[i]);

			while (i < clnt_cnt - 1) {
				clnt_socks[i] = clnt_socks[i + 1];
				for (int j = 0; j < 20; j++) {
					person[i][j] = person[i + 1][j];
				}
				i++;
			}
			break;
		}
	}
	clnt_cnt--;
	pthread_mutex_unlock(&mutx);
	close(clnt_sock);
	return NULL;
}

void send_msg(char * user, char * msg, int len) {	//	Send message
	int i;
	pthread_mutex_lock(&mutx);

	if (!strcmp(user, "all")) {	//Send a message to the correct client at the destination
		for (i = 0; i < clnt_cnt; i++) {
			write(clnt_socks[i], msg, len);
		}
	}
	else {
		int a = 0;
		for (i = 0; i < clnt_cnt; i++) {
			if (!strcmp(user, person[i])) {
				write(clnt_socks[i], msg, len);
				a = 1;
			}
		}
		if (!a) {
			msg = "Target user not find!";
			len = sizeof(msg);
			write(clnt_socks[i], msg, len);
		}
	}

	pthread_mutex_unlock(&mutx);
}

void error_handling(char * msg) {
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}