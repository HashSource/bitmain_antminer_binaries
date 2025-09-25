
void cms_content_bio(CMS_ContentInfo *param_1)

{
  ASN1_OCTET_STRING **ppAVar1;
  BIO_METHOD *pBVar2;
  ASN1_OCTET_STRING *pAVar3;
  
  ppAVar1 = CMS_get0_content(param_1);
  if (ppAVar1 == (ASN1_OCTET_STRING **)0x0) {
    return;
  }
  pAVar3 = *ppAVar1;
  if (pAVar3 != (ASN1_OCTET_STRING *)0x0) {
    if (pAVar3->flags != 0x20) {
      BIO_new_mem_buf(pAVar3->data,pAVar3->length);
      return;
    }
    pBVar2 = BIO_s_mem();
    BIO_new(pBVar2);
    return;
  }
  pBVar2 = BIO_s_null();
  BIO_new(pBVar2);
  return;
}

