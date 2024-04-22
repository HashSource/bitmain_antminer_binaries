
/* WARNING: Unknown calling convention */

_Bool pool_active(pool *pool,_Bool pinging)

{
  char cVar1;
  __start_routine *__start_routine;
  _Bool _Var2;
  _Bool init;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  void *pvVar6;
  size_t __n;
  timeval tv_getwork;
  timeval tv_getwork_reply;
  char tmp42 [2048];
  
  if (pool->has_gbt == false) {
    if (((*DAT_00020e44 != '\0') || (*DAT_00020e38 != '\0')) || (5 < *DAT_00020e4c)) {
      snprintf(tmp42,0x800,DAT_00020e48,pool->rpc_url);
      _applog(6,tmp42,false);
    }
  }
  else if ((*DAT_00020c2c != '\0') &&
          (((*DAT_00020e44 != '\0' || (*DAT_00020e38 != '\0')) || (6 < *DAT_00020e4c)))) {
    snprintf(tmp42,0x800,DAT_00020e50,pool->rpc_url);
    _applog(7,tmp42,false);
  }
  pcVar3 = DAT_00020c38;
  pcVar4 = DAT_00020c2c;
  if (pool->has_stratum != false) goto LAB_00020b78;
  if (*(int *)(DAT_00020c30 + 0x7fc) == 0) {
    if (((*DAT_00020e44 == '\0') && (*DAT_00020e38 == '\0')) && (*DAT_00020e4c < 3)) {
      return false;
    }
    tmp42._0_4_ = *DAT_00020e64;
    tmp42._4_4_ = DAT_00020e64[1];
    tmp42._8_4_ = DAT_00020e64[2];
    tmp42._12_4_ = DAT_00020e64[3];
    tmp42._16_4_ = DAT_00020e64[4];
    tmp42._20_4_ = DAT_00020e64[5];
    tmp42._24_3_ = (undefined3)DAT_00020e64[6];
    _applog(3,tmp42,false);
    return false;
  }
  if (pool->probed == false) {
    if (*DAT_00020c2c == '\0') {
      pool->probed = false;
    }
    else if (((*DAT_00020c38 == '\0') && (*DAT_00020c3c == '\0')) && (*DAT_00020c40 < 7)) {
      pool->probed = false;
      if (pool->has_gbt == false) {
        if (pool->gbt_solo == false) {
LAB_00020c90:
          pvVar6 = DAT_00020e40;
          if ((*pcVar3 == '\0') && (*DAT_00020e38 == '\0')) {
            if (*DAT_00020e4c < 7) goto LAB_00020a22;
            __n = 0x4b;
          }
          else {
            __n = 0x4b;
          }
        }
        else {
LAB_00020c68:
          if (((*pcVar3 == '\0') && (*DAT_00020e38 == '\0')) && (*DAT_00020e4c < 7))
          goto LAB_00020a22;
          __n = 0x42;
          pvVar6 = DAT_00020e3c;
        }
        memcpy(tmp42,pvVar6,__n);
        _applog(7,tmp42,false);
      }
      else {
LAB_00020bee:
        if (((*pcVar3 != '\0') || (*DAT_00020c3c != '\0')) || (6 < *DAT_00020c40)) {
          tmp42._0_4_ = *DAT_00020c54;
          tmp42._4_4_ = DAT_00020c54[1];
          tmp42._8_4_ = DAT_00020c54[2];
          tmp42._12_4_ = DAT_00020c54[3];
          tmp42._16_4_ = DAT_00020c54[4];
          tmp42._20_4_ = DAT_00020c54[5];
          tmp42._24_4_ = DAT_00020c54[6];
          tmp42._28_4_ = DAT_00020c54[7];
          tmp42._32_4_ = DAT_00020c54[8];
          tmp42._36_4_ = DAT_00020c54[9];
          tmp42._40_4_ = DAT_00020c54[10];
          tmp42._44_4_ = DAT_00020c54[0xb];
          tmp42._48_4_ = DAT_00020c54[0xc];
          tmp42._52_4_ = DAT_00020c54[0xd];
          tmp42._56_4_ = DAT_00020c54[0xe];
          tmp42._60_2_ = (undefined2)DAT_00020c54[0xf];
          tmp42[62] = (char)((uint)DAT_00020c54[0xf] >> 0x10);
          _applog(7,tmp42,false);
        }
      }
    }
    else {
      tmp42._0_4_ = *DAT_00020c58;
      tmp42._4_4_ = DAT_00020c58[1];
      tmp42._8_4_ = DAT_00020c58[2];
      tmp42._12_4_ = DAT_00020c58[3];
      tmp42._16_4_ = DAT_00020c58[4];
      tmp42._20_4_ = DAT_00020c58[5];
      _applog(7,tmp42,false);
      cVar1 = *pcVar4;
      pool->probed = false;
      if (pool->has_gbt == false) {
        if (pool->gbt_solo == false) {
          if (cVar1 != '\0') goto LAB_00020c90;
        }
        else if (cVar1 != '\0') goto LAB_00020c68;
      }
      else if (cVar1 != '\0') goto LAB_00020bee;
    }
  }
LAB_00020a22:
  cgtime(&tv_getwork);
  cgtime(&tv_getwork_reply);
  pcVar4 = DAT_00020c38;
  pcVar3 = pool->stratum_url;
  if ((pcVar3 != (char *)0x0) && (*(char *)(DAT_00020c34 + 0x464) == '\0')) {
    if ((*DAT_00020c38 != '\0') || ((*DAT_00020c3c != '\0' || (5 < *DAT_00020c40)))) {
      snprintf(tmp42,0x800,DAT_00020c44,pool->pool_no,pcVar3);
      _applog(6,tmp42,false);
      pcVar3 = pool->stratum_url;
    }
    _Var2 = extract_sockaddr(pcVar3,&pool->sockaddr_url,&pool->stratum_port);
    if ((_Var2) && (_Var2 = initiate_stratum(pool), _Var2)) {
      if ((*pcVar4 != '\0') || ((*DAT_00020c3c != '\0' || (4 < *DAT_00020c40)))) {
        snprintf(tmp42,0x800,DAT_00020c50,pool->pool_no,pool->rpc_url,pool->stratum_url);
        _applog(5,tmp42,false);
      }
      if (pool->rpc_url == (char *)0x0) {
        pcVar4 = (char *)__strdup(pool->stratum_url);
        pool->rpc_url = pcVar4;
        pool->has_stratum = true;
      }
      else {
        pool->has_stratum = true;
      }
LAB_00020b78:
      _Var2 = pool_tset(pool,&pool->stratum_init);
      if (_Var2) {
        return pool->stratum_active;
      }
      _Var2 = initiate_stratum(pool);
      if ((_Var2) &&
         (((pool->extranonce_subscribe == false || (_Var2 = subscribe_extranonce(pool), _Var2)) &&
          (_Var2 = auth_stratum(pool), __start_routine = DAT_00020e58, _Var2)))) {
        *DAT_00020e54 = 1;
        iVar5 = pthread_create(&pool->stratum_sthread,(pthread_attr_t *)0x0,__start_routine,pool);
        if (iVar5 != 0) {
          tmp42._0_4_ = *DAT_00020e6c;
          tmp42._4_4_ = DAT_00020e6c[1];
          tmp42._8_4_ = DAT_00020e6c[2];
          tmp42._12_4_ = DAT_00020e6c[3];
          tmp42._16_4_ = DAT_00020e6c[4];
          tmp42._20_4_ = DAT_00020e6c[5];
          tmp42._24_4_ = DAT_00020e6c[6];
          tmp42._28_4_ = DAT_00020e6c[7];
          tmp42[32] = (char)DAT_00020e6c[8];
          _applog(3,tmp42,true);
          _quit(1);
        }
        iVar5 = pthread_create(&pool->stratum_rthread,(pthread_attr_t *)0x0,DAT_00020e5c,pool);
        if (iVar5 != 0) {
          tmp42._0_4_ = *DAT_00020e68;
          tmp42._4_4_ = DAT_00020e68[1];
          tmp42._8_4_ = DAT_00020e68[2];
          tmp42._12_4_ = DAT_00020e68[3];
          tmp42._16_4_ = DAT_00020e68[4];
          tmp42._20_4_ = DAT_00020e68[5];
          tmp42._24_4_ = DAT_00020e68[6];
          tmp42._28_4_ = DAT_00020e68[7];
          tmp42[32] = (char)DAT_00020e68[8];
          _applog(3,tmp42,true);
          _quit(1);
          return true;
        }
        return true;
      }
      pool_tclear(pool,&pool->stratum_init);
      return false;
    }
  }
  if (((pool->has_stratum == false) && (pool->gbt_solo == false)) && (pool->has_gbt == false)) {
    if (((*DAT_00020c38 == '\0') && (*DAT_00020c3c == '\0')) && (*DAT_00020c40 < 4)) {
      return false;
    }
    snprintf(tmp42,0x800,DAT_00020e60,pool->pool_no,pool->rpc_url);
  }
  else {
    if ((*DAT_00020c2c != '\0') &&
       (((*DAT_00020c38 != '\0' || (*DAT_00020c3c != '\0')) || (6 < *DAT_00020e4c)))) {
      snprintf(tmp42,0x800,DAT_00020c48,pool->pool_no,pool->rpc_url);
      _applog(7,tmp42,false);
    }
    if (pinging) {
      return false;
    }
    if (pool->idle != false) {
      return false;
    }
    if (((*DAT_00020c38 == '\0') && (*DAT_00020c3c == '\0')) && (*DAT_00020c40 < 4)) {
      return false;
    }
    snprintf(tmp42,0x800,DAT_00020c4c,pool->pool_no);
  }
  _applog(4,tmp42,false);
  return false;
}

