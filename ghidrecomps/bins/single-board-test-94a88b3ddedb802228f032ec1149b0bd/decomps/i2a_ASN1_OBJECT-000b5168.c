
int i2a_ASN1_OBJECT(BIO *bp,ASN1_OBJECT *a)

{
  int len;
  char *buf;
  char acStack_70 [84];
  
  if ((a == (ASN1_OBJECT *)0x0) || (a->data == (uchar *)0x0)) {
    len = BIO_write(bp,DAT_000b51f4,4);
  }
  else {
    len = OBJ_obj2txt(acStack_70,0x50,a,0);
    if (len < 0x50) {
      if (len < 1) {
        len = BIO_write(bp,DAT_000b51fc,9);
      }
      else {
        BIO_write(bp,acStack_70,len);
      }
    }
    else {
      buf = (char *)CRYPTO_malloc(len + 1,DAT_000b51f8,0xe3);
      if (buf == (char *)0x0) {
        len = -1;
      }
      else {
        OBJ_obj2txt(buf,len + 1,a,0);
        BIO_write(bp,buf,len);
        if (buf != acStack_70) {
          CRYPTO_free(buf);
        }
      }
    }
  }
  return len;
}

