
undefined4 hashtable_set(uint *param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  size_t sVar4;
  undefined4 *puVar5;
  int extraout_r1;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  
  uVar8 = *param_1;
  uVar1 = num_buckets(param_1);
  if ((uVar8 < uVar1) || (iVar2 = hashtable_do_rehash(param_1), iVar2 == 0)) {
    uVar6 = hash_str(param_2);
    uVar3 = num_buckets(param_1);
    __aeabi_uidivmod(uVar6,uVar3);
    iVar7 = param_1[1] + extraout_r1 * 8;
    iVar2 = hashtable_find_pair(param_1,iVar7,param_2,uVar6);
    if (iVar2 == 0) {
      sVar4 = strlen(param_2);
      puVar5 = (undefined4 *)jsonp_malloc(sVar4 + 0x15);
      if (puVar5 == (undefined4 *)0x0) {
        return 0xffffffff;
      }
      *puVar5 = uVar6;
      puVar5[4] = param_3;
      strcpy((char *)(puVar5 + 5),param_2);
      puVar5[3] = param_4;
      list_init(puVar5 + 1);
      insert_to_bucket(param_1,iVar7,puVar5 + 1);
      *param_1 = *param_1 + 1;
    }
    else {
      json_decref(*(undefined4 *)(iVar2 + 0xc));
      *(undefined4 *)(iVar2 + 0xc) = param_4;
    }
    uVar6 = 0;
  }
  else {
    uVar6 = 0xffffffff;
  }
  return uVar6;
}

