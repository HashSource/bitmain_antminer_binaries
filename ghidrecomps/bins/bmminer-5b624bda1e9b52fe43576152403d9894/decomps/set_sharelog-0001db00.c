
/* WARNING: Unknown calling convention */

char * set_sharelog(char *arg)

{
  char *__fd;
  long i;
  FILE *pFVar1;
  char *__format;
  int iVar2;
  uchar *__s1;
  char *r;
  char tmp42 [2048];
  
  r = DAT_0001dbe8;
  __fd = (char *)strtol(arg,&r,10);
  if ((*r == '\0') && (-1 < (int)__fd)) {
    pFVar1 = fdopen((int)__fd,DAT_0001dbec);
    *(FILE **)(DAT_0001dbf0 + 0x11c) = pFVar1;
    if (pFVar1 != (FILE *)0x0) {
      return (char *)0x0;
    }
    __format = DAT_0001dc00;
    if ((*DAT_0001dbf4 != '\0') || (*DAT_0001dbf8 != '\0')) goto LAB_0001dba0;
    iVar2 = *DAT_0001dbfc;
  }
  else {
    if ((*arg == '-') && (arg[1] == '\0')) {
      iVar2 = *DAT_0001dc04;
      *(int *)(DAT_0001dbf0 + 0x11c) = iVar2;
      if (iVar2 != 0) {
        return (char *)0x0;
      }
      if (((*DAT_0001dbf4 == '\0') && (*DAT_0001dbf8 == '\0')) && (*DAT_0001dbfc < 3)) {
        return (char *)0x0;
      }
      tmp42._0_4_ = *DAT_0001dc0c;
      tmp42._4_4_ = DAT_0001dc0c[1];
      tmp42._8_4_ = DAT_0001dc0c[2];
      tmp42._12_4_ = DAT_0001dc0c[3];
      tmp42._16_4_ = DAT_0001dc0c[4];
      tmp42._20_4_ = DAT_0001dc0c[5];
      tmp42._24_4_ = DAT_0001dc0c[6];
      tmp42._28_4_ = DAT_0001dc0c[7];
      tmp42._32_4_ = DAT_0001dc0c[8];
      tmp42._36_2_ = (undefined2)DAT_0001dc0c[9];
      _applog(3,tmp42,false);
      return (char *)0x0;
    }
    pFVar1 = fopen(arg,DAT_0001dbec);
    *(FILE **)(DAT_0001dbf0 + 0x11c) = pFVar1;
    if (pFVar1 != (FILE *)0x0) {
      return (char *)0x0;
    }
    __format = DAT_0001dc08;
    __fd = arg;
    if ((*DAT_0001dbf4 != '\0') || (*DAT_0001dbf8 != '\0')) goto LAB_0001dba0;
    iVar2 = *DAT_0001dbfc;
  }
  if (iVar2 < 3) {
    return (char *)0x0;
  }
LAB_0001dba0:
  snprintf(tmp42,0x800,__format,__fd);
  _applog(3,tmp42,false);
  return (char *)0x0;
}

