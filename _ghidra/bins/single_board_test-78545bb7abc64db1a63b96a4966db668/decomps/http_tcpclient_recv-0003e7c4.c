
int http_tcpclient_recv(int socket,char *lpbuff)

{
  ssize_t sVar1;
  int iVar2;
  char *lpbuff_local;
  int socket_local;
  char time_str [24];
  timeval timeout;
  fd_set rd;
  int tmp;
  int sel_ret;
  fd_set *__arr;
  uint __i;
  int recvnum;
  
  recvnum = 0;
  for (__i = 0; __i < 0x20; __i = __i + 1) {
    rd.__fds_bits[__i] = 0;
  }
  iVar2 = socket + 0x1f;
  if (-1 < socket) {
    iVar2 = socket;
  }
  rd.__fds_bits[iVar2 >> 5] = rd.__fds_bits[iVar2 >> 5] | 1 << (socket % 0x20 & 0xffU);
  timeout.tv_sec = 0x14;
  timeout.tv_usec = 0;
  iVar2 = select(socket + 1,(fd_set *)&rd,(fd_set *)0x0,(fd_set *)0x0,(timeval *)&timeout);
  if (0 < iVar2) {
    iVar2 = socket + 0x1f;
    if (-1 < socket) {
      iVar2 = socket;
    }
    if ((rd.__fds_bits[iVar2 >> 5] >> (socket % 0x20 & 0xffU) & 1U) != 0) {
      time_str[0] = '\0';
      time_str[1] = '\0';
      time_str[2] = '\0';
      time_str[3] = '\0';
      time_str[4] = '\0';
      time_str[5] = '\0';
      time_str[6] = '\0';
      time_str[7] = '\0';
      time_str[8] = '\0';
      time_str[9] = '\0';
      time_str[10] = '\0';
      time_str[0xb] = '\0';
      time_str[0xc] = '\0';
      time_str[0xd] = '\0';
      time_str[0xe] = '\0';
      time_str[0xf] = '\0';
      time_str[0x10] = '\0';
      time_str[0x11] = '\0';
      time_str[0x12] = '\0';
      time_str[0x13] = '\0';
      time_str[0x14] = '\0';
      time_str[0x15] = '\0';
      time_str[0x16] = '\0';
      time_str[0x17] = '\0';
      get_format_time(time_str);
      printf("prepare recv:%s\n",time_str);
      while (sVar1 = recv(socket,lpbuff + recvnum,0x1fff - recvnum,0), 0 < sVar1) {
        recvnum = sVar1 + recvnum;
      }
    }
  }
  return recvnum;
}

