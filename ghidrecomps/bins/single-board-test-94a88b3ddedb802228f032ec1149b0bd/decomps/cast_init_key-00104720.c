
undefined4 cast_init_key(EVP_CIPHER_CTX *param_1,uchar *param_2)

{
  int len;
  CAST_KEY *key;
  
  key = (CAST_KEY *)param_1->cipher_data;
  len = EVP_CIPHER_CTX_key_length(param_1);
  CAST_set_key(key,len,param_2);
  return 1;
}

