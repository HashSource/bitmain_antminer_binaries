
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention */

_Bool parse_reconnect(pool *pool,json_t *val)

{
  _Bool _Var1;
  json_t *pjVar2;
  char *pcVar3;
  char *url;
  char *pcVar4;
  char *dot_pool;
  char *__s2;
  char *dot_reconnect;
  int iVar5;
  int port_no;
  int iVar6;
  char *tmp;
  int *piVar7;
  char **sockaddr_port;
  char *port;
  char *pcVar8;
  char **ppcVar9;
  json_int_t jVar10;
  undefined local_a40 [16];
  char acStack_a30 [248];
  undefined auStack_938 [16];
  char *sockaddr_url;
  char *stratum_port;
  char address [256];
  char tmp42 [2048];
  
  memset(address,0,0xff);
  pjVar2 = json_array_get(val,0);
  pcVar3 = json_string_value(pjVar2);
  if (pcVar3 == (char *)0x0) {
    pcVar3 = pool->sockaddr_url;
LAB_00014f10:
    pjVar2 = json_array_get(val,1);
    jVar10 = json_integer_value(pjVar2);
    if ((int)jVar10 == 0) {
      pjVar2 = json_array_get(val,1);
      pcVar8 = json_string_value(pjVar2);
      ppcVar9 = (char **)auStack_938;
      if (pcVar8 == (char *)0x0) {
        pcVar8 = pool->stratum_port;
        ppcVar9 = (char **)auStack_938;
      }
    }
    else {
      pcVar8 = acStack_a30;
      sprintf(pcVar8,DAT_000150e0,(int)jVar10);
      ppcVar9 = (char **)local_a40;
    }
    *ppcVar9 = pcVar8;
    snprintf(address,0xfe,DAT_000150e4,pcVar3);
    sockaddr_port = &stratum_port;
    _Var1 = extract_sockaddr(address,&sockaddr_url,sockaddr_port);
    if (!_Var1) {
      return false;
    }
    if (((*DAT_000150e8 != '\0') || (*DAT_000150ec != '\0')) || (iVar5 = *DAT_000150f0, 3 < iVar5))
    {
      iVar5 = pool->pool_no;
      *ppcVar9 = address;
      snprintf(tmp42,0x800,DAT_000150f4);
      sockaddr_port = (char **)0x0;
      _applog(4,tmp42,false);
    }
    clear_pool_work(pool);
    iVar6 = pthread_mutex_lock((pthread_mutex_t *)&pool->stratum_lock);
    if (iVar6 != 0) {
      _mutex_lock(DAT_0001510c,(char *)0x8b8,(char *)sockaddr_port,iVar5);
    }
    clear_sockbuf(pool);
    pool->stratum_notify = false;
    pool->stratum_active = false;
    if (pool->sock != 0) {
      close(pool->sock);
    }
    pcVar3 = pool->sockaddr_url;
    pool->sock = 0;
    pool->stratum_url = sockaddr_url;
    pool->sockaddr_url = sockaddr_url;
    free(pcVar3);
    pcVar3 = pool->stratum_port;
    pool->stratum_port = stratum_port;
    free(pcVar3);
    iVar5 = pthread_mutex_unlock((pthread_mutex_t *)&pool->stratum_lock);
    if (iVar5 != 0) {
      piVar7 = __errno_location();
      ppcVar9[2] = (char *)0x8c1;
      *ppcVar9 = (char *)DAT_00015108;
      ppcVar9[1] = (char *)DAT_0001510c;
      snprintf(tmp42,0x800,DAT_00015110,*piVar7);
      _applog(3,tmp42,true);
      _quit(1);
    }
    (**DAT_000150f8)();
    _Var1 = restart_stratum(pool);
    return _Var1;
  }
  pcVar8 = pool->sockaddr_url;
  pcVar4 = strchr(pcVar8,0x2e);
  if (pcVar4 == (char *)0x0) {
    pcVar4 = DAT_00015100;
    if ((*DAT_000150e8 != '\0') || (*DAT_000150ec != '\0')) goto LAB_00015012;
    iVar5 = *DAT_000150f0;
  }
  else {
    __s2 = strchr(pcVar3,0x2e);
    if (__s2 == (char *)0x0) {
      pcVar4 = DAT_00015104;
      pcVar8 = pcVar3;
      if ((*DAT_000150e8 != '\0') || (*DAT_000150ec != '\0')) goto LAB_00015012;
      iVar5 = *DAT_000150f0;
    }
    else {
      iVar5 = strcmp(pcVar4,__s2);
      if (iVar5 == 0) goto LAB_00014f10;
      pcVar4 = DAT_000150fc;
      if ((*DAT_000150e8 != '\0') || (*DAT_000150ec != '\0')) goto LAB_00015012;
      iVar5 = *DAT_000150f0;
    }
  }
  if (iVar5 < 3) {
    return false;
  }
LAB_00015012:
  snprintf(tmp42,0x800,pcVar4,pcVar8);
  _applog(3,tmp42,false);
  return false;
}

