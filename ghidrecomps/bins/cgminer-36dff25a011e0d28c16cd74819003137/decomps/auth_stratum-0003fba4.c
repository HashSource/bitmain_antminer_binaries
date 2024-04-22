
_Bool auth_stratum(pool *pool)

{
  int iVar1;
  _Bool _Var2;
  size_t sVar3;
  char *s_00;
  json_t *json;
  json_t *pjVar4;
  json_t *json_00;
  uint32_t uVar5;
  pool *pool_local;
  char tmp42 [2048];
  json_error_t err;
  char s [8192];
  json_t *err_val;
  json_t *res_val;
  char *sret;
  json_t *val;
  char *ss;
  _Bool ret;
  
  iVar1 = swork_id;
  ret = false;
  swork_id = swork_id + 1;
  sprintf(s,"{\"id\": %d, \"method\": \"mining.authorize\", \"params\": [\"%s\", \"%s\"]}",iVar1,
          pool->rpc_user,pool->rpc_pass);
  sVar3 = strlen(s);
  _Var2 = stratum_send(pool,s,sVar3);
  if (_Var2) {
    while (s_00 = recv_line(pool), s_00 != (char *)0x0) {
      _Var2 = parse_method(pool,s_00);
      if (!_Var2) {
        json = json_loads(s_00,0,&err);
        free(s_00);
        pjVar4 = json_object_get(json,"result");
        json_00 = json_object_get(json,"error");
        if (((pjVar4 == (json_t *)0x0) ||
            ((pjVar4 != (json_t *)0x0 && (pjVar4->type == JSON_FALSE)))) ||
           ((json_00 != (json_t *)0x0 &&
            ((json_00 == (json_t *)0x0 || (json_00->type != JSON_NULL)))))) {
          if (json_00 == (json_t *)0x0) {
            ss = strdup("(unknown reason)");
          }
          else {
            ss = json_dumps(json_00,3);
          }
          if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
            snprintf(tmp42,0x800,"pool %d JSON stratum auth failed: %s",pool->pool_no,ss);
            _applog(6,tmp42,false);
          }
          free(ss);
          suspend_stratum(pool);
        }
        else {
          ret = true;
          if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
            snprintf(tmp42,0x800,"Stratum authorisation success for pool %d",pool->pool_no);
            _applog(6,tmp42,false);
          }
          pool->probed = true;
          iVar1 = swork_id;
          successful_connect = true;
          if (opt_suggest_diff != 0) {
            swork_id = swork_id + 1;
            sprintf(s,"{\"id\": %d, \"method\": \"mining.suggest_difficulty\", \"params\": [%d]}",
                    iVar1,opt_suggest_diff);
            sVar3 = strlen(s);
            stratum_send(pool,s,sVar3);
          }
          if (opt_bitmain_ab != false) {
            if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
              tmp42[0] = s_LOW_POWER_MODE__0009fc10[0];
              tmp42[1] = s_LOW_POWER_MODE__0009fc10[1];
              tmp42[2] = s_LOW_POWER_MODE__0009fc10[2];
              tmp42[3] = s_LOW_POWER_MODE__0009fc10[3];
              tmp42[4] = s_LOW_POWER_MODE__0009fc10[4];
              tmp42[5] = s_LOW_POWER_MODE__0009fc10[5];
              tmp42[6] = s_LOW_POWER_MODE__0009fc10[6];
              tmp42[7] = s_LOW_POWER_MODE__0009fc10[7];
              tmp42[8] = s_LOW_POWER_MODE__0009fc10[8];
              tmp42[9] = s_LOW_POWER_MODE__0009fc10[9];
              tmp42[10] = s_LOW_POWER_MODE__0009fc10[10];
              tmp42[11] = s_LOW_POWER_MODE__0009fc10[11];
              tmp42[12] = s_LOW_POWER_MODE__0009fc10[12];
              tmp42[13] = s_LOW_POWER_MODE__0009fc10[13];
              tmp42[14] = s_LOW_POWER_MODE__0009fc10[14];
              tmp42[15] = s_LOW_POWER_MODE__0009fc10[15];
              _applog(5,tmp42,false);
            }
            iVar1 = swork_id;
            swork_id = swork_id + 1;
            uVar5 = swab32(0xc000);
            sprintf(s,
                    "{\"id\":%d, \"method\":\"mining.configure\", \"params\":[[\"version-rolling\"],{\"version-rolling.mask\":\"%08x\",\"version-rolling.min-bit-count\":%d}]}"
                    ,iVar1,uVar5,2);
            sVar3 = strlen(s);
            stratum_send(pool,s,sVar3);
            pool->version_num = 1;
          }
        }
        json_decref(json);
        return ret;
      }
      free(s_00);
    }
  }
  return false;
}

