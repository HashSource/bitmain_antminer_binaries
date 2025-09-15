
int hashtable_iter_at(int param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  size_t sVar1;
  uint uVar2;
  int iVar3;
  
  sVar1 = strlen(param_2);
  uVar2 = hashlittle(param_2,sVar1,hashtable_seed,&hashtable_seed,param_4);
  iVar3 = hashtable_find_pair(param_1,*(int *)(param_1 + 4) +
                                      ((1 << (*(uint *)(param_1 + 8) & 0xff)) - 1U & uVar2) * 8,
                              param_2,uVar2);
  if (iVar3 != 0) {
    iVar3 = iVar3 + 8;
  }
  return iVar3;
}

