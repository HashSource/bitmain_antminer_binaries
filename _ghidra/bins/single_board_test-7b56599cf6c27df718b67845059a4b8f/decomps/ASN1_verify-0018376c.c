
int ASN1_verify(undefined1 *i2d,X509_ALGOR *algor1,ASN1_BIT_STRING *signature,char *data,
               EVP_PKEY *pkey)

{
  EVP_MD_CTX *ctx;
  int iVar1;
  char *name;
  EVP_MD *type;
  size_t cnt;
  void *d;
  int line;
  void *local_2c [2];
  
  ctx = (EVP_MD_CTX *)EVP_MD_CTX_new();
  if (ctx == (EVP_MD_CTX *)0x0) {
    iVar1 = 0x23;
  }
  else {
    iVar1 = OBJ_obj2nid(algor1->algorithm);
    name = OBJ_nid2sn(iVar1);
    type = EVP_get_digestbyname(name);
    if (type == (EVP_MD *)0x0) {
      iVar1 = -1;
      ERR_put_error(0xd,0x89,0xa1,"crypto/asn1/a_verify.c",0x29);
      goto LAB_001837f8;
    }
    if ((signature->type == 3) && ((signature->flags & 7U) != 0)) {
      iVar1 = -1;
      ERR_put_error(0xd,0x89,0xdc,"crypto/asn1/a_verify.c",0x2e);
      goto LAB_001837f8;
    }
    cnt = (*(code *)i2d)(data,0);
    if ((int)cnt < 1) {
      iVar1 = -1;
      ERR_put_error(0xd,0x89,0x44,"crypto/asn1/a_verify.c",0x34);
      goto LAB_001837f8;
    }
    d = CRYPTO_malloc(cnt,"crypto/asn1/a_verify.c",0x37);
    if (d != (void *)0x0) {
      local_2c[0] = d;
      (*(code *)i2d)(data,local_2c);
      iVar1 = EVP_DigestInit_ex(ctx,type,(ENGINE *)0x0);
      if ((iVar1 == 0) || (iVar1 = EVP_DigestUpdate(ctx,d,cnt), iVar1 == 0)) {
        CRYPTO_clear_free(d,cnt,"crypto/asn1/a_verify.c",0x42);
        line = 0x45;
      }
      else {
        CRYPTO_clear_free(d,cnt,"crypto/asn1/a_verify.c",0x42);
        iVar1 = EVP_VerifyFinal(ctx,signature->data,signature->length,pkey);
        if (0 < iVar1) {
          EVP_MD_CTX_free(ctx);
          return 1;
        }
        line = 0x4c;
      }
      iVar1 = 0;
      ERR_put_error(0xd,0x89,6,"crypto/asn1/a_verify.c",line);
      goto LAB_001837f8;
    }
    iVar1 = 0x39;
  }
  ERR_put_error(0xd,0x89,0x41,"crypto/asn1/a_verify.c",iVar1);
  iVar1 = -1;
LAB_001837f8:
  EVP_MD_CTX_free(ctx);
  return iVar1;
}

