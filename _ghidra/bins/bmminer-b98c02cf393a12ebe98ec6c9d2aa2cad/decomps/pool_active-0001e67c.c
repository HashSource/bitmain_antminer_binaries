
uint pool_active(undefined4 *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  size_t __n;
  char cVar3;
  char *pcVar4;
  uint uVar5;
  undefined1 auStack_828 [8];
  undefined1 auStack_820 [8];
  undefined4 local_818;
  undefined4 uStack_814;
  undefined4 uStack_810;
  undefined4 uStack_80c;
  undefined4 local_808;
  undefined4 uStack_804;
  undefined4 uStack_800;
  undefined4 uStack_7fc;
  char local_7f8 [28];
  undefined2 uStack_7dc;
  undefined1 local_7da;
  
  if (*(char *)(param_1 + 0xb8) == '\0') {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (5 < opt_log_level)) {
      snprintf((char *)&local_818,0x800,"Testing pool %s",param_1[0x29]);
      _applog(6,&local_818,0);
    }
  }
  else if ((opt_debug != '\0') &&
          (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
    snprintf((char *)&local_818,0x800,"Retrieving block template from pool %s",param_1[0x29]);
    _applog(7,&local_818,0);
  }
  cVar3 = opt_debug;
  if (*(char *)(param_1 + 0xa0) == '\0') {
    uVar5 = 0;
    if (curly == 0) {
      if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 3)) {
        return 0;
      }
      local_818._0_1_ = 'C';
      local_818._1_1_ = 'U';
      local_818._2_1_ = 'R';
      local_818._3_1_ = 'L';
      uStack_814._0_1_ = ' ';
      uStack_814._1_1_ = 'i';
      uStack_814._2_1_ = 'n';
      uStack_814._3_1_ = 'i';
      uStack_810._0_1_ = 't';
      uStack_810._1_1_ = 'i';
      uStack_810._2_1_ = 'a';
      uStack_810._3_1_ = 'l';
      uStack_80c._0_1_ = 'i';
      uStack_80c._1_1_ = 's';
      uStack_80c._2_1_ = 'a';
      uStack_80c._3_1_ = 't';
      local_808._0_1_ = 'i';
      local_808._1_1_ = 'o';
      local_808._2_1_ = 'n';
      local_808._3_1_ = ' ';
      uStack_804._0_1_ = 'f';
      uStack_804._1_1_ = 'a';
      uStack_804._2_1_ = 'i';
      uStack_804._3_1_ = 'l';
      uStack_800 = CONCAT13(uStack_800._3_1_,0x6465);
      _applog(3,&local_818,0);
      return 0;
    }
    if (*(char *)((int)param_1 + 99) == '\0') {
      if (opt_debug == '\0') {
        *(undefined1 *)((int)param_1 + 99) = 0;
      }
      else if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 7)) {
        *(undefined1 *)((int)param_1 + 99) = 0;
        if (*(char *)(param_1 + 0xb8) == '\0') {
          if (*(char *)(param_1 + 0xe1) == '\0') {
LAB_0001e9de:
            if ((cVar3 == '\0') ||
               (((use_syslog == '\0' && (opt_log_output == '\0')) && (opt_log_level < 7))))
            goto LAB_0001e786;
            pcVar4 = "No GBT coinbase + append support found, pool unusable if it has no stratum";
            __n = 0x4b;
          }
          else {
LAB_0001e958:
            if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 7))
            goto LAB_0001e786;
            pcVar4 = "GBT coinbase without append found, switching to GBT solo protocol";
            __n = 0x42;
          }
          memcpy(&local_818,pcVar4,__n);
          _applog(7,&local_818,0);
        }
        else {
LAB_0001e730:
          if (((use_syslog != '\0') || (opt_log_output != '\0')) || (6 < opt_log_level)) {
            local_818._0_1_ = 'G';
            local_818._1_1_ = 'B';
            local_818._2_1_ = 'T';
            local_818._3_1_ = ' ';
            uStack_814._0_1_ = 'c';
            uStack_814._1_1_ = 'o';
            uStack_814._2_1_ = 'i';
            uStack_814._3_1_ = 'n';
            uStack_810._0_1_ = 'b';
            uStack_810._1_1_ = 'a';
            uStack_810._2_1_ = 's';
            uStack_810._3_1_ = 'e';
            uStack_80c._0_1_ = ' ';
            uStack_80c._1_1_ = '+';
            uStack_80c._2_1_ = ' ';
            uStack_80c._3_1_ = 'a';
            local_808._0_1_ = 'p';
            local_808._1_1_ = 'p';
            local_808._2_1_ = 'e';
            local_808._3_1_ = 'n';
            uStack_804._0_1_ = 'd';
            uStack_804._1_1_ = ' ';
            uStack_804._2_1_ = 's';
            uStack_804._3_1_ = 'u';
            uStack_800._0_1_ = 'p';
            uStack_800._1_1_ = 'p';
            uStack_800._2_1_ = 'o';
            uStack_800._3_1_ = 'r';
            uStack_7fc._0_1_ = 't';
            uStack_7fc._1_1_ = ' ';
            uStack_7fc._2_1_ = 'f';
            uStack_7fc._3_1_ = 'o';
            builtin_strncpy(local_7f8,"und, switching to GBT protoc",0x1c);
            uStack_7dc = 0x6c6f;
            local_7da = 0;
            _applog(7,&local_818,0);
          }
        }
      }
      else {
        local_818._0_1_ = 'P';
        local_818._1_1_ = 'r';
        local_818._2_1_ = 'o';
        local_818._3_1_ = 'b';
        uStack_814._0_1_ = 'i';
        uStack_814._1_1_ = 'n';
        uStack_814._2_1_ = 'g';
        uStack_814._3_1_ = ' ';
        uStack_810._0_1_ = 'f';
        uStack_810._1_1_ = 'o';
        uStack_810._2_1_ = 'r';
        uStack_810._3_1_ = ' ';
        uStack_80c._0_1_ = 'G';
        uStack_80c._1_1_ = 'B';
        uStack_80c._2_1_ = 'T';
        uStack_80c._3_1_ = ' ';
        local_808._0_1_ = 's';
        local_808._1_1_ = 'u';
        local_808._2_1_ = 'p';
        local_808._3_1_ = 'p';
        uStack_804._0_1_ = 'o';
        uStack_804._1_1_ = 'r';
        uStack_804._2_1_ = 't';
        uStack_804._3_1_ = '\0';
        _applog(7,&local_818,0);
        cVar3 = opt_debug;
        *(undefined1 *)((int)param_1 + 99) = 0;
        if (*(char *)(param_1 + 0xb8) == '\0') {
          if (*(char *)(param_1 + 0xe1) == '\0') goto LAB_0001e9de;
          if (cVar3 != '\0') goto LAB_0001e958;
        }
        else if (cVar3 != '\0') goto LAB_0001e730;
      }
    }
LAB_0001e786:
    cgtime(auStack_828);
    cgtime(auStack_820);
    iVar1 = param_1[0x90];
    if ((iVar1 != 0) && (opt_fix_protocol == '\0')) {
      if ((use_syslog != '\0') || ((opt_log_output != '\0' || (5 < opt_log_level)))) {
        snprintf((char *)&local_818,0x800,"Testing pool %d stratum %s",*param_1,iVar1);
        _applog(6,&local_818,0);
        iVar1 = param_1[0x90];
      }
      iVar1 = extract_sockaddr(iVar1,param_1 + 0x96,param_1 + 0x92);
      if ((iVar1 != 0) && (iVar1 = initiate_stratum(param_1), iVar1 != 0)) {
        if ((use_syslog != '\0') || ((opt_log_output != '\0' || (4 < opt_log_level)))) {
          snprintf((char *)&local_818,0x800,"Switching pool %d %s to %s",*param_1,param_1[0x29],
                   param_1[0x90]);
          _applog(5,&local_818,0);
        }
        if (param_1[0x29] == 0) {
          uVar2 = __strdup(param_1[0x90]);
          param_1[0x29] = uVar2;
          *(undefined1 *)(param_1 + 0xa0) = 1;
        }
        else {
          *(undefined1 *)(param_1 + 0xa0) = 1;
        }
        goto LAB_0001e8d6;
      }
    }
    if (((*(char *)(param_1 + 0xa0) == '\0') && (*(char *)(param_1 + 0xe1) == '\0')) &&
       (*(char *)(param_1 + 0xb8) == '\0')) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (3 < opt_log_level)) {
        uVar5 = 0;
        snprintf((char *)&local_818,0x800,
                 "No Stratum, GBT or Solo support in pool %d %s unable to use",*param_1,
                 param_1[0x29]);
        _applog(4,&local_818,0);
      }
    }
    else {
      if ((opt_debug != '\0') &&
         (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
        snprintf((char *)&local_818,0x800,"FAILED to retrieve work from pool %u %s",*param_1,
                 param_1[0x29]);
        _applog(7,&local_818,0);
      }
      if (((param_2 == 0) && (*(char *)((int)param_1 + 0x61) == '\0')) &&
         ((use_syslog != '\0' || ((opt_log_output != '\0' || (3 < opt_log_level)))))) {
        snprintf((char *)&local_818,0x800,"Pool %u slow/down or URL or credentials invalid",*param_1
                );
        uVar5 = 0;
        _applog(4,&local_818);
      }
    }
  }
  else {
LAB_0001e8d6:
    iVar1 = pool_tset(param_1,(int)param_1 + 0x282);
    if (iVar1 == 0) {
      iVar1 = initiate_stratum(param_1);
      if ((iVar1 != 0) &&
         (((*(char *)(param_1 + 0x91) == '\0' || (iVar1 = subscribe_extranonce(param_1), iVar1 != 0)
           ) && (uVar5 = auth_stratum(param_1), uVar5 != 0)))) {
        have_longpoll = 1;
        iVar1 = pthread_create(param_1 + 0xae,(pthread_attr_t *)0x0,(__start_routine *)0x24111,
                               param_1);
        if (iVar1 == 0) {
          iVar1 = pthread_create(param_1 + 0xaf,(pthread_attr_t *)0x0,(__start_routine *)0x27599,
                                 param_1);
          if (iVar1 == 0) {
            return uVar5;
          }
          pcVar4 = "Failed to create stratum rthread";
        }
        else {
          pcVar4 = "Failed to create stratum sthread";
        }
        local_818 = *(undefined4 *)pcVar4;
        uStack_814 = *(undefined4 *)(pcVar4 + 4);
        uStack_810 = *(undefined4 *)(pcVar4 + 8);
        uStack_80c = *(undefined4 *)(pcVar4 + 0xc);
        local_808 = *(undefined4 *)(pcVar4 + 0x10);
        uStack_804 = *(undefined4 *)(pcVar4 + 0x14);
        uStack_800 = *(undefined4 *)(pcVar4 + 0x18);
        uStack_7fc = *(undefined4 *)(pcVar4 + 0x1c);
        local_7f8[0] = (char)*(undefined4 *)(pcVar4 + 0x20);
        _applog(3,&local_818,1);
                    /* WARNING: Subroutine does not return */
        __quit(1,1);
      }
      pool_tclear(param_1,(int)param_1 + 0x282);
      uVar5 = 0;
    }
    else {
      uVar5 = (uint)*(byte *)((int)param_1 + 0x281);
    }
  }
  return uVar5;
}

