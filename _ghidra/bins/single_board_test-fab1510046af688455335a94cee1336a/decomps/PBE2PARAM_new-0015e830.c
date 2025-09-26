
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

PBE2PARAM * PBE2PARAM_new(void)

{
  PBE2PARAM *pPVar1;
  
  pPVar1 = (PBE2PARAM *)ASN1_item_new((ASN1_ITEM *)&PBE2PARAM_it);
  return pPVar1;
}

