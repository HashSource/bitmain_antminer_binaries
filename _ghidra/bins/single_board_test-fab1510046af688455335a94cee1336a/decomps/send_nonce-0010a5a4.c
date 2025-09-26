
void send_nonce(int fd,char *buf,int len)

{
  ssize_t sVar1;
  int len_local;
  char *buf_local;
  int fd_local;
  char time_stamp [48];
  char tmp1 [2048];
  int ret;
  
  if (fd < 1) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Socket error %d\n","send_nonce",fd);
    snprintf(tmp1,0x800,"Socket error %d",fd);
    log_to_file(tmp1,time_stamp);
  }
  else {
    sVar1 = send(fd,buf,len,0);
    if (sVar1 == 0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Timeout. MES close socket\n","send_nonce");
      builtin_strncpy(tmp1,"Timeout. MES close socke",0x18);
      tmp1[0x18] = 't';
      tmp1[0x19] = '\0';
      log_to_file(tmp1,time_stamp);
    }
    else if (sVar1 < 0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Socket return back: %d\n","send_nonce",sVar1);
      snprintf(tmp1,0x800,"Socket return back: %d",sVar1);
      log_to_file(tmp1,time_stamp);
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Socket send len: %d\n","send_nonce",sVar1);
    snprintf(tmp1,0x800,"Socket send len: %d",sVar1);
    log_to_file(tmp1,time_stamp);
  }
  return;
}

