
int parse_notify(undefined4 *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  byte *pbVar5;
  char *__s;
  char *__s_00;
  int iVar6;
  int *piVar7;
  size_t sVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 *puVar11;
  void *__ptr;
  undefined4 uVar12;
  char *pcVar13;
  byte *pbVar14;
  undefined4 *puVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  bool bVar21;
  double dVar22;
  char *local_978 [5];
  undefined4 local_964;
  char *local_960;
  char *local_95c;
  int local_958;
  undefined4 *local_954;
  int local_950;
  undefined4 *local_94c;
  undefined4 *local_948;
  undefined4 *local_944;
  undefined4 *local_940;
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
  undefined4 *local_914;
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
  undefined local_7f2;
  
  local_914 = param_1;
  piVar4 = (int *)json_array_get(param_2,4);
  if (piVar4 == (int *)0x0) {
    return 0;
  }
  if (*piVar4 != 1) {
    return 0;
  }
  local_920 = json_array_size();
  pbVar5 = (byte *)json_array_string(param_2,0);
  local_918 = __json_array_string(param_2,1);
  __s = (char *)json_array_string(param_2,2);
  __s_00 = (char *)json_array_string(param_2,3);
  local_91c = __json_array_string(param_2,5);
  local_924 = __json_array_string(param_2,6);
  local_928 = __json_array_string(param_2,7);
  iVar6 = json_array_get(param_2,8);
  if (iVar6 == 0) {
    uVar17 = 0;
  }
  else {
    piVar7 = (int *)json_array_get(param_2,8);
    uVar17 = (uint)(*piVar7 == 5);
  }
  local_92c = uVar17;
  if (pbVar5 == (byte *)0x0) {
    if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 3))
    goto LAB_00047db2;
    pcVar13 = "Null string passed to valid_ascii from";
  }
  else {
    sVar8 = strlen((char *)pbVar5);
    if (sVar8 != 0) {
      if (0 < (int)sVar8) {
        pcVar13 = (char *)(uint)*pbVar5;
        if (pcVar13 + -0x20 < (char *)0x5f) {
          pbVar14 = pbVar5;
          do {
            pbVar14 = pbVar14 + 1;
            if (pbVar14 == pbVar5 + sVar8) goto LAB_00047dda;
            pcVar13 = (char *)(uint)*pbVar14;
          } while (pcVar13 + -0x20 < (char *)0x5f);
        }
        if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
          local_978[1] = "util.c";
          local_978[2] = (char *)DAT_00047dd4;
          local_978[3] = (char *)0x79b;
          local_978[0] = pcVar13;
          snprintf((char *)&local_828,0x800,"Invalid char 0x%x passed to valid_ascii from",
                   " in %s %s():%d");
          _applog(3,&local_828,0);
        }
        goto LAB_00047db2;
      }
LAB_00047dda:
      iVar6 = _valid_hex_constprop_10(local_918,DAT_000480f8,0x79b);
      if (((iVar6 == 0) || (iVar6 = _valid_hex_constprop_10(__s,DAT_000480f8,0x79b), iVar6 == 0)) ||
         ((iVar6 = _valid_hex_constprop_10(__s_00,DAT_000480f8,0x79c), iVar6 == 0 ||
          (((iVar6 = _valid_hex_constprop_10(local_91c,DAT_000480f8,0x79c), iVar6 == 0 ||
            (iVar6 = _valid_hex_constprop_10(local_924,DAT_000480f8,0x79c), iVar6 == 0)) ||
           (iVar6 = _valid_hex_constprop_10(local_928,DAT_000480f8,0x79d), iVar6 == 0))))))
      goto LAB_00047db2;
      local_93c = (pthread_mutex_t *)(local_914 + 0x35);
      iVar6 = pthread_mutex_lock(local_93c);
      if (iVar6 != 0) {
        _mutex_lock_part_1_constprop_16(DAT_000486d4,0x7a6);
      }
      puVar15 = local_914;
      local_954 = local_914 + 0x3b;
      _wr_lock_constprop_12(local_954,DAT_000480f8,0x7a6);
      local_940 = puVar15 + 0x1ac;
      local_914 = puVar15;
      free((void *)puVar15[0xa8]);
      local_914[0xa8] = pbVar5;
      snprintf((char *)(puVar15 + 0x1ac),0x41,"%s",local_918);
      sVar8 = strlen(__s);
      local_930 = sVar8 >> 1;
      puVar15 = local_914 + 0x1bd;
      local_944 = puVar15;
      sVar8 = strlen(__s_00);
      local_938 = sVar8 >> 1;
      puVar11 = local_914 + 0x1c0;
      local_948 = puVar11;
      snprintf((char *)puVar15,9,"%s",local_91c);
      puVar15 = local_914 + 0x1c3;
      local_94c = puVar15;
      snprintf((char *)puVar11,9,"%s",local_924);
      snprintf((char *)puVar15,9,"%s",local_928);
      puVar15 = local_914;
      *(char *)(local_914 + 0xaa) = (char)uVar17;
      dVar22 = *(double *)(local_914 + 0x1c6);
      if (dVar22 != 0.0 && dVar22 < 0.0 == NAN(dVar22)) {
        *(double *)(local_914 + 0x1c8) = dVar22;
      }
      local_914[0x18a] = local_914[0x187] + local_930;
      local_950 = local_914[0x187] + local_930 + local_914[0x9e] + local_938;
      local_914[0x189] = local_950;
      if (0 < (int)local_914[0x1ab]) {
        iVar6 = 0;
        do {
          iVar19 = iVar6 * 4;
          iVar6 = iVar6 + 1;
          free(*(void **)(puVar15[0xa9] + iVar19));
        } while (iVar6 < (int)puVar15[0x1ab]);
      }
      local_914 = puVar15;
      if (local_920 == 0) {
        local_934 = &opt_protocol;
        puVar15[0x1ab] = 0;
LAB_00047f6e:
        uVar17 = local_914[0x5e];
        local_914[0x5e] = uVar17 + 1;
        local_914[0x5f] = local_914[0x5f] + (uint)(0xfffffffe < uVar17);
LAB_00047f7e:
        if (local_92c != 0) {
          local_914[0x9c] = 0;
          local_914[0x9d] = 0;
        }
        local_978[3] = (char *)local_948;
        local_978[1] = "0000000000000000000000000000000000000000000000000000000000000000";
        local_964 = workpadding;
        local_978[2] = (char *)local_94c;
        local_978[4] = "00000000";
        local_978[0] = (char *)local_940;
        snprintf(acStack_90c,0xe1,"%s%s%s%s%s%s%s",local_944);
        iVar6 = hex2bin(local_914 + 0x18b,acStack_90c,0x70);
        if (iVar6 == 0) {
          if (((use_syslog != '\0') || (opt_log_output != '\0')) ||
             (puVar15 = local_914, 2 < opt_log_level)) {
            pcVar13 = "Failed to convert header to header_bin in parse_notify";
            goto LAB_0004864e;
          }
LAB_0004863c:
          local_914 = puVar15;
          iVar6 = 0;
        }
        else {
          iVar19 = -(local_930 + 0xe & 0xfffffff8);
          iVar6 = hex2bin((int)&local_960 + iVar19,__s);
          if (iVar6 == 0) {
            if (((use_syslog == '\0') && (opt_log_output == '\0')) &&
               (puVar15 = local_914, opt_log_level < 3)) goto LAB_0004863c;
            pcVar13 = "Failed to convert cb1 to cb1_bin in parse_notify";
            iVar6 = 0;
          }
          else {
            iVar2 = -(local_938 + 0xe & 0xfffffff8);
            iVar18 = (int)&local_960 + iVar2 + iVar19;
            iVar6 = hex2bin(iVar18,__s_00);
            puVar15 = local_914;
            if (iVar6 != 0) {
              free((void *)local_914[0x188]);
              *(undefined4 *)((int)local_978 + iVar2 + iVar19) = 0x7f9;
              uVar9 = _cgcalloc(local_950,1,"util.c",DAT_000480f8);
              uVar12 = DAT_000480f8;
              puVar15[0x188] = uVar9;
              *(undefined4 *)((int)local_978 + iVar2 + iVar19 + 4) = 0x7fa;
              *(undefined4 *)((int)local_978 + iVar2 + iVar19) = uVar12;
              _cg_memcpy(uVar9,(int)&local_960 + iVar19,local_930,"util.c");
              puVar11 = local_914;
              iVar20 = puVar15[0x187];
              if (iVar20 != 0) {
                iVar10 = local_914[0x188];
                *(undefined4 *)((int)local_978 + iVar2 + iVar19 + 4) = 0x7fc;
                uVar17 = local_930;
                *(undefined4 *)((int)local_978 + iVar2 + iVar19) = DAT_000480f8;
                _cg_memcpy(iVar10 + uVar17,puVar11[0x9a],iVar20,"util.c");
                iVar20 = puVar11[0x187];
              }
              uVar17 = local_938;
              iVar10 = local_914[0x9e];
              iVar16 = local_914[0x188];
              *(undefined4 *)((int)local_978 + iVar2 + iVar19) = DAT_000480f8;
              uVar3 = local_930;
              *(undefined4 *)((int)local_978 + iVar2 + iVar19 + 4) = 0x7fd;
              _cg_memcpy(iVar10 + iVar20 + uVar3 + iVar16,iVar18,uVar17,"util.c");
              if (opt_debug != '\0') {
                __ptr = (void *)bin2hex(local_914[0x188],local_914[0x189]);
                puVar15 = local_914;
                if ((opt_debug != '\0') &&
                   (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
                  *(void **)((int)local_978 + iVar2 + iVar19) = __ptr;
                  snprintf((char *)&local_828,0x800,"Pool %d coinbase %s",*puVar15);
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
          uStack_824 = *(undefined4 *)((int)pcVar13 + 4);
          uStack_820 = *(undefined4 *)((int)pcVar13 + 8);
          uStack_81c = *(undefined4 *)((int)pcVar13 + 0xc);
          local_818 = *(undefined4 *)((int)pcVar13 + 0x10);
          uStack_814 = *(undefined4 *)((int)pcVar13 + 0x14);
          uStack_810 = *(undefined4 *)((int)pcVar13 + 0x18);
          uStack_80c = *(undefined4 *)((int)pcVar13 + 0x1c);
          local_808 = *(undefined4 *)((int)pcVar13 + 0x20);
          uStack_804 = *(undefined4 *)((int)pcVar13 + 0x24);
          uStack_800 = *(undefined4 *)((int)pcVar13 + 0x28);
          uStack_7fc = *(undefined4 *)((int)pcVar13 + 0x2c);
          local_7f8 = CONCAT31(local_7f8._1_3_,(char)*(undefined4 *)((int)pcVar13 + 0x30));
          _applog(3,&local_828,0);
        }
      }
      else {
        local_934 = (char *)0xbab8;
        iVar6 = 0;
        local_978[0] = (char *)0x7bb;
        uVar12 = _cgrealloc(puVar15[0xa9],local_920 * 4 + 1,"util.c",DAT_000486d4);
        puVar15 = local_914;
        local_95c = "util.c";
        local_960 = &opt_debug;
        local_914[0xa9] = uVar12;
        local_934 = (char *)((uint)local_934 & 0xffff | 0x800000);
        local_914 = (undefined4 *)pbVar5;
        do {
          local_958 = iVar6 << 2;
          if (local_920 <= iVar6) {
            puVar15[0x1ab] = local_920;
            pbVar5 = (byte *)local_914;
            local_914 = puVar15;
            if (1 < local_920) goto LAB_00047f7e;
            goto LAB_00047f6e;
          }
          puVar11 = (undefined4 *)json_array_string(piVar4,iVar6);
          iVar19 = puVar15[0xa9];
          uVar12 = _cgmalloc(0x20,local_95c,DAT_000486d4,0x7c0);
          cVar1 = *local_934;
          *(undefined4 *)(iVar19 + iVar6 * 4) = uVar12;
          if (((cVar1 != '\0') && (*local_960 != '\0')) &&
             ((use_syslog != '\0' || ((opt_log_output != '\0' || (6 < opt_log_level)))))) {
            local_978[0] = (char *)puVar11;
            snprintf((char *)&local_828,0x800,"merkle %d: %s",iVar6);
            _applog(7,&local_828,0);
          }
          iVar6 = iVar6 + 1;
          iVar19 = hex2bin(*(undefined4 *)(puVar15[0xa9] + local_958),puVar11,0x20);
          free(puVar11);
        } while (iVar19 != 0);
        pbVar5 = (byte *)local_914;
        if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 3))
        goto LAB_0004863c;
        pcVar13 = "Failed to convert merkle to merkle_bin in parse_notify";
        local_914 = puVar15;
LAB_0004864e:
        iVar6 = 0;
        local_828 = *(undefined4 *)pcVar13;
        uStack_824 = *(undefined4 *)((int)pcVar13 + 4);
        uStack_820 = *(undefined4 *)((int)pcVar13 + 8);
        uStack_81c = *(undefined4 *)((int)pcVar13 + 0xc);
        local_818 = *(undefined4 *)((int)pcVar13 + 0x10);
        uStack_814 = *(undefined4 *)((int)pcVar13 + 0x14);
        uStack_810 = *(undefined4 *)((int)pcVar13 + 0x18);
        uStack_80c = *(undefined4 *)((int)pcVar13 + 0x1c);
        local_808 = *(undefined4 *)((int)pcVar13 + 0x20);
        uStack_804 = *(undefined4 *)((int)pcVar13 + 0x24);
        uStack_800 = *(undefined4 *)((int)pcVar13 + 0x28);
        uStack_7fc = *(undefined4 *)((int)pcVar13 + 0x2c);
        local_7f8 = *(undefined4 *)((int)pcVar13 + 0x30);
        uStack_7f4 = (undefined2)*(undefined4 *)((int)pcVar13 + 0x34);
        local_7f2 = (undefined)((uint)*(undefined4 *)((int)pcVar13 + 0x34) >> 0x10);
        _applog(3,&local_828,0);
      }
LAB_000480dc:
      _rw_unlock_constprop_14(local_954,DAT_000480f8,0x806);
      _mutex_unlock_noyield_constprop_15(local_93c,DAT_000480f8,0x806);
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
          snprintf((char *)&local_828,0x800,"job_id: %s",pbVar5);
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
      puVar15 = (undefined4 *)&DAT_000674b4;
      if (local_92c == 0) {
        puVar15 = &DAT_000584ec;
      }
      snprintf((char *)&local_828,0x800,"clean: %s",puVar15);
      _applog(7,&local_828,0);
LAB_00048352:
      free(__s);
      free(__s_00);
      puVar15 = local_914;
      bVar21 = 0xfffffffe < (uint)total_getworks;
      total_getworks._0_4_ = (uint)total_getworks + 1;
      total_getworks._4_4_ = total_getworks._4_4_ + (uint)bVar21;
      local_914[0x1d] = local_914[0x1d] + 1;
      puVar11 = (undefined4 *)current_pool();
      if (puVar15 == puVar11) {
        opt_work_update = 1;
      }
      return iVar6;
    }
    if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 3))
    goto LAB_00047db2;
    pcVar13 = "Zero length string passed to valid_ascii from";
  }
  local_978[2] = (char *)0x79b;
  local_978[0] = "util.c";
  local_978[1] = DAT_000486d4;
  snprintf((char *)&local_828,0x800,pcVar13," in %s %s():%d");
  _applog(3,&local_828,0);
LAB_00047db2:
  free(pbVar5);
  free(__s);
  free(__s_00);
  return 0;
}

