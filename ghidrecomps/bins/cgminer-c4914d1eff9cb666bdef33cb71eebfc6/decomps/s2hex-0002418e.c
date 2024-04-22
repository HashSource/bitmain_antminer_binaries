
int s2hex(uchar *dst,uchar *src,int inlen)

{
  uchar uVar1;
  FILE *__stream;
  int iVar2;
  uint uVar3;
  int inlen_local;
  uchar *src_local;
  uchar *dst_local;
  FILE *pFile;
  uchar low;
  uchar high;
  int p;
  int len;
  int i;
  
  if (((src == (uchar *)0x0) || (inlen < 1)) || (dst == (uchar *)0x0)) {
    if (4 < log_level) {
      print_crt_time_to_file(log_file,4);
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: s2hex para error dst(%p), src(%p), inlen(%d)\n",
                "driver-btm-soc.c",0x1307,"s2hex",dst,src,inlen);
      }
      fclose(__stream);
    }
    iVar2 = -1;
  }
  else {
    uVar3 = inlen & 1;
    if (inlen < 0) {
      uVar3 = -uVar3;
    }
    for (i = 0; i < inlen / 2; i = i + 1) {
      uVar1 = twoc2hex(src[i * 2],src[i * 2 + 1]);
      dst[i] = uVar1;
    }
    if (uVar3 != 0) {
      uVar1 = twoc2hex(src[i * 2],'\0');
      dst[i] = uVar1;
    }
    iVar2 = uVar3 + inlen / 2;
  }
  return iVar2;
}

