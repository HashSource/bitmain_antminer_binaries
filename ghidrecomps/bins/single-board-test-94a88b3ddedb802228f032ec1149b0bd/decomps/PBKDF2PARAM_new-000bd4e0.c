
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

PBKDF2PARAM * PBKDF2PARAM_new(void)

{
  PBKDF2PARAM *pPVar1;
  
  pPVar1 = (PBKDF2PARAM *)ASN1_item_new(DAT_000bd4e8);
  return pPVar1;
}

