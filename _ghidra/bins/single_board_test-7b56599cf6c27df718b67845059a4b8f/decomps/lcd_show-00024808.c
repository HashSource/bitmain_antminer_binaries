
int32_t lcd_show(int32_t line,char *data)

{
  size_t __n;
  int32_t iVar1;
  char *data_local;
  int32_t line_local;
  char time_stamp [48];
  char tmp1 [256];
  char buf [16];
  uint32_t left_space;
  uint32_t length;
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : L%d: %s\n","lcd_show",line,data);
  snprintf(tmp1,0x100,"L%d: %s",line,data);
  log_to_file(tmp1,time_stamp);
  buf[4] = '\0';
  buf[5] = '\0';
  buf[6] = '\0';
  buf[7] = '\0';
  buf[8] = '\0';
  buf[9] = '\0';
  buf[10] = '\0';
  buf[0xb] = '\0';
  buf[0xc] = '\0';
  buf[0xd] = '\0';
  buf[0xe] = '\0';
  buf[0xf] = '\0';
  buf[0] = ' ';
  buf[1] = '\0';
  buf[2] = '\0';
  buf[3] = '\0';
  memset(buf,0x20,0x10);
  __n = strlen(data);
  if (__n < 0x11) {
    memcpy(buf + (0x10 - __n >> 1),data,__n);
    iVar1 = lcd_show_result(line,buf,0x10);
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}

