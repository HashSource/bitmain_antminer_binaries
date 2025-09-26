
undefined4 des_cbc_cipher(int param_1,uchar *param_2,uchar *param_3,uint param_4)

{
  int iVar1;
  uchar *input;
  uchar *output;
  uint uVar2;
  DES_key_schedule *schedule;
  uchar *local_2c;
  
  schedule = *(DES_key_schedule **)(param_1 + 0x60);
  if ((code *)schedule[1].ks[0].deslong[0] == (code *)0x0) {
    if (param_4 < 0x40000000) {
      local_2c = param_2;
      if (param_4 == 0) {
        return 1;
      }
    }
    else {
      input = param_3;
      output = param_2;
      uVar2 = param_4;
      while( true ) {
        uVar2 = uVar2 + 0xc0000000;
        DES_ncbc_encrypt(input,output,0x40000000,schedule,(DES_cblock *)(param_1 + 0x20),
                         *(int *)(param_1 + 8));
        if (uVar2 < 0x40000000) break;
        schedule = *(DES_key_schedule **)(param_1 + 0x60);
        input = input + 0x40000000;
        output = output + 0x40000000;
      }
      uVar2 = param_4 + 0xc0000000;
      param_4 = param_4 & 0x3fffffff;
      iVar1 = (uVar2 & 0xc0000000) + 0x40000000;
      local_2c = param_2 + iVar1;
      param_3 = param_3 + iVar1;
      if (param_4 == 0) {
        return 1;
      }
    }
    DES_ncbc_encrypt(param_3,local_2c,param_4,*(DES_key_schedule **)(param_1 + 0x60),
                     (DES_cblock *)(param_1 + 0x20),*(int *)(param_1 + 8));
  }
  else {
    (*(code *)schedule[1].ks[0].deslong[0])(param_3,param_2,param_4,schedule,param_1 + 0x20);
  }
  return 1;
}

