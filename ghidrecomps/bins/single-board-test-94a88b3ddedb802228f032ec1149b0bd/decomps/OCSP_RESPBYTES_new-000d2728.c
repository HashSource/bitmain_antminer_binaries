
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

OCSP_RESPBYTES * OCSP_RESPBYTES_new(void)

{
  OCSP_RESPBYTES *pOVar1;
  
  pOVar1 = (OCSP_RESPBYTES *)ASN1_item_new(DAT_000d2730);
  return pOVar1;
}

