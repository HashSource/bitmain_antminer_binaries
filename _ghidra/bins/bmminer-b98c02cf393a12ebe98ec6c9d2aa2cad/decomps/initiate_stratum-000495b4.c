
int initiate_stratum(undefined4 *param_1)

{
  char cVar1;
  int iVar2;
  size_t sVar3;
  int *piVar4;
  void *__ptr;
  int *piVar5;
  char *pcVar6;
  int *piVar7;
  char *__s;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  bool bVar12;
  bool bVar13;
  undefined4 local_2924 [23];
  undefined1 auStack_28c8 [160];
  char local_2828 [36];
  uint local_2804;
  char acStack_2800 [4];
  undefined4 uStack_27fc;
  undefined2 uStack_27f8;
  undefined1 local_27f6;
  char acStack_2028 [8196];
  
  iVar11 = 0;
  bVar12 = false;
  bVar13 = false;
  iVar2 = setup_stratum_socket(param_1);
  if (iVar2 == 0) goto LAB_0004973e;
  do {
    if (bVar13) {
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
    sVar3 = strlen(acStack_2028);
    iVar2 = __stratum_send(param_1,acStack_2028,sVar3);
    if (iVar2 == 0) {
      iVar2 = socket_full_isra_2(param_1[0x93],0x3c);
      if (iVar2 == 0) {
        if ((opt_debug != 0) &&
           (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
          builtin_strncpy(local_2828,"Timed out waiting for response in in",0x24);
          local_2804._0_1_ = 'i';
          local_2804._1_1_ = 't';
          local_2804._2_1_ = 'i';
          local_2804._3_1_ = 'a';
          builtin_strncpy(acStack_2800,"te_s",4);
          uStack_27fc._0_1_ = 't';
          uStack_27fc._1_1_ = 'r';
          uStack_27fc._2_1_ = 'a';
          uStack_27fc._3_1_ = 't';
          uStack_27f8 = 0x6d75;
          local_27f6 = 0;
          _applog(7,local_2828,0);
        }
      }
      else {
        __ptr = (void *)recv_line(param_1);
        if (__ptr != (void *)0x0) {
          iVar11 = json_loads(__ptr,0,local_2924);
          free(__ptr);
          if (iVar11 == 0) {
            if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 6)) {
              bVar13 = true;
            }
            else {
              snprintf(local_2828,0x800,"JSON decode failed(%d): %s",local_2924[0],auStack_28c8);
              bVar13 = true;
              _applog(6,local_2828,0);
            }
          }
          else {
            piVar4 = (int *)json_object_get(iVar11,"result");
            piVar5 = (int *)json_object_get(iVar11,"error");
            if ((piVar4 == (int *)0x0) || (*piVar4 == 7)) {
              if (piVar5 != (int *)0x0) goto LAB_00049a44;
              pcVar6 = (char *)malloc(0x11);
              if (pcVar6 != (char *)0x0) {
                builtin_strncpy(pcVar6,"(unknown reason)",0x11);
              }
LAB_00049a4c:
              if (((use_syslog != '\0') || (opt_log_output != '\0')) || (5 < opt_log_level)) {
                snprintf(local_2828,0x800,"JSON-RPC decode failed: %s",pcVar6);
                _applog(6,local_2828,0);
              }
            }
            else {
              if ((piVar5 != (int *)0x0) && (*piVar5 != 7)) {
LAB_00049a44:
                pcVar6 = (char *)json_dumps(piVar5,3);
                goto LAB_00049a4c;
              }
              piVar5 = (int *)json_array_get(piVar4,0);
              if (((piVar5 != (int *)0x0) && (*piVar5 == 1)) &&
                 (iVar2 = json_array_size(), 0 < iVar2)) {
                iVar10 = 0;
                do {
                  piVar7 = (int *)json_array_get(piVar5,iVar10);
                  if ((piVar7 == (int *)0x0) || (*piVar7 != 1)) break;
                  iVar10 = iVar10 + 1;
                  pcVar6 = (char *)__json_array_string(piVar7,0);
                  if ((pcVar6 != (char *)0x0) &&
                     (iVar8 = strncasecmp(pcVar6,"mining.notify",0xd), iVar8 == 0)) {
                    pcVar6 = (char *)json_array_string(piVar7,1);
                    if (pcVar6 != (char *)0x0) goto LAB_00049bc6;
                    break;
                  }
                } while (iVar2 != iVar10);
              }
              pcVar6 = (char *)(uint)opt_debug;
              if ((pcVar6 != (char *)0x0) &&
                 (((use_syslog != '\0' || (opt_log_output != '\0')) ||
                  (pcVar6 = (char *)0x0, 6 < opt_log_level)))) {
                pcVar6 = (char *)0x0;
                builtin_strncpy(local_2828,"Failed to get sessionid in initiate_",0x24);
                local_2804._0_1_ = 's';
                local_2804._1_1_ = 't';
                local_2804._2_1_ = 'r';
                local_2804._3_1_ = 'a';
                builtin_strncpy(acStack_2800,"tum",4);
                _applog(7,local_2828,0);
              }
LAB_00049bc6:
              __s = (char *)json_array_string(piVar4,1);
              iVar2 = _valid_hex_constprop_10(__s,"initiate_stratum",0xcba);
              if (iVar2 != 0) {
                json_array_get(piVar4,2);
                iVar2 = json_integer_value();
                if (0xe < iVar2 - 2U) {
                  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (5 < opt_log_level)) {
                    builtin_strncpy(local_2828,"Failed to get valid n2size in initia",0x24);
                    local_2804._0_1_ = 't';
                    local_2804._1_1_ = 'e';
                    local_2804._2_1_ = '_';
                    local_2804._3_1_ = 's';
                    builtin_strncpy(acStack_2800,"trat",4);
                    uStack_27fc._0_3_ = 0x6d75;
                    _applog(6,local_2828,0);
                  }
                  free(pcVar6);
                  bVar13 = true;
                  free(__s);
                  goto LAB_00049666;
                }
                if (((pcVar6 != (char *)0x0) && ((char *)param_1[0x9f] != (char *)0x0)) &&
                   ((iVar10 = strcmp(pcVar6,(char *)param_1[0x9f]), iVar10 == 0 &&
                    (((use_syslog != '\0' || (opt_log_output != '\0')) || (4 < opt_log_level)))))) {
                  snprintf(local_2828,0x800,
                           "Pool %d successfully negotiated resume with the same session ID",
                           *param_1);
                  _applog(5,local_2828,0);
                }
                iVar10 = pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x35));
                if (iVar10 != 0) {
                  _mutex_lock_part_1_constprop_16("initiate_stratum",0xccf);
                }
                iVar10 = pthread_rwlock_wrlock((pthread_rwlock_t *)(param_1 + 0x3b));
                if (iVar10 != 0) {
                  piVar4 = __errno_location();
                  snprintf(local_2828,0x800,"WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d",
                           *piVar4,"util.c","initiate_stratum",0xccf);
                  _applog(3,local_2828,1);
                  _quit(1);
                }
                free((void *)param_1[0x99]);
                free((void *)param_1[0x9f]);
                param_1[0x9f] = pcVar6;
                param_1[0x99] = __s;
                sVar3 = strlen(__s);
                param_1[0x187] = sVar3 >> 1;
                free((void *)param_1[0x9a]);
                uVar9 = _cgcalloc(param_1[0x187],1,"util.c","initiate_stratum",0xcd6);
                param_1[0x9a] = uVar9;
                hex2bin(uVar9,param_1[0x99],param_1[0x187]);
                param_1[0x9e] = iVar2;
                iVar2 = pthread_rwlock_unlock((pthread_rwlock_t *)(param_1 + 0x3b));
                if (iVar2 != 0) {
                  piVar4 = __errno_location();
                  snprintf(local_2828,0x800,"WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",
                           *piVar4,"util.c","initiate_stratum",0xcd9);
                  _applog(3,local_2828,1);
                  _quit(1);
                }
                iVar2 = pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x35));
                if (iVar2 != 0) {
                  piVar4 = __errno_location();
                  snprintf(local_2828,0x800,"WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",
                           *piVar4,"util.c","initiate_stratum",0xcd9);
                  _applog(3,local_2828,1);
                  _quit(1);
                }
                (*selective_yield)();
                if (((pcVar6 != (char *)0x0) && (opt_debug != 0)) &&
                   ((use_syslog != '\0' || ((opt_log_output != '\0' || (6 < opt_log_level)))))) {
                  snprintf(local_2828,0x800,"Pool %d stratum session id: %s",*param_1,param_1[0x9f])
                  ;
                  _applog(7,local_2828,0);
                }
                if (param_1[0x90] == 0) {
                  param_1[0x90] = param_1[0x96];
                }
                cVar1 = opt_protocol;
                *(undefined1 *)((int)param_1 + 0x281) = 1;
                param_1[0x1c6] = 0;
                param_1[0x1c7] = 0;
                param_1[0x1c8] = 0;
                param_1[0x1c9] = 0x3ff00000;
                if (((cVar1 != '\0') && (opt_debug != 0)) &&
                   ((use_syslog != '\0' || ((opt_log_output != '\0' || (6 < opt_log_level)))))) {
                  snprintf(local_2828,0x800,
                           "Pool %d confirmed mining.subscribe with extranonce1 %s extran2size %d",
                           *param_1,param_1[0x99],param_1[0x9e]);
                  _applog(7,local_2828,0);
                }
                iVar2 = 1;
                goto LAB_0004978a;
              }
              if (((use_syslog != '\0') || (opt_log_output != '\0')) || (5 < opt_log_level)) {
                builtin_strncpy(local_2828,"Failed to get valid nonce1 in initia",0x24);
                local_2804._0_1_ = 't';
                local_2804._1_1_ = 'e';
                local_2804._2_1_ = '_';
                local_2804._3_1_ = 's';
                builtin_strncpy(acStack_2800,"trat",4);
                uStack_27fc._0_3_ = 0x6d75;
                _applog(6,local_2828,0);
              }
            }
            bVar13 = true;
            free(pcVar6);
          }
        }
      }
    }
    else if ((opt_debug != 0) &&
            (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      builtin_strncpy(local_2828,"Failed to send s in initiate_stratum",0x24);
      local_2804 = local_2804 & 0xffffff00;
      _applog(7,local_2828,0);
    }
LAB_00049666:
    iVar2 = 1;
    if (bVar13 <= bVar12) {
LAB_00049744:
      if ((opt_debug != 0) &&
         (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
        builtin_strncpy(local_2828,"Initiate stratum failed",0x18);
        _applog(7,local_2828,0);
      }
      if (iVar2 != 0) {
        suspend_stratum(param_1);
      }
      iVar2 = iVar11;
      if (iVar11 != 0) {
        iVar2 = 0;
LAB_0004978a:
        if ((*(int *)(iVar11 + 4) != -1) &&
           (iVar10 = *(int *)(iVar11 + 4) + -1, *(int *)(iVar11 + 4) = iVar10, iVar10 == 0)) {
          json_delete(iVar11);
        }
      }
      return iVar2;
    }
    while( true ) {
      iVar2 = pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x35));
      if (iVar2 == 0) {
        iVar2 = pthread_rwlock_wrlock((pthread_rwlock_t *)(param_1 + 0x3b));
      }
      else {
        piVar4 = __errno_location();
        snprintf(local_2828,0x800,"WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",*piVar4,"util.c"
                 ,"initiate_stratum",0xcf5);
        _applog(3,local_2828,1);
        _quit(1);
        iVar2 = pthread_rwlock_wrlock((pthread_rwlock_t *)(param_1 + 0x3b));
      }
      if (iVar2 != 0) {
        piVar4 = __errno_location();
        snprintf(local_2828,0x800,"WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d",*piVar4,
                 "util.c","initiate_stratum",0xcf5);
        _applog(3,local_2828,1);
        _quit(1);
      }
      free((void *)param_1[0x9f]);
      free((void *)param_1[0x99]);
      param_1[0x99] = 0;
      param_1[0x9f] = 0;
      iVar2 = pthread_rwlock_unlock((pthread_rwlock_t *)(param_1 + 0x3b));
      if (iVar2 != 0) {
        piVar4 = __errno_location();
        snprintf(local_2828,0x800,"WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar4,
                 "util.c","initiate_stratum",0xcf9);
        _applog(3,local_2828,1);
        _quit(1);
      }
      iVar2 = pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x35));
      if (iVar2 != 0) {
        piVar4 = __errno_location();
        snprintf(local_2828,0x800,"WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar4,
                 "util.c","initiate_stratum",0xcf9);
        _applog(3,local_2828,1);
        _quit(1);
      }
      (*selective_yield)();
      if ((opt_debug != 0) &&
         (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
        builtin_strncpy(local_2828,"Failed to resume stratum, trying afr",0x24);
        local_2804._0_1_ = 'e';
        local_2804._1_1_ = 's';
        local_2804._2_1_ = 'h';
        local_2804._3_1_ = '\0';
        _applog(7,local_2828,0);
      }
      if (((iVar11 != 0) && (*(int *)(iVar11 + 4) != -1)) &&
         (iVar2 = *(int *)(iVar11 + 4) + -1, *(int *)(iVar11 + 4) = iVar2, iVar2 == 0)) {
        json_delete(iVar11);
      }
      bVar12 = true;
      iVar2 = setup_stratum_socket(param_1);
      if (iVar2 != 0) break;
LAB_0004973e:
      if (bVar13 <= bVar12) goto LAB_00049744;
    }
  } while( true );
}

