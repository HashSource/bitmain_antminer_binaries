
_Bool initiate_stratum(pool *pool)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  undefined4 uVar4;
  _Bool _Var5;
  size_t sVar6;
  send_ret sVar7;
  char *pcVar8;
  json_t *pjVar9;
  json_t *json;
  char *s_00;
  uint uVar10;
  int iVar11;
  uchar *puVar12;
  json_int_t jVar13;
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
    _Var5 = setup_stratum_socket(pool);
    iVar11 = swork_id;
    if (_Var5) {
      bVar3 = true;
      if (bVar1) {
        clear_sock(pool);
        iVar11 = swork_id;
        swork_id = swork_id + 1;
        sprintf(s,"{\"id\": %d, \"method\": \"mining.subscribe\", \"params\": []}",iVar11);
      }
      else if (pool->sessionid == (char *)0x0) {
        swork_id = swork_id + 1;
        sprintf(s,"{\"id\": %d, \"method\": \"mining.subscribe\", \"params\": [\"bmminer/2.0.0\"]}",
                iVar11);
      }
      else {
        swork_id = swork_id + 1;
        sprintf(s,
                "{\"id\": %d, \"method\": \"mining.subscribe\", \"params\": [\"bmminer/2.0.0\", \"%s\"]}"
                ,iVar11,pool->sessionid);
      }
      sVar6 = strlen(s);
      sVar7 = __stratum_send(pool,s,sVar6);
      if (sVar7 == SEND_OK) {
        _Var5 = socket_full(pool,0x3c);
        if (_Var5) {
          pcVar8 = recv_line(pool);
          if (pcVar8 != (char *)0x0) {
            bVar1 = true;
            val = json_loads(pcVar8,0,&err);
            free(pcVar8);
            if (val == (json_t *)0x0) {
              if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
                snprintf(tmp42,0x800,"JSON decode failed(%d): %s",err.line,err.text);
                _applog(6,tmp42,false);
              }
            }
            else {
              pjVar9 = json_object_get(val,"result");
              json = json_object_get(val,"error");
              if (((pjVar9 == (json_t *)0x0) ||
                  ((pjVar9 != (json_t *)0x0 && (pjVar9->type == JSON_NULL)))) ||
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
                pcVar8 = get_sessionid(pjVar9);
                if (((pcVar8 == (char *)0x0) && (opt_debug != false)) &&
                   ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
                  builtin_strncpy(tmp42,"Failed to get sessionid in initiate_stratum",0x2c);
                  _applog(7,tmp42,false);
                }
                s_00 = json_array_string(pjVar9,1);
                _Var5 = _valid_hex(s_00,"util.c","initiate_stratum",0xbf0);
                uVar4 = tmp42._44_4_;
                if (_Var5) {
                  pjVar9 = json_array_get(pjVar9,2);
                  jVar13 = json_integer_value(pjVar9);
                  uVar4 = tmp42._44_4_;
                  uVar10 = (uint)jVar13;
                  if (((int)uVar10 < 2) || (0x10 < (int)uVar10)) {
                    if ((use_syslog != false) || ((opt_log_output != false || (5 < opt_log_level))))
                    {
                      builtin_strncpy(tmp42,"Failed to get valid n2size in initiate_stratum",0x2f);
                      tmp42[0x2f] = SUB41(uVar4,3);
                      _applog(6,tmp42,false);
                    }
                    free(pcVar8);
                    free(s_00);
                  }
                  else {
                    if ((((pcVar8 != (char *)0x0) && (pool->sessionid != (char *)0x0)) &&
                        (iVar11 = strcmp(pcVar8,pool->sessionid), iVar11 == 0)) &&
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
                    pool->sessionid = pcVar8;
                    pool->nonce1 = s_00;
                    sVar6 = strlen(s_00);
                    pool->n1_len = sVar6 >> 1;
                    free(pool->nonce1bin);
                    puVar12 = (uchar *)_cgcalloc(pool->n1_len,1,"util.c","initiate_stratum",0xc0b);
                    pool->nonce1bin = puVar12;
                    hex2bin(pool->nonce1bin,pool->nonce1,pool->n1_len);
                    pool->n2size = uVar10;
                    _cg_wunlock(&pool->data_lock,"util.c","initiate_stratum",0xc0e);
                    if (((pcVar8 != (char *)0x0) && (opt_debug != false)) &&
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
                    builtin_strncpy(tmp42,"Failed to get valid nonce1 in initiate_stratum",0x2f);
                    tmp42[0x2f] = SUB41(uVar4,3);
                    _applog(6,tmp42,false);
                  }
                  free(pcVar8);
                }
              }
            }
          }
        }
        else if ((opt_debug != false) &&
                (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          builtin_strncpy(tmp42,"Timed out waiting for response in initiate_strat",0x30);
          tmp42[0x30] = 'u';
          tmp42[0x31] = 'm';
          tmp42[0x32] = '\0';
          _applog(7,tmp42,false);
        }
      }
      else if ((opt_debug != false) &&
              (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        builtin_strncpy(tmp42,"Failed to send s in initiate_stratum",0x24);
        tmp42._36_4_ = tmp42._36_4_ & 0xffffff00;
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
        builtin_strncpy(tmp42,"Initiate stratum failed",0x18);
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
      builtin_strncpy(tmp42,"Failed to resume stratum, trying afresh",0x28);
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

