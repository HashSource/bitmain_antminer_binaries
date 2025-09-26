
IPAddressOrRange * d2i_IPAddressOrRange(IPAddressOrRange **a,uchar **in,long len)

{
  IPAddressOrRange *pIVar1;
  
  pIVar1 = (IPAddressOrRange *)
           ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)IPAddressOrRange_it);
  return pIVar1;
}

