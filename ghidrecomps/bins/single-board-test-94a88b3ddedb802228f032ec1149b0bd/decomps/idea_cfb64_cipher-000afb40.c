
undefined4 idea_cfb64_cipher(int param_1,uchar *param_2,uchar *param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uchar *puVar3;
  uchar *puVar4;
  
  uVar2 = param_4;
  if (0x3fffffff < param_4) {
    uVar2 = 0x40000000;
  }
  while (uVar1 = param_4 - uVar2, param_4 != 0 && uVar2 <= param_4) {
    puVar3 = param_3 + uVar2;
    puVar4 = param_2 + uVar2;
    if (uVar1 <= uVar2) {
      uVar2 = uVar1;
    }
    idea_cfb64_encrypt(param_3,param_2,param_4,*(IDEA_KEY_SCHEDULE **)(param_1 + 0x60),
                       (uchar *)(param_1 + 0x20),(int *)(param_1 + 0x50),*(int *)(param_1 + 8));
    param_4 = uVar1;
    param_3 = puVar3;
    param_2 = puVar4;
  }
  return 1;
}

