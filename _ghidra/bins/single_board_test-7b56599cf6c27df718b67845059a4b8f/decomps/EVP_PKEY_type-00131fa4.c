
int EVP_PKEY_type(int type)

{
  EVP_PKEY_ASN1_METHOD *pEVar1;
  int iVar2;
  ENGINE *local_c;
  
  pEVar1 = EVP_PKEY_asn1_find(&local_c,type);
  if (pEVar1 == (EVP_PKEY_ASN1_METHOD *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)pEVar1;
  }
  ENGINE_finish(local_c);
  return iVar2;
}

