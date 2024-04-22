
undefined4 Curl_ssl_addsessionid(int *param_1,int param_2,int param_3)

{
  code **ppcVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  uint uVar13;
  
  iVar12 = *param_1;
  piVar11 = *(int **)(iVar12 + 0x85b0);
  iVar10 = piVar11[3];
  iVar3 = (**DAT_0003cc24)(param_1[0x26]);
  if (iVar3 == 0) {
    return 0x1b;
  }
  if ((*(int **)(iVar12 + 0x48) == (int *)0x0) || (-1 < **(int **)(iVar12 + 0x48) << 0x1b)) {
    piVar6 = (int *)(iVar12 + 0x85b4);
  }
  else {
    Curl_share_lock(iVar12,4,2);
    piVar6 = (int *)(*(int *)(iVar12 + 0x48) + 0x38);
  }
  uVar4 = *(uint *)(iVar12 + 0x2a8);
  if (uVar4 < 2) {
    if (uVar4 == 1) {
LAB_0003cba4:
      Curl_ssl_kill_session(piVar11);
      goto LAB_0003cbc0;
    }
LAB_0003cbb2:
    uVar13 = 1;
  }
  else {
    iVar7 = *(int *)(iVar12 + 0x85b0);
    if (*(int *)(iVar7 + 0x5c) == 0) goto LAB_0003cbb2;
    uVar13 = 1;
    piVar2 = (int *)(iVar7 + 0xb0);
    piVar9 = (int *)(iVar7 + 0x58);
    do {
      piVar8 = piVar2;
      uVar13 = uVar13 + 1;
      if (piVar9[3] < iVar10) {
        iVar10 = piVar9[3];
        piVar11 = piVar9;
      }
      if (uVar13 == uVar4) goto LAB_0003cba4;
      piVar2 = piVar8 + 0x16;
      piVar9 = piVar8;
    } while (piVar8[1] != 0);
  }
  piVar11 = (int *)(uVar13 * 0x58 + *(int *)(iVar12 + 0x85b0));
LAB_0003cbc0:
  ppcVar1 = DAT_0003cc28;
  iVar10 = *piVar6;
  piVar11[1] = param_2;
  piVar11[3] = iVar10;
  piVar11[2] = param_3;
  (**ppcVar1)(*piVar11);
  iVar10 = param_1[0x2d];
  piVar6 = *(int **)(iVar12 + 0x48);
  *piVar11 = iVar3;
  piVar11[4] = iVar10;
  if ((piVar6 != (int *)0x0) && (*piVar6 << 0x1b < 0)) {
    Curl_share_unlock(iVar12,4);
  }
  iVar10 = Curl_clone_ssl_config(param_1 + 0x6a,piVar11 + 5);
  if (iVar10 == 0) {
    piVar11[1] = 0;
    (**ppcVar1)(iVar3);
    uVar5 = 0x1b;
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}

