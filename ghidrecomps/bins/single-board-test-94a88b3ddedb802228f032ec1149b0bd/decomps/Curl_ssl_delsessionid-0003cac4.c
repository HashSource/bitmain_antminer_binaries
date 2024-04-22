
void Curl_ssl_delsessionid(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = *param_1;
  if ((*(int **)(iVar5 + 0x48) != (int *)0x0) && (**(int **)(iVar5 + 0x48) << 0x1b < 0)) {
    Curl_share_lock(iVar5,4);
  }
  if (*(int *)(iVar5 + 0x2a8) != 0) {
    iVar3 = *(int *)(iVar5 + 0x85b0);
    if (*(int *)(iVar3 + 4) != param_2) {
      iVar4 = 0;
      iVar2 = iVar3;
      do {
        iVar3 = iVar2 + 0x58;
        iVar4 = iVar4 + 1;
        if (iVar4 == *(int *)(iVar5 + 0x2a8)) goto LAB_0003cb06;
        piVar1 = (int *)(iVar2 + 0x5c);
        iVar2 = iVar3;
      } while (*piVar1 != param_2);
    }
    Curl_ssl_kill_session(iVar3);
  }
LAB_0003cb06:
  if ((*(int **)(iVar5 + 0x48) != (int *)0x0) && (**(int **)(iVar5 + 0x48) << 0x1b < 0)) {
    Curl_share_unlock(iVar5,4);
    return;
  }
  return;
}

