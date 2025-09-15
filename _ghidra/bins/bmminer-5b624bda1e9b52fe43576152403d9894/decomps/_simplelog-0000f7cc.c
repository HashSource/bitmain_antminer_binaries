
/* WARNING: Unknown calling convention */

void _simplelog(int prio,char *str,_Bool force)

{
  int iVar1;
  undefined4 in_r3;
  
  if (use_syslog) {
    (*(code *)(undefined *)0x0)(prio | 0x80,"%s",str,in_r3);
    return;
  }
  iVar1 = fileno(stderr);
  iVar1 = isatty(iVar1);
  if (iVar1 == 0) {
    fprintf(stderr,"%s\n",str);
    fflush(stderr);
  }
  if (opt_quiet != false) {
    if (prio != 3) {
      return;
    }
  }
  my_log_curses(0x46bb8,str,(char *)(uint)force,SUB41(in_r3,0));
  return;
}

