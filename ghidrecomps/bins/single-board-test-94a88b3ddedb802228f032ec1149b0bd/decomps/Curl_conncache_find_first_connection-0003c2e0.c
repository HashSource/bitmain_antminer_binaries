
undefined4 Curl_conncache_find_first_connection(undefined4 param_1)

{
  int *piVar1;
  undefined auStack_14 [20];
  
  Curl_hash_start_iterate(param_1,auStack_14);
  do {
    piVar1 = (int *)Curl_hash_next_element(auStack_14);
    if (piVar1 == (int *)0x0) {
      return 0;
    }
  } while ((undefined4 *)**(undefined4 **)(*piVar1 + 8) == (undefined4 *)0x0);
  return *(undefined4 *)**(undefined4 **)(*piVar1 + 8);
}

