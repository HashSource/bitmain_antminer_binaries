
/* WARNING: Unknown calling convention */

void _applog(int prio,char *str,_Bool force)

{
  char cVar1;
  char *pcVar2;
  FILE **ppFVar3;
  tm *ptVar4;
  tm *tm;
  int iVar5;
  size_t sVar6;
  FILE *__s;
  int ms;
  time_t tmp_time;
  timeval tv;
  char datetime [64];
  
  tv.tv_sec = (__time_t)*DAT_0000f6b4;
  if (tv.tv_sec != 0) {
    syslog(prio | 0x80,DAT_0000f6cc,str);
    return;
  }
  tv.tv_usec = tv.tv_sec;
  cgtime(&tv);
  ppFVar3 = DAT_0000f6b8;
  tmp_time = tv.tv_sec;
  iVar5 = tv.tv_usec / 1000;
  ptVar4 = localtime(&tmp_time);
  snprintf(datetime,0x40,DAT_0000f6bc,ptVar4->tm_year + 0x76c,ptVar4->tm_mon + 1,ptVar4->tm_mday,
           ptVar4->tm_hour,ptVar4->tm_min,ptVar4->tm_sec,iVar5);
  iVar5 = fileno(*ppFVar3);
  iVar5 = isatty(iVar5);
  if (iVar5 == 0) {
    fprintf(*ppFVar3,DAT_0000f6d0,datetime,str);
    pcVar2 = DAT_0000f6c0;
    fflush(*ppFVar3);
    cVar1 = *pcVar2;
  }
  else {
    cVar1 = *DAT_0000f6c0;
    pcVar2 = DAT_0000f6c0;
  }
  if (cVar1 != '\0') {
    __s = *(FILE **)(pcVar2 + 4);
    if (__s == (FILE *)0x0) {
      __s = fopen(pcVar2 + 8,pcVar2 + 0x108);
      *(FILE **)(pcVar2 + 4) = __s;
      if (__s == (FILE *)0x0) goto LAB_0000f656;
    }
    sVar6 = strlen(datetime);
    fwrite(datetime,sVar6,1,__s);
    sVar6 = strlen(str);
    fwrite(str,sVar6,1,*(FILE **)(pcVar2 + 4));
    fwrite(DAT_0000f6c4,1,1,*(FILE **)(pcVar2 + 4));
    fflush(*(FILE **)(pcVar2 + 4));
  }
LAB_0000f656:
  if ((*(_Bool *)DAT_0000f6c8 == false) || (prio == 3)) {
    my_log_curses((int)datetime,str,(char *)(uint)force,*(_Bool *)DAT_0000f6c8);
  }
  return;
}

