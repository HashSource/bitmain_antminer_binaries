
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

OCSP_REQINFO * OCSP_REQINFO_new(void)

{
  OCSP_REQINFO *pOVar1;
  
  pOVar1 = (OCSP_REQINFO *)ASN1_item_new(DAT_000d26d0);
  return pOVar1;
}

