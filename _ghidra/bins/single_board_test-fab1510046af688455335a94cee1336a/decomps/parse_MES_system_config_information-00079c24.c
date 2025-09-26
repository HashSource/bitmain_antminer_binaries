
_Bool parse_MES_system_config_information(uint32_t which_information)

{
  _Bool _Var1;
  uint32_t which_information_local;
  char time_stamp [48];
  char tmp1 [2048];
  
  if (which_information == 0) {
    _Var1 = parse_all_MES_system_config_information();
  }
  else if (which_information == 1) {
    _Var1 = false;
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Don\'t support parse this type config information. type = %d\n",
           "parse_MES_system_config_information",which_information);
    snprintf(tmp1,0x800,"Don\'t support parse this type config information. type = %d",
             which_information);
    log_to_file(tmp1,time_stamp);
    _Var1 = false;
  }
  return _Var1;
}

