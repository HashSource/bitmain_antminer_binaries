
bool dsa_param_decode(EVP_PKEY *param_1,uchar **param_2,long param_3)

{
  DSA *key;
  
  key = d2i_DSAparams((DSA **)0x0,param_2,param_3);
  if (key == (DSA *)0x0) {
    ERR_put_error(10,0x77,10,DAT_000ff13c,0x1e1);
  }
  else {
    EVP_PKEY_assign(param_1,0x74,key);
  }
  return key != (DSA *)0x0;
}

