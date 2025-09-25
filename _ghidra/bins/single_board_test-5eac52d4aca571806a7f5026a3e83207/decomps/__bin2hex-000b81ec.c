
void __bin2hex(char *s,uchar *p,size_t len)

{
  char *pcVar1;
  size_t len_local;
  uchar *p_local;
  char *s_local;
  int i;
  
  s_local = s;
  for (i = 0; i < (int)len; i = i + 1) {
    pcVar1 = s_local + 1;
    *s_local = "0123456789abcdef"[p[i] >> 4];
    s_local = s_local + 2;
    *pcVar1 = "0123456789abcdef"[p[i] & 0xf];
  }
  *s_local = '\0';
  return;
}

