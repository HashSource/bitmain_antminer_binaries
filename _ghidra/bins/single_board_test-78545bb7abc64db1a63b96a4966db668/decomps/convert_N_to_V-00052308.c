
_Bool convert_N_to_V(char *board_name,int32_t n,double *voltage)

{
  int iVar1;
  _Bool _Var2;
  double *voltage_local;
  int32_t n_local;
  char *board_name_local;
  char time_stamp [48];
  char tmp1 [256];
  
  iVar1 = strcmp(board_name,"NBT2006-36");
  if (iVar1 == 0) {
    if (n < 0x400) {
      iVar1 = n + 0x3ff;
      if (-1 < n) {
        iVar1 = n;
      }
      *voltage = 15.32 - (double)(longlong)(iVar1 >> 10) * 4.69;
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : %s dac voltage: %f\n","convert_N_to_V",board_name,*(undefined4 *)voltage,
             *(undefined4 *)voltage,*(undefined4 *)((int)voltage + 4));
      snprintf(tmp1,0x100,"%s dac voltage: %f",board_name,*(undefined4 *)voltage,
               *(undefined4 *)((int)voltage + 4));
      log_to_file(tmp1,time_stamp);
      _Var2 = true;
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : N can\'t bigger than 1023\n","convert_N_to_V");
      builtin_strncpy(tmp1,"N can\'t bigger than 1023",0x18);
      tmp1[0x18] = '\0';
      log_to_file(tmp1,time_stamp);
      _Var2 = false;
    }
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Do not support %s\n","convert_N_to_V",board_name);
    snprintf(tmp1,0x100,"Do not support %s",board_name);
    log_to_file(tmp1,time_stamp);
    _Var2 = false;
  }
  return _Var2;
}

