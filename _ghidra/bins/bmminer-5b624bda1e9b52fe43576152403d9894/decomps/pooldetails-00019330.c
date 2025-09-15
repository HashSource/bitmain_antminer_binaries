
/* WARNING: Unknown calling convention */

_Bool pooldetails(char *param,char **url,char **user,char **pass)

{
  char cVar1;
  size_t sVar2;
  char *__ptr;
  char **extraout_r2;
  char **buf_00;
  char **buf_01;
  char **buf_02;
  char **extraout_r2_00;
  char *buf;
  char tmp42 [2048];
  
  sVar2 = strlen(param);
  __ptr = (char *)malloc(sVar2 + 1);
  buf_00 = extraout_r2;
  buf = __ptr;
  if (__ptr == (char *)0x0) {
    builtin_strncpy(tmp42,"Failed to malloc pooldetails buf",0x20);
    tmp42[0x20] = '\0';
    _applog(3,tmp42,true);
    _quit(1);
    buf_00 = extraout_r2_00;
  }
  *url = buf;
  cVar1 = (char)&stack0xffffffec;
  copyadvanceafter(cVar1 + -0x10,&buf,buf_00);
  if (*param != '\0') {
    *user = buf;
    copyadvanceafter(cVar1 + -0x10,&buf,buf_01);
    if (*param != '\0') {
      *pass = buf;
      copyadvanceafter(cVar1 + -0x10,&buf,buf_02);
      return true;
    }
  }
  free(__ptr);
  return false;
}

