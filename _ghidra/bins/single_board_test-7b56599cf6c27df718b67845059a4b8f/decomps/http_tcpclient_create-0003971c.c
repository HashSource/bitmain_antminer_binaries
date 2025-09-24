
int http_tcpclient_create(char *host,int port,_Bool ver_1_0)

{
  char *pcVar1;
  _Bool _Var2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  _Bool ver_1_0_local;
  int port_local;
  char *host_local;
  char time_stamp_3 [48];
  char time_stamp [48];
  char tmp1 [256];
  int err;
  socklen_t len;
  timeval tv_timeout;
  addrinfo hints;
  addrinfo *servinfo;
  char sockaddr_port [10];
  int n;
  int selret;
  fd_set *__arr;
  uint __i;
  int i_1;
  int i;
  int socket_id;
  int count;
  addrinfo *p;
  
  sockaddr_port[0] = '\0';
  sockaddr_port[1] = '\0';
  sockaddr_port[2] = '\0';
  sockaddr_port[3] = '\0';
  sockaddr_port[4] = '\0';
  sockaddr_port[5] = '\0';
  sockaddr_port[6] = '\0';
  sockaddr_port[7] = '\0';
  sockaddr_port[8] = '\0';
  sockaddr_port[9] = '\0';
  count = 0;
  socket_id = -1;
  sprintf(sockaddr_port,"%d",port);
  memset(&hints,0,0x20);
  hints.ai_family = 0;
  hints.ai_socktype = 1;
  printf("socket host:%s,port:%s\n",host,sockaddr_port);
  i = 0;
  while ((i < 5 && (iVar3 = getaddrinfo(host,sockaddr_port,(addrinfo *)&hints,(addrinfo **)&servinfo
                                       ), iVar3 != 0))) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Failed to getaddrinfo for %s:%s, sleep\n","http_tcpclient_create",host,
           sockaddr_port);
    snprintf(tmp1,0x100,"Failed to getaddrinfo for %s:%s, sleep",host,sockaddr_port);
    log_to_file(tmp1,time_stamp);
    __res_init();
    sleep(5);
    i = i + 1;
  }
  p = servinfo;
  do {
    if (p == (addrinfo *)0x0) {
LAB_00039c6e:
      if (p == (addrinfo *)0x0) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : Failed to connect to server on %s:%s\n\n","http_tcpclient_create",host,
               sockaddr_port);
        snprintf(tmp1,0x100,"Failed to connect to server on %s:%s\n",host,sockaddr_port);
        log_to_file(tmp1,time_stamp);
        freeaddrinfo((addrinfo *)servinfo);
        socket_id = -2;
      }
      else {
        freeaddrinfo((addrinfo *)servinfo);
      }
      return socket_id;
    }
    printf("socket domain:%d,type:%d,protocol:%d\n",p->ai_family,p->ai_socktype,p->ai_protocol);
    socket_id = socket(p->ai_family,p->ai_socktype,p->ai_protocol);
    if (socket_id == 0xffffffff) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : Failed socket\n","http_tcpclient_create");
      builtin_strncpy(tmp1,"Failed socke",0xc);
      tmp1[0xc] = 't';
      tmp1[0xd] = '\0';
      log_to_file(tmp1,time_stamp);
    }
    else {
      puts("log addr:");
      for (i_1 = 0; i_1 < 0xe; i_1 = i_1 + 1) {
        printf("%2X ",(uint)(byte)p->ai_addr->sa_data[i_1]);
      }
      putchar(10);
      printf("log connect:%d  family:%d,len:%d",socket_id,(uint)p->ai_addr->sa_family,p->ai_addrlen)
      ;
      iVar3 = connect(socket_id,(sockaddr *)p->ai_addr,p->ai_addrlen);
      if (iVar3 != -1) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : Succeeded immediate connect\n\n","http_tcpclient_create");
        builtin_strncpy(tmp1,"Succeeded immediate connect\n",0x1c);
        tmp1._28_2_ = tmp1._28_2_ & 0xff00;
        log_to_file(tmp1,time_stamp);
        noblock_socket(socket_id);
        goto LAB_00039c6e;
      }
      perror("socket connect err!\n");
      tv_timeout.tv_sec = 1;
      tv_timeout.tv_usec = 0;
      _Var2 = sock_connecting();
      if (_Var2) {
        do {
          count = count + 1;
          for (__i = 0; __i < 0x20; __i = __i + 1) {
            pcVar1 = time_stamp + __i * 4;
            pcVar1[0] = '\0';
            pcVar1[1] = '\0';
            pcVar1[2] = '\0';
            pcVar1[3] = '\0';
          }
          uVar5 = socket_id + 0x1f;
          if (-1 < socket_id) {
            uVar5 = socket_id;
          }
          uVar6 = socket_id & 0x1f;
          if (socket_id < 1) {
            uVar6 = -(-socket_id & 0x1fU);
          }
          *(uint *)(time_stamp + ((int)uVar5 >> 5) * 4) =
               *(uint *)(time_stamp + ((int)uVar5 >> 5) * 4) | 1 << (uVar6 & 0xff);
          iVar3 = select(socket_id + 1,(fd_set *)0x0,(fd_set *)time_stamp,(fd_set *)0x0,
                         (timeval *)&tv_timeout);
          if (0 < iVar3) {
            uVar5 = socket_id + 0x1f;
            if (-1 < socket_id) {
              uVar5 = socket_id;
            }
            uVar6 = socket_id & 0x1f;
            if (socket_id < 1) {
              uVar6 = -(-socket_id & 0x1fU);
            }
            if ((1 << (uVar6 & 0xff) & *(uint *)(time_stamp + ((int)uVar5 >> 5) * 4)) != 0) {
              len = 4;
              iVar4 = getsockopt(socket_id,1,4,&err,&len);
              if ((iVar4 == 0) && (err == 0)) {
                print_time_stamp(time_stamp_3,0x30);
                printf("%s ",time_stamp_3);
                printf("%s : Succeeded delayed connect, count:%d\n\n","http_tcpclient_create",count)
                ;
                snprintf(tmp1,0x100,"Succeeded delayed connect, count:%d\n",count);
                log_to_file(tmp1,time_stamp_3);
                goto LAB_00039c6e;
              }
            }
          }
        } while ((iVar3 < 0) && (_Var2 = interrupted(), _Var2));
        close(socket_id);
        print_time_stamp(time_stamp_3,0x30);
        printf("%s ",time_stamp_3);
        printf("%s : Select timeout/failed connect\n\n","http_tcpclient_create");
        builtin_strncpy(tmp1,"Select timeout/failed connec",0x1c);
        tmp1[0x1c] = 't';
        tmp1[0x1d] = '\n';
        tmp1[0x1e] = '\0';
        log_to_file(tmp1,time_stamp_3);
      }
      else {
        close(socket_id);
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : Failed sock connect\n\n","http_tcpclient_create");
        builtin_strncpy(tmp1,"Failed sock connect\n",0x14);
        tmp1._20_4_ = tmp1._20_4_ & 0xffffff00;
        log_to_file(tmp1,time_stamp);
      }
    }
    p = p->ai_next;
  } while( true );
}

