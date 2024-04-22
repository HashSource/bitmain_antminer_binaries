
bool old_ec_priv_decode(EVP_PKEY *param_1,uchar **param_2,long param_3)

{
  EC_KEY *key;
  
  key = d2i_ECPrivateKey((EC_KEY **)0x0,param_2,param_3);
  if (key == (EC_KEY *)0x0) {
    ERR_put_error(0x10,0xde,0x8e,DAT_000f8178,0x21d);
  }
  else {
    EVP_PKEY_assign(param_1,0x198,key);
  }
  return key != (EC_KEY *)0x0;
}

