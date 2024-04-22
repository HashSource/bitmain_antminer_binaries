
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

DIST_POINT_NAME * DIST_POINT_NAME_new(void)

{
  DIST_POINT_NAME *pDVar1;
  
  pDVar1 = (DIST_POINT_NAME *)ASN1_item_new(DAT_000cafbc);
  return pDVar1;
}

