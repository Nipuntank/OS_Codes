
#include <stdio.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include<arpa/inet.h>
#include <unistd.h>

int main()
{
    int sockfd, n, clen;
    struct sockaddr_in servaddr, cli;
    char buff[80];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1)
    {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(43454);
    if ((bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
    {
        printf("socket bind failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully binded..\n");
    clen = sizeof(cli);
    while (1)
    {
        bzero(buff, 80);
        recvfrom(sockfd, buff, sizeof(buff), 0, (struct sockaddr *)&cli, &clen);
        printf("\nUDP Echo Back: %s ", buff);
        sendto(sockfd, buff, strlen(buff), 0, (struct sockaddr *)&cli, clen);
        if (strncmp("exit", buff, 4) == 0)
        {
            printf("Client Exit...\n");
            break;
        }
    }
    close(sockfd);
}

