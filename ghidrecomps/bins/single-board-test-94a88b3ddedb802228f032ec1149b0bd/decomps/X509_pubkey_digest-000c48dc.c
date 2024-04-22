
int X509_pubkey_digest(X509 *data,EVP_MD *type,uchar *md,uint *len)

{
  ASN1_BIT_STRING *pAVar1;
  
  pAVar1 = X509_get0_pubkey_bitstr(data);
  if (pAVar1 != (ASN1_BIT_STRING *)0x0) {
    pAVar1 = (ASN1_BIT_STRING *)EVP_Digest(pAVar1->data,pAVar1->length,md,len,type,(ENGINE *)0x0);
  }
  return (int)pAVar1;
}

