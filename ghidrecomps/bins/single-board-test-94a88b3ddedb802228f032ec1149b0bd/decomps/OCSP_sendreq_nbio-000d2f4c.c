
int OCSP_sendreq_nbio(OCSP_RESPONSE **presp,OCSP_REQ_CTX *rctx)

{
  int iVar1;
  long len;
  OCSP_RESPONSE *pOVar2;
  uchar *puStack_14;
  
  iVar1 = OCSP_REQ_CTX_nbio(rctx);
  if (iVar1 == 1) {
    len = BIO_ctrl(*(BIO **)(rctx + 0x10),3,0,&puStack_14);
    pOVar2 = (OCSP_RESPONSE *)ASN1_item_d2i((ASN1_VALUE **)0x0,&puStack_14,len,DAT_000d2f90);
    *presp = pOVar2;
    if (pOVar2 == (OCSP_RESPONSE *)0x0) {
      *(undefined4 *)rctx = 0x1000;
      iVar1 = 0;
    }
  }
  return iVar1;
}

