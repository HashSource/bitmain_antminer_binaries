
undefined4 cast5_cfb64_cipher(undefined4 param_1,uchar *param_2,uchar *param_3,uint param_4)

{
  CAST_KEY *schedule;
  uchar *ivec;
  int enc;
  uint uVar1;
  uint length;
  uchar *puVar2;
  int local_2c [2];
  
  length = param_4;
  if (0x3fffffff < param_4) {
    length = 0x40000000;
  }
  if (param_4 != 0) {
    do {
      param_4 = param_4 - length;
      local_2c[0] = EVP_CIPHER_CTX_num(param_1);
      schedule = (CAST_KEY *)EVP_CIPHER_CTX_get_cipher_data(param_1);
      ivec = (uchar *)EVP_CIPHER_CTX_iv_noconst(param_1);
      enc = EVP_CIPHER_CTX_encrypting(param_1);
      puVar2 = param_2 + length;
      CAST_cfb64_encrypt(param_3,param_2,length,schedule,ivec,local_2c,enc);
      param_3 = param_3 + length;
      if (param_4 <= length) {
        length = param_4;
      }
      EVP_CIPHER_CTX_set_num(param_1,local_2c[0]);
      uVar1 = param_4;
      if (param_4 != 0) {
        uVar1 = 1;
      }
      if (param_4 < length) {
        uVar1 = 0;
      }
      param_2 = puVar2;
    } while (uVar1 != 0);
  }
  return 1;
}

