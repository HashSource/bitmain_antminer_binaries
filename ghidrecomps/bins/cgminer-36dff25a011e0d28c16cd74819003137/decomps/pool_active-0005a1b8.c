
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
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

_Bool pool_active(pool *pool,_Bool pinging)

{
  _Bool _Var1;
  char *pcVar2;
  char cVar3;
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
    if (pool->has_stratum != false) {
      _Var1 = pool_tset(pool,&pool->stratum_init);
      if (_Var1) {
        cVar3 = pool->stratum_active;
      }
      else {
        _Var1 = initiate_stratum(pool);
        if (((_Var1) &&
            ((pool->extranonce_subscribe != true || (_Var1 = subscribe_extranonce(pool), _Var1))))
           && (_Var1 = auth_stratum(pool), _Var1)) {
          cVar3 = '\x01';
        }
        else {
          cVar3 = '\0';
        }
        if (cVar3 == '\0') {
          pool_tclear(pool,&pool->stratum_init);
        }
        else {
          init_stratum_threads(pool);
        }
      }
      return (_Bool)cVar3;
    }
    if (curly == (char *)0x0) {
      if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
        tmp42[0] = s_CURL_initialisation_failed_000a47dc[0];
        tmp42[1] = s_CURL_initialisation_failed_000a47dc[1];
        tmp42[2] = s_CURL_initialisation_failed_000a47dc[2];
        tmp42[3] = s_CURL_initialisation_failed_000a47dc[3];
        tmp42[4] = s_CURL_initialisation_failed_000a47dc[4];
        tmp42[5] = s_CURL_initialisation_failed_000a47dc[5];
        tmp42[6] = s_CURL_initialisation_failed_000a47dc[6];
        tmp42[7] = s_CURL_initialisation_failed_000a47dc[7];
        tmp42[8] = s_CURL_initialisation_failed_000a47dc[8];
        tmp42[9] = s_CURL_initialisation_failed_000a47dc[9];
        tmp42[10] = s_CURL_initialisation_failed_000a47dc[10];
        tmp42[11] = s_CURL_initialisation_failed_000a47dc[11];
        tmp42[12] = s_CURL_initialisation_failed_000a47dc[12];
        tmp42[13] = s_CURL_initialisation_failed_000a47dc[13];
        tmp42[14] = s_CURL_initialisation_failed_000a47dc[14];
        tmp42[15] = s_CURL_initialisation_failed_000a47dc[15];
        tmp42[16] = s_CURL_initialisation_failed_000a47dc[16];
        tmp42[17] = s_CURL_initialisation_failed_000a47dc[17];
        tmp42[18] = s_CURL_initialisation_failed_000a47dc[18];
        tmp42[19] = s_CURL_initialisation_failed_000a47dc[19];
        tmp42[20] = s_CURL_initialisation_failed_000a47dc[20];
        tmp42[21] = s_CURL_initialisation_failed_000a47dc[21];
        tmp42[22] = s_CURL_initialisation_failed_000a47dc[22];
        tmp42[23] = s_CURL_initialisation_failed_000a47dc[23];
        tmp42._24_3_ = (undefined3)ram0x000a47f4;
        _applog(3,tmp42,false);
      }
      return false;
    }
    if (pool->probed != true) {
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        tmp42[0] = s_Probing_for_GBT_support_000a47f8[0];
        tmp42[1] = s_Probing_for_GBT_support_000a47f8[1];
        tmp42[2] = s_Probing_for_GBT_support_000a47f8[2];
        tmp42[3] = s_Probing_for_GBT_support_000a47f8[3];
        tmp42[4] = s_Probing_for_GBT_support_000a47f8[4];
        tmp42[5] = s_Probing_for_GBT_support_000a47f8[5];
        tmp42[6] = s_Probing_for_GBT_support_000a47f8[6];
        tmp42[7] = s_Probing_for_GBT_support_000a47f8[7];
        tmp42[8] = s_Probing_for_GBT_support_000a47f8[8];
        tmp42[9] = s_Probing_for_GBT_support_000a47f8[9];
        tmp42[10] = s_Probing_for_GBT_support_000a47f8[10];
        tmp42[11] = s_Probing_for_GBT_support_000a47f8[11];
        tmp42[12] = s_Probing_for_GBT_support_000a47f8[12];
        tmp42[13] = s_Probing_for_GBT_support_000a47f8[13];
        tmp42[14] = s_Probing_for_GBT_support_000a47f8[14];
        tmp42[15] = s_Probing_for_GBT_support_000a47f8[15];
        tmp42[16] = s_Probing_for_GBT_support_000a47f8[16];
        tmp42[17] = s_Probing_for_GBT_support_000a47f8[17];
        tmp42[18] = s_Probing_for_GBT_support_000a47f8[18];
        tmp42[19] = s_Probing_for_GBT_support_000a47f8[19];
        tmp42[20] = s_Probing_for_GBT_support_000a47f8[20];
        tmp42[21] = s_Probing_for_GBT_support_000a47f8[21];
        tmp42[22] = s_Probing_for_GBT_support_000a47f8[22];
        tmp42[23] = s_Probing_for_GBT_support_000a47f8[23];
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
        tmp42[0] = s_GBT_coinbase___append_support_fo_000a4848[0];
        tmp42[1] = s_GBT_coinbase___append_support_fo_000a4848[1];
        tmp42[2] = s_GBT_coinbase___append_support_fo_000a4848[2];
        tmp42[3] = s_GBT_coinbase___append_support_fo_000a4848[3];
        tmp42[4] = s_GBT_coinbase___append_support_fo_000a4848[4];
        tmp42[5] = s_GBT_coinbase___append_support_fo_000a4848[5];
        tmp42[6] = s_GBT_coinbase___append_support_fo_000a4848[6];
        tmp42[7] = s_GBT_coinbase___append_support_fo_000a4848[7];
        tmp42[8] = s_GBT_coinbase___append_support_fo_000a4848[8];
        tmp42[9] = s_GBT_coinbase___append_support_fo_000a4848[9];
        tmp42[10] = s_GBT_coinbase___append_support_fo_000a4848[10];
        tmp42[11] = s_GBT_coinbase___append_support_fo_000a4848[11];
        tmp42[12] = s_GBT_coinbase___append_support_fo_000a4848[12];
        tmp42[13] = s_GBT_coinbase___append_support_fo_000a4848[13];
        tmp42[14] = s_GBT_coinbase___append_support_fo_000a4848[14];
        tmp42[15] = s_GBT_coinbase___append_support_fo_000a4848[15];
        tmp42[16] = s_GBT_coinbase___append_support_fo_000a4848[16];
        tmp42[17] = s_GBT_coinbase___append_support_fo_000a4848[17];
        tmp42[18] = s_GBT_coinbase___append_support_fo_000a4848[18];
        tmp42[19] = s_GBT_coinbase___append_support_fo_000a4848[19];
        tmp42[20] = s_GBT_coinbase___append_support_fo_000a4848[20];
        tmp42[21] = s_GBT_coinbase___append_support_fo_000a4848[21];
        tmp42[22] = s_GBT_coinbase___append_support_fo_000a4848[22];
        tmp42[23] = s_GBT_coinbase___append_support_fo_000a4848[23];
        tmp42[24] = s_GBT_coinbase___append_support_fo_000a4848[24];
        tmp42[25] = s_GBT_coinbase___append_support_fo_000a4848[25];
        tmp42[26] = s_GBT_coinbase___append_support_fo_000a4848[26];
        tmp42[27] = s_GBT_coinbase___append_support_fo_000a4848[27];
        tmp42[28] = s_GBT_coinbase___append_support_fo_000a4848[28];
        tmp42[29] = s_GBT_coinbase___append_support_fo_000a4848[29];
        tmp42[30] = s_GBT_coinbase___append_support_fo_000a4848[30];
        tmp42[31] = s_GBT_coinbase___append_support_fo_000a4848[31];
        tmp42[32] = s_GBT_coinbase___append_support_fo_000a4848[32];
        tmp42[33] = s_GBT_coinbase___append_support_fo_000a4848[33];
        tmp42[34] = s_GBT_coinbase___append_support_fo_000a4848[34];
        tmp42[35] = s_GBT_coinbase___append_support_fo_000a4848[35];
        tmp42[36] = s_GBT_coinbase___append_support_fo_000a4848[36];
        tmp42[37] = s_GBT_coinbase___append_support_fo_000a4848[37];
        tmp42[38] = s_GBT_coinbase___append_support_fo_000a4848[38];
        tmp42[39] = s_GBT_coinbase___append_support_fo_000a4848[39];
        tmp42[40] = s_GBT_coinbase___append_support_fo_000a4848[40];
        tmp42[41] = s_GBT_coinbase___append_support_fo_000a4848[41];
        tmp42[42] = s_GBT_coinbase___append_support_fo_000a4848[42];
        tmp42[43] = s_GBT_coinbase___append_support_fo_000a4848[43];
        tmp42[44] = s_GBT_coinbase___append_support_fo_000a4848[44];
        tmp42[45] = s_GBT_coinbase___append_support_fo_000a4848[45];
        tmp42[46] = s_GBT_coinbase___append_support_fo_000a4848[46];
        tmp42[47] = s_GBT_coinbase___append_support_fo_000a4848[47];
        tmp42[48] = s_GBT_coinbase___append_support_fo_000a4848[48];
        tmp42[49] = s_GBT_coinbase___append_support_fo_000a4848[49];
        tmp42[50] = s_GBT_coinbase___append_support_fo_000a4848[50];
        tmp42[51] = s_GBT_coinbase___append_support_fo_000a4848[51];
        tmp42[52] = s_GBT_coinbase___append_support_fo_000a4848[52];
        tmp42[53] = s_GBT_coinbase___append_support_fo_000a4848[53];
        tmp42[54] = s_GBT_coinbase___append_support_fo_000a4848[54];
        tmp42[55] = s_GBT_coinbase___append_support_fo_000a4848[55];
        tmp42[56] = s_GBT_coinbase___append_support_fo_000a4848[56];
        tmp42[57] = s_GBT_coinbase___append_support_fo_000a4848[57];
        tmp42[58] = s_GBT_coinbase___append_support_fo_000a4848[58];
        tmp42[59] = s_GBT_coinbase___append_support_fo_000a4848[59];
        tmp42._60_2_ = (undefined2)ram0x000a4884;
        tmp42[62] = (char)((uint)ram0x000a4884 >> 0x10);
        _applog(7,tmp42,false);
      }
    }
    cgtime(&tv_getwork);
    cgtime(&tv_getwork_reply);
    if (((pool->stratum_url == (char *)0x0) || (opt_fix_protocol == true)) ||
       (_Var1 = stratum_works(pool), !_Var1)) break;
    if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
      snprintf(tmp42,0x800,"Switching pool %d %s to %s",pool->pool_no);
      _applog(5,tmp42,false);
    }
    if (pool->rpc_url == (char *)0x0) {
      pcVar2 = strdup(pool->stratum_url);
      pool->rpc_url = pcVar2;
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

