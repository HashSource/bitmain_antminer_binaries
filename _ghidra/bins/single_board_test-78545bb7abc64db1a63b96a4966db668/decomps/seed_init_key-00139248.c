
undefined4 seed_init_key(undefined4 param_1,uchar *param_2)

{
  SEED_KEY_SCHEDULE *ks;
  
  ks = (SEED_KEY_SCHEDULE *)EVP_CIPHER_CTX_get_cipher_data();
  SEED_set_key(param_2,ks);
  return 1;
}

