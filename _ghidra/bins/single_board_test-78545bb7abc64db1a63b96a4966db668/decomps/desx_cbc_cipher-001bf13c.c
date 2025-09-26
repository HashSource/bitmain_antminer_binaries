
undefined4 desx_cbc_cipher(undefined4 param_1,uchar *param_2,uchar *param_3,uint param_4)

{
  DES_key_schedule *pDVar1;
  DES_cblock *pauVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uchar *output;
  uchar *input;
  uint uVar6;
  uchar *local_34;
  uchar *local_30;
  
  output = param_2;
  input = param_3;
  uVar6 = param_4;
  local_34 = param_2;
  local_30 = param_3;
  if (0x3fffffff < param_4) {
    do {
      uVar6 = uVar6 + 0xc0000000;
      pDVar1 = (DES_key_schedule *)EVP_CIPHER_CTX_get_cipher_data(param_1);
      pauVar2 = (DES_cblock *)EVP_CIPHER_CTX_iv_noconst(param_1);
      iVar3 = EVP_CIPHER_CTX_get_cipher_data(param_1);
      iVar4 = EVP_CIPHER_CTX_get_cipher_data(param_1);
      iVar5 = EVP_CIPHER_CTX_encrypting(param_1);
      DES_xcbc_encrypt(input,output,0x40000000,pDVar1,pauVar2,(const_DES_cblock *)(iVar3 + 0x80),
                       (const_DES_cblock *)(iVar4 + 0x88),iVar5);
      output = output + 0x40000000;
      input = input + 0x40000000;
    } while (0x3fffffff < uVar6);
    uVar6 = param_4 + 0xc0000000;
    param_4 = param_4 & 0x3fffffff;
    iVar3 = (uVar6 & 0xc0000000) + 0x40000000;
    local_30 = param_3 + iVar3;
    local_34 = param_2 + iVar3;
  }
  if (param_4 != 0) {
    pDVar1 = (DES_key_schedule *)EVP_CIPHER_CTX_get_cipher_data(param_1);
    pauVar2 = (DES_cblock *)EVP_CIPHER_CTX_iv_noconst(param_1);
    iVar3 = EVP_CIPHER_CTX_get_cipher_data(param_1);
    iVar4 = EVP_CIPHER_CTX_get_cipher_data(param_1);
    iVar5 = EVP_CIPHER_CTX_encrypting(param_1);
    DES_xcbc_encrypt(local_30,local_34,param_4,pDVar1,pauVar2,(const_DES_cblock *)(iVar3 + 0x80),
                     (const_DES_cblock *)(iVar4 + 0x88),iVar5);
  }
  return 1;
}

