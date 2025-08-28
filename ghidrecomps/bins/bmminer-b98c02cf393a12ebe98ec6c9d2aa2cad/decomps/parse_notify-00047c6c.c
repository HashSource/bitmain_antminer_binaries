
int parse_notify(undefined4 *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  int *piVar5;
  byte *pbVar6;
  char *__s;
  char *__s_00;
  int iVar7;
  int *piVar8;
  size_t sVar9;
  undefined4 uVar10;
  int iVar11;
  undefined4 *puVar12;
  void *__ptr;
  char *pcVar13;
  byte *pbVar14;
  int iVar15;
  char *__s_01;
  uint uVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  bool bVar20;
  char *local_978 [5];
  undefined4 local_964;
  char *local_960;
  char *local_95c;
  int local_958;
  undefined4 *local_954;
  int local_950;
  char *local_94c;
  char *local_948;
  char *local_944;
  char *local_940;
  pthread_mutex_t *local_93c;
  uint local_938;
  char *local_934;
  uint local_930;
  uint local_92c;
  undefined4 local_928;
  undefined4 local_924;
  int local_920;
  undefined4 local_91c;
  undefined4 local_918;
  byte *local_914;
  char acStack_90c [228];
  undefined4 local_828;
  undefined4 uStack_824;
  undefined4 uStack_820;
  undefined4 uStack_81c;
  undefined4 local_818;
  undefined4 uStack_814;
  undefined4 uStack_810;
  undefined4 uStack_80c;
  undefined4 local_808;
  undefined4 uStack_804;
  undefined4 uStack_800;
  undefined4 uStack_7fc;
  undefined4 local_7f8;
  undefined2 uStack_7f4;
  undefined1 local_7f2;
  
  local_914 = (byte *)param_1;
  piVar5 = (int *)json_array_get(param_2,4);
  if (piVar5 == (int *)0x0) {
    return 0;
  }
  if (*piVar5 != 1) {
    return 0;
  }
  local_920 = json_array_size();
  pbVar6 = (byte *)json_array_string(param_2,0);
  local_918 = __json_array_string(param_2,1);
  __s = (char *)json_array_string(param_2,2);
  __s_00 = (char *)json_array_string(param_2,3);
  local_91c = __json_array_string(param_2,5);
  local_924 = __json_array_string(param_2,6);
  local_928 = __json_array_string(param_2,7);
  iVar7 = json_array_get(param_2,8);
  if (iVar7 == 0) {
    uVar16 = 0;
  }
  else {
    piVar8 = (int *)json_array_get(param_2,8);
    uVar16 = (uint)(*piVar8 == 5);
  }
  local_92c = uVar16;
  if (pbVar6 == (byte *)0x0) {
    if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 3))
    goto LAB_00047db2;
    pcVar13 = "Null string passed to valid_ascii from";
  }
  else {
    sVar9 = strlen((char *)pbVar6);
    if (sVar9 != 0) {
      if (0 < (int)sVar9) {
        pcVar13 = (char *)(uint)*pbVar6;
        if (pcVar13 + -0x20 < (char *)0x5f) {
          pbVar14 = pbVar6;
          do {
            pbVar14 = pbVar14 + 1;
            if (pbVar14 == pbVar6 + sVar9) goto LAB_00047dda;
            pcVar13 = (char *)(uint)*pbVar14;
          } while (pcVar13 + -0x20 < (char *)0x5f);
        }
        if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
          local_978[1] = "util.c";
          local_978[2] = "parse_notify";
          local_978[3] = (char *)0x79b;
          local_978[0] = pcVar13;
          snprintf((char *)&local_828,0x800,"Invalid char 0x%x passed to valid_ascii from",
                   " in %s %s():%d");
          _applog(3,&local_828,0);
        }
        goto LAB_00047db2;
      }
LAB_00047dda:
      iVar7 = _valid_hex_constprop_10(local_918,"parse_notify",0x79b);
      if (((iVar7 == 0) || (iVar7 = _valid_hex_constprop_10(__s,"parse_notify",0x79b), iVar7 == 0))
         || ((iVar7 = _valid_hex_constprop_10(__s_00,"parse_notify",0x79c), iVar7 == 0 ||
             (((iVar7 = _valid_hex_constprop_10(local_91c,"parse_notify",0x79c), iVar7 == 0 ||
               (iVar7 = _valid_hex_constprop_10(local_924,"parse_notify",0x79c), iVar7 == 0)) ||
              (iVar7 = _valid_hex_constprop_10(local_928,"parse_notify",0x79d), iVar7 == 0))))))
      goto LAB_00047db2;
      local_93c = (pthread_mutex_t *)((int)local_914 + 0xd4);
      iVar7 = pthread_mutex_lock(local_93c);
      if (iVar7 != 0) {
        _mutex_lock_part_1_constprop_16("parse_notify",0x7a6);
      }
      pbVar14 = local_914;
      local_954 = (undefined4 *)((int)local_914 + 0xec);
      _wr_lock_constprop_12(local_954,"parse_notify",0x7a6);
      local_940 = (char *)((int)pbVar14 + 0x6b0);
      local_914 = pbVar14;
      free(*(void **)((int)pbVar14 + 0x2a0));
      *(byte **)((int)local_914 + 0x2a0) = pbVar6;
      snprintf((char *)((int)pbVar14 + 0x6b0),0x41,"%s",local_918);
      sVar9 = strlen(__s);
      local_930 = sVar9 >> 1;
      pcVar13 = (char *)((int)local_914 + 0x6f4);
      local_944 = pcVar13;
      sVar9 = strlen(__s_00);
      local_938 = sVar9 >> 1;
      __s_01 = (char *)((int)local_914 + 0x700);
      local_948 = __s_01;
      snprintf(pcVar13,9,"%s",local_91c);
      pcVar13 = (char *)((int)local_914 + 0x70c);
      local_94c = pcVar13;
      snprintf(__s_01,9,"%s",local_924);
      snprintf(pcVar13,9,"%s",local_928);
      pbVar14 = local_914;
      *(char *)((int)local_914 + 0x2a8) = (char)uVar16;
      if (0.0 < *(double *)((int)local_914 + 0x718)) {
        *(double *)((int)local_914 + 0x720) = *(double *)((int)local_914 + 0x718);
      }
      *(uint *)((int)local_914 + 0x628) = *(int *)((int)local_914 + 0x61c) + local_930;
      local_950 = *(int *)((int)local_914 + 0x61c) + local_930 +
                  *(int *)((int)local_914 + 0x278) + local_938;
      *(int *)((int)local_914 + 0x624) = local_950;
      if (0 < *(int *)((int)local_914 + 0x6ac)) {
        iVar7 = 0;
        do {
          iVar18 = iVar7 * 4;
          iVar7 = iVar7 + 1;
          free(*(void **)(*(int *)((int)pbVar14 + 0x2a4) + iVar18));
        } while (iVar7 < *(int *)((int)pbVar14 + 0x6ac));
      }
      local_914 = pbVar14;
      if (local_920 == 0) {
        local_934 = &opt_protocol;
        *(undefined4 *)((int)pbVar14 + 0x6ac) = 0;
LAB_00047f6e:
        uVar16 = *(uint *)((int)local_914 + 0x178);
        *(uint *)((int)local_914 + 0x178) = uVar16 + 1;
        *(uint *)((int)local_914 + 0x17c) =
             *(int *)((int)local_914 + 0x17c) + (uint)(0xfffffffe < uVar16);
LAB_00047f7e:
        if (local_92c != 0) {
          *(undefined4 *)((int)local_914 + 0x270) = 0;
          *(undefined4 *)((int)local_914 + 0x274) = 0;
        }
        local_978[3] = local_948;
        local_978[1] = "0000000000000000000000000000000000000000000000000000000000000000";
        local_964 = workpadding;
        local_978[2] = local_94c;
        local_978[4] = "00000000";
        local_978[0] = local_940;
        snprintf(acStack_90c,0xe1,"%s%s%s%s%s%s%s",local_944);
        iVar7 = hex2bin((undefined4 *)((int)local_914 + 0x62c),acStack_90c,0x70);
        if (iVar7 == 0) {
          if (((use_syslog != '\0') || (opt_log_output != '\0')) ||
             (pbVar14 = local_914, 2 < opt_log_level)) {
            pcVar13 = "Failed to convert header to header_bin in parse_notify";
            goto LAB_0004864e;
          }
LAB_0004863c:
          local_914 = pbVar14;
          iVar7 = 0;
        }
        else {
          iVar18 = -(local_930 + 0xe & 0xfffffff8);
          iVar7 = hex2bin((int)&local_960 + iVar18,__s);
          if (iVar7 == 0) {
            if (((use_syslog == '\0') && (opt_log_output == '\0')) &&
               (pbVar14 = local_914, opt_log_level < 3)) goto LAB_0004863c;
            pcVar13 = "Failed to convert cb1 to cb1_bin in parse_notify";
            iVar7 = 0;
          }
          else {
            iVar2 = -(local_938 + 0xe & 0xfffffff8);
            iVar17 = (int)&local_960 + iVar2 + iVar18;
            iVar7 = hex2bin(iVar17,__s_00);
            pbVar14 = local_914;
            if (iVar7 != 0) {
              free(*(void **)((int)local_914 + 0x620));
              *(undefined4 *)((int)local_978 + iVar2 + iVar18) = 0x7f9;
              uVar10 = _cgcalloc(local_950,1,"util.c","parse_notify");
              *(undefined4 *)((int)pbVar14 + 0x620) = uVar10;
              *(undefined4 *)((int)local_978 + iVar2 + iVar18 + 4) = 0x7fa;
              *(char **)((int)local_978 + iVar2 + iVar18) = "parse_notify";
              _cg_memcpy(uVar10,(int)&local_960 + iVar18,local_930,"util.c");
              pbVar4 = local_914;
              iVar19 = *(int *)((int)pbVar14 + 0x61c);
              if (iVar19 != 0) {
                iVar11 = *(int *)((int)local_914 + 0x620);
                *(undefined4 *)((int)local_978 + iVar2 + iVar18 + 4) = 0x7fc;
                uVar16 = local_930;
                *(char **)((int)local_978 + iVar2 + iVar18) = "parse_notify";
                _cg_memcpy(iVar11 + uVar16,*(undefined4 *)((int)pbVar4 + 0x268),iVar19,"util.c");
                iVar19 = *(int *)((int)pbVar4 + 0x61c);
              }
              uVar16 = local_938;
              iVar11 = *(int *)((int)local_914 + 0x278);
              iVar15 = *(int *)((int)local_914 + 0x620);
              *(char **)((int)local_978 + iVar2 + iVar18) = "parse_notify";
              uVar3 = local_930;
              *(undefined4 *)((int)local_978 + iVar2 + iVar18 + 4) = 0x7fd;
              _cg_memcpy(iVar11 + iVar19 + uVar3 + iVar15,iVar17,uVar16,"util.c");
              if (opt_debug != '\0') {
                __ptr = (void *)bin2hex(*(undefined4 *)((int)local_914 + 0x620),
                                        *(undefined4 *)((int)local_914 + 0x624));
                pbVar14 = local_914;
                if ((opt_debug != '\0') &&
                   (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
                  *(void **)((int)local_978 + iVar2 + iVar18) = __ptr;
                  snprintf((char *)&local_828,0x800,"Pool %d coinbase %s",*(undefined4 *)pbVar14);
                  _applog(7,&local_828,0);
                }
                free(__ptr);
              }
              goto LAB_000480dc;
            }
            if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 3))
            goto LAB_0004863c;
            pcVar13 = "Failed to convert cb2 to cb2_bin in parse_notify";
          }
          local_828 = *(undefined4 *)pcVar13;
          uStack_824 = *(undefined4 *)(pcVar13 + 4);
          uStack_820 = *(undefined4 *)(pcVar13 + 8);
          uStack_81c = *(undefined4 *)(pcVar13 + 0xc);
          local_818 = *(undefined4 *)(pcVar13 + 0x10);
          uStack_814 = *(undefined4 *)(pcVar13 + 0x14);
          uStack_810 = *(undefined4 *)(pcVar13 + 0x18);
          uStack_80c = *(undefined4 *)(pcVar13 + 0x1c);
          local_808 = *(undefined4 *)(pcVar13 + 0x20);
          uStack_804 = *(undefined4 *)(pcVar13 + 0x24);
          uStack_800 = *(undefined4 *)(pcVar13 + 0x28);
          uStack_7fc = *(undefined4 *)(pcVar13 + 0x2c);
          local_7f8 = CONCAT31(local_7f8._1_3_,(char)*(undefined4 *)(pcVar13 + 0x30));
          _applog(3,&local_828,0);
        }
      }
      else {
        local_934 = (char *)0xbab8;
        iVar7 = 0;
        local_978[0] = (char *)0x7bb;
        uVar10 = _cgrealloc(*(undefined4 *)((int)pbVar14 + 0x2a4),local_920 * 4 + 1,"util.c",
                            "parse_notify");
        pbVar14 = local_914;
        local_95c = "util.c";
        local_960 = &opt_debug;
        *(undefined4 *)((int)local_914 + 0x2a4) = uVar10;
        local_934 = (char *)((uint)local_934 & 0xffff | 0x800000);
        local_914 = pbVar6;
        do {
          local_958 = iVar7 << 2;
          if (local_920 <= iVar7) {
            *(int *)((int)pbVar14 + 0x6ac) = local_920;
            pbVar6 = local_914;
            local_914 = pbVar14;
            if (1 < local_920) goto LAB_00047f7e;
            goto LAB_00047f6e;
          }
          pcVar13 = (char *)json_array_string(piVar5,iVar7);
          iVar18 = *(int *)((int)pbVar14 + 0x2a4);
          uVar10 = _cgmalloc(0x20,local_95c,"parse_notify",0x7c0);
          cVar1 = *local_934;
          *(undefined4 *)(iVar18 + iVar7 * 4) = uVar10;
          if (((cVar1 != '\0') && (*local_960 != '\0')) &&
             ((use_syslog != '\0' || ((opt_log_output != '\0' || (6 < opt_log_level)))))) {
            local_978[0] = pcVar13;
            snprintf((char *)&local_828,0x800,"merkle %d: %s",iVar7);
            _applog(7,&local_828,0);
          }
          iVar7 = iVar7 + 1;
          iVar18 = hex2bin(*(undefined4 *)(*(int *)((int)pbVar14 + 0x2a4) + local_958),pcVar13,0x20)
          ;
          free(pcVar13);
        } while (iVar18 != 0);
        pbVar6 = local_914;
        if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 3))
        goto LAB_0004863c;
        pcVar13 = "Failed to convert merkle to merkle_bin in parse_notify";
        local_914 = pbVar14;
LAB_0004864e:
        iVar7 = 0;
        local_828 = *(undefined4 *)pcVar13;
        uStack_824 = *(undefined4 *)(pcVar13 + 4);
        uStack_820 = *(undefined4 *)(pcVar13 + 8);
        uStack_81c = *(undefined4 *)(pcVar13 + 0xc);
        local_818 = *(undefined4 *)(pcVar13 + 0x10);
        uStack_814 = *(undefined4 *)(pcVar13 + 0x14);
        uStack_810 = *(undefined4 *)(pcVar13 + 0x18);
        uStack_80c = *(undefined4 *)(pcVar13 + 0x1c);
        local_808 = *(undefined4 *)(pcVar13 + 0x20);
        uStack_804 = *(undefined4 *)(pcVar13 + 0x24);
        uStack_800 = *(undefined4 *)(pcVar13 + 0x28);
        uStack_7fc = *(undefined4 *)(pcVar13 + 0x2c);
        local_7f8 = *(undefined4 *)(pcVar13 + 0x30);
        uStack_7f4 = (undefined2)*(undefined4 *)(pcVar13 + 0x34);
        local_7f2 = (undefined1)((uint)*(undefined4 *)(pcVar13 + 0x34) >> 0x10);
        _applog(3,&local_828,0);
      }
LAB_000480dc:
      _rw_unlock_constprop_14(local_954,"parse_notify",0x806);
      _mutex_unlock_noyield_constprop_15(local_93c,"parse_notify",0x806);
      (*selective_yield)();
      if (*local_934 == '\0') goto LAB_00048352;
      if (opt_debug == '\0') {
LAB_00048244:
        if (opt_debug == '\0') goto LAB_00048352;
        if (use_syslog != '\0') {
LAB_00048272:
          snprintf((char *)&local_828,0x800,"bbversion: %s",local_91c);
          _applog(7,&local_828,0);
          goto LAB_00048294;
        }
LAB_00048260:
        if ((opt_log_output != '\0') || (6 < opt_log_level)) goto LAB_00048272;
LAB_000482a6:
        if ((opt_log_output != '\0') || (6 < opt_log_level)) {
LAB_000482bc:
          snprintf((char *)&local_828,0x800,"nbit: %s",local_924);
          _applog(7,&local_828,0);
LAB_000482da:
          if (opt_debug == '\0') goto LAB_00048352;
          if (use_syslog == '\0') goto LAB_000482f0;
LAB_00048466:
          snprintf((char *)&local_828,0x800,"ntime: %s",local_928);
          _applog(7,&local_828,0);
          goto LAB_00048484;
        }
LAB_000482f0:
        if ((opt_log_output != '\0') || (6 < opt_log_level)) goto LAB_00048466;
LAB_00048308:
        if ((opt_log_output == '\0') && (opt_log_level < 7)) goto LAB_00048352;
      }
      else {
        if (((use_syslog != '\0') || (opt_log_output != '\0')) || (6 < opt_log_level)) {
          snprintf((char *)&local_828,0x800,"job_id: %s",pbVar6);
          _applog(7,&local_828,0);
          if (opt_debug != '\0') {
            if (use_syslog == '\0') goto LAB_00048180;
            goto LAB_00048196;
          }
LAB_00048294:
          if (opt_debug == '\0') goto LAB_00048352;
          if (use_syslog == '\0') goto LAB_000482a6;
          goto LAB_000482bc;
        }
LAB_00048180:
        if ((opt_log_output != '\0') || (6 < opt_log_level)) {
LAB_00048196:
          snprintf((char *)&local_828,0x800,"prev_hash: %s",local_918);
          _applog(7,&local_828,0);
          if (opt_debug != '\0') {
            if (use_syslog == '\0') goto LAB_000481c8;
            goto LAB_000481de;
          }
          goto LAB_000482da;
        }
LAB_000481c8:
        if ((opt_log_output == '\0') && (opt_log_level < 7)) {
LAB_00048210:
          if ((opt_log_output != '\0') || (6 < opt_log_level)) {
LAB_00048226:
            snprintf((char *)&local_828,0x800,"coinbase2: %s",__s_00);
            _applog(7,&local_828,0);
            goto LAB_00048244;
          }
          goto LAB_00048260;
        }
LAB_000481de:
        snprintf((char *)&local_828,0x800,"coinbase1: %s",__s);
        _applog(7,&local_828,0);
        if (opt_debug != '\0') {
          if (use_syslog == '\0') goto LAB_00048210;
          goto LAB_00048226;
        }
LAB_00048484:
        if (opt_debug == '\0') goto LAB_00048352;
        if (use_syslog == '\0') goto LAB_00048308;
      }
      puVar12 = (undefined4 *)&DAT_000674b4;
      if (local_92c == 0) {
        puVar12 = &DAT_000584ec;
      }
      snprintf((char *)&local_828,0x800,"clean: %s",puVar12);
      _applog(7,&local_828,0);
LAB_00048352:
      free(__s);
      free(__s_00);
      pbVar6 = local_914;
      bVar20 = 0xfffffffe < (uint)total_getworks;
      total_getworks._0_4_ = (uint)total_getworks + 1;
      total_getworks._4_4_ = total_getworks._4_4_ + (uint)bVar20;
      *(int *)((int)local_914 + 0x74) = *(int *)((int)local_914 + 0x74) + 1;
      puVar12 = (undefined4 *)current_pool();
      if (pbVar6 == (byte *)puVar12) {
        opt_work_update = 1;
      }
      return iVar7;
    }
    if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 3))
    goto LAB_00047db2;
    pcVar13 = "Zero length string passed to valid_ascii from";
  }
  local_978[2] = (char *)0x79b;
  local_978[1] = "parse_notify";
  local_978[0] = "util.c";
  snprintf((char *)&local_828,0x800,pcVar13," in %s %s():%d");
  _applog(3,&local_828,0);
LAB_00047db2:
  free(pbVar6);
  free(__s);
  free(__s_00);
  return 0;
}

