#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int sock_desc;
    struct sockaddr_in serv_addr;
    char sbuff[100],rbuff[100];

    if((sock_desc = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        printf("Socket ko\n");

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(3000);

    if (connect(sock_desc, (struct sockaddr *) &serv_addr, sizeof (serv_addr)) < 0) {
        printf("Par reussit a se connecter au servuer\n");
    }

    printf("Connection ok\n");
    while(fgets(sbuff, 100 , stdin)!=NULL)
    {
      send(sock_desc,sbuff,strlen(sbuff),0);

          if(recv(sock_desc,rbuff,100,0)==0)
           printf("Erreur");
          else
           fputs(rbuff,stdout);

       bzero(rbuff,100);//to clean buffer
    }
        close(sock_desc);
    return 0;

}
