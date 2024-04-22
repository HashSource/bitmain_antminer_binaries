
int ASN1_verify(undefined1 *i2d,X509_ALGOR *algor1,ASN1_BIT_STRING *signature,char *data,
               EVP_PKEY *pkey)

{
  int iVar1;
  char *name;
  EVP_MD *type;
  size_t cnt;
  void *d;
  int line;
  void *local_3c;
  EVP_MD_CTX EStack_38;
  
  EVP_MD_CTX_init(&EStack_38);
  iVar1 = OBJ_obj2nid(algor1->algorithm);
  name = OBJ_nid2sn(iVar1);
  type = EVP_get_digestbyname(name);
  if (type == (EVP_MD *)0x0) {
    ERR_put_error(0xd,0x89,0xa1,DAT_00107034,0x59);
    iVar1 = -1;
  }
  else if ((signature->type == 3) && ((signature->flags & 7U) != 0)) {
    ERR_put_error(0xd,0x89,0xdc,DAT_00107034,0x5e);
    iVar1 = -1;
  }
  else {
    cnt = (*(code *)i2d)(data,0);
    d = CRYPTO_malloc(cnt,DAT_00107034,99);
    if (d == (void *)0x0) {
      ERR_put_error(0xd,0x89,0x41,DAT_00107034,0x65);
      iVar1 = -1;
    }
    else {
      local_3c = d;
      (*(code *)i2d)(data,&local_3c);
      iVar1 = EVP_DigestInit_ex(&EStack_38,type,(ENGINE *)0x0);
      if ((iVar1 == 0) || (iVar1 = EVP_DigestUpdate(&EStack_38,d,cnt), iVar1 == 0)) {
        line = 0x6d;
      }
      else {
        OPENSSL_cleanse(d,cnt);
        CRYPTO_free(d);
        iVar1 = EVP_VerifyFinal(&EStack_38,signature->data,signature->length,pkey);
        if (0 < iVar1) {
          iVar1 = 1;
          goto LAB_00106fb2;
        }
        line = 0x77;
      }
      iVar1 = 0;
      ERR_put_error(0xd,0x89,6,DAT_00107034,line);
    }
  }
LAB_00106fb2:
  EVP_MD_CTX_cleanup(&EStack_38);
  return iVar1;
}

