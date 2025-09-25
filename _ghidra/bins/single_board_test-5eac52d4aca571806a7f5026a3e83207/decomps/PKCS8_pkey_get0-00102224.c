
int PKCS8_pkey_get0(ASN1_OBJECT **ppkalg,uchar **pk,int *ppklen,X509_ALGOR **pa,
                   PKCS8_PRIV_KEY_INFO *p8)

{
  uchar *puVar1;
  int iVar2;
  
  if (ppkalg != (ASN1_OBJECT **)0x0) {
    *ppkalg = (ASN1_OBJECT *)p8->version->length;
  }
  if (pk != (uchar **)0x0) {
    puVar1 = (uchar *)ASN1_STRING_get0_data(p8->pkeyalg);
    *pk = puVar1;
    iVar2 = ASN1_STRING_length((ASN1_STRING *)p8->pkeyalg);
    *ppklen = iVar2;
  }
  if (pa != (X509_ALGOR **)0x0) {
    *pa = (X509_ALGOR *)p8->version;
  }
  return 1;
}

