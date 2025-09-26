
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

OCSP_SIGNATURE * OCSP_SIGNATURE_new(void)

{
  OCSP_SIGNATURE *pOVar1;
  
  pOVar1 = (OCSP_SIGNATURE *)ASN1_item_new((ASN1_ITEM *)&OCSP_SIGNATURE_it);
  return pOVar1;
}

