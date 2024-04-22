
/* WARNING: Type propagation algorithm not settling */

int ftp_state_use_port(int *param_1,int param_2)

{
  char cVar1;
  size_t sVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  socklen_t *psVar9;
  char *extraout_r1;
  socklen_t *__buf;
  socklen_t __len;
  uint uVar10;
  socklen_t *__dest;
  undefined4 *puVar11;
  char *pcVar13;
  int iVar14;
  socklen_t *unaff_r11;
  socklen_t *psVar15;
  bool bVar16;
  int local_9b8;
  socklen_t local_9b4;
  int *local_9b0;
  sockaddr local_9ac [8];
  undefined4 local_92c;
  undefined auStack_928 [252];
  char local_82c [1024];
  socklen_t asStack_42c [258];
  undefined4 *puVar12;
  
  __dest = (socklen_t *)0x0;
  iVar14 = *param_1;
  local_92c = 0;
  local_9b8 = -1;
  memset(auStack_928,0,0xfc);
  pcVar13 = *(char **)(iVar14 + 0x368);
  local_9b0 = (int *)0x0;
  if (pcVar13 == (char *)0x0) {
    __dest = (socklen_t *)0x0;
    pcVar13 = (char *)0x0;
    pcVar4 = (char *)0x0;
LAB_0005ba04:
    __len = 0x80;
    psVar9 = &local_9b4;
    local_9b4 = 0x80;
    iVar3 = getsockname(param_1[0x55],local_9ac,psVar9);
    if (iVar3 != 0) {
      piVar8 = __errno_location();
      psVar9 = (socklen_t *)Curl_strerror(param_1,*piVar8);
      uVar6 = DAT_0005bdbc;
      goto LAB_0005bb9a;
    }
    bVar16 = local_9ac[0].sa_family == 10;
    if (bVar16) {
      psVar9 = asStack_42c;
      psVar15 = (socklen_t *)0x0;
    }
    else {
      psVar15 = asStack_42c;
      unaff_r11 = (socklen_t *)0x0;
    }
    __buf = psVar15;
    pcVar5 = extraout_r1;
    if (bVar16) {
      __len = 0x401;
      __buf = psVar9;
      pcVar5 = local_9ac[0].sa_data + 6;
    }
    psVar9 = __buf;
    if (!bVar16) {
      __len = 0x401;
      psVar9 = psVar15;
      pcVar5 = local_9ac[0].sa_data + 2;
      psVar15 = unaff_r11;
    }
    inet_ntop((uint)local_9ac[0].sa_family,pcVar5,(char *)__buf,__len);
  }
  else {
    sVar2 = strlen(pcVar13);
    if (sVar2 < 2) {
      pcVar13 = (char *)0x0;
      pcVar4 = (char *)0x0;
      goto LAB_0005ba04;
    }
    if (sVar2 < 0x2e) {
      iVar3 = 0x2f;
    }
    else {
      iVar3 = sVar2 + 1;
    }
    __dest = (socklen_t *)(**DAT_0005bbb0)(iVar3,1);
    if (__dest == (socklen_t *)0x0) {
      return 0x1b;
    }
    if (*pcVar13 == '[') {
      pcVar4 = strchr(pcVar13,0x5d);
      if (pcVar4 != (char *)0x0) {
        strncpy((char *)__dest,pcVar13 + 1,(int)pcVar4 - (int)(pcVar13 + 1));
        pcVar13 = pcVar4;
        goto LAB_0005b97a;
      }
LAB_0005bb8a:
      pcVar13 = (char *)0x0;
      pcVar4 = pcVar13;
    }
    else {
      if (*pcVar13 != ':') {
        pcVar4 = strchr(pcVar13,0x3a);
        if ((pcVar4 == (char *)0x0) || (iVar3 = inet_pton(10,pcVar13,local_9ac), iVar3 == 1)) {
          strcpy((char *)__dest,pcVar13);
          goto LAB_0005bb8a;
        }
        strncpy((char *)__dest,pcVar13,(int)pcVar4 - (int)pcVar13);
        pcVar13 = pcVar4;
      }
LAB_0005b97a:
      pcVar13 = strchr(pcVar13,0x3a);
      pcVar4 = pcVar13;
      if (pcVar13 != (char *)0x0) {
        strtoul(pcVar13 + 1,(char **)0x0,10);
        pcVar4 = (char *)curlx_ultous();
        pcVar5 = strchr(pcVar13,0x2d);
        pcVar13 = pcVar4;
        if (pcVar5 != (char *)0x0) {
          strtoul(pcVar5 + 1,(char **)0x0,10);
          pcVar13 = (char *)curlx_ultous();
          if (pcVar13 < pcVar4) {
            pcVar13 = (char *)0x0;
            pcVar4 = (char *)0x0;
          }
        }
      }
    }
    if (*(char *)__dest == '\0') goto LAB_0005ba04;
    unaff_r11 = *(socklen_t **)(param_1[0x13] + 4);
    uVar6 = Curl_ipv6_scope(*(undefined4 *)(param_1[0x13] + 0x18));
    iVar3 = Curl_if2ip(unaff_r11,uVar6,param_1[0x22],__dest,asStack_42c,0x401);
    if (iVar3 == 1) {
      return 0x1e;
    }
    psVar9 = __dest;
    if ((iVar3 != 0) && (psVar9 = asStack_42c, iVar3 != 2)) goto LAB_0005ba04;
    psVar15 = (socklen_t *)0x1;
  }
  Curl_resolv(param_1,psVar9,0,&local_9b0);
  uVar6 = DAT_0005bbc8;
  if (local_9b0 != (int *)0x0) {
    iVar3 = *local_9b0;
    Curl_resolv_unlock(iVar14);
    uVar6 = DAT_0005bbc8;
    if (iVar3 != 0) {
      (**DAT_0005bbb4)(__dest);
      local_9b8 = -1;
      while (iVar7 = Curl_socket(param_1,iVar3,0,&local_9b8), iVar7 != 0) {
        piVar8 = __errno_location();
        iVar3 = *(int *)(iVar3 + 0x1c);
        if (iVar3 == 0) {
          uVar6 = Curl_strerror(param_1,*piVar8);
          Curl_failf(iVar14,DAT_0005bbb8,uVar6);
          return 0x1e;
        }
      }
      memcpy(local_9ac,*(void **)(iVar3 + 0x18),*(size_t *)(iVar3 + 0x10));
      local_9b4 = *(socklen_t *)(iVar3 + 0x10);
      pcVar5 = pcVar4;
      do {
        if (pcVar13 < pcVar5) {
          Curl_failf(iVar14,DAT_0005bbbc);
          Curl_closesocket(param_1,local_9b8);
          return 0x1e;
        }
        while( true ) {
          local_9ac[0].sa_data._0_2_ =
               (ushort)(byte)((uint)pcVar5 >> 8) | (ushort)((int)pcVar5 << 8);
          iVar7 = bind(local_9b8,local_9ac,local_9b4);
          if (iVar7 == 0) {
            local_9b4 = 0x80;
            iVar7 = getsockname(local_9b8,local_9ac,&local_9b4);
            if (iVar7 != 0) {
              piVar8 = __errno_location();
              uVar6 = Curl_strerror(param_1,*piVar8);
              Curl_failf(iVar14,DAT_0005bdbc,uVar6);
              Curl_closesocket(param_1,local_9b8);
              return 0x1e;
            }
            iVar7 = listen(local_9b8,1);
            if (iVar7 != 0) {
              piVar8 = __errno_location();
              uVar6 = Curl_strerror(param_1,*piVar8);
              Curl_failf(iVar14,DAT_0005bdc4,uVar6);
              Curl_closesocket(param_1,local_9b8);
              return 0x1e;
            }
            Curl_printable_address(iVar3,&local_92c,0x100);
            if ((*(char *)((int)param_1 + 0x1fe) == '\0') && (*(char *)(param_1 + 0x7d) != '\0')) {
              *(undefined *)((int)param_1 + 0x1fe) = 1;
            }
            if (param_2 == 2) goto LAB_0005bd50;
            iVar3 = param_2;
            goto LAB_0005bcbc;
          }
          piVar8 = __errno_location();
          iVar7 = *piVar8;
          if (iVar7 == 99) {
            uVar10 = (uint)psVar15 & 1;
          }
          else {
            uVar10 = 0;
          }
          if (uVar10 == 0) break;
          uVar6 = Curl_strerror(param_1,99);
          Curl_infof(iVar14,DAT_0005bbc0,pcVar5,uVar6);
          local_9b4 = 0x80;
          iVar7 = getsockname(param_1[0x55],local_9ac,&local_9b4);
          if (iVar7 != 0) {
            uVar6 = Curl_strerror(param_1,*piVar8);
            Curl_failf(iVar14,DAT_0005bbc4,uVar6);
            Curl_closesocket(param_1,local_9b8);
            return 0x1e;
          }
          psVar15 = (socklen_t *)0x0;
          pcVar5 = pcVar4;
        }
        if (iVar7 != 0xd && iVar7 != 0x62) {
          uVar6 = Curl_strerror(param_1);
          Curl_failf(iVar14,DAT_0005bdc0,pcVar5,uVar6);
          Curl_closesocket(param_1,local_9b8);
          return 0x1e;
        }
        pcVar5 = (char *)((uint)(pcVar5 + 1) & 0xffff);
      } while( true );
    }
  }
LAB_0005bb9a:
  Curl_failf(iVar14,uVar6,psVar9);
  (**DAT_0005bbb4)(__dest);
  return 0x1e;
LAB_0005bcbc:
  iVar3 = iVar3 + 1;
  if ((*(char *)((int)param_1 + 0x1fe) != '\0') || (param_2 != 0)) {
    if (param_2 == 1) {
      if (local_9ac[0].sa_family != 2) goto LAB_0005bd50;
LAB_0005bcde:
      pcVar13 = local_82c;
      puVar12 = &local_92c;
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
        iVar7 = Curl_pp_sendf(param_1 + 0xf0,DAT_0005bdd8,DAT_0005bdd4,uVar6,&local_92c,
                              ((ushort)local_9ac[0].sa_data._0_2_ & 0xff) << 8 |
                              (uint)((ushort)local_9ac[0].sa_data._0_2_ >> 8));
        iVar3 = 0;
        if (iVar7 != 0) {
          uVar6 = curl_easy_strerror();
          Curl_failf(iVar14,DAT_0005bddc,uVar6);
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
      pcVar13[-1] = ',';
    }
    else {
      pcVar13[-1] = cVar1;
    }
    puVar12 = puVar11;
    pcVar4 = pcVar13;
    if (puVar11 == (undefined4 *)0x0) break;
LAB_0005bcfa:
    pcVar13 = pcVar13 + 1;
    puVar11 = (undefined4 *)((int)puVar12 + 1);
    cVar1 = *(char *)puVar12;
    pcVar4 = pcVar13 + -1;
    if (cVar1 == '\0') break;
  }
  *pcVar4 = '\0';
  curl_msnprintf(pcVar4,0x14,DAT_0005bdc8,(ushort)local_9ac[0].sa_data._0_2_ & 0xff,
                 (char)((ushort)local_9ac[0].sa_data._0_2_ >> 8));
  iVar3 = Curl_pp_sendf(param_1 + 0xf0,DAT_0005bdcc,DAT_0005bdd0,local_82c);
  if (iVar3 != 0) {
    uVar6 = curl_easy_strerror();
    Curl_failf(iVar14,DAT_0005bde0,uVar6);
    Curl_closesocket(param_1,local_9b8);
    param_1[0x10a] = 0;
    return iVar3;
  }
  iVar3 = 1;
LAB_0005bd2e:
  param_1[0x107] = iVar3;
  close_secondarysocket(param_1);
  *(undefined *)((int)param_1 + 0x1f7) = 1;
  param_1[0x10a] = 0x1c;
  param_1[0x56] = local_9b8;
  return 0;
}

