
void Curl_multi_process_pending_handles(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  piVar1 = **(int ***)(param_1 + 0x18);
  do {
    piVar2 = piVar1;
    if (piVar1 == (int *)0x0) {
      return;
    }
    while( true ) {
      iVar3 = *piVar2;
      piVar1 = (int *)piVar2[2];
      if (*(int *)(iVar3 + 0xc) != 1) break;
      mstate(iVar3,2);
      Curl_llist_remove(*(undefined4 *)(param_1 + 0x18),piVar2,0);
      Curl_expire_latest(iVar3,1);
      piVar2 = piVar1;
      if (piVar1 == (int *)0x0) {
        return;
      }
    }
  } while( true );
}

