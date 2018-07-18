//server mono processus

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/time.h>


int main()
{
	//création socket et stucture
	char str[100];
	int listen_fd,accepted_fd;
	struct sockaddr_in servaddr;

	listen_fd = socket(AF_INET, SOCK_STREAM, 0);

	// ou mainset
	bzero(&servaddr,sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(8081);
	servaddr.sin_addr.s_addr=htons(INADDR_ANY)

	//bind structure et socket
	bind(listen_fd, (struct sockaddr*) &servaddr, sizeof(servaddr));

	//listen
	//socket deviens passive
	listen(listen_fd,10);

	//accept est une fonction bloquante
	//socket qui est la connexion entre le client et le serveur
	//possible de mettre une structur afin de logger l'adresse ip à la place du null
	accepted_fd = accept(listen_fd,(struct sockadrr*) NULL,NULL);

	while(1)
	{
		//pour pas avoir de résidu
		bzero(str,100);
		read(accepted_fd,str,100);

		printf("Echoing back - %s",str);
		write(accepted_fd,str,strlen(str)+1);
	}

	/*
	struct sockaddr_in
	int sock_desc = socket(AF_INET, SOCK_STREAM, 0), client_sock
	c = sizeof(struct sockaddr_in);

        c=sizeof(struct sockaddr_in);
       while(client_sock=accept(socket_desc,(struct sockaddr*)&client,(socklen_t*)&c))
       {
        printf("Connection accepter");

        pthread_t p_thread;
        new_sock = malloc(1);
        *new_sock = client_sock;

        if( pthread_create( &p_thread , NULL ,  connection_handler , (void*) new_sock) < 0)
        {
            perror("could not create thread");
            return 1;
        }

    }*/



	return 0;
}
