
undefined4 des_ede_cbc_cipher_constprop_4(undefined4 param_1,uchar *param_2,uchar *param_3)

{
  DES_key_schedule *ks1;
  undefined4 uVar1;
  DES_cblock *ivec;
  int enc;
  code *pcVar2;
  
  ks1 = (DES_key_schedule *)EVP_CIPHER_CTX_get_cipher_data();
  pcVar2 = (code *)ks1[3].ks[0].deslong[0];
  if (pcVar2 != (code *)0x0) {
    uVar1 = EVP_CIPHER_CTX_iv_noconst(param_1);
    (*pcVar2)(param_3,param_2,8,ks1,uVar1);
    return 1;
  }
  ivec = (DES_cblock *)EVP_CIPHER_CTX_iv_noconst(param_1);
  enc = EVP_CIPHER_CTX_encrypting(param_1);
  DES_ede3_cbc_encrypt(param_3,param_2,8,ks1,ks1 + 1,ks1 + 2,ivec,enc);
  return 1;
}

