
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

OCSP_REQUEST * OCSP_REQUEST_new(void)

{
  OCSP_REQUEST *pOVar1;
  
  pOVar1 = (OCSP_REQUEST *)ASN1_item_new(DAT_000d2700);
  return pOVar1;
}

