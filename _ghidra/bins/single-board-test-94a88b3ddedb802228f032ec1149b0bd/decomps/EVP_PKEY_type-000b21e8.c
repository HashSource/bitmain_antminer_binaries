
int EVP_PKEY_type(int type)

{
  EVP_PKEY_ASN1_METHOD *pEVar1;
  ENGINE *local_c;
  
  pEVar1 = EVP_PKEY_asn1_find(&local_c,type);
  if (pEVar1 != (EVP_PKEY_ASN1_METHOD *)0x0) {
    pEVar1 = *(EVP_PKEY_ASN1_METHOD **)pEVar1;
  }
  if (local_c != (ENGINE *)0x0) {
    ENGINE_finish(local_c);
  }
  return (int)pEVar1;
}

