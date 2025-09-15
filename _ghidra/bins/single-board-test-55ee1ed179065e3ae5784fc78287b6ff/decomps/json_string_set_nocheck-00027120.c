
undefined4 json_string_set_nocheck(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((param_1 == (int *)0x0) || (*param_1 != 2)) || (param_2 == 0)) {
    uVar2 = 0xffffffff;
  }
  else {
    iVar1 = jsonp_strdup(param_2);
    if (iVar1 == 0) {
      uVar2 = 0xffffffff;
    }
    else {
      jsonp_free(param_1[2]);
      param_1[2] = iVar1;
      uVar2 = 0;
    }
  }
  return uVar2;
}

