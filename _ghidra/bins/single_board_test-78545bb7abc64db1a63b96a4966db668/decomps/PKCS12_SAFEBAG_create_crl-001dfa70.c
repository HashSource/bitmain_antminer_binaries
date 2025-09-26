
void PKCS12_SAFEBAG_create_crl(void *param_1)

{
  PKCS12_item_pack_safebag(param_1,(ASN1_ITEM *)&X509_CRL_it,0xa0,0x99);
  return;
}

