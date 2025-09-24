
undefined4 des_ede3_init_key(undefined4 param_1,const_DES_cblock *param_2)

{
  DES_key_schedule *schedule;
  
  schedule = (DES_key_schedule *)EVP_CIPHER_CTX_get_cipher_data();
  schedule[3].ks[0].deslong[0] = 0;
  DES_set_key_unchecked(param_2,schedule);
  DES_set_key_unchecked(param_2 + 1,schedule + 1);
  DES_set_key_unchecked(param_2 + 2,schedule + 2);
  return 1;
}

