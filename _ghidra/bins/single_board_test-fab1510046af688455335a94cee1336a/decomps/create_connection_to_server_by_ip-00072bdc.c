
int create_connection_to_server_by_ip(char *host,int port)

{
  undefined4 uVar1;
  _Bool _Var2;
  int iVar3;
  int iVar4;
  int port_local;
  char *host_local;
  char time_stamp [48];
  char tmp1 [2048];
  sockaddr_in serverAddr;
  int sockd;
  int32_t timeout_counter;
  
  timeout_counter = 0x1e;
  iVar3 = socket(2,1,0);
  if (iVar3 < 0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Creat socket fail\n","create_connection_to_server_by_ip");
    builtin_strncpy(tmp1,"Creat socket fai",0x10);
    tmp1[0x10] = 'l';
    tmp1[0x11] = '\0';
    log_to_file(tmp1,time_stamp);
    iVar3 = -3;
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Creat socket success\n","create_connection_to_server_by_ip");
    builtin_strncpy(tmp1,"Creat socket success",0x14);
    tmp1._20_4_ = tmp1._20_4_ & 0xffffff00;
    log_to_file(tmp1,time_stamp);
    serverAddr.sin_family = 2;
    serverAddr.sin_port = htons((uint16_t)port);
    serverAddr.sin_addr.s_addr = inet_addr(host);
    while (0 < timeout_counter) {
      iVar4 = connect(iVar3,(sockaddr *)&serverAddr,0x10);
      if (iVar4 == 0) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Creat socket connection to server succeed\n","create_connection_to_server_by_ip"
              );
        builtin_strncpy(tmp1,"Creat socket connection to server succee",0x28);
        tmp1[0x28] = 'd';
        tmp1[0x29] = '\0';
        log_to_file(tmp1,time_stamp);
        _Var2 = set_socket_feature(iVar3);
        if (_Var2) {
          return iVar3;
        }
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: set_socket_feature failed\n","create_connection_to_server_by_ip");
        uVar1 = tmp1._24_4_;
        builtin_strncpy(tmp1,"set_socket_feature failed",0x1a);
        tmp1._26_2_ = SUB42(uVar1,2);
        log_to_file(tmp1,time_stamp);
        close(iVar3);
        return -1;
      }
      sleep(1);
      timeout_counter = timeout_counter + -1;
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: timeout_counter = %d\n","create_connection_to_server_by_ip",timeout_counter);
      snprintf(tmp1,0x800,"timeout_counter = %d",timeout_counter);
      log_to_file(tmp1,time_stamp);
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Creat socket connection to server failed\n","create_connection_to_server_by_ip");
    builtin_strncpy(tmp1,"Creat socket connection to server failed",0x28);
    tmp1._40_2_ = (ushort)(byte)tmp1[0x29] << 8;
    log_to_file(tmp1,time_stamp);
    iVar3 = -2;
  }
  return iVar3;
}

