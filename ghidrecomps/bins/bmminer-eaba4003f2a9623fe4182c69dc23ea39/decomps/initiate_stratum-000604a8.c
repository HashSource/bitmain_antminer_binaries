
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
    _Var4 = setup_stratum_socket(pool);
    iVar10 = swork_id;
    if (_Var4) {
      bVar3 = true;
      if (bVar1) {
        clear_sock(pool);
        iVar10 = swork_id;
        swork_id = swork_id + 1;
        sprintf(s,"{\"id\": %d, \"method\": \"mining.subscribe\", \"params\": []}",iVar10);
      }
      else if (pool->sessionid == (char *)0x0) {
        swork_id = swork_id + 1;
        sprintf(s,"{\"id\": %d, \"method\": \"mining.subscribe\", \"params\": [\"bmminer/2.0.0\"]}",
                iVar10);
      }
      else {
        swork_id = swork_id + 1;
        sprintf(s,
                "{\"id\": %d, \"method\": \"mining.subscribe\", \"params\": [\"bmminer/2.0.0\", \"%s\"]}"
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
                snprintf(tmp42,0x800,"JSON decode failed(%d): %s",err.line,err.text);
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
                  tmp42[0] = s_Failed_to_get_sessionid_in_initi_0007bf44[0];
                  tmp42[1] = s_Failed_to_get_sessionid_in_initi_0007bf44[1];
                  tmp42[2] = s_Failed_to_get_sessionid_in_initi_0007bf44[2];
                  tmp42[3] = s_Failed_to_get_sessionid_in_initi_0007bf44[3];
                  tmp42[4] = s_Failed_to_get_sessionid_in_initi_0007bf44[4];
                  tmp42[5] = s_Failed_to_get_sessionid_in_initi_0007bf44[5];
                  tmp42[6] = s_Failed_to_get_sessionid_in_initi_0007bf44[6];
                  tmp42[7] = s_Failed_to_get_sessionid_in_initi_0007bf44[7];
                  tmp42[8] = s_Failed_to_get_sessionid_in_initi_0007bf44[8];
                  tmp42[9] = s_Failed_to_get_sessionid_in_initi_0007bf44[9];
                  tmp42[10] = s_Failed_to_get_sessionid_in_initi_0007bf44[10];
                  tmp42[11] = s_Failed_to_get_sessionid_in_initi_0007bf44[11];
                  tmp42[12] = s_Failed_to_get_sessionid_in_initi_0007bf44[12];
                  tmp42[13] = s_Failed_to_get_sessionid_in_initi_0007bf44[13];
                  tmp42[14] = s_Failed_to_get_sessionid_in_initi_0007bf44[14];
                  tmp42[15] = s_Failed_to_get_sessionid_in_initi_0007bf44[15];
                  tmp42[16] = s_Failed_to_get_sessionid_in_initi_0007bf44[16];
                  tmp42[17] = s_Failed_to_get_sessionid_in_initi_0007bf44[17];
                  tmp42[18] = s_Failed_to_get_sessionid_in_initi_0007bf44[18];
                  tmp42[19] = s_Failed_to_get_sessionid_in_initi_0007bf44[19];
                  tmp42[20] = s_Failed_to_get_sessionid_in_initi_0007bf44[20];
                  tmp42[21] = s_Failed_to_get_sessionid_in_initi_0007bf44[21];
                  tmp42[22] = s_Failed_to_get_sessionid_in_initi_0007bf44[22];
                  tmp42[23] = s_Failed_to_get_sessionid_in_initi_0007bf44[23];
                  tmp42[24] = s_Failed_to_get_sessionid_in_initi_0007bf44[24];
                  tmp42[25] = s_Failed_to_get_sessionid_in_initi_0007bf44[25];
                  tmp42[26] = s_Failed_to_get_sessionid_in_initi_0007bf44[26];
                  tmp42[27] = s_Failed_to_get_sessionid_in_initi_0007bf44[27];
                  tmp42[28] = s_Failed_to_get_sessionid_in_initi_0007bf44[28];
                  tmp42[29] = s_Failed_to_get_sessionid_in_initi_0007bf44[29];
                  tmp42[30] = s_Failed_to_get_sessionid_in_initi_0007bf44[30];
                  tmp42[31] = s_Failed_to_get_sessionid_in_initi_0007bf44[31];
                  tmp42[32] = s_Failed_to_get_sessionid_in_initi_0007bf44[32];
                  tmp42[33] = s_Failed_to_get_sessionid_in_initi_0007bf44[33];
                  tmp42[34] = s_Failed_to_get_sessionid_in_initi_0007bf44[34];
                  tmp42[35] = s_Failed_to_get_sessionid_in_initi_0007bf44[35];
                  tmp42[36] = s_Failed_to_get_sessionid_in_initi_0007bf44[36];
                  tmp42[37] = s_Failed_to_get_sessionid_in_initi_0007bf44[37];
                  tmp42[38] = s_Failed_to_get_sessionid_in_initi_0007bf44[38];
                  tmp42[39] = s_Failed_to_get_sessionid_in_initi_0007bf44[39];
                  tmp42[40] = s_Failed_to_get_sessionid_in_initi_0007bf44[40];
                  tmp42[41] = s_Failed_to_get_sessionid_in_initi_0007bf44[41];
                  tmp42[42] = s_Failed_to_get_sessionid_in_initi_0007bf44[42];
                  tmp42[43] = s_Failed_to_get_sessionid_in_initi_0007bf44[43];
                  _applog(7,tmp42,false);
                }
                s_00 = json_array_string(pjVar8,1);
                _Var4 = _valid_hex(s_00,"util.c","initiate_stratum",0xbf0);
                if (_Var4) {
                  pjVar8 = json_array_get(pjVar8,2);
                  jVar12 = json_integer_value(pjVar8);
                  uVar9 = (uint)jVar12;
                  if (((int)uVar9 < 2) || (0x10 < (int)uVar9)) {
                    if ((use_syslog != false) || ((opt_log_output != false || (5 < opt_log_level))))
                    {
                      tmp42[0] = s_Failed_to_get_valid_n2size_in_in_0007bfa0[0];
                      tmp42[1] = s_Failed_to_get_valid_n2size_in_in_0007bfa0[1];
                      tmp42[2] = s_Failed_to_get_valid_n2size_in_in_0007bfa0[2];
                      tmp42[3] = s_Failed_to_get_valid_n2size_in_in_0007bfa0[3];
                      tmp42[4] = s_Failed_to_get_valid_n2size_in_in_0007bfa0[4];
                      tmp42[5] = s_Failed_to_get_valid_n2size_in_in_0007bfa0[5];
                      tmp42[6] = s_Failed_to_get_valid_n2size_in_in_0007bfa0[6];
                      tmp42[7] = s_Failed_to_get_valid_n2size_in_in_0007bfa0[7];
                      tmp42[8] = s_Failed_to_get_valid_n2size_in_in_0007bfa0[8];
                      tmp42[9] = s_Failed_to_get_valid_n2size_in_in_0007bfa0[9];
                      tmp42[10] = s_Failed_to_get_valid_n2size_in_in_0007bfa0[10];
                      tmp42[11] = s_Failed_to_get_valid_n2size_in_in_0007bfa0[11];
                      tmp42[12] = s_Failed_to_get_valid_n2size_in_in_0007bfa0[12];
                      tmp42[13] = s_Failed_to_get_valid_n2size_in_in_0007bfa0[13];
                      tmp42[14] = s_Failed_to_get_valid_n2size_in_in_0007bfa0[14];
                      tmp42[15] = s_Failed_to_get_valid_n2size_in_in_0007bfa0[15];
                      tmp42[16] = s_Failed_to_get_valid_n2size_in_in_0007bfa0[16];
                      tmp42[17] = s_Failed_to_get_valid_n2size_in_in_0007bfa0[17];
                      tmp42[18] = s_Failed_to_get_valid_n2size_in_in_0007bfa0[18];
                      tmp42[19] = s_Failed_to_get_valid_n2size_in_in_0007bfa0[19];
                      tmp42[20] = s_Failed_to_get_valid_n2size_in_in_0007bfa0[20];
                      tmp42[21] = s_Failed_to_get_valid_n2size_in_in_0007bfa0[21];
                      tmp42[22] = s_Failed_to_get_valid_n2size_in_in_0007bfa0[22];
                      tmp42[23] = s_Failed_to_get_valid_n2size_in_in_0007bfa0[23];
                      tmp42[24] = s_Failed_to_get_valid_n2size_in_in_0007bfa0[24];
                      tmp42[25] = s_Failed_to_get_valid_n2size_in_in_0007bfa0[25];
                      tmp42[26] = s_Failed_to_get_valid_n2size_in_in_0007bfa0[26];
                      tmp42[27] = s_Failed_to_get_valid_n2size_in_in_0007bfa0[27];
                      tmp42[28] = s_Failed_to_get_valid_n2size_in_in_0007bfa0[28];
                      tmp42[29] = s_Failed_to_get_valid_n2size_in_in_0007bfa0[29];
                      tmp42[30] = s_Failed_to_get_valid_n2size_in_in_0007bfa0[30];
                      tmp42[31] = s_Failed_to_get_valid_n2size_in_in_0007bfa0[31];
                      tmp42[32] = s_Failed_to_get_valid_n2size_in_in_0007bfa0[32];
                      tmp42[33] = s_Failed_to_get_valid_n2size_in_in_0007bfa0[33];
                      tmp42[34] = s_Failed_to_get_valid_n2size_in_in_0007bfa0[34];
                      tmp42[35] = s_Failed_to_get_valid_n2size_in_in_0007bfa0[35];
                      tmp42[36] = s_Failed_to_get_valid_n2size_in_in_0007bfa0[36];
                      tmp42[37] = s_Failed_to_get_valid_n2size_in_in_0007bfa0[37];
                      tmp42[38] = s_Failed_to_get_valid_n2size_in_in_0007bfa0[38];
                      tmp42[39] = s_Failed_to_get_valid_n2size_in_in_0007bfa0[39];
                      tmp42[40] = s_Failed_to_get_valid_n2size_in_in_0007bfa0[40];
                      tmp42[41] = s_Failed_to_get_valid_n2size_in_in_0007bfa0[41];
                      tmp42[42] = s_Failed_to_get_valid_n2size_in_in_0007bfa0[42];
                      tmp42[43] = s_Failed_to_get_valid_n2size_in_in_0007bfa0[43];
                      tmp42._44_3_ = (undefined3)ram0x0007bfcc;
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
                    _cg_wlock(&pool->data_lock,"util.c","initiate_stratum",0xc04);
                    free(pool->nonce1);
                    free(pool->sessionid);
                    pool->sessionid = pcVar7;
                    pool->nonce1 = s_00;
                    sVar5 = strlen(s_00);
                    pool->n1_len = sVar5 >> 1;
                    free(pool->nonce1bin);
                    puVar11 = (uchar *)_cgcalloc(pool->n1_len,1,"util.c","initiate_stratum",0xc0b);
                    pool->nonce1bin = puVar11;
                    hex2bin(pool->nonce1bin,pool->nonce1,pool->n1_len);
                    pool->n2size = uVar9;
                    _cg_wunlock(&pool->data_lock,"util.c","initiate_stratum",0xc0e);
                    if (((pcVar7 != (char *)0x0) && (opt_debug != false)) &&
                       ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))
                       ) {
                      snprintf(tmp42,0x800,"Pool %d stratum session id: %s",pool->pool_no,
                               pool->sessionid);
                      _applog(7,tmp42,false);
                    }
                    ret = true;
                  }
                }
                else {
                  if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
                    tmp42[0] = s_Failed_to_get_valid_nonce1_in_in_0007bf70[0];
                    tmp42[1] = s_Failed_to_get_valid_nonce1_in_in_0007bf70[1];
                    tmp42[2] = s_Failed_to_get_valid_nonce1_in_in_0007bf70[2];
                    tmp42[3] = s_Failed_to_get_valid_nonce1_in_in_0007bf70[3];
                    tmp42[4] = s_Failed_to_get_valid_nonce1_in_in_0007bf70[4];
                    tmp42[5] = s_Failed_to_get_valid_nonce1_in_in_0007bf70[5];
                    tmp42[6] = s_Failed_to_get_valid_nonce1_in_in_0007bf70[6];
                    tmp42[7] = s_Failed_to_get_valid_nonce1_in_in_0007bf70[7];
                    tmp42[8] = s_Failed_to_get_valid_nonce1_in_in_0007bf70[8];
                    tmp42[9] = s_Failed_to_get_valid_nonce1_in_in_0007bf70[9];
                    tmp42[10] = s_Failed_to_get_valid_nonce1_in_in_0007bf70[10];
                    tmp42[11] = s_Failed_to_get_valid_nonce1_in_in_0007bf70[11];
                    tmp42[12] = s_Failed_to_get_valid_nonce1_in_in_0007bf70[12];
                    tmp42[13] = s_Failed_to_get_valid_nonce1_in_in_0007bf70[13];
                    tmp42[14] = s_Failed_to_get_valid_nonce1_in_in_0007bf70[14];
                    tmp42[15] = s_Failed_to_get_valid_nonce1_in_in_0007bf70[15];
                    tmp42[16] = s_Failed_to_get_valid_nonce1_in_in_0007bf70[16];
                    tmp42[17] = s_Failed_to_get_valid_nonce1_in_in_0007bf70[17];
                    tmp42[18] = s_Failed_to_get_valid_nonce1_in_in_0007bf70[18];
                    tmp42[19] = s_Failed_to_get_valid_nonce1_in_in_0007bf70[19];
                    tmp42[20] = s_Failed_to_get_valid_nonce1_in_in_0007bf70[20];
                    tmp42[21] = s_Failed_to_get_valid_nonce1_in_in_0007bf70[21];
                    tmp42[22] = s_Failed_to_get_valid_nonce1_in_in_0007bf70[22];
                    tmp42[23] = s_Failed_to_get_valid_nonce1_in_in_0007bf70[23];
                    tmp42[24] = s_Failed_to_get_valid_nonce1_in_in_0007bf70[24];
                    tmp42[25] = s_Failed_to_get_valid_nonce1_in_in_0007bf70[25];
                    tmp42[26] = s_Failed_to_get_valid_nonce1_in_in_0007bf70[26];
                    tmp42[27] = s_Failed_to_get_valid_nonce1_in_in_0007bf70[27];
                    tmp42[28] = s_Failed_to_get_valid_nonce1_in_in_0007bf70[28];
                    tmp42[29] = s_Failed_to_get_valid_nonce1_in_in_0007bf70[29];
                    tmp42[30] = s_Failed_to_get_valid_nonce1_in_in_0007bf70[30];
                    tmp42[31] = s_Failed_to_get_valid_nonce1_in_in_0007bf70[31];
                    tmp42[32] = s_Failed_to_get_valid_nonce1_in_in_0007bf70[32];
                    tmp42[33] = s_Failed_to_get_valid_nonce1_in_in_0007bf70[33];
                    tmp42[34] = s_Failed_to_get_valid_nonce1_in_in_0007bf70[34];
                    tmp42[35] = s_Failed_to_get_valid_nonce1_in_in_0007bf70[35];
                    tmp42[36] = s_Failed_to_get_valid_nonce1_in_in_0007bf70[36];
                    tmp42[37] = s_Failed_to_get_valid_nonce1_in_in_0007bf70[37];
                    tmp42[38] = s_Failed_to_get_valid_nonce1_in_in_0007bf70[38];
                    tmp42[39] = s_Failed_to_get_valid_nonce1_in_in_0007bf70[39];
                    tmp42[40] = s_Failed_to_get_valid_nonce1_in_in_0007bf70[40];
                    tmp42[41] = s_Failed_to_get_valid_nonce1_in_in_0007bf70[41];
                    tmp42[42] = s_Failed_to_get_valid_nonce1_in_in_0007bf70[42];
                    tmp42[43] = s_Failed_to_get_valid_nonce1_in_in_0007bf70[43];
                    tmp42._44_3_ = (undefined3)ram0x0007bf9c;
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
          tmp42[0] = s_Timed_out_waiting_for_response_i_0007bef4[0];
          tmp42[1] = s_Timed_out_waiting_for_response_i_0007bef4[1];
          tmp42[2] = s_Timed_out_waiting_for_response_i_0007bef4[2];
          tmp42[3] = s_Timed_out_waiting_for_response_i_0007bef4[3];
          tmp42[4] = s_Timed_out_waiting_for_response_i_0007bef4[4];
          tmp42[5] = s_Timed_out_waiting_for_response_i_0007bef4[5];
          tmp42[6] = s_Timed_out_waiting_for_response_i_0007bef4[6];
          tmp42[7] = s_Timed_out_waiting_for_response_i_0007bef4[7];
          tmp42[8] = s_Timed_out_waiting_for_response_i_0007bef4[8];
          tmp42[9] = s_Timed_out_waiting_for_response_i_0007bef4[9];
          tmp42[10] = s_Timed_out_waiting_for_response_i_0007bef4[10];
          tmp42[11] = s_Timed_out_waiting_for_response_i_0007bef4[11];
          tmp42[12] = s_Timed_out_waiting_for_response_i_0007bef4[12];
          tmp42[13] = s_Timed_out_waiting_for_response_i_0007bef4[13];
          tmp42[14] = s_Timed_out_waiting_for_response_i_0007bef4[14];
          tmp42[15] = s_Timed_out_waiting_for_response_i_0007bef4[15];
          tmp42[16] = s_Timed_out_waiting_for_response_i_0007bef4[16];
          tmp42[17] = s_Timed_out_waiting_for_response_i_0007bef4[17];
          tmp42[18] = s_Timed_out_waiting_for_response_i_0007bef4[18];
          tmp42[19] = s_Timed_out_waiting_for_response_i_0007bef4[19];
          tmp42[20] = s_Timed_out_waiting_for_response_i_0007bef4[20];
          tmp42[21] = s_Timed_out_waiting_for_response_i_0007bef4[21];
          tmp42[22] = s_Timed_out_waiting_for_response_i_0007bef4[22];
          tmp42[23] = s_Timed_out_waiting_for_response_i_0007bef4[23];
          tmp42[24] = s_Timed_out_waiting_for_response_i_0007bef4[24];
          tmp42[25] = s_Timed_out_waiting_for_response_i_0007bef4[25];
          tmp42[26] = s_Timed_out_waiting_for_response_i_0007bef4[26];
          tmp42[27] = s_Timed_out_waiting_for_response_i_0007bef4[27];
          tmp42[28] = s_Timed_out_waiting_for_response_i_0007bef4[28];
          tmp42[29] = s_Timed_out_waiting_for_response_i_0007bef4[29];
          tmp42[30] = s_Timed_out_waiting_for_response_i_0007bef4[30];
          tmp42[31] = s_Timed_out_waiting_for_response_i_0007bef4[31];
          tmp42[32] = s_Timed_out_waiting_for_response_i_0007bef4[32];
          tmp42[33] = s_Timed_out_waiting_for_response_i_0007bef4[33];
          tmp42[34] = s_Timed_out_waiting_for_response_i_0007bef4[34];
          tmp42[35] = s_Timed_out_waiting_for_response_i_0007bef4[35];
          tmp42[36] = s_Timed_out_waiting_for_response_i_0007bef4[36];
          tmp42[37] = s_Timed_out_waiting_for_response_i_0007bef4[37];
          tmp42[38] = s_Timed_out_waiting_for_response_i_0007bef4[38];
          tmp42[39] = s_Timed_out_waiting_for_response_i_0007bef4[39];
          tmp42[40] = s_Timed_out_waiting_for_response_i_0007bef4[40];
          tmp42[41] = s_Timed_out_waiting_for_response_i_0007bef4[41];
          tmp42[42] = s_Timed_out_waiting_for_response_i_0007bef4[42];
          tmp42[43] = s_Timed_out_waiting_for_response_i_0007bef4[43];
          tmp42[44] = s_Timed_out_waiting_for_response_i_0007bef4[44];
          tmp42[45] = s_Timed_out_waiting_for_response_i_0007bef4[45];
          tmp42[46] = s_Timed_out_waiting_for_response_i_0007bef4[46];
          tmp42[47] = s_Timed_out_waiting_for_response_i_0007bef4[47];
          tmp42._48_2_ = (undefined2)ram0x0007bf24;
          tmp42[50] = (char)((uint)ram0x0007bf24 >> 0x10);
          _applog(7,tmp42,false);
        }
      }
      else if ((opt_debug != false) &&
              (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        tmp42[0] = s_Failed_to_send_s_in_initiate_str_0007becc[0];
        tmp42[1] = s_Failed_to_send_s_in_initiate_str_0007becc[1];
        tmp42[2] = s_Failed_to_send_s_in_initiate_str_0007becc[2];
        tmp42[3] = s_Failed_to_send_s_in_initiate_str_0007becc[3];
        tmp42[4] = s_Failed_to_send_s_in_initiate_str_0007becc[4];
        tmp42[5] = s_Failed_to_send_s_in_initiate_str_0007becc[5];
        tmp42[6] = s_Failed_to_send_s_in_initiate_str_0007becc[6];
        tmp42[7] = s_Failed_to_send_s_in_initiate_str_0007becc[7];
        tmp42[8] = s_Failed_to_send_s_in_initiate_str_0007becc[8];
        tmp42[9] = s_Failed_to_send_s_in_initiate_str_0007becc[9];
        tmp42[10] = s_Failed_to_send_s_in_initiate_str_0007becc[10];
        tmp42[11] = s_Failed_to_send_s_in_initiate_str_0007becc[11];
        tmp42[12] = s_Failed_to_send_s_in_initiate_str_0007becc[12];
        tmp42[13] = s_Failed_to_send_s_in_initiate_str_0007becc[13];
        tmp42[14] = s_Failed_to_send_s_in_initiate_str_0007becc[14];
        tmp42[15] = s_Failed_to_send_s_in_initiate_str_0007becc[15];
        tmp42[16] = s_Failed_to_send_s_in_initiate_str_0007becc[16];
        tmp42[17] = s_Failed_to_send_s_in_initiate_str_0007becc[17];
        tmp42[18] = s_Failed_to_send_s_in_initiate_str_0007becc[18];
        tmp42[19] = s_Failed_to_send_s_in_initiate_str_0007becc[19];
        tmp42[20] = s_Failed_to_send_s_in_initiate_str_0007becc[20];
        tmp42[21] = s_Failed_to_send_s_in_initiate_str_0007becc[21];
        tmp42[22] = s_Failed_to_send_s_in_initiate_str_0007becc[22];
        tmp42[23] = s_Failed_to_send_s_in_initiate_str_0007becc[23];
        tmp42[24] = s_Failed_to_send_s_in_initiate_str_0007becc[24];
        tmp42[25] = s_Failed_to_send_s_in_initiate_str_0007becc[25];
        tmp42[26] = s_Failed_to_send_s_in_initiate_str_0007becc[26];
        tmp42[27] = s_Failed_to_send_s_in_initiate_str_0007becc[27];
        tmp42[28] = s_Failed_to_send_s_in_initiate_str_0007becc[28];
        tmp42[29] = s_Failed_to_send_s_in_initiate_str_0007becc[29];
        tmp42[30] = s_Failed_to_send_s_in_initiate_str_0007becc[30];
        tmp42[31] = s_Failed_to_send_s_in_initiate_str_0007becc[31];
        tmp42[32] = s_Failed_to_send_s_in_initiate_str_0007becc[32];
        tmp42[33] = s_Failed_to_send_s_in_initiate_str_0007becc[33];
        tmp42[34] = s_Failed_to_send_s_in_initiate_str_0007becc[34];
        tmp42[35] = s_Failed_to_send_s_in_initiate_str_0007becc[35];
        tmp42[36] = (char)ram0x0007bef0;
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
        tmp42[0] = s_Initiate_stratum_failed_0007c0a0[0];
        tmp42[1] = s_Initiate_stratum_failed_0007c0a0[1];
        tmp42[2] = s_Initiate_stratum_failed_0007c0a0[2];
        tmp42[3] = s_Initiate_stratum_failed_0007c0a0[3];
        tmp42[4] = s_Initiate_stratum_failed_0007c0a0[4];
        tmp42[5] = s_Initiate_stratum_failed_0007c0a0[5];
        tmp42[6] = s_Initiate_stratum_failed_0007c0a0[6];
        tmp42[7] = s_Initiate_stratum_failed_0007c0a0[7];
        tmp42[8] = s_Initiate_stratum_failed_0007c0a0[8];
        tmp42[9] = s_Initiate_stratum_failed_0007c0a0[9];
        tmp42[10] = s_Initiate_stratum_failed_0007c0a0[10];
        tmp42[11] = s_Initiate_stratum_failed_0007c0a0[11];
        tmp42[12] = s_Initiate_stratum_failed_0007c0a0[12];
        tmp42[13] = s_Initiate_stratum_failed_0007c0a0[13];
        tmp42[14] = s_Initiate_stratum_failed_0007c0a0[14];
        tmp42[15] = s_Initiate_stratum_failed_0007c0a0[15];
        tmp42[16] = s_Initiate_stratum_failed_0007c0a0[16];
        tmp42[17] = s_Initiate_stratum_failed_0007c0a0[17];
        tmp42[18] = s_Initiate_stratum_failed_0007c0a0[18];
        tmp42[19] = s_Initiate_stratum_failed_0007c0a0[19];
        tmp42[20] = s_Initiate_stratum_failed_0007c0a0[20];
        tmp42[21] = s_Initiate_stratum_failed_0007c0a0[21];
        tmp42[22] = s_Initiate_stratum_failed_0007c0a0[22];
        tmp42[23] = s_Initiate_stratum_failed_0007c0a0[23];
        _applog(7,tmp42,false);
      }
      if (bVar3) {
        suspend_stratum(pool);
      }
LAB_000610d6:
      json_decref(val);
      return ret;
    }
    _cg_wlock(&pool->data_lock,"util.c","initiate_stratum",0xc2a);
    free(pool->sessionid);
    free(pool->nonce1);
    pool->nonce1 = (char *)0x0;
    pool->sessionid = pool->nonce1;
    _cg_wunlock(&pool->data_lock,"util.c","initiate_stratum",0xc2e);
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      tmp42[0] = s_Failed_to_resume_stratum__trying_0007c078[0];
      tmp42[1] = s_Failed_to_resume_stratum__trying_0007c078[1];
      tmp42[2] = s_Failed_to_resume_stratum__trying_0007c078[2];
      tmp42[3] = s_Failed_to_resume_stratum__trying_0007c078[3];
      tmp42[4] = s_Failed_to_resume_stratum__trying_0007c078[4];
      tmp42[5] = s_Failed_to_resume_stratum__trying_0007c078[5];
      tmp42[6] = s_Failed_to_resume_stratum__trying_0007c078[6];
      tmp42[7] = s_Failed_to_resume_stratum__trying_0007c078[7];
      tmp42[8] = s_Failed_to_resume_stratum__trying_0007c078[8];
      tmp42[9] = s_Failed_to_resume_stratum__trying_0007c078[9];
      tmp42[10] = s_Failed_to_resume_stratum__trying_0007c078[10];
      tmp42[11] = s_Failed_to_resume_stratum__trying_0007c078[11];
      tmp42[12] = s_Failed_to_resume_stratum__trying_0007c078[12];
      tmp42[13] = s_Failed_to_resume_stratum__trying_0007c078[13];
      tmp42[14] = s_Failed_to_resume_stratum__trying_0007c078[14];
      tmp42[15] = s_Failed_to_resume_stratum__trying_0007c078[15];
      tmp42[16] = s_Failed_to_resume_stratum__trying_0007c078[16];
      tmp42[17] = s_Failed_to_resume_stratum__trying_0007c078[17];
      tmp42[18] = s_Failed_to_resume_stratum__trying_0007c078[18];
      tmp42[19] = s_Failed_to_resume_stratum__trying_0007c078[19];
      tmp42[20] = s_Failed_to_resume_stratum__trying_0007c078[20];
      tmp42[21] = s_Failed_to_resume_stratum__trying_0007c078[21];
      tmp42[22] = s_Failed_to_resume_stratum__trying_0007c078[22];
      tmp42[23] = s_Failed_to_resume_stratum__trying_0007c078[23];
      tmp42[24] = s_Failed_to_resume_stratum__trying_0007c078[24];
      tmp42[25] = s_Failed_to_resume_stratum__trying_0007c078[25];
      tmp42[26] = s_Failed_to_resume_stratum__trying_0007c078[26];
      tmp42[27] = s_Failed_to_resume_stratum__trying_0007c078[27];
      tmp42[28] = s_Failed_to_resume_stratum__trying_0007c078[28];
      tmp42[29] = s_Failed_to_resume_stratum__trying_0007c078[29];
      tmp42[30] = s_Failed_to_resume_stratum__trying_0007c078[30];
      tmp42[31] = s_Failed_to_resume_stratum__trying_0007c078[31];
      tmp42[32] = s_Failed_to_resume_stratum__trying_0007c078[32];
      tmp42[33] = s_Failed_to_resume_stratum__trying_0007c078[33];
      tmp42[34] = s_Failed_to_resume_stratum__trying_0007c078[34];
      tmp42[35] = s_Failed_to_resume_stratum__trying_0007c078[35];
      tmp42[36] = s_Failed_to_resume_stratum__trying_0007c078[36];
      tmp42[37] = s_Failed_to_resume_stratum__trying_0007c078[37];
      tmp42[38] = s_Failed_to_resume_stratum__trying_0007c078[38];
      tmp42[39] = s_Failed_to_resume_stratum__trying_0007c078[39];
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
  goto LAB_000610d6;
}

