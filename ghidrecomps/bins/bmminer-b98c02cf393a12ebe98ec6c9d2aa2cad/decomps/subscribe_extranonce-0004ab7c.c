
undefined4 subscribe_extranonce(undefined4 *param_1)

{
  size_t sVar1;
  int iVar2;
  void *__ptr;
  int *piVar3;
  int *piVar4;
  char *pcVar5;
  int iVar6;
  undefined4 uVar7;
  undefined1 auStack_2914 [252];
  char local_2818 [2048];
  char acStack_2018 [8196];
  
  swork_id = swork_id + 1;
  sprintf(acStack_2018,"{\"id\": %d, \"method\": \"mining.extranonce.subscribe\", \"params\": []}");
  sVar1 = strlen(acStack_2018);
  iVar2 = stratum_send(param_1,acStack_2018,sVar1);
  if (iVar2 == 0) {
    uVar7 = 0;
  }
  else {
    while (iVar2 = socket_full_isra_2(param_1[0x93],2), iVar2 != 0) {
      __ptr = (void *)recv_line(param_1);
      if (__ptr == (void *)0x0) {
        return 0;
      }
      iVar2 = parse_method(param_1,__ptr);
      if (iVar2 == 0) {
        iVar2 = json_loads(__ptr,0,auStack_2914);
        free(__ptr);
        piVar3 = (int *)json_object_get(iVar2,"result");
        piVar4 = (int *)json_object_get(iVar2,"error");
        if ((piVar3 == (int *)0x0) || (*piVar3 == 6)) {
          if (piVar4 != (int *)0x0) goto LAB_0004ac90;
          pcVar5 = (char *)malloc(0x11);
          if (pcVar5 != (char *)0x0) {
            builtin_strncpy(pcVar5,"(unknown reason)",0x11);
          }
LAB_0004acce:
          if (((use_syslog != '\0') || (opt_log_output != '\0')) || (5 < opt_log_level)) {
            snprintf(local_2818,0x800,"Pool %d JSON extranonce subscribe failed: %s",*param_1,pcVar5
                    );
            _applog(6,local_2818,0);
          }
          uVar7 = 0;
          free(pcVar5);
        }
        else {
          if ((piVar4 == (int *)0x0) || (*piVar4 == 7)) {
            if ((use_syslog != '\0') || ((opt_log_output != '\0' || (5 < opt_log_level)))) {
              uVar7 = 1;
              snprintf(local_2818,0x800,"Stratum extranonce subscribe for pool %d",*param_1);
              _applog(6,local_2818,0);
              goto LAB_0004ad1c;
            }
          }
          else {
LAB_0004ac90:
            pcVar5 = (char *)__json_array_string(piVar4,1);
            if (((pcVar5 == (char *)0x0) &&
                (pcVar5 = (char *)json_string_value(piVar4), pcVar5 == (char *)0x0)) ||
               ((iVar6 = strcmp(pcVar5,
                                "Method \'subscribe\' not found for service \'mining.extranonce\'"),
                iVar6 != 0 && (iVar6 = strcmp(pcVar5,"Unrecognized request provided"), iVar6 != 0)))
               ) {
              pcVar5 = (char *)json_dumps(piVar4,3);
              goto LAB_0004acce;
            }
            if (((use_syslog != '\0') || (opt_log_output != '\0')) || (5 < opt_log_level)) {
              uVar7 = 1;
              snprintf(local_2818,0x800,"Cannot subscribe to mining.extranonce for pool %d",*param_1
                      );
              _applog(6,local_2818,0);
              goto LAB_0004ad1c;
            }
          }
          uVar7 = 1;
        }
LAB_0004ad1c:
        if (iVar2 == 0) {
          return uVar7;
        }
        if (*(int *)(iVar2 + 4) == -1) {
          return uVar7;
        }
        iVar6 = *(int *)(iVar2 + 4) + -1;
        *(int *)(iVar2 + 4) = iVar6;
        if (iVar6 != 0) {
          return uVar7;
        }
        json_delete(iVar2);
        return uVar7;
      }
      free(__ptr);
    }
    if ((opt_debug != '\0') &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      builtin_strncpy(local_2818,"Timed out waiting for response extranonce.subscribe",0x34);
      _applog(7,local_2818,0);
    }
    uVar7 = 1;
  }
  return uVar7;
}

