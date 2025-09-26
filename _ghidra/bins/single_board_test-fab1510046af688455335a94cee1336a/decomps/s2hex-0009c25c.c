
int s2hex(uchar *dst,uchar *src,int inlen)

{
  uchar uVar1;
  int iVar2;
  uint uVar3;
  int inlen_local;
  uchar *src_local;
  uchar *dst_local;
  char tmp42 [256];
  uchar low;
  uchar high;
  int p;
  int len;
  int i;
  
  if (((src == (uchar *)0x0) || (inlen < 1)) || (dst == (uchar *)0x0)) {
    snprintf(tmp42,0x100,"s2hex para 3 dst(%p), src(%p), inlen(%d)\n",dst,src,inlen);
    puts(tmp42);
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

