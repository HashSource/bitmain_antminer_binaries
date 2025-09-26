
IPAddressRange * d2i_IPAddressRange(IPAddressRange **a,uchar **in,long len)

{
  IPAddressRange *pIVar1;
  
  pIVar1 = (IPAddressRange *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)IPAddressRange_it);
  return pIVar1;
}

