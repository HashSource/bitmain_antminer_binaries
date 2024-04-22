
X509 * d2i_X509_AUX(X509 **a,uchar **pp,long length)

{
  X509 *val;
  X509_CERT_AUX *pXVar1;
  uchar *puVar2;
  int iVar3;
  
  iVar3 = 1;
  puVar2 = *pp;
  if ((a != (X509 **)0x0) && (iVar3 = 1 - (int)*a, (X509 *)0x1 < *a)) {
    iVar3 = 0;
  }
  val = (X509 *)ASN1_item_d2i((ASN1_VALUE **)a,pp,length,DAT_000b7cbc);
  if (val != (X509 *)0x0) {
    if (puVar2 + (length - (int)*pp) == (uchar *)0x0) {
      return val;
    }
    pXVar1 = d2i_X509_CERT_AUX((X509_CERT_AUX **)(val->sha1_hash + 0xc),pp,
                               (long)(puVar2 + (length - (int)*pp)));
    if (pXVar1 != (X509_CERT_AUX *)0x0) {
      return val;
    }
    if ((iVar3 != 0) && (ASN1_item_free((ASN1_VALUE *)val,DAT_000b7cbc), a != (X509 **)0x0)) {
      *a = (X509 *)0x0;
      return (X509 *)0x0;
    }
  }
  return (X509 *)0x0;
}

