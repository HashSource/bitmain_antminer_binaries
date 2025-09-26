
undefined4 aria_128_cfb1_cipher(EVP_CIPHER_CTX *param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 local_2c [2];
  
  uVar5 = param_4;
  if (0x7ffffff < param_4) {
    uVar5 = 0x8000000;
  }
  if (param_4 != 0) {
    do {
      local_2c[0] = EVP_CIPHER_CTX_num(param_1);
      iVar1 = EVP_CIPHER_CTX_test_flags(param_1,0x2000);
      uVar6 = uVar5;
      if (iVar1 == 0) {
        uVar6 = uVar5 << 3;
      }
      uVar2 = EVP_CIPHER_CTX_get_cipher_data(param_1);
      uVar3 = EVP_CIPHER_CTX_iv_noconst(param_1);
      uVar4 = EVP_CIPHER_CTX_encrypting(param_1);
      param_4 = param_4 - uVar5;
      iVar1 = param_2 + uVar5;
      CRYPTO_cfb128_1_encrypt(param_3,param_2,uVar6,uVar2,uVar3,local_2c,uVar4,0x185efd);
      param_3 = param_3 + uVar5;
      if (param_4 <= uVar5) {
        uVar5 = param_4;
      }
      EVP_CIPHER_CTX_set_num(param_1,local_2c[0]);
      uVar6 = param_4;
      if (param_4 != 0) {
        uVar6 = 1;
      }
      if (param_4 < uVar5) {
        uVar6 = 0;
      }
      param_2 = iVar1;
    } while (uVar6 != 0);
  }
  return 1;
}

