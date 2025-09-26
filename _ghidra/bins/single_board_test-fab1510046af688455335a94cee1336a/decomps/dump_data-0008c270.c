
void dump_data(char *data,int len)

{
  int len_local;
  char *data_local;
  char time_stamp [48];
  char tmp1 [2048];
  int i;
  
  for (i = 0; i < len; i = i + 1) {
    if ((i & 0xfU) == 0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: \n0x%02x  \n","dump_data",i);
      snprintf(tmp1,0x800,"\n0x%02x  ",i);
      log_to_file(tmp1,time_stamp);
    }
    if ((i & 0xfU) == 8) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s:    \n","dump_data");
      builtin_strncpy(tmp1,"   ",4);
      log_to_file(tmp1,time_stamp);
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: %02x \n","dump_data",(uint)(byte)data[i]);
    snprintf(tmp1,0x800,"%02x ",(uint)(byte)data[i]);
    log_to_file(tmp1,time_stamp);
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: \n\n","dump_data");
  tmp1[0] = '\n';
  tmp1[1] = '\0';
  log_to_file(tmp1,time_stamp);
  return;
}

