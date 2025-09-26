
/* WARNING: Unknown calling convention */

int create_socket(void)

{
  _Bool _Var1;
  int __fd;
  int iVar2;
  char time_stamp [48];
  char tmp1 [2048];
  sockaddr_in serverAddr;
  int fd;
  int32_t timeout_counter;
  
  timeout_counter = 0x1e;
  __fd = socket(2,1,0);
  if (__fd < 0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Creat socket fail\n","create_socket");
    builtin_strncpy(tmp1,"Creat socket fai",0x10);
    tmp1[0x10] = 'l';
    tmp1[0x11] = '\0';
    log_to_file(tmp1,time_stamp);
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Creat socket success\n","create_socket");
    builtin_strncpy(tmp1,"Creat socket success",0x14);
    tmp1._20_4_ = tmp1._20_4_ & 0xffffff00;
    log_to_file(tmp1,time_stamp);
    serverAddr.sin_family = 2;
    serverAddr.sin_port = htons(0x11d8);
    serverAddr.sin_addr.s_addr = inet_addr("10.76.6.34");
    while (0 < timeout_counter) {
      iVar2 = connect(__fd,(sockaddr *)&serverAddr,0x10);
      if (iVar2 == 0) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Creat socket connection to pattern svr succeed\n","create_socket");
        builtin_strncpy(tmp1,"Creat socket connection to pattern svr succe",0x2c);
        tmp1[0x2c] = 'e';
        tmp1[0x2d] = 'd';
        tmp1[0x2e] = '\0';
        log_to_file(tmp1,time_stamp);
        _Var1 = set_socket_opt(__fd);
        if (_Var1) {
          return __fd;
        }
        return -1;
      }
      sleep(1);
      timeout_counter = timeout_counter + -1;
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: timeout_counter = %d\n","create_socket",timeout_counter);
      snprintf(tmp1,0x800,"timeout_counter = %d",timeout_counter);
      log_to_file(tmp1,time_stamp);
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Creat socket connection to  pattern svr fail\n","create_socket");
    builtin_strncpy(tmp1,"Creat socket connection to  pattern svr fail",0x2c);
    tmp1._44_2_ = (ushort)(byte)tmp1[0x2d] << 8;
    log_to_file(tmp1,time_stamp);
  }
  return -1;
}

