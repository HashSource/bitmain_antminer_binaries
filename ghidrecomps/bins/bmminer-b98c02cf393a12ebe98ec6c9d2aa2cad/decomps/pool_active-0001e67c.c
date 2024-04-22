
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint pool_active(undefined4 *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  size_t __n;
  char cVar3;
  char *pcVar4;
  uint uVar5;
  undefined auStack_828 [8];
  undefined auStack_820 [8];
  undefined4 local_818;
  undefined4 uStack_814;
  undefined4 uStack_810;
  undefined4 uStack_80c;
  undefined4 local_808;
  undefined4 uStack_804;
  undefined4 uStack_800;
  undefined4 uStack_7fc;
  undefined4 local_7f8;
  undefined4 uStack_7f4;
  undefined4 uStack_7f0;
  undefined4 uStack_7ec;
  undefined4 local_7e8;
  undefined4 uStack_7e4;
  undefined4 uStack_7e0;
  undefined2 uStack_7dc;
  undefined local_7da;
  
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
      local_818._0_1_ = s_CURL_initialisation_failed_0005cbb0[0];
      local_818._1_1_ = s_CURL_initialisation_failed_0005cbb0[1];
      local_818._2_1_ = s_CURL_initialisation_failed_0005cbb0[2];
      local_818._3_1_ = s_CURL_initialisation_failed_0005cbb0[3];
      uStack_814._0_1_ = s_CURL_initialisation_failed_0005cbb0[4];
      uStack_814._1_1_ = s_CURL_initialisation_failed_0005cbb0[5];
      uStack_814._2_1_ = s_CURL_initialisation_failed_0005cbb0[6];
      uStack_814._3_1_ = s_CURL_initialisation_failed_0005cbb0[7];
      uStack_810._0_1_ = s_CURL_initialisation_failed_0005cbb0[8];
      uStack_810._1_1_ = s_CURL_initialisation_failed_0005cbb0[9];
      uStack_810._2_1_ = s_CURL_initialisation_failed_0005cbb0[10];
      uStack_810._3_1_ = s_CURL_initialisation_failed_0005cbb0[11];
      uStack_80c._0_1_ = s_CURL_initialisation_failed_0005cbb0[12];
      uStack_80c._1_1_ = s_CURL_initialisation_failed_0005cbb0[13];
      uStack_80c._2_1_ = s_CURL_initialisation_failed_0005cbb0[14];
      uStack_80c._3_1_ = s_CURL_initialisation_failed_0005cbb0[15];
      local_808._0_1_ = s_CURL_initialisation_failed_0005cbb0[16];
      local_808._1_1_ = s_CURL_initialisation_failed_0005cbb0[17];
      local_808._2_1_ = s_CURL_initialisation_failed_0005cbb0[18];
      local_808._3_1_ = s_CURL_initialisation_failed_0005cbb0[19];
      uStack_804._0_1_ = s_CURL_initialisation_failed_0005cbb0[20];
      uStack_804._1_1_ = s_CURL_initialisation_failed_0005cbb0[21];
      uStack_804._2_1_ = s_CURL_initialisation_failed_0005cbb0[22];
      uStack_804._3_1_ = s_CURL_initialisation_failed_0005cbb0[23];
      _applog(3,&local_818,0);
      return 0;
    }
    if (*(char *)((int)param_1 + 99) == '\0') {
      if (opt_debug == '\0') {
        *(undefined *)((int)param_1 + 99) = 0;
      }
      else if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 7)) {
        *(undefined *)((int)param_1 + 99) = 0;
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
            local_818._0_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[0];
            local_818._1_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[1];
            local_818._2_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[2];
            local_818._3_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[3];
            uStack_814._0_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[4];
            uStack_814._1_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[5];
            uStack_814._2_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[6];
            uStack_814._3_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[7];
            uStack_810._0_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[8];
            uStack_810._1_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[9];
            uStack_810._2_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[10];
            uStack_810._3_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[11];
            uStack_80c._0_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[12];
            uStack_80c._1_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[13];
            uStack_80c._2_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[14];
            uStack_80c._3_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[15];
            local_808._0_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[16];
            local_808._1_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[17];
            local_808._2_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[18];
            local_808._3_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[19];
            uStack_804._0_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[20];
            uStack_804._1_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[21];
            uStack_804._2_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[22];
            uStack_804._3_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[23];
            uStack_800._0_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[24];
            uStack_800._1_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[25];
            uStack_800._2_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[26];
            uStack_800._3_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[27];
            uStack_7fc._0_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[28];
            uStack_7fc._1_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[29];
            uStack_7fc._2_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[30];
            uStack_7fc._3_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[31];
            local_7f8._0_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[32];
            local_7f8._1_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[33];
            local_7f8._2_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[34];
            local_7f8._3_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[35];
            uStack_7f4._0_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[36];
            uStack_7f4._1_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[37];
            uStack_7f4._2_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[38];
            uStack_7f4._3_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[39];
            uStack_7f0._0_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[40];
            uStack_7f0._1_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[41];
            uStack_7f0._2_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[42];
            uStack_7f0._3_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[43];
            uStack_7ec._0_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[44];
            uStack_7ec._1_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[45];
            uStack_7ec._2_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[46];
            uStack_7ec._3_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[47];
            local_7e8._0_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[48];
            local_7e8._1_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[49];
            local_7e8._2_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[50];
            local_7e8._3_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[51];
            uStack_7e4._0_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[52];
            uStack_7e4._1_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[53];
            uStack_7e4._2_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[54];
            uStack_7e4._3_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[55];
            uStack_7e0._0_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[56];
            uStack_7e0._1_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[57];
            uStack_7e0._2_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[58];
            uStack_7e0._3_1_ = s_GBT_coinbase___append_support_fo_0005cbe4[59];
            uStack_7dc = (undefined2)ram0x0005cc20;
            local_7da = (undefined)((uint)ram0x0005cc20 >> 0x10);
            _applog(7,&local_818,0);
          }
        }
      }
      else {
        local_818._0_1_ = s_Probing_for_GBT_support_0005cbcc[0];
        local_818._1_1_ = s_Probing_for_GBT_support_0005cbcc[1];
        local_818._2_1_ = s_Probing_for_GBT_support_0005cbcc[2];
        local_818._3_1_ = s_Probing_for_GBT_support_0005cbcc[3];
        uStack_814._0_1_ = s_Probing_for_GBT_support_0005cbcc[4];
        uStack_814._1_1_ = s_Probing_for_GBT_support_0005cbcc[5];
        uStack_814._2_1_ = s_Probing_for_GBT_support_0005cbcc[6];
        uStack_814._3_1_ = s_Probing_for_GBT_support_0005cbcc[7];
        uStack_810._0_1_ = s_Probing_for_GBT_support_0005cbcc[8];
        uStack_810._1_1_ = s_Probing_for_GBT_support_0005cbcc[9];
        uStack_810._2_1_ = s_Probing_for_GBT_support_0005cbcc[10];
        uStack_810._3_1_ = s_Probing_for_GBT_support_0005cbcc[11];
        uStack_80c._0_1_ = s_Probing_for_GBT_support_0005cbcc[12];
        uStack_80c._1_1_ = s_Probing_for_GBT_support_0005cbcc[13];
        uStack_80c._2_1_ = s_Probing_for_GBT_support_0005cbcc[14];
        uStack_80c._3_1_ = s_Probing_for_GBT_support_0005cbcc[15];
        local_808._0_1_ = s_Probing_for_GBT_support_0005cbcc[16];
        local_808._1_1_ = s_Probing_for_GBT_support_0005cbcc[17];
        local_808._2_1_ = s_Probing_for_GBT_support_0005cbcc[18];
        local_808._3_1_ = s_Probing_for_GBT_support_0005cbcc[19];
        uStack_804._0_1_ = s_Probing_for_GBT_support_0005cbcc[20];
        uStack_804._1_1_ = s_Probing_for_GBT_support_0005cbcc[21];
        uStack_804._2_1_ = s_Probing_for_GBT_support_0005cbcc[22];
        uStack_804._3_1_ = s_Probing_for_GBT_support_0005cbcc[23];
        _applog(7,&local_818,0);
        cVar3 = opt_debug;
        *(undefined *)((int)param_1 + 99) = 0;
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
          *(undefined *)(param_1 + 0xa0) = 1;
        }
        else {
          *(undefined *)(param_1 + 0xa0) = 1;
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
        iVar1 = pthread_create(param_1 + 0xae,(pthread_attr_t *)0x0,stratum_sthread + 1,param_1);
        if (iVar1 == 0) {
          iVar1 = pthread_create(param_1 + 0xaf,(pthread_attr_t *)0x0,stratum_rthread + 1,param_1);
          if (iVar1 == 0) {
            return uVar5;
          }
          pcVar4 = "Failed to create stratum rthread";
        }
        else {
          pcVar4 = "Failed to create stratum sthread";
        }
        local_818 = *(undefined4 *)pcVar4;
        uStack_814 = *(undefined4 *)((int)pcVar4 + 4);
        uStack_810 = *(undefined4 *)((int)pcVar4 + 8);
        uStack_80c = *(undefined4 *)((int)pcVar4 + 0xc);
        local_808 = *(undefined4 *)((int)pcVar4 + 0x10);
        uStack_804 = *(undefined4 *)((int)pcVar4 + 0x14);
        uStack_800 = *(undefined4 *)((int)pcVar4 + 0x18);
        uStack_7fc = *(undefined4 *)((int)pcVar4 + 0x1c);
        local_7f8 = CONCAT31(local_7f8._1_3_,(char)*(undefined4 *)((int)pcVar4 + 0x20));
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

