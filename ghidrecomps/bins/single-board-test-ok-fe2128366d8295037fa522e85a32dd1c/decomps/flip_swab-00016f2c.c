
void flip_swab(int param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  uint local_14;
  
  for (local_14 = 0; local_14 < param_3 >> 2; local_14 = local_14 + 1) {
    uVar1 = swab32(*(undefined4 *)(param_2 + local_14 * 4));
    *(undefined4 *)(param_1 + local_14 * 4) = uVar1;
  }
  return;
}

