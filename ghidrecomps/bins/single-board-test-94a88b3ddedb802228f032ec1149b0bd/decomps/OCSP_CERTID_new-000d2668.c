
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

OCSP_CERTID * OCSP_CERTID_new(void)

{
  OCSP_CERTID *pOVar1;
  
  pOVar1 = (OCSP_CERTID *)ASN1_item_new(DAT_000d2670);
  return pOVar1;
}

