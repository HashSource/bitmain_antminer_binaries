
undefined4 * json_array(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)jsonp_malloc(0x18);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar1 = 1;
  puVar1[1] = 1;
  puVar1[3] = 0;
  puVar1[2] = 8;
  iVar2 = jsonp_malloc(0x20);
  puVar1[4] = iVar2;
  if (iVar2 != 0) {
    puVar1[5] = 0;
    return puVar1;
  }
  jsonp_free(puVar1);
  return (undefined4 *)0x0;
}

