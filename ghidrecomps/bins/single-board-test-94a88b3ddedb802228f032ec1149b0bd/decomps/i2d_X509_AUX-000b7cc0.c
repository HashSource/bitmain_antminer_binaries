
int i2d_X509_AUX(X509 *a,uchar **pp)

{
  int iVar1;
  int iVar2;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,pp,DAT_000b7ce0);
  if (a != (X509 *)0x0) {
    iVar2 = i2d_X509_CERT_AUX(*(X509_CERT_AUX **)(a->sha1_hash + 0xc),pp);
    iVar1 = iVar1 + iVar2;
  }
  return iVar1;
}

