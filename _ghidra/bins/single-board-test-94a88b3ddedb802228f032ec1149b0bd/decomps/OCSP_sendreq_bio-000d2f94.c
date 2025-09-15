
OCSP_RESPONSE * OCSP_sendreq_bio(BIO *b,char *path,OCSP_REQUEST *req)

{
  OCSP_REQ_CTX *ptr;
  int iVar1;
  int iVar2;
  long len;
  OCSP_RESPONSE *pOVar3;
  uchar *puStack_14;
  
  ptr = OCSP_sendreq_new(b,path,req,-1);
  if (ptr != (OCSP_REQ_CTX *)0x0) {
    do {
      iVar2 = OCSP_REQ_CTX_nbio(ptr);
      if (iVar2 == 1) {
        len = BIO_ctrl(*(BIO **)(ptr + 0x10),3,0,&puStack_14);
        pOVar3 = (OCSP_RESPONSE *)
                 ASN1_item_d2i((ASN1_VALUE **)0x0,&puStack_14,len,(ASN1_ITEM *)OCSP_RESPONSE_it);
        if (pOVar3 == (OCSP_RESPONSE *)0x0) {
          *(undefined4 *)ptr = 0x1000;
          iVar2 = 0;
        }
        goto LAB_000d2fe0;
      }
      if (iVar2 != -1) {
        pOVar3 = (OCSP_RESPONSE *)0x0;
        goto LAB_000d2fe0;
      }
      iVar1 = BIO_test_flags(b,8);
    } while (iVar1 != 0);
    pOVar3 = (OCSP_RESPONSE *)0x0;
LAB_000d2fe0:
    if (*(BIO **)(ptr + 0x10) != (BIO *)0x0) {
      BIO_free(*(BIO **)(ptr + 0x10));
    }
    if (*(void **)(ptr + 4) != (void *)0x0) {
      CRYPTO_free(*(void **)(ptr + 4));
    }
    CRYPTO_free(ptr);
    if (iVar2 != 0) {
      return pOVar3;
    }
  }
  return (OCSP_RESPONSE *)0x0;
}

