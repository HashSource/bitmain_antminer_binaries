
undefined4 des_cfb64_cipher(undefined4 param_1,uchar *param_2,uchar *param_3,uint param_4)

{
  DES_key_schedule *pDVar1;
  DES_cblock *pauVar2;
  int iVar3;
  uchar *out;
  uchar *in;
  uint uVar4;
  uchar *local_38;
  uchar *local_34;
  int local_2c [2];
  
  local_38 = param_2;
  local_34 = param_3;
  if (0x3fffffff < param_4) {
    out = param_2;
    in = param_3;
    uVar4 = param_4;
    do {
      uVar4 = uVar4 + 0xc0000000;
      local_2c[0] = EVP_CIPHER_CTX_num(param_1);
      pDVar1 = (DES_key_schedule *)EVP_CIPHER_CTX_get_cipher_data(param_1);
      pauVar2 = (DES_cblock *)EVP_CIPHER_CTX_iv_noconst(param_1);
      iVar3 = EVP_CIPHER_CTX_encrypting(param_1);
      DES_cfb64_encrypt(in,out,0x40000000,pDVar1,pauVar2,local_2c,iVar3);
      EVP_CIPHER_CTX_set_num(param_1,local_2c[0]);
      in = in + 0x40000000;
      out = out + 0x40000000;
    } while (0x3fffffff < uVar4);
    uVar4 = param_4 + 0xc0000000;
    param_4 = param_4 & 0x3fffffff;
    iVar3 = (uVar4 & 0xc0000000) + 0x40000000;
    local_34 = param_3 + iVar3;
    local_38 = param_2 + iVar3;
  }
  if (param_4 != 0) {
    local_2c[0] = EVP_CIPHER_CTX_num(param_1);
    pDVar1 = (DES_key_schedule *)EVP_CIPHER_CTX_get_cipher_data(param_1);
    pauVar2 = (DES_cblock *)EVP_CIPHER_CTX_iv_noconst(param_1);
    iVar3 = EVP_CIPHER_CTX_encrypting(param_1);
    DES_cfb64_encrypt(local_34,local_38,param_4,pDVar1,pauVar2,local_2c,iVar3);
    EVP_CIPHER_CTX_set_num(param_1,local_2c[0]);
  }
  return 1;
}

