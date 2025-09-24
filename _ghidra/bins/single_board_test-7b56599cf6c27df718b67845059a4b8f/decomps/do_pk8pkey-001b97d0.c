
int do_pk8pkey(BIO *param_1,EVP_PKEY *param_2,int param_3,int param_4,EVP_CIPHER *param_5,
              char *param_6,int param_7,code *param_8,void *param_9)

{
  PKCS8_PRIV_KEY_INFO *x;
  X509_SIG *x_00;
  int iVar1;
  size_t len;
  char acStack_428 [1028];
  
  x = EVP_PKEY2PKCS8(param_2);
  if (x == (PKCS8_PRIV_KEY_INFO *)0x0) {
    ERR_put_error(9,0x7e,0x73,"crypto/pem/pem_pk8.c",0x49);
    iVar1 = 0;
  }
  else if (param_4 == -1 && param_5 == (EVP_CIPHER *)0x0) {
    if (param_3 == 0) {
      iVar1 = PEM_write_bio_PKCS8_PRIV_KEY_INFO(param_1,x);
    }
    else {
      iVar1 = i2d_PKCS8_PRIV_KEY_INFO_bio(param_1,x);
    }
    PKCS8_PRIV_KEY_INFO_free(x);
  }
  else {
    if (param_6 == (char *)0x0) {
      if (param_8 == (code *)0x0) {
        len = PEM_def_callback(acStack_428,0x400,1,param_9);
      }
      else {
        len = (*param_8)(acStack_428,0x400,1,param_9);
      }
      if ((int)len < 1) {
        ERR_put_error(9,0x7e,0x6f,"crypto/pem/pem_pk8.c",0x53);
        PKCS8_PRIV_KEY_INFO_free(x);
        return 0;
      }
      x_00 = PKCS8_encrypt(param_4,param_5,acStack_428,len,(uchar *)0x0,0,0,x);
      OPENSSL_cleanse(acStack_428,len);
    }
    else {
      x_00 = PKCS8_encrypt(param_4,param_5,param_6,param_7,(uchar *)0x0,0,0,x);
    }
    PKCS8_PRIV_KEY_INFO_free(x);
    if (x_00 != (X509_SIG *)0x0) {
      if (param_3 == 0) {
        iVar1 = PEM_write_bio_PKCS8(param_1,x_00);
      }
      else {
        iVar1 = i2d_PKCS8_bio(param_1,x_00);
      }
      X509_SIG_free(x_00);
      return iVar1;
    }
    iVar1 = 0;
  }
  return iVar1;
}

