
int json_object_deep_copy(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int local_c;
  
  iVar1 = json_object();
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    for (local_c = json_object_iter(param_1); local_c != 0;
        local_c = json_object_iter_next(param_1,local_c)) {
      uVar2 = json_object_iter_key(local_c);
      uVar3 = json_object_iter_value(local_c);
      uVar3 = json_deep_copy(uVar3);
      json_object_set_new_nocheck(iVar1,uVar2,uVar3);
    }
  }
  return iVar1;
}

