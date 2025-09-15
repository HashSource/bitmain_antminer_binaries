
void stratum_resumed(int param_1)

{
  int iVar1;
  
  iVar1 = pool_tclear(param_1,param_1 + 0x61);
  if (iVar1 != 0) {
    stratum_resumed_part_50(param_1);
    return;
  }
  return;
}

