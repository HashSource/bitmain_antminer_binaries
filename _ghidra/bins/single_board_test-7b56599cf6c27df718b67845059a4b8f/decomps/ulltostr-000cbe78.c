
_Bool ulltostr(char *str,size_t size,uint64_t num,int base)

{
  int extraout_r2;
  char *pcVar1;
  char *pcVar2;
  undefined4 uVar3;
  char acStack_6e [2];
  char buf [65];
  
  buf[0] = '\0';
  buf[1] = '\0';
  buf[2] = '\0';
  buf[3] = '\0';
  memset(buf + 4,0,0x3d);
  if (size != 0) {
    if (0x40 < size) {
      size = 0x41;
    }
    if (size - 1 == 0) {
      if (num == 0) goto LAB_000cbefe;
    }
    else {
      pcVar1 = acStack_6e + 1;
      do {
        pcVar2 = pcVar1;
        uVar3 = (undefined4)(num >> 0x20);
        __aeabi_uldivmod((int)num,uVar3,0x24,0);
        pcVar1 = pcVar2 + 1;
        *pcVar1 = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[extraout_r2];
        num = __aeabi_uldivmod((int)num,uVar3,0x24,0);
      } while (pcVar1 != buf + (size - 2));
      if (num == 0) {
        pcVar2 = pcVar2 + 2;
        pcVar1 = str + -1;
        do {
          pcVar2 = pcVar2 + -1;
          pcVar1 = pcVar1 + 1;
          *pcVar1 = *pcVar2;
        } while (buf != pcVar2);
LAB_000cbefe:
        str[size - 1] = '\0';
        return true;
      }
    }
  }
  return false;
}

