
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

_Bool initiate_stratum(pool *pool)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  _Bool _Var4;
  size_t sVar5;
  send_ret sVar6;
  char *pcVar7;
  json_t *pjVar8;
  json_t *json;
  char *s_00;
  uint uVar9;
  int iVar10;
  uchar *puVar11;
  json_int_t jVar12;
  char *in_stack_ffffd6c0;
  undefined4 in_stack_ffffd6c4;
  pool *pool_local;
  char tmp42 [2048];
  json_error_t err;
  char s [8192];
  int n2size;
  char *nonce1;
  char *sessionid;
  json_t *err_val;
  json_t *res_val;
  char *sret;
  char *ss;
  json_t *val;
  _Bool sockd;
  _Bool noresume;
  _Bool recvd;
  _Bool ret;
  
  ret = false;
  bVar1 = false;
  bVar2 = false;
  val = (json_t *)0x0;
  while( true ) {
    cgsleep_us(CONCAT44(in_stack_ffffd6c4,in_stack_ffffd6c0));
    if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
      tmp42[0] = s_initiate_stratum_00088b58[0];
      tmp42[1] = s_initiate_stratum_00088b58[1];
      tmp42[2] = s_initiate_stratum_00088b58[2];
      tmp42[3] = s_initiate_stratum_00088b58[3];
      tmp42[4] = s_initiate_stratum_00088b58[4];
      tmp42[5] = s_initiate_stratum_00088b58[5];
      tmp42[6] = s_initiate_stratum_00088b58[6];
      tmp42[7] = s_initiate_stratum_00088b58[7];
      tmp42[8] = s_initiate_stratum_00088b58[8];
      tmp42[9] = s_initiate_stratum_00088b58[9];
      tmp42[10] = s_initiate_stratum_00088b58[10];
      tmp42[11] = s_initiate_stratum_00088b58[11];
      tmp42[12] = s_initiate_stratum_00088b58[12];
      tmp42[13] = s_initiate_stratum_00088b58[13];
      tmp42[14] = s_initiate_stratum_00088b58[14];
      tmp42[15] = s_initiate_stratum_00088b58[15];
      tmp42[16] = (char)ram0x00088b68;
      _applog(5,tmp42,false);
    }
    _Var4 = setup_stratum_socket(pool);
    iVar10 = swork_id;
    if (_Var4) {
      bVar3 = true;
      if (bVar1) {
        clear_sock(pool);
        swork_id = swork_id + 1;
        sprintf(s,"{\"id\": %d, \"method\": \"mining.subscribe\", \"params\": []}");
      }
      else if (pool->sessionid == (char *)0x0) {
        swork_id = swork_id + 1;
        sprintf(s,"{\"id\": %d, \"method\": \"mining.subscribe\", \"params\": [\"cgminer/2.0.0\"]}")
        ;
      }
      else {
        swork_id = swork_id + 1;
        sprintf(s,
                "{\"id\": %d, \"method\": \"mining.subscribe\", \"params\": [\"cgminer/2.0.0\", \"%s\"]}"
                ,iVar10,pool->sessionid);
      }
      sVar5 = strlen(s);
      sVar6 = __stratum_send(pool,s,sVar5);
      if (sVar6 == SEND_OK) {
        _Var4 = socket_full(pool,0x3c);
        if (_Var4) {
          pcVar7 = recv_line(pool);
          if (pcVar7 != (char *)0x0) {
            bVar1 = true;
            val = json_loads(pcVar7,0,&err);
            free(pcVar7);
            if (val == (json_t *)0x0) {
              if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
                in_stack_ffffd6c0 = err.text;
                snprintf(tmp42,0x800,"JSON decode failed(%d): %s",err.line);
                _applog(6,tmp42,false);
              }
            }
            else {
              pjVar8 = json_object_get(val,"result");
              json = json_object_get(val,"error");
              if (((pjVar8 == (json_t *)0x0) ||
                  ((pjVar8 != (json_t *)0x0 && (pjVar8->type == JSON_NULL)))) ||
                 ((json != (json_t *)0x0 && ((json == (json_t *)0x0 || (json->type != JSON_NULL)))))
                 ) {
                if (json == (json_t *)0x0) {
                  ss = strdup("(unknown reason)");
                }
                else {
                  ss = json_dumps(json,3);
                }
                if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
                  snprintf(tmp42,0x800,"JSON-RPC decode failed: %s",ss);
                  _applog(6,tmp42,false);
                }
                free(ss);
              }
              else {
                pcVar7 = get_sessionid(pjVar8);
                if (((pcVar7 == (char *)0x0) && (opt_debug != false)) &&
                   ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
                  tmp42[0] = s_Failed_to_get_sessionid_in_initi_00088c38[0];
                  tmp42[1] = s_Failed_to_get_sessionid_in_initi_00088c38[1];
                  tmp42[2] = s_Failed_to_get_sessionid_in_initi_00088c38[2];
                  tmp42[3] = s_Failed_to_get_sessionid_in_initi_00088c38[3];
                  tmp42[4] = s_Failed_to_get_sessionid_in_initi_00088c38[4];
                  tmp42[5] = s_Failed_to_get_sessionid_in_initi_00088c38[5];
                  tmp42[6] = s_Failed_to_get_sessionid_in_initi_00088c38[6];
                  tmp42[7] = s_Failed_to_get_sessionid_in_initi_00088c38[7];
                  tmp42[8] = s_Failed_to_get_sessionid_in_initi_00088c38[8];
                  tmp42[9] = s_Failed_to_get_sessionid_in_initi_00088c38[9];
                  tmp42[10] = s_Failed_to_get_sessionid_in_initi_00088c38[10];
                  tmp42[11] = s_Failed_to_get_sessionid_in_initi_00088c38[11];
                  tmp42[12] = s_Failed_to_get_sessionid_in_initi_00088c38[12];
                  tmp42[13] = s_Failed_to_get_sessionid_in_initi_00088c38[13];
                  tmp42[14] = s_Failed_to_get_sessionid_in_initi_00088c38[14];
                  tmp42[15] = s_Failed_to_get_sessionid_in_initi_00088c38[15];
                  tmp42[16] = s_Failed_to_get_sessionid_in_initi_00088c38[16];
                  tmp42[17] = s_Failed_to_get_sessionid_in_initi_00088c38[17];
                  tmp42[18] = s_Failed_to_get_sessionid_in_initi_00088c38[18];
                  tmp42[19] = s_Failed_to_get_sessionid_in_initi_00088c38[19];
                  tmp42[20] = s_Failed_to_get_sessionid_in_initi_00088c38[20];
                  tmp42[21] = s_Failed_to_get_sessionid_in_initi_00088c38[21];
                  tmp42[22] = s_Failed_to_get_sessionid_in_initi_00088c38[22];
                  tmp42[23] = s_Failed_to_get_sessionid_in_initi_00088c38[23];
                  tmp42[24] = s_Failed_to_get_sessionid_in_initi_00088c38[24];
                  tmp42[25] = s_Failed_to_get_sessionid_in_initi_00088c38[25];
                  tmp42[26] = s_Failed_to_get_sessionid_in_initi_00088c38[26];
                  tmp42[27] = s_Failed_to_get_sessionid_in_initi_00088c38[27];
                  tmp42[28] = s_Failed_to_get_sessionid_in_initi_00088c38[28];
                  tmp42[29] = s_Failed_to_get_sessionid_in_initi_00088c38[29];
                  tmp42[30] = s_Failed_to_get_sessionid_in_initi_00088c38[30];
                  tmp42[31] = s_Failed_to_get_sessionid_in_initi_00088c38[31];
                  tmp42[32] = s_Failed_to_get_sessionid_in_initi_00088c38[32];
                  tmp42[33] = s_Failed_to_get_sessionid_in_initi_00088c38[33];
                  tmp42[34] = s_Failed_to_get_sessionid_in_initi_00088c38[34];
                  tmp42[35] = s_Failed_to_get_sessionid_in_initi_00088c38[35];
                  tmp42[36] = s_Failed_to_get_sessionid_in_initi_00088c38[36];
                  tmp42[37] = s_Failed_to_get_sessionid_in_initi_00088c38[37];
                  tmp42[38] = s_Failed_to_get_sessionid_in_initi_00088c38[38];
                  tmp42[39] = s_Failed_to_get_sessionid_in_initi_00088c38[39];
                  tmp42[40] = s_Failed_to_get_sessionid_in_initi_00088c38[40];
                  tmp42[41] = s_Failed_to_get_sessionid_in_initi_00088c38[41];
                  tmp42[42] = s_Failed_to_get_sessionid_in_initi_00088c38[42];
                  tmp42[43] = s_Failed_to_get_sessionid_in_initi_00088c38[43];
                  _applog(7,tmp42,false);
                }
                s_00 = json_array_string(pjVar8,1);
                _Var4 = _valid_hex(s_00,"util.c","initiate_stratum",0xcfe);
                if (_Var4) {
                  pjVar8 = json_array_get(pjVar8,2);
                  jVar12 = json_integer_value(pjVar8);
                  uVar9 = (uint)jVar12;
                  if (((int)uVar9 < 2) || (0x10 < (int)uVar9)) {
                    if ((use_syslog != false) || ((opt_log_output != false || (5 < opt_log_level))))
                    {
                      tmp42[0] = s_Failed_to_get_valid_n2size_in_in_00088c94[0];
                      tmp42[1] = s_Failed_to_get_valid_n2size_in_in_00088c94[1];
                      tmp42[2] = s_Failed_to_get_valid_n2size_in_in_00088c94[2];
                      tmp42[3] = s_Failed_to_get_valid_n2size_in_in_00088c94[3];
                      tmp42[4] = s_Failed_to_get_valid_n2size_in_in_00088c94[4];
                      tmp42[5] = s_Failed_to_get_valid_n2size_in_in_00088c94[5];
                      tmp42[6] = s_Failed_to_get_valid_n2size_in_in_00088c94[6];
                      tmp42[7] = s_Failed_to_get_valid_n2size_in_in_00088c94[7];
                      tmp42[8] = s_Failed_to_get_valid_n2size_in_in_00088c94[8];
                      tmp42[9] = s_Failed_to_get_valid_n2size_in_in_00088c94[9];
                      tmp42[10] = s_Failed_to_get_valid_n2size_in_in_00088c94[10];
                      tmp42[11] = s_Failed_to_get_valid_n2size_in_in_00088c94[11];
                      tmp42[12] = s_Failed_to_get_valid_n2size_in_in_00088c94[12];
                      tmp42[13] = s_Failed_to_get_valid_n2size_in_in_00088c94[13];
                      tmp42[14] = s_Failed_to_get_valid_n2size_in_in_00088c94[14];
                      tmp42[15] = s_Failed_to_get_valid_n2size_in_in_00088c94[15];
                      tmp42[16] = s_Failed_to_get_valid_n2size_in_in_00088c94[16];
                      tmp42[17] = s_Failed_to_get_valid_n2size_in_in_00088c94[17];
                      tmp42[18] = s_Failed_to_get_valid_n2size_in_in_00088c94[18];
                      tmp42[19] = s_Failed_to_get_valid_n2size_in_in_00088c94[19];
                      tmp42[20] = s_Failed_to_get_valid_n2size_in_in_00088c94[20];
                      tmp42[21] = s_Failed_to_get_valid_n2size_in_in_00088c94[21];
                      tmp42[22] = s_Failed_to_get_valid_n2size_in_in_00088c94[22];
                      tmp42[23] = s_Failed_to_get_valid_n2size_in_in_00088c94[23];
                      tmp42[24] = s_Failed_to_get_valid_n2size_in_in_00088c94[24];
                      tmp42[25] = s_Failed_to_get_valid_n2size_in_in_00088c94[25];
                      tmp42[26] = s_Failed_to_get_valid_n2size_in_in_00088c94[26];
                      tmp42[27] = s_Failed_to_get_valid_n2size_in_in_00088c94[27];
                      tmp42[28] = s_Failed_to_get_valid_n2size_in_in_00088c94[28];
                      tmp42[29] = s_Failed_to_get_valid_n2size_in_in_00088c94[29];
                      tmp42[30] = s_Failed_to_get_valid_n2size_in_in_00088c94[30];
                      tmp42[31] = s_Failed_to_get_valid_n2size_in_in_00088c94[31];
                      tmp42[32] = s_Failed_to_get_valid_n2size_in_in_00088c94[32];
                      tmp42[33] = s_Failed_to_get_valid_n2size_in_in_00088c94[33];
                      tmp42[34] = s_Failed_to_get_valid_n2size_in_in_00088c94[34];
                      tmp42[35] = s_Failed_to_get_valid_n2size_in_in_00088c94[35];
                      tmp42[36] = s_Failed_to_get_valid_n2size_in_in_00088c94[36];
                      tmp42[37] = s_Failed_to_get_valid_n2size_in_in_00088c94[37];
                      tmp42[38] = s_Failed_to_get_valid_n2size_in_in_00088c94[38];
                      tmp42[39] = s_Failed_to_get_valid_n2size_in_in_00088c94[39];
                      tmp42[40] = s_Failed_to_get_valid_n2size_in_in_00088c94[40];
                      tmp42[41] = s_Failed_to_get_valid_n2size_in_in_00088c94[41];
                      tmp42[42] = s_Failed_to_get_valid_n2size_in_in_00088c94[42];
                      tmp42[43] = s_Failed_to_get_valid_n2size_in_in_00088c94[43];
                      tmp42._44_3_ = (undefined3)ram0x00088cc0;
                      _applog(6,tmp42,false);
                    }
                    free(pcVar7);
                    free(s_00);
                  }
                  else {
                    if ((((pcVar7 != (char *)0x0) && (pool->sessionid != (char *)0x0)) &&
                        (iVar10 = strcmp(pcVar7,pool->sessionid), iVar10 == 0)) &&
                       (((use_syslog != false || (opt_log_output != false)) || (4 < opt_log_level)))
                       ) {
                      snprintf(tmp42,0x800,
                               "Pool %d successfully negotiated resume with the same session ID",
                               pool->pool_no);
                      _applog(5,tmp42,false);
                    }
                    _cg_wlock(&pool->data_lock,"util.c","initiate_stratum",0xd13);
                    pool->sessionid = pcVar7;
                    pool->nonce1 = s_00;
                    sVar5 = strlen(s_00);
                    pool->n1_len = sVar5 >> 1;
                    free(pool->nonce1bin);
                    in_stack_ffffd6c0 = (char *)0xd1a;
                    puVar11 = (uchar *)_cgcalloc(pool->n1_len,1,"util.c","initiate_stratum",0xd1a);
                    pool->nonce1bin = puVar11;
                    hex2bin(pool->nonce1bin,pool->nonce1,pool->n1_len);
                    pool->n2size = uVar9;
                    _cg_wunlock(&pool->data_lock,"util.c","initiate_stratum",0xd1d);
                    if (((pcVar7 != (char *)0x0) && (opt_debug != false)) &&
                       ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))
                       ) {
                      in_stack_ffffd6c0 = pool->sessionid;
                      snprintf(tmp42,0x800,"Pool %d stratum session id: %s",pool->pool_no);
                      _applog(7,tmp42,false);
                    }
                    ret = true;
                  }
                }
                else {
                  if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
                    tmp42[0] = s_Failed_to_get_valid_nonce1_in_in_00088c64[0];
                    tmp42[1] = s_Failed_to_get_valid_nonce1_in_in_00088c64[1];
                    tmp42[2] = s_Failed_to_get_valid_nonce1_in_in_00088c64[2];
                    tmp42[3] = s_Failed_to_get_valid_nonce1_in_in_00088c64[3];
                    tmp42[4] = s_Failed_to_get_valid_nonce1_in_in_00088c64[4];
                    tmp42[5] = s_Failed_to_get_valid_nonce1_in_in_00088c64[5];
                    tmp42[6] = s_Failed_to_get_valid_nonce1_in_in_00088c64[6];
                    tmp42[7] = s_Failed_to_get_valid_nonce1_in_in_00088c64[7];
                    tmp42[8] = s_Failed_to_get_valid_nonce1_in_in_00088c64[8];
                    tmp42[9] = s_Failed_to_get_valid_nonce1_in_in_00088c64[9];
                    tmp42[10] = s_Failed_to_get_valid_nonce1_in_in_00088c64[10];
                    tmp42[11] = s_Failed_to_get_valid_nonce1_in_in_00088c64[11];
                    tmp42[12] = s_Failed_to_get_valid_nonce1_in_in_00088c64[12];
                    tmp42[13] = s_Failed_to_get_valid_nonce1_in_in_00088c64[13];
                    tmp42[14] = s_Failed_to_get_valid_nonce1_in_in_00088c64[14];
                    tmp42[15] = s_Failed_to_get_valid_nonce1_in_in_00088c64[15];
                    tmp42[16] = s_Failed_to_get_valid_nonce1_in_in_00088c64[16];
                    tmp42[17] = s_Failed_to_get_valid_nonce1_in_in_00088c64[17];
                    tmp42[18] = s_Failed_to_get_valid_nonce1_in_in_00088c64[18];
                    tmp42[19] = s_Failed_to_get_valid_nonce1_in_in_00088c64[19];
                    tmp42[20] = s_Failed_to_get_valid_nonce1_in_in_00088c64[20];
                    tmp42[21] = s_Failed_to_get_valid_nonce1_in_in_00088c64[21];
                    tmp42[22] = s_Failed_to_get_valid_nonce1_in_in_00088c64[22];
                    tmp42[23] = s_Failed_to_get_valid_nonce1_in_in_00088c64[23];
                    tmp42[24] = s_Failed_to_get_valid_nonce1_in_in_00088c64[24];
                    tmp42[25] = s_Failed_to_get_valid_nonce1_in_in_00088c64[25];
                    tmp42[26] = s_Failed_to_get_valid_nonce1_in_in_00088c64[26];
                    tmp42[27] = s_Failed_to_get_valid_nonce1_in_in_00088c64[27];
                    tmp42[28] = s_Failed_to_get_valid_nonce1_in_in_00088c64[28];
                    tmp42[29] = s_Failed_to_get_valid_nonce1_in_in_00088c64[29];
                    tmp42[30] = s_Failed_to_get_valid_nonce1_in_in_00088c64[30];
                    tmp42[31] = s_Failed_to_get_valid_nonce1_in_in_00088c64[31];
                    tmp42[32] = s_Failed_to_get_valid_nonce1_in_in_00088c64[32];
                    tmp42[33] = s_Failed_to_get_valid_nonce1_in_in_00088c64[33];
                    tmp42[34] = s_Failed_to_get_valid_nonce1_in_in_00088c64[34];
                    tmp42[35] = s_Failed_to_get_valid_nonce1_in_in_00088c64[35];
                    tmp42[36] = s_Failed_to_get_valid_nonce1_in_in_00088c64[36];
                    tmp42[37] = s_Failed_to_get_valid_nonce1_in_in_00088c64[37];
                    tmp42[38] = s_Failed_to_get_valid_nonce1_in_in_00088c64[38];
                    tmp42[39] = s_Failed_to_get_valid_nonce1_in_in_00088c64[39];
                    tmp42[40] = s_Failed_to_get_valid_nonce1_in_in_00088c64[40];
                    tmp42[41] = s_Failed_to_get_valid_nonce1_in_in_00088c64[41];
                    tmp42[42] = s_Failed_to_get_valid_nonce1_in_in_00088c64[42];
                    tmp42[43] = s_Failed_to_get_valid_nonce1_in_in_00088c64[43];
                    tmp42._44_3_ = (undefined3)ram0x00088c90;
                    _applog(6,tmp42,false);
                  }
                  free(pcVar7);
                }
              }
            }
          }
        }
        else if ((opt_debug != false) &&
                (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          tmp42[0] = s_Timed_out_waiting_for_response_i_00088b08[0];
          tmp42[1] = s_Timed_out_waiting_for_response_i_00088b08[1];
          tmp42[2] = s_Timed_out_waiting_for_response_i_00088b08[2];
          tmp42[3] = s_Timed_out_waiting_for_response_i_00088b08[3];
          tmp42[4] = s_Timed_out_waiting_for_response_i_00088b08[4];
          tmp42[5] = s_Timed_out_waiting_for_response_i_00088b08[5];
          tmp42[6] = s_Timed_out_waiting_for_response_i_00088b08[6];
          tmp42[7] = s_Timed_out_waiting_for_response_i_00088b08[7];
          tmp42[8] = s_Timed_out_waiting_for_response_i_00088b08[8];
          tmp42[9] = s_Timed_out_waiting_for_response_i_00088b08[9];
          tmp42[10] = s_Timed_out_waiting_for_response_i_00088b08[10];
          tmp42[11] = s_Timed_out_waiting_for_response_i_00088b08[11];
          tmp42[12] = s_Timed_out_waiting_for_response_i_00088b08[12];
          tmp42[13] = s_Timed_out_waiting_for_response_i_00088b08[13];
          tmp42[14] = s_Timed_out_waiting_for_response_i_00088b08[14];
          tmp42[15] = s_Timed_out_waiting_for_response_i_00088b08[15];
          tmp42[16] = s_Timed_out_waiting_for_response_i_00088b08[16];
          tmp42[17] = s_Timed_out_waiting_for_response_i_00088b08[17];
          tmp42[18] = s_Timed_out_waiting_for_response_i_00088b08[18];
          tmp42[19] = s_Timed_out_waiting_for_response_i_00088b08[19];
          tmp42[20] = s_Timed_out_waiting_for_response_i_00088b08[20];
          tmp42[21] = s_Timed_out_waiting_for_response_i_00088b08[21];
          tmp42[22] = s_Timed_out_waiting_for_response_i_00088b08[22];
          tmp42[23] = s_Timed_out_waiting_for_response_i_00088b08[23];
          tmp42[24] = s_Timed_out_waiting_for_response_i_00088b08[24];
          tmp42[25] = s_Timed_out_waiting_for_response_i_00088b08[25];
          tmp42[26] = s_Timed_out_waiting_for_response_i_00088b08[26];
          tmp42[27] = s_Timed_out_waiting_for_response_i_00088b08[27];
          tmp42[28] = s_Timed_out_waiting_for_response_i_00088b08[28];
          tmp42[29] = s_Timed_out_waiting_for_response_i_00088b08[29];
          tmp42[30] = s_Timed_out_waiting_for_response_i_00088b08[30];
          tmp42[31] = s_Timed_out_waiting_for_response_i_00088b08[31];
          tmp42[32] = s_Timed_out_waiting_for_response_i_00088b08[32];
          tmp42[33] = s_Timed_out_waiting_for_response_i_00088b08[33];
          tmp42[34] = s_Timed_out_waiting_for_response_i_00088b08[34];
          tmp42[35] = s_Timed_out_waiting_for_response_i_00088b08[35];
          tmp42[36] = s_Timed_out_waiting_for_response_i_00088b08[36];
          tmp42[37] = s_Timed_out_waiting_for_response_i_00088b08[37];
          tmp42[38] = s_Timed_out_waiting_for_response_i_00088b08[38];
          tmp42[39] = s_Timed_out_waiting_for_response_i_00088b08[39];
          tmp42[40] = s_Timed_out_waiting_for_response_i_00088b08[40];
          tmp42[41] = s_Timed_out_waiting_for_response_i_00088b08[41];
          tmp42[42] = s_Timed_out_waiting_for_response_i_00088b08[42];
          tmp42[43] = s_Timed_out_waiting_for_response_i_00088b08[43];
          tmp42[44] = s_Timed_out_waiting_for_response_i_00088b08[44];
          tmp42[45] = s_Timed_out_waiting_for_response_i_00088b08[45];
          tmp42[46] = s_Timed_out_waiting_for_response_i_00088b08[46];
          tmp42[47] = s_Timed_out_waiting_for_response_i_00088b08[47];
          tmp42._48_2_ = (undefined2)ram0x00088b38;
          tmp42[50] = (char)((uint)ram0x00088b38 >> 0x10);
          _applog(7,tmp42,false);
        }
      }
      else if ((opt_debug != false) &&
              (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        tmp42[0] = s_Failed_to_send_s_in_initiate_str_00088ae0[0];
        tmp42[1] = s_Failed_to_send_s_in_initiate_str_00088ae0[1];
        tmp42[2] = s_Failed_to_send_s_in_initiate_str_00088ae0[2];
        tmp42[3] = s_Failed_to_send_s_in_initiate_str_00088ae0[3];
        tmp42[4] = s_Failed_to_send_s_in_initiate_str_00088ae0[4];
        tmp42[5] = s_Failed_to_send_s_in_initiate_str_00088ae0[5];
        tmp42[6] = s_Failed_to_send_s_in_initiate_str_00088ae0[6];
        tmp42[7] = s_Failed_to_send_s_in_initiate_str_00088ae0[7];
        tmp42[8] = s_Failed_to_send_s_in_initiate_str_00088ae0[8];
        tmp42[9] = s_Failed_to_send_s_in_initiate_str_00088ae0[9];
        tmp42[10] = s_Failed_to_send_s_in_initiate_str_00088ae0[10];
        tmp42[11] = s_Failed_to_send_s_in_initiate_str_00088ae0[11];
        tmp42[12] = s_Failed_to_send_s_in_initiate_str_00088ae0[12];
        tmp42[13] = s_Failed_to_send_s_in_initiate_str_00088ae0[13];
        tmp42[14] = s_Failed_to_send_s_in_initiate_str_00088ae0[14];
        tmp42[15] = s_Failed_to_send_s_in_initiate_str_00088ae0[15];
        tmp42[16] = s_Failed_to_send_s_in_initiate_str_00088ae0[16];
        tmp42[17] = s_Failed_to_send_s_in_initiate_str_00088ae0[17];
        tmp42[18] = s_Failed_to_send_s_in_initiate_str_00088ae0[18];
        tmp42[19] = s_Failed_to_send_s_in_initiate_str_00088ae0[19];
        tmp42[20] = s_Failed_to_send_s_in_initiate_str_00088ae0[20];
        tmp42[21] = s_Failed_to_send_s_in_initiate_str_00088ae0[21];
        tmp42[22] = s_Failed_to_send_s_in_initiate_str_00088ae0[22];
        tmp42[23] = s_Failed_to_send_s_in_initiate_str_00088ae0[23];
        tmp42[24] = s_Failed_to_send_s_in_initiate_str_00088ae0[24];
        tmp42[25] = s_Failed_to_send_s_in_initiate_str_00088ae0[25];
        tmp42[26] = s_Failed_to_send_s_in_initiate_str_00088ae0[26];
        tmp42[27] = s_Failed_to_send_s_in_initiate_str_00088ae0[27];
        tmp42[28] = s_Failed_to_send_s_in_initiate_str_00088ae0[28];
        tmp42[29] = s_Failed_to_send_s_in_initiate_str_00088ae0[29];
        tmp42[30] = s_Failed_to_send_s_in_initiate_str_00088ae0[30];
        tmp42[31] = s_Failed_to_send_s_in_initiate_str_00088ae0[31];
        tmp42[32] = s_Failed_to_send_s_in_initiate_str_00088ae0[32];
        tmp42[33] = s_Failed_to_send_s_in_initiate_str_00088ae0[33];
        tmp42[34] = s_Failed_to_send_s_in_initiate_str_00088ae0[34];
        tmp42[35] = s_Failed_to_send_s_in_initiate_str_00088ae0[35];
        tmp42[36] = (char)ram0x00088b04;
        _applog(7,tmp42,false);
      }
    }
    else {
      bVar3 = false;
    }
    if (ret != false) break;
    if ((!bVar1) || (bVar2)) {
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        tmp42[0] = s_Initiate_stratum_failed_00088d94[0];
        tmp42[1] = s_Initiate_stratum_failed_00088d94[1];
        tmp42[2] = s_Initiate_stratum_failed_00088d94[2];
        tmp42[3] = s_Initiate_stratum_failed_00088d94[3];
        tmp42[4] = s_Initiate_stratum_failed_00088d94[4];
        tmp42[5] = s_Initiate_stratum_failed_00088d94[5];
        tmp42[6] = s_Initiate_stratum_failed_00088d94[6];
        tmp42[7] = s_Initiate_stratum_failed_00088d94[7];
        tmp42[8] = s_Initiate_stratum_failed_00088d94[8];
        tmp42[9] = s_Initiate_stratum_failed_00088d94[9];
        tmp42[10] = s_Initiate_stratum_failed_00088d94[10];
        tmp42[11] = s_Initiate_stratum_failed_00088d94[11];
        tmp42[12] = s_Initiate_stratum_failed_00088d94[12];
        tmp42[13] = s_Initiate_stratum_failed_00088d94[13];
        tmp42[14] = s_Initiate_stratum_failed_00088d94[14];
        tmp42[15] = s_Initiate_stratum_failed_00088d94[15];
        tmp42[16] = s_Initiate_stratum_failed_00088d94[16];
        tmp42[17] = s_Initiate_stratum_failed_00088d94[17];
        tmp42[18] = s_Initiate_stratum_failed_00088d94[18];
        tmp42[19] = s_Initiate_stratum_failed_00088d94[19];
        tmp42[20] = s_Initiate_stratum_failed_00088d94[20];
        tmp42[21] = s_Initiate_stratum_failed_00088d94[21];
        tmp42[22] = s_Initiate_stratum_failed_00088d94[22];
        tmp42[23] = s_Initiate_stratum_failed_00088d94[23];
        _applog(7,tmp42,false);
      }
      if (bVar3) {
        suspend_stratum(pool);
      }
LAB_00044b64:
      json_decref(val);
      return ret;
    }
    _cg_wlock(&pool->data_lock,"util.c","initiate_stratum",0xd39);
    free(pool->sessionid);
    free(pool->nonce1);
    pool->nonce1 = (char *)0x0;
    pool->sessionid = pool->nonce1;
    _cg_wunlock(&pool->data_lock,"util.c","initiate_stratum",0xd3d);
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      tmp42[0] = s_Failed_to_resume_stratum__trying_00088d6c[0];
      tmp42[1] = s_Failed_to_resume_stratum__trying_00088d6c[1];
      tmp42[2] = s_Failed_to_resume_stratum__trying_00088d6c[2];
      tmp42[3] = s_Failed_to_resume_stratum__trying_00088d6c[3];
      tmp42[4] = s_Failed_to_resume_stratum__trying_00088d6c[4];
      tmp42[5] = s_Failed_to_resume_stratum__trying_00088d6c[5];
      tmp42[6] = s_Failed_to_resume_stratum__trying_00088d6c[6];
      tmp42[7] = s_Failed_to_resume_stratum__trying_00088d6c[7];
      tmp42[8] = s_Failed_to_resume_stratum__trying_00088d6c[8];
      tmp42[9] = s_Failed_to_resume_stratum__trying_00088d6c[9];
      tmp42[10] = s_Failed_to_resume_stratum__trying_00088d6c[10];
      tmp42[11] = s_Failed_to_resume_stratum__trying_00088d6c[11];
      tmp42[12] = s_Failed_to_resume_stratum__trying_00088d6c[12];
      tmp42[13] = s_Failed_to_resume_stratum__trying_00088d6c[13];
      tmp42[14] = s_Failed_to_resume_stratum__trying_00088d6c[14];
      tmp42[15] = s_Failed_to_resume_stratum__trying_00088d6c[15];
      tmp42[16] = s_Failed_to_resume_stratum__trying_00088d6c[16];
      tmp42[17] = s_Failed_to_resume_stratum__trying_00088d6c[17];
      tmp42[18] = s_Failed_to_resume_stratum__trying_00088d6c[18];
      tmp42[19] = s_Failed_to_resume_stratum__trying_00088d6c[19];
      tmp42[20] = s_Failed_to_resume_stratum__trying_00088d6c[20];
      tmp42[21] = s_Failed_to_resume_stratum__trying_00088d6c[21];
      tmp42[22] = s_Failed_to_resume_stratum__trying_00088d6c[22];
      tmp42[23] = s_Failed_to_resume_stratum__trying_00088d6c[23];
      tmp42[24] = s_Failed_to_resume_stratum__trying_00088d6c[24];
      tmp42[25] = s_Failed_to_resume_stratum__trying_00088d6c[25];
      tmp42[26] = s_Failed_to_resume_stratum__trying_00088d6c[26];
      tmp42[27] = s_Failed_to_resume_stratum__trying_00088d6c[27];
      tmp42[28] = s_Failed_to_resume_stratum__trying_00088d6c[28];
      tmp42[29] = s_Failed_to_resume_stratum__trying_00088d6c[29];
      tmp42[30] = s_Failed_to_resume_stratum__trying_00088d6c[30];
      tmp42[31] = s_Failed_to_resume_stratum__trying_00088d6c[31];
      tmp42[32] = s_Failed_to_resume_stratum__trying_00088d6c[32];
      tmp42[33] = s_Failed_to_resume_stratum__trying_00088d6c[33];
      tmp42[34] = s_Failed_to_resume_stratum__trying_00088d6c[34];
      tmp42[35] = s_Failed_to_resume_stratum__trying_00088d6c[35];
      tmp42[36] = s_Failed_to_resume_stratum__trying_00088d6c[36];
      tmp42[37] = s_Failed_to_resume_stratum__trying_00088d6c[37];
      tmp42[38] = s_Failed_to_resume_stratum__trying_00088d6c[38];
      tmp42[39] = s_Failed_to_resume_stratum__trying_00088d6c[39];
      _applog(7,tmp42,false);
    }
    bVar2 = true;
    json_decref(val);
  }
  if (pool->stratum_url == (char *)0x0) {
    pool->stratum_url = pool->sockaddr_url;
  }
  pool->stratum_active = true;
  *(undefined4 *)&pool->next_diff = 0;
  *(undefined4 *)((int)&pool->next_diff + 4) = 0;
  *(undefined4 *)&pool->sdiff = 0;
  *(undefined4 *)((int)&pool->sdiff + 4) = 0x3ff00000;
  if (((opt_protocol != false) && (opt_debug != false)) &&
     ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
    snprintf(tmp42,0x800,"Pool %d confirmed mining.subscribe with extranonce1 %s extran2size %d",
             pool->pool_no,pool->nonce1,pool->n2size);
    _applog(7,tmp42,false);
  }
  goto LAB_00044b64;
}

