
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

OCSP_ONEREQ * OCSP_ONEREQ_new(void)

{
  OCSP_ONEREQ *pOVar1;
  
  pOVar1 = (OCSP_ONEREQ *)ASN1_item_new((ASN1_ITEM *)OCSP_ONEREQ_it);
  return pOVar1;
}

