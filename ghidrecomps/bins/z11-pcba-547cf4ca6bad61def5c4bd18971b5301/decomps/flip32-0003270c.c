
void flip32(int param_1,int param_2)

{
  undefined4 uVar1;
  int local_14;
  
  for (local_14 = 0; local_14 < 8; local_14 = local_14 + 1) {
    uVar1 = swab32(*(undefined4 *)(local_14 * 4 + param_2));
    *(undefined4 *)(param_1 + local_14 * 4) = uVar1;
  }
  return;
}

