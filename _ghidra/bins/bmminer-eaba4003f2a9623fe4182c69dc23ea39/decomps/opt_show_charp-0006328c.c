
void opt_show_charp(char *buf,char **p)

{
  char **p_local;
  char *buf_local;
  size_t len;
  
  len = strlen(*p);
  *buf = '\"';
  if (0x4e < len) {
    len = 0x4e;
  }
  strncpy(buf + 1,*p,len);
  buf[len + 1] = '\"';
  if (len < 0x4e) {
    buf[len + 2] = '\0';
  }
  return;
}

