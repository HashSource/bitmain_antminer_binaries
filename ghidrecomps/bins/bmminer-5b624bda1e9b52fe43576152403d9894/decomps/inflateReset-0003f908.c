
undefined4 inflateReset(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if ((param_1 == 0) || (puVar4 = *(undefined4 **)(param_1 + 0x1c), puVar4 == (undefined4 *)0x0)) {
    uVar1 = 0xfffffffe;
  }
  else {
    uVar2 = puVar4[2];
    puVar4[10] = 0;
    puVar4[0xb] = 0;
    puVar4[0xc] = 0;
    puVar4[7] = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
    if (uVar2 != 0) {
      *(uint *)(param_1 + 0x30) = uVar2 & 1;
    }
    puVar3 = puVar4 + 0x14c;
    uVar1 = 0;
    *puVar4 = 0;
    puVar4[1] = 0;
    puVar4[3] = 0;
    puVar4[8] = 0;
    puVar4[0xe] = 0;
    puVar4[0xf] = 0;
    puVar4[5] = 0x8000;
    puVar4[0x1b] = puVar3;
    puVar4[0x14] = puVar3;
    puVar4[0x13] = puVar3;
    puVar4[0x6f0] = 1;
    puVar4[0x6f1] = 0xffffffff;
  }
  return uVar1;
}

