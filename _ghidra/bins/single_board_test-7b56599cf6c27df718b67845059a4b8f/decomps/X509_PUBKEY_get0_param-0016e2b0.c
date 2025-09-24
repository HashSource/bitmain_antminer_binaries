
int X509_PUBKEY_get0_param
              (ASN1_OBJECT **ppkalg,uchar **pk,int *ppklen,X509_ALGOR **pa,X509_PUBKEY *pub)

{
  if (ppkalg != (ASN1_OBJECT **)0x0) {
    *ppkalg = pub->algor->algorithm;
  }
  if (pk != (uchar **)0x0) {
    *pk = pub->public_key->data;
    *ppklen = pub->public_key->length;
  }
  if (pa != (X509_ALGOR **)0x0) {
    *pa = pub->algor;
  }
  return 1;
}

