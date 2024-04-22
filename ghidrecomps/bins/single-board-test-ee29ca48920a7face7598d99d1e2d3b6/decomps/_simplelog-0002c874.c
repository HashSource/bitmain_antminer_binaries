
void _simplelog(undefined4 param_1,undefined4 param_2,undefined param_3)

{
  int iVar1;
  
  iVar1 = fileno(stderr);
  iVar1 = isatty(iVar1);
  if (iVar1 == 0) {
    fprintf(stderr,"%s\n",param_2);
    fflush(stderr);
  }
  my_log_curses(param_1,&DAT_00036b34,param_2,param_3);
  return;
}

