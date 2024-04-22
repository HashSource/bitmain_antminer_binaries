
void PROXY_CERT_INFO_EXTENSION_free(PROXY_CERT_INFO_EXTENSION *a)

{
  ASN1_item_free((ASN1_VALUE *)a,DAT_000ccf50);
  return;
}

