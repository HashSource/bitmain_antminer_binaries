
int ASN1_item_sign(ASN1_ITEM *it,X509_ALGOR *algor1,X509_ALGOR *algor2,ASN1_BIT_STRING *signature,
                  void *data,EVP_PKEY *pkey,EVP_MD *type)

{
  EVP_MD_CTX *ctx;
  int iVar1;
  
  ctx = (EVP_MD_CTX *)EVP_MD_CTX_new();
  if (ctx != (EVP_MD_CTX *)0x0) {
    iVar1 = EVP_DigestSignInit(ctx,(EVP_PKEY_CTX **)0x0,type,(ENGINE *)0x0,pkey);
    if (iVar1 != 0) {
      iVar1 = ASN1_item_sign_ctx(it,algor1,algor2,signature,data,ctx);
    }
    EVP_MD_CTX_free(ctx);
    return iVar1;
  }
  ERR_put_error(0xd,0xc3,0x41,"crypto/asn1/a_sign.c",0x7d);
  return 0;
}

