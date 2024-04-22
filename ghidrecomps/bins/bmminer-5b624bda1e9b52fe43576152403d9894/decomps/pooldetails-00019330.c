
/* WARNING: Unknown calling convention */

_Bool pooldetails(char *param,char **url,char **user,char **pass)

{
  char cVar1;
  size_t sVar2;
  char *__ptr;
  char *ptr;
  char **buf_00;
  char *buf;
  char tmp42 [2048];
  
  buf_00 = user;
  sVar2 = strlen(param);
  __ptr = (char *)malloc(sVar2 + 1);
  buf = __ptr;
  if (__ptr == (char *)0x0) {
    tmp42._0_4_ = *DAT_000193c8;
    tmp42._4_4_ = DAT_000193c8[1];
    tmp42._8_4_ = DAT_000193c8[2];
    tmp42._12_4_ = DAT_000193c8[3];
    tmp42._16_4_ = DAT_000193c8[4];
    tmp42._20_4_ = DAT_000193c8[5];
    tmp42._24_4_ = DAT_000193c8[6];
    tmp42._28_4_ = DAT_000193c8[7];
    buf_00 = (char **)0x1;
    tmp42[32] = (char)DAT_000193c8[8];
    _applog(3,tmp42,true);
    _quit(1);
  }
  *url = buf;
  cVar1 = (char)&stack0xffffffec;
  copyadvanceafter(cVar1 + -0x10,&buf,buf_00);
  if (*param != '\0') {
    *user = buf;
    copyadvanceafter(cVar1 + -0x10,&buf,buf_00);
    if (*param != '\0') {
      *pass = buf;
      copyadvanceafter(cVar1 + -0x10,&buf,buf_00);
      return true;
    }
  }
  free(__ptr);
  return false;
}

