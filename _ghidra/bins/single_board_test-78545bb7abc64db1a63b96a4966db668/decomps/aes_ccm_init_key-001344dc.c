
undefined4 aes_ccm_init_key(EVP_CIPHER_CTX *param_1,uchar *param_2,void *param_3)

{
  AES_KEY *key;
  int iVar1;
  void *__dest;
  
  key = (AES_KEY *)EVP_CIPHER_CTX_get_cipher_data();
  if (param_3 != (void *)0x0 || param_2 != (uchar *)0x0) {
    if (param_2 != (uchar *)0x0) {
      iVar1 = EVP_CIPHER_CTX_key_length(param_1);
      AES_set_encrypt_key(param_2,iVar1 << 3,key);
      CRYPTO_ccm128_init(key[1].rd_key + 9,key[1].rd_key[6],key[1].rd_key[5],key,0x1856d1);
      key[1].rd_key[0x15] = 0;
      key[1].rd_key[1] = 1;
    }
    if (param_3 != (void *)0x0) {
      __dest = (void *)EVP_CIPHER_CTX_iv_noconst(param_1);
      memcpy(__dest,param_3,0xf - key[1].rd_key[5]);
      key[1].rd_key[2] = 1;
    }
  }
  return 1;
}

