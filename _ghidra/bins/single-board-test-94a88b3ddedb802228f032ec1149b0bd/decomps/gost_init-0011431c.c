
void gost_init(int param_1,undefined1 *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = 0;
  if (param_2 == (undefined1 *)0x0) {
    param_2 = &GostR3411_94_TestParamSet;
  }
  do {
    iVar3 = (int)uVar2 >> 4;
    uVar1 = uVar2 & 0xf;
    uVar2 = uVar2 + 1;
    *(uint *)(param_1 + 0x20) =
         ((uint)(byte)param_2[uVar1 + 0x10] | (uint)(byte)param_2[iVar3] << 4) << 0x18;
    *(uint *)(param_1 + 0x420) =
         ((uint)(byte)param_2[uVar1 + 0x30] | (uint)(byte)param_2[iVar3 + 0x20] << 4) << 0x10;
    *(uint *)(param_1 + 0x820) =
         ((uint)(byte)param_2[uVar1 + 0x50] | (uint)(byte)param_2[iVar3 + 0x40] << 4) << 8;
    *(uint *)(param_1 + 0xc20) =
         (uint)(byte)param_2[uVar1 + 0x70] | (uint)(byte)param_2[iVar3 + 0x60] << 4;
    param_1 = param_1 + 4;
  } while (uVar2 != 0x100);
  return;
}

