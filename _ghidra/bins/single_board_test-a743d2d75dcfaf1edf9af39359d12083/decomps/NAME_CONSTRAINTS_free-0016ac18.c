
void NAME_CONSTRAINTS_free(NAME_CONSTRAINTS *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)&NAME_CONSTRAINTS_it);
  return;
}

