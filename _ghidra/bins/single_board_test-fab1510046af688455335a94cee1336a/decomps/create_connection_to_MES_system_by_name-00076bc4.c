
_Bool create_connection_to_MES_system_by_name(uint32_t which_process_to_connect_MES)

{
  _Bool _Var1;
  int32_t iVar2;
  char *__s;
  size_t __n;
  int iVar3;
  char *pcVar4;
  uint32_t which_process_to_connect_MES_local;
  char time_stamp [48];
  char tmp1 [2048];
  char ip [32];
  sockaddr_in serverAddr;
  uint8_t i;
  int32_t connect_MES_system_timeout_counter;
  int32_t creat_socket_timeout_counter;
  int32_t get_host_timeout_counter;
  int32_t get_local_ip_timeout_counter;
  hostent *mes_host;
  
  mes_host = (hostent *)0x0;
  memset(ip,0,0x20);
  memset(ip,0,0x20);
  if (which_process_to_connect_MES == 1) {
    get_local_ip_timeout_counter = 1000000;
    get_host_timeout_counter = 1000000;
    creat_socket_timeout_counter = 1000000;
    connect_MES_system_timeout_counter = 1000000;
  }
  else {
    if (which_process_to_connect_MES != 2) {
      lcd_clear_result();
      lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
      lcd_show(1,"don\'t figer out");
      lcd_show(2,"which process to");
      lcd_show(3,"connect MES");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: don\'t figer out which process to connect MES\n",
             "create_connection_to_MES_system_by_name");
      builtin_strncpy(tmp1,"don\'t figer out which process to connect MES",0x2c);
      tmp1._44_2_ = (ushort)(byte)tmp1[0x2d] << 8;
      log_to_file(tmp1,time_stamp);
      return false;
    }
    get_local_ip_timeout_counter = 0x3c;
    get_host_timeout_counter = 3;
    creat_socket_timeout_counter = 3;
    connect_MES_system_timeout_counter = 3;
  }
  if (bitmain_MES_system_clientSocket != -1) {
    close(bitmain_MES_system_clientSocket);
    bitmain_MES_system_clientSocket = -1;
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: close socket\n","create_connection_to_MES_system_by_name");
    builtin_strncpy(tmp1,"close socket",0xc);
    tmp1._12_4_ = tmp1._12_4_ & 0xffffff00;
    log_to_file(tmp1,time_stamp);
  }
  for (i = '\0'; (uint)i < (uint)get_local_ip_timeout_counter; i = i + '\x01') {
    sleep(1);
    iVar2 = get_local_ip("eth0",ip);
    if (iVar2 == 0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: %s: %s\n","create_connection_to_MES_system_by_name",&DAT_001e3fe8,ip);
      snprintf(tmp1,0x800,"%s: %s",&DAT_001e3fe8,ip);
      log_to_file(tmp1,time_stamp);
      break;
    }
    if (get_local_ip_timeout_counter + -1 <= (int)(uint)i) {
      lcd_clear_result();
      lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
      lcd_show(1,"can\'t get");
      lcd_show(2,"local ip");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Can\'t get %s ip\n","create_connection_to_MES_system_by_name",&DAT_001e3fe8);
      snprintf(tmp1,0x800,"Can\'t get %s ip",&DAT_001e3fe8);
      log_to_file(tmp1,time_stamp);
      return false;
    }
  }
  i = '\0';
  while (((uint)i < (uint)get_host_timeout_counter &&
         (mes_host = (hostent *)gethostbyname("mtcs.bitmain.vip"), mes_host == (hostent *)0x0))) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: try get MES system ip: %d\n","create_connection_to_MES_system_by_name",(uint)i);
    snprintf(tmp1,0x800,"try get MES system ip: %d",(uint)i);
    log_to_file(tmp1,time_stamp);
    sleep(3);
    if (get_host_timeout_counter + -1 <= (int)(uint)i) {
      lcd_clear_result();
      lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
      lcd_show(1,"can\'t get");
      lcd_show(2,"MES system ip");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Can\'t get MES system by host name\n","create_connection_to_MES_system_by_name");
      builtin_strncpy(tmp1,"Can\'t get MES system by host name",0x22);
      log_to_file(tmp1,time_stamp);
      return false;
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
  printf("%s: Address type: %s\n","create_connection_to_MES_system_by_name",pcVar4);
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
    printf("%s: IP addr %d: %s\n","create_connection_to_MES_system_by_name",i + 1,pcVar4);
    pcVar4 = inet_ntoa((in_addr)*(in_addr_t *)mes_host->h_addr_list[i]);
    snprintf(tmp1,0x800,"IP addr %d: %s",i + 1,pcVar4);
    log_to_file(tmp1,time_stamp);
    pcVar4 = inet_ntoa((in_addr)*(in_addr_t *)mes_host->h_addr_list[i]);
    __s = inet_ntoa((in_addr)*(in_addr_t *)mes_host->h_addr_list[i]);
    __n = strlen(__s);
    memcpy(ip,pcVar4,__n);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: ip addr: %s\n","create_connection_to_MES_system_by_name",ip);
    snprintf(tmp1,0x800,"ip addr: %s",ip);
    log_to_file(tmp1,time_stamp);
  }
  i = '\0';
  do {
    if ((uint)creat_socket_timeout_counter <= (uint)i) {
LAB_000773ec:
      serverAddr.sin_family = (sa_family_t)mes_host->h_addrtype;
      serverAddr.sin_port = htons(0x1f9a);
      serverAddr.sin_addr.s_addr = inet_addr(ip);
      while( true ) {
        if (connect_MES_system_timeout_counter < 1) {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: Creat socket connection to MES system fail\n",
                 "create_connection_to_MES_system_by_name");
          builtin_strncpy(tmp1,"Creat socket connection to MES system fail",0x2b);
          log_to_file(tmp1,time_stamp);
          return false;
        }
        iVar3 = connect(bitmain_MES_system_clientSocket,(sockaddr *)&serverAddr,0x10);
        if (iVar3 == 0) break;
        sleep(1);
        connect_MES_system_timeout_counter = connect_MES_system_timeout_counter + -1;
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: timeout_counter = %d\n","create_connection_to_MES_system_by_name",
               connect_MES_system_timeout_counter);
        snprintf(tmp1,0x800,"timeout_counter = %d",connect_MES_system_timeout_counter);
        log_to_file(tmp1,time_stamp);
      }
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Creat socket connection to MES system succeed\n",
             "create_connection_to_MES_system_by_name");
      builtin_strncpy(tmp1,"Creat socket connection to MES system succee",0x2c);
      tmp1[0x2c] = 'd';
      tmp1[0x2d] = '\0';
      log_to_file(tmp1,time_stamp);
      _Var1 = set_socket_feature(bitmain_MES_system_clientSocket);
      if (!_Var1) {
        lcd_clear_result();
        lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
        lcd_show(1,"set socket");
        lcd_show(2,"feature");
        lcd_show(3,"fail");
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Creat socket timeout\n","create_connection_to_MES_system_by_name");
        builtin_strncpy(tmp1,"Creat socket timeout",0x14);
        tmp1._20_4_ = tmp1._20_4_ & 0xffffff00;
        log_to_file(tmp1,time_stamp);
        return false;
      }
      return true;
    }
    bitmain_MES_system_clientSocket = socket(mes_host->h_addrtype,1,0);
    if (-1 < bitmain_MES_system_clientSocket) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Creat socket success\n","create_connection_to_MES_system_by_name");
      builtin_strncpy(tmp1,"Creat socket success",0x14);
      tmp1._20_4_ = tmp1._20_4_ & 0xffffff00;
      log_to_file(tmp1,time_stamp);
      goto LAB_000773ec;
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Creat socket fail\n","create_connection_to_MES_system_by_name");
    builtin_strncpy(tmp1,"Creat socket fai",0x10);
    tmp1[0x10] = 'l';
    tmp1[0x11] = '\0';
    log_to_file(tmp1,time_stamp);
    if (creat_socket_timeout_counter + -1 <= (int)(uint)i) {
      lcd_clear_result();
      lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
      lcd_show(1,"can\'t connect");
      lcd_show(2,"MES system");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Creat socket timeout\n","create_connection_to_MES_system_by_name");
      builtin_strncpy(tmp1,"Creat socket timeout",0x14);
      tmp1._20_4_ = tmp1._20_4_ & 0xffffff00;
      log_to_file(tmp1,time_stamp);
      return false;
    }
    i = i + '\x01';
  } while( true );
}

