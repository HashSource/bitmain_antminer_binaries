
undefined4 strbuffer_init(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  param_1[2] = 0x10;
  param_1[1] = 0;
  iVar1 = jsonp_malloc(param_1[2]);
  *param_1 = iVar1;
  if (*param_1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    *(undefined *)*param_1 = 0;
    uVar2 = 0;
  }
  return uVar2;
}

