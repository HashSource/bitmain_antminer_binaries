
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

OCSP_CERTSTATUS * OCSP_CERTSTATUS_new(void)

{
  OCSP_CERTSTATUS *pOVar1;
  
  pOVar1 = (OCSP_CERTSTATUS *)ASN1_item_new(DAT_000d27f0);
  return pOVar1;
}

