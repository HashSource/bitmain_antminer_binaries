
OCSP_REQ_CTX * OCSP_sendreq_new(BIO *io,char *path,OCSP_REQUEST *req,int maxline)

{
  OCSP_REQ_CTX *ptr;
  BIO_METHOD *type;
  BIO *pBVar1;
  void *ptr_00;
  int iVar2;
  char *pcVar3;
  
  iVar2 = maxline;
  ptr = (OCSP_REQ_CTX *)CRYPTO_malloc(0x1c,"ocsp_ht.c",0x78);
  if (ptr == (OCSP_REQ_CTX *)0x0) {
    return (OCSP_REQ_CTX *)0x0;
  }
  *(undefined4 *)ptr = 0x1000;
  if (maxline < 1) {
    maxline = 0x1000;
  }
  *(undefined4 *)(ptr + 0x18) = 0x19000;
  type = BIO_s_mem();
  pBVar1 = BIO_new(type);
  *(int *)(ptr + 8) = maxline;
  *(BIO **)(ptr + 0x10) = pBVar1;
  *(BIO **)(ptr + 0xc) = io;
  *(undefined4 *)(ptr + 0x14) = 0;
  ptr_00 = CRYPTO_malloc(maxline,"ocsp_ht.c",0x84);
  *(void **)(ptr + 4) = ptr_00;
  if (ptr_00 == (void *)0x0) {
    if (*(BIO **)(ptr + 0x10) == (BIO *)0x0) goto LAB_000d2b6e;
    BIO_free(*(BIO **)(ptr + 0x10));
    ptr_00 = *(void **)(ptr + 4);
    if (ptr_00 == (void *)0x0) goto LAB_000d2b6e;
  }
  else if (*(BIO **)(ptr + 0x10) != (BIO *)0x0) {
    pcVar3 = "/";
    if (path != (char *)0x0) {
      pcVar3 = path;
    }
    iVar2 = BIO_printf(*(BIO **)(ptr + 0x10),"%s %s HTTP/1.0\r\n","POST",pcVar3,iVar2);
    if (0 < iVar2) {
      *(undefined4 *)ptr = 0x1009;
      if (req == (OCSP_REQUEST *)0x0) {
        return ptr;
      }
      iVar2 = ASN1_item_i2d((ASN1_VALUE *)req,(uchar **)0x0,(ASN1_ITEM *)OCSP_REQUEST_it);
      iVar2 = BIO_printf(*(BIO **)(ptr + 0x10),
                         "Content-Type: application/ocsp-request\r\nContent-Length: %d\r\n\r\n",
                         iVar2);
      if ((0 < iVar2) &&
         (iVar2 = ASN1_item_i2d_bio((ASN1_ITEM *)OCSP_REQUEST_it,*(BIO **)(ptr + 0x10),req),
         0 < iVar2)) {
        *(undefined4 *)ptr = 0x1005;
        return ptr;
      }
    }
    if (*(BIO **)(ptr + 0x10) != (BIO *)0x0) {
      BIO_free(*(BIO **)(ptr + 0x10));
    }
    if (*(void **)(ptr + 4) != (void *)0x0) {
      CRYPTO_free(*(void **)(ptr + 4));
    }
    CRYPTO_free(ptr);
    return (OCSP_REQ_CTX *)0x0;
  }
  CRYPTO_free(ptr_00);
LAB_000d2b6e:
  CRYPTO_free(ptr);
  return (OCSP_REQ_CTX *)0x0;
}

