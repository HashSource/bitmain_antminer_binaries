
void PKCS8_PRIV_KEY_INFO_free(PKCS8_PRIV_KEY_INFO *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)&PKCS8_PRIV_KEY_INFO_it);
  return;
}

