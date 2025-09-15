
void curl_slist_free_all(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    do {
      puVar1 = (undefined4 *)param_1[1];
      (*Curl_cfree)(*param_1);
      *param_1 = 0;
      (*Curl_cfree)(param_1);
      param_1 = puVar1;
    } while (puVar1 != (undefined4 *)0x0);
  }
  return;
}

