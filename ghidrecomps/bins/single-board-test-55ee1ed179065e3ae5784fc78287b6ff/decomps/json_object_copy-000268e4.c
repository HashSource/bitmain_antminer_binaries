
int json_object_copy(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int local_c;
  
  iVar1 = json_object();
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    uVar2 = json_object_iter(param_1);
    local_c = json_object_iter_key(uVar2);
    while (local_c != 0) {
      uVar2 = json_object_key_to_iter(local_c);
      iVar3 = json_object_iter_value(uVar2);
      if (iVar3 == 0) {
        return iVar1;
      }
      json_object_set_nocheck(iVar1,local_c,iVar3);
      uVar2 = json_object_key_to_iter(local_c);
      uVar2 = json_object_iter_next(param_1,uVar2);
      local_c = json_object_iter_key(uVar2);
    }
  }
  return iVar1;
}

