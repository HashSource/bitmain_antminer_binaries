
undefined4 des_ede_cbc_cipher(undefined4 param_1,uchar *param_2,uchar *param_3,uint param_4)

{
  DES_key_schedule *ks1;
  undefined4 uVar1;
  DES_cblock *pauVar2;
  int iVar3;
  code *pcVar4;
  uchar *output;
  uchar *input;
  uint uVar5;
  uchar *local_34;
  uchar *local_30;
  
  ks1 = (DES_key_schedule *)EVP_CIPHER_CTX_get_cipher_data();
  pcVar4 = (code *)ks1[3].ks[0].deslong[0];
  if (pcVar4 == (code *)0x0) {
    local_34 = param_2;
    local_30 = param_3;
    if (0x3fffffff < param_4) {
      output = param_2;
      input = param_3;
      uVar5 = param_4;
      do {
        uVar5 = uVar5 + 0xc0000000;
        pauVar2 = (DES_cblock *)EVP_CIPHER_CTX_iv_noconst(param_1);
        iVar3 = EVP_CIPHER_CTX_encrypting(param_1);
        DES_ede3_cbc_encrypt(input,output,0x40000000,ks1,ks1 + 1,ks1 + 2,pauVar2,iVar3);
        output = output + 0x40000000;
        input = input + 0x40000000;
      } while (0x3fffffff < uVar5);
      uVar5 = param_4 + 0xc0000000;
      param_4 = param_4 & 0x3fffffff;
      iVar3 = (uVar5 & 0xc0000000) + 0x40000000;
      local_30 = param_3 + iVar3;
      local_34 = param_2 + iVar3;
    }
    if (param_4 != 0) {
      pauVar2 = (DES_cblock *)EVP_CIPHER_CTX_iv_noconst(param_1);
      iVar3 = EVP_CIPHER_CTX_encrypting(param_1);
      DES_ede3_cbc_encrypt(local_30,local_34,param_4,ks1,ks1 + 1,ks1 + 2,pauVar2,iVar3);
      return 1;
    }
  }
  else {
    uVar1 = EVP_CIPHER_CTX_iv_noconst(param_1);
    (*pcVar4)(param_3,param_2,param_4,ks1,uVar1);
  }
  return 1;
}

