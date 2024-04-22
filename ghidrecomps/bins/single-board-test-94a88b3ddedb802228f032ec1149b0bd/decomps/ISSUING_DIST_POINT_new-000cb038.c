
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ISSUING_DIST_POINT * ISSUING_DIST_POINT_new(void)

{
  ISSUING_DIST_POINT *pIVar1;
  
  pIVar1 = (ISSUING_DIST_POINT *)ASN1_item_new(DAT_000cb040);
  return pIVar1;
}

