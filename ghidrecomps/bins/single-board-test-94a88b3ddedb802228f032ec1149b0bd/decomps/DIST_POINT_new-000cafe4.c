
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

DIST_POINT * DIST_POINT_new(void)

{
  DIST_POINT *pDVar1;
  
  pDVar1 = (DIST_POINT *)ASN1_item_new(DAT_000cafec);
  return pDVar1;
}

