
undefined4 json_object_update_existing(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int local_c;
  
  if ((((param_1 == (int *)0x0) || (*param_1 != 0)) || (param_2 == (int *)0x0)) || (*param_2 != 0))
  {
    uVar3 = 0xffffffff;
  }
  else {
    uVar3 = json_object_iter(param_2);
    local_c = json_object_iter_key(uVar3);
    while (local_c != 0) {
      uVar3 = json_object_key_to_iter(local_c);
      iVar2 = json_object_iter_value(uVar3);
      if (iVar2 == 0) break;
      iVar1 = json_object_get(param_1,local_c);
      if (iVar1 != 0) {
        json_object_set_nocheck(param_1,local_c,iVar2);
      }
      uVar3 = json_object_key_to_iter(local_c);
      uVar3 = json_object_iter_next(param_2,uVar3);
      local_c = json_object_iter_key(uVar3);
    }
    uVar3 = 0;
  }
  return uVar3;
}

