
undefined4 aes_xts_init_key(EVP_CIPHER_CTX *param_1,uchar *param_2,undefined4 *param_3,int param_4)

{
  AES_KEY *key;
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  key = (AES_KEY *)EVP_CIPHER_CTX_get_cipher_data();
  if (param_3 != (undefined4 *)0x0 || param_2 != (uchar *)0x0) {
    if (param_2 != (uchar *)0x0) {
      iVar1 = EVP_CIPHER_CTX_key_length(param_1);
      if (param_4 == 0) {
        key[2].rd_key[6] = 0;
        iVar1 = EVP_CIPHER_CTX_key_length(param_1);
        AES_set_decrypt_key(param_2,iVar1 << 2,key);
        key[2].rd_key[4] = 0x17bf15;
      }
      else {
        iVar1 = CRYPTO_memcmp(param_2,param_2 + iVar1 / 2,iVar1 / 2);
        if (iVar1 == 0) {
          ERR_put_error(6,0xd1,0xb7,"crypto/evp/e_aes.c",0xd32);
          return 0;
        }
        key[2].rd_key[6] = 0;
        iVar1 = EVP_CIPHER_CTX_key_length(param_1);
        AES_set_encrypt_key(param_2,iVar1 << 2,key);
        key[2].rd_key[4] = 0x17baf9;
      }
      iVar1 = EVP_CIPHER_CTX_key_length(param_1);
      iVar2 = EVP_CIPHER_CTX_key_length(param_1);
      AES_set_encrypt_key(param_2 + iVar1 / 2,iVar2 << 2,(AES_KEY *)(key[1].rd_key + 1));
      key[2].rd_key[5] = 0x17baf9;
      key[2].rd_key[2] = (uint)key;
    }
    if (param_3 != (undefined4 *)0x0) {
      key[2].rd_key[3] = (uint)(key[1].rd_key + 1);
      puVar3 = (undefined4 *)EVP_CIPHER_CTX_iv_noconst(param_1);
      uVar4 = param_3[1];
      uVar5 = param_3[2];
      uVar6 = param_3[3];
      *puVar3 = *param_3;
      puVar3[1] = uVar4;
      puVar3[2] = uVar5;
      puVar3[3] = uVar6;
      return 1;
    }
  }
  return 1;
}

