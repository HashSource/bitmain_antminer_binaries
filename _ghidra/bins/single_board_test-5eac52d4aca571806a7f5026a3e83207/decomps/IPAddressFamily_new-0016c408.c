
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

IPAddressFamily * IPAddressFamily_new(void)

{
  IPAddressFamily *pIVar1;
  
  pIVar1 = (IPAddressFamily *)ASN1_item_new((ASN1_ITEM *)IPAddressFamily_it);
  return pIVar1;
}

