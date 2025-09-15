
void json_integer(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)jsonp_malloc(0x10);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[2] = param_1;
    puVar1[3] = param_2;
    *puVar1 = 3;
    puVar1[1] = 1;
  }
  return;
}

