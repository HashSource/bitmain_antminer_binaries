
undefined4 parse_reconnect(undefined4 *param_1,undefined4 param_2)

{
  char *__s;
  char *pcVar1;
  char *__s2;
  int iVar2;
  void *pvVar3;
  int *piVar4;
  undefined4 uVar5;
  char *pcVar6;
  int *piVar7;
  undefined1 local_a40 [16];
  char acStack_a30 [248];
  undefined1 auStack_938 [16];
  undefined4 local_928;
  undefined4 local_924;
  char acStack_920 [256];
  char acStack_820 [2052];
  
  memset(acStack_920,0,0xff);
  json_array_get(param_2,0);
  __s = (char *)json_string_value();
  if (__s == (char *)0x0) {
    __s = (char *)param_1[0x96];
LAB_0004a060:
    json_array_get(param_2,1);
    iVar2 = json_integer_value();
    if (iVar2 == 0) {
      json_array_get(param_2,1);
      pcVar6 = (char *)json_string_value();
      piVar7 = (int *)auStack_938;
      if (pcVar6 == (char *)0x0) {
        pcVar6 = (char *)param_1[0x92];
        piVar7 = (int *)auStack_938;
      }
    }
    else {
      pcVar6 = acStack_a30;
      sprintf(pcVar6,"%d",iVar2);
      piVar7 = (int *)local_a40;
    }
    *piVar7 = (int)pcVar6;
    snprintf(acStack_920,0xfe,"%s:%s",__s);
    iVar2 = extract_sockaddr(acStack_920,&local_928,&local_924);
    if (iVar2 != 0) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (3 < opt_log_level)) {
        uVar5 = *param_1;
        *piVar7 = (int)acStack_920;
        snprintf(acStack_820,0x800,"Stratum reconnect requested from pool %d to %s",uVar5);
        _applog(4,acStack_820,0);
      }
      clear_pool_work(param_1);
      iVar2 = pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0xb0));
      if (iVar2 != 0) {
        piVar4 = __errno_location();
        iVar2 = *piVar4;
        *piVar7 = (int)"util.c";
        piVar7[1] = (int)"parse_reconnect";
        piVar7[2] = 0x91e;
        snprintf(acStack_820,0x800,"WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",iVar2);
        _applog(3,acStack_820,1);
        _quit(1);
      }
      __suspend_stratum(param_1);
      pvVar3 = (void *)param_1[0x96];
      param_1[0x90] = local_928;
      param_1[0x96] = local_928;
      free(pvVar3);
      pvVar3 = (void *)param_1[0x92];
      param_1[0x92] = local_924;
      free(pvVar3);
      iVar2 = pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0xb0));
      if (iVar2 != 0) {
        piVar4 = __errno_location();
        iVar2 = *piVar4;
        *piVar7 = (int)"util.c";
        piVar7[1] = (int)"parse_reconnect";
        piVar7[2] = 0x927;
        snprintf(acStack_820,0x800,"WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",iVar2);
        _applog(3,acStack_820,1);
        _quit(1);
      }
      (*selective_yield)();
      uVar5 = restart_stratum(param_1);
      return uVar5;
    }
  }
  else {
    pcVar6 = (char *)param_1[0x96];
    pcVar1 = strchr(pcVar6,0x2e);
    if (pcVar1 == (char *)0x0) {
      if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 3)) {
        return 0;
      }
      pcVar1 = "Denied stratum reconnect request for pool without domain \'%s\'";
    }
    else {
      __s2 = strchr(__s,0x2e);
      if (__s2 == (char *)0x0) {
        if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 3)) {
          return 0;
        }
        pcVar1 = "Denied stratum reconnect request to url without domain \'%s\'";
        pcVar6 = __s;
      }
      else {
        iVar2 = strcmp(pcVar1,__s2);
        if (iVar2 == 0) goto LAB_0004a060;
        if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 3)) {
          return 0;
        }
        pcVar1 = "Denied stratum reconnect request to non-matching domain url \'%s\'";
      }
    }
    snprintf(acStack_820,0x800,pcVar1,pcVar6);
    _applog(3,acStack_820,0);
  }
  return 0;
}

