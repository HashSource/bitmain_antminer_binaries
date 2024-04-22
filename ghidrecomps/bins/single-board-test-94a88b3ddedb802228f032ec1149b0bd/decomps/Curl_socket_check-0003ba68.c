
uint Curl_socket_check(int param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  pollfd local_40 [3];
  
  local_50 = 0;
  local_4c = 0;
  if ((param_2 == -1 && param_1 == -1) && (param_3 == -1)) {
    uVar7 = Curl_wait_ms(param_4);
  }
  else {
    if (param_4 < 1) {
      iVar4 = 0;
    }
    else {
      curlx_tvnow(&local_50);
      iVar4 = param_4;
    }
    piVar1 = DAT_0003bbec;
    if (param_1 != -1) {
      local_40[0].events = 0xc3;
      local_40[0].revents = 0;
      local_40[0].fd = param_1;
    }
    uVar7 = (uint)(param_1 != -1);
    uVar6 = uVar7;
    if (param_2 != -1) {
      uVar6 = uVar7 + 1;
      local_40[uVar7].fd = param_2;
      local_40[uVar7].events = 0xc3;
      local_40[uVar7].revents = 0;
    }
    uVar7 = uVar6;
    if (param_3 != -1) {
      uVar7 = uVar6 + 1;
      local_40[uVar6].fd = param_3;
      local_40[uVar6].events = 0x104;
      local_40[uVar6].revents = 0;
    }
    do {
      do {
        if (param_4 < 0) {
          iVar4 = -1;
        }
        else if (param_4 == 0) {
          iVar4 = param_4;
        }
        iVar2 = poll(local_40,uVar7,iVar4);
        if (iVar2 != -1) {
          if (iVar2 < 0) {
            return 0xffffffff;
          }
          if (iVar2 != 0) {
            if (param_1 == -1) {
              uVar6 = 0;
              uVar7 = uVar6;
            }
            else {
              uVar7 = (uint)((local_40[0].revents & 0x59U) != 0);
              if ((local_40[0].revents & 0xa2U) == 0) {
                uVar6 = 1;
              }
              else {
                uVar6 = 1;
                uVar7 = uVar7 | 4;
              }
            }
            uVar5 = uVar6;
            if (param_2 != -1) {
              uVar5 = uVar6 + 1;
              if ((local_40[uVar6].revents & 0x59U) != 0) {
                uVar7 = uVar7 | 8;
              }
              if ((local_40[uVar6].revents & 0xa2U) != 0) {
                uVar7 = uVar7 | 4;
              }
            }
            if (param_3 == -1) {
              return uVar7;
            }
            if ((local_40[uVar5].revents & 0x104U) != 0) {
              uVar7 = uVar7 | 2;
            }
            if ((local_40[uVar5].revents & 0x38U) == 0) {
              return uVar7;
            }
            return uVar7 | 4;
          }
          goto LAB_0003bb50;
        }
        piVar3 = __errno_location();
        if (*piVar3 != 0) {
          if (*piVar1 != 0) {
            return 0xffffffff;
          }
          if (*piVar3 != 4) {
            return 0xffffffff;
          }
        }
      } while (param_4 < 1);
      curlx_tvnow(&local_48);
      iVar4 = curlx_tvdiff(local_48,uStack_44,local_50,local_4c);
      iVar4 = param_4 - iVar4;
    } while (0 < iVar4);
LAB_0003bb50:
    uVar7 = 0;
  }
  return uVar7;
}

