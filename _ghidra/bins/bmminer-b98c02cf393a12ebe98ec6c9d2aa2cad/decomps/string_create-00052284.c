
undefined4 * string_create(int param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  
  if (param_1 == 0) {
    return (undefined4 *)0x0;
  }
  if (param_3 == 0) {
    param_1 = jsonp_strndup();
    if (param_1 == 0) {
      return (undefined4 *)0x0;
    }
    puVar1 = (undefined4 *)jsonp_malloc(0x10);
    if (puVar1 == (undefined4 *)0x0) {
      jsonp_free(param_1);
      return (undefined4 *)0x0;
    }
  }
  else {
    puVar1 = (undefined4 *)jsonp_malloc(0x10);
    if (puVar1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
  }
  puVar1[2] = param_1;
  puVar1[3] = param_2;
  *puVar1 = 2;
  puVar1[1] = 1;
  return puVar1;
}

