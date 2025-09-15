
int PKCS8_pkey_get0(ASN1_OBJECT **ppkalg,uchar **pk,int *ppklen,X509_ALGOR **pa,
                   PKCS8_PRIV_KEY_INFO *p8)

{
  int iVar1;
  
  if (ppkalg != (ASN1_OBJECT **)0x0) {
    *ppkalg = p8->pkeyalg->algorithm;
  }
  iVar1 = p8->pkey->type;
  if (iVar1 == 4) {
    p8->broken = 0;
  }
  else {
    if (iVar1 != 0x10) {
      return 0;
    }
    p8->broken = 1;
  }
  if (pk != (uchar **)0x0) {
    *pk = ((p8->pkey->value).asn1_string)->data;
    *ppklen = ((p8->pkey->value).asn1_string)->length;
  }
  if (pa != (X509_ALGOR **)0x0) {
    *pa = p8->pkeyalg;
  }
  return 1;
}

