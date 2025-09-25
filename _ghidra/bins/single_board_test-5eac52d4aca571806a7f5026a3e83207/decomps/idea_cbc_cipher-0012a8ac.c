
undefined4 idea_cbc_cipher(undefined4 param_1,int param_2,int param_3,uint param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int local_2c;
  
  iVar4 = param_2;
  iVar5 = param_3;
  uVar6 = param_4;
  local_2c = param_3;
  if (0x3fffffff < param_4) {
    do {
      uVar6 = uVar6 + 0xc0000000;
      uVar1 = EVP_CIPHER_CTX_get_cipher_data(param_1);
      uVar2 = EVP_CIPHER_CTX_iv_noconst(param_1);
      uVar3 = EVP_CIPHER_CTX_encrypting(param_1);
      IDEA_cbc_encrypt(iVar5,iVar4,0x40000000,uVar1,uVar2,uVar3);
      iVar4 = iVar4 + 0x40000000;
      iVar5 = iVar5 + 0x40000000;
    } while (0x3fffffff < uVar6);
    uVar6 = param_4 + 0xc0000000;
    param_4 = param_4 & 0x3fffffff;
    local_2c = (uVar6 & 0xc0000000) + 0x40000000;
    param_2 = param_2 + local_2c;
    local_2c = param_3 + local_2c;
  }
  if (param_4 != 0) {
    uVar1 = EVP_CIPHER_CTX_get_cipher_data(param_1);
    uVar2 = EVP_CIPHER_CTX_iv_noconst(param_1);
    uVar3 = EVP_CIPHER_CTX_encrypting(param_1);
    IDEA_cbc_encrypt(local_2c,param_2,param_4,uVar1,uVar2,uVar3);
  }
  return 1;
}

