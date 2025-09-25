
IPAddressFamily * d2i_IPAddressFamily(IPAddressFamily **a,uchar **in,long len)

{
  IPAddressFamily *pIVar1;
  
  pIVar1 = (IPAddressFamily *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)IPAddressFamily_it)
  ;
  return pIVar1;
}

