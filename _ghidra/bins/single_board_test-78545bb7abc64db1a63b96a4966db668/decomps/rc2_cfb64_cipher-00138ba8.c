
undefined4 rc2_cfb64_cipher(undefined4 param_1,uchar *param_2,uchar *param_3,uint param_4)

{
  int iVar1;
  uchar *ivec;
  int enc;
  uint uVar2;
  uint length;
  uchar *puVar3;
  int local_2c [2];
  
  length = param_4;
  if (0x3fffffff < param_4) {
    length = 0x40000000;
  }
  if (param_4 != 0) {
    do {
      param_4 = param_4 - length;
      local_2c[0] = EVP_CIPHER_CTX_num(param_1);
      iVar1 = EVP_CIPHER_CTX_get_cipher_data(param_1);
      ivec = (uchar *)EVP_CIPHER_CTX_iv_noconst(param_1);
      enc = EVP_CIPHER_CTX_encrypting(param_1);
      puVar3 = param_2 + length;
      RC2_cfb64_encrypt(param_3,param_2,length,(RC2_KEY *)(iVar1 + 4),ivec,local_2c,enc);
      param_3 = param_3 + length;
      if (param_4 <= length) {
        length = param_4;
      }
      EVP_CIPHER_CTX_set_num(param_1,local_2c[0]);
      uVar2 = param_4;
      if (param_4 != 0) {
        uVar2 = 1;
      }
      if (param_4 < length) {
        uVar2 = 0;
      }
      param_2 = puVar3;
    } while (uVar2 != 0);
  }
  return 1;
}

