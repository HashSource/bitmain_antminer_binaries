
_Bool set_dac_voltage(char *board_name,uint8_t which_chain,double voltage)

{
  _Bool _Var1;
  int iVar2;
  double voltage_local;
  uint8_t which_chain_local;
  char *board_name_local;
  char time_stamp [48];
  char tmp1 [2048];
  uint32_t voltage_N;
  
  voltage_N = 0;
  iVar2 = strcmp(board_name,"NBT2006-36");
  if (iVar2 == 0) {
    _Var1 = convert_V_to_N(board_name,voltage,&voltage_N);
    if (_Var1) {
      _Var1 = set_voltage_by_N(board_name,which_chain,voltage_N);
      if (_Var1) {
        _Var1 = true;
      }
      else {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: fail\n","set_dac_voltage");
        builtin_strncpy(tmp1,"fail",4);
        tmp1[4] = '\0';
        log_to_file(tmp1,time_stamp);
        _Var1 = false;
      }
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: fail\n","set_dac_voltage");
      builtin_strncpy(tmp1,"fail",4);
      tmp1[4] = '\0';
      log_to_file(tmp1,time_stamp);
      _Var1 = false;
    }
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: %s not use dac\n","set_dac_voltage",board_name);
    snprintf(tmp1,0x800,"%s not use dac",board_name);
    log_to_file(tmp1,time_stamp);
    _Var1 = false;
  }
  return _Var1;
}

