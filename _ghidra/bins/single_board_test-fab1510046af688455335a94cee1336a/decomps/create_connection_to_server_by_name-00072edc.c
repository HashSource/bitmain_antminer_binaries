
int create_connection_to_server_by_name(char *host,int port)

{
  _Bool _Var1;
  int32_t iVar2;
  char *__s;
  size_t __n;
  int iVar3;
  char *pcVar4;
  int port_local;
  char *host_local;
  char time_stamp [48];
  char tmp1 [2048];
  char ip [32];
  sockaddr_in serverAddr;
  int32_t creat_socket_timeout_counter;
  int32_t get_host_timeout_counter;
  int32_t get_local_ip_timeout_counter;
  int socket_id;
  uint8_t i;
  int32_t connect_MES_system_timeout_counter;
  hostent *mes_host;
  
  mes_host = (hostent *)0x0;
  memset(ip,0,0x20);
  memset(ip,0,0x20);
  connect_MES_system_timeout_counter = 3;
  socket_id = -1;
  sleep(1);
  iVar2 = get_ip(ip);
  if (iVar2 == 0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: %s: %s\n","create_connection_to_server_by_name",&DAT_001e2748,ip);
    snprintf(tmp1,0x800,"%s: %s",&DAT_001e2748,ip);
    log_to_file(tmp1,time_stamp);
    i = '\0';
    while ((i < 3 && (mes_host = (hostent *)gethostbyname(host), mes_host == (hostent *)0x0))) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: try get MES system ip: %d\n","create_connection_to_server_by_name",(uint)i);
      snprintf(tmp1,0x800,"try get MES system ip: %d",(uint)i);
      log_to_file(tmp1,time_stamp);
      sleep(3);
      if (1 < i) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Can\'t get MES system by host name\n","create_connection_to_server_by_name");
        builtin_strncpy(tmp1,"Can\'t get MES system by host name",0x22);
        log_to_file(tmp1,time_stamp);
        return -1;
      }
      i = i + '\x01';
    }
    memset(ip,0,0x20);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    if (mes_host->h_addrtype == 2) {
      pcVar4 = "AF_INET";
    }
    else {
      pcVar4 = "AF_INET6";
    }
    printf("%s: Address type: %s\n","create_connection_to_server_by_name",pcVar4);
    if (mes_host->h_addrtype == 2) {
      pcVar4 = "AF_INET";
    }
    else {
      pcVar4 = "AF_INET6";
    }
    snprintf(tmp1,0x800,"Address type: %s",pcVar4);
    log_to_file(tmp1,time_stamp);
    for (i = '\0'; mes_host->h_addr_list[i] != (char *)0x0; i = i + '\x01') {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      pcVar4 = inet_ntoa((in_addr)*(in_addr_t *)mes_host->h_addr_list[i]);
      printf("%s: IP addr %d: %s\n","create_connection_to_server_by_name",i + 1,pcVar4);
      pcVar4 = inet_ntoa((in_addr)*(in_addr_t *)mes_host->h_addr_list[i]);
      snprintf(tmp1,0x800,"IP addr %d: %s",i + 1,pcVar4);
      log_to_file(tmp1,time_stamp);
      pcVar4 = inet_ntoa((in_addr)*(in_addr_t *)mes_host->h_addr_list[i]);
      __s = inet_ntoa((in_addr)*(in_addr_t *)mes_host->h_addr_list[i]);
      __n = strlen(__s);
      memcpy(ip,pcVar4,__n);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: ip addr: %s\n","create_connection_to_server_by_name",ip);
      snprintf(tmp1,0x800,"ip addr: %s",ip);
      log_to_file(tmp1,time_stamp);
    }
    for (i = '\0'; i < 3; i = i + '\x01') {
      socket_id = socket(mes_host->h_addrtype,1,0);
      if (-1 < socket_id) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Creat socket success\n","create_connection_to_server_by_name");
        builtin_strncpy(tmp1,"Creat socket success",0x14);
        tmp1._20_4_ = tmp1._20_4_ & 0xffffff00;
        log_to_file(tmp1,time_stamp);
        break;
      }
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Creat socket fail\n","create_connection_to_server_by_name");
      builtin_strncpy(tmp1,"Creat socket fai",0x10);
      tmp1[0x10] = 'l';
      tmp1[0x11] = '\0';
      log_to_file(tmp1,time_stamp);
      if (1 < i) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Creat socket timeout\n","create_connection_to_server_by_name");
        builtin_strncpy(tmp1,"Creat socket timeout",0x14);
        tmp1._20_4_ = tmp1._20_4_ & 0xffffff00;
        log_to_file(tmp1,time_stamp);
        return -1;
      }
    }
    serverAddr.sin_family = (sa_family_t)mes_host->h_addrtype;
    serverAddr.sin_port = htons((uint16_t)port);
    serverAddr.sin_addr.s_addr = inet_addr(ip);
    while (0 < connect_MES_system_timeout_counter) {
      iVar3 = connect(socket_id,(sockaddr *)&serverAddr,0x10);
      if (iVar3 == 0) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Creat socket connection to MES system succeed\n",
               "create_connection_to_server_by_name");
        builtin_strncpy(tmp1,"Creat socket connection to MES system succee",0x2c);
        tmp1[0x2c] = 'd';
        tmp1[0x2d] = '\0';
        log_to_file(tmp1,time_stamp);
        _Var1 = set_socket_feature(socket_id);
        if (_Var1) {
          return socket_id;
        }
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Creat socket timeout\n","create_connection_to_server_by_name");
        builtin_strncpy(tmp1,"Creat socket timeout",0x14);
        tmp1._20_4_ = tmp1._20_4_ & 0xffffff00;
        log_to_file(tmp1,time_stamp);
        return -1;
      }
      sleep(1);
      connect_MES_system_timeout_counter = connect_MES_system_timeout_counter + -1;
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: timeout_counter = %d\n","create_connection_to_server_by_name",
             connect_MES_system_timeout_counter);
      snprintf(tmp1,0x800,"timeout_counter = %d",connect_MES_system_timeout_counter);
      log_to_file(tmp1,time_stamp);
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Creat socket connection to MES system fail\n","create_connection_to_server_by_name")
    ;
    builtin_strncpy(tmp1,"Creat socket connection to MES system fail",0x2b);
    log_to_file(tmp1,time_stamp);
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Can\'t get %s ip\n","create_connection_to_server_by_name",&DAT_001e2748);
    snprintf(tmp1,0x800,"Can\'t get %s ip",&DAT_001e2748);
    log_to_file(tmp1,time_stamp);
  }
  return -1;
}

