
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

OCSP_CRLID * OCSP_CRLID_new(void)

{
  OCSP_CRLID *pOVar1;
  
  pOVar1 = (OCSP_CRLID *)ASN1_item_new((ASN1_ITEM *)OCSP_CRLID_it);
  return pOVar1;
}

