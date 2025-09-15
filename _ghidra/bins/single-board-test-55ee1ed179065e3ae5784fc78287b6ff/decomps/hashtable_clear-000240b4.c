
void hashtable_clear(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint local_c;
  
  hashtable_do_clear(param_1);
  for (local_c = 0; uVar1 = num_buckets(param_1), local_c < uVar1; local_c = local_c + 1) {
    iVar2 = param_1[1];
    iVar3 = param_1[1] + local_c * 8;
    *(undefined4 **)(iVar3 + 4) = param_1 + 3;
    *(undefined4 *)(iVar2 + local_c * 8) = *(undefined4 *)(iVar3 + 4);
  }
  list_init(param_1 + 3);
  *param_1 = 0;
  return;
}

