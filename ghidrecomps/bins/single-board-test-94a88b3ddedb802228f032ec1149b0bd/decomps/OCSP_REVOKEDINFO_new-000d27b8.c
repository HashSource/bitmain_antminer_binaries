
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

OCSP_REVOKEDINFO * OCSP_REVOKEDINFO_new(void)

{
  OCSP_REVOKEDINFO *pOVar1;
  
  pOVar1 = (OCSP_REVOKEDINFO *)ASN1_item_new((ASN1_ITEM *)OCSP_REVOKEDINFO_it);
  return pOVar1;
}

