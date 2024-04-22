
int Curl_poll(pollfd *param_1,nfds_t param_2,int param_3)

{
  pollfd *ppVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  nfds_t nVar7;
  int iVar8;
  bool bVar9;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  
  nVar7 = 0;
  local_30 = 0;
  local_2c = 0;
  if ((param_1 != (pollfd *)0x0) && (param_2 != 0)) {
    iVar5 = param_1->fd;
    ppVar1 = param_1;
    while( true ) {
      if (iVar5 != -1) {
        if (param_3 < 1) {
          iVar5 = 0;
        }
        else {
          curlx_tvnow(&local_30);
          iVar5 = param_3;
        }
        piVar2 = DAT_0003bcd8;
        do {
          if (param_3 < 0) {
            iVar5 = -1;
          }
          else if (param_3 == 0) {
            iVar5 = param_3;
          }
          iVar3 = poll(param_1,param_2,iVar5);
          if (iVar3 != -1) {
            if (iVar3 < 0) {
              return -1;
            }
            if (iVar3 == 0) {
              return 0;
            }
            iVar5 = 0;
            do {
              iVar8 = iVar5 + 8;
              if (*(int *)((int)&param_1->fd + iVar5) != -1) {
                uVar6 = (uint)*(ushort *)((int)&param_1->revents + iVar5);
                bVar9 = (int)(uVar6 << 0x1b) < 0;
                if (bVar9) {
                  uVar6 = uVar6 | 1;
                }
                if (bVar9) {
                  *(ushort *)((int)&param_1->revents + iVar5) = (ushort)uVar6;
                }
                if ((uVar6 & 8) != 0) {
                  *(ushort *)((int)&param_1->revents + iVar5) = (ushort)uVar6 | 5;
                }
              }
              iVar5 = iVar8;
            } while (iVar8 != param_2 * 8);
            return iVar3;
          }
          piVar4 = __errno_location();
          if (*piVar4 != 0) {
            if (*piVar2 != 0) {
              return -1;
            }
            if (*piVar4 != 4) {
              return -1;
            }
          }
          if (0 < param_3) {
            curlx_tvnow(&local_28);
            iVar5 = curlx_tvdiff(local_28,uStack_24,local_30,local_2c);
            iVar5 = param_3 - iVar5;
            if (iVar5 < 1) {
              return 0;
            }
          }
        } while( true );
      }
      nVar7 = nVar7 + 1;
      if (nVar7 == param_2) break;
      ppVar1 = ppVar1 + 1;
      iVar5 = ppVar1->fd;
    }
  }
  iVar5 = Curl_wait_ms(param_3);
  return iVar5;
}

