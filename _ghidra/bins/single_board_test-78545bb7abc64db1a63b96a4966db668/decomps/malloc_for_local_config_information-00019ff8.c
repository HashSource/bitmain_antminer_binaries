
/* WARNING: Unknown calling convention */

_Bool malloc_for_local_config_information(void)

{
  char time_stamp [48];
  char tmp1 [256];
  
  if (Local_Config_Information == (Local_Config_Info *)0x0) {
    Local_Config_Information = (Local_Config_Info *)malloc(0x61c);
    if (Local_Config_Information == (Local_Config_Info *)0x0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : malloc for local config information fail!\n",
             "malloc_for_local_config_information");
      builtin_strncpy(tmp1,"malloc for local config information fail!",0x2a);
      log_to_file(tmp1,time_stamp);
      return false;
    }
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : local config information already malloced\n","malloc_for_local_config_information")
    ;
    builtin_strncpy(tmp1,"local config information already malloced",0x2a);
    log_to_file(tmp1,time_stamp);
  }
  memset(Local_Config_Information,0,0x61c);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : malloc for local config information success\n","malloc_for_local_config_information")
  ;
  builtin_strncpy(tmp1,"malloc for local config information success",0x2c);
  log_to_file(tmp1,time_stamp);
  return true;
}

