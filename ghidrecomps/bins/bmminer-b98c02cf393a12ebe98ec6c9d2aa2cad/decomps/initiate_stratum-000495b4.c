
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int initiate_stratum(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char cVar4;
  int iVar5;
  size_t sVar6;
  int *piVar7;
  void *__ptr;
  int *piVar8;
  undefined4 *__s1;
  int *piVar9;
  char *pcVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  bool bVar15;
  bool bVar16;
  undefined4 local_2924 [23];
  undefined auStack_28c8 [160];
  undefined4 local_2828;
  undefined4 uStack_2824;
  undefined4 uStack_2820;
  undefined4 uStack_281c;
  undefined4 local_2818;
  undefined4 uStack_2814;
  undefined4 uStack_2810;
  undefined4 uStack_280c;
  undefined4 local_2808;
  undefined4 local_2804;
  undefined4 uStack_2800;
  undefined4 uStack_27fc;
  undefined2 uStack_27f8;
  undefined local_27f6;
  char acStack_2028 [8196];
  
  iVar14 = 0;
  bVar15 = false;
  bVar16 = false;
  iVar5 = setup_stratum_socket(param_1);
  if (iVar5 == 0) goto LAB_0004973e;
  do {
    if (bVar16) {
      clear_sock(param_1);
      swork_id = swork_id + 1;
      sprintf(acStack_2028,"{\"id\": %d, \"method\": \"mining.subscribe\", \"params\": []}");
    }
    else if (param_1[0x9f] == 0) {
      swork_id = swork_id + 1;
      sprintf(acStack_2028,
              "{\"id\": %d, \"method\": \"mining.subscribe\", \"params\": [\"bmminer/2.0.0\"]}");
    }
    else {
      swork_id = swork_id + 1;
      sprintf(acStack_2028,
              "{\"id\": %d, \"method\": \"mining.subscribe\", \"params\": [\"bmminer/2.0.0\", \"%s\"]}"
             );
    }
    sVar6 = strlen(acStack_2028);
    iVar5 = __stratum_send(param_1,acStack_2028,sVar6);
    if (iVar5 == 0) {
      iVar5 = socket_full_isra_2(param_1[0x93],0x3c);
      if (iVar5 == 0) {
        if ((opt_debug != 0) &&
           (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
          local_2828._0_1_ = s_Timed_out_waiting_for_response_i_000679b0[0];
          local_2828._1_1_ = s_Timed_out_waiting_for_response_i_000679b0[1];
          local_2828._2_1_ = s_Timed_out_waiting_for_response_i_000679b0[2];
          local_2828._3_1_ = s_Timed_out_waiting_for_response_i_000679b0[3];
          uStack_2824._0_1_ = s_Timed_out_waiting_for_response_i_000679b0[4];
          uStack_2824._1_1_ = s_Timed_out_waiting_for_response_i_000679b0[5];
          uStack_2824._2_1_ = s_Timed_out_waiting_for_response_i_000679b0[6];
          uStack_2824._3_1_ = s_Timed_out_waiting_for_response_i_000679b0[7];
          uStack_2820._0_1_ = s_Timed_out_waiting_for_response_i_000679b0[8];
          uStack_2820._1_1_ = s_Timed_out_waiting_for_response_i_000679b0[9];
          uStack_2820._2_1_ = s_Timed_out_waiting_for_response_i_000679b0[10];
          uStack_2820._3_1_ = s_Timed_out_waiting_for_response_i_000679b0[11];
          uStack_281c._0_1_ = s_Timed_out_waiting_for_response_i_000679b0[12];
          uStack_281c._1_1_ = s_Timed_out_waiting_for_response_i_000679b0[13];
          uStack_281c._2_1_ = s_Timed_out_waiting_for_response_i_000679b0[14];
          uStack_281c._3_1_ = s_Timed_out_waiting_for_response_i_000679b0[15];
          local_2818._0_1_ = s_Timed_out_waiting_for_response_i_000679b0[16];
          local_2818._1_1_ = s_Timed_out_waiting_for_response_i_000679b0[17];
          local_2818._2_1_ = s_Timed_out_waiting_for_response_i_000679b0[18];
          local_2818._3_1_ = s_Timed_out_waiting_for_response_i_000679b0[19];
          uStack_2814._0_1_ = s_Timed_out_waiting_for_response_i_000679b0[20];
          uStack_2814._1_1_ = s_Timed_out_waiting_for_response_i_000679b0[21];
          uStack_2814._2_1_ = s_Timed_out_waiting_for_response_i_000679b0[22];
          uStack_2814._3_1_ = s_Timed_out_waiting_for_response_i_000679b0[23];
          uStack_2810._0_1_ = s_Timed_out_waiting_for_response_i_000679b0[24];
          uStack_2810._1_1_ = s_Timed_out_waiting_for_response_i_000679b0[25];
          uStack_2810._2_1_ = s_Timed_out_waiting_for_response_i_000679b0[26];
          uStack_2810._3_1_ = s_Timed_out_waiting_for_response_i_000679b0[27];
          uStack_280c._0_1_ = s_Timed_out_waiting_for_response_i_000679b0[28];
          uStack_280c._1_1_ = s_Timed_out_waiting_for_response_i_000679b0[29];
          uStack_280c._2_1_ = s_Timed_out_waiting_for_response_i_000679b0[30];
          uStack_280c._3_1_ = s_Timed_out_waiting_for_response_i_000679b0[31];
          local_2808._0_1_ = s_Timed_out_waiting_for_response_i_000679b0[32];
          local_2808._1_1_ = s_Timed_out_waiting_for_response_i_000679b0[33];
          local_2808._2_1_ = s_Timed_out_waiting_for_response_i_000679b0[34];
          local_2808._3_1_ = s_Timed_out_waiting_for_response_i_000679b0[35];
          local_2804._0_1_ = s_Timed_out_waiting_for_response_i_000679b0[36];
          local_2804._1_1_ = s_Timed_out_waiting_for_response_i_000679b0[37];
          local_2804._2_1_ = s_Timed_out_waiting_for_response_i_000679b0[38];
          local_2804._3_1_ = s_Timed_out_waiting_for_response_i_000679b0[39];
          uStack_2800._0_1_ = s_Timed_out_waiting_for_response_i_000679b0[40];
          uStack_2800._1_1_ = s_Timed_out_waiting_for_response_i_000679b0[41];
          uStack_2800._2_1_ = s_Timed_out_waiting_for_response_i_000679b0[42];
          uStack_2800._3_1_ = s_Timed_out_waiting_for_response_i_000679b0[43];
          uStack_27fc._0_1_ = s_Timed_out_waiting_for_response_i_000679b0[44];
          uStack_27fc._1_1_ = s_Timed_out_waiting_for_response_i_000679b0[45];
          uStack_27fc._2_1_ = s_Timed_out_waiting_for_response_i_000679b0[46];
          uStack_27fc._3_1_ = s_Timed_out_waiting_for_response_i_000679b0[47];
          uStack_27f8 = (undefined2)ram0x000679e0;
          local_27f6 = (undefined)((uint)ram0x000679e0 >> 0x10);
          _applog(7,&local_2828,0);
        }
      }
      else {
        __ptr = (void *)recv_line(param_1);
        if (__ptr != (void *)0x0) {
          iVar14 = json_loads(__ptr,0,local_2924);
          free(__ptr);
          if (iVar14 == 0) {
            if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 6)) {
              bVar16 = true;
            }
            else {
              snprintf((char *)&local_2828,0x800,"JSON decode failed(%d): %s",local_2924[0],
                       auStack_28c8);
              bVar16 = true;
              _applog(6,&local_2828,0);
            }
          }
          else {
            piVar7 = (int *)json_object_get(iVar14,"result");
            piVar8 = (int *)json_object_get(iVar14,"error");
            if ((piVar7 == (int *)0x0) || (*piVar7 == 7)) {
              if (piVar8 != (int *)0x0) goto LAB_00049a44;
              __s1 = (undefined4 *)malloc(0x11);
              uVar3 = ram0x0005e28c;
              uVar2 = s__unknown_reason__0005e27c._12_4_;
              uVar12 = s__unknown_reason__0005e27c._8_4_;
              uVar1 = s__unknown_reason__0005e27c._4_4_;
              if (__s1 != (undefined4 *)0x0) {
                *__s1 = s__unknown_reason__0005e27c._0_4_;
                __s1[1] = uVar1;
                __s1[2] = uVar12;
                __s1[3] = uVar2;
                *(char *)(__s1 + 4) = (char)uVar3;
              }
LAB_00049a4c:
              if (((use_syslog != '\0') || (opt_log_output != '\0')) || (5 < opt_log_level)) {
                snprintf((char *)&local_2828,0x800,"JSON-RPC decode failed: %s",__s1);
                _applog(6,&local_2828,0);
              }
            }
            else {
              if ((piVar8 != (int *)0x0) && (*piVar8 != 7)) {
LAB_00049a44:
                __s1 = (undefined4 *)json_dumps(piVar8,3);
                goto LAB_00049a4c;
              }
              piVar8 = (int *)json_array_get(piVar7,0);
              if (((piVar8 != (int *)0x0) && (*piVar8 == 1)) &&
                 (iVar5 = json_array_size(), 0 < iVar5)) {
                iVar13 = 0;
                do {
                  piVar9 = (int *)json_array_get(piVar8,iVar13);
                  if ((piVar9 == (int *)0x0) || (*piVar9 != 1)) break;
                  iVar13 = iVar13 + 1;
                  pcVar10 = (char *)__json_array_string(piVar9,0);
                  if ((pcVar10 != (char *)0x0) &&
                     (iVar11 = strncasecmp(pcVar10,"mining.notify",0xd), iVar11 == 0)) {
                    __s1 = (undefined4 *)json_array_string(piVar9,1);
                    if (__s1 != (undefined4 *)0x0) goto LAB_00049bc6;
                    break;
                  }
                } while (iVar5 != iVar13);
              }
              __s1 = (undefined4 *)(uint)opt_debug;
              if ((__s1 != (undefined4 *)0x0) &&
                 (((use_syslog != '\0' || (opt_log_output != '\0')) ||
                  (__s1 = (undefined4 *)0x0, 6 < opt_log_level)))) {
                __s1 = (undefined4 *)0x0;
                local_2828._0_1_ = s_Failed_to_get_sessionid_in_initi_00067adc[0];
                local_2828._1_1_ = s_Failed_to_get_sessionid_in_initi_00067adc[1];
                local_2828._2_1_ = s_Failed_to_get_sessionid_in_initi_00067adc[2];
                local_2828._3_1_ = s_Failed_to_get_sessionid_in_initi_00067adc[3];
                uStack_2824._0_1_ = s_Failed_to_get_sessionid_in_initi_00067adc[4];
                uStack_2824._1_1_ = s_Failed_to_get_sessionid_in_initi_00067adc[5];
                uStack_2824._2_1_ = s_Failed_to_get_sessionid_in_initi_00067adc[6];
                uStack_2824._3_1_ = s_Failed_to_get_sessionid_in_initi_00067adc[7];
                uStack_2820._0_1_ = s_Failed_to_get_sessionid_in_initi_00067adc[8];
                uStack_2820._1_1_ = s_Failed_to_get_sessionid_in_initi_00067adc[9];
                uStack_2820._2_1_ = s_Failed_to_get_sessionid_in_initi_00067adc[10];
                uStack_2820._3_1_ = s_Failed_to_get_sessionid_in_initi_00067adc[11];
                uStack_281c._0_1_ = s_Failed_to_get_sessionid_in_initi_00067adc[12];
                uStack_281c._1_1_ = s_Failed_to_get_sessionid_in_initi_00067adc[13];
                uStack_281c._2_1_ = s_Failed_to_get_sessionid_in_initi_00067adc[14];
                uStack_281c._3_1_ = s_Failed_to_get_sessionid_in_initi_00067adc[15];
                local_2818._0_1_ = s_Failed_to_get_sessionid_in_initi_00067adc[16];
                local_2818._1_1_ = s_Failed_to_get_sessionid_in_initi_00067adc[17];
                local_2818._2_1_ = s_Failed_to_get_sessionid_in_initi_00067adc[18];
                local_2818._3_1_ = s_Failed_to_get_sessionid_in_initi_00067adc[19];
                uStack_2814._0_1_ = s_Failed_to_get_sessionid_in_initi_00067adc[20];
                uStack_2814._1_1_ = s_Failed_to_get_sessionid_in_initi_00067adc[21];
                uStack_2814._2_1_ = s_Failed_to_get_sessionid_in_initi_00067adc[22];
                uStack_2814._3_1_ = s_Failed_to_get_sessionid_in_initi_00067adc[23];
                uStack_2810._0_1_ = s_Failed_to_get_sessionid_in_initi_00067adc[24];
                uStack_2810._1_1_ = s_Failed_to_get_sessionid_in_initi_00067adc[25];
                uStack_2810._2_1_ = s_Failed_to_get_sessionid_in_initi_00067adc[26];
                uStack_2810._3_1_ = s_Failed_to_get_sessionid_in_initi_00067adc[27];
                uStack_280c._0_1_ = s_Failed_to_get_sessionid_in_initi_00067adc[28];
                uStack_280c._1_1_ = s_Failed_to_get_sessionid_in_initi_00067adc[29];
                uStack_280c._2_1_ = s_Failed_to_get_sessionid_in_initi_00067adc[30];
                uStack_280c._3_1_ = s_Failed_to_get_sessionid_in_initi_00067adc[31];
                local_2808._0_1_ = s_Failed_to_get_sessionid_in_initi_00067adc[32];
                local_2808._1_1_ = s_Failed_to_get_sessionid_in_initi_00067adc[33];
                local_2808._2_1_ = s_Failed_to_get_sessionid_in_initi_00067adc[34];
                local_2808._3_1_ = s_Failed_to_get_sessionid_in_initi_00067adc[35];
                local_2804._0_1_ = s_Failed_to_get_sessionid_in_initi_00067adc[36];
                local_2804._1_1_ = s_Failed_to_get_sessionid_in_initi_00067adc[37];
                local_2804._2_1_ = s_Failed_to_get_sessionid_in_initi_00067adc[38];
                local_2804._3_1_ = s_Failed_to_get_sessionid_in_initi_00067adc[39];
                uStack_2800._0_1_ = s_Failed_to_get_sessionid_in_initi_00067adc[40];
                uStack_2800._1_1_ = s_Failed_to_get_sessionid_in_initi_00067adc[41];
                uStack_2800._2_1_ = s_Failed_to_get_sessionid_in_initi_00067adc[42];
                uStack_2800._3_1_ = s_Failed_to_get_sessionid_in_initi_00067adc[43];
                _applog(7,&local_2828,0);
              }
LAB_00049bc6:
              pcVar10 = (char *)json_array_string(piVar7,1);
              iVar5 = _valid_hex_constprop_10(pcVar10,DAT_00049d04,0xcba);
              if (iVar5 != 0) {
                json_array_get(piVar7,2);
                iVar5 = json_integer_value();
                if (0xe < iVar5 - 2U) {
                  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (5 < opt_log_level)) {
                    local_2828._0_1_ = s_Failed_to_get_valid_n2size_in_in_00067b38[0];
                    local_2828._1_1_ = s_Failed_to_get_valid_n2size_in_in_00067b38[1];
                    local_2828._2_1_ = s_Failed_to_get_valid_n2size_in_in_00067b38[2];
                    local_2828._3_1_ = s_Failed_to_get_valid_n2size_in_in_00067b38[3];
                    uStack_2824._0_1_ = s_Failed_to_get_valid_n2size_in_in_00067b38[4];
                    uStack_2824._1_1_ = s_Failed_to_get_valid_n2size_in_in_00067b38[5];
                    uStack_2824._2_1_ = s_Failed_to_get_valid_n2size_in_in_00067b38[6];
                    uStack_2824._3_1_ = s_Failed_to_get_valid_n2size_in_in_00067b38[7];
                    uStack_2820._0_1_ = s_Failed_to_get_valid_n2size_in_in_00067b38[8];
                    uStack_2820._1_1_ = s_Failed_to_get_valid_n2size_in_in_00067b38[9];
                    uStack_2820._2_1_ = s_Failed_to_get_valid_n2size_in_in_00067b38[10];
                    uStack_2820._3_1_ = s_Failed_to_get_valid_n2size_in_in_00067b38[11];
                    uStack_281c._0_1_ = s_Failed_to_get_valid_n2size_in_in_00067b38[12];
                    uStack_281c._1_1_ = s_Failed_to_get_valid_n2size_in_in_00067b38[13];
                    uStack_281c._2_1_ = s_Failed_to_get_valid_n2size_in_in_00067b38[14];
                    uStack_281c._3_1_ = s_Failed_to_get_valid_n2size_in_in_00067b38[15];
                    local_2818._0_1_ = s_Failed_to_get_valid_n2size_in_in_00067b38[16];
                    local_2818._1_1_ = s_Failed_to_get_valid_n2size_in_in_00067b38[17];
                    local_2818._2_1_ = s_Failed_to_get_valid_n2size_in_in_00067b38[18];
                    local_2818._3_1_ = s_Failed_to_get_valid_n2size_in_in_00067b38[19];
                    uStack_2814._0_1_ = s_Failed_to_get_valid_n2size_in_in_00067b38[20];
                    uStack_2814._1_1_ = s_Failed_to_get_valid_n2size_in_in_00067b38[21];
                    uStack_2814._2_1_ = s_Failed_to_get_valid_n2size_in_in_00067b38[22];
                    uStack_2814._3_1_ = s_Failed_to_get_valid_n2size_in_in_00067b38[23];
                    uStack_2810._0_1_ = s_Failed_to_get_valid_n2size_in_in_00067b38[24];
                    uStack_2810._1_1_ = s_Failed_to_get_valid_n2size_in_in_00067b38[25];
                    uStack_2810._2_1_ = s_Failed_to_get_valid_n2size_in_in_00067b38[26];
                    uStack_2810._3_1_ = s_Failed_to_get_valid_n2size_in_in_00067b38[27];
                    uStack_280c._0_1_ = s_Failed_to_get_valid_n2size_in_in_00067b38[28];
                    uStack_280c._1_1_ = s_Failed_to_get_valid_n2size_in_in_00067b38[29];
                    uStack_280c._2_1_ = s_Failed_to_get_valid_n2size_in_in_00067b38[30];
                    uStack_280c._3_1_ = s_Failed_to_get_valid_n2size_in_in_00067b38[31];
                    local_2808._0_1_ = s_Failed_to_get_valid_n2size_in_in_00067b38[32];
                    local_2808._1_1_ = s_Failed_to_get_valid_n2size_in_in_00067b38[33];
                    local_2808._2_1_ = s_Failed_to_get_valid_n2size_in_in_00067b38[34];
                    local_2808._3_1_ = s_Failed_to_get_valid_n2size_in_in_00067b38[35];
                    local_2804._0_1_ = s_Failed_to_get_valid_n2size_in_in_00067b38[36];
                    local_2804._1_1_ = s_Failed_to_get_valid_n2size_in_in_00067b38[37];
                    local_2804._2_1_ = s_Failed_to_get_valid_n2size_in_in_00067b38[38];
                    local_2804._3_1_ = s_Failed_to_get_valid_n2size_in_in_00067b38[39];
                    uStack_2800._0_1_ = s_Failed_to_get_valid_n2size_in_in_00067b38[40];
                    uStack_2800._1_1_ = s_Failed_to_get_valid_n2size_in_in_00067b38[41];
                    uStack_2800._2_1_ = s_Failed_to_get_valid_n2size_in_in_00067b38[42];
                    uStack_2800._3_1_ = s_Failed_to_get_valid_n2size_in_in_00067b38[43];
                    uStack_27fc._0_3_ = (undefined3)ram0x00067b64;
                    _applog(6,&local_2828,0);
                  }
                  free(__s1);
                  bVar16 = true;
                  free(pcVar10);
                  goto LAB_00049666;
                }
                if (((__s1 != (undefined4 *)0x0) && ((char *)param_1[0x9f] != (char *)0x0)) &&
                   ((iVar13 = strcmp((char *)__s1,(char *)param_1[0x9f]), iVar13 == 0 &&
                    (((use_syslog != '\0' || (opt_log_output != '\0')) || (4 < opt_log_level)))))) {
                  snprintf((char *)&local_2828,0x800,
                           "Pool %d successfully negotiated resume with the same session ID",
                           *param_1);
                  _applog(5,&local_2828,0);
                }
                iVar13 = pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x35));
                if (iVar13 != 0) {
                  _mutex_lock_part_1_constprop_16(DAT_00049fbc,0xccf);
                }
                iVar13 = pthread_rwlock_wrlock((pthread_rwlock_t *)(param_1 + 0x3b));
                uVar1 = DAT_00049fbc;
                if (iVar13 != 0) {
                  piVar7 = __errno_location();
                  snprintf((char *)&local_2828,0x800,
                           "WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d",*piVar7,"util.c",uVar1
                           ,0xccf);
                  _applog(3,&local_2828,1);
                  _quit(1);
                }
                free((void *)param_1[0x99]);
                free((void *)param_1[0x9f]);
                param_1[0x9f] = __s1;
                param_1[0x99] = pcVar10;
                sVar6 = strlen(pcVar10);
                param_1[0x187] = sVar6 >> 1;
                free((void *)param_1[0x9a]);
                uVar12 = _cgcalloc(param_1[0x187],1,"util.c",DAT_00049fbc,0xcd6);
                param_1[0x9a] = uVar12;
                hex2bin(uVar12,param_1[0x99],param_1[0x187]);
                param_1[0x9e] = iVar5;
                iVar5 = pthread_rwlock_unlock((pthread_rwlock_t *)(param_1 + 0x3b));
                if (iVar5 != 0) {
                  piVar7 = __errno_location();
                  snprintf((char *)&local_2828,0x800,
                           "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar7,"util.c",
                           uVar1,0xcd9);
                  _applog(3,&local_2828,1);
                  _quit(1);
                }
                iVar5 = pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x35));
                if (iVar5 != 0) {
                  piVar7 = __errno_location();
                  snprintf((char *)&local_2828,0x800,
                           "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar7,"util.c",
                           uVar1,0xcd9);
                  _applog(3,&local_2828,1);
                  _quit(1);
                }
                (*selective_yield)();
                if (((__s1 != (undefined4 *)0x0) && (opt_debug != 0)) &&
                   ((use_syslog != '\0' || ((opt_log_output != '\0' || (6 < opt_log_level)))))) {
                  snprintf((char *)&local_2828,0x800,"Pool %d stratum session id: %s",*param_1,
                           param_1[0x9f]);
                  _applog(7,&local_2828,0);
                }
                if (param_1[0x90] == 0) {
                  param_1[0x90] = param_1[0x96];
                }
                cVar4 = opt_protocol;
                *(undefined *)((int)param_1 + 0x281) = 1;
                param_1[0x1c6] = 0;
                param_1[0x1c7] = 0;
                param_1[0x1c8] = 0;
                param_1[0x1c9] = 0x3ff00000;
                if (((cVar4 != '\0') && (opt_debug != 0)) &&
                   ((use_syslog != '\0' || ((opt_log_output != '\0' || (6 < opt_log_level)))))) {
                  snprintf((char *)&local_2828,0x800,
                           "Pool %d confirmed mining.subscribe with extranonce1 %s extran2size %d",
                           *param_1,param_1[0x99],param_1[0x9e]);
                  _applog(7,&local_2828,0);
                }
                iVar5 = 1;
                goto LAB_0004978a;
              }
              if (((use_syslog != '\0') || (opt_log_output != '\0')) || (5 < opt_log_level)) {
                local_2828._0_1_ = s_Failed_to_get_valid_nonce1_in_in_00067b08[0];
                local_2828._1_1_ = s_Failed_to_get_valid_nonce1_in_in_00067b08[1];
                local_2828._2_1_ = s_Failed_to_get_valid_nonce1_in_in_00067b08[2];
                local_2828._3_1_ = s_Failed_to_get_valid_nonce1_in_in_00067b08[3];
                uStack_2824._0_1_ = s_Failed_to_get_valid_nonce1_in_in_00067b08[4];
                uStack_2824._1_1_ = s_Failed_to_get_valid_nonce1_in_in_00067b08[5];
                uStack_2824._2_1_ = s_Failed_to_get_valid_nonce1_in_in_00067b08[6];
                uStack_2824._3_1_ = s_Failed_to_get_valid_nonce1_in_in_00067b08[7];
                uStack_2820._0_1_ = s_Failed_to_get_valid_nonce1_in_in_00067b08[8];
                uStack_2820._1_1_ = s_Failed_to_get_valid_nonce1_in_in_00067b08[9];
                uStack_2820._2_1_ = s_Failed_to_get_valid_nonce1_in_in_00067b08[10];
                uStack_2820._3_1_ = s_Failed_to_get_valid_nonce1_in_in_00067b08[11];
                uStack_281c._0_1_ = s_Failed_to_get_valid_nonce1_in_in_00067b08[12];
                uStack_281c._1_1_ = s_Failed_to_get_valid_nonce1_in_in_00067b08[13];
                uStack_281c._2_1_ = s_Failed_to_get_valid_nonce1_in_in_00067b08[14];
                uStack_281c._3_1_ = s_Failed_to_get_valid_nonce1_in_in_00067b08[15];
                local_2818._0_1_ = s_Failed_to_get_valid_nonce1_in_in_00067b08[16];
                local_2818._1_1_ = s_Failed_to_get_valid_nonce1_in_in_00067b08[17];
                local_2818._2_1_ = s_Failed_to_get_valid_nonce1_in_in_00067b08[18];
                local_2818._3_1_ = s_Failed_to_get_valid_nonce1_in_in_00067b08[19];
                uStack_2814._0_1_ = s_Failed_to_get_valid_nonce1_in_in_00067b08[20];
                uStack_2814._1_1_ = s_Failed_to_get_valid_nonce1_in_in_00067b08[21];
                uStack_2814._2_1_ = s_Failed_to_get_valid_nonce1_in_in_00067b08[22];
                uStack_2814._3_1_ = s_Failed_to_get_valid_nonce1_in_in_00067b08[23];
                uStack_2810._0_1_ = s_Failed_to_get_valid_nonce1_in_in_00067b08[24];
                uStack_2810._1_1_ = s_Failed_to_get_valid_nonce1_in_in_00067b08[25];
                uStack_2810._2_1_ = s_Failed_to_get_valid_nonce1_in_in_00067b08[26];
                uStack_2810._3_1_ = s_Failed_to_get_valid_nonce1_in_in_00067b08[27];
                uStack_280c._0_1_ = s_Failed_to_get_valid_nonce1_in_in_00067b08[28];
                uStack_280c._1_1_ = s_Failed_to_get_valid_nonce1_in_in_00067b08[29];
                uStack_280c._2_1_ = s_Failed_to_get_valid_nonce1_in_in_00067b08[30];
                uStack_280c._3_1_ = s_Failed_to_get_valid_nonce1_in_in_00067b08[31];
                local_2808._0_1_ = s_Failed_to_get_valid_nonce1_in_in_00067b08[32];
                local_2808._1_1_ = s_Failed_to_get_valid_nonce1_in_in_00067b08[33];
                local_2808._2_1_ = s_Failed_to_get_valid_nonce1_in_in_00067b08[34];
                local_2808._3_1_ = s_Failed_to_get_valid_nonce1_in_in_00067b08[35];
                local_2804._0_1_ = s_Failed_to_get_valid_nonce1_in_in_00067b08[36];
                local_2804._1_1_ = s_Failed_to_get_valid_nonce1_in_in_00067b08[37];
                local_2804._2_1_ = s_Failed_to_get_valid_nonce1_in_in_00067b08[38];
                local_2804._3_1_ = s_Failed_to_get_valid_nonce1_in_in_00067b08[39];
                uStack_2800._0_1_ = s_Failed_to_get_valid_nonce1_in_in_00067b08[40];
                uStack_2800._1_1_ = s_Failed_to_get_valid_nonce1_in_in_00067b08[41];
                uStack_2800._2_1_ = s_Failed_to_get_valid_nonce1_in_in_00067b08[42];
                uStack_2800._3_1_ = s_Failed_to_get_valid_nonce1_in_in_00067b08[43];
                uStack_27fc._0_3_ = (undefined3)ram0x00067b34;
                _applog(6,&local_2828,0);
              }
            }
            bVar16 = true;
            free(__s1);
          }
        }
      }
    }
    else if ((opt_debug != 0) &&
            (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      local_2828._0_1_ = s_Failed_to_send_s_in_initiate_str_00067988[0];
      local_2828._1_1_ = s_Failed_to_send_s_in_initiate_str_00067988[1];
      local_2828._2_1_ = s_Failed_to_send_s_in_initiate_str_00067988[2];
      local_2828._3_1_ = s_Failed_to_send_s_in_initiate_str_00067988[3];
      uStack_2824._0_1_ = s_Failed_to_send_s_in_initiate_str_00067988[4];
      uStack_2824._1_1_ = s_Failed_to_send_s_in_initiate_str_00067988[5];
      uStack_2824._2_1_ = s_Failed_to_send_s_in_initiate_str_00067988[6];
      uStack_2824._3_1_ = s_Failed_to_send_s_in_initiate_str_00067988[7];
      uStack_2820._0_1_ = s_Failed_to_send_s_in_initiate_str_00067988[8];
      uStack_2820._1_1_ = s_Failed_to_send_s_in_initiate_str_00067988[9];
      uStack_2820._2_1_ = s_Failed_to_send_s_in_initiate_str_00067988[10];
      uStack_2820._3_1_ = s_Failed_to_send_s_in_initiate_str_00067988[11];
      uStack_281c._0_1_ = s_Failed_to_send_s_in_initiate_str_00067988[12];
      uStack_281c._1_1_ = s_Failed_to_send_s_in_initiate_str_00067988[13];
      uStack_281c._2_1_ = s_Failed_to_send_s_in_initiate_str_00067988[14];
      uStack_281c._3_1_ = s_Failed_to_send_s_in_initiate_str_00067988[15];
      local_2818._0_1_ = s_Failed_to_send_s_in_initiate_str_00067988[16];
      local_2818._1_1_ = s_Failed_to_send_s_in_initiate_str_00067988[17];
      local_2818._2_1_ = s_Failed_to_send_s_in_initiate_str_00067988[18];
      local_2818._3_1_ = s_Failed_to_send_s_in_initiate_str_00067988[19];
      uStack_2814._0_1_ = s_Failed_to_send_s_in_initiate_str_00067988[20];
      uStack_2814._1_1_ = s_Failed_to_send_s_in_initiate_str_00067988[21];
      uStack_2814._2_1_ = s_Failed_to_send_s_in_initiate_str_00067988[22];
      uStack_2814._3_1_ = s_Failed_to_send_s_in_initiate_str_00067988[23];
      uStack_2810._0_1_ = s_Failed_to_send_s_in_initiate_str_00067988[24];
      uStack_2810._1_1_ = s_Failed_to_send_s_in_initiate_str_00067988[25];
      uStack_2810._2_1_ = s_Failed_to_send_s_in_initiate_str_00067988[26];
      uStack_2810._3_1_ = s_Failed_to_send_s_in_initiate_str_00067988[27];
      uStack_280c._0_1_ = s_Failed_to_send_s_in_initiate_str_00067988[28];
      uStack_280c._1_1_ = s_Failed_to_send_s_in_initiate_str_00067988[29];
      uStack_280c._2_1_ = s_Failed_to_send_s_in_initiate_str_00067988[30];
      uStack_280c._3_1_ = s_Failed_to_send_s_in_initiate_str_00067988[31];
      local_2808._0_1_ = s_Failed_to_send_s_in_initiate_str_00067988[32];
      local_2808._1_1_ = s_Failed_to_send_s_in_initiate_str_00067988[33];
      local_2808._2_1_ = s_Failed_to_send_s_in_initiate_str_00067988[34];
      local_2808._3_1_ = s_Failed_to_send_s_in_initiate_str_00067988[35];
      local_2804._0_1_ = (char)ram0x000679ac;
      _applog(7,&local_2828,0);
    }
LAB_00049666:
    iVar5 = 1;
    if (bVar16 <= bVar15) {
LAB_00049744:
      if ((opt_debug != 0) &&
         (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
        local_2828._0_1_ = s_Initiate_stratum_failed_00067c38[0];
        local_2828._1_1_ = s_Initiate_stratum_failed_00067c38[1];
        local_2828._2_1_ = s_Initiate_stratum_failed_00067c38[2];
        local_2828._3_1_ = s_Initiate_stratum_failed_00067c38[3];
        uStack_2824._0_1_ = s_Initiate_stratum_failed_00067c38[4];
        uStack_2824._1_1_ = s_Initiate_stratum_failed_00067c38[5];
        uStack_2824._2_1_ = s_Initiate_stratum_failed_00067c38[6];
        uStack_2824._3_1_ = s_Initiate_stratum_failed_00067c38[7];
        uStack_2820._0_1_ = s_Initiate_stratum_failed_00067c38[8];
        uStack_2820._1_1_ = s_Initiate_stratum_failed_00067c38[9];
        uStack_2820._2_1_ = s_Initiate_stratum_failed_00067c38[10];
        uStack_2820._3_1_ = s_Initiate_stratum_failed_00067c38[11];
        uStack_281c._0_1_ = s_Initiate_stratum_failed_00067c38[12];
        uStack_281c._1_1_ = s_Initiate_stratum_failed_00067c38[13];
        uStack_281c._2_1_ = s_Initiate_stratum_failed_00067c38[14];
        uStack_281c._3_1_ = s_Initiate_stratum_failed_00067c38[15];
        local_2818._0_1_ = s_Initiate_stratum_failed_00067c38[16];
        local_2818._1_1_ = s_Initiate_stratum_failed_00067c38[17];
        local_2818._2_1_ = s_Initiate_stratum_failed_00067c38[18];
        local_2818._3_1_ = s_Initiate_stratum_failed_00067c38[19];
        uStack_2814._0_1_ = s_Initiate_stratum_failed_00067c38[20];
        uStack_2814._1_1_ = s_Initiate_stratum_failed_00067c38[21];
        uStack_2814._2_1_ = s_Initiate_stratum_failed_00067c38[22];
        uStack_2814._3_1_ = s_Initiate_stratum_failed_00067c38[23];
        _applog(7,&local_2828,0);
      }
      if (iVar5 != 0) {
        suspend_stratum(param_1);
      }
      iVar5 = iVar14;
      if (iVar14 != 0) {
        iVar5 = 0;
LAB_0004978a:
        if ((*(int *)(iVar14 + 4) != -1) &&
           (iVar13 = *(int *)(iVar14 + 4) + -1, *(int *)(iVar14 + 4) = iVar13, iVar13 == 0)) {
          json_delete(iVar14);
        }
      }
      return iVar5;
    }
    while( true ) {
      iVar5 = pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x35));
      if (iVar5 == 0) {
        iVar5 = pthread_rwlock_wrlock((pthread_rwlock_t *)(param_1 + 0x3b));
      }
      else {
        piVar7 = __errno_location();
        snprintf((char *)&local_2828,0x800,"WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",*piVar7
                 ,"util.c",DAT_00049d04,0xcf5);
        _applog(3,&local_2828,1);
        _quit(1);
        iVar5 = pthread_rwlock_wrlock((pthread_rwlock_t *)(param_1 + 0x3b));
      }
      if (iVar5 != 0) {
        piVar7 = __errno_location();
        snprintf((char *)&local_2828,0x800,"WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d",
                 *piVar7,"util.c",DAT_00049d04,0xcf5);
        _applog(3,&local_2828,1);
        _quit(1);
      }
      free((void *)param_1[0x9f]);
      free((void *)param_1[0x99]);
      param_1[0x99] = 0;
      param_1[0x9f] = 0;
      iVar5 = pthread_rwlock_unlock((pthread_rwlock_t *)(param_1 + 0x3b));
      if (iVar5 != 0) {
        piVar7 = __errno_location();
        snprintf((char *)&local_2828,0x800,"WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",
                 *piVar7,"util.c",DAT_00049d04,0xcf9);
        _applog(3,&local_2828,1);
        _quit(1);
      }
      iVar5 = pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x35));
      if (iVar5 != 0) {
        piVar7 = __errno_location();
        snprintf((char *)&local_2828,0x800,"WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",
                 *piVar7,"util.c",DAT_00049d04,0xcf9);
        _applog(3,&local_2828,1);
        _quit(1);
      }
      (*selective_yield)();
      if ((opt_debug != 0) &&
         (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
        local_2828._0_1_ = s_Failed_to_resume_stratum__trying_00067c10[0];
        local_2828._1_1_ = s_Failed_to_resume_stratum__trying_00067c10[1];
        local_2828._2_1_ = s_Failed_to_resume_stratum__trying_00067c10[2];
        local_2828._3_1_ = s_Failed_to_resume_stratum__trying_00067c10[3];
        uStack_2824._0_1_ = s_Failed_to_resume_stratum__trying_00067c10[4];
        uStack_2824._1_1_ = s_Failed_to_resume_stratum__trying_00067c10[5];
        uStack_2824._2_1_ = s_Failed_to_resume_stratum__trying_00067c10[6];
        uStack_2824._3_1_ = s_Failed_to_resume_stratum__trying_00067c10[7];
        uStack_2820._0_1_ = s_Failed_to_resume_stratum__trying_00067c10[8];
        uStack_2820._1_1_ = s_Failed_to_resume_stratum__trying_00067c10[9];
        uStack_2820._2_1_ = s_Failed_to_resume_stratum__trying_00067c10[10];
        uStack_2820._3_1_ = s_Failed_to_resume_stratum__trying_00067c10[11];
        uStack_281c._0_1_ = s_Failed_to_resume_stratum__trying_00067c10[12];
        uStack_281c._1_1_ = s_Failed_to_resume_stratum__trying_00067c10[13];
        uStack_281c._2_1_ = s_Failed_to_resume_stratum__trying_00067c10[14];
        uStack_281c._3_1_ = s_Failed_to_resume_stratum__trying_00067c10[15];
        local_2818._0_1_ = s_Failed_to_resume_stratum__trying_00067c10[16];
        local_2818._1_1_ = s_Failed_to_resume_stratum__trying_00067c10[17];
        local_2818._2_1_ = s_Failed_to_resume_stratum__trying_00067c10[18];
        local_2818._3_1_ = s_Failed_to_resume_stratum__trying_00067c10[19];
        uStack_2814._0_1_ = s_Failed_to_resume_stratum__trying_00067c10[20];
        uStack_2814._1_1_ = s_Failed_to_resume_stratum__trying_00067c10[21];
        uStack_2814._2_1_ = s_Failed_to_resume_stratum__trying_00067c10[22];
        uStack_2814._3_1_ = s_Failed_to_resume_stratum__trying_00067c10[23];
        uStack_2810._0_1_ = s_Failed_to_resume_stratum__trying_00067c10[24];
        uStack_2810._1_1_ = s_Failed_to_resume_stratum__trying_00067c10[25];
        uStack_2810._2_1_ = s_Failed_to_resume_stratum__trying_00067c10[26];
        uStack_2810._3_1_ = s_Failed_to_resume_stratum__trying_00067c10[27];
        uStack_280c._0_1_ = s_Failed_to_resume_stratum__trying_00067c10[28];
        uStack_280c._1_1_ = s_Failed_to_resume_stratum__trying_00067c10[29];
        uStack_280c._2_1_ = s_Failed_to_resume_stratum__trying_00067c10[30];
        uStack_280c._3_1_ = s_Failed_to_resume_stratum__trying_00067c10[31];
        local_2808._0_1_ = s_Failed_to_resume_stratum__trying_00067c10[32];
        local_2808._1_1_ = s_Failed_to_resume_stratum__trying_00067c10[33];
        local_2808._2_1_ = s_Failed_to_resume_stratum__trying_00067c10[34];
        local_2808._3_1_ = s_Failed_to_resume_stratum__trying_00067c10[35];
        local_2804._0_1_ = s_Failed_to_resume_stratum__trying_00067c10[36];
        local_2804._1_1_ = s_Failed_to_resume_stratum__trying_00067c10[37];
        local_2804._2_1_ = s_Failed_to_resume_stratum__trying_00067c10[38];
        local_2804._3_1_ = s_Failed_to_resume_stratum__trying_00067c10[39];
        _applog(7,&local_2828,0);
      }
      if (((iVar14 != 0) && (*(int *)(iVar14 + 4) != -1)) &&
         (iVar5 = *(int *)(iVar14 + 4) + -1, *(int *)(iVar14 + 4) = iVar5, iVar5 == 0)) {
        json_delete(iVar14);
      }
      bVar15 = true;
      iVar5 = setup_stratum_socket(param_1);
      if (iVar5 != 0) break;
LAB_0004973e:
      if (bVar16 <= bVar15) goto LAB_00049744;
    }
  } while( true );
}

