
undefined4 cast_init_key(EVP_CIPHER_CTX *param_1,uchar *param_2)

{
  CAST_KEY *key;
  int len;
  
  key = (CAST_KEY *)EVP_CIPHER_CTX_get_cipher_data();
  len = EVP_CIPHER_CTX_key_length(param_1);
  CAST_set_key(key,len,param_2);
  return 1;
}

