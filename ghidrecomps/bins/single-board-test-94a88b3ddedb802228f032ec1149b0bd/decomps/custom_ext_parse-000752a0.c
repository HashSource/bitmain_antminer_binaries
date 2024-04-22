
undefined4
custom_ext_parse(int param_1,int param_2,uint param_3,undefined4 param_4,undefined4 param_5,
                undefined4 *param_6)

{
  ushort uVar1;
  undefined4 uVar2;
  ushort **ppuVar3;
  ushort *puVar4;
  ushort *puVar5;
  
  if (param_2 == 0) {
    ppuVar3 = (ushort **)(*(int *)(param_1 + 0x98) + 0x15c);
  }
  else {
    ppuVar3 = (ushort **)(*(int *)(param_1 + 0x98) + 0x164);
  }
  puVar4 = *ppuVar3;
  if (ppuVar3[1] != (ushort *)0x0) {
    if (param_3 != *puVar4) {
      puVar5 = (ushort *)0x0;
      do {
        puVar5 = (ushort *)((int)puVar5 + 1);
        puVar4 = puVar4 + 0xc;
        if (puVar5 == ppuVar3[1]) {
          return 1;
        }
      } while (param_3 != *puVar4);
    }
    uVar1 = puVar4[1];
    if ((param_2 == 0) && ((uVar1 & 2) == 0)) {
      *param_6 = 0x6e;
      return 0;
    }
    if ((int)((uint)uVar1 << 0x1f) < 0) {
      *param_6 = 0x32;
      return 0;
    }
    puVar4[1] = uVar1 | 1;
    if (*(code **)(puVar4 + 8) != (code *)0x0) {
      uVar2 = (**(code **)(puVar4 + 8))
                        (param_1,param_3,param_4,param_5,param_6,*(undefined4 *)(puVar4 + 10));
      return uVar2;
    }
  }
  return 1;
}

