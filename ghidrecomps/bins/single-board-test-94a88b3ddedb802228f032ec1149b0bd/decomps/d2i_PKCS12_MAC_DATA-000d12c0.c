
PKCS12_MAC_DATA * d2i_PKCS12_MAC_DATA(PKCS12_MAC_DATA **a,uchar **in,long len)

{
  PKCS12_MAC_DATA *pPVar1;
  
  pPVar1 = (PKCS12_MAC_DATA *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,DAT_000d12c8);
  return pPVar1;
}

