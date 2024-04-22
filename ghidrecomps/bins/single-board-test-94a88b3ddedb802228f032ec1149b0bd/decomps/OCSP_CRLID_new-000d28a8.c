
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

OCSP_CRLID * OCSP_CRLID_new(void)

{
  OCSP_CRLID *pOVar1;
  
  pOVar1 = (OCSP_CRLID *)ASN1_item_new(DAT_000d28b0);
  return pOVar1;
}

