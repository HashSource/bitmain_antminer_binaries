
int find_oldest_idle_connection(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 local_2c;
  undefined4 uStack_28;
  undefined auStack_24 [12];
  
  uVar3 = *(undefined4 *)(param_1 + 0x580);
  curlx_tvnow(&local_2c);
  Curl_hash_start_iterate(uVar3,auStack_24);
  piVar1 = (int *)Curl_hash_next_element(auStack_24);
  if (piVar1 == (int *)0x0) {
    iVar6 = 0;
  }
  else {
    iVar6 = 0;
    iVar5 = -1;
    do {
      for (piVar1 = **(int ***)(*piVar1 + 8); piVar1 != (int *)0x0; piVar1 = (int *)piVar1[2]) {
        while (iVar4 = *piVar1, *(char *)(iVar4 + 0x40) == '\0') {
          iVar2 = curlx_tvdiff(local_2c,uStack_28,*(undefined4 *)(iVar4 + 0x144),
                               *(undefined4 *)(iVar4 + 0x148));
          piVar1 = (int *)piVar1[2];
          if (iVar5 < iVar2) {
            iVar5 = iVar2;
            iVar6 = iVar4;
          }
          if (piVar1 == (int *)0x0) goto LAB_00043388;
        }
      }
LAB_00043388:
      piVar1 = (int *)Curl_hash_next_element(auStack_24);
    } while (piVar1 != (int *)0x0);
  }
  return iVar6;
}

