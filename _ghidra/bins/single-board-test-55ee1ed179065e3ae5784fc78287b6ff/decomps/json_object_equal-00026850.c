
undefined4 json_object_equal(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int local_14;
  
  iVar1 = json_object_size(param_1);
  iVar2 = json_object_size(param_2);
  if (iVar1 == iVar2) {
    uVar3 = json_object_iter(param_1);
    local_14 = json_object_iter_key(uVar3);
    while (local_14 != 0) {
      uVar3 = json_object_key_to_iter(local_14);
      iVar1 = json_object_iter_value(uVar3);
      if (iVar1 == 0) break;
      uVar3 = json_object_get(param_2,local_14);
      iVar1 = json_equal(iVar1,uVar3);
      if (iVar1 == 0) {
        return 0;
      }
      uVar3 = json_object_key_to_iter(local_14);
      uVar3 = json_object_iter_next(param_1,uVar3);
      local_14 = json_object_iter_key(uVar3);
    }
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

