
bool old_rsa_priv_decode(EVP_PKEY *param_1,uchar **param_2,long param_3)

{
  RSA *key;
  
  key = d2i_RSAPrivateKey((RSA **)0x0,param_2,param_3);
  if (key == (RSA *)0x0) {
    ERR_put_error(4,0x93,4,DAT_000fc694,0x77);
  }
  else {
    EVP_PKEY_assign(param_1,6,key);
  }
  return key != (RSA *)0x0;
}

