
undefined4 parse_reconnect(undefined4 *param_1,undefined4 param_2)

{
  char *pcVar1;
  char *pcVar2;
  char *__s2;
  int iVar3;
  void *pvVar4;
  int *piVar5;
  undefined4 uVar6;
  char *pcVar7;
  char **ppcVar8;
  undefined local_a40 [16];
  char acStack_a30 [248];
  undefined auStack_938 [16];
  undefined4 local_928;
  undefined4 local_924;
  char acStack_920 [256];
  char acStack_820 [2052];
  
  memset(acStack_920,0,0xff);
  json_array_get(param_2,0);
  pcVar1 = (char *)json_string_value();
  if (pcVar1 == (char *)0x0) {
    pcVar1 = (char *)param_1[0x96];
LAB_0004a060:
    json_array_get(param_2,1);
    iVar3 = json_integer_value();
    if (iVar3 == 0) {
      json_array_get(param_2,1);
      pcVar7 = (char *)json_string_value();
      ppcVar8 = (char **)auStack_938;
      if (pcVar7 == (char *)0x0) {
        pcVar7 = (char *)param_1[0x92];
        ppcVar8 = (char **)auStack_938;
      }
    }
    else {
      pcVar7 = acStack_a30;
      sprintf(pcVar7,"%d",iVar3);
      ppcVar8 = (char **)local_a40;
    }
    *ppcVar8 = pcVar7;
    snprintf(acStack_920,0xfe,"%s:%s",pcVar1);
    iVar3 = extract_sockaddr(acStack_920,&local_928,&local_924);
    if (iVar3 != 0) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (3 < opt_log_level)) {
        uVar6 = *param_1;
        *ppcVar8 = acStack_920;
        snprintf(acStack_820,0x800,"Stratum reconnect requested from pool %d to %s",uVar6);
        _applog(4,acStack_820,0);
      }
      clear_pool_work(param_1);
      iVar3 = pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0xb0));
      if (iVar3 != 0) {
        piVar5 = __errno_location();
        iVar3 = *piVar5;
        *ppcVar8 = "util.c";
        ppcVar8[1] = DAT_0004a2c4;
        ppcVar8[2] = (char *)0x91e;
        snprintf(acStack_820,0x800,"WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",iVar3);
        _applog(3,acStack_820,1);
        _quit(1);
      }
      __suspend_stratum(param_1);
      pvVar4 = (void *)param_1[0x96];
      param_1[0x90] = local_928;
      param_1[0x96] = local_928;
      free(pvVar4);
      pvVar4 = (void *)param_1[0x92];
      param_1[0x92] = local_924;
      free(pvVar4);
      iVar3 = pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0xb0));
      pcVar1 = DAT_0004a2c4;
      if (iVar3 != 0) {
        piVar5 = __errno_location();
        iVar3 = *piVar5;
        *ppcVar8 = "util.c";
        ppcVar8[1] = pcVar1;
        ppcVar8[2] = (char *)0x927;
        snprintf(acStack_820,0x800,"WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",iVar3);
        _applog(3,acStack_820,1);
        _quit(1);
      }
      (*selective_yield)();
      uVar6 = restart_stratum(param_1);
      return uVar6;
    }
  }
  else {
    pcVar7 = (char *)param_1[0x96];
    pcVar2 = strchr(pcVar7,0x2e);
    if (pcVar2 == (char *)0x0) {
      if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 3)) {
        return 0;
      }
      pcVar2 = "Denied stratum reconnect request for pool without domain \'%s\'";
    }
    else {
      __s2 = strchr(pcVar1,0x2e);
      if (__s2 == (char *)0x0) {
        if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 3)) {
          return 0;
        }
        pcVar2 = "Denied stratum reconnect request to url without domain \'%s\'";
        pcVar7 = pcVar1;
      }
      else {
        iVar3 = strcmp(pcVar2,__s2);
        if (iVar3 == 0) goto LAB_0004a060;
        if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 3)) {
          return 0;
        }
        pcVar2 = "Denied stratum reconnect request to non-matching domain url \'%s\'";
      }
    }
    snprintf(acStack_820,0x800,pcVar2,pcVar7);
    _applog(3,acStack_820,0);
  }
  return 0;
}

