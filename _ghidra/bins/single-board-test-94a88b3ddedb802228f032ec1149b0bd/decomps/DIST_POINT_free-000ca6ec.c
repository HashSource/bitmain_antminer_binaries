
void DIST_POINT_free(DIST_POINT *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)DIST_POINT_it);
  return;
}

