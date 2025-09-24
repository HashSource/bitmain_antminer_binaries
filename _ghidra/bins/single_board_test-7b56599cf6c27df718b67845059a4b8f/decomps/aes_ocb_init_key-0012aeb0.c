
undefined4 aes_ocb_init_key(EVP_CIPHER_CTX *param_1,uchar *param_2,void *param_3)

{
  AES_KEY *key;
  undefined4 uVar1;
  int iVar2;
  
  key = (AES_KEY *)EVP_CIPHER_CTX_get_cipher_data();
  if (param_3 == (void *)0x0 && param_2 == (uchar *)0x0) {
    uVar1 = 1;
  }
  else {
    if (param_2 == (uchar *)0x0) {
      if (key[2].rd_key[2] == 0) {
        memcpy((void *)key[2].rd_key[0x2a],param_3,key[2].rd_key[0x39]);
      }
      else {
        CRYPTO_ocb128_setiv(key[2].rd_key + 4,param_3,key[2].rd_key[0x39],key[2].rd_key[0x3a]);
      }
      key[2].rd_key[3] = 1;
      return 1;
    }
    iVar2 = EVP_CIPHER_CTX_key_length(param_1);
    AES_set_encrypt_key(param_2,iVar2 << 3,key);
    iVar2 = EVP_CIPHER_CTX_key_length(param_1);
    AES_set_decrypt_key(param_2,iVar2 << 3,(AES_KEY *)(key[1].rd_key + 1));
    iVar2 = CRYPTO_ocb128_init(key[2].rd_key + 4,key,(AES_KEY *)(key[1].rd_key + 1),0x17baf9,
                               0x17bf15,0);
    if (iVar2 != 0) {
      if ((param_3 == (void *)0x0) &&
         ((key[2].rd_key[3] == 0 || (param_3 = (void *)key[2].rd_key[0x2a], param_3 == (void *)0x0))
         )) {
LAB_0012af64:
        key[2].rd_key[2] = 1;
        return 1;
      }
      iVar2 = CRYPTO_ocb128_setiv(key[2].rd_key + 4,param_3,key[2].rd_key[0x39],key[2].rd_key[0x3a])
      ;
      if (iVar2 == 1) {
        key[2].rd_key[3] = 1;
        goto LAB_0012af64;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}

