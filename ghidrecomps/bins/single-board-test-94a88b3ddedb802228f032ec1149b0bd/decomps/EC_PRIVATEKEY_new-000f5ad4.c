
void EC_PRIVATEKEY_new(void)

{
  ASN1_item_new((ASN1_ITEM *)EC_PRIVATEKEY_it);
  return;
}

