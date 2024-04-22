
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

OCSP_SERVICELOC * OCSP_SERVICELOC_new(void)

{
  OCSP_SERVICELOC *pOVar1;
  
  pOVar1 = (OCSP_SERVICELOC *)ASN1_item_new(DAT_000d28e0);
  return pOVar1;
}

