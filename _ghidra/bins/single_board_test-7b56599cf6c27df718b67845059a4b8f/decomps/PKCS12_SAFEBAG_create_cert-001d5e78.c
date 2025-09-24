
void PKCS12_SAFEBAG_create_cert(void *param_1)

{
  PKCS12_item_pack_safebag(param_1,(ASN1_ITEM *)&X509_it,0x9e,0x98);
  return;
}

