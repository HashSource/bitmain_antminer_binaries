
uint Curl_socket_check(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  pollfd local_40 [3];
  
  local_50 = 0;
  local_4c = 0;
  if ((param_2 == -1 && param_1 == -1) && (param_3 == -1)) {
    uVar6 = Curl_wait_ms(param_4);
  }
  else {
    if (param_4 < 1) {
      iVar3 = 0;
    }
    else {
      curlx_tvnow(&local_50);
      iVar3 = param_4;
    }
    if (param_1 != -1) {
      local_40[0].events = 0xc3;
      local_40[0].revents = 0;
      local_40[0].fd = param_1;
    }
    uVar6 = (uint)(param_1 != -1);
    uVar5 = uVar6;
    if (param_2 != -1) {
      uVar5 = uVar6 + 1;
      local_40[uVar6].fd = param_2;
      local_40[uVar6].events = 0xc3;
      local_40[uVar6].revents = 0;
    }
    uVar6 = uVar5;
    if (param_3 != -1) {
      uVar6 = uVar5 + 1;
      local_40[uVar5].fd = param_3;
      local_40[uVar5].events = 0x104;
      local_40[uVar5].revents = 0;
    }
    do {
      do {
        if (param_4 < 0) {
          iVar3 = -1;
        }
        else if (param_4 == 0) {
          iVar3 = param_4;
        }
        iVar1 = poll(local_40,uVar6,iVar3);
        if (iVar1 != -1) {
          if (iVar1 < 0) {
            return 0xffffffff;
          }
          if (iVar1 != 0) {
            if (param_1 == -1) {
              uVar5 = 0;
              uVar6 = uVar5;
            }
            else {
              uVar6 = (uint)((local_40[0].revents & 0x59U) != 0);
              if ((local_40[0].revents & 0xa2U) == 0) {
                uVar5 = 1;
              }
              else {
                uVar5 = 1;
                uVar6 = uVar6 | 4;
              }
            }
            uVar4 = uVar5;
            if (param_2 != -1) {
              uVar4 = uVar5 + 1;
              if ((local_40[uVar5].revents & 0x59U) != 0) {
                uVar6 = uVar6 | 8;
              }
              if ((local_40[uVar5].revents & 0xa2U) != 0) {
                uVar6 = uVar6 | 4;
              }
            }
            if (param_3 == -1) {
              return uVar6;
            }
            if ((local_40[uVar4].revents & 0x104U) != 0) {
              uVar6 = uVar6 | 2;
            }
            if ((local_40[uVar4].revents & 0x38U) == 0) {
              return uVar6;
            }
            return uVar6 | 4;
          }
          goto LAB_0003bb50;
        }
        piVar2 = __errno_location();
        if (*piVar2 != 0) {
          if (Curl_ack_eintr != 0) {
            return 0xffffffff;
          }
          if (*piVar2 != 4) {
            return 0xffffffff;
          }
        }
      } while (param_4 < 1);
      curlx_tvnow(&local_48);
      iVar3 = curlx_tvdiff(local_48,uStack_44,local_50,local_4c);
      iVar3 = param_4 - iVar3;
    } while (0 < iVar3);
LAB_0003bb50:
    uVar6 = 0;
  }
  return uVar6;
}

