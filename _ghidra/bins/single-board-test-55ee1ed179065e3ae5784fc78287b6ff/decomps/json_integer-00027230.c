
int json_integer(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = jsonp_malloc(0x10);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    json_init(iVar1,3);
    *(undefined4 *)(iVar1 + 8) = param_1;
    *(undefined4 *)(iVar1 + 0xc) = param_2;
  }
  return iVar1;
}

