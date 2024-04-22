
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

OCSP_SINGLERESP * OCSP_SINGLERESP_new(void)

{
  OCSP_SINGLERESP *pOVar1;
  
  pOVar1 = (OCSP_SINGLERESP *)ASN1_item_new(DAT_000d2820);
  return pOVar1;
}

