
int X509_PUBKEY_set0_param
              (X509_PUBKEY *pub,ASN1_OBJECT *aobj,int ptype,void *pval,uchar *penc,int penclen)

{
  int iVar1;
  ASN1_BIT_STRING *pAVar2;
  
  iVar1 = X509_ALGOR_set0(pub->algor,aobj,ptype,pval);
  if (iVar1 != 0) {
    if (penc != (uchar *)0x0) {
      pAVar2 = pub->public_key;
      if (pAVar2->data != (uchar *)0x0) {
        CRYPTO_free(pAVar2->data);
        pAVar2 = pub->public_key;
      }
      pAVar2->data = penc;
      pAVar2->length = penclen;
      pAVar2->flags = pAVar2->flags & 0xfffffff0U | 8;
      return 1;
    }
    iVar1 = 1;
  }
  return iVar1;
}

