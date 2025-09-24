
undefined4 WPACKET_set_max_size(int param_1,uint param_2)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  
  piVar3 = *(int **)(param_1 + 0x14);
  if (*(int **)(param_1 + 0x14) == (int *)0x0) {
    return 0;
  }
  do {
    piVar1 = piVar3;
    piVar3 = (int *)*piVar1;
  } while (piVar3 != (int *)0x0);
  uVar4 = piVar1[2];
  uVar2 = uVar4 - 1;
  if ((uVar2 < 3) && (uVar2 + (1 << ((uVar4 & 0x1f) << 3)) < param_2)) {
    return 0;
  }
  if (*(uint *)(param_1 + 0xc) <= param_2) {
    *(uint *)(param_1 + 0x10) = param_2;
    return 1;
  }
  return 0;
}

