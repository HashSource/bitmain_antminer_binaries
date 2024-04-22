
NETSCAPE_SPKI * d2i_NETSCAPE_SPKI(NETSCAPE_SPKI **a,uchar **in,long len)

{
  NETSCAPE_SPKI *pNVar1;
  
  pNVar1 = (NETSCAPE_SPKI *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,DAT_00107f74);
  return pNVar1;
}

