
uint send_certificate_request(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = *(uint *)(param_1 + 0x4ac);
  uVar2 = uVar1 & 1;
  if ((uVar2 != 0) &&
     ((((*(int *)((*(int **)(param_1 + 4))[0x19] + 0x30) << 0x1c < 0 ||
        (iVar3 = **(int **)(param_1 + 4), iVar3 < 0x304 || iVar3 == 0x10000)) ||
       (-1 < (int)(uVar1 << 0x1c))) || (uVar2 = 0, *(int *)(param_1 + 0x5f4) == 3)))) {
    if ((*(int *)(param_1 + 0x604) < 1) || (-1 < (int)(uVar1 << 0x1d))) {
      iVar3 = *(int *)(*(int *)(param_1 + 0x7c) + 0x210);
      if ((-1 < *(int *)(iVar3 + 0x14) << 0x1d) || (uVar1 = uVar1 & 2, uVar1 != 0)) {
        return (uint)((*(uint *)(iVar3 + 0x14) & 0x50) == 0);
      }
    }
    else {
      uVar1 = 0;
    }
    return uVar1;
  }
  return uVar2;
}

