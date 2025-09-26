
int ASN1_i2d_bio(undefined1 *i2d,BIO *out,uchar *x)

{
  int iVar1;
  void *ptr;
  int iVar2;
  int iVar3;
  bool bVar4;
  void *local_24 [2];
  
  iVar1 = (*(code *)i2d)(x,0);
  if (iVar1 < 1) {
    iVar1 = 0;
  }
  else {
    ptr = CRYPTO_malloc(iVar1,"crypto/asn1/a_i2d_fp.c",0x2c);
    if (ptr == (void *)0x0) {
      ERR_put_error(0xd,0x74,0x41,"crypto/asn1/a_i2d_fp.c",0x2e);
      iVar1 = 0;
    }
    else {
      iVar3 = 0;
      local_24[0] = ptr;
      (*(code *)i2d)(x,local_24);
      do {
        iVar2 = BIO_write(out,(void *)((int)ptr + iVar3),iVar1);
        bVar4 = iVar1 == iVar2;
        iVar3 = iVar3 + iVar2;
        iVar1 = iVar1 - iVar2;
        if (bVar4) {
          iVar1 = 1;
          goto LAB_00187bae;
        }
      } while (0 < iVar2);
      iVar1 = 0;
LAB_00187bae:
      CRYPTO_free(ptr);
    }
  }
  return iVar1;
}

