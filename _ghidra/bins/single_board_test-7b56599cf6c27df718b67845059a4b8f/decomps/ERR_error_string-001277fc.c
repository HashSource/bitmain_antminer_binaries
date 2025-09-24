
char * ERR_error_string(ulong e,char *buf)

{
  if (buf != (char *)0x0) {
    ERR_error_string_n(e,buf,0x100);
    return buf;
  }
  ERR_error_string_n(e,buf_9458,0x100);
  return buf_9458;
}

