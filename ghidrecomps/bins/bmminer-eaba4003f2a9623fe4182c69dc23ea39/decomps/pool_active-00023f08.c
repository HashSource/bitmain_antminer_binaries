
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
        tmp42[0] = s_CURL_initialisation_failed_00073b9c[0];
        tmp42[1] = s_CURL_initialisation_failed_00073b9c[1];
        tmp42[2] = s_CURL_initialisation_failed_00073b9c[2];
        tmp42[3] = s_CURL_initialisation_failed_00073b9c[3];
        tmp42[4] = s_CURL_initialisation_failed_00073b9c[4];
        tmp42[5] = s_CURL_initialisation_failed_00073b9c[5];
        tmp42[6] = s_CURL_initialisation_failed_00073b9c[6];
        tmp42[7] = s_CURL_initialisation_failed_00073b9c[7];
        tmp42[8] = s_CURL_initialisation_failed_00073b9c[8];
        tmp42[9] = s_CURL_initialisation_failed_00073b9c[9];
        tmp42[10] = s_CURL_initialisation_failed_00073b9c[10];
        tmp42[11] = s_CURL_initialisation_failed_00073b9c[11];
        tmp42[12] = s_CURL_initialisation_failed_00073b9c[12];
        tmp42[13] = s_CURL_initialisation_failed_00073b9c[13];
        tmp42[14] = s_CURL_initialisation_failed_00073b9c[14];
        tmp42[15] = s_CURL_initialisation_failed_00073b9c[15];
        tmp42[16] = s_CURL_initialisation_failed_00073b9c[16];
        tmp42[17] = s_CURL_initialisation_failed_00073b9c[17];
        tmp42[18] = s_CURL_initialisation_failed_00073b9c[18];
        tmp42[19] = s_CURL_initialisation_failed_00073b9c[19];
        tmp42[20] = s_CURL_initialisation_failed_00073b9c[20];
        tmp42[21] = s_CURL_initialisation_failed_00073b9c[21];
        tmp42[22] = s_CURL_initialisation_failed_00073b9c[22];
        tmp42[23] = s_CURL_initialisation_failed_00073b9c[23];
        tmp42._24_3_ = (undefined3)ram0x00073bb4;
        _applog(3,tmp42,false);
      }
      return false;
    }
    if (pool->probed != true) {
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        tmp42[0] = s_Probing_for_GBT_support_00073bb8[0];
        tmp42[1] = s_Probing_for_GBT_support_00073bb8[1];
        tmp42[2] = s_Probing_for_GBT_support_00073bb8[2];
        tmp42[3] = s_Probing_for_GBT_support_00073bb8[3];
        tmp42[4] = s_Probing_for_GBT_support_00073bb8[4];
        tmp42[5] = s_Probing_for_GBT_support_00073bb8[5];
        tmp42[6] = s_Probing_for_GBT_support_00073bb8[6];
        tmp42[7] = s_Probing_for_GBT_support_00073bb8[7];
        tmp42[8] = s_Probing_for_GBT_support_00073bb8[8];
        tmp42[9] = s_Probing_for_GBT_support_00073bb8[9];
        tmp42[10] = s_Probing_for_GBT_support_00073bb8[10];
        tmp42[11] = s_Probing_for_GBT_support_00073bb8[11];
        tmp42[12] = s_Probing_for_GBT_support_00073bb8[12];
        tmp42[13] = s_Probing_for_GBT_support_00073bb8[13];
        tmp42[14] = s_Probing_for_GBT_support_00073bb8[14];
        tmp42[15] = s_Probing_for_GBT_support_00073bb8[15];
        tmp42[16] = s_Probing_for_GBT_support_00073bb8[16];
        tmp42[17] = s_Probing_for_GBT_support_00073bb8[17];
        tmp42[18] = s_Probing_for_GBT_support_00073bb8[18];
        tmp42[19] = s_Probing_for_GBT_support_00073bb8[19];
        tmp42[20] = s_Probing_for_GBT_support_00073bb8[20];
        tmp42[21] = s_Probing_for_GBT_support_00073bb8[21];
        tmp42[22] = s_Probing_for_GBT_support_00073bb8[22];
        tmp42[23] = s_Probing_for_GBT_support_00073bb8[23];
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
        tmp42[0] = s_GBT_coinbase___append_support_fo_00073c08[0];
        tmp42[1] = s_GBT_coinbase___append_support_fo_00073c08[1];
        tmp42[2] = s_GBT_coinbase___append_support_fo_00073c08[2];
        tmp42[3] = s_GBT_coinbase___append_support_fo_00073c08[3];
        tmp42[4] = s_GBT_coinbase___append_support_fo_00073c08[4];
        tmp42[5] = s_GBT_coinbase___append_support_fo_00073c08[5];
        tmp42[6] = s_GBT_coinbase___append_support_fo_00073c08[6];
        tmp42[7] = s_GBT_coinbase___append_support_fo_00073c08[7];
        tmp42[8] = s_GBT_coinbase___append_support_fo_00073c08[8];
        tmp42[9] = s_GBT_coinbase___append_support_fo_00073c08[9];
        tmp42[10] = s_GBT_coinbase___append_support_fo_00073c08[10];
        tmp42[11] = s_GBT_coinbase___append_support_fo_00073c08[11];
        tmp42[12] = s_GBT_coinbase___append_support_fo_00073c08[12];
        tmp42[13] = s_GBT_coinbase___append_support_fo_00073c08[13];
        tmp42[14] = s_GBT_coinbase___append_support_fo_00073c08[14];
        tmp42[15] = s_GBT_coinbase___append_support_fo_00073c08[15];
        tmp42[16] = s_GBT_coinbase___append_support_fo_00073c08[16];
        tmp42[17] = s_GBT_coinbase___append_support_fo_00073c08[17];
        tmp42[18] = s_GBT_coinbase___append_support_fo_00073c08[18];
        tmp42[19] = s_GBT_coinbase___append_support_fo_00073c08[19];
        tmp42[20] = s_GBT_coinbase___append_support_fo_00073c08[20];
        tmp42[21] = s_GBT_coinbase___append_support_fo_00073c08[21];
        tmp42[22] = s_GBT_coinbase___append_support_fo_00073c08[22];
        tmp42[23] = s_GBT_coinbase___append_support_fo_00073c08[23];
        tmp42[24] = s_GBT_coinbase___append_support_fo_00073c08[24];
        tmp42[25] = s_GBT_coinbase___append_support_fo_00073c08[25];
        tmp42[26] = s_GBT_coinbase___append_support_fo_00073c08[26];
        tmp42[27] = s_GBT_coinbase___append_support_fo_00073c08[27];
        tmp42[28] = s_GBT_coinbase___append_support_fo_00073c08[28];
        tmp42[29] = s_GBT_coinbase___append_support_fo_00073c08[29];
        tmp42[30] = s_GBT_coinbase___append_support_fo_00073c08[30];
        tmp42[31] = s_GBT_coinbase___append_support_fo_00073c08[31];
        tmp42[32] = s_GBT_coinbase___append_support_fo_00073c08[32];
        tmp42[33] = s_GBT_coinbase___append_support_fo_00073c08[33];
        tmp42[34] = s_GBT_coinbase___append_support_fo_00073c08[34];
        tmp42[35] = s_GBT_coinbase___append_support_fo_00073c08[35];
        tmp42[36] = s_GBT_coinbase___append_support_fo_00073c08[36];
        tmp42[37] = s_GBT_coinbase___append_support_fo_00073c08[37];
        tmp42[38] = s_GBT_coinbase___append_support_fo_00073c08[38];
        tmp42[39] = s_GBT_coinbase___append_support_fo_00073c08[39];
        tmp42[40] = s_GBT_coinbase___append_support_fo_00073c08[40];
        tmp42[41] = s_GBT_coinbase___append_support_fo_00073c08[41];
        tmp42[42] = s_GBT_coinbase___append_support_fo_00073c08[42];
        tmp42[43] = s_GBT_coinbase___append_support_fo_00073c08[43];
        tmp42[44] = s_GBT_coinbase___append_support_fo_00073c08[44];
        tmp42[45] = s_GBT_coinbase___append_support_fo_00073c08[45];
        tmp42[46] = s_GBT_coinbase___append_support_fo_00073c08[46];
        tmp42[47] = s_GBT_coinbase___append_support_fo_00073c08[47];
        tmp42[48] = s_GBT_coinbase___append_support_fo_00073c08[48];
        tmp42[49] = s_GBT_coinbase___append_support_fo_00073c08[49];
        tmp42[50] = s_GBT_coinbase___append_support_fo_00073c08[50];
        tmp42[51] = s_GBT_coinbase___append_support_fo_00073c08[51];
        tmp42[52] = s_GBT_coinbase___append_support_fo_00073c08[52];
        tmp42[53] = s_GBT_coinbase___append_support_fo_00073c08[53];
        tmp42[54] = s_GBT_coinbase___append_support_fo_00073c08[54];
        tmp42[55] = s_GBT_coinbase___append_support_fo_00073c08[55];
        tmp42[56] = s_GBT_coinbase___append_support_fo_00073c08[56];
        tmp42[57] = s_GBT_coinbase___append_support_fo_00073c08[57];
        tmp42[58] = s_GBT_coinbase___append_support_fo_00073c08[58];
        tmp42[59] = s_GBT_coinbase___append_support_fo_00073c08[59];
        tmp42._60_2_ = (undefined2)ram0x00073c44;
        tmp42[62] = (char)((uint)ram0x00073c44 >> 0x10);
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

