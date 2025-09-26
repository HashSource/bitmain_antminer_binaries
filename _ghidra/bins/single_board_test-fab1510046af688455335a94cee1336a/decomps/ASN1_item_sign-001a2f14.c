
int ASN1_item_sign(ASN1_ITEM *it,X509_ALGOR *algor1,X509_ALGOR *algor2,ASN1_BIT_STRING *signature,
                  void *data,EVP_PKEY *pkey,EVP_MD *type)

{
  int iVar1;
  EVP_MD_CTX EStack_38;
  
  EVP_MD_CTX_init(&EStack_38);
  iVar1 = EVP_DigestSignInit(&EStack_38,(EVP_PKEY_CTX **)0x0,type,(ENGINE *)0x0,pkey);
  if (iVar1 == 0) {
    EVP_MD_CTX_cleanup(&EStack_38);
    iVar1 = 0;
  }
  else {
    iVar1 = ASN1_item_sign_ctx(it,algor1,algor2,signature,data,&EStack_38);
  }
  return iVar1;
}

