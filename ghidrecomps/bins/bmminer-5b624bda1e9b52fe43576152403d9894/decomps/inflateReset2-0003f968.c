
undefined4 inflateReset2(int param_1,uint param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  if ((param_1 != 0) && (puVar3 = *(undefined4 **)(param_1 + 0x1c), puVar3 != (undefined4 *)0x0)) {
    if ((int)param_2 < 0) {
      param_2 = -param_2;
      iVar4 = 0;
    }
    else {
      iVar4 = (int)param_2 >> 4;
      if ((int)param_2 < 0x30) {
        param_2 = param_2 & 0xf;
      }
      iVar4 = iVar4 + 1;
    }
    if (param_2 == 0 || param_2 - 8 < 8) {
      if ((puVar3[0xd] == 0) || (param_2 == puVar3[9])) {
        puVar3[2] = iVar4;
        puVar3[9] = param_2;
      }
      else {
        (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28));
        puVar2 = *(undefined4 **)(param_1 + 0x1c);
        puVar3[0xd] = 0;
        puVar3[2] = iVar4;
        puVar3[9] = param_2;
        puVar3 = puVar2;
        if (puVar2 == (undefined4 *)0x0) {
          return 0xfffffffe;
        }
      }
      uVar1 = puVar3[2];
      puVar3[10] = 0;
      puVar3[0xb] = 0;
      puVar3[0xc] = 0;
      puVar3[7] = 0;
      *(undefined4 *)(param_1 + 0x14) = 0;
      *(undefined4 *)(param_1 + 8) = 0;
      *(undefined4 *)(param_1 + 0x18) = 0;
      if (uVar1 != 0) {
        *(uint *)(param_1 + 0x30) = uVar1 & 1;
      }
      puVar2 = puVar3 + 0x14c;
      *puVar3 = 0;
      puVar3[1] = 0;
      puVar3[3] = 0;
      puVar3[8] = 0;
      puVar3[0xe] = 0;
      puVar3[0xf] = 0;
      puVar3[5] = 0x8000;
      puVar3[0x1b] = puVar2;
      puVar3[0x14] = puVar2;
      puVar3[0x13] = puVar2;
      puVar3[0x6f0] = 1;
      puVar3[0x6f1] = 0xffffffff;
      return 0;
    }
  }
  return 0xfffffffe;
}

