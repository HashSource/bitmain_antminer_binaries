
undefined4 idea_init_key(EVP_CIPHER_CTX *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  EVP_CIPHER *pEVar2;
  ulong uVar3;
  undefined1 auStack_e8 [216];
  
  if (param_4 == 0) {
    pEVar2 = EVP_CIPHER_CTX_cipher(param_1);
    uVar3 = EVP_CIPHER_flags(pEVar2);
    if ((uVar3 & 0xf0007) != 4) {
      pEVar2 = EVP_CIPHER_CTX_cipher(param_1);
      uVar3 = EVP_CIPHER_flags(pEVar2);
      if ((uVar3 & 0xf0007) != 3) {
        IDEA_set_encrypt_key(param_2,auStack_e8);
        uVar1 = EVP_CIPHER_CTX_get_cipher_data(param_1);
        IDEA_set_decrypt_key(auStack_e8,uVar1);
        OPENSSL_cleanse(auStack_e8,0xd8);
        return 1;
      }
    }
  }
  uVar1 = EVP_CIPHER_CTX_get_cipher_data(param_1);
  IDEA_set_encrypt_key(param_2,uVar1);
  return 1;
}

