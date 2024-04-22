
undefined4 strbuffer_init(undefined4 *param_1)

{
  undefined *puVar1;
  
  param_1[2] = 0x10;
  param_1[1] = 0;
  puVar1 = (undefined *)jsonp_malloc();
  *param_1 = puVar1;
  if (puVar1 != (undefined *)0x0) {
    *puVar1 = 0;
    return 0;
  }
  return 0xffffffff;
}

