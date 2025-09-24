
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

IPAddressChoice * IPAddressChoice_new(void)

{
  IPAddressChoice *pIVar1;
  
  pIVar1 = (IPAddressChoice *)ASN1_item_new((ASN1_ITEM *)IPAddressChoice_it);
  return pIVar1;
}

