
char * ERR_error_string(ulong e,char *buf)

{
  undefined1 *buf_00;
  
  buf_00 = buf_7667;
  if (buf != (char *)0x0) {
    buf_00 = buf;
  }
  ERR_error_string_n(e,buf_00,0x100);
  return buf_00;
}

