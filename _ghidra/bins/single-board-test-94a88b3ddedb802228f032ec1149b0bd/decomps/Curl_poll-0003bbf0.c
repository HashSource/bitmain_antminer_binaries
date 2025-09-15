
int Curl_poll(pollfd *param_1,nfds_t param_2,int param_3)

{
  pollfd *ppVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  nfds_t nVar6;
  int iVar7;
  bool bVar8;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  
  nVar6 = 0;
  local_30 = 0;
  local_2c = 0;
  if ((param_1 != (pollfd *)0x0) && (param_2 != 0)) {
    iVar4 = param_1->fd;
    ppVar1 = param_1;
    while( true ) {
      if (iVar4 != -1) {
        if (param_3 < 1) {
          iVar4 = 0;
        }
        else {
          curlx_tvnow(&local_30);
          iVar4 = param_3;
        }
        do {
          if (param_3 < 0) {
            iVar4 = -1;
          }
          else if (param_3 == 0) {
            iVar4 = param_3;
          }
          iVar2 = poll(param_1,param_2,iVar4);
          if (iVar2 != -1) {
            if (iVar2 < 0) {
              return -1;
            }
            if (iVar2 == 0) {
              return 0;
            }
            iVar4 = 0;
            do {
              iVar7 = iVar4 + 8;
              if (*(int *)((int)&param_1->fd + iVar4) != -1) {
                uVar5 = (uint)*(ushort *)((int)&param_1->revents + iVar4);
                bVar8 = (int)(uVar5 << 0x1b) < 0;
                if (bVar8) {
                  uVar5 = uVar5 | 1;
                }
                if (bVar8) {
                  *(ushort *)((int)&param_1->revents + iVar4) = (ushort)uVar5;
                }
                if ((uVar5 & 8) != 0) {
                  *(ushort *)((int)&param_1->revents + iVar4) = (ushort)uVar5 | 5;
                }
              }
              iVar4 = iVar7;
            } while (iVar7 != param_2 * 8);
            return iVar2;
          }
          piVar3 = __errno_location();
          if (*piVar3 != 0) {
            if (Curl_ack_eintr != 0) {
              return -1;
            }
            if (*piVar3 != 4) {
              return -1;
            }
          }
          if (0 < param_3) {
            curlx_tvnow(&local_28);
            iVar4 = curlx_tvdiff(local_28,uStack_24,local_30,local_2c);
            iVar4 = param_3 - iVar4;
            if (iVar4 < 1) {
              return 0;
            }
          }
        } while( true );
      }
      nVar6 = nVar6 + 1;
      if (nVar6 == param_2) break;
      ppVar1 = ppVar1 + 1;
      iVar4 = ppVar1->fd;
    }
  }
  iVar4 = Curl_wait_ms(param_3);
  return iVar4;
}

