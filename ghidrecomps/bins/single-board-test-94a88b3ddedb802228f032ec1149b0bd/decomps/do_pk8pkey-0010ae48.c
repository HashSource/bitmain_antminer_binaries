
int do_pk8pkey(BIO *param_1,EVP_PKEY *param_2,int param_3,int param_4,EVP_CIPHER *param_5,
              char *param_6,int param_7,code *param_8,void *param_9)

{
  PKCS8_PRIV_KEY_INFO *p8inf;
  X509_SIG *p8;
  int iVar1;
  size_t len;
  char acStack_420 [1024];
  
  p8inf = EVP_PKEY2PKCS8(param_2);
  if (p8inf == (PKCS8_PRIV_KEY_INFO *)0x0) {
    ERR_put_error(9,0x7e,0x73,DAT_0010afb4,0x78);
    return 0;
  }
  if (param_4 != -1 || param_5 != (EVP_CIPHER *)0x0) {
    if (param_6 == (char *)0x0) {
      if (param_8 == (code *)0x0) {
        len = PEM_def_callback(acStack_420,0x400,1,param_9);
      }
      else {
        len = (*param_8)(acStack_420,0x400,1,param_9);
      }
      if ((int)len < 1) {
        ERR_put_error(9,0x7e,0x6f,DAT_0010afb4,0x82);
        PKCS8_PRIV_KEY_INFO_free(p8inf);
        return 0;
      }
      p8 = PKCS8_encrypt(param_4,param_5,acStack_420,len,(uchar *)0x0,0,0,p8inf);
      OPENSSL_cleanse(acStack_420,len);
    }
    else {
      p8 = PKCS8_encrypt(param_4,param_5,param_6,param_7,(uchar *)0x0,0,0,p8inf);
    }
    PKCS8_PRIV_KEY_INFO_free(p8inf);
    if (p8 == (X509_SIG *)0x0) {
      return 0;
    }
    if (param_3 == 0) {
      iVar1 = PEM_ASN1_write_bio(DAT_0010afac,DAT_0010afb0,param_1,p8,(EVP_CIPHER *)0x0,(uchar *)0x0
                                 ,0,(undefined1 *)0x0,(void *)0x0);
    }
    else {
      iVar1 = i2d_PKCS8_bio(param_1,p8);
    }
    X509_SIG_free(p8);
    return iVar1;
  }
  if (param_3 == 0) {
    iVar1 = PEM_ASN1_write_bio(DAT_0010afa4,DAT_0010afa8,param_1,p8inf,(EVP_CIPHER *)0x0,
                               (uchar *)0x0,0,(undefined1 *)0x0,(void *)0x0);
  }
  else {
    iVar1 = i2d_PKCS8_PRIV_KEY_INFO_bio(param_1,p8inf);
  }
  PKCS8_PRIV_KEY_INFO_free(p8inf);
  return iVar1;
}

