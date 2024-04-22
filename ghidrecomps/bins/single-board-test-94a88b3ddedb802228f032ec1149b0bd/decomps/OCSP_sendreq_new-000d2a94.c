
OCSP_REQ_CTX * OCSP_sendreq_new(BIO *io,char *path,OCSP_REQUEST *req,int maxline)

{
  undefined4 *ptr;
  BIO_METHOD *type;
  BIO *pBVar1;
  void *ptr_00;
  int iVar2;
  char *pcVar3;
  
  iVar2 = maxline;
  ptr = (undefined4 *)CRYPTO_malloc(0x1c,DAT_000d2b78,0x78);
  if (ptr == (undefined4 *)0x0) {
    return (OCSP_REQ_CTX *)0x0;
  }
  *ptr = 0x1000;
  if (maxline < 1) {
    maxline = 0x1000;
  }
  ptr[6] = 0x19000;
  type = BIO_s_mem();
  pBVar1 = BIO_new(type);
  ptr[2] = maxline;
  ptr[4] = pBVar1;
  ptr[3] = io;
  ptr[5] = 0;
  ptr_00 = CRYPTO_malloc(maxline,DAT_000d2b78,0x84);
  ptr[1] = ptr_00;
  if (ptr_00 == (void *)0x0) {
    if ((BIO *)ptr[4] == (BIO *)0x0) goto LAB_000d2b6e;
    BIO_free((BIO *)ptr[4]);
    ptr_00 = (void *)ptr[1];
    if (ptr_00 == (void *)0x0) goto LAB_000d2b6e;
  }
  else if ((BIO *)ptr[4] != (BIO *)0x0) {
    pcVar3 = DAT_000d2b7c;
    if (path != (char *)0x0) {
      pcVar3 = path;
    }
    iVar2 = BIO_printf((BIO *)ptr[4],DAT_000d2b80,DAT_000d2b84,pcVar3,iVar2);
    if (0 < iVar2) {
      *ptr = 0x1009;
      if (req == (OCSP_REQUEST *)0x0) {
        return (OCSP_REQ_CTX *)ptr;
      }
      iVar2 = ASN1_item_i2d((ASN1_VALUE *)req,(uchar **)0x0,DAT_000d2b88);
      iVar2 = BIO_printf((BIO *)ptr[4],DAT_000d2b8c,iVar2);
      if ((0 < iVar2) && (iVar2 = ASN1_item_i2d_bio(DAT_000d2b88,(BIO *)ptr[4],req), 0 < iVar2)) {
        *ptr = 0x1005;
        return (OCSP_REQ_CTX *)ptr;
      }
    }
    if ((BIO *)ptr[4] != (BIO *)0x0) {
      BIO_free((BIO *)ptr[4]);
    }
    if ((void *)ptr[1] != (void *)0x0) {
      CRYPTO_free((void *)ptr[1]);
    }
    CRYPTO_free(ptr);
    return (OCSP_REQ_CTX *)0x0;
  }
  CRYPTO_free(ptr_00);
LAB_000d2b6e:
  CRYPTO_free(ptr);
  return (OCSP_REQ_CTX *)0x0;
}

