
/* WARNING: Unknown calling convention */

_Bool pool_active(pool *pool,_Bool pinging)

{
  undefined4 uVar1;
  _Bool _Var2;
  char *pcVar3;
  int iVar4;
  size_t __n;
  timeval tv_getwork;
  timeval tv_getwork_reply;
  char tmp42 [2048];
  
  if (pool->has_gbt == false) {
    if (((use_syslog) || (opt_log_output)) || (5 < opt_log_level)) {
      snprintf(tmp42,0x800,"Testing pool %s",pool->rpc_url);
      _applog(6,tmp42,false);
    }
  }
  else if ((opt_debug) && (((use_syslog || (opt_log_output)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"Retrieving block template from pool %s",pool->rpc_url);
    _applog(7,tmp42,false);
  }
  uVar1 = tmp42._24_4_;
  if (pool->has_stratum != false) goto LAB_00020b78;
  if (curly == (char *)0x0) {
    if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 3)) {
      return false;
    }
    builtin_strncpy(tmp42,"CURL initialisation failed",0x1b);
    tmp42[0x1b] = SUB41(uVar1,3);
    _applog(3,tmp42,false);
    return false;
  }
  if (pool->probed == false) {
    if (opt_debug == false) {
      pool->probed = false;
    }
    else if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 7)) {
      pool->probed = false;
      if (pool->has_gbt == false) {
        if (pool->gbt_solo == false) {
LAB_00020c90:
          if ((use_syslog == false) && (opt_log_output == false)) {
            if (opt_log_level < 7) goto LAB_00020a22;
            pcVar3 = "No GBT coinbase + append support found, pool unusable if it has no stratum";
            __n = 0x4b;
          }
          else {
            pcVar3 = "No GBT coinbase + append support found, pool unusable if it has no stratum";
            __n = 0x4b;
          }
        }
        else {
LAB_00020c68:
          if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 7))
          goto LAB_00020a22;
          pcVar3 = "GBT coinbase without append found, switching to GBT solo protocol";
          __n = 0x42;
        }
        memcpy(tmp42,pcVar3,__n);
        _applog(7,tmp42,false);
      }
      else {
LAB_00020bee:
        if (((use_syslog != false) || (opt_log_output != false)) || (6 < opt_log_level)) {
          builtin_strncpy(tmp42,"GBT coinbase + append support found, switching to GBT protoc",0x3c)
          ;
          tmp42[0x3c] = 'o';
          tmp42[0x3d] = 'l';
          tmp42[0x3e] = '\0';
          _applog(7,tmp42,false);
        }
      }
    }
    else {
      builtin_strncpy(tmp42,"Probing for GBT support",0x18);
      _applog(7,tmp42,false);
      _Var2 = opt_debug;
      pool->probed = false;
      if (pool->has_gbt == false) {
        if (pool->gbt_solo == false) {
          if (_Var2 != false) goto LAB_00020c90;
        }
        else if (_Var2 != false) goto LAB_00020c68;
      }
      else if (_Var2 != false) goto LAB_00020bee;
    }
  }
LAB_00020a22:
  cgtime(&tv_getwork);
  cgtime(&tv_getwork_reply);
  pcVar3 = pool->stratum_url;
  if ((pcVar3 != (char *)0x0) && (opt_fix_protocol == false)) {
    if ((use_syslog != false) || ((opt_log_output != false || (5 < opt_log_level)))) {
      snprintf(tmp42,0x800,"Testing pool %d stratum %s",pool->pool_no,pcVar3);
      _applog(6,tmp42,false);
      pcVar3 = pool->stratum_url;
    }
    _Var2 = extract_sockaddr(pcVar3,&pool->sockaddr_url,&pool->stratum_port);
    if ((_Var2) && (_Var2 = initiate_stratum(pool), _Var2)) {
      if ((use_syslog != false) || ((opt_log_output != false || (4 < opt_log_level)))) {
        snprintf(tmp42,0x800,"Switching pool %d %s to %s",pool->pool_no,pool->rpc_url,
                 pool->stratum_url);
        _applog(5,tmp42,false);
      }
      if (pool->rpc_url == (char *)0x0) {
        pcVar3 = (char *)__strdup(pool->stratum_url);
        pool->rpc_url = pcVar3;
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
          (_Var2 = auth_stratum(pool), _Var2)))) {
        have_longpoll = true;
        iVar4 = pthread_create(&pool->stratum_sthread,(pthread_attr_t *)0x0,
                               (__start_routine *)0x27655,pool);
        if (iVar4 != 0) {
          builtin_strncpy(tmp42,"Failed to create stratum sthread",0x20);
          tmp42._32_4_ = tmp42._32_4_ & 0xffffff00;
          _applog(3,tmp42,true);
          _quit(1);
        }
        iVar4 = pthread_create(&pool->stratum_rthread,(pthread_attr_t *)0x0,
                               (__start_routine *)0x265ad,pool);
        if (iVar4 != 0) {
          builtin_strncpy(tmp42,"Failed to create stratum rthread",0x20);
          tmp42._32_4_ = tmp42._32_4_ & 0xffffff00;
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
    if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 4)) {
      return false;
    }
    snprintf(tmp42,0x800,"No Stratum, GBT or Solo support in pool %d %s unable to use",pool->pool_no
             ,pool->rpc_url);
  }
  else {
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"FAILED to retrieve work from pool %u %s",pool->pool_no,pool->rpc_url);
      _applog(7,tmp42,false);
    }
    if (pinging) {
      return false;
    }
    if (pool->idle != false) {
      return false;
    }
    if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 4)) {
      return false;
    }
    snprintf(tmp42,0x800,"Pool %u slow/down or URL or credentials invalid",pool->pool_no);
  }
  _applog(4,tmp42,false);
  return false;
}

