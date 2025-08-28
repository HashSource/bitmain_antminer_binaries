
undefined4 config_asicboost(int param_1)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  int iVar4;
  size_t sVar5;
  void *__ptr;
  int *piVar6;
  int *piVar7;
  char *pcVar8;
  char *pcVar9;
  int iVar10;
  char *pcVar11;
  uint uVar12;
  undefined4 uVar13;
  uint uVar14;
  undefined4 local_2920;
  undefined4 local_291c;
  undefined1 local_2918;
  undefined4 local_2914 [23];
  undefined1 auStack_28b8 [160];
  char local_2818 [36];
  uint local_27f4;
  char acStack_27f0 [8];
  undefined2 uStack_27e8;
  undefined1 local_27e6;
  char acStack_2018 [8196];
  
  local_291c = 0;
  local_2920 = 0x30;
  local_2918 = 0;
  iVar4 = setup_stratum_socket();
  if (iVar4 == 0) {
    return 0;
  }
  clear_sock(param_1);
  iVar4 = swork_id;
  swork_id = swork_id + 1;
  sprintf(acStack_2018,
          "{\"id\":%d, \"method\":\"mining.configure\", \"params\":[[\"version-rolling\"],{\"version-rolling.mask\":\"ffffffff\",\"version-rolling.min-bit-count\":%d}]}"
          ,iVar4,2);
  sVar5 = strlen(acStack_2018);
  iVar4 = __stratum_send(param_1,acStack_2018,sVar5);
  if (iVar4 != 0) {
    if (opt_debug == '\0') {
      return 0;
    }
    if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 7)) {
      return 0;
    }
    builtin_strncpy(local_2818,"Failed to send s in initiate_stratum",0x24);
    local_27f4 = local_27f4 & 0xffffff00;
    _applog(7,local_2818,0);
    return 0;
  }
  iVar4 = socket_full_isra_2(*(undefined4 *)(param_1 + 0x24c),0x3c);
  if (iVar4 == 0) {
    if (opt_debug == '\0') {
      return 0;
    }
    if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 7)) {
      return 0;
    }
    builtin_strncpy(local_2818,"Timed out waiting for response in in",0x24);
    local_27f4._0_1_ = 'i';
    local_27f4._1_1_ = 't';
    local_27f4._2_1_ = 'i';
    local_27f4._3_1_ = 'a';
    builtin_strncpy(acStack_27f0,"te_strat",8);
    uStack_27e8 = 0x6d75;
    local_27e6 = 0;
    _applog(7,local_2818,0);
    return 0;
  }
  __ptr = (void *)recv_line(param_1);
  if (__ptr == (void *)0x0) {
    return 0;
  }
  iVar4 = json_loads(__ptr,0,local_2914);
  free(__ptr);
  if (iVar4 == 0) {
    if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 6)) {
      return 0;
    }
    snprintf(local_2818,0x800,"JSON decode failed(%d): %s",local_2914[0],auStack_28b8);
    _applog(6,local_2818,0);
    return 0;
  }
  piVar6 = (int *)json_object_get(iVar4,"result");
  piVar7 = (int *)json_object_get(iVar4,"error");
  if ((piVar6 == (int *)0x0) || (*piVar6 == 7)) {
    if (piVar7 != (int *)0x0) goto LAB_00049426;
    pcVar8 = (char *)malloc(0x11);
    if (pcVar8 != (char *)0x0) {
      builtin_strncpy(pcVar8,"(unknown reason)",0x11);
    }
  }
  else {
    if ((piVar7 == (int *)0x0) || (*piVar7 == 7)) {
      json_object_get(piVar6,"version-rolling.mask");
      pcVar8 = (char *)json_string_value();
      sVar5 = strlen(pcVar8);
      if (0 < (int)sVar5) {
        pcVar9 = (char *)((int)&local_291c + (3 - sVar5));
        pcVar11 = pcVar8 + -1;
        do {
          pcVar11 = pcVar11 + 1;
          pcVar9 = pcVar9 + 1;
          *pcVar9 = *pcVar11;
        } while (pcVar11 != pcVar8 + (sVar5 - 1));
      }
      uVar14 = 0;
      local_2918 = 0;
      hex2bin(param_1 + 0x28c,&local_2920,4);
      bVar3 = false;
      uVar12 = 0;
      do {
        uVar2 = uVar12 & 0xff;
        uVar1 = uVar12 & 0xff;
        uVar12 = uVar12 + 1;
        if ((*(uint *)(param_1 + 0x28c) >> uVar2 & 1) != 0) {
          uVar14 = uVar14 | 1 << uVar1;
          if (bVar3) break;
          bVar3 = true;
        }
      } while (uVar12 != 0x20);
      uVar13 = 1;
      *(uint *)(param_1 + 0x28c) = uVar14;
      opt_multi_version = 1;
      *(undefined4 *)(param_1 + 0x288) = 4;
      goto LAB_00049494;
    }
LAB_00049426:
    pcVar8 = (char *)json_dumps(piVar7,3);
  }
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (4 < opt_log_level)) {
    snprintf(local_2818,0x800,"JSON-RPC decode failed: %s",pcVar8);
    _applog(5,local_2818,0);
  }
  uVar13 = 0;
  free(pcVar8);
  opt_multi_version = 1;
  *(undefined4 *)(param_1 + 0x28c) = 0xc000;
  *(undefined4 *)(param_1 + 0x288) = 4;
LAB_00049494:
  if (*(int *)(iVar4 + 4) == -1) {
    return uVar13;
  }
  iVar10 = *(int *)(iVar4 + 4) + -1;
  *(int *)(iVar4 + 4) = iVar10;
  if (iVar10 == 0) {
    json_delete(iVar4);
    return uVar13;
  }
  return uVar13;
}

