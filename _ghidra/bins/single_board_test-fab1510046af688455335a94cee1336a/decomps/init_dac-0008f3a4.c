
_Bool init_dac(char *board_name,uint8_t which_chain)

{
  _Bool _Var1;
  int iVar2;
  uint8_t which_chain_local;
  char *board_name_local;
  char time_stamp [48];
  char tmp1 [2048];
  
  iVar2 = strcmp(board_name,"NBT2006-36");
  if (iVar2 == 0) {
    _Var1 = init_dac53401_NBT2006_36(which_chain);
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: %s not use dac\n","init_dac",board_name);
    snprintf(tmp1,0x800,"%s not use dac",board_name);
    log_to_file(tmp1,time_stamp);
    _Var1 = false;
  }
  return _Var1;
}

