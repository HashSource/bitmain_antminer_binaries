
/* WARNING: Unknown calling convention */

_Bool parse_reconnect(pool *pool,json_t *val)

{
  _Bool _Var1;
  json_t *pjVar2;
  char *pcVar3;
  char *pcVar4;
  char *__s2;
  int iVar5;
  int *piVar6;
  char *func;
  int line;
  char *pcVar7;
  int *piVar8;
  json_int_t jVar9;
  undefined1 local_a40 [16];
  char acStack_a30 [248];
  undefined1 auStack_938 [16];
  char *local_928;
  char *local_924;
  char address [256];
  char tmp42 [2048];
  
  memset(address,0,0xff);
  pjVar2 = json_array_get(val,0);
  pcVar3 = json_string_value(pjVar2);
  if (pcVar3 == (char *)0x0) {
    pcVar3 = pool->sockaddr_url;
LAB_00014f10:
    pjVar2 = json_array_get(val,1);
    jVar9 = json_integer_value(pjVar2);
    if ((int)jVar9 == 0) {
      pjVar2 = json_array_get(val,1);
      pcVar7 = json_string_value(pjVar2);
      piVar8 = (int *)auStack_938;
      if (pcVar7 == (char *)0x0) {
        pcVar7 = pool->stratum_port;
        piVar8 = (int *)auStack_938;
      }
    }
    else {
      pcVar7 = acStack_a30;
      sprintf(pcVar7,"%d",(int)jVar9);
      piVar8 = (int *)local_a40;
    }
    *piVar8 = (int)pcVar7;
    snprintf(address,0xfe,"%s:%s",pcVar3);
    _Var1 = extract_sockaddr(address,&local_928,&local_924);
    if (_Var1) {
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        iVar5 = pool->pool_no;
        *piVar8 = (int)address;
        snprintf(tmp42,0x800,"Stratum reconnect requested from pool %d to %s",iVar5);
        _applog(4,tmp42,false);
      }
      clear_pool_work(pool);
      iVar5 = pthread_mutex_lock((pthread_mutex_t *)&pool->stratum_lock);
      if (iVar5 != 0) {
        _mutex_lock((pthread_mutex_t *)"parse_reconnect",(char *)0x8b8,func,line);
      }
      clear_sockbuf(pool);
      pool->stratum_notify = false;
      pool->stratum_active = false;
      if (pool->sock != 0) {
        close(pool->sock);
      }
      pcVar3 = pool->sockaddr_url;
      pool->sock = 0;
      pool->stratum_url = local_928;
      pool->sockaddr_url = local_928;
      free(pcVar3);
      pcVar3 = pool->stratum_port;
      pool->stratum_port = local_924;
      free(pcVar3);
      iVar5 = pthread_mutex_unlock((pthread_mutex_t *)&pool->stratum_lock);
      if (iVar5 != 0) {
        piVar6 = __errno_location();
        piVar8[2] = 0x8c1;
        *piVar8 = (int)"util.c";
        piVar8[1] = (int)"parse_reconnect";
        snprintf(tmp42,0x800,"WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar6);
        _applog(3,tmp42,true);
        _quit(1);
      }
      (*selective_yield)();
      _Var1 = restart_stratum(pool);
      return _Var1;
    }
  }
  else {
    pcVar7 = pool->sockaddr_url;
    pcVar4 = strchr(pcVar7,0x2e);
    if (pcVar4 == (char *)0x0) {
      if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 3)) {
        return false;
      }
      pcVar4 = "Denied stratum reconnect request for pool without domain \'%s\'";
    }
    else {
      __s2 = strchr(pcVar3,0x2e);
      if (__s2 == (char *)0x0) {
        if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 3)) {
          return false;
        }
        pcVar4 = "Denied stratum reconnect request to url without domain \'%s\'";
        pcVar7 = pcVar3;
      }
      else {
        iVar5 = strcmp(pcVar4,__s2);
        if (iVar5 == 0) goto LAB_00014f10;
        if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 3)) {
          return false;
        }
        pcVar4 = "Denied stratum reconnect request to non-matching domain url \'%s\'";
      }
    }
    snprintf(tmp42,0x800,pcVar4,pcVar7);
    _applog(3,tmp42,false);
  }
  return false;
}

