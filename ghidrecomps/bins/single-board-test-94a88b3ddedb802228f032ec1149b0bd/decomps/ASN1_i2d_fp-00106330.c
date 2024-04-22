
int ASN1_i2d_fp(undefined1 *i2d,FILE *out,void *x)

{
  BIO_METHOD *type;
  BIO *bp;
  int iVar1;
  void *ptr;
  int iVar2;
  int iVar3;
  bool bVar4;
  void *local_24 [2];
  
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0xd,0x75,7,DAT_001063d4,0x49);
    iVar1 = 0;
  }
  else {
    BIO_ctrl(bp,0x6a,0,out);
    iVar1 = (*(code *)i2d)(x,0);
    ptr = CRYPTO_malloc(iVar1,DAT_001063d4,0x5a);
    if (ptr == (void *)0x0) {
      ERR_put_error(0xd,0x74,0x41,DAT_001063d4,0x5c);
      iVar1 = 0;
    }
    else {
      iVar3 = 0;
      local_24[0] = ptr;
      (*(code *)i2d)(x,local_24);
      do {
        iVar2 = BIO_write(bp,(void *)((int)ptr + iVar3),iVar1);
        bVar4 = iVar1 == iVar2;
        iVar3 = iVar3 + iVar2;
        iVar1 = iVar1 - iVar2;
        if (bVar4) {
          iVar1 = 1;
          goto LAB_00106392;
        }
      } while (0 < iVar2);
      iVar1 = 0;
LAB_00106392:
      CRYPTO_free(ptr);
    }
    BIO_free(bp);
  }
  return iVar1;
}

