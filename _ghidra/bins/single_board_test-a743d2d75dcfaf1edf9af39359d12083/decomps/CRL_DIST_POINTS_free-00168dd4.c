
void CRL_DIST_POINTS_free(CRL_DIST_POINTS *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)CRL_DIST_POINTS_it);
  return;
}

