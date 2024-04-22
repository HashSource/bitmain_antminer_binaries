
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EDIPARTYNAME * EDIPARTYNAME_new(void)

{
  EDIPARTYNAME *pEVar1;
  
  pEVar1 = (EDIPARTYNAME *)ASN1_item_new(DAT_000c8804);
  return pEVar1;
}

