
/* WARNING: Unknown calling convention */

void opt_show_charp(char *buf,char **p)

{
  size_t __n;
  
  __n = strlen(*p);
  *buf = '\"';
  if (__n < 0x4f) {
    strncpy(buf + 1,*p,__n);
    buf[__n + 1] = '\"';
    if (__n != 0x4e) {
      buf[__n + 2] = '\0';
      return;
    }
  }
  else {
    strncpy(buf + 1,*p,0x4e);
    buf[0x4f] = '\"';
  }
  return;
}

