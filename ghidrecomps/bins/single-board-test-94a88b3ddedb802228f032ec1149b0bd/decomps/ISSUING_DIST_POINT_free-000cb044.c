
void ISSUING_DIST_POINT_free(ISSUING_DIST_POINT *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)ISSUING_DIST_POINT_it);
  return;
}

