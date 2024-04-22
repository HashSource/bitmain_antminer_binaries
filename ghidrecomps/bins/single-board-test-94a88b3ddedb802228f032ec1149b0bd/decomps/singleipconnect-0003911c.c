
/* WARNING: Type propagation algorithm not settling */

int singleipconnect(int *param_1,undefined4 param_2,int *param_3)

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  size_t sVar5;
  int iVar6;
  int *piVar7;
  char *pcVar8;
  uint __len;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  char *pcVar14;
  bool bVar15;
  uint local_310;
  int local_300;
  int iStack_2fc;
  int local_2f8;
  undefined auStack_2f4 [4];
  int *local_2f0;
  socklen_t local_2ec;
  undefined auStack_2e8 [48];
  sockaddr local_2b8;
  long local_2a0;
  sockaddr asStack_238 [8];
  uint local_1b8;
  int local_1b4;
  socklen_t local_1ac;
  sockaddr asStack_1a8 [8];
  uint local_128;
  undefined auStack_124 [256];
  
  iVar11 = *param_1;
  *param_3 = -1;
  iVar3 = Curl_socket(param_1,param_2,&local_1b8,&local_2f8);
  if (iVar3 != 0) {
    return 0;
  }
  iVar3 = getaddressinfo(asStack_1a8,auStack_2e8,auStack_2f4);
  if (iVar3 == 0) {
    piVar7 = __errno_location();
    iVar3 = *piVar7;
    uVar4 = Curl_strerror(param_1,iVar3);
    Curl_failf(iVar11,DAT_000393ec,iVar3,uVar4);
    Curl_closesocket(param_1,local_2f8);
    return 0;
  }
  Curl_infof(iVar11,DAT_000393e8,auStack_2e8);
  if (((local_1b8 & 0xfffffff7) == 2) && (local_1b4 == 1)) {
    if (*(char *)(iVar11 + 0x326) != '\0') {
      Curl_tcpnodelay(param_1,local_2f8);
    }
    iVar3 = local_2f8;
    if (*(char *)(iVar11 + 0x42c) != '\0') {
      local_2ec = 1;
      iVar12 = setsockopt(local_2f8,1,9,&local_2ec,4);
      if (iVar12 < 0) {
        Curl_infof(iVar11,DAT_000396ac,iVar3);
      }
      else {
        local_2ec = curlx_sltosi(*(undefined4 *)(iVar11 + 0x430));
        iVar12 = setsockopt(iVar3,6,4,&local_2ec,4);
        if (iVar12 < 0) {
          Curl_infof(iVar11,DAT_000396bc,iVar3);
        }
        local_2ec = curlx_sltosi(*(undefined4 *)(iVar11 + 0x434));
        iVar12 = setsockopt(iVar3,6,5,&local_2ec,4);
        if (iVar12 < 0) {
          Curl_infof(iVar11,DAT_000393f0,iVar3);
        }
      }
    }
  }
  if (*(code **)(iVar11 + 0x1d0) == (code *)0x0) {
LAB_0003918c:
    bVar2 = false;
  }
  else {
    iVar3 = (**(code **)(iVar11 + 0x1d0))(*(undefined4 *)(iVar11 + 0x1d4),local_2f8,0);
    if (iVar3 != 2) {
      if (iVar3 != 0) {
        Curl_closesocket(param_1,local_2f8);
        return 0x2a;
      }
      goto LAB_0003918c;
    }
    bVar2 = true;
  }
  uVar10 = local_1b8;
  iVar3 = local_2f8;
  if ((local_1b8 & 0xfffffff7) != 2) goto LAB_000391ca;
  uVar4 = Curl_ipv6_scope(asStack_1a8);
  iVar13 = *param_1;
  local_2f0 = (int *)0x0;
  uVar1 = *(ushort *)(iVar13 + 0x1a0);
  uVar9 = (uint)uVar1;
  pcVar14 = *(char **)(iVar13 + 0x358);
  iVar12 = *(int *)(iVar13 + 0x1a4);
  local_310 = (uint)(uVar9 == 0 && pcVar14 == (char *)0x0);
  if (uVar9 == 0 && pcVar14 == (char *)0x0) goto LAB_000391ca;
  __len = (uint)(uVar10 == 2);
  bVar15 = uVar10 == 10;
  memset(&local_2b8,local_310,0x80);
  if ((pcVar14 == (char *)0x0) || (sVar5 = strlen(pcVar14), 0xfe < sVar5)) {
    if (bVar15) {
      local_2b8.sa_family = 10;
      __len = 0x1c;
      local_2b8.sa_data._0_2_ = uVar1 << 8 | uVar1 >> 8;
    }
    else if (__len != 0) {
LAB_00039480:
      local_2b8.sa_family = 2;
      __len = 0x10;
      local_2b8.sa_data._0_2_ = uVar1 << 8 | uVar1 >> 8;
    }
    goto LAB_0003942a;
  }
  local_128 = local_310;
  memset(auStack_124,local_310,0xfc);
  iVar6 = strncmp(DAT_000393f4,pcVar14,3);
  if (iVar6 == 0) {
    pcVar14 = pcVar14 + 3;
    local_310 = 1;
LAB_00039336:
    iVar6 = Curl_if2ip(uVar10,uVar4,param_1[0x22],pcVar14,&local_128,0x100);
    if (iVar6 == 1) {
      iVar3 = 1;
      goto LAB_000394da;
    }
    if (iVar6 == 0) {
      if (local_310 != 0) {
        iVar3 = 0x2d;
        Curl_failf(iVar13,DAT_000396c8,pcVar14);
        goto LAB_000394da;
      }
      goto LAB_00039368;
    }
    if (iVar6 == 2) {
      Curl_infof(iVar13,DAT_000396c0,pcVar14,&local_128,uVar10);
      sVar5 = strlen(pcVar14);
      iVar6 = setsockopt(iVar3,1,0x19,pcVar14,sVar5 + 1);
      if (iVar6 != 0) {
        piVar7 = __errno_location();
        iVar6 = *piVar7;
        uVar4 = Curl_strerror(param_1,iVar6);
        Curl_infof(iVar13,DAT_000396c4,pcVar14,iVar6,uVar4);
      }
      goto LAB_000393d4;
    }
    if (local_310 == 0) goto LAB_00039368;
  }
  else {
    iVar6 = strncmp(DAT_000396a8,pcVar14,5);
    if (iVar6 != 0) goto LAB_00039336;
    pcVar14 = pcVar14 + 5;
LAB_00039368:
    iVar6 = param_1[0x88];
    if (__len == 0) {
      if (bVar15) {
        param_1[0x88] = 2;
      }
    }
    else {
      param_1[0x88] = 1;
    }
    Curl_resolv(param_1,pcVar14,0,&local_2f0);
    param_1[0x88] = iVar6;
    if (local_2f0 != (int *)0x0) {
      Curl_printable_address(*local_2f0,&local_128,0x100);
      Curl_infof(iVar13,DAT_000393f8,pcVar14,uVar10,&local_128,*(undefined4 *)(*local_2f0 + 4));
      Curl_resolv_unlock(iVar13,local_2f0);
LAB_000393d4:
      if (bVar15) {
        pcVar8 = strchr((char *)&local_128,0x25);
        pcVar14 = pcVar8;
        if (pcVar8 != (char *)0x0) {
          pcVar14 = pcVar8 + 1;
          *pcVar8 = '\0';
        }
        iVar6 = inet_pton(10,(char *)&local_128,local_2b8.sa_data + 6);
        if (0 < iVar6) {
          local_2b8.sa_family = 10;
          local_2b8.sa_data._0_2_ = uVar1 << 8 | uVar1 >> 8;
          if (pcVar14 != (char *)0x0) {
            local_2a0 = strtol(pcVar14,(char **)0x0,10);
            __len = 0x1c;
            goto LAB_0003942a;
          }
        }
        __len = 0x1c;
      }
      else {
        if ((__len != 0) &&
           (iVar6 = inet_pton(2,(char *)&local_128,local_2b8.sa_data + 2), 0 < iVar6))
        goto LAB_00039480;
        __len = 0;
      }
LAB_0003942a:
      while( true ) {
        iVar12 = iVar12 + -1;
        iVar6 = bind(iVar3,&local_2b8,__len);
        if (-1 < iVar6) break;
        if (iVar12 < 1) {
          piVar7 = __errno_location();
          iVar11 = *piVar7;
          iVar3 = 0x2d;
          *(int *)(iVar13 + 0x85cc) = iVar11;
          uVar4 = Curl_strerror(param_1,iVar11);
          Curl_failf(iVar13,DAT_000396a4,iVar11,uVar4);
          goto LAB_000394da;
        }
        uVar10 = uVar9 + 1;
        Curl_infof(iVar13,DAT_0003969c,uVar9);
        uVar9 = uVar10 & 0xffff;
        uVar10 = uVar10 & 0xff;
        if (local_2b8.sa_family == 2) {
          uVar10 = uVar9;
        }
        local_2b8.sa_data._0_2_ = (ushort)(uVar10 << 8) | (ushort)(uVar9 >> 8);
      }
      local_2ec = 0x80;
      memset(asStack_238,0,0x80);
      iVar3 = getsockname(iVar3,asStack_238,&local_2ec);
      if (iVar3 < 0) {
        piVar7 = __errno_location();
        iVar3 = *piVar7;
        *(int *)(iVar13 + 0x85cc) = iVar3;
        uVar4 = Curl_strerror(param_1,iVar3);
        Curl_failf(iVar13,DAT_000396b4,iVar3,uVar4);
        Curl_closesocket(param_1,local_2f8);
        return 0x2d;
      }
      Curl_infof(iVar13,DAT_000396a0,uVar9);
      *(undefined *)((int)param_1 + 0x203) = 1;
LAB_000391ca:
      curlx_nonblock(local_2f8,1);
      curlx_tvnow(&local_300);
      param_1[0x82] = local_300;
      param_1[0x83] = iStack_2fc;
      if (1 < param_1[0x84]) {
        Curl_expire_latest(iVar11,param_1[0x85]);
      }
      if ((!bVar2) && (param_1[0x23] == 1)) {
        iVar3 = connect(local_2f8,asStack_1a8,local_1ac);
        if (iVar3 == -1) {
          piVar7 = __errno_location();
          iVar3 = *piVar7;
          *(bool *)(param_1 + 0x7d) = local_1b8 == 10;
          if ((iVar3 != 0xb) && (iVar3 != 0x73)) {
            uVar4 = Curl_strerror(param_1,iVar3);
            Curl_infof(iVar11,DAT_000396b0,auStack_2e8,uVar4);
            *(int *)(iVar11 + 0x85cc) = iVar3;
            Curl_closesocket(param_1,local_2f8);
            return 7;
          }
        }
        else {
          *(bool *)(param_1 + 0x7d) = local_1b8 == 10;
        }
      }
      *param_3 = local_2f8;
      return 0;
    }
  }
  iVar3 = 0x2d;
  Curl_failf(iVar13,DAT_000396b8,pcVar14);
LAB_000394da:
  Curl_closesocket(param_1,local_2f8);
  if (iVar3 != 1) {
    return iVar3;
  }
  return 7;
}

