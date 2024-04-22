
int RSA_padding_check_X931(uchar *to,int tlen,uchar *f,int fl,int rsa_len)

{
  uchar uVar1;
  uchar *__src;
  uchar *puVar2;
  int iVar3;
  size_t __n;
  int iVar4;
  
  if ((rsa_len != fl) || (1 < *f - 0x6a)) {
    ERR_put_error(4,0x80,0x89,DAT_000fc5c0,0x70);
    return -1;
  }
  if (*f != 0x6b) {
    __src = f + 1;
    __n = rsa_len - 2;
LAB_000fc536:
    if (__src[__n] == 0xcc) {
      memcpy(to,__src,__n);
      return __n;
    }
    ERR_put_error(4,0x80,0x8b,DAT_000fc5c0,0x8b);
    return -1;
  }
  iVar4 = rsa_len + -3;
  if (0 < iVar4) {
    if (f[1] != 0xba) {
      if (f[1] == 0xbb) {
        iVar3 = 0;
        puVar2 = f + 2;
        do {
          iVar3 = iVar3 + 1;
          __src = puVar2;
          if (iVar4 == iVar3) {
LAB_000fc576:
            __n = iVar4 - iVar3;
            if (iVar3 != 0) goto LAB_000fc536;
            goto LAB_000fc57c;
          }
          __src = puVar2 + 1;
          uVar1 = *puVar2;
          if (uVar1 == 0xba) goto LAB_000fc576;
          puVar2 = __src;
        } while (uVar1 == 0xbb);
      }
      iVar4 = 0x7b;
      goto LAB_000fc598;
    }
  }
LAB_000fc57c:
  iVar4 = 0x83;
LAB_000fc598:
  ERR_put_error(4,0x80,0x8a,DAT_000fc5c0,iVar4);
  return -1;
}

