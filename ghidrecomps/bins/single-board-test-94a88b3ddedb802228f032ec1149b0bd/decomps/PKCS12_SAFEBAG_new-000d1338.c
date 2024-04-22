
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

PKCS12_SAFEBAG * PKCS12_SAFEBAG_new(void)

{
  PKCS12_SAFEBAG *pPVar1;
  
  pPVar1 = (PKCS12_SAFEBAG *)ASN1_item_new(DAT_000d1340);
  return pPVar1;
}

