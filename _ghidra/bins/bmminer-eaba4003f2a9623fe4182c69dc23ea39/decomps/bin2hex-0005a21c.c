
char * bin2hex(uchar *p,size_t len)

{
  char *s_00;
  size_t len_local;
  uchar *p_local;
  char *s;
  ssize_t slen;
  
  slen = len * 2 + 1;
  if ((slen & 3U) != 0) {
    slen = slen + (4 - slen % 4);
  }
  s_00 = (char *)_cgcalloc(slen,1,"util.c","bin2hex",0x315);
  __bin2hex(s_00,p,len);
  return s_00;
}

