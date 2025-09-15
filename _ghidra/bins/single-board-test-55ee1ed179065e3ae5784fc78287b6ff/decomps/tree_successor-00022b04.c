
undefined4 * tree_successor(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *local_18;
  undefined4 *local_c;
  
  if ((undefined4 *)param_2[1] == param_1 + 1) {
    puVar1 = (undefined4 *)maximum_c_rb(param_1,*param_1);
    if (puVar1 == param_2) {
      local_c = (undefined4 *)0x0;
    }
    else {
      local_18 = param_2;
      for (local_c = (undefined4 *)param_2[2];
          (param_1 + 1 != local_c && ((undefined4 *)local_c[1] == local_18));
          local_c = (undefined4 *)local_c[2]) {
        local_18 = local_c;
      }
    }
  }
  else {
    local_c = (undefined4 *)minimum_c_rb(param_1,param_2[1]);
  }
  return local_c;
}

