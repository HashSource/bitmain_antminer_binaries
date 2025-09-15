
undefined4 Curl_ssl_getsessionid(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  
  iVar5 = param_1[0x77];
  uVar4 = 1;
  iVar7 = *param_1;
  *param_2 = 0;
  if ((char)iVar5 != '\0') {
    piVar3 = *(int **)(iVar7 + 0x48);
    if ((piVar3 == (int *)0x0) || (-1 < *piVar3 << 0x1b)) {
      piVar8 = (int *)(iVar7 + 0x85b4);
    }
    else {
      Curl_share_lock(iVar7,4,2);
      piVar3 = *(int **)(iVar7 + 0x48);
      piVar8 = piVar3 + 0xe;
    }
    uVar1 = *(uint *)(iVar7 + 0x2a8);
    if (uVar1 != 0) {
      iVar5 = 0;
      uVar6 = 0;
      do {
        iVar9 = *(int *)(iVar7 + 0x85b0) + iVar5;
        if (*(int *)(iVar9 + 4) != 0) {
          iVar2 = Curl_raw_equal(param_1[0x26],*(undefined4 *)(*(int *)(iVar7 + 0x85b0) + iVar5));
          if (((iVar2 != 0) && (param_1[0x2d] == *(int *)(iVar9 + 0x10))) &&
             (iVar2 = Curl_ssl_config_matches(param_1 + 0x6a,iVar9 + 0x14), iVar2 != 0)) {
            iVar5 = *piVar8;
            uVar4 = *(undefined4 *)(iVar9 + 4);
            *piVar8 = iVar5 + 1;
            *(int *)(iVar9 + 0xc) = iVar5 + 1;
            *param_2 = uVar4;
            if (param_3 == (undefined4 *)0x0) {
              piVar3 = *(int **)(iVar7 + 0x48);
              uVar4 = 0;
            }
            else {
              uVar4 = 0;
              piVar3 = *(int **)(iVar7 + 0x48);
              *param_3 = *(undefined4 *)(iVar9 + 8);
            }
            goto LAB_0003ca5e;
          }
          uVar1 = *(uint *)(iVar7 + 0x2a8);
        }
        uVar6 = uVar6 + 1;
        iVar5 = iVar5 + 0x58;
      } while (uVar6 < uVar1);
      piVar3 = *(int **)(iVar7 + 0x48);
    }
    uVar4 = 1;
LAB_0003ca5e:
    if ((piVar3 != (int *)0x0) && (*piVar3 << 0x1b < 0)) {
      Curl_share_unlock(iVar7,4);
    }
  }
  return uVar4;
}

