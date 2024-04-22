
_Bool _valid_hex(char *s,char *file,char *func,int line)

{
  size_t sVar1;
  int len;
  size_t sVar2;
  uint uVar3;
  uchar *idx;
  char tmp42 [2048];
  
  if (s == (char *)0x0) {
    if (((*DAT_00010b8c == '\0') && (*DAT_00010b90 == '\0')) && (*DAT_00010b94 < 3)) {
      return false;
    }
    snprintf(tmp42,0x800,DAT_00010ba4,DAT_00010ba0,DAT_00010b98,file,func);
  }
  else {
    sVar1 = strlen(s);
    if ((int)sVar1 < 1) {
      return true;
    }
    uVar3 = (uint)(byte)*s;
    if (-1 < *(int *)(DAT_00010b88 + uVar3 * 4)) {
      sVar2 = 0;
      do {
        sVar2 = sVar2 + 1;
        if (sVar1 == sVar2) {
          return true;
        }
        s = (char *)((byte *)s + 1);
        uVar3 = (uint)(byte)*s;
      } while (-1 < *(int *)(DAT_00010b88 + uVar3 * 4));
    }
    if (((*DAT_00010b8c == '\0') && (*DAT_00010b90 == '\0')) && (*DAT_00010b94 < 3)) {
      return false;
    }
    snprintf(tmp42,0x800,DAT_00010b9c,DAT_00010ba0,uVar3,DAT_00010b98,file,func);
  }
  _applog(3,tmp42,false);
  return false;
}

