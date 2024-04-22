
int s2hex(uchar *dst,uchar *src,int inlen)

{
  uchar uVar1;
  int iVar2;
  int inlen_local;
  uchar *src_local;
  uchar *dst_local;
  char tmp42 [2048];
  uchar low;
  uchar high;
  int p;
  int len;
  int i;
  
  if (((src == (uchar *)0x0) || (inlen < 1)) || (dst == (uchar *)0x0)) {
    if ((opt_debug) && (((use_syslog || (opt_log_output)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"s2hex para error dst(%p), src(%p), inlen(%d)\n",dst,src,inlen);
      _applog(7,tmp42,false);
    }
    iVar2 = -1;
  }
  else {
    for (i = 0; i < inlen / 2; i = i + 1) {
      uVar1 = twoc2hex(src[i * 2],src[i * 2 + 1]);
      dst[i] = uVar1;
    }
    if (inlen % 2 != 0) {
      uVar1 = twoc2hex(src[i * 2],'\0');
      dst[i] = uVar1;
    }
    iVar2 = inlen / 2 + inlen % 2;
  }
  return iVar2;
}

