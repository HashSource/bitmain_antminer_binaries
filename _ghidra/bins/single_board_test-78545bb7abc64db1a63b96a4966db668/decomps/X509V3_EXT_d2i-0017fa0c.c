
void * X509V3_EXT_d2i(X509_EXTENSION *ext)

{
  X509V3_EXT_METHOD *pXVar1;
  ASN1_OCTET_STRING *x;
  int len;
  ASN1_VALUE *pAVar2;
  void *pvVar3;
  uchar *local_14 [2];
  
  pXVar1 = X509V3_EXT_get(ext);
  if (pXVar1 == (X509V3_EXT_METHOD *)0x0) {
    pAVar2 = (ASN1_VALUE *)0x0;
  }
  else {
    x = X509_EXTENSION_get_data(ext);
    local_14[0] = (uchar *)ASN1_STRING_get0_data();
    len = ASN1_STRING_length(x);
    if (pXVar1->it == (ASN1_ITEM *)0x0) {
      pvVar3 = (*pXVar1->d2i)((void *)0x0,local_14,len);
      return pvVar3;
    }
    pAVar2 = ASN1_item_d2i((ASN1_VALUE **)0x0,local_14,len,pXVar1->it);
  }
  return pAVar2;
}

