
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void pt_exit(void)

{
  char time_stamp [48];
  char tmp1 [256];
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : pt exit\n","pt_exit");
  builtin_strncpy(tmp1,"pt exit",8);
  log_to_file(tmp1,time_stamp);
  return;
}

