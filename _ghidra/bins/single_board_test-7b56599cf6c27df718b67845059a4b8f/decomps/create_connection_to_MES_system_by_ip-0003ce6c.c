
/* WARNING: Unknown calling convention */

_Bool create_connection_to_MES_system_by_ip(void)

{
  _Bool _Var1;
  int iVar2;
  char time_stamp [48];
  char tmp1 [256];
  sockaddr_in serverAddr;
  int32_t timeout_counter;
  
  timeout_counter = 0x1e;
  bitmain_MES_system_clientSocket = socket(2,1,0);
  if (bitmain_MES_system_clientSocket < 0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Creat socket fail\n","create_connection_to_MES_system_by_ip");
    builtin_strncpy(tmp1,"Creat socket fai",0x10);
    tmp1[0x10] = 'l';
    tmp1[0x11] = '\0';
    log_to_file(tmp1,time_stamp);
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Creat socket success\n","create_connection_to_MES_system_by_ip");
    builtin_strncpy(tmp1,"Creat socket success",0x14);
    tmp1._20_4_ = tmp1._20_4_ & 0xffffff00;
    log_to_file(tmp1,time_stamp);
    serverAddr.sin_family = 2;
    serverAddr.sin_port = htons(0x1f9a);
    serverAddr.sin_addr.s_addr = inet_addr("8.135.46.51");
    while (0 < timeout_counter) {
      iVar2 = connect(bitmain_MES_system_clientSocket,(sockaddr *)&serverAddr,0x10);
      if (iVar2 == 0) {
        _Var1 = set_socket_feature(bitmain_MES_system_clientSocket);
        if (!_Var1) {
          return false;
        }
        return true;
      }
      sleep(1);
      timeout_counter = timeout_counter + -1;
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : timeout_counter = %d\n","create_connection_to_MES_system_by_ip",timeout_counter);
      snprintf(tmp1,0x100,"timeout_counter = %d",timeout_counter);
      log_to_file(tmp1,time_stamp);
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Creat socket connection to MES system fail\n",
           "create_connection_to_MES_system_by_ip");
    builtin_strncpy(tmp1,"Creat socket connection to MES system fa",0x28);
    tmp1[0x28] = 'i';
    tmp1[0x29] = 'l';
    tmp1[0x2a] = '\0';
    log_to_file(tmp1,time_stamp);
  }
  return false;
}

