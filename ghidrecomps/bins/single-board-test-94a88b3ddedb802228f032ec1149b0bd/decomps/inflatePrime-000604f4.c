
undefined4 inflatePrime(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if ((param_1 != 0) && (iVar2 = *(int *)(param_1 + 0x1c), iVar2 != 0)) {
    if ((int)param_2 < 0) {
      *(undefined4 *)(iVar2 + 0x38) = 0;
      *(undefined4 *)(iVar2 + 0x3c) = 0;
      return 0;
    }
    if ((int)param_2 < 0x11) {
      uVar3 = *(uint *)(iVar2 + 0x3c);
      uVar1 = param_2 + uVar3;
      if (uVar1 < 0x21) {
        *(uint *)(iVar2 + 0x3c) = uVar1;
        *(uint *)(iVar2 + 0x38) =
             *(int *)(iVar2 + 0x38) + ((param_3 & (1 << (param_2 & 0xff)) - 1U) << (uVar3 & 0xff));
        return 0;
      }
    }
  }
  return 0xfffffffe;
}

