
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
        tmp42[0] = s_CURL_initialisation_failed_0008d420[0];
        tmp42[1] = s_CURL_initialisation_failed_0008d420[1];
        tmp42[2] = s_CURL_initialisation_failed_0008d420[2];
        tmp42[3] = s_CURL_initialisation_failed_0008d420[3];
        tmp42[4] = s_CURL_initialisation_failed_0008d420[4];
        tmp42[5] = s_CURL_initialisation_failed_0008d420[5];
        tmp42[6] = s_CURL_initialisation_failed_0008d420[6];
        tmp42[7] = s_CURL_initialisation_failed_0008d420[7];
        tmp42[8] = s_CURL_initialisation_failed_0008d420[8];
        tmp42[9] = s_CURL_initialisation_failed_0008d420[9];
        tmp42[10] = s_CURL_initialisation_failed_0008d420[10];
        tmp42[11] = s_CURL_initialisation_failed_0008d420[11];
        tmp42[12] = s_CURL_initialisation_failed_0008d420[12];
        tmp42[13] = s_CURL_initialisation_failed_0008d420[13];
        tmp42[14] = s_CURL_initialisation_failed_0008d420[14];
        tmp42[15] = s_CURL_initialisation_failed_0008d420[15];
        tmp42[16] = s_CURL_initialisation_failed_0008d420[16];
        tmp42[17] = s_CURL_initialisation_failed_0008d420[17];
        tmp42[18] = s_CURL_initialisation_failed_0008d420[18];
        tmp42[19] = s_CURL_initialisation_failed_0008d420[19];
        tmp42[20] = s_CURL_initialisation_failed_0008d420[20];
        tmp42[21] = s_CURL_initialisation_failed_0008d420[21];
        tmp42[22] = s_CURL_initialisation_failed_0008d420[22];
        tmp42[23] = s_CURL_initialisation_failed_0008d420[23];
        tmp42._24_3_ = (undefined3)ram0x0008d438;
        _applog(3,tmp42,false);
      }
      return false;
    }
    if (pool->probed != true) {
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        tmp42[0] = s_Probing_for_GBT_support_0008d43c[0];
        tmp42[1] = s_Probing_for_GBT_support_0008d43c[1];
        tmp42[2] = s_Probing_for_GBT_support_0008d43c[2];
        tmp42[3] = s_Probing_for_GBT_support_0008d43c[3];
        tmp42[4] = s_Probing_for_GBT_support_0008d43c[4];
        tmp42[5] = s_Probing_for_GBT_support_0008d43c[5];
        tmp42[6] = s_Probing_for_GBT_support_0008d43c[6];
        tmp42[7] = s_Probing_for_GBT_support_0008d43c[7];
        tmp42[8] = s_Probing_for_GBT_support_0008d43c[8];
        tmp42[9] = s_Probing_for_GBT_support_0008d43c[9];
        tmp42[10] = s_Probing_for_GBT_support_0008d43c[10];
        tmp42[11] = s_Probing_for_GBT_support_0008d43c[11];
        tmp42[12] = s_Probing_for_GBT_support_0008d43c[12];
        tmp42[13] = s_Probing_for_GBT_support_0008d43c[13];
        tmp42[14] = s_Probing_for_GBT_support_0008d43c[14];
        tmp42[15] = s_Probing_for_GBT_support_0008d43c[15];
        tmp42[16] = s_Probing_for_GBT_support_0008d43c[16];
        tmp42[17] = s_Probing_for_GBT_support_0008d43c[17];
        tmp42[18] = s_Probing_for_GBT_support_0008d43c[18];
        tmp42[19] = s_Probing_for_GBT_support_0008d43c[19];
        tmp42[20] = s_Probing_for_GBT_support_0008d43c[20];
        tmp42[21] = s_Probing_for_GBT_support_0008d43c[21];
        tmp42[22] = s_Probing_for_GBT_support_0008d43c[22];
        tmp42[23] = s_Probing_for_GBT_support_0008d43c[23];
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
        tmp42[0] = s_GBT_coinbase___append_support_fo_0008d48c[0];
        tmp42[1] = s_GBT_coinbase___append_support_fo_0008d48c[1];
        tmp42[2] = s_GBT_coinbase___append_support_fo_0008d48c[2];
        tmp42[3] = s_GBT_coinbase___append_support_fo_0008d48c[3];
        tmp42[4] = s_GBT_coinbase___append_support_fo_0008d48c[4];
        tmp42[5] = s_GBT_coinbase___append_support_fo_0008d48c[5];
        tmp42[6] = s_GBT_coinbase___append_support_fo_0008d48c[6];
        tmp42[7] = s_GBT_coinbase___append_support_fo_0008d48c[7];
        tmp42[8] = s_GBT_coinbase___append_support_fo_0008d48c[8];
        tmp42[9] = s_GBT_coinbase___append_support_fo_0008d48c[9];
        tmp42[10] = s_GBT_coinbase___append_support_fo_0008d48c[10];
        tmp42[11] = s_GBT_coinbase___append_support_fo_0008d48c[11];
        tmp42[12] = s_GBT_coinbase___append_support_fo_0008d48c[12];
        tmp42[13] = s_GBT_coinbase___append_support_fo_0008d48c[13];
        tmp42[14] = s_GBT_coinbase___append_support_fo_0008d48c[14];
        tmp42[15] = s_GBT_coinbase___append_support_fo_0008d48c[15];
        tmp42[16] = s_GBT_coinbase___append_support_fo_0008d48c[16];
        tmp42[17] = s_GBT_coinbase___append_support_fo_0008d48c[17];
        tmp42[18] = s_GBT_coinbase___append_support_fo_0008d48c[18];
        tmp42[19] = s_GBT_coinbase___append_support_fo_0008d48c[19];
        tmp42[20] = s_GBT_coinbase___append_support_fo_0008d48c[20];
        tmp42[21] = s_GBT_coinbase___append_support_fo_0008d48c[21];
        tmp42[22] = s_GBT_coinbase___append_support_fo_0008d48c[22];
        tmp42[23] = s_GBT_coinbase___append_support_fo_0008d48c[23];
        tmp42[24] = s_GBT_coinbase___append_support_fo_0008d48c[24];
        tmp42[25] = s_GBT_coinbase___append_support_fo_0008d48c[25];
        tmp42[26] = s_GBT_coinbase___append_support_fo_0008d48c[26];
        tmp42[27] = s_GBT_coinbase___append_support_fo_0008d48c[27];
        tmp42[28] = s_GBT_coinbase___append_support_fo_0008d48c[28];
        tmp42[29] = s_GBT_coinbase___append_support_fo_0008d48c[29];
        tmp42[30] = s_GBT_coinbase___append_support_fo_0008d48c[30];
        tmp42[31] = s_GBT_coinbase___append_support_fo_0008d48c[31];
        tmp42[32] = s_GBT_coinbase___append_support_fo_0008d48c[32];
        tmp42[33] = s_GBT_coinbase___append_support_fo_0008d48c[33];
        tmp42[34] = s_GBT_coinbase___append_support_fo_0008d48c[34];
        tmp42[35] = s_GBT_coinbase___append_support_fo_0008d48c[35];
        tmp42[36] = s_GBT_coinbase___append_support_fo_0008d48c[36];
        tmp42[37] = s_GBT_coinbase___append_support_fo_0008d48c[37];
        tmp42[38] = s_GBT_coinbase___append_support_fo_0008d48c[38];
        tmp42[39] = s_GBT_coinbase___append_support_fo_0008d48c[39];
        tmp42[40] = s_GBT_coinbase___append_support_fo_0008d48c[40];
        tmp42[41] = s_GBT_coinbase___append_support_fo_0008d48c[41];
        tmp42[42] = s_GBT_coinbase___append_support_fo_0008d48c[42];
        tmp42[43] = s_GBT_coinbase___append_support_fo_0008d48c[43];
        tmp42[44] = s_GBT_coinbase___append_support_fo_0008d48c[44];
        tmp42[45] = s_GBT_coinbase___append_support_fo_0008d48c[45];
        tmp42[46] = s_GBT_coinbase___append_support_fo_0008d48c[46];
        tmp42[47] = s_GBT_coinbase___append_support_fo_0008d48c[47];
        tmp42[48] = s_GBT_coinbase___append_support_fo_0008d48c[48];
        tmp42[49] = s_GBT_coinbase___append_support_fo_0008d48c[49];
        tmp42[50] = s_GBT_coinbase___append_support_fo_0008d48c[50];
        tmp42[51] = s_GBT_coinbase___append_support_fo_0008d48c[51];
        tmp42[52] = s_GBT_coinbase___append_support_fo_0008d48c[52];
        tmp42[53] = s_GBT_coinbase___append_support_fo_0008d48c[53];
        tmp42[54] = s_GBT_coinbase___append_support_fo_0008d48c[54];
        tmp42[55] = s_GBT_coinbase___append_support_fo_0008d48c[55];
        tmp42[56] = s_GBT_coinbase___append_support_fo_0008d48c[56];
        tmp42[57] = s_GBT_coinbase___append_support_fo_0008d48c[57];
        tmp42[58] = s_GBT_coinbase___append_support_fo_0008d48c[58];
        tmp42[59] = s_GBT_coinbase___append_support_fo_0008d48c[59];
        tmp42._60_2_ = (undefined2)ram0x0008d4c8;
        tmp42[62] = (char)((uint)ram0x0008d4c8 >> 0x10);
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

