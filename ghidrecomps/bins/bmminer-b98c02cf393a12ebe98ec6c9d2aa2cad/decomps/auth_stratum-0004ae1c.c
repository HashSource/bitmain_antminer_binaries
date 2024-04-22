
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 auth_stratum(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  size_t sVar4;
  int iVar5;
  void *__ptr;
  int *piVar6;
  int *piVar7;
  undefined4 *__ptr_00;
  int iVar8;
  undefined4 uVar9;
  undefined auStack_2914 [252];
  undefined4 local_2818;
  undefined4 uStack_2814;
  undefined4 uStack_2810;
  undefined4 uStack_280c;
  char acStack_2018 [8196];
  
  iVar5 = swork_id;
  swork_id = swork_id + 1;
  sprintf(acStack_2018,
          "{\"id\": %d, \"method\": \"mining.authorize\", \"params\": [\"%s\", \"%s\"]}",iVar5,
          param_1[0x2b],param_1[0x2c]);
  sVar4 = strlen(acStack_2018);
  iVar5 = stratum_send(param_1,acStack_2018,sVar4);
  if (iVar5 != 0) {
    while (__ptr = (void *)recv_line(param_1), __ptr != (void *)0x0) {
      iVar5 = parse_method(param_1,__ptr);
      if (iVar5 == 0) {
        iVar5 = json_loads(__ptr,0,auStack_2914);
        free(__ptr);
        piVar6 = (int *)json_object_get(iVar5,"result");
        piVar7 = (int *)json_object_get(iVar5,"error");
        if ((piVar6 == (int *)0x0) || (*piVar6 == 6)) {
          if (piVar7 != (int *)0x0) goto LAB_0004aed2;
          __ptr_00 = (undefined4 *)malloc(0x11);
          uVar3 = ram0x0005e28c;
          uVar2 = s__unknown_reason__0005e27c._12_4_;
          uVar1 = s__unknown_reason__0005e27c._8_4_;
          uVar9 = s__unknown_reason__0005e27c._4_4_;
          if (__ptr_00 != (undefined4 *)0x0) {
            *__ptr_00 = s__unknown_reason__0005e27c._0_4_;
            __ptr_00[1] = uVar9;
            __ptr_00[2] = uVar1;
            __ptr_00[3] = uVar2;
            *(char *)(__ptr_00 + 4) = (char)uVar3;
          }
        }
        else {
          if ((piVar7 == (int *)0x0) || (*piVar7 == 7)) {
            if (((use_syslog != '\0') || (opt_log_output != '\0')) || (5 < opt_log_level)) {
              snprintf((char *)&local_2818,0x800,"Stratum authorisation success for pool %d",
                       *param_1);
              _applog(6,&local_2818,0);
            }
            iVar8 = opt_suggest_diff;
            successful_connect = 1;
            *(undefined *)((int)param_1 + 99) = 1;
            if (iVar8 != 0) {
              swork_id = swork_id + 1;
              sprintf(acStack_2018,
                      "{\"id\": %d, \"method\": \"mining.suggest_difficulty\", \"params\": [%d]}");
              sVar4 = strlen(acStack_2018);
              stratum_send(param_1,acStack_2018,sVar4);
            }
            if (opt_bitmain_ab == '\0') {
              uVar9 = 1;
            }
            else {
              if (((use_syslog != '\0') || (opt_log_output != '\0')) || (4 < opt_log_level)) {
                local_2818._0_1_ = s_LOW_POWER_MODE__00068200[0];
                local_2818._1_1_ = s_LOW_POWER_MODE__00068200[1];
                local_2818._2_1_ = s_LOW_POWER_MODE__00068200[2];
                local_2818._3_1_ = s_LOW_POWER_MODE__00068200[3];
                uStack_2814._0_1_ = s_LOW_POWER_MODE__00068200[4];
                uStack_2814._1_1_ = s_LOW_POWER_MODE__00068200[5];
                uStack_2814._2_1_ = s_LOW_POWER_MODE__00068200[6];
                uStack_2814._3_1_ = s_LOW_POWER_MODE__00068200[7];
                uStack_2810._0_1_ = s_LOW_POWER_MODE__00068200[8];
                uStack_2810._1_1_ = s_LOW_POWER_MODE__00068200[9];
                uStack_2810._2_1_ = s_LOW_POWER_MODE__00068200[10];
                uStack_2810._3_1_ = s_LOW_POWER_MODE__00068200[11];
                uStack_280c._0_1_ = s_LOW_POWER_MODE__00068200[12];
                uStack_280c._1_1_ = s_LOW_POWER_MODE__00068200[13];
                uStack_280c._2_1_ = s_LOW_POWER_MODE__00068200[14];
                uStack_280c._3_1_ = s_LOW_POWER_MODE__00068200[15];
                _applog(5,&local_2818,0);
              }
              iVar8 = swork_id;
              swork_id = swork_id + 1;
              uVar9 = 1;
              sprintf(acStack_2018,
                      "{\"id\":%d, \"method\":\"mining.configure\", \"params\":[[\"version-rolling\"],{\"version-rolling.mask\":\"%08x\",\"version-rolling.min-bit-count\":%d}]}"
                      ,iVar8,0xc00000,2);
              sVar4 = strlen(acStack_2018);
              stratum_send(param_1,acStack_2018,sVar4);
              param_1[0xa2] = 1;
            }
            goto LAB_0004af2e;
          }
LAB_0004aed2:
          __ptr_00 = (undefined4 *)json_dumps(piVar7,3);
        }
        if (((use_syslog != '\0') || (opt_log_output != '\0')) || (5 < opt_log_level)) {
          snprintf((char *)&local_2818,0x800,"pool %d JSON stratum auth failed: %s",*param_1,
                   __ptr_00);
          _applog(6,&local_2818,0);
        }
        uVar9 = 0;
        free(__ptr_00);
        suspend_stratum(param_1);
LAB_0004af2e:
        if (iVar5 == 0) {
          return uVar9;
        }
        if (*(int *)(iVar5 + 4) == -1) {
          return uVar9;
        }
        iVar8 = *(int *)(iVar5 + 4) + -1;
        *(int *)(iVar5 + 4) = iVar8;
        if (iVar8 != 0) {
          return uVar9;
        }
        json_delete(iVar5);
        return uVar9;
      }
      free(__ptr);
    }
  }
  return 0;
}

