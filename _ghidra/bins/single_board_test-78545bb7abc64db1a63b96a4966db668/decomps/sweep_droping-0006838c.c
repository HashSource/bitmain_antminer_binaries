
/* WARNING: Unknown calling convention */

int sweep_droping(void)

{
  int iVar1;
  char time_stamp [48];
  char tmp1 [256];
  
  iVar1 = (*ops.drop)(&freq_matrix,&state_matrix);
  if (iVar1 == 0) {
    iVar1 = sweep_flush();
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : sweep failed\n","sweep_droping");
    builtin_strncpy(tmp1,"sweep failed",0xc);
    tmp1[0xc] = '\0';
    log_to_file(tmp1,time_stamp);
    iVar1 = -1;
  }
  return iVar1;
}

