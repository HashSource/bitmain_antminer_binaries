
void _applog(uint param_1,char *param_2,undefined4 param_3)

{
  FILE *__s;
  tm *ptVar1;
  int iVar2;
  size_t sVar3;
  byte bVar4;
  uint local_6c;
  uint local_68;
  uint local_64;
  char acStack_60 [68];
  
  local_68 = (uint)use_syslog;
  if (local_68 != 0) {
    syslog(param_1 | 0x80,"%s",param_2);
    return;
  }
  local_64 = local_68;
  cgtime(&local_68);
  local_6c = local_68;
  iVar2 = (int)local_64 / 1000;
  ptVar1 = localtime((time_t *)&local_6c);
  snprintf(acStack_60,0x40," [%d-%02d-%02d %02d:%02d:%02d.%03d] ",ptVar1->tm_year + 0x76c,
           ptVar1->tm_mon + 1,ptVar1->tm_mday,ptVar1->tm_hour,ptVar1->tm_min,ptVar1->tm_sec,iVar2);
  iVar2 = fileno(stderr);
  iVar2 = isatty(iVar2);
  if (iVar2 == 0) {
    fprintf(stderr,"%s%s\n",acStack_60,param_2);
    fflush(stderr);
  }
  if ((g_logfile_enable != '\0') &&
     ((g_log_file != (FILE *)0x0 ||
      (g_log_file = fopen(g_logfile_path,g_logfile_openflag), g_log_file != (FILE *)0x0)))) {
    __s = g_log_file;
    sVar3 = strlen(acStack_60);
    fwrite(acStack_60,sVar3,1,__s);
    sVar3 = strlen(param_2);
    fwrite(param_2,sVar3,1,g_log_file);
    fwrite(&DAT_00065a34,1,1,g_log_file);
    fflush(g_log_file);
  }
  if (param_1 == 3) {
    bVar4 = 0;
  }
  else {
    bVar4 = opt_quiet & 1;
  }
  if (bVar4 != 0) {
    return;
  }
  my_log_curses_part_2(acStack_60,param_2,param_3);
  return;
}

