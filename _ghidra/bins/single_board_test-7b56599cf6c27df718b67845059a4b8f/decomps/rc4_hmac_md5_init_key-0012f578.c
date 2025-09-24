
undefined4 rc4_hmac_md5_init_key(EVP_CIPHER_CTX *param_1,uchar *param_2)

{
  RC4_KEY *key;
  int len;
  RC4_KEY *c;
  
  key = (RC4_KEY *)EVP_CIPHER_CTX_get_cipher_data();
  len = EVP_CIPHER_CTX_key_length(param_1);
  c = key + 1;
  RC4_set_key(key,len,param_2);
  MD5_Init((MD5_CTX *)c);
  memcpy(key[1].data + 0x15,c,0x5c);
  memcpy(key[1].data + 0x2c,c,0x5c);
  key[1].data[0x43] = 0xffffffff;
  return 1;
}

