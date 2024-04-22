
void Curl_conncache_foreach(int param_1,undefined4 param_2,code *param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined auStack_24 [16];
  
  if (param_1 != 0) {
    Curl_hash_start_iterate(param_1,auStack_24);
    piVar1 = (int *)Curl_hash_next_element(auStack_24);
    while (piVar1 != (int *)0x0) {
      iVar3 = *piVar1;
      piVar1 = (int *)Curl_hash_next_element(auStack_24);
      puVar4 = (undefined4 *)**(int **)(iVar3 + 8);
      while (puVar4 != (undefined4 *)0x0) {
        uVar2 = *puVar4;
        puVar4 = (undefined4 *)puVar4[2];
        iVar3 = (*param_3)(uVar2,param_2);
        if (iVar3 == 1) {
          return;
        }
      }
    }
  }
  return;
}

