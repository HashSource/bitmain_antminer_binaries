
void _simplelog(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  int iVar2;
  
  if (use_syslog != '\0') {
    (*(code *)PTR_syslog_0007d034)(param_1 | 0x80,"%s",param_2,param_4);
    return;
  }
  iVar2 = fileno(stderr);
  iVar2 = isatty(iVar2);
  if (iVar2 == 0) {
    fprintf(stderr,"%s\n",param_2);
    fflush(stderr);
  }
  if (param_1 == 3) {
    bVar1 = 0;
  }
  else {
    bVar1 = opt_quiet & 1;
  }
  if (bVar1 != 0) {
    return;
  }
  my_log_curses_part_2(&DAT_000609ec,param_2,param_3,param_4);
  return;
}

