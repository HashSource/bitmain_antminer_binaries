
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

IPAddressOrRange * IPAddressOrRange_new(void)

{
  IPAddressOrRange *pIVar1;
  
  pIVar1 = (IPAddressOrRange *)ASN1_item_new((ASN1_ITEM *)IPAddressOrRange_it);
  return pIVar1;
}

