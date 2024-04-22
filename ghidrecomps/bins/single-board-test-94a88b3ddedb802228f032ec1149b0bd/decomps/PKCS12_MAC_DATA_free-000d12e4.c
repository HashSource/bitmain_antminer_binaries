
void PKCS12_MAC_DATA_free(PKCS12_MAC_DATA *a)

{
  ASN1_item_free((ASN1_VALUE *)a,DAT_000d12ec);
  return;
}

