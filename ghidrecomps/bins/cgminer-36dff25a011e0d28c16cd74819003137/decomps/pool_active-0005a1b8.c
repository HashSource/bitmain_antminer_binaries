
/* WARNING: Removing unreachable block (ram,0x0005ab8c) */
/* WARNING: Removing unreachable block (ram,0x0005aba0) */
/* WARNING: Removing unreachable block (ram,0x0005abb4) */
/* WARNING: Removing unreachable block (ram,0x0005abc8) */
/* WARNING: Removing unreachable block (ram,0x0005abdc) */
/* WARNING: Removing unreachable block (ram,0x0005ac2c) */
/* WARNING: Removing unreachable block (ram,0x0005ac3c) */
/* WARNING: Removing unreachable block (ram,0x0005ac5c) */
/* WARNING: Removing unreachable block (ram,0x0005ac64) */
/* WARNING: Removing unreachable block (ram,0x0005ac84) */
/* WARNING: Removing unreachable block (ram,0x0005acfc) */
/* WARNING: Removing unreachable block (ram,0x0005ad10) */
/* WARNING: Removing unreachable block (ram,0x0005ad24) */
/* WARNING: Removing unreachable block (ram,0x0005ad38) */
/* WARNING: Removing unreachable block (ram,0x0005ad94) */
/* WARNING: Removing unreachable block (ram,0x0005a580) */
/* WARNING: Removing unreachable block (ram,0x0005a5c0) */
/* WARNING: Removing unreachable block (ram,0x0005a5e4) */
/* WARNING: Removing unreachable block (ram,0x0005a6b8) */
/* WARNING: Removing unreachable block (ram,0x0005a5f0) */
/* WARNING: Removing unreachable block (ram,0x0005a610) */
/* WARNING: Removing unreachable block (ram,0x0005a620) */
/* WARNING: Removing unreachable block (ram,0x0005a658) */
/* WARNING: Removing unreachable block (ram,0x0005a684) */
/* WARNING: Removing unreachable block (ram,0x0005a6a4) */
/* WARNING: Removing unreachable block (ram,0x0005a678) */
/* WARNING: Removing unreachable block (ram,0x0005a64c) */
/* WARNING: Removing unreachable block (ram,0x0005a6ac) */
/* WARNING: Removing unreachable block (ram,0x0005a6c8) */
/* WARNING: Removing unreachable block (ram,0x0005a6dc) */
/* WARNING: Removing unreachable block (ram,0x0005a70c) */
/* WARNING: Removing unreachable block (ram,0x0005a718) */
/* WARNING: Removing unreachable block (ram,0x0005a6e8) */
/* WARNING: Removing unreachable block (ram,0x0005ab6c) */
/* WARNING: Removing unreachable block (ram,0x0005ade8) */
/* WARNING: Removing unreachable block (ram,0x0005adfc) */
/* WARNING: Removing unreachable block (ram,0x0005ae10) */
/* WARNING: Removing unreachable block (ram,0x0005ae24) */
/* WARNING: Removing unreachable block (ram,0x0005ae38) */
/* WARNING: Removing unreachable block (ram,0x0005ae88) */
/* WARNING: Removing unreachable block (ram,0x0005aea4) */
/* WARNING: Removing unreachable block (ram,0x0005b180) */
/* WARNING: Removing unreachable block (ram,0x0005aeb4) */
/* WARNING: Removing unreachable block (ram,0x0005b010) */
/* WARNING: Removing unreachable block (ram,0x0005aec4) */
/* WARNING: Removing unreachable block (ram,0x0005af0c) */
/* WARNING: Removing unreachable block (ram,0x0005af28) */
/* WARNING: Removing unreachable block (ram,0x0005af1c) */
/* WARNING: Removing unreachable block (ram,0x0005af2c) */
/* WARNING: Removing unreachable block (ram,0x0005af60) */
/* WARNING: Removing unreachable block (ram,0x0005af68) */
/* WARNING: Removing unreachable block (ram,0x0005afe4) */
/* WARNING: Removing unreachable block (ram,0x0005afd8) */
/* WARNING: Removing unreachable block (ram,0x0005afec) */
/* WARNING: Removing unreachable block (ram,0x0005aef4) */
/* WARNING: Removing unreachable block (ram,0x0005b01c) */
/* WARNING: Removing unreachable block (ram,0x0005b194) */

_Bool pool_active(pool *pool,_Bool pinging)

{
  undefined4 uVar1;
  _Bool _Var2;
  char *pcVar3;
  char cVar4;
  _Bool pinging_local;
  pool *pool_local;
  char tmp42 [2048];
  work *work;
  timeval tv_getwork_reply;
  timeval tv_getwork;
  _Bool ret_1;
  _Bool init;
  size_t siz;
  char *copy_start;
  char *hdr_path;
  _Bool rc;
  char *mutable;
  json_t *arrval;
  json_t *res_val;
  CURL *curl;
  int rolltime;
  json_t *val;
  _Bool need_slash;
  int mutsize;
  int i;
  json_t *mutables;
  _Bool transactions;
  _Bool submit;
  _Bool append;
  _Bool ret;
  
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
  while( true ) {
    uVar1 = tmp42._24_4_;
    if (pool->has_stratum != false) {
      _Var2 = pool_tset(pool,&pool->stratum_init);
      if (_Var2) {
        cVar4 = pool->stratum_active;
      }
      else {
        _Var2 = initiate_stratum(pool);
        if (((_Var2) &&
            ((pool->extranonce_subscribe != true || (_Var2 = subscribe_extranonce(pool), _Var2))))
           && (_Var2 = auth_stratum(pool), _Var2)) {
          cVar4 = '\x01';
        }
        else {
          cVar4 = '\0';
        }
        if (cVar4 == '\0') {
          pool_tclear(pool,&pool->stratum_init);
        }
        else {
          init_stratum_threads(pool);
        }
      }
      return (_Bool)cVar4;
    }
    if (curly == (char *)0x0) {
      if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
        builtin_strncpy(tmp42,"CURL initialisation failed",0x1b);
        tmp42[0x1b] = SUB41(uVar1,3);
        _applog(3,tmp42,false);
      }
      return false;
    }
    if (pool->probed != true) {
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        builtin_strncpy(tmp42,"Probing for GBT support",0x18);
        _applog(7,tmp42,false);
      }
      pool->probed = false;
      if (pool->has_gbt == false) {
        if (pool->gbt_solo == false) {
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            memcpy(tmp42,
                   "No GBT coinbase + append support found, pool unusable if it has no stratum",0x4b
                  );
            _applog(7,tmp42,false);
          }
        }
        else if ((opt_debug != false) &&
                (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          memcpy(tmp42,"GBT coinbase without append found, switching to GBT solo protocol",0x42);
          _applog(7,tmp42,false);
        }
      }
      else if ((opt_debug != false) &&
              (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        builtin_strncpy(tmp42,"GBT coinbase + append support found, switching to GBT protoc",0x3c);
        tmp42[0x3c] = 'o';
        tmp42[0x3d] = 'l';
        tmp42[0x3e] = '\0';
        _applog(7,tmp42,false);
      }
    }
    cgtime(&tv_getwork);
    cgtime(&tv_getwork_reply);
    if (((pool->stratum_url == (char *)0x0) || (opt_fix_protocol == true)) ||
       (_Var2 = stratum_works(pool), !_Var2)) break;
    if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
      snprintf(tmp42,0x800,"Switching pool %d %s to %s",pool->pool_no,pool->rpc_url,
               pool->stratum_url);
      _applog(5,tmp42,false);
    }
    if (pool->rpc_url == (char *)0x0) {
      pcVar3 = strdup(pool->stratum_url);
      pool->rpc_url = pcVar3;
    }
    pool->has_stratum = true;
  }
  if (((pool->has_stratum != true) && (pool->gbt_solo != true)) && (pool->has_gbt != true)) {
    if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
      snprintf(tmp42,0x800,"No Stratum, GBT or Solo support in pool %d %s unable to use",
               pool->pool_no,pool->rpc_url);
      _applog(4,tmp42,false);
    }
    return false;
  }
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"FAILED to retrieve work from pool %u %s",pool->pool_no,pool->rpc_url);
    _applog(7,tmp42,false);
  }
  if (pinging) {
    return false;
  }
  if (pool->idle == true) {
    return false;
  }
  if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 4)) {
    return false;
  }
  snprintf(tmp42,0x800,"Pool %u slow/down or URL or credentials invalid",pool->pool_no);
  _applog(4,tmp42,false);
  return false;
}

