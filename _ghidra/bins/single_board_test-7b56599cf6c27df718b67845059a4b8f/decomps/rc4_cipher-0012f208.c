
undefined4 rc4_cipher(undefined4 param_1,uchar *param_2,uchar *param_3,size_t param_4)

{
  RC4_KEY *key;
  
  key = (RC4_KEY *)EVP_CIPHER_CTX_get_cipher_data();
  RC4(key,param_4,param_3,param_2);
  return 1;
}

