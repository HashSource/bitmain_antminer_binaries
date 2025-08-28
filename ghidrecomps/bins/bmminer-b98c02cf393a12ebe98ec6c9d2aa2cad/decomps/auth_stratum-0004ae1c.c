
undefined4 auth_stratum(undefined4 *param_1)

{
  size_t sVar1;
  int iVar2;
  void *__ptr;
  int *piVar3;
  int *piVar4;
  char *__ptr_00;
  int iVar5;
  undefined4 uVar6;
  undefined1 auStack_2914 [252];
  char local_2818 [2048];
  char acStack_2018 [8196];
  
  iVar2 = swork_id;
  swork_id = swork_id + 1;
  sprintf(acStack_2018,
          "{\"id\": %d, \"method\": \"mining.authorize\", \"params\": [\"%s\", \"%s\"]}",iVar2,
          param_1[0x2b],param_1[0x2c]);
  sVar1 = strlen(acStack_2018);
  iVar2 = stratum_send(param_1,acStack_2018,sVar1);
  if (iVar2 != 0) {
    while (__ptr = (void *)recv_line(param_1), __ptr != (void *)0x0) {
      iVar2 = parse_method(param_1,__ptr);
      if (iVar2 == 0) {
        iVar2 = json_loads(__ptr,0,auStack_2914);
        free(__ptr);
        piVar3 = (int *)json_object_get(iVar2,"result");
        piVar4 = (int *)json_object_get(iVar2,"error");
        if ((piVar3 == (int *)0x0) || (*piVar3 == 6)) {
          if (piVar4 != (int *)0x0) goto LAB_0004aed2;
          __ptr_00 = (char *)malloc(0x11);
          if (__ptr_00 != (char *)0x0) {
            builtin_strncpy(__ptr_00,"(unknown reason)",0x11);
          }
        }
        else {
          if ((piVar4 == (int *)0x0) || (*piVar4 == 7)) {
            if (((use_syslog != '\0') || (opt_log_output != '\0')) || (5 < opt_log_level)) {
              snprintf(local_2818,0x800,"Stratum authorisation success for pool %d",*param_1);
              _applog(6,local_2818,0);
            }
            iVar5 = opt_suggest_diff;
            successful_connect = 1;
            *(undefined1 *)((int)param_1 + 99) = 1;
            if (iVar5 != 0) {
              swork_id = swork_id + 1;
              sprintf(acStack_2018,
                      "{\"id\": %d, \"method\": \"mining.suggest_difficulty\", \"params\": [%d]}");
              sVar1 = strlen(acStack_2018);
              stratum_send(param_1,acStack_2018,sVar1);
            }
            if (opt_bitmain_ab == '\0') {
              uVar6 = 1;
            }
            else {
              if (((use_syslog != '\0') || (opt_log_output != '\0')) || (4 < opt_log_level)) {
                builtin_strncpy(local_2818,"LOW POWER MODE!",0x10);
                _applog(5,local_2818,0);
              }
              iVar5 = swork_id;
              swork_id = swork_id + 1;
              uVar6 = 1;
              sprintf(acStack_2018,
                      "{\"id\":%d, \"method\":\"mining.configure\", \"params\":[[\"version-rolling\"],{\"version-rolling.mask\":\"%08x\",\"version-rolling.min-bit-count\":%d}]}"
                      ,iVar5,0xc00000,2);
              sVar1 = strlen(acStack_2018);
              stratum_send(param_1,acStack_2018,sVar1);
              param_1[0xa2] = 1;
            }
            goto LAB_0004af2e;
          }
LAB_0004aed2:
          __ptr_00 = (char *)json_dumps(piVar4,3);
        }
        if (((use_syslog != '\0') || (opt_log_output != '\0')) || (5 < opt_log_level)) {
          snprintf(local_2818,0x800,"pool %d JSON stratum auth failed: %s",*param_1,__ptr_00);
          _applog(6,local_2818,0);
        }
        uVar6 = 0;
        free(__ptr_00);
        suspend_stratum(param_1);
LAB_0004af2e:
        if (iVar2 == 0) {
          return uVar6;
        }
        if (*(int *)(iVar2 + 4) == -1) {
          return uVar6;
        }
        iVar5 = *(int *)(iVar2 + 4) + -1;
        *(int *)(iVar2 + 4) = iVar5;
        if (iVar5 != 0) {
          return uVar6;
        }
        json_delete(iVar2);
        return uVar6;
      }
      free(__ptr);
    }
  }
  return 0;
}

