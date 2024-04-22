
undefined4 hashtable_do_rehash(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int extraout_r1;
  int iVar4;
  int iVar5;
  uint local_10;
  int local_c;
  
  jsonp_free(*(undefined4 *)(param_1 + 4));
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  iVar1 = num_buckets(param_1);
  uVar2 = jsonp_malloc(iVar1 << 3);
  *(undefined4 *)(param_1 + 4) = uVar2;
  if (*(int *)(param_1 + 4) == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    for (local_10 = 0; uVar3 = num_buckets(param_1), local_10 < uVar3; local_10 = local_10 + 1) {
      iVar5 = *(int *)(param_1 + 4);
      iVar4 = *(int *)(param_1 + 4) + local_10 * 8;
      *(int *)(iVar4 + 4) = param_1 + 0xc;
      *(undefined4 *)(iVar5 + local_10 * 8) = *(undefined4 *)(iVar4 + 4);
    }
    local_c = *(int *)(param_1 + 0x10);
    list_init(param_1 + 0xc);
    while (param_1 + 0xc != local_c) {
      iVar5 = *(int *)(local_c + 4);
      __aeabi_uidivmod(*(undefined4 *)(local_c + -4),iVar1);
      insert_to_bucket(param_1,*(int *)(param_1 + 4) + extraout_r1 * 8,local_c);
      local_c = iVar5;
    }
    uVar2 = 0;
  }
  return uVar2;
}

