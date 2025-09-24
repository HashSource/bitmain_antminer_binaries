
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

IPAddressRange * IPAddressRange_new(void)

{
  IPAddressRange *pIVar1;
  
  pIVar1 = (IPAddressRange *)ASN1_item_new((ASN1_ITEM *)IPAddressRange_it);
  return pIVar1;
}

