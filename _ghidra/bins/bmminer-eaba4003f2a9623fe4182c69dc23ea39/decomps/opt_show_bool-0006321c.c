
void opt_show_bool(char *buf,_Bool *b)

{
  char *__src;
  _Bool *b_local;
  char *buf_local;
  
  if (*b == false) {
    __src = "false";
  }
  else {
    __src = "true";
  }
  strncpy(buf,__src,0x50);
  return;
}

