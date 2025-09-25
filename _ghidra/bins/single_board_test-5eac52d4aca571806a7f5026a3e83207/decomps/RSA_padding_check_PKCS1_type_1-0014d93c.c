
int RSA_padding_check_PKCS1_type_1(uchar *to,int tlen,uchar *f,int fl,int rsa_len)

{
  uchar *puVar1;
  int iVar2;
  int iVar3;
  size_t __n;
  uchar uVar4;
  uchar *puVar5;
  
  if (rsa_len < 0xb) {
    return -1;
  }
  if (rsa_len == fl) {
    uVar4 = *f;
    f = f + 1;
    if (uVar4 != '\0') {
      ERR_put_error(4,0x70,0x8a,"crypto/rsa/rsa_pk1.c",0x43);
      return -1;
    }
    fl = rsa_len + -1;
  }
  if ((rsa_len != fl + 1) || (puVar5 = f + 1, *f != '\x01')) {
    ERR_put_error(4,0x70,0x6a,"crypto/rsa/rsa_pk1.c",0x4b);
    return -1;
  }
  iVar2 = fl + -1;
  if (iVar2 < 1) {
    if (iVar2 == 0) {
LAB_0014d97c:
      ERR_put_error(4,0x70,0x71,"crypto/rsa/rsa_pk1.c",0x61);
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
        if (iVar3 == iVar2) goto LAB_0014d97c;
        uVar4 = *puVar5;
        puVar1 = puVar5 + 1;
      } while (uVar4 == 0xff);
    }
    else {
      iVar3 = 0;
    }
    if (uVar4 != '\0') {
      ERR_put_error(4,0x70,0x66,"crypto/rsa/rsa_pk1.c",0x58);
      return -1;
    }
    if (7 < iVar3) {
      __n = iVar2 - (iVar3 + 1);
      if ((int)__n <= tlen) {
        memcpy(to,puVar5 + 1,__n);
        return __n;
      }
      iVar2 = 0x6d;
      goto LAB_0014d9e2;
    }
  }
  iVar2 = 0x67;
LAB_0014d9e2:
  ERR_put_error(4,0x70,iVar2,"crypto/rsa/rsa_pk1.c",iVar2);
  return -1;
}

