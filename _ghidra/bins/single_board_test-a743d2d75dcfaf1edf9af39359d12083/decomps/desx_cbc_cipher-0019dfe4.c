
undefined4 desx_cbc_cipher(int param_1,uchar *param_2,uchar *param_3,uint param_4)

{
  DES_key_schedule *pDVar1;
  int iVar2;
  uchar *output;
  uchar *input;
  uint uVar3;
  uchar *local_2c;
  
  local_2c = param_2;
  if (0x3fffffff < param_4) {
    output = param_2;
    input = param_3;
    uVar3 = param_4;
    do {
      pDVar1 = *(DES_key_schedule **)(param_1 + 0x60);
      uVar3 = uVar3 + 0xc0000000;
      DES_xcbc_encrypt(input,output,0x40000000,pDVar1,(DES_cblock *)(param_1 + 0x20),
                       (const_DES_cblock *)(pDVar1 + 1),(const_DES_cblock *)(pDVar1[1].ks + 1),
                       *(int *)(param_1 + 8));
      output = output + 0x40000000;
      input = input + 0x40000000;
    } while (0x3fffffff < uVar3);
    uVar3 = param_4 + 0xc0000000;
    param_4 = param_4 & 0x3fffffff;
    iVar2 = (uVar3 & 0xc0000000) + 0x40000000;
    param_3 = param_3 + iVar2;
    local_2c = param_2 + iVar2;
  }
  if (param_4 != 0) {
    pDVar1 = *(DES_key_schedule **)(param_1 + 0x60);
    DES_xcbc_encrypt(param_3,local_2c,param_4,pDVar1,(DES_cblock *)(param_1 + 0x20),
                     (const_DES_cblock *)(pDVar1 + 1),(const_DES_cblock *)(pDVar1[1].ks + 1),
                     *(int *)(param_1 + 8));
  }
  return 1;
}

