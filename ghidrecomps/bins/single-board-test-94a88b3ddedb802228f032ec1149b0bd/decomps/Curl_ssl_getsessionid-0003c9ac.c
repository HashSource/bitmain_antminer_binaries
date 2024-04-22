
undefined4 Curl_ssl_getsessionid(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  
  cVar1 = *(char *)(param_1 + 0x77);
  uVar5 = 1;
  iVar8 = *param_1;
  *param_2 = 0;
  if (cVar1 != '\0') {
    piVar4 = *(int **)(iVar8 + 0x48);
    if ((piVar4 == (int *)0x0) || (-1 < *piVar4 << 0x1b)) {
      piVar9 = (int *)(iVar8 + 0x85b4);
    }
    else {
      Curl_share_lock(iVar8,4,2);
      piVar4 = *(int **)(iVar8 + 0x48);
      piVar9 = piVar4 + 0xe;
    }
    uVar2 = *(uint *)(iVar8 + 0x2a8);
    if (uVar2 != 0) {
      iVar6 = 0;
      uVar7 = 0;
      do {
        iVar10 = *(int *)(iVar8 + 0x85b0) + iVar6;
        if (*(int *)(iVar10 + 4) != 0) {
          iVar3 = Curl_raw_equal(param_1[0x26],*(undefined4 *)(*(int *)(iVar8 + 0x85b0) + iVar6));
          if (((iVar3 != 0) && (param_1[0x2d] == *(int *)(iVar10 + 0x10))) &&
             (iVar3 = Curl_ssl_config_matches(param_1 + 0x6a,iVar10 + 0x14), iVar3 != 0)) {
            iVar6 = *piVar9;
            uVar5 = *(undefined4 *)(iVar10 + 4);
            *piVar9 = iVar6 + 1;
            *(int *)(iVar10 + 0xc) = iVar6 + 1;
            *param_2 = uVar5;
            if (param_3 == (undefined4 *)0x0) {
              piVar4 = *(int **)(iVar8 + 0x48);
              uVar5 = 0;
            }
            else {
              uVar5 = 0;
              piVar4 = *(int **)(iVar8 + 0x48);
              *param_3 = *(undefined4 *)(iVar10 + 8);
            }
            goto LAB_0003ca5e;
          }
          uVar2 = *(uint *)(iVar8 + 0x2a8);
        }
        uVar7 = uVar7 + 1;
        iVar6 = iVar6 + 0x58;
      } while (uVar7 < uVar2);
      piVar4 = *(int **)(iVar8 + 0x48);
    }
    uVar5 = 1;
LAB_0003ca5e:
    if ((piVar4 != (int *)0x0) && (*piVar4 << 0x1b < 0)) {
      Curl_share_unlock(iVar8,4);
    }
  }
  return uVar5;
}

