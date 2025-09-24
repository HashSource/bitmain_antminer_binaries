
undefined4 aes_gcm_init_key(int param_1,uchar *param_2,void *param_3,undefined4 param_4)

{
  AES_KEY *key;
  
  key = (AES_KEY *)EVP_CIPHER_CTX_get_cipher_data();
  if (param_3 != (void *)0x0 || param_2 != (uchar *)0x0) {
    if (param_2 == (uchar *)0x0) {
      if (key[1].rd_key[1] == 0) {
        memcpy((void *)key[2].rd_key[0x30],param_3,key[2].rd_key[0x31]);
      }
      else {
        CRYPTO_gcm128_setiv(key[1].rd_key + 3);
      }
      key[1].rd_key[2] = 1;
      key[2].rd_key[0x33] = 0;
      return 1;
    }
    AES_set_encrypt_key(param_2,*(int *)(param_1 + 0x58) << 3,key);
    CRYPTO_gcm128_init(key[1].rd_key + 3,key,0x17baf9,0x370,param_4);
    key[2].rd_key[0x35] = 0;
    if ((param_3 != (void *)0x0) ||
       ((key[1].rd_key[2] != 0 && (param_3 = (void *)key[2].rd_key[0x30], param_3 != (void *)0x0))))
    {
      CRYPTO_gcm128_setiv(key[1].rd_key + 3,param_3,key[2].rd_key[0x31]);
      key[1].rd_key[2] = 1;
    }
    key[1].rd_key[1] = 1;
  }
  return 1;
}

