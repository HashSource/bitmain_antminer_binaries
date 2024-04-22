
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
  char *in_stack_ffffd6c8;
  undefined4 in_stack_ffffd6cc;
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
    cgsleep_us(CONCAT44(in_stack_ffffd6cc,in_stack_ffffd6c8));
    if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
      tmp42[0] = s_initiate_stratum_000a012c[0];
      tmp42[1] = s_initiate_stratum_000a012c[1];
      tmp42[2] = s_initiate_stratum_000a012c[2];
      tmp42[3] = s_initiate_stratum_000a012c[3];
      tmp42[4] = s_initiate_stratum_000a012c[4];
      tmp42[5] = s_initiate_stratum_000a012c[5];
      tmp42[6] = s_initiate_stratum_000a012c[6];
      tmp42[7] = s_initiate_stratum_000a012c[7];
      tmp42[8] = s_initiate_stratum_000a012c[8];
      tmp42[9] = s_initiate_stratum_000a012c[9];
      tmp42[10] = s_initiate_stratum_000a012c[10];
      tmp42[11] = s_initiate_stratum_000a012c[11];
      tmp42[12] = s_initiate_stratum_000a012c[12];
      tmp42[13] = s_initiate_stratum_000a012c[13];
      tmp42[14] = s_initiate_stratum_000a012c[14];
      tmp42[15] = s_initiate_stratum_000a012c[15];
      tmp42[16] = (char)ram0x000a013c;
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
                in_stack_ffffd6c8 = err.text;
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
                  tmp42[0] = s_Failed_to_get_sessionid_in_initi_000a020c[0];
                  tmp42[1] = s_Failed_to_get_sessionid_in_initi_000a020c[1];
                  tmp42[2] = s_Failed_to_get_sessionid_in_initi_000a020c[2];
                  tmp42[3] = s_Failed_to_get_sessionid_in_initi_000a020c[3];
                  tmp42[4] = s_Failed_to_get_sessionid_in_initi_000a020c[4];
                  tmp42[5] = s_Failed_to_get_sessionid_in_initi_000a020c[5];
                  tmp42[6] = s_Failed_to_get_sessionid_in_initi_000a020c[6];
                  tmp42[7] = s_Failed_to_get_sessionid_in_initi_000a020c[7];
                  tmp42[8] = s_Failed_to_get_sessionid_in_initi_000a020c[8];
                  tmp42[9] = s_Failed_to_get_sessionid_in_initi_000a020c[9];
                  tmp42[10] = s_Failed_to_get_sessionid_in_initi_000a020c[10];
                  tmp42[11] = s_Failed_to_get_sessionid_in_initi_000a020c[11];
                  tmp42[12] = s_Failed_to_get_sessionid_in_initi_000a020c[12];
                  tmp42[13] = s_Failed_to_get_sessionid_in_initi_000a020c[13];
                  tmp42[14] = s_Failed_to_get_sessionid_in_initi_000a020c[14];
                  tmp42[15] = s_Failed_to_get_sessionid_in_initi_000a020c[15];
                  tmp42[16] = s_Failed_to_get_sessionid_in_initi_000a020c[16];
                  tmp42[17] = s_Failed_to_get_sessionid_in_initi_000a020c[17];
                  tmp42[18] = s_Failed_to_get_sessionid_in_initi_000a020c[18];
                  tmp42[19] = s_Failed_to_get_sessionid_in_initi_000a020c[19];
                  tmp42[20] = s_Failed_to_get_sessionid_in_initi_000a020c[20];
                  tmp42[21] = s_Failed_to_get_sessionid_in_initi_000a020c[21];
                  tmp42[22] = s_Failed_to_get_sessionid_in_initi_000a020c[22];
                  tmp42[23] = s_Failed_to_get_sessionid_in_initi_000a020c[23];
                  tmp42[24] = s_Failed_to_get_sessionid_in_initi_000a020c[24];
                  tmp42[25] = s_Failed_to_get_sessionid_in_initi_000a020c[25];
                  tmp42[26] = s_Failed_to_get_sessionid_in_initi_000a020c[26];
                  tmp42[27] = s_Failed_to_get_sessionid_in_initi_000a020c[27];
                  tmp42[28] = s_Failed_to_get_sessionid_in_initi_000a020c[28];
                  tmp42[29] = s_Failed_to_get_sessionid_in_initi_000a020c[29];
                  tmp42[30] = s_Failed_to_get_sessionid_in_initi_000a020c[30];
                  tmp42[31] = s_Failed_to_get_sessionid_in_initi_000a020c[31];
                  tmp42[32] = s_Failed_to_get_sessionid_in_initi_000a020c[32];
                  tmp42[33] = s_Failed_to_get_sessionid_in_initi_000a020c[33];
                  tmp42[34] = s_Failed_to_get_sessionid_in_initi_000a020c[34];
                  tmp42[35] = s_Failed_to_get_sessionid_in_initi_000a020c[35];
                  tmp42[36] = s_Failed_to_get_sessionid_in_initi_000a020c[36];
                  tmp42[37] = s_Failed_to_get_sessionid_in_initi_000a020c[37];
                  tmp42[38] = s_Failed_to_get_sessionid_in_initi_000a020c[38];
                  tmp42[39] = s_Failed_to_get_sessionid_in_initi_000a020c[39];
                  tmp42[40] = s_Failed_to_get_sessionid_in_initi_000a020c[40];
                  tmp42[41] = s_Failed_to_get_sessionid_in_initi_000a020c[41];
                  tmp42[42] = s_Failed_to_get_sessionid_in_initi_000a020c[42];
                  tmp42[43] = s_Failed_to_get_sessionid_in_initi_000a020c[43];
                  _applog(7,tmp42,false);
                }
                s_00 = json_array_string(pjVar8,1);
                _Var4 = _valid_hex(s_00,"util.c","initiate_stratum",0xcfd);
                if (_Var4) {
                  pjVar8 = json_array_get(pjVar8,2);
                  jVar12 = json_integer_value(pjVar8);
                  uVar9 = (uint)jVar12;
                  if (((int)uVar9 < 2) || (0x10 < (int)uVar9)) {
                    if ((use_syslog != false) || ((opt_log_output != false || (5 < opt_log_level))))
                    {
                      tmp42[0] = s_Failed_to_get_valid_n2size_in_in_000a0268[0];
                      tmp42[1] = s_Failed_to_get_valid_n2size_in_in_000a0268[1];
                      tmp42[2] = s_Failed_to_get_valid_n2size_in_in_000a0268[2];
                      tmp42[3] = s_Failed_to_get_valid_n2size_in_in_000a0268[3];
                      tmp42[4] = s_Failed_to_get_valid_n2size_in_in_000a0268[4];
                      tmp42[5] = s_Failed_to_get_valid_n2size_in_in_000a0268[5];
                      tmp42[6] = s_Failed_to_get_valid_n2size_in_in_000a0268[6];
                      tmp42[7] = s_Failed_to_get_valid_n2size_in_in_000a0268[7];
                      tmp42[8] = s_Failed_to_get_valid_n2size_in_in_000a0268[8];
                      tmp42[9] = s_Failed_to_get_valid_n2size_in_in_000a0268[9];
                      tmp42[10] = s_Failed_to_get_valid_n2size_in_in_000a0268[10];
                      tmp42[11] = s_Failed_to_get_valid_n2size_in_in_000a0268[11];
                      tmp42[12] = s_Failed_to_get_valid_n2size_in_in_000a0268[12];
                      tmp42[13] = s_Failed_to_get_valid_n2size_in_in_000a0268[13];
                      tmp42[14] = s_Failed_to_get_valid_n2size_in_in_000a0268[14];
                      tmp42[15] = s_Failed_to_get_valid_n2size_in_in_000a0268[15];
                      tmp42[16] = s_Failed_to_get_valid_n2size_in_in_000a0268[16];
                      tmp42[17] = s_Failed_to_get_valid_n2size_in_in_000a0268[17];
                      tmp42[18] = s_Failed_to_get_valid_n2size_in_in_000a0268[18];
                      tmp42[19] = s_Failed_to_get_valid_n2size_in_in_000a0268[19];
                      tmp42[20] = s_Failed_to_get_valid_n2size_in_in_000a0268[20];
                      tmp42[21] = s_Failed_to_get_valid_n2size_in_in_000a0268[21];
                      tmp42[22] = s_Failed_to_get_valid_n2size_in_in_000a0268[22];
                      tmp42[23] = s_Failed_to_get_valid_n2size_in_in_000a0268[23];
                      tmp42[24] = s_Failed_to_get_valid_n2size_in_in_000a0268[24];
                      tmp42[25] = s_Failed_to_get_valid_n2size_in_in_000a0268[25];
                      tmp42[26] = s_Failed_to_get_valid_n2size_in_in_000a0268[26];
                      tmp42[27] = s_Failed_to_get_valid_n2size_in_in_000a0268[27];
                      tmp42[28] = s_Failed_to_get_valid_n2size_in_in_000a0268[28];
                      tmp42[29] = s_Failed_to_get_valid_n2size_in_in_000a0268[29];
                      tmp42[30] = s_Failed_to_get_valid_n2size_in_in_000a0268[30];
                      tmp42[31] = s_Failed_to_get_valid_n2size_in_in_000a0268[31];
                      tmp42[32] = s_Failed_to_get_valid_n2size_in_in_000a0268[32];
                      tmp42[33] = s_Failed_to_get_valid_n2size_in_in_000a0268[33];
                      tmp42[34] = s_Failed_to_get_valid_n2size_in_in_000a0268[34];
                      tmp42[35] = s_Failed_to_get_valid_n2size_in_in_000a0268[35];
                      tmp42[36] = s_Failed_to_get_valid_n2size_in_in_000a0268[36];
                      tmp42[37] = s_Failed_to_get_valid_n2size_in_in_000a0268[37];
                      tmp42[38] = s_Failed_to_get_valid_n2size_in_in_000a0268[38];
                      tmp42[39] = s_Failed_to_get_valid_n2size_in_in_000a0268[39];
                      tmp42[40] = s_Failed_to_get_valid_n2size_in_in_000a0268[40];
                      tmp42[41] = s_Failed_to_get_valid_n2size_in_in_000a0268[41];
                      tmp42[42] = s_Failed_to_get_valid_n2size_in_in_000a0268[42];
                      tmp42[43] = s_Failed_to_get_valid_n2size_in_in_000a0268[43];
                      tmp42._44_3_ = (undefined3)ram0x000a0294;
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
                    _cg_wlock(&pool->data_lock,"util.c","initiate_stratum",0xd12);
                    pool->sessionid = pcVar7;
                    pool->nonce1 = s_00;
                    sVar5 = strlen(s_00);
                    pool->n1_len = sVar5 >> 1;
                    free(pool->nonce1bin);
                    in_stack_ffffd6c8 = (char *)0xd19;
                    puVar11 = (uchar *)_cgcalloc(pool->n1_len,1,"util.c","initiate_stratum",0xd19);
                    pool->nonce1bin = puVar11;
                    hex2bin(pool->nonce1bin,pool->nonce1,pool->n1_len);
                    pool->n2size = uVar9;
                    _cg_wunlock(&pool->data_lock,"util.c","initiate_stratum",0xd1c);
                    if (((pcVar7 != (char *)0x0) && (opt_debug != false)) &&
                       ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))
                       ) {
                      in_stack_ffffd6c8 = pool->sessionid;
                      snprintf(tmp42,0x800,"Pool %d stratum session id: %s",pool->pool_no);
                      _applog(7,tmp42,false);
                    }
                    ret = true;
                  }
                }
                else {
                  if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
                    tmp42[0] = s_Failed_to_get_valid_nonce1_in_in_000a0238[0];
                    tmp42[1] = s_Failed_to_get_valid_nonce1_in_in_000a0238[1];
                    tmp42[2] = s_Failed_to_get_valid_nonce1_in_in_000a0238[2];
                    tmp42[3] = s_Failed_to_get_valid_nonce1_in_in_000a0238[3];
                    tmp42[4] = s_Failed_to_get_valid_nonce1_in_in_000a0238[4];
                    tmp42[5] = s_Failed_to_get_valid_nonce1_in_in_000a0238[5];
                    tmp42[6] = s_Failed_to_get_valid_nonce1_in_in_000a0238[6];
                    tmp42[7] = s_Failed_to_get_valid_nonce1_in_in_000a0238[7];
                    tmp42[8] = s_Failed_to_get_valid_nonce1_in_in_000a0238[8];
                    tmp42[9] = s_Failed_to_get_valid_nonce1_in_in_000a0238[9];
                    tmp42[10] = s_Failed_to_get_valid_nonce1_in_in_000a0238[10];
                    tmp42[11] = s_Failed_to_get_valid_nonce1_in_in_000a0238[11];
                    tmp42[12] = s_Failed_to_get_valid_nonce1_in_in_000a0238[12];
                    tmp42[13] = s_Failed_to_get_valid_nonce1_in_in_000a0238[13];
                    tmp42[14] = s_Failed_to_get_valid_nonce1_in_in_000a0238[14];
                    tmp42[15] = s_Failed_to_get_valid_nonce1_in_in_000a0238[15];
                    tmp42[16] = s_Failed_to_get_valid_nonce1_in_in_000a0238[16];
                    tmp42[17] = s_Failed_to_get_valid_nonce1_in_in_000a0238[17];
                    tmp42[18] = s_Failed_to_get_valid_nonce1_in_in_000a0238[18];
                    tmp42[19] = s_Failed_to_get_valid_nonce1_in_in_000a0238[19];
                    tmp42[20] = s_Failed_to_get_valid_nonce1_in_in_000a0238[20];
                    tmp42[21] = s_Failed_to_get_valid_nonce1_in_in_000a0238[21];
                    tmp42[22] = s_Failed_to_get_valid_nonce1_in_in_000a0238[22];
                    tmp42[23] = s_Failed_to_get_valid_nonce1_in_in_000a0238[23];
                    tmp42[24] = s_Failed_to_get_valid_nonce1_in_in_000a0238[24];
                    tmp42[25] = s_Failed_to_get_valid_nonce1_in_in_000a0238[25];
                    tmp42[26] = s_Failed_to_get_valid_nonce1_in_in_000a0238[26];
                    tmp42[27] = s_Failed_to_get_valid_nonce1_in_in_000a0238[27];
                    tmp42[28] = s_Failed_to_get_valid_nonce1_in_in_000a0238[28];
                    tmp42[29] = s_Failed_to_get_valid_nonce1_in_in_000a0238[29];
                    tmp42[30] = s_Failed_to_get_valid_nonce1_in_in_000a0238[30];
                    tmp42[31] = s_Failed_to_get_valid_nonce1_in_in_000a0238[31];
                    tmp42[32] = s_Failed_to_get_valid_nonce1_in_in_000a0238[32];
                    tmp42[33] = s_Failed_to_get_valid_nonce1_in_in_000a0238[33];
                    tmp42[34] = s_Failed_to_get_valid_nonce1_in_in_000a0238[34];
                    tmp42[35] = s_Failed_to_get_valid_nonce1_in_in_000a0238[35];
                    tmp42[36] = s_Failed_to_get_valid_nonce1_in_in_000a0238[36];
                    tmp42[37] = s_Failed_to_get_valid_nonce1_in_in_000a0238[37];
                    tmp42[38] = s_Failed_to_get_valid_nonce1_in_in_000a0238[38];
                    tmp42[39] = s_Failed_to_get_valid_nonce1_in_in_000a0238[39];
                    tmp42[40] = s_Failed_to_get_valid_nonce1_in_in_000a0238[40];
                    tmp42[41] = s_Failed_to_get_valid_nonce1_in_in_000a0238[41];
                    tmp42[42] = s_Failed_to_get_valid_nonce1_in_in_000a0238[42];
                    tmp42[43] = s_Failed_to_get_valid_nonce1_in_in_000a0238[43];
                    tmp42._44_3_ = (undefined3)ram0x000a0264;
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
          tmp42[0] = s_Timed_out_waiting_for_response_i_000a00dc[0];
          tmp42[1] = s_Timed_out_waiting_for_response_i_000a00dc[1];
          tmp42[2] = s_Timed_out_waiting_for_response_i_000a00dc[2];
          tmp42[3] = s_Timed_out_waiting_for_response_i_000a00dc[3];
          tmp42[4] = s_Timed_out_waiting_for_response_i_000a00dc[4];
          tmp42[5] = s_Timed_out_waiting_for_response_i_000a00dc[5];
          tmp42[6] = s_Timed_out_waiting_for_response_i_000a00dc[6];
          tmp42[7] = s_Timed_out_waiting_for_response_i_000a00dc[7];
          tmp42[8] = s_Timed_out_waiting_for_response_i_000a00dc[8];
          tmp42[9] = s_Timed_out_waiting_for_response_i_000a00dc[9];
          tmp42[10] = s_Timed_out_waiting_for_response_i_000a00dc[10];
          tmp42[11] = s_Timed_out_waiting_for_response_i_000a00dc[11];
          tmp42[12] = s_Timed_out_waiting_for_response_i_000a00dc[12];
          tmp42[13] = s_Timed_out_waiting_for_response_i_000a00dc[13];
          tmp42[14] = s_Timed_out_waiting_for_response_i_000a00dc[14];
          tmp42[15] = s_Timed_out_waiting_for_response_i_000a00dc[15];
          tmp42[16] = s_Timed_out_waiting_for_response_i_000a00dc[16];
          tmp42[17] = s_Timed_out_waiting_for_response_i_000a00dc[17];
          tmp42[18] = s_Timed_out_waiting_for_response_i_000a00dc[18];
          tmp42[19] = s_Timed_out_waiting_for_response_i_000a00dc[19];
          tmp42[20] = s_Timed_out_waiting_for_response_i_000a00dc[20];
          tmp42[21] = s_Timed_out_waiting_for_response_i_000a00dc[21];
          tmp42[22] = s_Timed_out_waiting_for_response_i_000a00dc[22];
          tmp42[23] = s_Timed_out_waiting_for_response_i_000a00dc[23];
          tmp42[24] = s_Timed_out_waiting_for_response_i_000a00dc[24];
          tmp42[25] = s_Timed_out_waiting_for_response_i_000a00dc[25];
          tmp42[26] = s_Timed_out_waiting_for_response_i_000a00dc[26];
          tmp42[27] = s_Timed_out_waiting_for_response_i_000a00dc[27];
          tmp42[28] = s_Timed_out_waiting_for_response_i_000a00dc[28];
          tmp42[29] = s_Timed_out_waiting_for_response_i_000a00dc[29];
          tmp42[30] = s_Timed_out_waiting_for_response_i_000a00dc[30];
          tmp42[31] = s_Timed_out_waiting_for_response_i_000a00dc[31];
          tmp42[32] = s_Timed_out_waiting_for_response_i_000a00dc[32];
          tmp42[33] = s_Timed_out_waiting_for_response_i_000a00dc[33];
          tmp42[34] = s_Timed_out_waiting_for_response_i_000a00dc[34];
          tmp42[35] = s_Timed_out_waiting_for_response_i_000a00dc[35];
          tmp42[36] = s_Timed_out_waiting_for_response_i_000a00dc[36];
          tmp42[37] = s_Timed_out_waiting_for_response_i_000a00dc[37];
          tmp42[38] = s_Timed_out_waiting_for_response_i_000a00dc[38];
          tmp42[39] = s_Timed_out_waiting_for_response_i_000a00dc[39];
          tmp42[40] = s_Timed_out_waiting_for_response_i_000a00dc[40];
          tmp42[41] = s_Timed_out_waiting_for_response_i_000a00dc[41];
          tmp42[42] = s_Timed_out_waiting_for_response_i_000a00dc[42];
          tmp42[43] = s_Timed_out_waiting_for_response_i_000a00dc[43];
          tmp42[44] = s_Timed_out_waiting_for_response_i_000a00dc[44];
          tmp42[45] = s_Timed_out_waiting_for_response_i_000a00dc[45];
          tmp42[46] = s_Timed_out_waiting_for_response_i_000a00dc[46];
          tmp42[47] = s_Timed_out_waiting_for_response_i_000a00dc[47];
          tmp42._48_2_ = (undefined2)ram0x000a010c;
          tmp42[50] = (char)((uint)ram0x000a010c >> 0x10);
          _applog(7,tmp42,false);
        }
      }
      else if ((opt_debug != false) &&
              (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        tmp42[0] = s_Failed_to_send_s_in_initiate_str_000a00b4[0];
        tmp42[1] = s_Failed_to_send_s_in_initiate_str_000a00b4[1];
        tmp42[2] = s_Failed_to_send_s_in_initiate_str_000a00b4[2];
        tmp42[3] = s_Failed_to_send_s_in_initiate_str_000a00b4[3];
        tmp42[4] = s_Failed_to_send_s_in_initiate_str_000a00b4[4];
        tmp42[5] = s_Failed_to_send_s_in_initiate_str_000a00b4[5];
        tmp42[6] = s_Failed_to_send_s_in_initiate_str_000a00b4[6];
        tmp42[7] = s_Failed_to_send_s_in_initiate_str_000a00b4[7];
        tmp42[8] = s_Failed_to_send_s_in_initiate_str_000a00b4[8];
        tmp42[9] = s_Failed_to_send_s_in_initiate_str_000a00b4[9];
        tmp42[10] = s_Failed_to_send_s_in_initiate_str_000a00b4[10];
        tmp42[11] = s_Failed_to_send_s_in_initiate_str_000a00b4[11];
        tmp42[12] = s_Failed_to_send_s_in_initiate_str_000a00b4[12];
        tmp42[13] = s_Failed_to_send_s_in_initiate_str_000a00b4[13];
        tmp42[14] = s_Failed_to_send_s_in_initiate_str_000a00b4[14];
        tmp42[15] = s_Failed_to_send_s_in_initiate_str_000a00b4[15];
        tmp42[16] = s_Failed_to_send_s_in_initiate_str_000a00b4[16];
        tmp42[17] = s_Failed_to_send_s_in_initiate_str_000a00b4[17];
        tmp42[18] = s_Failed_to_send_s_in_initiate_str_000a00b4[18];
        tmp42[19] = s_Failed_to_send_s_in_initiate_str_000a00b4[19];
        tmp42[20] = s_Failed_to_send_s_in_initiate_str_000a00b4[20];
        tmp42[21] = s_Failed_to_send_s_in_initiate_str_000a00b4[21];
        tmp42[22] = s_Failed_to_send_s_in_initiate_str_000a00b4[22];
        tmp42[23] = s_Failed_to_send_s_in_initiate_str_000a00b4[23];
        tmp42[24] = s_Failed_to_send_s_in_initiate_str_000a00b4[24];
        tmp42[25] = s_Failed_to_send_s_in_initiate_str_000a00b4[25];
        tmp42[26] = s_Failed_to_send_s_in_initiate_str_000a00b4[26];
        tmp42[27] = s_Failed_to_send_s_in_initiate_str_000a00b4[27];
        tmp42[28] = s_Failed_to_send_s_in_initiate_str_000a00b4[28];
        tmp42[29] = s_Failed_to_send_s_in_initiate_str_000a00b4[29];
        tmp42[30] = s_Failed_to_send_s_in_initiate_str_000a00b4[30];
        tmp42[31] = s_Failed_to_send_s_in_initiate_str_000a00b4[31];
        tmp42[32] = s_Failed_to_send_s_in_initiate_str_000a00b4[32];
        tmp42[33] = s_Failed_to_send_s_in_initiate_str_000a00b4[33];
        tmp42[34] = s_Failed_to_send_s_in_initiate_str_000a00b4[34];
        tmp42[35] = s_Failed_to_send_s_in_initiate_str_000a00b4[35];
        tmp42[36] = (char)ram0x000a00d8;
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
        tmp42[0] = s_Initiate_stratum_failed_000a0368[0];
        tmp42[1] = s_Initiate_stratum_failed_000a0368[1];
        tmp42[2] = s_Initiate_stratum_failed_000a0368[2];
        tmp42[3] = s_Initiate_stratum_failed_000a0368[3];
        tmp42[4] = s_Initiate_stratum_failed_000a0368[4];
        tmp42[5] = s_Initiate_stratum_failed_000a0368[5];
        tmp42[6] = s_Initiate_stratum_failed_000a0368[6];
        tmp42[7] = s_Initiate_stratum_failed_000a0368[7];
        tmp42[8] = s_Initiate_stratum_failed_000a0368[8];
        tmp42[9] = s_Initiate_stratum_failed_000a0368[9];
        tmp42[10] = s_Initiate_stratum_failed_000a0368[10];
        tmp42[11] = s_Initiate_stratum_failed_000a0368[11];
        tmp42[12] = s_Initiate_stratum_failed_000a0368[12];
        tmp42[13] = s_Initiate_stratum_failed_000a0368[13];
        tmp42[14] = s_Initiate_stratum_failed_000a0368[14];
        tmp42[15] = s_Initiate_stratum_failed_000a0368[15];
        tmp42[16] = s_Initiate_stratum_failed_000a0368[16];
        tmp42[17] = s_Initiate_stratum_failed_000a0368[17];
        tmp42[18] = s_Initiate_stratum_failed_000a0368[18];
        tmp42[19] = s_Initiate_stratum_failed_000a0368[19];
        tmp42[20] = s_Initiate_stratum_failed_000a0368[20];
        tmp42[21] = s_Initiate_stratum_failed_000a0368[21];
        tmp42[22] = s_Initiate_stratum_failed_000a0368[22];
        tmp42[23] = s_Initiate_stratum_failed_000a0368[23];
        _applog(7,tmp42,false);
      }
      if (bVar3) {
        suspend_stratum(pool);
      }
LAB_00042ed8:
      json_decref(val);
      return ret;
    }
    _cg_wlock(&pool->data_lock,"util.c","initiate_stratum",0xd38);
    free(pool->sessionid);
    free(pool->nonce1);
    pool->nonce1 = (char *)0x0;
    pool->sessionid = pool->nonce1;
    _cg_wunlock(&pool->data_lock,"util.c","initiate_stratum",0xd3c);
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      tmp42[0] = s_Failed_to_resume_stratum__trying_000a0340[0];
      tmp42[1] = s_Failed_to_resume_stratum__trying_000a0340[1];
      tmp42[2] = s_Failed_to_resume_stratum__trying_000a0340[2];
      tmp42[3] = s_Failed_to_resume_stratum__trying_000a0340[3];
      tmp42[4] = s_Failed_to_resume_stratum__trying_000a0340[4];
      tmp42[5] = s_Failed_to_resume_stratum__trying_000a0340[5];
      tmp42[6] = s_Failed_to_resume_stratum__trying_000a0340[6];
      tmp42[7] = s_Failed_to_resume_stratum__trying_000a0340[7];
      tmp42[8] = s_Failed_to_resume_stratum__trying_000a0340[8];
      tmp42[9] = s_Failed_to_resume_stratum__trying_000a0340[9];
      tmp42[10] = s_Failed_to_resume_stratum__trying_000a0340[10];
      tmp42[11] = s_Failed_to_resume_stratum__trying_000a0340[11];
      tmp42[12] = s_Failed_to_resume_stratum__trying_000a0340[12];
      tmp42[13] = s_Failed_to_resume_stratum__trying_000a0340[13];
      tmp42[14] = s_Failed_to_resume_stratum__trying_000a0340[14];
      tmp42[15] = s_Failed_to_resume_stratum__trying_000a0340[15];
      tmp42[16] = s_Failed_to_resume_stratum__trying_000a0340[16];
      tmp42[17] = s_Failed_to_resume_stratum__trying_000a0340[17];
      tmp42[18] = s_Failed_to_resume_stratum__trying_000a0340[18];
      tmp42[19] = s_Failed_to_resume_stratum__trying_000a0340[19];
      tmp42[20] = s_Failed_to_resume_stratum__trying_000a0340[20];
      tmp42[21] = s_Failed_to_resume_stratum__trying_000a0340[21];
      tmp42[22] = s_Failed_to_resume_stratum__trying_000a0340[22];
      tmp42[23] = s_Failed_to_resume_stratum__trying_000a0340[23];
      tmp42[24] = s_Failed_to_resume_stratum__trying_000a0340[24];
      tmp42[25] = s_Failed_to_resume_stratum__trying_000a0340[25];
      tmp42[26] = s_Failed_to_resume_stratum__trying_000a0340[26];
      tmp42[27] = s_Failed_to_resume_stratum__trying_000a0340[27];
      tmp42[28] = s_Failed_to_resume_stratum__trying_000a0340[28];
      tmp42[29] = s_Failed_to_resume_stratum__trying_000a0340[29];
      tmp42[30] = s_Failed_to_resume_stratum__trying_000a0340[30];
      tmp42[31] = s_Failed_to_resume_stratum__trying_000a0340[31];
      tmp42[32] = s_Failed_to_resume_stratum__trying_000a0340[32];
      tmp42[33] = s_Failed_to_resume_stratum__trying_000a0340[33];
      tmp42[34] = s_Failed_to_resume_stratum__trying_000a0340[34];
      tmp42[35] = s_Failed_to_resume_stratum__trying_000a0340[35];
      tmp42[36] = s_Failed_to_resume_stratum__trying_000a0340[36];
      tmp42[37] = s_Failed_to_resume_stratum__trying_000a0340[37];
      tmp42[38] = s_Failed_to_resume_stratum__trying_000a0340[38];
      tmp42[39] = s_Failed_to_resume_stratum__trying_000a0340[39];
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
  goto LAB_00042ed8;
}

