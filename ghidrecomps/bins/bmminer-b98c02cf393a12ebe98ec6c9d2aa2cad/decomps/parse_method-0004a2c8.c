
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint parse_method(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  void *__ptr;
  char *pcVar6;
  undefined4 uVar7;
  uint uVar8;
  size_t sVar9;
  int iVar10;
  uint unaff_r6;
  uint uVar11;
  double dVar12;
  double dVar13;
  undefined8 in_stack_ffffdeb0;
  undefined8 uVar14;
  undefined4 local_2134 [23];
  undefined auStack_20d8 [160];
  undefined4 local_2038;
  undefined4 uStack_2034;
  undefined4 uStack_2030;
  undefined4 uStack_202c;
  undefined4 local_2028;
  undefined4 uStack_2024;
  undefined4 uStack_2020;
  undefined4 uStack_201c;
  undefined4 local_2018;
  undefined4 uStack_2014;
  undefined4 uStack_2010;
  undefined2 uStack_200c;
  undefined local_200a;
  
  uVar7 = (undefined4)((ulonglong)in_stack_ffffdeb0 >> 0x20);
  if (param_2 == 0) {
    return 0;
  }
  iVar2 = json_loads(param_2,0,local_2134);
  if (iVar2 == 0) {
    if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 6)) {
      return 0;
    }
    snprintf((char *)&local_2038,0x800,"JSON decode failed(%d): %s",local_2134[0],auStack_20d8);
    _applog(6,&local_2038,0);
    return 0;
  }
  iVar3 = json_object_get(iVar2,"method");
  if (iVar3 == 0) goto LAB_0004a3f0;
  piVar4 = (int *)json_object_get(iVar2,"error");
  piVar5 = (int *)json_object_get(iVar2,"params");
  if ((piVar4 != (int *)0x0) && (*piVar4 != 7)) {
    __ptr = (void *)json_dumps(piVar4,3);
    if ((use_syslog != '\0') || ((opt_log_output != '\0' || (5 < opt_log_level)))) {
      snprintf((char *)&local_2038,0x800,"JSON-RPC method decode failed: %s",__ptr);
      _applog(6,&local_2038,0);
    }
    unaff_r6 = 0;
    free(__ptr);
    goto LAB_0004a37e;
  }
  pcVar6 = (char *)json_string_value(iVar3);
  if (pcVar6 == (char *)0x0) {
    unaff_r6 = 0;
    goto LAB_0004a37e;
  }
  iVar3 = strncasecmp(pcVar6,"mining.multi_version",0x14);
  if (iVar3 == 0) {
    *(undefined *)(param_1 + 0xa1) = 1;
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (5 < opt_log_level)) {
      local_2038._0_1_ = s_Pool_support_multi_version_00067d84[0];
      local_2038._1_1_ = s_Pool_support_multi_version_00067d84[1];
      local_2038._2_1_ = s_Pool_support_multi_version_00067d84[2];
      local_2038._3_1_ = s_Pool_support_multi_version_00067d84[3];
      uStack_2034._0_1_ = s_Pool_support_multi_version_00067d84[4];
      uStack_2034._1_1_ = s_Pool_support_multi_version_00067d84[5];
      uStack_2034._2_1_ = s_Pool_support_multi_version_00067d84[6];
      uStack_2034._3_1_ = s_Pool_support_multi_version_00067d84[7];
      uStack_2030._0_1_ = s_Pool_support_multi_version_00067d84[8];
      uStack_2030._1_1_ = s_Pool_support_multi_version_00067d84[9];
      uStack_2030._2_1_ = s_Pool_support_multi_version_00067d84[10];
      uStack_2030._3_1_ = s_Pool_support_multi_version_00067d84[11];
      uStack_202c._0_1_ = s_Pool_support_multi_version_00067d84[12];
      uStack_202c._1_1_ = s_Pool_support_multi_version_00067d84[13];
      uStack_202c._2_1_ = s_Pool_support_multi_version_00067d84[14];
      uStack_202c._3_1_ = s_Pool_support_multi_version_00067d84[15];
      local_2028._0_1_ = s_Pool_support_multi_version_00067d84[16];
      local_2028._1_1_ = s_Pool_support_multi_version_00067d84[17];
      local_2028._2_1_ = s_Pool_support_multi_version_00067d84[18];
      local_2028._3_1_ = s_Pool_support_multi_version_00067d84[19];
      uStack_2024._0_1_ = s_Pool_support_multi_version_00067d84[20];
      uStack_2024._1_1_ = s_Pool_support_multi_version_00067d84[21];
      uStack_2024._2_1_ = s_Pool_support_multi_version_00067d84[22];
      uStack_2024._3_1_ = s_Pool_support_multi_version_00067d84[23];
      uStack_2020._0_3_ = (undefined3)ram0x00067d9c;
      _applog(6,&local_2038,0);
    }
    param_1 = param_1 + 0xa3;
    uVar11 = 0;
    while( true ) {
      uVar8 = json_array_size(piVar5);
      if (uVar8 <= uVar11) break;
      json_array_get(piVar5,uVar11);
      uVar7 = json_integer_value();
      param_1 = param_1 + 1;
      *param_1 = uVar7;
      uVar11 = uVar11 + 1;
    }
    goto LAB_0004a37e;
  }
  iVar3 = strncasecmp(pcVar6,"mining.notify",0xd);
  if (iVar3 == 0) {
    unaff_r6 = parse_notify(param_1,piVar5);
    if (unaff_r6 != 0) {
      *(undefined *)((int)param_1 + 0x283) = 1;
      goto LAB_0004a37e;
    }
  }
  else {
    iVar3 = strncasecmp(pcVar6,"mining.set_version_mask",0x17);
    if (iVar3 != 0) {
      iVar3 = strncasecmp(pcVar6,"mining.set_difficulty",0x15);
      if (iVar3 == 0) {
        json_array_get(piVar5,0);
        dVar12 = (double)json_number_value();
        if (dVar12 != 0.0) {
          iVar3 = pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x35));
          if (iVar3 != 0) {
            _mutex_lock_part_1_constprop_16(DAT_0004ab78,0x895);
          }
          iVar3 = pthread_rwlock_wrlock((pthread_rwlock_t *)(param_1 + 0x3b));
          if (iVar3 != 0) {
            piVar4 = __errno_location();
            uVar7 = DAT_0004ab78;
            snprintf((char *)&local_2038,0x800,"WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d",
                     *piVar4,"util.c",DAT_0004ab78,0x895);
            _applog(3,&local_2038,1);
            _quit(1);
          }
          dVar13 = *(double *)(param_1 + 0x1c6);
          if (dVar13 == 0.0 || dVar13 < 0.0 != NAN(dVar13)) {
            dVar13 = *(double *)(param_1 + 0x1c8);
            *(double *)(param_1 + 0x1c8) = dVar12;
          }
          *(double *)(param_1 + 0x1c6) = dVar12;
          iVar3 = pthread_rwlock_unlock((pthread_rwlock_t *)(param_1 + 0x3b));
          if (iVar3 != 0) {
            piVar4 = __errno_location();
            uVar7 = DAT_0004ab78;
            snprintf((char *)&local_2038,0x800,"WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",
                     *piVar4,"util.c",DAT_0004ab78,0x8a2);
            _applog(3,&local_2038,1);
            _quit(1);
          }
          iVar3 = pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x35));
          if (iVar3 != 0) {
            piVar4 = __errno_location();
            uVar7 = DAT_0004ab78;
            snprintf((char *)&local_2038,0x800,"WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",
                     *piVar4,"util.c",DAT_0004ab78,0x8a2);
            _applog(3,&local_2038,1);
            _quit(1);
          }
          (*selective_yield)();
          if (dVar12 == dVar13) {
            unaff_r6 = (uint)opt_debug;
            if ((unaff_r6 != 0) &&
               (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
              snprintf((char *)&local_2038,0x800,"Pool %d difficulty set to %f",*param_1,dVar12);
              _applog(7,&local_2038,0);
              goto LAB_0004a37e;
            }
          }
          else if (dVar12 == (double)(longlong)(int)(longlong)dVar12) {
            if (((use_syslog != '\0') || (opt_log_output != '\0')) || (4 < opt_log_level)) {
              uVar14 = CONCAT44(uVar7,(int)(longlong)dVar12);
              uVar7 = *param_1;
              pcVar6 = "Pool %d difficulty changed to %d";
LAB_0004a6ce:
              unaff_r6 = 1;
              snprintf((char *)&local_2038,0x800,pcVar6,uVar7,uVar14);
              _applog(5,&local_2038,0);
              goto LAB_0004a37e;
            }
          }
          else if (((use_syslog != '\0') || (opt_log_output != '\0')) || (4 < opt_log_level)) {
            snprintf((char *)&local_2038,0x800,"Pool %d difficulty changed to %.1f",*param_1,dVar12)
            ;
            unaff_r6 = 1;
            _applog(5,&local_2038,0);
            goto LAB_0004a37e;
          }
LAB_0004a8b0:
          unaff_r6 = 1;
          goto LAB_0004a37e;
        }
      }
      else {
        iVar3 = strncasecmp(pcVar6,"mining.set_extranonce",0x15);
        uVar1 = DAT_0004a904;
        if (iVar3 == 0) {
          pcVar6 = (char *)json_array_string(piVar5,0);
          unaff_r6 = _valid_hex_constprop_10(pcVar6,uVar1,0x8c1);
          if (unaff_r6 != 0) {
            json_array_get(piVar5,1);
            iVar3 = json_integer_value();
            if (iVar3 == 0) {
              if (((use_syslog != '\0') || (opt_log_output != '\0')) || (5 < opt_log_level)) {
                local_2038._0_1_ = s_Failed_to_get_valid_n2size_in_pa_00067e68[0];
                local_2038._1_1_ = s_Failed_to_get_valid_n2size_in_pa_00067e68[1];
                local_2038._2_1_ = s_Failed_to_get_valid_n2size_in_pa_00067e68[2];
                local_2038._3_1_ = s_Failed_to_get_valid_n2size_in_pa_00067e68[3];
                uStack_2034._0_1_ = s_Failed_to_get_valid_n2size_in_pa_00067e68[4];
                uStack_2034._1_1_ = s_Failed_to_get_valid_n2size_in_pa_00067e68[5];
                uStack_2034._2_1_ = s_Failed_to_get_valid_n2size_in_pa_00067e68[6];
                uStack_2034._3_1_ = s_Failed_to_get_valid_n2size_in_pa_00067e68[7];
                uStack_2030._0_1_ = s_Failed_to_get_valid_n2size_in_pa_00067e68[8];
                uStack_2030._1_1_ = s_Failed_to_get_valid_n2size_in_pa_00067e68[9];
                uStack_2030._2_1_ = s_Failed_to_get_valid_n2size_in_pa_00067e68[10];
                uStack_2030._3_1_ = s_Failed_to_get_valid_n2size_in_pa_00067e68[11];
                uStack_202c._0_1_ = s_Failed_to_get_valid_n2size_in_pa_00067e68[12];
                uStack_202c._1_1_ = s_Failed_to_get_valid_n2size_in_pa_00067e68[13];
                uStack_202c._2_1_ = s_Failed_to_get_valid_n2size_in_pa_00067e68[14];
                uStack_202c._3_1_ = s_Failed_to_get_valid_n2size_in_pa_00067e68[15];
                local_2028._0_1_ = s_Failed_to_get_valid_n2size_in_pa_00067e68[16];
                local_2028._1_1_ = s_Failed_to_get_valid_n2size_in_pa_00067e68[17];
                local_2028._2_1_ = s_Failed_to_get_valid_n2size_in_pa_00067e68[18];
                local_2028._3_1_ = s_Failed_to_get_valid_n2size_in_pa_00067e68[19];
                uStack_2024._0_1_ = s_Failed_to_get_valid_n2size_in_pa_00067e68[20];
                uStack_2024._1_1_ = s_Failed_to_get_valid_n2size_in_pa_00067e68[21];
                uStack_2024._2_1_ = s_Failed_to_get_valid_n2size_in_pa_00067e68[22];
                uStack_2024._3_1_ = s_Failed_to_get_valid_n2size_in_pa_00067e68[23];
                uStack_2020._0_1_ = s_Failed_to_get_valid_n2size_in_pa_00067e68[24];
                uStack_2020._1_1_ = s_Failed_to_get_valid_n2size_in_pa_00067e68[25];
                uStack_2020._2_1_ = s_Failed_to_get_valid_n2size_in_pa_00067e68[26];
                uStack_2020._3_1_ = s_Failed_to_get_valid_n2size_in_pa_00067e68[27];
                uStack_201c._0_1_ = s_Failed_to_get_valid_n2size_in_pa_00067e68[28];
                uStack_201c._1_1_ = s_Failed_to_get_valid_n2size_in_pa_00067e68[29];
                uStack_201c._2_1_ = s_Failed_to_get_valid_n2size_in_pa_00067e68[30];
                uStack_201c._3_1_ = s_Failed_to_get_valid_n2size_in_pa_00067e68[31];
                local_2018._0_1_ = s_Failed_to_get_valid_n2size_in_pa_00067e68[32];
                local_2018._1_1_ = s_Failed_to_get_valid_n2size_in_pa_00067e68[33];
                local_2018._2_1_ = s_Failed_to_get_valid_n2size_in_pa_00067e68[34];
                local_2018._3_1_ = s_Failed_to_get_valid_n2size_in_pa_00067e68[35];
                uStack_2014._0_1_ = s_Failed_to_get_valid_n2size_in_pa_00067e68[36];
                uStack_2014._1_1_ = s_Failed_to_get_valid_n2size_in_pa_00067e68[37];
                uStack_2014._2_1_ = s_Failed_to_get_valid_n2size_in_pa_00067e68[38];
                uStack_2014._3_1_ = s_Failed_to_get_valid_n2size_in_pa_00067e68[39];
                uStack_2010._0_1_ = s_Failed_to_get_valid_n2size_in_pa_00067e68[40];
                uStack_2010._1_1_ = s_Failed_to_get_valid_n2size_in_pa_00067e68[41];
                uStack_2010._2_1_ = s_Failed_to_get_valid_n2size_in_pa_00067e68[42];
                uStack_2010._3_1_ = s_Failed_to_get_valid_n2size_in_pa_00067e68[43];
                uStack_200c = (undefined2)ram0x00067e94;
                local_200a = (undefined)((uint)ram0x00067e94 >> 0x10);
                _applog(6,&local_2038,0);
              }
              unaff_r6 = 0;
              free(pcVar6);
            }
            else {
              iVar10 = pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x35));
              if (iVar10 != 0) {
                _mutex_lock_part_1_constprop_16(uVar1,0x8cd);
              }
              iVar10 = pthread_rwlock_wrlock((pthread_rwlock_t *)(param_1 + 0x3b));
              if (iVar10 != 0) {
                piVar4 = __errno_location();
                snprintf((char *)&local_2038,0x800,
                         "WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d",*piVar4,"util.c",uVar1,
                         0x8cd);
                _applog(3,&local_2038,1);
                _quit(1);
              }
              free((void *)param_1[0x99]);
              param_1[0x99] = pcVar6;
              sVar9 = strlen(pcVar6);
              param_1[0x187] = sVar9 >> 1;
              free((void *)param_1[0x9a]);
              iVar10 = _cgcalloc(param_1[0x187],1,"util.c",DAT_0004ab74,0x8d2);
              param_1[0x9a] = iVar10;
              if (iVar10 == 0) {
                snprintf((char *)&local_2038,0x800,"Failed to calloc pool->nonce1bin in %s %s():%d",
                         "util.c",uVar1,0x8d4);
                _applog(3,&local_2038,1);
                _quit(1);
              }
              hex2bin(param_1[0x9a],param_1[0x99],param_1[0x187]);
              param_1[0x9e] = iVar3;
              iVar3 = pthread_rwlock_unlock((pthread_rwlock_t *)(param_1 + 0x3b));
              if (iVar3 != 0) {
                piVar4 = __errno_location();
                snprintf((char *)&local_2038,0x800,
                         "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar4,"util.c",uVar1
                         ,0x8d7);
                _applog(3,&local_2038,1);
                _quit(1);
              }
              _mutex_unlock_noyield_constprop_15
                        ((pthread_mutex_t *)(param_1 + 0x35),DAT_0004ab74,0x8d7);
              (*selective_yield)();
              if (((use_syslog != '\0') || (opt_log_output != '\0')) || (4 < opt_log_level)) {
                snprintf((char *)&local_2038,0x800,"Pool %d extranonce change requested",*param_1);
                _applog(5,&local_2038,0);
              }
              opt_work_update = 1;
            }
            goto LAB_0004a37e;
          }
          if (((use_syslog != '\0') || (opt_log_output != '\0')) || (5 < opt_log_level)) {
            local_2038._0_1_ = s_Failed_to_get_valid_nonce1_in_pa_00067e38[0];
            local_2038._1_1_ = s_Failed_to_get_valid_nonce1_in_pa_00067e38[1];
            local_2038._2_1_ = s_Failed_to_get_valid_nonce1_in_pa_00067e38[2];
            local_2038._3_1_ = s_Failed_to_get_valid_nonce1_in_pa_00067e38[3];
            uStack_2034._0_1_ = s_Failed_to_get_valid_nonce1_in_pa_00067e38[4];
            uStack_2034._1_1_ = s_Failed_to_get_valid_nonce1_in_pa_00067e38[5];
            uStack_2034._2_1_ = s_Failed_to_get_valid_nonce1_in_pa_00067e38[6];
            uStack_2034._3_1_ = s_Failed_to_get_valid_nonce1_in_pa_00067e38[7];
            uStack_2030._0_1_ = s_Failed_to_get_valid_nonce1_in_pa_00067e38[8];
            uStack_2030._1_1_ = s_Failed_to_get_valid_nonce1_in_pa_00067e38[9];
            uStack_2030._2_1_ = s_Failed_to_get_valid_nonce1_in_pa_00067e38[10];
            uStack_2030._3_1_ = s_Failed_to_get_valid_nonce1_in_pa_00067e38[11];
            uStack_202c._0_1_ = s_Failed_to_get_valid_nonce1_in_pa_00067e38[12];
            uStack_202c._1_1_ = s_Failed_to_get_valid_nonce1_in_pa_00067e38[13];
            uStack_202c._2_1_ = s_Failed_to_get_valid_nonce1_in_pa_00067e38[14];
            uStack_202c._3_1_ = s_Failed_to_get_valid_nonce1_in_pa_00067e38[15];
            local_2028._0_1_ = s_Failed_to_get_valid_nonce1_in_pa_00067e38[16];
            local_2028._1_1_ = s_Failed_to_get_valid_nonce1_in_pa_00067e38[17];
            local_2028._2_1_ = s_Failed_to_get_valid_nonce1_in_pa_00067e38[18];
            local_2028._3_1_ = s_Failed_to_get_valid_nonce1_in_pa_00067e38[19];
            uStack_2024._0_1_ = s_Failed_to_get_valid_nonce1_in_pa_00067e38[20];
            uStack_2024._1_1_ = s_Failed_to_get_valid_nonce1_in_pa_00067e38[21];
            uStack_2024._2_1_ = s_Failed_to_get_valid_nonce1_in_pa_00067e38[22];
            uStack_2024._3_1_ = s_Failed_to_get_valid_nonce1_in_pa_00067e38[23];
            uStack_2020._0_1_ = s_Failed_to_get_valid_nonce1_in_pa_00067e38[24];
            uStack_2020._1_1_ = s_Failed_to_get_valid_nonce1_in_pa_00067e38[25];
            uStack_2020._2_1_ = s_Failed_to_get_valid_nonce1_in_pa_00067e38[26];
            uStack_2020._3_1_ = s_Failed_to_get_valid_nonce1_in_pa_00067e38[27];
            uStack_201c._0_1_ = s_Failed_to_get_valid_nonce1_in_pa_00067e38[28];
            uStack_201c._1_1_ = s_Failed_to_get_valid_nonce1_in_pa_00067e38[29];
            uStack_201c._2_1_ = s_Failed_to_get_valid_nonce1_in_pa_00067e38[30];
            uStack_201c._3_1_ = s_Failed_to_get_valid_nonce1_in_pa_00067e38[31];
            local_2018._0_1_ = s_Failed_to_get_valid_nonce1_in_pa_00067e38[32];
            local_2018._1_1_ = s_Failed_to_get_valid_nonce1_in_pa_00067e38[33];
            local_2018._2_1_ = s_Failed_to_get_valid_nonce1_in_pa_00067e38[34];
            local_2018._3_1_ = s_Failed_to_get_valid_nonce1_in_pa_00067e38[35];
            uStack_2014._0_1_ = s_Failed_to_get_valid_nonce1_in_pa_00067e38[36];
            uStack_2014._1_1_ = s_Failed_to_get_valid_nonce1_in_pa_00067e38[37];
            uStack_2014._2_1_ = s_Failed_to_get_valid_nonce1_in_pa_00067e38[38];
            uStack_2014._3_1_ = s_Failed_to_get_valid_nonce1_in_pa_00067e38[39];
            uStack_2010._0_1_ = s_Failed_to_get_valid_nonce1_in_pa_00067e38[40];
            uStack_2010._1_1_ = s_Failed_to_get_valid_nonce1_in_pa_00067e38[41];
            uStack_2010._2_1_ = s_Failed_to_get_valid_nonce1_in_pa_00067e38[42];
            uStack_2010._3_1_ = s_Failed_to_get_valid_nonce1_in_pa_00067e38[43];
            uStack_200c = (undefined2)ram0x00067e64;
            local_200a = (undefined)((uint)ram0x00067e64 >> 0x10);
            _applog(6,&local_2038,0);
            goto LAB_0004a37e;
          }
        }
        else {
          iVar3 = strncasecmp(pcVar6,"client.reconnect",0x10);
          if (iVar3 == 0) {
            unaff_r6 = parse_reconnect(param_1,piVar5);
            goto LAB_0004a37e;
          }
          iVar3 = strncasecmp(pcVar6,"client.get_version",0x12);
          if (iVar3 == 0) {
            iVar3 = json_object_get(iVar2,&DAT_0005e278);
            if (iVar3 != 0) {
              json_object_get(iVar2,&DAT_0005e278);
              uVar7 = json_integer_value();
              pcVar6 = "{\"id\": %d, \"result\": \"bmminer/2.0.0\", \"error\": null}";
LAB_0004a5b0:
              sprintf((char *)&local_2038,pcVar6,uVar7);
              sVar9 = strlen((char *)&local_2038);
              unaff_r6 = stratum_send(param_1,&local_2038,sVar9);
              goto LAB_0004a37e;
            }
          }
          else {
            iVar3 = strncasecmp(pcVar6,"client.show_message",0x13);
            if (iVar3 == 0) {
              if ((piVar5 != (int *)0x0) && (*piVar5 == 1)) {
                json_array_get(piVar5,0);
                iVar3 = json_string_value();
                if (iVar3 != 0) {
                  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (4 < opt_log_level)) {
                    uVar14 = CONCAT44(uVar7,iVar3);
                    pcVar6 = "Pool %d message: %s";
                    uVar7 = *param_1;
                    goto LAB_0004a6ce;
                  }
                  goto LAB_0004a8b0;
                }
              }
            }
            else {
              iVar3 = strncasecmp(pcVar6,"mining.ping",0xb);
              if (iVar3 == 0) {
                if (((use_syslog != '\0') || (opt_log_output != '\0')) || (5 < opt_log_level)) {
                  snprintf((char *)&local_2038,0x800,"Pool %d ping",*param_1);
                  _applog(6,&local_2038,0);
                }
                unaff_r6 = json_object_get(iVar2,&DAT_0005e278);
                if (unaff_r6 == 0) goto LAB_0004a37e;
                json_object_get(iVar2,&DAT_0005e278);
                uVar7 = json_integer_value();
                pcVar6 = "{\"id\": %d, \"result\": \"pong\", \"error\": null}";
                goto LAB_0004a5b0;
              }
            }
          }
        }
      }
LAB_0004a3f0:
      unaff_r6 = 0;
      goto LAB_0004a37e;
    }
    json_array_get(piVar5,0);
    unaff_r6 = 1;
    uVar7 = json_string_value();
    process_version_mask(param_1,uVar7);
  }
  *(char *)((int)param_1 + 0x283) = (char)unaff_r6;
LAB_0004a37e:
  if (*(int *)(iVar2 + 4) == -1) {
    return unaff_r6;
  }
  iVar3 = *(int *)(iVar2 + 4) + -1;
  *(int *)(iVar2 + 4) = iVar3;
  if (iVar3 == 0) {
    json_delete(iVar2);
    return unaff_r6;
  }
  return unaff_r6;
}

