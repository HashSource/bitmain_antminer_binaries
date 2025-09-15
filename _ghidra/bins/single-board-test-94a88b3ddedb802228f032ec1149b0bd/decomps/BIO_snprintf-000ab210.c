
int BIO_snprintf(char *buf,size_t n,char *format,...)

{
  undefined4 in_r3;
  char *local_28;
  size_t local_24;
  uint local_20;
  int local_1c;
  undefined4 uStack_4;
  
  local_28 = buf;
  local_24 = n;
  uStack_4 = in_r3;
  _dopr(&local_28,0,&local_24,&local_20,&local_1c,format,&uStack_4);
  if (local_1c == 0) {
    local_20 = local_20 | (int)local_20 >> 0x1f;
  }
  else {
    local_20 = 0xffffffff;
  }
  return local_20;
}

