
PKCS12_SAFEBAG * d2i_PKCS12_SAFEBAG(PKCS12_SAFEBAG **a,uchar **in,long len)

{
  PKCS12_SAFEBAG *pPVar1;
  
  pPVar1 = (PKCS12_SAFEBAG *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,DAT_000d1328);
  return pPVar1;
}

