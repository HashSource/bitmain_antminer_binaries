
void i2d_DHxparams(int param_1)

{
  int **ppiVar1;
  int iVar2;
  int **ppiVar3;
  int *local_3c;
  int **local_38;
  int local_34 [2];
  int **local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int **local_14;
  
  ppiVar3 = *(int ***)(param_1 + 0x34);
  local_18 = *(undefined4 *)(param_1 + 0x28);
  local_24 = *(undefined4 *)(param_1 + 8);
  local_1c = *(undefined4 *)(param_1 + 0xc);
  local_20 = *(undefined4 *)(param_1 + 0x24);
  local_14 = ppiVar3;
  if ((ppiVar3 != (int **)0x0) && (local_14 = *(int ***)(param_1 + 0x2c), local_14 != (int **)0x0))
  {
    iVar2 = *(int *)(param_1 + 0x30);
    ppiVar1 = local_14;
    if (iVar2 < 1) {
      local_14 = (int **)0x0;
      ppiVar1 = local_2c;
    }
    local_2c = ppiVar1;
    if (0 < iVar2) {
      local_3c = local_34;
      local_28 = 8;
      local_14 = &local_3c;
      local_38 = ppiVar3;
      local_34[0] = iVar2;
    }
  }
  i2d_int_dhx(&local_24);
  return;
}

