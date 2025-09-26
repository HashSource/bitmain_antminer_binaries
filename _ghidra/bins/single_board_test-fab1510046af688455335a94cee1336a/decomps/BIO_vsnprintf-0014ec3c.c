
int BIO_vsnprintf(char *buf,size_t n,char *format,va_list args)

{
  size_t local_18;
  char *local_14;
  uint local_10;
  int local_c;
  
  local_18 = n;
  local_14 = buf;
  _dopr(&local_14,0,&local_18,&local_10,&local_c,format,args);
  if (local_c == 0) {
    local_10 = local_10 | (int)local_10 >> 0x1f;
  }
  else {
    local_10 = 0xffffffff;
  }
  return local_10;
}

