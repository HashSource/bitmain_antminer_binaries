
void PBE2PARAM_free(PBE2PARAM *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)&PBE2PARAM_it);
  return;
}

