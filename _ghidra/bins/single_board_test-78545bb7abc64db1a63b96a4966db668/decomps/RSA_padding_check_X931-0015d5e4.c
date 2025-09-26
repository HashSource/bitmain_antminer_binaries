
int RSA_padding_check_X931(uchar *to,int tlen,uchar *f,int fl,int rsa_len)

{
  uchar uVar1;
  uchar *__src;
  uchar *puVar2;
  int iVar3;
  int iVar4;
  size_t __n;
  int iVar5;
  
  if ((rsa_len != fl) || (1 < *f - 0x6a)) {
    ERR_put_error(4,0x80,0x89,"crypto/rsa/rsa_x931.c",0x3d);
    return -1;
  }
  if (*f != 0x6b) {
    __src = f + 1;
    __n = rsa_len - 2;
LAB_0015d602:
    if (__src[__n] == 0xcc) {
      memcpy(to,__src,__n);
      return __n;
    }
    ERR_put_error(4,0x80,0x8b,"crypto/rsa/rsa_x931.c",0x59);
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
          iVar5 = iVar4;
          if (iVar3 == iVar4) {
LAB_0015d640:
            __n = iVar4 - iVar5;
            if (iVar5 != 0) goto LAB_0015d602;
            goto LAB_0015d646;
          }
          __src = puVar2 + 1;
          uVar1 = *puVar2;
          iVar5 = iVar3;
          if (uVar1 == 0xba) goto LAB_0015d640;
          puVar2 = __src;
        } while (uVar1 == 0xbb);
      }
      iVar4 = 0x48;
      goto LAB_0015d66e;
    }
  }
LAB_0015d646:
  iVar4 = 0x50;
LAB_0015d66e:
  ERR_put_error(4,0x80,0x8a,"crypto/rsa/rsa_x931.c",iVar4);
  return -1;
}

