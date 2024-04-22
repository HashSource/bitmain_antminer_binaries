
/* WARNING: Unknown calling convention */

void get_datestamp(char *f,size_t fsiz,timeval *tv)

{
  tm *ptVar1;
  tm *tm;
  int iVar2;
  int ms;
  __time_t local_1c [2];
  
  iVar2 = tv->tv_usec;
  local_1c[0] = tv->tv_sec;
  ptVar1 = localtime(local_1c);
  snprintf(f,fsiz,"[%d-%02d-%02d %02d:%02d:%02d.%03d]",ptVar1->tm_year + 0x76c,ptVar1->tm_mon + 1,
           ptVar1->tm_mday,ptVar1->tm_hour,ptVar1->tm_min,ptVar1->tm_sec,iVar2 / 1000);
  return;
}

