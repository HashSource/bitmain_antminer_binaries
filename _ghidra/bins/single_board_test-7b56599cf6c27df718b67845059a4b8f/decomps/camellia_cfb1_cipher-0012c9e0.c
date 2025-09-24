
undefined4 camellia_cfb1_cipher(EVP_CIPHER_CTX *param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int local_38;
  int local_34;
  undefined4 local_2c [2];
  
  iVar1 = EVP_CIPHER_CTX_get_cipher_data();
  iVar2 = EVP_CIPHER_CTX_test_flags(param_1,0x2000);
  if (iVar2 != 0) {
    local_2c[0] = EVP_CIPHER_CTX_num(param_1);
    uVar3 = EVP_CIPHER_CTX_iv_noconst(param_1);
    uVar4 = EVP_CIPHER_CTX_encrypting(param_1);
    CRYPTO_cfb128_1_encrypt
              (param_3,param_2,param_4,iVar1,uVar3,local_2c,uVar4,*(undefined4 *)(iVar1 + 0x118));
    EVP_CIPHER_CTX_set_num(param_1,local_2c[0]);
    return 1;
  }
  local_38 = param_2;
  local_34 = param_3;
  if (0xfffffff < param_4) {
    iVar2 = param_2;
    iVar5 = param_3;
    uVar6 = param_4;
    do {
      uVar6 = uVar6 + 0xf0000000;
      local_2c[0] = EVP_CIPHER_CTX_num(param_1);
      uVar3 = EVP_CIPHER_CTX_iv_noconst(param_1);
      uVar4 = EVP_CIPHER_CTX_encrypting(param_1);
      CRYPTO_cfb128_1_encrypt
                (iVar5,iVar2,0x80000000,iVar1,uVar3,local_2c,uVar4,*(undefined4 *)(iVar1 + 0x118));
      EVP_CIPHER_CTX_set_num(param_1,local_2c[0]);
      iVar5 = iVar5 + 0x10000000;
      iVar2 = iVar2 + 0x10000000;
    } while (0xfffffff < uVar6);
    uVar6 = param_4 + 0xf0000000;
    param_4 = param_4 & 0xfffffff;
    local_34 = (uVar6 & 0xf0000000) + 0x10000000;
    local_38 = param_2 + local_34;
    local_34 = param_3 + local_34;
  }
  if (param_4 == 0) {
    return 1;
  }
  local_2c[0] = EVP_CIPHER_CTX_num(param_1);
  uVar3 = EVP_CIPHER_CTX_iv_noconst(param_1);
  uVar4 = EVP_CIPHER_CTX_encrypting(param_1);
  CRYPTO_cfb128_1_encrypt
            (local_34,local_38,param_4 << 3,iVar1,uVar3,local_2c,uVar4,
             *(undefined4 *)(iVar1 + 0x118));
  EVP_CIPHER_CTX_set_num(param_1,local_2c[0]);
  return 1;
}

