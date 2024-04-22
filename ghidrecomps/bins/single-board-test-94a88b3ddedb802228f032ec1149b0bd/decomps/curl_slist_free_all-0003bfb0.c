
void curl_slist_free_all(undefined4 *param_1)

{
  code **ppcVar1;
  undefined4 *puVar2;
  
  ppcVar1 = DAT_0003bfd4;
  if (param_1 != (undefined4 *)0x0) {
    do {
      puVar2 = (undefined4 *)param_1[1];
      (**ppcVar1)(*param_1);
      *param_1 = 0;
      (**ppcVar1)(param_1);
      param_1 = puVar2;
    } while (puVar2 != (undefined4 *)0x0);
  }
  return;
}

