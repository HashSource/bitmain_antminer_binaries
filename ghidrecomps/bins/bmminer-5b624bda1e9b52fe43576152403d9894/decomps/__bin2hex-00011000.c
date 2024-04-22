
/* WARNING: Unknown calling convention */

void __bin2hex(char *s,uchar *p,size_t len)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = DAT_0001103c;
  pcVar2 = s;
  if (0 < (int)len) {
    pcVar2 = s + len * 2;
    do {
      *s = *(char *)(iVar1 + (uint)(*p >> 4) + 0x454);
      s[1] = *(char *)(iVar1 + (*p & 0xf) + 0x454);
      s = s + 2;
      p = p + 1;
    } while (pcVar2 != s);
  }
  *pcVar2 = '\0';
  return;
}

