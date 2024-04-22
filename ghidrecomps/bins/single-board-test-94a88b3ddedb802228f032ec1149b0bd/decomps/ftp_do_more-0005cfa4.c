
int ftp_do_more(int *param_1,uint *param_2)

{
  char cVar1;
  undefined2 uVar2;
  longlong lVar3;
  int iVar4;
  ushort **ppuVar5;
  byte *__nptr;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  longlong lVar12;
  longlong lVar13;
  char local_93;
  byte local_92;
  char local_91;
  byte *local_90;
  byte *local_8c;
  undefined auStack_88 [100];
  
  iVar9 = *param_1;
  cVar1 = *(char *)((int)param_1 + 0x1f7);
  local_93 = '\0';
  iVar10 = *(int *)(iVar9 + 0x14c);
  local_92 = 0;
  if (cVar1 == '\0') {
    if (param_1[0x11b] == 1) {
      iVar9 = Curl_proxyCONNECT(param_1,1,0,0,0);
      return iVar9;
    }
    iVar4 = Curl_is_connected(param_1,1,&local_93);
    if (local_93 == '\0') {
      if (iVar4 == 0) {
        return 0;
      }
      if (param_1[0x107] != 0) {
        return iVar4;
      }
      *param_2 = 0xffffffff;
      iVar9 = ftp_epsv_disable(param_1);
      return iVar9;
    }
    if (*(char *)((int)param_1 + 0x1ef) != '\0') {
      Curl_infof(iVar9,DAT_0005d364);
      iVar6 = *param_1;
      iVar11 = param_1[0x112];
      uVar2 = *(undefined2 *)(param_1 + 0x113);
      local_93 = cVar1;
      switch(param_1[0x4e]) {
      case 0:
      case 1:
        iVar4 = 0;
        break;
      default:
        iVar4 = 7;
        Curl_failf(iVar6,DAT_0005d368);
        break;
      case 4:
        iVar4 = Curl_SOCKS4(param_1[0x4c],iVar11,uVar2,1,param_1,0);
        local_93 = '\x01';
        break;
      case 5:
      case 7:
        iVar4 = Curl_SOCKS5(param_1[0x4c],param_1[0x4d],iVar11,uVar2,1,param_1);
        local_93 = '\x01';
        break;
      case 6:
        iVar4 = Curl_SOCKS4(param_1[0x4c],iVar11,uVar2,1,param_1,1);
        local_93 = '\x01';
      }
      if ((*(char *)((int)param_1 + 0x1fa) != '\0') && (*(char *)(param_1 + 0x7c) != '\0')) {
        uVar8 = *(undefined4 *)(iVar6 + 0x14c);
        memset(auStack_88,0,0x60);
        *(undefined **)(iVar6 + 0x14c) = auStack_88;
        iVar4 = Curl_proxyCONNECT(param_1,1,iVar11,uVar2,1);
        *(undefined4 *)(iVar6 + 0x14c) = uVar8;
        if (iVar4 == 0) {
          if (param_1[0x11b] != 2) {
            param_1[0x10a] = 0;
            goto LAB_0005cff8;
          }
          local_93 = '\x01';
        }
      }
    }
    if (param_1[0x10a] == 0) goto LAB_0005cff8;
LAB_0005d040:
    iVar9 = ftp_multi_statemach(param_1,&local_92);
    *param_2 = (uint)local_92;
    if (iVar9 != 0) {
      return iVar9;
    }
    if (*(char *)(param_1 + 0x104) == '\0') {
      return 0;
    }
    uVar7 = *(uint *)(iVar10 + 0xc);
    *param_2 = 0;
    if (1 < uVar7) goto LAB_0005d002;
LAB_0005d06c:
    iVar9 = ReceivedServerConnect(param_1,&local_91);
    if (iVar9 != 0) {
      return iVar9;
    }
    if (local_91 == '\0') {
      return 0;
    }
    iVar9 = AcceptServerConnect(param_1);
    *(undefined *)(param_1 + 0x104) = 0;
    if (iVar9 != 0) {
      return iVar9;
    }
    iVar9 = InitiateTransfer(param_1);
    iVar4 = 0;
    if (iVar9 != 0) {
      return iVar9;
    }
LAB_0005d028:
    *param_2 = 1;
    return iVar4;
  }
  iVar4 = 0;
  if (param_1[0x10a] != 0) goto LAB_0005d040;
LAB_0005cff8:
  if (1 < *(uint *)(iVar10 + 0xc)) {
    if (iVar4 == 0) {
LAB_0005d002:
      iVar4 = 0;
      Curl_setup_transfer(param_1,0xffffffff,0xffffffff,0xffffffff,0,0,0xffffffff,0);
    }
    if (*(char *)(param_1 + 0x104) != '\0') {
      return iVar4;
    }
    goto LAB_0005d028;
  }
  if (*(char *)(param_1 + 0x104) != '\0') goto LAB_0005d06c;
  if (*(char *)(iVar9 + 0x309) != '\0') {
    iVar9 = ftp_nb_type(param_1,*(undefined *)(iVar9 + 0x2fb),0x16);
    if (iVar9 != 0) {
      return iVar9;
    }
    iVar9 = ftp_multi_statemach(param_1,&local_92);
    if (*(char *)(param_1 + 0x104) != '\0') {
      *param_2 = 0;
      return iVar9;
    }
    goto LAB_0005d218;
  }
  iVar4 = *param_1;
  *(undefined4 *)(iVar10 + 0x10) = 0xffffffff;
  *(undefined4 *)(iVar10 + 0x14) = 0xffffffff;
  if ((*(char *)(iVar4 + 0x8691) == '\0') || (*(char **)(iVar4 + 0x8694) == (char *)0x0)) {
    *(undefined4 *)(iVar4 + 0x60) = 0xffffffff;
    *(undefined4 *)(iVar4 + 100) = 0xffffffff;
  }
  else {
    lVar12 = strtoll(*(char **)(iVar4 + 0x8694),(char **)&local_90,0);
    __nptr = local_90;
    uVar7 = (uint)*local_90;
    if (uVar7 != 0) {
      ppuVar5 = __ctype_b_loc();
      do {
        if ((-1 < (int)((uint)(*ppuVar5)[uVar7] << 0x12)) && (uVar7 != 0x2d)) break;
        local_90 = __nptr + 1;
        uVar7 = (uint)__nptr[1];
        __nptr = local_90;
      } while (uVar7 != 0);
    }
    lVar13 = strtoll((char *)__nptr,(char **)&local_8c,0);
    lVar3 = lVar13;
    if (local_90 == local_8c) {
      lVar3 = -1;
    }
    if (lVar12 < 0 || local_90 != local_8c && lVar13 != -1) {
      if (lVar12 < 0) {
        *(longlong *)(iVar4 + 0x8698) = lVar12;
        *(int *)(iVar4 + 0x60) = -(int)lVar12;
        *(uint *)(iVar4 + 100) = -(int)((ulonglong)lVar12 >> 0x20) - (uint)((int)lVar12 != 0);
      }
      else {
        *(longlong *)(iVar4 + 0x8698) = lVar12;
        *(longlong *)(iVar4 + 0x60) = (lVar3 - lVar12) + 1;
      }
    }
    else {
      *(longlong *)(iVar4 + 0x8698) = lVar12;
    }
    *(undefined *)(param_1 + 0x103) = 1;
  }
  if ((*(char *)(iVar9 + 0x2fd) == '\0') && (param_1[0x102] != 0)) {
    iVar9 = ftp_nb_type(param_1,*(undefined *)(iVar9 + 0x2fb),0x15);
joined_r0x0005d30e:
    if (iVar9 != 0) {
      return iVar9;
    }
  }
  else if (*(int *)(iVar10 + 0xc) == 0) {
    iVar9 = ftp_nb_type(param_1,1,0x14);
    goto joined_r0x0005d30e;
  }
  iVar9 = ftp_multi_statemach(param_1,&local_92);
LAB_0005d218:
  *param_2 = (uint)local_92;
  return iVar9;
}

