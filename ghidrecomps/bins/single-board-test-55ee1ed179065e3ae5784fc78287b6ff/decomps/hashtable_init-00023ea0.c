
undefined4 hashtable_init(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint local_c;
  
  *param_1 = 0;
  param_1[2] = 0;
  iVar1 = num_buckets(param_1);
  uVar2 = jsonp_malloc(iVar1 << 3);
  param_1[1] = uVar2;
  if (param_1[1] == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    list_init(param_1 + 3);
    for (local_c = 0; uVar3 = num_buckets(param_1), local_c < uVar3; local_c = local_c + 1) {
      iVar1 = param_1[1];
      iVar4 = param_1[1] + local_c * 8;
      *(undefined4 **)(iVar4 + 4) = param_1 + 3;
      *(undefined4 *)(iVar1 + local_c * 8) = *(undefined4 *)(iVar4 + 4);
    }
    uVar2 = 0;
  }
  return uVar2;
}

