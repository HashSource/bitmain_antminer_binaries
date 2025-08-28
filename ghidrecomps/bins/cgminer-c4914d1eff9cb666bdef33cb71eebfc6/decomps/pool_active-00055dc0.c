
/* WARNING: Removing unreachable block (ram,0x000564b0) */
/* WARNING: Removing unreachable block (ram,0x000564be) */
/* WARNING: Removing unreachable block (ram,0x000564cc) */
/* WARNING: Removing unreachable block (ram,0x000564da) */
/* WARNING: Removing unreachable block (ram,0x000564e8) */
/* WARNING: Removing unreachable block (ram,0x0005651c) */
/* WARNING: Removing unreachable block (ram,0x00056528) */
/* WARNING: Removing unreachable block (ram,0x00056542) */
/* WARNING: Removing unreachable block (ram,0x0005654a) */
/* WARNING: Removing unreachable block (ram,0x00056568) */
/* WARNING: Removing unreachable block (ram,0x000565ce) */
/* WARNING: Removing unreachable block (ram,0x000565dc) */
/* WARNING: Removing unreachable block (ram,0x000565ea) */
/* WARNING: Removing unreachable block (ram,0x000565f8) */
/* WARNING: Removing unreachable block (ram,0x0005662a) */
/* WARNING: Removing unreachable block (ram,0x00056060) */
/* WARNING: Removing unreachable block (ram,0x00056094) */
/* WARNING: Removing unreachable block (ram,0x000560b6) */
/* WARNING: Removing unreachable block (ram,0x00056156) */
/* WARNING: Removing unreachable block (ram,0x000560be) */
/* WARNING: Removing unreachable block (ram,0x000560d8) */
/* WARNING: Removing unreachable block (ram,0x000560e2) */
/* WARNING: Removing unreachable block (ram,0x0005610e) */
/* WARNING: Removing unreachable block (ram,0x0005612e) */
/* WARNING: Removing unreachable block (ram,0x00056146) */
/* WARNING: Removing unreachable block (ram,0x00056126) */
/* WARNING: Removing unreachable block (ram,0x00056106) */
/* WARNING: Removing unreachable block (ram,0x0005614c) */
/* WARNING: Removing unreachable block (ram,0x00056162) */
/* WARNING: Removing unreachable block (ram,0x00056172) */
/* WARNING: Removing unreachable block (ram,0x00056198) */
/* WARNING: Removing unreachable block (ram,0x000561a0) */
/* WARNING: Removing unreachable block (ram,0x0005617a) */
/* WARNING: Removing unreachable block (ram,0x00056496) */
/* WARNING: Removing unreachable block (ram,0x00056670) */
/* WARNING: Removing unreachable block (ram,0x0005667e) */
/* WARNING: Removing unreachable block (ram,0x0005668c) */
/* WARNING: Removing unreachable block (ram,0x0005669a) */
/* WARNING: Removing unreachable block (ram,0x000566a8) */
/* WARNING: Removing unreachable block (ram,0x000566dc) */
/* WARNING: Removing unreachable block (ram,0x000566f8) */
/* WARNING: Removing unreachable block (ram,0x00056912) */
/* WARNING: Removing unreachable block (ram,0x00056704) */
/* WARNING: Removing unreachable block (ram,0x00056814) */
/* WARNING: Removing unreachable block (ram,0x00056710) */
/* WARNING: Removing unreachable block (ram,0x00056748) */
/* WARNING: Removing unreachable block (ram,0x0005675a) */
/* WARNING: Removing unreachable block (ram,0x00056752) */
/* WARNING: Removing unreachable block (ram,0x0005675e) */
/* WARNING: Removing unreachable block (ram,0x00056784) */
/* WARNING: Removing unreachable block (ram,0x0005678a) */
/* WARNING: Removing unreachable block (ram,0x000567f0) */
/* WARNING: Removing unreachable block (ram,0x000567e6) */
/* WARNING: Removing unreachable block (ram,0x000567f8) */
/* WARNING: Removing unreachable block (ram,0x00056736) */
/* WARNING: Removing unreachable block (ram,0x0005681c) */
/* WARNING: Removing unreachable block (ram,0x0005691e) */

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

