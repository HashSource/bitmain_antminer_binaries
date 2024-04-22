
undefined4 des_ede_cbc_cipher(int param_1,uchar *param_2,uchar *param_3,uint param_4)

{
  int iVar1;
  uchar *output;
  uchar *input;
  uint uVar2;
  DES_key_schedule *ks1;
  uchar *local_30;
  uchar *local_2c;
  
  ks1 = *(DES_key_schedule **)(param_1 + 0x60);
  if ((code *)ks1[3].ks[0].deslong[0] == (code *)0x0) {
    local_30 = param_3;
    local_2c = param_2;
    if (0x3fffffff < param_4) {
      output = param_2;
      input = param_3;
      uVar2 = param_4;
      do {
        uVar2 = uVar2 + 0xc0000000;
        DES_ede3_cbc_encrypt
                  (input,output,0x40000000,ks1,ks1 + 1,ks1 + 2,(DES_cblock *)(param_1 + 0x20),
                   *(int *)(param_1 + 8));
        output = output + 0x40000000;
        input = input + 0x40000000;
      } while (0x3fffffff < uVar2);
      uVar2 = param_4 + 0xc0000000;
      param_4 = param_4 & 0x3fffffff;
      iVar1 = (uVar2 & 0xc0000000) + 0x40000000;
      local_30 = param_3 + iVar1;
      local_2c = param_2 + iVar1;
    }
    if (param_4 != 0) {
      DES_ede3_cbc_encrypt
                (local_30,local_2c,param_4,ks1,ks1 + 1,ks1 + 2,(DES_cblock *)(param_1 + 0x20),
                 *(int *)(param_1 + 8));
    }
  }
  else {
    (*(code *)ks1[3].ks[0].deslong[0])(param_3,param_2,param_4,ks1,param_1 + 0x20);
  }
  return 1;
}

