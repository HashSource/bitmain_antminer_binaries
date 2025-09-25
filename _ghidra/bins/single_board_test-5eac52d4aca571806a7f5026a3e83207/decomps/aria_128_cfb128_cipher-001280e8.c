
undefined4 aria_128_cfb128_cipher(undefined4 param_1,int param_2,int param_3,uint param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 local_2c [2];
  
  uVar5 = param_4;
  if (0x3fffffff < param_4) {
    uVar5 = 0x40000000;
  }
  if (param_4 != 0) {
    do {
      param_4 = param_4 - uVar5;
      local_2c[0] = EVP_CIPHER_CTX_num(param_1);
      uVar1 = EVP_CIPHER_CTX_get_cipher_data(param_1);
      uVar2 = EVP_CIPHER_CTX_iv_noconst(param_1);
      uVar3 = EVP_CIPHER_CTX_encrypting(param_1);
      iVar6 = param_2 + uVar5;
      CRYPTO_cfb128_encrypt(param_3,param_2,uVar5,uVar1,uVar2,local_2c,uVar3,0x1780d5);
      param_3 = param_3 + uVar5;
      if (param_4 <= uVar5) {
        uVar5 = param_4;
      }
      EVP_CIPHER_CTX_set_num(param_1,local_2c[0]);
      uVar4 = param_4;
      if (param_4 != 0) {
        uVar4 = 1;
      }
      if (param_4 < uVar5) {
        uVar4 = 0;
      }
      param_2 = iVar6;
    } while (uVar4 != 0);
  }
  return 1;
}

