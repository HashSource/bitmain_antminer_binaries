
int http_tcpclient_send(int socket,char *buff,int size)

{
  ssize_t sVar1;
  int size_local;
  char *buff_local;
  int socket_local;
  int tmpres;
  int sent;
  
  sent = 0;
  while( true ) {
    if (size <= sent) {
      return sent;
    }
    sVar1 = send(socket,buff + sent,size - sent,0);
    if (sVar1 == -1) break;
    sent = sVar1 + sent;
  }
  return -1;
}

