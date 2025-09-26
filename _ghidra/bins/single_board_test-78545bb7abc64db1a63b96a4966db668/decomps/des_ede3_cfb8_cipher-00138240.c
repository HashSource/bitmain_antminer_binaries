
undefined4 des_ede3_cfb8_cipher(undefined4 param_1,uchar *param_2,uchar *param_3,uint param_4)

{
  DES_key_schedule *pDVar1;
  int iVar2;
  int iVar3;
  DES_cblock *pauVar4;
  int iVar5;
  uchar *out;
  uchar *in;
  uint uVar6;
  uchar *local_34;
  uchar *local_30;
  
  out = param_2;
  in = param_3;
  uVar6 = param_4;
  local_34 = param_2;
  local_30 = param_3;
  if (0x3fffffff < param_4) {
    do {
      uVar6 = uVar6 + 0xc0000000;
      pDVar1 = (DES_key_schedule *)EVP_CIPHER_CTX_get_cipher_data(param_1);
      iVar2 = EVP_CIPHER_CTX_get_cipher_data(param_1);
      iVar3 = EVP_CIPHER_CTX_get_cipher_data(param_1);
      pauVar4 = (DES_cblock *)EVP_CIPHER_CTX_iv_noconst(param_1);
      iVar5 = EVP_CIPHER_CTX_encrypting(param_1);
      DES_ede3_cfb_encrypt
                (in,out,8,0x40000000,pDVar1,(DES_key_schedule *)(iVar2 + 0x80),
                 (DES_key_schedule *)(iVar3 + 0x100),pauVar4,iVar5);
      out = out + 0x40000000;
      in = in + 0x40000000;
    } while (0x3fffffff < uVar6);
    uVar6 = param_4 + 0xc0000000;
    param_4 = param_4 & 0x3fffffff;
    iVar2 = (uVar6 & 0xc0000000) + 0x40000000;
    local_30 = param_3 + iVar2;
    local_34 = param_2 + iVar2;
  }
  if (param_4 != 0) {
    pDVar1 = (DES_key_schedule *)EVP_CIPHER_CTX_get_cipher_data(param_1);
    iVar2 = EVP_CIPHER_CTX_get_cipher_data(param_1);
    iVar3 = EVP_CIPHER_CTX_get_cipher_data(param_1);
    pauVar4 = (DES_cblock *)EVP_CIPHER_CTX_iv_noconst(param_1);
    iVar5 = EVP_CIPHER_CTX_encrypting(param_1);
    DES_ede3_cfb_encrypt
              (local_30,local_34,8,param_4,pDVar1,(DES_key_schedule *)(iVar2 + 0x80),
               (DES_key_schedule *)(iVar3 + 0x100),pauVar4,iVar5);
  }
  return 1;
}

