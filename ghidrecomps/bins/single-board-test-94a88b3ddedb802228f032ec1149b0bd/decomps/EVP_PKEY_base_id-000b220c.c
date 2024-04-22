
int EVP_PKEY_base_id(EVP_PKEY *pkey)

{
  EVP_PKEY_ASN1_METHOD **ppEVar1;
  ENGINE *local_c;
  
  ppEVar1 = (EVP_PKEY_ASN1_METHOD **)EVP_PKEY_asn1_find(&local_c,pkey->type);
  if (ppEVar1 != (EVP_PKEY_ASN1_METHOD **)0x0) {
    ppEVar1 = (EVP_PKEY_ASN1_METHOD **)*ppEVar1;
  }
  if (local_c != (ENGINE *)0x0) {
    ENGINE_finish(local_c);
  }
  return (int)(EVP_PKEY_ASN1_METHOD *)ppEVar1;
}

