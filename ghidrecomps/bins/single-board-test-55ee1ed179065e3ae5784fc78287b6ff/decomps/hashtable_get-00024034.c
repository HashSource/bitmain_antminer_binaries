
undefined4 hashtable_get(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int extraout_r1;
  int iVar3;
  
  uVar1 = hash_str(param_2);
  iVar3 = *(int *)(param_1 + 4);
  uVar2 = num_buckets(param_1);
  __aeabi_uidivmod(uVar1,uVar2);
  iVar3 = hashtable_find_pair(param_1,iVar3 + extraout_r1 * 8,param_2,uVar1);
  if (iVar3 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(iVar3 + 0xc);
  }
  return uVar1;
}

