
undefined4 old_rsa_priv_decode(EVP_PKEY *param_1,uchar **param_2,long param_3)

{
  RSA *key;
  
  key = d2i_RSAPrivateKey((RSA **)0x0,param_2,param_3);
  if (key != (RSA *)0x0) {
    EVP_PKEY_assign(param_1,*(int *)param_1->ameth,key);
    return 1;
  }
  ERR_put_error(4,0x93,4,"crypto/rsa/rsa_ameth.c",0x8e);
  return 0;
}

