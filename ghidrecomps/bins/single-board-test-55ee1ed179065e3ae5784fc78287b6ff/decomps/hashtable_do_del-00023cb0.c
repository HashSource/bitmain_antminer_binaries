
undefined4 hashtable_do_del(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int extraout_r1;
  int *piVar3;
  
  uVar1 = num_buckets(param_1);
  __aeabi_uidivmod(param_3,uVar1);
  piVar3 = (int *)(param_1[1] + extraout_r1 * 8);
  iVar2 = hashtable_find_pair(param_1,piVar3,param_2,param_3);
  if (iVar2 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    if ((iVar2 + 4 == *piVar3) && (iVar2 + 4 == piVar3[1])) {
      piVar3[1] = (int)(param_1 + 3);
      *piVar3 = piVar3[1];
    }
    else if (iVar2 + 4 == *piVar3) {
      *piVar3 = *(int *)(iVar2 + 8);
    }
    else if (iVar2 + 4 == piVar3[1]) {
      piVar3[1] = *(int *)(iVar2 + 4);
    }
    list_remove(iVar2 + 4);
    json_decref(*(undefined4 *)(iVar2 + 0xc));
    jsonp_free(iVar2);
    *param_1 = *param_1 + -1;
    uVar1 = 0;
  }
  return uVar1;
}

