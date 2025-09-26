
undefined4 idea_init_key(EVP_CIPHER_CTX *param_1,uchar *param_2,undefined4 param_3,int param_4)

{
  ulong uVar1;
  IDEA_KEY_SCHEDULE IStack_e8;
  
  if (((param_4 == 0) && (uVar1 = EVP_CIPHER_CTX_flags(param_1), (uVar1 & 0xf0007) != 4)) &&
     (uVar1 = EVP_CIPHER_CTX_flags(param_1), (uVar1 & 0xf0007) != 3)) {
    idea_set_encrypt_key(param_2,&IStack_e8);
    idea_set_decrypt_key(&IStack_e8,(IDEA_KEY_SCHEDULE *)param_1->cipher_data);
    OPENSSL_cleanse(&IStack_e8,0xd8);
  }
  else {
    idea_set_encrypt_key(param_2,(IDEA_KEY_SCHEDULE *)param_1->cipher_data);
  }
  return 1;
}

