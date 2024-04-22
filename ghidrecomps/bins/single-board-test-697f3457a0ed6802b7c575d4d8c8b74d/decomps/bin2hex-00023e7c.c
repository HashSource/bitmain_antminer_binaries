
char * bin2hex(uchar *p,size_t len)

{
  char *s_00;
  size_t len_local;
  uchar *p_local;
  char *s;
  size_t slen;
  
  slen = len * 2 + 1;
  if ((slen & 3) != 0) {
    slen = (slen & 0xfffffffc) + 4;
  }
  s_00 = (char *)calloc(slen,1);
  if (s_00 == (char *)0x0) {
    fwrite("Failed to calloc",1,0x10,stderr);
  }
  __bin2hex(s_00,p,len);
  return s_00;
}

