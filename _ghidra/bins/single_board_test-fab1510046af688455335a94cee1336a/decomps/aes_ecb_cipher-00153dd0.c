
undefined4 aes_ecb_cipher(int *param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  iVar4 = param_1[0x18];
  uVar5 = *(uint *)(*param_1 + 4);
  if (uVar5 <= param_4) {
    uVar3 = 0;
    do {
      iVar1 = param_3 + uVar3;
      iVar2 = param_2 + uVar3;
      uVar3 = uVar3 + uVar5;
      (**(code **)(iVar4 + 0xf8))(iVar1,iVar2,iVar4);
    } while (uVar3 <= param_4 - uVar5);
  }
  return 1;
}

