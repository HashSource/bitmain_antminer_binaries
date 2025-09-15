
char * bin2hex(uchar *p,size_t len)

{
  char *s_00;
  uint uVar1;
  size_t len_local;
  uchar *p_local;
  char *s;
  ssize_t slen;
  
  slen = len * 2 + 1;
  if ((slen & 3U) != 0) {
    uVar1 = slen & 3;
    if (slen < 1) {
      uVar1 = -(-slen & 3U);
    }
    slen = slen + (4 - uVar1);
  }
  s_00 = (char *)_cgcalloc(slen,1,"util.c","bin2hex",0x31e);
  __bin2hex(s_00,p,len);
  return s_00;
}

