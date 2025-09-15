
undefined4 json_string_setn_nocheck(int *param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  
  if (param_1 == (int *)0x0) {
    return 0xffffffff;
  }
  if ((*param_1 == 2 && param_2 != 0) &&
     (iVar1 = jsonp_strndup(param_2,param_3,param_3,param_2 == 0,param_4), iVar1 != 0)) {
    jsonp_free(param_1[2]);
    param_1[2] = iVar1;
    param_1[3] = param_3;
    return 0;
  }
  return 0xffffffff;
}

