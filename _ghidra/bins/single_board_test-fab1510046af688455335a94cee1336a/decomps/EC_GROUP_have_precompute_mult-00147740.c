
int EC_GROUP_have_precompute_mult(EC_GROUP *group)

{
  int iVar1;
  code *pcVar2;
  
  if (*(int *)(*(int *)group + 0x78) == 0) {
    iVar1 = ec_wNAF_have_precompute_mult();
    return iVar1;
  }
  pcVar2 = *(code **)(*(int *)group + 0x80);
  if (pcVar2 != (code *)0x0) {
    iVar1 = (*pcVar2)();
    return iVar1;
  }
  return 0;
}

