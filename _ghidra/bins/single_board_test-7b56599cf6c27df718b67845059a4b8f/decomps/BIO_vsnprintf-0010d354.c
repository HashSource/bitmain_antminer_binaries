
int BIO_vsnprintf(char *buf,size_t n,char *format,va_list args)

{
  int iVar1;
  size_t local_18;
  char *local_14;
  uint local_10;
  int local_c [2];
  
  local_18 = n;
  local_14 = buf;
  iVar1 = _dopr(&local_14,0,&local_18,&local_10,local_c,format,args);
  if ((iVar1 == 0) || (local_c[0] != 0)) {
    local_10 = 0xffffffff;
  }
  else {
    local_10 = local_10 | (int)local_10 >> 0x1f;
  }
  return local_10;
}

