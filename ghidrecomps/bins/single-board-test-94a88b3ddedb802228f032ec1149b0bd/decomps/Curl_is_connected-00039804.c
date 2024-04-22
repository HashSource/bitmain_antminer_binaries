
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffa0 : 0x0003995a */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

int Curl_is_connected(int *param_1,int param_2,undefined *param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  uint uVar10;
  undefined4 local_70;
  undefined4 uStack_6c;
  int local_64;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined auStack_58 [52];
  
  iVar7 = 0;
  iVar8 = *param_1;
  *param_3 = 0;
  local_64 = 0;
  if (*(char *)((int)param_1 + param_2 + 0x1f6) == '\0') {
    curlx_tvnow(&local_70);
    local_60 = local_70;
    uStack_5c = uStack_6c;
    iVar1 = Curl_timeleft(iVar8,&local_60,1);
    if (iVar1 < 0) {
      Curl_failf(iVar8,DAT_00039a64);
      iVar7 = 0x1c;
    }
    else {
      uVar5 = 0;
      iVar6 = 0;
      piVar9 = param_1;
      do {
        iVar7 = iVar6;
        if (piVar9[0x57] != -1) {
          uVar10 = uVar5 ^ 1;
          iVar2 = Curl_socket_check(0xffffffff,0xffffffff,piVar9[0x57],0);
          if (iVar2 == 0) {
            iVar2 = curlx_tvdiff(local_60,uStack_5c,param_1[0x82],param_1[0x83]);
            if (param_1[0x85] <= iVar2) {
              Curl_infof(iVar8,DAT_00039a6c);
              local_64 = 0x6e;
            }
            if (((uVar5 == 0) && (param_1[0x15] == 0)) &&
               (iVar2 = curlx_tvdiff(local_60,uStack_5c,param_1[0x82],param_1[0x83]), 199 < iVar2))
            {
              trynextip(param_1,param_2,1);
            }
          }
          else if (iVar2 == 2) {
            iVar2 = verifyconnect(piVar9[0x57],&local_64);
            if (iVar2 != 0) {
              iVar1 = param_1[uVar5 + 0x57];
              param_1[uVar5 + 0x57] = -1;
              iVar7 = param_1[uVar10 + 0x57];
              param_1[0x13] = param_1[uVar5 + 0x14];
              param_1[param_2 + 0x55] = iVar1;
              if (iVar7 != -1) {
                Curl_closesocket(param_1);
                param_1[uVar10 + 0x57] = -1;
              }
              iVar7 = Curl_connected_proxy(param_1,param_2);
              if (iVar7 != 0) {
                return iVar7;
              }
              *(undefined *)((int)param_1 + param_2 + 0x1f6) = 1;
              *param_3 = 1;
              if (param_2 == 0) {
                Curl_pgrsTime(iVar8,4);
              }
              Curl_updateconninfo(param_1,param_1[param_2 + 0x55]);
              Curl_verboseconnect(param_1);
              return 0;
            }
            Curl_infof(iVar8,DAT_00039a68);
          }
          else if (iVar2 << 0x1d < 0) {
            verifyconnect(piVar9[0x57],&local_64);
          }
          iVar2 = local_64;
          if (local_64 != 0) {
            *(int *)(iVar8 + 0x85cc) = local_64;
            piVar3 = __errno_location();
            *piVar3 = iVar2;
            if (piVar9[0x14] != 0) {
              Curl_printable_address(piVar9[0x14],auStack_58,0x2e);
              iVar7 = param_1[0x2c];
              uVar4 = Curl_strerror(param_1,local_64);
              Curl_infof(iVar8,DAT_00039a5c,auStack_58,iVar7,uVar4);
              iVar7 = iVar1 >> 1;
              if (*(int *)(piVar9[0x14] + 0x1c) == 0) {
                iVar7 = iVar1;
              }
              param_1[0x85] = iVar7;
              iVar7 = trynextip(param_1,param_2,uVar5);
              if ((iVar7 == 7) && (iVar7 = iVar6, param_1[uVar10 + 0x57] == -1)) {
                iVar7 = 7;
              }
            }
          }
        }
        uVar5 = uVar5 + 1;
        piVar9 = piVar9 + 1;
        iVar6 = iVar7;
      } while (uVar5 != 2);
      if ((iVar7 == 0) ||
         ((param_1[0x15] == 0 && (iVar7 = trynextip(param_1,param_2,1), iVar7 == 0)))) {
        iVar7 = 0;
      }
      else {
        if (*(char *)((int)param_1 + 0x1ef) == '\0') {
          iVar1 = param_1[0x26];
        }
        else {
          iVar1 = param_1[0x2a];
        }
        iVar6 = param_1[0x2c];
        uVar4 = Curl_strerror(param_1,local_64);
        Curl_failf(iVar8,DAT_00039a60,iVar1,iVar6,uVar4);
      }
    }
  }
  else {
    *param_3 = 1;
  }
  return iVar7;
}

