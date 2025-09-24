
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ISSUING_DIST_POINT * ISSUING_DIST_POINT_new(void)

{
  ISSUING_DIST_POINT *pIVar1;
  
  pIVar1 = (ISSUING_DIST_POINT *)ASN1_item_new((ASN1_ITEM *)ISSUING_DIST_POINT_it);
  return pIVar1;
}

