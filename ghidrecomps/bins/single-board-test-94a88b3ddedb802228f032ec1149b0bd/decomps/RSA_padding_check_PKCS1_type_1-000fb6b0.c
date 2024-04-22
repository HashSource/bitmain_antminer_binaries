
int RSA_padding_check_PKCS1_type_1(uchar *to,int tlen,uchar *f,int fl,int rsa_len)

{
  uchar *puVar1;
  int iVar2;
  int iVar3;
  size_t __n;
  uchar uVar4;
  uchar *puVar5;
  
  if ((fl + 1 != rsa_len) || (puVar5 = f + 1, *f != '\x01')) {
    ERR_put_error(4,0x70,0x6a,DAT_000fb77c,0x67);
    return -1;
  }
  iVar2 = fl + -1;
  if (iVar2 < 1) {
    if (iVar2 == 0) {
LAB_000fb6e8:
      ERR_put_error(4,0x70,0x71,DAT_000fb77c,0x7d);
      return -1;
    }
  }
  else {
    uVar4 = f[1];
    if (uVar4 == 0xff) {
      iVar3 = 0;
      puVar1 = f + 2;
      do {
        puVar5 = puVar1;
        iVar3 = iVar3 + 1;
        if (iVar2 == iVar3) goto LAB_000fb6e8;
        uVar4 = *puVar5;
        puVar1 = puVar5 + 1;
      } while (uVar4 == 0xff);
    }
    else {
      iVar3 = 0;
    }
    if (uVar4 != '\0') {
      ERR_put_error(4,0x70,0x66,DAT_000fb77c,0x74);
      return -1;
    }
    if (7 < iVar3) {
      __n = iVar2 - (iVar3 + 1);
      if ((int)__n <= tlen) {
        memcpy(to,puVar5 + 1,__n);
        return __n;
      }
      ERR_put_error(4,0x70,0x6d,DAT_000fb77c,0x89);
      return -1;
    }
  }
  ERR_put_error(4,0x70,0x67,DAT_000fb77c,0x83);
  return -1;
}

