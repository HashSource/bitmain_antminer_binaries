
undefined4 idea_ofb_cipher(undefined4 param_1,int param_2,int param_3,uint param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int local_34;
  undefined4 local_2c [2];
  
  local_34 = param_3;
  if (0x3fffffff < param_4) {
    iVar3 = param_2;
    iVar4 = param_3;
    uVar5 = param_4;
    do {
      uVar5 = uVar5 + 0xc0000000;
      local_2c[0] = EVP_CIPHER_CTX_num(param_1);
      uVar1 = EVP_CIPHER_CTX_get_cipher_data(param_1);
      uVar2 = EVP_CIPHER_CTX_iv_noconst(param_1);
      IDEA_ofb64_encrypt(iVar4,iVar3,0x40000000,uVar1,uVar2,local_2c);
      EVP_CIPHER_CTX_set_num(param_1,local_2c[0]);
      iVar4 = iVar4 + 0x40000000;
      iVar3 = iVar3 + 0x40000000;
    } while (0x3fffffff < uVar5);
    uVar5 = param_4 + 0xc0000000;
    param_4 = param_4 & 0x3fffffff;
    local_34 = (uVar5 & 0xc0000000) + 0x40000000;
    param_2 = param_2 + local_34;
    local_34 = param_3 + local_34;
  }
  if (param_4 != 0) {
    local_2c[0] = EVP_CIPHER_CTX_num(param_1);
    uVar1 = EVP_CIPHER_CTX_get_cipher_data(param_1);
    uVar2 = EVP_CIPHER_CTX_iv_noconst(param_1);
    IDEA_ofb64_encrypt(local_34,param_2,param_4,uVar1,uVar2,local_2c);
    EVP_CIPHER_CTX_set_num(param_1,local_2c[0]);
  }
  return 1;
}

