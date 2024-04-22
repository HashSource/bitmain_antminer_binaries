
int OCSP_REQ_CTX_nbio_d2i(undefined4 *param_1,ASN1_VALUE **param_2,ASN1_ITEM *param_3)

{
  int iVar1;
  long len;
  ASN1_VALUE *pAVar2;
  uchar *apuStack_1c [2];
  
  iVar1 = OCSP_REQ_CTX_nbio();
  if (iVar1 == 1) {
    len = BIO_ctrl((BIO *)param_1[4],3,0,apuStack_1c);
    pAVar2 = ASN1_item_d2i((ASN1_VALUE **)0x0,apuStack_1c,len,param_3);
    *param_2 = pAVar2;
    if (pAVar2 == (ASN1_VALUE *)0x0) {
      *param_1 = 0x1000;
      iVar1 = 0;
    }
  }
  return iVar1;
}

