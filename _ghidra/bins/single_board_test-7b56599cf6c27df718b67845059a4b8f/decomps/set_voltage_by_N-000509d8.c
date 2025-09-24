
_Bool set_voltage_by_N(char *board_name,uint8_t which_chain,uint32_t voltage_N)

{
  _Bool _Var1;
  int iVar2;
  uint32_t voltage_N_local;
  uint8_t which_chain_local;
  char *board_name_local;
  char time_stamp [48];
  char tmp1 [256];
  
  iVar2 = strcmp(board_name,"NBT2006-36");
  if (iVar2 == 0) {
    _Var1 = set_dac53401_voltage(which_chain,voltage_N);
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : %s not use dac\n","set_voltage_by_N",board_name);
    snprintf(tmp1,0x100,"%s not use dac",board_name);
    log_to_file(tmp1,time_stamp);
    _Var1 = false;
  }
  return _Var1;
}

