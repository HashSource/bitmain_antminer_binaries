
void opt_show_invbool(char *buf,_Bool *b)

{
  char *__src;
  _Bool *b_local;
  char *buf_local;
  
  if (*b == false) {
    __src = "true";
  }
  else {
    __src = "false";
  }
  strncpy(buf,__src,0x50);
  return;
}

