
undefined4 json_array_extend(int *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint local_c;
  
  if ((((param_1 == (int *)0x0) || (*param_1 != 1)) || (param_2 == (int *)0x0)) || (*param_2 != 1))
  {
    uVar2 = 0xffffffff;
  }
  else {
    iVar1 = json_array_grow(param_1,param_2[3],1);
    if (iVar1 == 0) {
      uVar2 = 0xffffffff;
    }
    else {
      for (local_c = 0; local_c < (uint)param_2[3]; local_c = local_c + 1) {
        json_incref(*(undefined4 *)(param_2[4] + local_c * 4));
      }
      array_copy(param_1[4],param_1[3],param_2[4],0,param_2[3]);
      param_1[3] = param_1[3] + param_2[3];
      uVar2 = 0;
    }
  }
  return uVar2;
}

