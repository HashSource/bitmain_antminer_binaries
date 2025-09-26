
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

OCSP_RESPDATA * OCSP_RESPDATA_new(void)

{
  OCSP_RESPDATA *pOVar1;
  
  pOVar1 = (OCSP_RESPDATA *)ASN1_item_new((ASN1_ITEM *)OCSP_RESPDATA_it);
  return pOVar1;
}

