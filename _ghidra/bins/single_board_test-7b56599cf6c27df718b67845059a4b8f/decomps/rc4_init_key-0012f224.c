
undefined4 rc4_init_key(EVP_CIPHER_CTX *param_1,uchar *param_2)

{
  RC4_KEY *key;
  int len;
  
  key = (RC4_KEY *)EVP_CIPHER_CTX_get_cipher_data();
  len = EVP_CIPHER_CTX_key_length(param_1);
  RC4_set_key(key,len,param_2);
  return 1;
}

