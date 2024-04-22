
void conncache_remove_bundle(int param_1,int param_2)

{
  int *piVar1;
  undefined auStack_1c [16];
  
  if (param_1 != 0) {
    Curl_hash_start_iterate(param_1,auStack_1c);
    do {
      piVar1 = (int *)Curl_hash_next_element(auStack_1c);
      if (piVar1 == (int *)0x0) {
        return;
      }
    } while (*piVar1 != param_2);
    Curl_hash_delete(param_1,piVar1[1],piVar1[2]);
  }
  return;
}

