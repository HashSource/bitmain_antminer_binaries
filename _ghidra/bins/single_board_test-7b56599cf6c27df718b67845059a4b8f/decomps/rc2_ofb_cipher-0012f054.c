
undefined4 rc2_ofb_cipher(undefined4 param_1,uchar *param_2,uchar *param_3,uint param_4)

{
  int iVar1;
  uchar *ivec;
  uchar *puVar2;
  uchar *in;
  uint uVar3;
  uchar *local_34;
  int local_2c [2];
  
  local_34 = param_3;
  if (0x3fffffff < param_4) {
    puVar2 = param_2;
    in = param_3;
    uVar3 = param_4;
    do {
      uVar3 = uVar3 + 0xc0000000;
      local_2c[0] = EVP_CIPHER_CTX_num(param_1);
      iVar1 = EVP_CIPHER_CTX_get_cipher_data(param_1);
      ivec = (uchar *)EVP_CIPHER_CTX_iv_noconst(param_1);
      RC2_ofb64_encrypt(in,puVar2,0x40000000,(RC2_KEY *)(iVar1 + 4),ivec,local_2c);
      EVP_CIPHER_CTX_set_num(param_1,local_2c[0]);
      in = in + 0x40000000;
      puVar2 = puVar2 + 0x40000000;
    } while (0x3fffffff < uVar3);
    uVar3 = param_4 + 0xc0000000;
    param_4 = param_4 & 0x3fffffff;
    iVar1 = (uVar3 & 0xc0000000) + 0x40000000;
    param_2 = param_2 + iVar1;
    local_34 = param_3 + iVar1;
  }
  if (param_4 != 0) {
    local_2c[0] = EVP_CIPHER_CTX_num(param_1);
    iVar1 = EVP_CIPHER_CTX_get_cipher_data(param_1);
    puVar2 = (uchar *)EVP_CIPHER_CTX_iv_noconst(param_1);
    RC2_ofb64_encrypt(local_34,param_2,param_4,(RC2_KEY *)(iVar1 + 4),puVar2,local_2c);
    EVP_CIPHER_CTX_set_num(param_1,local_2c[0]);
  }
  return 1;
}

