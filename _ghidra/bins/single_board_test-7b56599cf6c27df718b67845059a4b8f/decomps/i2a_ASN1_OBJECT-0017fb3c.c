
int i2a_ASN1_OBJECT(BIO *bp,ASN1_OBJECT *a)

{
  int iVar1;
  int iVar2;
  char *buf;
  char acStack_70 [80];
  
  if ((a == (ASN1_OBJECT *)0x0) || (a->data == (uchar *)0x0)) {
    iVar1 = BIO_write(bp,"NULL",4);
  }
  else {
    iVar1 = i2t_ASN1_OBJECT(acStack_70,0x50,a);
    if (iVar1 < 0x50) {
      if (iVar1 < 1) {
        iVar1 = BIO_write(bp,"<INVALID>",9);
        iVar2 = BIO_dump(bp,(char *)a->data,a->length);
        return iVar2 + iVar1;
      }
      BIO_write(bp,acStack_70,iVar1);
      return iVar1;
    }
    buf = (char *)CRYPTO_malloc(iVar1 + 1,"crypto/asn1/a_object.c",0xc2);
    if (buf != (char *)0x0) {
      i2t_ASN1_OBJECT(buf,iVar1 + 1,a);
      BIO_write(bp,buf,iVar1);
      if (buf != acStack_70) {
        CRYPTO_free(buf);
      }
      return iVar1;
    }
    ERR_put_error(0xd,0x7e,0x41,"crypto/asn1/a_object.c",0xc3);
    iVar1 = -1;
  }
  return iVar1;
}

