
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 subscribe_extranonce(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  size_t sVar4;
  int iVar5;
  void *__ptr;
  int *piVar6;
  int *piVar7;
  char *__s1;
  int iVar8;
  undefined4 *__ptr_00;
  undefined4 uVar9;
  undefined auStack_2914 [252];
  undefined4 local_2818;
  undefined4 uStack_2814;
  undefined4 uStack_2810;
  undefined4 uStack_280c;
  undefined4 local_2808;
  undefined4 uStack_2804;
  undefined4 uStack_2800;
  undefined4 uStack_27fc;
  undefined4 local_27f8;
  undefined4 uStack_27f4;
  undefined4 uStack_27f0;
  undefined4 uStack_27ec;
  undefined4 local_27e8;
  char acStack_2018 [8196];
  
  swork_id = swork_id + 1;
  sprintf(acStack_2018,"{\"id\": %d, \"method\": \"mining.extranonce.subscribe\", \"params\": []}");
  sVar4 = strlen(acStack_2018);
  iVar5 = stratum_send(param_1,acStack_2018,sVar4);
  if (iVar5 == 0) {
    uVar9 = 0;
  }
  else {
    while (iVar5 = socket_full_isra_2(param_1[0x93],2), iVar5 != 0) {
      __ptr = (void *)recv_line(param_1);
      if (__ptr == (void *)0x0) {
        return 0;
      }
      iVar5 = parse_method(param_1,__ptr);
      if (iVar5 == 0) {
        iVar5 = json_loads(__ptr,0,auStack_2914);
        free(__ptr);
        piVar6 = (int *)json_object_get(iVar5,"result");
        piVar7 = (int *)json_object_get(iVar5,"error");
        if ((piVar6 == (int *)0x0) || (*piVar6 == 6)) {
          if (piVar7 != (int *)0x0) goto LAB_0004ac90;
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
LAB_0004acce:
          if (((use_syslog != '\0') || (opt_log_output != '\0')) || (5 < opt_log_level)) {
            snprintf((char *)&local_2818,0x800,"Pool %d JSON extranonce subscribe failed: %s",
                     *param_1,__ptr_00);
            _applog(6,&local_2818,0);
          }
          uVar9 = 0;
          free(__ptr_00);
        }
        else {
          if ((piVar7 == (int *)0x0) || (*piVar7 == 7)) {
            if ((use_syslog != '\0') || ((opt_log_output != '\0' || (5 < opt_log_level)))) {
              uVar9 = 1;
              snprintf((char *)&local_2818,0x800,"Stratum extranonce subscribe for pool %d",*param_1
                      );
              _applog(6,&local_2818,0);
              goto LAB_0004ad1c;
            }
          }
          else {
LAB_0004ac90:
            __s1 = (char *)__json_array_string(piVar7,1);
            if (((__s1 == (char *)0x0) &&
                (__s1 = (char *)json_string_value(piVar7), __s1 == (char *)0x0)) ||
               ((iVar8 = strcmp(__s1,
                                "Method \'subscribe\' not found for service \'mining.extranonce\'"),
                iVar8 != 0 && (iVar8 = strcmp(__s1,"Unrecognized request provided"), iVar8 != 0))))
            {
              __ptr_00 = (undefined4 *)json_dumps(piVar7,3);
              goto LAB_0004acce;
            }
            if (((use_syslog != '\0') || (opt_log_output != '\0')) || (5 < opt_log_level)) {
              uVar9 = 1;
              snprintf((char *)&local_2818,0x800,"Cannot subscribe to mining.extranonce for pool %d"
                       ,*param_1);
              _applog(6,&local_2818,0);
              goto LAB_0004ad1c;
            }
          }
          uVar9 = 1;
        }
LAB_0004ad1c:
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
    if ((opt_debug != '\0') &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      local_2818._0_1_ = s_Timed_out_waiting_for_response_e_00068000[0];
      local_2818._1_1_ = s_Timed_out_waiting_for_response_e_00068000[1];
      local_2818._2_1_ = s_Timed_out_waiting_for_response_e_00068000[2];
      local_2818._3_1_ = s_Timed_out_waiting_for_response_e_00068000[3];
      uStack_2814._0_1_ = s_Timed_out_waiting_for_response_e_00068000[4];
      uStack_2814._1_1_ = s_Timed_out_waiting_for_response_e_00068000[5];
      uStack_2814._2_1_ = s_Timed_out_waiting_for_response_e_00068000[6];
      uStack_2814._3_1_ = s_Timed_out_waiting_for_response_e_00068000[7];
      uStack_2810._0_1_ = s_Timed_out_waiting_for_response_e_00068000[8];
      uStack_2810._1_1_ = s_Timed_out_waiting_for_response_e_00068000[9];
      uStack_2810._2_1_ = s_Timed_out_waiting_for_response_e_00068000[10];
      uStack_2810._3_1_ = s_Timed_out_waiting_for_response_e_00068000[11];
      uStack_280c._0_1_ = s_Timed_out_waiting_for_response_e_00068000[12];
      uStack_280c._1_1_ = s_Timed_out_waiting_for_response_e_00068000[13];
      uStack_280c._2_1_ = s_Timed_out_waiting_for_response_e_00068000[14];
      uStack_280c._3_1_ = s_Timed_out_waiting_for_response_e_00068000[15];
      local_2808._0_1_ = s_Timed_out_waiting_for_response_e_00068000[16];
      local_2808._1_1_ = s_Timed_out_waiting_for_response_e_00068000[17];
      local_2808._2_1_ = s_Timed_out_waiting_for_response_e_00068000[18];
      local_2808._3_1_ = s_Timed_out_waiting_for_response_e_00068000[19];
      uStack_2804._0_1_ = s_Timed_out_waiting_for_response_e_00068000[20];
      uStack_2804._1_1_ = s_Timed_out_waiting_for_response_e_00068000[21];
      uStack_2804._2_1_ = s_Timed_out_waiting_for_response_e_00068000[22];
      uStack_2804._3_1_ = s_Timed_out_waiting_for_response_e_00068000[23];
      uStack_2800._0_1_ = s_Timed_out_waiting_for_response_e_00068000[24];
      uStack_2800._1_1_ = s_Timed_out_waiting_for_response_e_00068000[25];
      uStack_2800._2_1_ = s_Timed_out_waiting_for_response_e_00068000[26];
      uStack_2800._3_1_ = s_Timed_out_waiting_for_response_e_00068000[27];
      uStack_27fc._0_1_ = s_Timed_out_waiting_for_response_e_00068000[28];
      uStack_27fc._1_1_ = s_Timed_out_waiting_for_response_e_00068000[29];
      uStack_27fc._2_1_ = s_Timed_out_waiting_for_response_e_00068000[30];
      uStack_27fc._3_1_ = s_Timed_out_waiting_for_response_e_00068000[31];
      local_27f8._0_1_ = s_Timed_out_waiting_for_response_e_00068000[32];
      local_27f8._1_1_ = s_Timed_out_waiting_for_response_e_00068000[33];
      local_27f8._2_1_ = s_Timed_out_waiting_for_response_e_00068000[34];
      local_27f8._3_1_ = s_Timed_out_waiting_for_response_e_00068000[35];
      uStack_27f4._0_1_ = s_Timed_out_waiting_for_response_e_00068000[36];
      uStack_27f4._1_1_ = s_Timed_out_waiting_for_response_e_00068000[37];
      uStack_27f4._2_1_ = s_Timed_out_waiting_for_response_e_00068000[38];
      uStack_27f4._3_1_ = s_Timed_out_waiting_for_response_e_00068000[39];
      uStack_27f0._0_1_ = s_Timed_out_waiting_for_response_e_00068000[40];
      uStack_27f0._1_1_ = s_Timed_out_waiting_for_response_e_00068000[41];
      uStack_27f0._2_1_ = s_Timed_out_waiting_for_response_e_00068000[42];
      uStack_27f0._3_1_ = s_Timed_out_waiting_for_response_e_00068000[43];
      uStack_27ec._0_1_ = s_Timed_out_waiting_for_response_e_00068000[44];
      uStack_27ec._1_1_ = s_Timed_out_waiting_for_response_e_00068000[45];
      uStack_27ec._2_1_ = s_Timed_out_waiting_for_response_e_00068000[46];
      uStack_27ec._3_1_ = s_Timed_out_waiting_for_response_e_00068000[47];
      local_27e8._0_1_ = s_Timed_out_waiting_for_response_e_00068000[48];
      local_27e8._1_1_ = s_Timed_out_waiting_for_response_e_00068000[49];
      local_27e8._2_1_ = s_Timed_out_waiting_for_response_e_00068000[50];
      local_27e8._3_1_ = s_Timed_out_waiting_for_response_e_00068000[51];
      _applog(7,&local_2818,0);
    }
    uVar9 = 1;
  }
  return uVar9;
}

