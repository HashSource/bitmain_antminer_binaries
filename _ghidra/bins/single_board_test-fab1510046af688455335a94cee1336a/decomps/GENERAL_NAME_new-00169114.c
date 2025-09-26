
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

GENERAL_NAME * GENERAL_NAME_new(void)

{
  GENERAL_NAME *pGVar1;
  
  pGVar1 = (GENERAL_NAME *)ASN1_item_new((ASN1_ITEM *)&GENERAL_NAME_it);
  return pGVar1;
}

