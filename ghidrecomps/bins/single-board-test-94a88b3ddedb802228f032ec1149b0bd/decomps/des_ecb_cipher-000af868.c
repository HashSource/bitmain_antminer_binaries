
undefined4 des_ecb_cipher(int *param_1,int param_2,int param_3,uint param_4)

{
  const_DES_cblock *input;
  DES_cblock *output;
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(*param_1 + 4);
  if (uVar2 <= param_4) {
    uVar1 = 0;
    do {
      input = (const_DES_cblock *)(param_3 + uVar1);
      output = (DES_cblock *)(param_2 + uVar1);
      uVar1 = uVar1 + uVar2;
      DES_ecb_encrypt(input,output,(DES_key_schedule *)param_1[0x18],param_1[2]);
    } while (uVar1 <= param_4 - uVar2);
  }
  return 1;
}

