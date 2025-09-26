
void PBKDF2PARAM_free(PBKDF2PARAM *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)PBKDF2PARAM_it);
  return;
}

