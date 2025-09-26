
/* WARNING: Unknown calling convention */

int sweep_flush(void)

{
  int iVar1;
  char time_stamp [48];
  char tmp1 [256];
  int ret;
  
  iVar1 = (*ops.flush)(&freq_matrix);
  if (iVar1 == 0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Sweep Success\n","sweep_flush");
    builtin_strncpy(tmp1,"Sweep Succes",0xc);
    tmp1[0xc] = 's';
    tmp1[0xd] = '\0';
    log_to_file(tmp1,time_stamp);
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Sweep Fail\n","sweep_flush");
    builtin_strncpy(tmp1,"Sweep Fa",8);
    tmp1[8] = 'i';
    tmp1[9] = 'l';
    tmp1[10] = '\0';
    log_to_file(tmp1,time_stamp);
  }
  if (freq_matrix != (float *)0x0) {
    free(freq_matrix);
    freq_matrix = (float *)0x0;
  }
  if (state_matrix != (uint8_t *)0x0) {
    free(state_matrix);
    state_matrix = (uint8_t *)0x0;
  }
  return iVar1;
}

