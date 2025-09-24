
IPAddressChoice * d2i_IPAddressChoice(IPAddressChoice **a,uchar **in,long len)

{
  IPAddressChoice *pIVar1;
  
  pIVar1 = (IPAddressChoice *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)IPAddressChoice_it)
  ;
  return pIVar1;
}

