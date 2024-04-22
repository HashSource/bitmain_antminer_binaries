
int X509_alias_set1(X509 *x,uchar *name,int len)

{
  ASN1_STRING *str;
  int iVar1;
  ASN1_UTF8STRING *a;
  ASN1_VALUE *pAVar2;
  
  if (name != (uchar *)0x0) {
    if (x == (X509 *)0x0) {
      return 0;
    }
    pAVar2 = *(ASN1_VALUE **)(x->sha1_hash + 0xc);
    if (pAVar2 == (ASN1_VALUE *)0x0) {
      pAVar2 = ASN1_item_new(DAT_000b7db0);
      *(ASN1_VALUE **)(x->sha1_hash + 0xc) = pAVar2;
      if (pAVar2 == (ASN1_VALUE *)0x0) {
        return 0;
      }
    }
    str = *(ASN1_STRING **)(pAVar2 + 8);
    if (str == (ASN1_STRING *)0x0) {
      str = ASN1_UTF8STRING_new();
      *(ASN1_STRING **)(pAVar2 + 8) = str;
      if (str == (ASN1_UTF8STRING *)0x0) {
        return 0;
      }
    }
    iVar1 = ASN1_STRING_set(str,name,len);
    return iVar1;
  }
  if (((x != (X509 *)0x0) && (*(int *)(x->sha1_hash + 0xc) != 0)) &&
     (a = *(ASN1_UTF8STRING **)(*(int *)(x->sha1_hash + 0xc) + 8), a != (ASN1_UTF8STRING *)0x0)) {
    ASN1_UTF8STRING_free(a);
    *(undefined4 *)(*(int *)(x->sha1_hash + 0xc) + 8) = 0;
    return 1;
  }
  return 1;
}

