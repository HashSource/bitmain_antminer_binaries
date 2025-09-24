
undefined4 des_init_key(undefined4 param_1,const_DES_cblock *param_2)

{
  int iVar1;
  DES_key_schedule *schedule;
  
  iVar1 = EVP_CIPHER_CTX_get_cipher_data();
  *(undefined4 *)(iVar1 + 0x80) = 0;
  schedule = (DES_key_schedule *)EVP_CIPHER_CTX_get_cipher_data(param_1);
  DES_set_key_unchecked(param_2,schedule);
  return 1;
}

