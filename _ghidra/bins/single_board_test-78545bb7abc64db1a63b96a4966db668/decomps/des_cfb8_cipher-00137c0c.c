
undefined4 des_cfb8_cipher(undefined4 param_1,uchar *param_2,uchar *param_3,uint param_4)

{
  DES_key_schedule *pDVar1;
  DES_cblock *pauVar2;
  int iVar3;
  uchar *out;
  uchar *in;
  uint uVar4;
  uchar *local_2c;
  
  out = param_2;
  in = param_3;
  uVar4 = param_4;
  local_2c = param_3;
  if (0x3fffffff < param_4) {
    do {
      uVar4 = uVar4 + 0xc0000000;
      pDVar1 = (DES_key_schedule *)EVP_CIPHER_CTX_get_cipher_data(param_1);
      pauVar2 = (DES_cblock *)EVP_CIPHER_CTX_iv_noconst(param_1);
      iVar3 = EVP_CIPHER_CTX_encrypting(param_1);
      DES_cfb_encrypt(in,out,8,0x40000000,pDVar1,pauVar2,iVar3);
      out = out + 0x40000000;
      in = in + 0x40000000;
    } while (0x3fffffff < uVar4);
    uVar4 = param_4 + 0xc0000000;
    param_4 = param_4 & 0x3fffffff;
    iVar3 = (uVar4 & 0xc0000000) + 0x40000000;
    param_2 = param_2 + iVar3;
    local_2c = param_3 + iVar3;
  }
  if (param_4 != 0) {
    pDVar1 = (DES_key_schedule *)EVP_CIPHER_CTX_get_cipher_data(param_1);
    pauVar2 = (DES_cblock *)EVP_CIPHER_CTX_iv_noconst(param_1);
    iVar3 = EVP_CIPHER_CTX_encrypting(param_1);
    DES_cfb_encrypt(local_2c,param_2,8,param_4,pDVar1,pauVar2,iVar3);
  }
  return 1;
}

