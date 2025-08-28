
/* WARNING: Type propagation algorithm not settling */

int ftp_state_use_port(int *param_1,int param_2)

{
  char cVar1;
  char *__cp;
  size_t sVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  char *extraout_r1;
  char *extraout_r2;
  char *__buf;
  socklen_t extraout_r3;
  socklen_t __len;
  uint uVar9;
  char *pcVar10;
  char *pcVar11;
  int iVar12;
  char *unaff_r11;
  char *pcVar13;
  bool bVar14;
  int local_9b8;
  socklen_t local_9b4;
  int *local_9b0;
  sockaddr local_9ac [8];
  undefined4 local_92c;
  undefined4 auStack_928 [63];
  char local_82c [1024];
  char acStack_42c [1032];
  
  pcVar10 = (char *)0x0;
  iVar12 = *param_1;
  local_92c = 0;
  local_9b8 = -1;
  memset(auStack_928,0,0xfc);
  pcVar11 = *(char **)(iVar12 + 0x368);
  local_9b0 = (int *)0x0;
  if (pcVar11 == (char *)0x0) {
    pcVar10 = (char *)0x0;
    pcVar11 = (char *)0x0;
    pcVar4 = (char *)0x0;
LAB_0005ba04:
    local_9b4 = 0x80;
    iVar3 = getsockname(param_1[0x55],local_9ac,&local_9b4);
    if (iVar3 != 0) {
      piVar8 = __errno_location();
      pcVar5 = (char *)Curl_strerror(param_1,*piVar8);
      pcVar11 = "getsockname() failed: %s";
      goto LAB_0005bb9a;
    }
    bVar14 = local_9ac[0].sa_family == 10;
    if (bVar14) {
      pcVar5 = acStack_42c;
      pcVar13 = (char *)0x0;
    }
    else {
      pcVar13 = acStack_42c;
      unaff_r11 = (char *)0x0;
      pcVar5 = extraout_r2;
    }
    __buf = pcVar13;
    __cp = extraout_r1;
    __len = extraout_r3;
    if (bVar14) {
      __len = 0x401;
      __buf = pcVar5;
      __cp = local_9ac[0].sa_data + 6;
    }
    pcVar5 = __buf;
    if (!bVar14) {
      __len = 0x401;
      pcVar5 = pcVar13;
      __cp = local_9ac[0].sa_data + 2;
      pcVar13 = unaff_r11;
    }
    inet_ntop((uint)local_9ac[0].sa_family,__cp,__buf,__len);
  }
  else {
    sVar2 = strlen(pcVar11);
    if (sVar2 < 2) {
      pcVar11 = (char *)0x0;
      pcVar4 = (char *)0x0;
      goto LAB_0005ba04;
    }
    if (sVar2 < 0x2e) {
      iVar3 = 0x2f;
    }
    else {
      iVar3 = sVar2 + 1;
    }
    pcVar10 = (char *)(*Curl_ccalloc)(iVar3,1);
    if (pcVar10 == (char *)0x0) {
      return 0x1b;
    }
    if (*pcVar11 == '[') {
      pcVar4 = strchr(pcVar11,0x5d);
      if (pcVar4 != (char *)0x0) {
        strncpy(pcVar10,pcVar11 + 1,(int)pcVar4 - (int)(pcVar11 + 1));
        pcVar11 = pcVar4;
        goto LAB_0005b97a;
      }
LAB_0005bb8a:
      pcVar11 = (char *)0x0;
      pcVar4 = pcVar11;
    }
    else {
      if (*pcVar11 != ':') {
        pcVar4 = strchr(pcVar11,0x3a);
        if ((pcVar4 == (char *)0x0) || (iVar3 = inet_pton(10,pcVar11,local_9ac), iVar3 == 1)) {
          strcpy(pcVar10,pcVar11);
          goto LAB_0005bb8a;
        }
        strncpy(pcVar10,pcVar11,(int)pcVar4 - (int)pcVar11);
        pcVar11 = pcVar4;
      }
LAB_0005b97a:
      pcVar11 = strchr(pcVar11,0x3a);
      pcVar4 = pcVar11;
      if (pcVar11 != (char *)0x0) {
        strtoul(pcVar11 + 1,(char **)0x0,10);
        pcVar4 = (char *)curlx_ultous();
        pcVar5 = strchr(pcVar11,0x2d);
        pcVar11 = pcVar4;
        if (pcVar5 != (char *)0x0) {
          strtoul(pcVar5 + 1,(char **)0x0,10);
          pcVar11 = (char *)curlx_ultous();
          if (pcVar11 < pcVar4) {
            pcVar11 = (char *)0x0;
            pcVar4 = (char *)0x0;
          }
        }
      }
    }
    if (*pcVar10 == '\0') goto LAB_0005ba04;
    unaff_r11 = *(char **)(param_1[0x13] + 4);
    uVar6 = Curl_ipv6_scope(*(undefined4 *)(param_1[0x13] + 0x18));
    iVar3 = Curl_if2ip(unaff_r11,uVar6,param_1[0x22],pcVar10,acStack_42c,0x401);
    if (iVar3 == 1) {
      return 0x1e;
    }
    pcVar5 = pcVar10;
    if ((iVar3 != 0) && (pcVar5 = acStack_42c, iVar3 != 2)) goto LAB_0005ba04;
    pcVar13 = (char *)0x1;
  }
  Curl_resolv(param_1,pcVar5,0,&local_9b0);
  if (local_9b0 != (int *)0x0) {
    iVar3 = *local_9b0;
    Curl_resolv_unlock(iVar12);
    if (iVar3 != 0) {
      (*Curl_cfree)(pcVar10);
      local_9b8 = -1;
      while (iVar7 = Curl_socket(param_1,iVar3,0,&local_9b8), iVar7 != 0) {
        piVar8 = __errno_location();
        iVar3 = *(int *)(iVar3 + 0x1c);
        if (iVar3 == 0) {
          uVar6 = Curl_strerror(param_1,*piVar8);
          Curl_failf(iVar12,"socket failure: %s",uVar6);
          return 0x1e;
        }
      }
      memcpy(local_9ac,*(void **)(iVar3 + 0x18),*(size_t *)(iVar3 + 0x10));
      local_9b4 = *(socklen_t *)(iVar3 + 0x10);
      pcVar10 = pcVar4;
      do {
        if (pcVar11 < pcVar10) {
          Curl_failf(iVar12,"bind() failed, we ran out of ports!");
          Curl_closesocket(param_1,local_9b8);
          return 0x1e;
        }
        while( true ) {
          local_9ac[0].sa_data._0_2_ =
               (ushort)(byte)((uint)pcVar10 >> 8) | (ushort)((int)pcVar10 << 8);
          iVar7 = bind(local_9b8,local_9ac,local_9b4);
          if (iVar7 == 0) {
            local_9b4 = 0x80;
            iVar7 = getsockname(local_9b8,local_9ac,&local_9b4);
            if (iVar7 != 0) {
              piVar8 = __errno_location();
              uVar6 = Curl_strerror(param_1,*piVar8);
              Curl_failf(iVar12,"getsockname() failed: %s",uVar6);
              Curl_closesocket(param_1,local_9b8);
              return 0x1e;
            }
            iVar7 = listen(local_9b8,1);
            if (iVar7 != 0) {
              piVar8 = __errno_location();
              uVar6 = Curl_strerror(param_1,*piVar8);
              Curl_failf(iVar12,"socket failure: %s",uVar6);
              Curl_closesocket(param_1,local_9b8);
              return 0x1e;
            }
            Curl_printable_address(iVar3,&local_92c,0x100);
            if ((*(char *)((int)param_1 + 0x1fe) == '\0') && ((char)param_1[0x7d] != '\0')) {
              *(undefined1 *)((int)param_1 + 0x1fe) = 1;
            }
            if (param_2 == 2) goto LAB_0005bd50;
            iVar3 = param_2;
            goto LAB_0005bcbc;
          }
          piVar8 = __errno_location();
          iVar7 = *piVar8;
          if (iVar7 == 99) {
            uVar9 = (uint)pcVar13 & 1;
          }
          else {
            uVar9 = 0;
          }
          if (uVar9 == 0) break;
          uVar6 = Curl_strerror(param_1,99);
          Curl_infof(iVar12,"bind(port=%hu) on non-local address failed: %s\n",pcVar10,uVar6);
          local_9b4 = 0x80;
          iVar7 = getsockname(param_1[0x55],local_9ac,&local_9b4);
          if (iVar7 != 0) {
            uVar6 = Curl_strerror(param_1,*piVar8);
            Curl_failf(iVar12,"getsockname() failed: %s",uVar6);
            Curl_closesocket(param_1,local_9b8);
            return 0x1e;
          }
          pcVar13 = (char *)0x0;
          pcVar10 = pcVar4;
        }
        if (iVar7 != 0xd && iVar7 != 0x62) {
          uVar6 = Curl_strerror(param_1);
          Curl_failf(iVar12,"bind(port=%hu) failed: %s",pcVar10,uVar6);
          Curl_closesocket(param_1,local_9b8);
          return 0x1e;
        }
        pcVar10 = (char *)((uint)(pcVar10 + 1) & 0xffff);
      } while( true );
    }
  }
  pcVar11 = "failed to resolve the address provided to PORT: %s";
LAB_0005bb9a:
  Curl_failf(iVar12,pcVar11,pcVar5);
  (*Curl_cfree)(pcVar10);
  return 0x1e;
LAB_0005bcbc:
  iVar3 = iVar3 + 1;
  if ((*(char *)((int)param_1 + 0x1fe) != '\0') || (param_2 != 0)) {
    if (param_2 == 1) {
      if (local_9ac[0].sa_family != 2) goto LAB_0005bd50;
LAB_0005bcde:
      pcVar10 = local_82c;
      pcVar11 = (char *)&local_92c;
      goto LAB_0005bcfa;
    }
    if ((local_9ac[0].sa_family == 2) || (local_9ac[0].sa_family == 10)) {
      if (param_2 == 0) {
        if (local_9ac[0].sa_family == 2) {
          uVar6 = 1;
        }
        else {
          uVar6 = 2;
        }
        iVar7 = Curl_pp_sendf(param_1 + 0xf0,"%s |%d|%s|%hu|",mode_23518,uVar6,&local_92c,
                              local_9ac[0].sa_data._0_2_ << 8 |
                              (ushort)local_9ac[0].sa_data._0_2_ >> 8);
        iVar3 = 0;
        if (iVar7 != 0) {
          uVar6 = curl_easy_strerror();
          Curl_failf(iVar12,"Failure sending EPRT command: %s",uVar6);
          Curl_closesocket(param_1,local_9b8);
          param_1[0x107] = 1;
          param_1[0x10a] = 0;
          return iVar7;
        }
        goto LAB_0005bd2e;
      }
      if (param_2 == 1) goto LAB_0005bcde;
    }
    if (iVar3 == 2) goto LAB_0005bd2e;
  }
  param_2 = param_2 + 1;
  goto LAB_0005bcbc;
LAB_0005bd50:
  iVar3 = 2;
  goto LAB_0005bd2e;
  while( true ) {
    if (cVar1 == '.') {
      pcVar10[-1] = ',';
    }
    else {
      pcVar10[-1] = cVar1;
    }
    pcVar11 = pcVar5;
    pcVar4 = pcVar10;
    if (pcVar5 == (char *)0x0) break;
LAB_0005bcfa:
    pcVar10 = pcVar10 + 1;
    pcVar5 = pcVar11 + 1;
    cVar1 = *pcVar11;
    pcVar4 = pcVar10 + -1;
    if (cVar1 == '\0') break;
  }
  *pcVar4 = '\0';
  curl_msnprintf(pcVar4,0x14,",%d,%d",local_9ac[0].sa_data._0_2_ & 0xff,
                 SUB21(local_9ac[0].sa_data._0_2_,1));
  iVar3 = Curl_pp_sendf(param_1 + 0xf0,"%s %s",0x13c251,local_82c);
  if (iVar3 != 0) {
    uVar6 = curl_easy_strerror();
    Curl_failf(iVar12,"Failure sending PORT command: %s",uVar6);
    Curl_closesocket(param_1,local_9b8);
    param_1[0x10a] = 0;
    return iVar3;
  }
  iVar3 = 1;
LAB_0005bd2e:
  param_1[0x107] = iVar3;
  close_secondarysocket(param_1);
  *(undefined1 *)((int)param_1 + 0x1f7) = 1;
  param_1[0x10a] = 0x1c;
  param_1[0x56] = local_9b8;
  return 0;
}

