
undefined4 aes_wrap_init_key(EVP_CIPHER_CTX *param_1,uchar *param_2,void *param_3)

{
  AES_KEY *key;
  int iVar1;
  void *__dest;
  size_t __n;
  uint uVar2;
  
  key = (AES_KEY *)EVP_CIPHER_CTX_get_cipher_data();
  if (param_3 != (void *)0x0 || param_2 != (uchar *)0x0) {
    if (param_2 == (uchar *)0x0) {
      if (param_3 == (void *)0x0) {
        return 1;
      }
    }
    else {
      iVar1 = EVP_CIPHER_CTX_encrypting(param_1);
      if (iVar1 == 0) {
        iVar1 = EVP_CIPHER_CTX_key_length(param_1);
        AES_set_decrypt_key(param_2,iVar1 << 3,key);
      }
      else {
        iVar1 = EVP_CIPHER_CTX_key_length(param_1);
        AES_set_encrypt_key(param_2,iVar1 << 3,key);
      }
      if (param_3 == (void *)0x0) {
        key[1].rd_key[1] = 0;
        return 1;
      }
    }
    __dest = (void *)EVP_CIPHER_CTX_iv_noconst(param_1);
    __n = EVP_CIPHER_CTX_iv_length(param_1);
    memcpy(__dest,param_3,__n);
    uVar2 = EVP_CIPHER_CTX_iv_noconst(param_1);
    key[1].rd_key[1] = uVar2;
  }
  return 1;
}

