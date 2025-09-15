
uint parse_method(undefined4 *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  void *__ptr;
  char *__s1;
  undefined4 uVar5;
  uint uVar6;
  size_t sVar7;
  int iVar8;
  char *pcVar9;
  uint unaff_r6;
  uint uVar10;
  double dVar11;
  double dVar12;
  undefined8 in_stack_ffffdeb0;
  undefined8 uVar13;
  undefined4 local_2134 [23];
  undefined1 auStack_20d8 [160];
  char local_2038 [24];
  undefined4 uStack_2020;
  char acStack_201c [16];
  undefined2 uStack_200c;
  undefined1 local_200a;
  undefined4 extraout_s1;
  
  pcVar9 = (char *)((ulonglong)in_stack_ffffdeb0 >> 0x20);
  if (param_2 == 0) {
    return 0;
  }
  iVar1 = json_loads(param_2,0,local_2134);
  if (iVar1 == 0) {
    if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 6)) {
      return 0;
    }
    snprintf(local_2038,0x800,"JSON decode failed(%d): %s",local_2134[0],auStack_20d8);
    _applog(6,local_2038,0);
    return 0;
  }
  iVar2 = json_object_get(iVar1,"method");
  if (iVar2 == 0) goto LAB_0004a3f0;
  piVar3 = (int *)json_object_get(iVar1,"error");
  piVar4 = (int *)json_object_get(iVar1,"params");
  if ((piVar3 != (int *)0x0) && (*piVar3 != 7)) {
    __ptr = (void *)json_dumps(piVar3,3);
    if ((use_syslog != '\0') || ((opt_log_output != '\0' || (5 < opt_log_level)))) {
      snprintf(local_2038,0x800,"JSON-RPC method decode failed: %s",__ptr);
      _applog(6,local_2038,0);
    }
    unaff_r6 = 0;
    free(__ptr);
    goto LAB_0004a37e;
  }
  __s1 = (char *)json_string_value(iVar2);
  if (__s1 == (char *)0x0) {
    unaff_r6 = 0;
    goto LAB_0004a37e;
  }
  iVar2 = strncasecmp(__s1,"mining.multi_version",0x14);
  if (iVar2 == 0) {
    *(undefined1 *)(param_1 + 0xa1) = 1;
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (5 < opt_log_level)) {
      builtin_strncpy(local_2038,"Pool support multi versi",0x18);
      uStack_2020._0_3_ = 0x6e6f;
      _applog(6,local_2038,0);
    }
    param_1 = param_1 + 0xa3;
    uVar10 = 0;
    while( true ) {
      uVar6 = json_array_size(piVar4);
      if (uVar6 <= uVar10) break;
      json_array_get(piVar4,uVar10);
      uVar5 = json_integer_value();
      param_1 = param_1 + 1;
      *param_1 = uVar5;
      uVar10 = uVar10 + 1;
    }
    goto LAB_0004a37e;
  }
  iVar2 = strncasecmp(__s1,"mining.notify",0xd);
  if (iVar2 == 0) {
    unaff_r6 = parse_notify(param_1,piVar4);
    if (unaff_r6 != 0) {
      *(undefined1 *)((int)param_1 + 0x283) = 1;
      goto LAB_0004a37e;
    }
  }
  else {
    iVar2 = strncasecmp(__s1,"mining.set_version_mask",0x17);
    if (iVar2 != 0) {
      iVar2 = strncasecmp(__s1,"mining.set_difficulty",0x15);
      if (iVar2 == 0) {
        json_array_get(piVar4,0);
        uVar5 = json_number_value();
        dVar11 = (double)CONCAT44(extraout_s1,uVar5);
        if (dVar11 != 0.0) {
          iVar2 = pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x35));
          if (iVar2 != 0) {
            _mutex_lock_part_1_constprop_16("parse_diff",0x895);
          }
          iVar2 = pthread_rwlock_wrlock((pthread_rwlock_t *)(param_1 + 0x3b));
          if (iVar2 != 0) {
            piVar3 = __errno_location();
            pcVar9 = "parse_diff";
            snprintf(local_2038,0x800,"WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d",*piVar3,
                     "util.c","parse_diff",0x895);
            _applog(3,local_2038,1);
            _quit(1);
          }
          dVar12 = *(double *)(param_1 + 0x1c6);
          if (dVar12 <= 0.0) {
            dVar12 = *(double *)(param_1 + 0x1c8);
            *(double *)(param_1 + 0x1c8) = dVar11;
          }
          *(double *)(param_1 + 0x1c6) = dVar11;
          iVar2 = pthread_rwlock_unlock((pthread_rwlock_t *)(param_1 + 0x3b));
          if (iVar2 != 0) {
            piVar3 = __errno_location();
            pcVar9 = "parse_diff";
            snprintf(local_2038,0x800,"WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar3,
                     "util.c","parse_diff",0x8a2);
            _applog(3,local_2038,1);
            _quit(1);
          }
          iVar2 = pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x35));
          if (iVar2 != 0) {
            piVar3 = __errno_location();
            pcVar9 = "parse_diff";
            snprintf(local_2038,0x800,"WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar3,
                     "util.c","parse_diff",0x8a2);
            _applog(3,local_2038,1);
            _quit(1);
          }
          (*selective_yield)();
          if (dVar11 == dVar12) {
            unaff_r6 = (uint)opt_debug;
            if ((unaff_r6 != 0) &&
               (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
              snprintf(local_2038,0x800,"Pool %d difficulty set to %f",*param_1,dVar11);
              _applog(7,local_2038,0);
              goto LAB_0004a37e;
            }
          }
          else if (dVar11 == (double)(longlong)(int)(longlong)dVar11) {
            if (((use_syslog != '\0') || (opt_log_output != '\0')) || (4 < opt_log_level)) {
              uVar13 = CONCAT44(pcVar9,(int)(longlong)dVar11);
              uVar5 = *param_1;
              pcVar9 = "Pool %d difficulty changed to %d";
LAB_0004a6ce:
              unaff_r6 = 1;
              snprintf(local_2038,0x800,pcVar9,uVar5,uVar13);
              _applog(5,local_2038,0);
              goto LAB_0004a37e;
            }
          }
          else if (((use_syslog != '\0') || (opt_log_output != '\0')) || (4 < opt_log_level)) {
            snprintf(local_2038,0x800,"Pool %d difficulty changed to %.1f",*param_1,dVar11);
            unaff_r6 = 1;
            _applog(5,local_2038,0);
            goto LAB_0004a37e;
          }
LAB_0004a8b0:
          unaff_r6 = 1;
          goto LAB_0004a37e;
        }
      }
      else {
        iVar2 = strncasecmp(__s1,"mining.set_extranonce",0x15);
        if (iVar2 == 0) {
          pcVar9 = (char *)json_array_string(piVar4,0);
          unaff_r6 = _valid_hex_constprop_10(pcVar9,"parse_extranonce",0x8c1);
          if (unaff_r6 != 0) {
            json_array_get(piVar4,1);
            iVar2 = json_integer_value();
            if (iVar2 == 0) {
              if (((use_syslog != '\0') || (opt_log_output != '\0')) || (5 < opt_log_level)) {
                builtin_strncpy(local_2038,"Failed to get valid n2si",0x18);
                uStack_2020._0_1_ = 'z';
                uStack_2020._1_1_ = 'e';
                uStack_2020._2_1_ = ' ';
                uStack_2020._3_1_ = 'i';
                builtin_strncpy(acStack_201c,"n parse_extranon",0x10);
                uStack_200c = 0x6563;
                local_200a = 0;
                _applog(6,local_2038,0);
              }
              unaff_r6 = 0;
              free(pcVar9);
            }
            else {
              iVar8 = pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x35));
              if (iVar8 != 0) {
                _mutex_lock_part_1_constprop_16("parse_extranonce",0x8cd);
              }
              iVar8 = pthread_rwlock_wrlock((pthread_rwlock_t *)(param_1 + 0x3b));
              if (iVar8 != 0) {
                piVar3 = __errno_location();
                snprintf(local_2038,0x800,"WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d",*piVar3
                         ,"util.c","parse_extranonce",0x8cd);
                _applog(3,local_2038,1);
                _quit(1);
              }
              free((void *)param_1[0x99]);
              param_1[0x99] = pcVar9;
              sVar7 = strlen(pcVar9);
              param_1[0x187] = sVar7 >> 1;
              free((void *)param_1[0x9a]);
              iVar8 = _cgcalloc(param_1[0x187],1,"util.c","parse_extranonce",0x8d2);
              param_1[0x9a] = iVar8;
              if (iVar8 == 0) {
                snprintf(local_2038,0x800,"Failed to calloc pool->nonce1bin in %s %s():%d","util.c",
                         "parse_extranonce",0x8d4);
                _applog(3,local_2038,1);
                _quit(1);
              }
              hex2bin(param_1[0x9a],param_1[0x99],param_1[0x187]);
              param_1[0x9e] = iVar2;
              iVar2 = pthread_rwlock_unlock((pthread_rwlock_t *)(param_1 + 0x3b));
              if (iVar2 != 0) {
                piVar3 = __errno_location();
                snprintf(local_2038,0x800,"WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",
                         *piVar3,"util.c","parse_extranonce",0x8d7);
                _applog(3,local_2038,1);
                _quit(1);
              }
              _mutex_unlock_noyield_constprop_15
                        ((pthread_mutex_t *)(param_1 + 0x35),"parse_extranonce",0x8d7);
              (*selective_yield)();
              if (((use_syslog != '\0') || (opt_log_output != '\0')) || (4 < opt_log_level)) {
                snprintf(local_2038,0x800,"Pool %d extranonce change requested",*param_1);
                _applog(5,local_2038,0);
              }
              opt_work_update = 1;
            }
            goto LAB_0004a37e;
          }
          if (((use_syslog != '\0') || (opt_log_output != '\0')) || (5 < opt_log_level)) {
            builtin_strncpy(local_2038,"Failed to get valid nonc",0x18);
            uStack_2020._0_1_ = 'e';
            uStack_2020._1_1_ = '1';
            uStack_2020._2_1_ = ' ';
            uStack_2020._3_1_ = 'i';
            builtin_strncpy(acStack_201c,"n parse_extranon",0x10);
            uStack_200c = 0x6563;
            local_200a = 0;
            _applog(6,local_2038,0);
            goto LAB_0004a37e;
          }
        }
        else {
          iVar2 = strncasecmp(__s1,"client.reconnect",0x10);
          if (iVar2 == 0) {
            unaff_r6 = parse_reconnect(param_1,piVar4);
            goto LAB_0004a37e;
          }
          iVar2 = strncasecmp(__s1,"client.get_version",0x12);
          if (iVar2 == 0) {
            iVar2 = json_object_get(iVar1,&DAT_0005e278);
            if (iVar2 != 0) {
              json_object_get(iVar1,&DAT_0005e278);
              uVar5 = json_integer_value();
              pcVar9 = "{\"id\": %d, \"result\": \"bmminer/2.0.0\", \"error\": null}";
LAB_0004a5b0:
              sprintf(local_2038,pcVar9,uVar5);
              sVar7 = strlen(local_2038);
              unaff_r6 = stratum_send(param_1,local_2038,sVar7);
              goto LAB_0004a37e;
            }
          }
          else {
            iVar2 = strncasecmp(__s1,"client.show_message",0x13);
            if (iVar2 == 0) {
              if ((piVar4 != (int *)0x0) && (*piVar4 == 1)) {
                json_array_get(piVar4,0);
                iVar2 = json_string_value();
                if (iVar2 != 0) {
                  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (4 < opt_log_level)) {
                    uVar13 = CONCAT44(pcVar9,iVar2);
                    pcVar9 = "Pool %d message: %s";
                    uVar5 = *param_1;
                    goto LAB_0004a6ce;
                  }
                  goto LAB_0004a8b0;
                }
              }
            }
            else {
              iVar2 = strncasecmp(__s1,"mining.ping",0xb);
              if (iVar2 == 0) {
                if (((use_syslog != '\0') || (opt_log_output != '\0')) || (5 < opt_log_level)) {
                  snprintf(local_2038,0x800,"Pool %d ping",*param_1);
                  _applog(6,local_2038,0);
                }
                unaff_r6 = json_object_get(iVar1,&DAT_0005e278);
                if (unaff_r6 == 0) goto LAB_0004a37e;
                json_object_get(iVar1,&DAT_0005e278);
                uVar5 = json_integer_value();
                pcVar9 = "{\"id\": %d, \"result\": \"pong\", \"error\": null}";
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
    json_array_get(piVar4,0);
    unaff_r6 = 1;
    uVar5 = json_string_value();
    process_version_mask(param_1,uVar5);
  }
  *(char *)((int)param_1 + 0x283) = (char)unaff_r6;
LAB_0004a37e:
  if (*(int *)(iVar1 + 4) == -1) {
    return unaff_r6;
  }
  iVar2 = *(int *)(iVar1 + 4) + -1;
  *(int *)(iVar1 + 4) = iVar2;
  if (iVar2 == 0) {
    json_delete(iVar1);
    return unaff_r6;
  }
  return unaff_r6;
}

