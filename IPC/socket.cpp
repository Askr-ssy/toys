#include<sys/socket.h>
#include<netinet/in.h>
#include<cstring>
#include<unistd.h>
#include<string>
#include<iostream>
int get_line(int sock,char *buf,int size){
    int i = 0;
    char c = '\0';
    int n;

    while ((i < size - 1) && (c != '\n'))
    {
        n = recv(sock, &c, 1, 0);
        /* DEBUG printf("%02X\n", c); */
        if (n > 0)
        {
            if (c == '\r')
            {
                n = recv(sock, &c, 1, MSG_PEEK);
                /* DEBUG printf("%02X\n", c); */
                if ((n > 0) && (c == '\n'))
                    recv(sock, &c, 1, 0);
                else
                    c = '\n';
            }
            buf[i] = c;
            i++;
        }
        else
            c = '\n';
    }
    buf[i] = '\0';
    std::cout<<buf<<std::endl;
    return (i);
}


int main(void){
    // server sock
    int server_sock = -1;
    u_short port = 4000;
    int client_sock = -1;
    struct sockaddr_in client_name;
    struct sockaddr_in server_name;
    socklen_t client_name_len = sizeof(client_name);
    char buf[1024];
    char response[1024] = "pong";
    int numchars = 0;

    server_sock = socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);
    if (server_sock==-1){
        std::cout<<"socket create error"<<std::endl;
        exit(1);
    }
    memset(&server_name,0,sizeof(server_name));
    server_name.sin_family = AF_INET;
    server_name.sin_port = htons(port);
    server_name.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_sock,(struct sockaddr *)&server_name,sizeof(server_name))<0){
        std::cout<<"bind port error"<<std::endl;
        exit(1);
    }
    if (listen(server_sock,5)<0){
        std::cout<<"listen error"<<std::endl;
        exit(1);
    }
    std::cout<<"httpd running on port "<<port<<std::endl;
    while(1){
        client_sock = accept(server_sock,(struct sockaddr *)&client_name,&client_name_len);
        if (client_sock==-1)
            std::cout<<"accept error"<<std::endl;
        numchars = get_line(client_sock,buf,sizeof(buf));
        while ((numchars>0)&&strcmp("\n",buf))
            numchars = get_line(client_sock,buf,sizeof(buf));
        std::cout<<buf<<std::endl;
        send(client_sock,response,strlen(response),0);
        // std::cout<<"socket info done"<<std::endl;
    }

    close(server_sock);
    return 0;
}