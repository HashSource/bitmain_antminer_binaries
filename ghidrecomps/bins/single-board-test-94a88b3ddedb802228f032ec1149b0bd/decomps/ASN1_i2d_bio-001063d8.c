
int ASN1_i2d_bio(undefined1 *i2d,BIO *out,uchar *x)

{
  int iVar1;
  void *ptr;
  int iVar2;
  int iVar3;
  bool bVar4;
  void *local_24 [2];
  
  iVar1 = (*(code *)i2d)(x,0);
  ptr = CRYPTO_malloc(iVar1,DAT_00106448,0x5a);
  if (ptr == (void *)0x0) {
    ERR_put_error(0xd,0x74,0x41,DAT_00106448,0x5c);
    iVar1 = 0;
  }
  else {
    iVar3 = 0;
    local_24[0] = ptr;
    (*(code *)i2d)(x,local_24);
    do {
      iVar2 = BIO_write(out,(void *)((int)ptr + iVar3),iVar1);
      bVar4 = iVar2 == iVar1;
      iVar3 = iVar3 + iVar2;
      iVar1 = iVar1 - iVar2;
      if (bVar4) {
        iVar1 = 1;
        goto LAB_00106420;
      }
    } while (0 < iVar2);
    iVar1 = 0;
LAB_00106420:
    CRYPTO_free(ptr);
  }
  return iVar1;
}

