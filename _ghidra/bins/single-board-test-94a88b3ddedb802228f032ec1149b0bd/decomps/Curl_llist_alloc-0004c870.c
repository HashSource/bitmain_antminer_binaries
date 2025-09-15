
void Curl_llist_alloc(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*Curl_cmalloc)(0x10);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[2] = param_1;
    puVar1[3] = 0;
    *puVar1 = 0;
    puVar1[1] = 0;
  }
  return;
}

