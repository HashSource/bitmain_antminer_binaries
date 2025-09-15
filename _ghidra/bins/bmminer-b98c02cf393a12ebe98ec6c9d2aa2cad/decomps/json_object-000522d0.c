
undefined4 * json_object(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)jsonp_malloc(0x28);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  if (hashtable_seed == 0) {
    json_object_seed();
  }
  *puVar1 = 0;
  puVar1[1] = 1;
  iVar2 = hashtable_init(puVar1 + 2);
  if (iVar2 == 0) {
    puVar1[9] = 0;
    return puVar1;
  }
  jsonp_free(puVar1);
  return (undefined4 *)0x0;
}

