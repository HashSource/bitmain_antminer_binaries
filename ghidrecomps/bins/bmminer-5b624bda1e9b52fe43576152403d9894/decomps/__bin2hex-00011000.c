
/* WARNING: Unknown calling convention */

void __bin2hex(char *s,uchar *p,size_t len)

{
  char *pcVar1;
  
  pcVar1 = s;
  if (0 < (int)len) {
    pcVar1 = s + len * 2;
    do {
      *s = "0123456789abcdef"[*p >> 4];
      s[1] = "0123456789abcdef"[*p & 0xf];
      s = s + 2;
      p = p + 1;
    } while (pcVar1 != s);
  }
  *pcVar1 = '\0';
  return;
}

