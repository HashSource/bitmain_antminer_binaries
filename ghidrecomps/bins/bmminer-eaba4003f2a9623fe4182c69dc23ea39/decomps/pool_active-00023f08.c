
/* WARNING: Removing unreachable block (ram,0x000245fe) */
/* WARNING: Removing unreachable block (ram,0x0002460c) */
/* WARNING: Removing unreachable block (ram,0x0002461a) */
/* WARNING: Removing unreachable block (ram,0x00024628) */
/* WARNING: Removing unreachable block (ram,0x00024636) */
/* WARNING: Removing unreachable block (ram,0x0002466a) */
/* WARNING: Removing unreachable block (ram,0x00024676) */
/* WARNING: Removing unreachable block (ram,0x00024690) */
/* WARNING: Removing unreachable block (ram,0x00024698) */
/* WARNING: Removing unreachable block (ram,0x000246b8) */
/* WARNING: Removing unreachable block (ram,0x0002471e) */
/* WARNING: Removing unreachable block (ram,0x0002472c) */
/* WARNING: Removing unreachable block (ram,0x0002473a) */
/* WARNING: Removing unreachable block (ram,0x00024748) */
/* WARNING: Removing unreachable block (ram,0x0002477a) */
/* WARNING: Removing unreachable block (ram,0x000241a6) */
/* WARNING: Removing unreachable block (ram,0x000241da) */
/* WARNING: Removing unreachable block (ram,0x000241fc) */
/* WARNING: Removing unreachable block (ram,0x0002429c) */
/* WARNING: Removing unreachable block (ram,0x00024204) */
/* WARNING: Removing unreachable block (ram,0x0002421e) */
/* WARNING: Removing unreachable block (ram,0x00024228) */
/* WARNING: Removing unreachable block (ram,0x00024254) */
/* WARNING: Removing unreachable block (ram,0x00024274) */
/* WARNING: Removing unreachable block (ram,0x0002428c) */
/* WARNING: Removing unreachable block (ram,0x0002426c) */
/* WARNING: Removing unreachable block (ram,0x0002424c) */
/* WARNING: Removing unreachable block (ram,0x00024292) */
/* WARNING: Removing unreachable block (ram,0x000242a8) */
/* WARNING: Removing unreachable block (ram,0x000242b8) */
/* WARNING: Removing unreachable block (ram,0x000242de) */
/* WARNING: Removing unreachable block (ram,0x000242e6) */
/* WARNING: Removing unreachable block (ram,0x000242c0) */
/* WARNING: Removing unreachable block (ram,0x000245e4) */
/* WARNING: Removing unreachable block (ram,0x000247be) */
/* WARNING: Removing unreachable block (ram,0x000247cc) */
/* WARNING: Removing unreachable block (ram,0x000247da) */
/* WARNING: Removing unreachable block (ram,0x000247e8) */
/* WARNING: Removing unreachable block (ram,0x000247f6) */
/* WARNING: Removing unreachable block (ram,0x0002482a) */
/* WARNING: Removing unreachable block (ram,0x00024848) */
/* WARNING: Removing unreachable block (ram,0x00024854) */
/* WARNING: Removing unreachable block (ram,0x00024966) */
/* WARNING: Removing unreachable block (ram,0x00024860) */
/* WARNING: Removing unreachable block (ram,0x00024898) */
/* WARNING: Removing unreachable block (ram,0x000248aa) */
/* WARNING: Removing unreachable block (ram,0x000248a2) */
/* WARNING: Removing unreachable block (ram,0x000248ae) */
/* WARNING: Removing unreachable block (ram,0x000248d4) */
/* WARNING: Removing unreachable block (ram,0x000248da) */
/* WARNING: Removing unreachable block (ram,0x00024940) */
/* WARNING: Removing unreachable block (ram,0x00024936) */
/* WARNING: Removing unreachable block (ram,0x00024948) */
/* WARNING: Removing unreachable block (ram,0x00024886) */
/* WARNING: Removing unreachable block (ram,0x0002496e) */
/* WARNING: Removing unreachable block (ram,0x00024a68) */

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
  size_t siz;
  char *copy_start;
  char *hdr_path;
  _Bool rc;
  char *mutable;
  json_t *arrval;
  json_t *res_val;
  CURL *curl;
  _Bool ret_1;
  _Bool init;
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

