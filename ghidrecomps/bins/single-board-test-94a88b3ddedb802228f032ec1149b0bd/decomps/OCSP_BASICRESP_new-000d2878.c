
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

OCSP_BASICRESP * OCSP_BASICRESP_new(void)

{
  OCSP_BASICRESP *pOVar1;
  
  pOVar1 = (OCSP_BASICRESP *)ASN1_item_new(DAT_000d2880);
  return pOVar1;
}

