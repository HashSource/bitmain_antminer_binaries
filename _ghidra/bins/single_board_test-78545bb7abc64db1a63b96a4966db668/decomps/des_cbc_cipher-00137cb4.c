
undefined4 des_cbc_cipher(undefined4 param_1,uchar *param_2,uchar *param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  DES_key_schedule *pDVar3;
  DES_cblock *pauVar4;
  code *pcVar5;
  uchar *input;
  uchar *output;
  uint uVar6;
  uchar *local_2c;
  
  iVar1 = EVP_CIPHER_CTX_get_cipher_data();
  pcVar5 = *(code **)(iVar1 + 0x80);
  if (pcVar5 == (code *)0x0) {
    input = param_3;
    output = param_2;
    uVar6 = param_4;
    if (param_4 < 0x40000000) {
      local_2c = param_3;
      if (param_4 != 0) goto LAB_00137d4a;
    }
    else {
      do {
        uVar6 = uVar6 + 0xc0000000;
        pDVar3 = (DES_key_schedule *)EVP_CIPHER_CTX_get_cipher_data(param_1);
        pauVar4 = (DES_cblock *)EVP_CIPHER_CTX_iv_noconst(param_1);
        iVar1 = EVP_CIPHER_CTX_encrypting(param_1);
        DES_ncbc_encrypt(input,output,0x40000000,pDVar3,pauVar4,iVar1);
        input = input + 0x40000000;
        output = output + 0x40000000;
      } while (0x3fffffff < uVar6);
      uVar6 = param_4 + 0xc0000000;
      param_4 = param_4 & 0x3fffffff;
      iVar1 = (uVar6 & 0xc0000000) + 0x40000000;
      local_2c = param_3 + iVar1;
      param_2 = param_2 + iVar1;
      if (param_4 != 0) {
LAB_00137d4a:
        pDVar3 = (DES_key_schedule *)EVP_CIPHER_CTX_get_cipher_data(param_1);
        pauVar4 = (DES_cblock *)EVP_CIPHER_CTX_iv_noconst(param_1);
        iVar1 = EVP_CIPHER_CTX_encrypting(param_1);
        DES_ncbc_encrypt(local_2c,param_2,param_4,pDVar3,pauVar4,iVar1);
        return 1;
      }
    }
  }
  else {
    uVar2 = EVP_CIPHER_CTX_iv_noconst(param_1);
    (*pcVar5)(param_3,param_2,param_4,iVar1,uVar2);
  }
  return 1;
}

