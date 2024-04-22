
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

GENERAL_NAMES * GENERAL_NAMES_new(void)

{
  GENERAL_NAMES *pGVar1;
  
  pGVar1 = (GENERAL_NAMES *)ASN1_item_new(DAT_000c884c);
  return pGVar1;
}

