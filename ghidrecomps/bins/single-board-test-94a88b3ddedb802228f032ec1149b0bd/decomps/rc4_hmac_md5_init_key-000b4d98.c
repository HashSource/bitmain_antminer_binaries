
undefined4 rc4_hmac_md5_init_key(EVP_CIPHER_CTX *param_1,uchar *param_2)

{
  int len;
  RC4_KEY *key;
  MD5_CTX *c;
  
  key = (RC4_KEY *)param_1->cipher_data;
  len = EVP_CIPHER_CTX_key_length(param_1);
  c = (MD5_CTX *)(key->data + 0x3f);
  RC4_set_key(key,len,param_2);
  MD5_Init(c);
  memcpy(key->data + 0x56,c,0x5c);
  memcpy(key->data + 0x6d,c,0x5c);
  key->data[0x84] = 0xffffffff;
  return 1;
}

