
undefined4 Curl_ssl_addsessionid(int *param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  uint uVar12;
  
  iVar11 = *param_1;
  piVar10 = *(int **)(iVar11 + 0x85b0);
  iVar9 = piVar10[3];
  iVar2 = (*Curl_cstrdup)(param_1[0x26]);
  if (iVar2 == 0) {
    return 0x1b;
  }
  if ((*(int **)(iVar11 + 0x48) == (int *)0x0) || (-1 < **(int **)(iVar11 + 0x48) << 0x1b)) {
    piVar5 = (int *)(iVar11 + 0x85b4);
  }
  else {
    Curl_share_lock(iVar11,4,2);
    piVar5 = (int *)(*(int *)(iVar11 + 0x48) + 0x38);
  }
  uVar3 = *(uint *)(iVar11 + 0x2a8);
  if (uVar3 < 2) {
    if (uVar3 == 1) {
LAB_0003cba4:
      Curl_ssl_kill_session(piVar10);
      goto LAB_0003cbc0;
    }
LAB_0003cbb2:
    uVar12 = 1;
  }
  else {
    iVar6 = *(int *)(iVar11 + 0x85b0);
    if (*(int *)(iVar6 + 0x5c) == 0) goto LAB_0003cbb2;
    uVar12 = 1;
    piVar1 = (int *)(iVar6 + 0xb0);
    piVar8 = (int *)(iVar6 + 0x58);
    do {
      piVar7 = piVar1;
      uVar12 = uVar12 + 1;
      if (piVar8[3] < iVar9) {
        iVar9 = piVar8[3];
        piVar10 = piVar8;
      }
      if (uVar12 == uVar3) goto LAB_0003cba4;
      piVar1 = piVar7 + 0x16;
      piVar8 = piVar7;
    } while (piVar7[1] != 0);
  }
  piVar10 = (int *)(uVar12 * 0x58 + *(int *)(iVar11 + 0x85b0));
LAB_0003cbc0:
  iVar9 = *piVar5;
  piVar10[1] = param_2;
  piVar10[3] = iVar9;
  piVar10[2] = param_3;
  (*Curl_cfree)(*piVar10);
  iVar9 = param_1[0x2d];
  piVar5 = *(int **)(iVar11 + 0x48);
  *piVar10 = iVar2;
  piVar10[4] = iVar9;
  if ((piVar5 != (int *)0x0) && (*piVar5 << 0x1b < 0)) {
    Curl_share_unlock(iVar11,4);
  }
  iVar9 = Curl_clone_ssl_config(param_1 + 0x6a,piVar10 + 5);
  if (iVar9 == 0) {
    piVar10[1] = 0;
    (*Curl_cfree)(iVar2);
    uVar4 = 0x1b;
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}

