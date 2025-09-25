
_Bool convert_V_to_N(char *board_name,double voltage,uint32_t *N)

{
  int iVar1;
  _Bool _Var2;
  double dVar3;
  double voltage_local;
  uint32_t *N_local;
  char *board_name_local;
  char time_stamp [48];
  char tmp1 [256];
  
  iVar1 = strcmp(board_name,"NBT2006-36");
  if (iVar1 == 0) {
    if (voltage <= 15.32) {
      dVar3 = ((15.32 - voltage) / 4.690000057220459) * 1024.0;
      *N = (uint)(0.0 < dVar3) * (int)(longlong)dVar3;
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : %s dac voltage N: %d\n","convert_V_to_N",board_name,*N);
      snprintf(tmp1,0x100,"%s dac voltage N: %d",board_name,*N);
      log_to_file(tmp1,time_stamp);
      _Var2 = true;
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : voltage can\'t bigger than 15.32v\n","convert_V_to_N");
      builtin_strncpy(tmp1,"voltage can\'t bigger than 15.32v",0x20);
      tmp1[0x20] = '\0';
      log_to_file(tmp1,time_stamp);
      _Var2 = false;
    }
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Do not support %s\n","convert_V_to_N",board_name);
    snprintf(tmp1,0x100,"Do not support %s",board_name);
    log_to_file(tmp1,time_stamp);
    _Var2 = false;
  }
  return _Var2;
}

