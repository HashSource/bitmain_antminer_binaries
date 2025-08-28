
bool dh_param_decode(EVP_PKEY *param_1,uchar **param_2,long param_3)

{
  DH *key;
  
  if (param_1->ameth == (EVP_PKEY_ASN1_METHOD *)&dhx_asn1_meth) {
    key = (DH *)d2i_DHxparams();
  }
  else {
    key = d2i_DHparams((DH **)0x0,param_2,param_3);
  }
  if (key == (DH *)0x0) {
    ERR_put_error(5,0x6b,5,"dh_ameth.c",0x141);
  }
  else {
    EVP_PKEY_assign(param_1,*(int *)param_1->ameth,key);
  }
  return key != (DH *)0x0;
}

