
undefined4 * Curl_slist_append_nodup(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar1 = (undefined4 *)(**DAT_0003bf74)(8);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    puVar1[1] = 0;
    puVar3 = param_1;
    if (param_1 != (undefined4 *)0x0) {
      do {
        puVar2 = puVar3;
        puVar3 = (undefined4 *)puVar2[1];
      } while (puVar3 != (undefined4 *)0x0);
      puVar2[1] = puVar1;
      puVar1 = param_1;
    }
  }
  return puVar1;
}

