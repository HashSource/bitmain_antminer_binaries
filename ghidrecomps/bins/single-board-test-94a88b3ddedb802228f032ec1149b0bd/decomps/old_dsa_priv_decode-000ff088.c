
bool old_dsa_priv_decode(EVP_PKEY *param_1,uchar **param_2,long param_3)

{
  DSA *key;
  
  key = d2i_DSAPrivateKey((DSA **)0x0,param_2,param_3);
  if (key == (DSA *)0x0) {
    ERR_put_error(10,0x7a,10,DAT_000ff0c0,0x204);
  }
  else {
    EVP_PKEY_assign(param_1,0x74,key);
  }
  return key != (DSA *)0x0;
}

