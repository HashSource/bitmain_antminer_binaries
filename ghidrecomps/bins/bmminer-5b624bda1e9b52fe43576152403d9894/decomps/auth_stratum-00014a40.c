
/* WARNING: Unknown calling convention */

_Bool auth_stratum(pool *pool)

{
  int iVar1;
  _Bool _Var2;
  size_t sVar3;
  char *pcVar4;
  json_t *json;
  json_t *pjVar5;
  json_t *json_00;
  char *pcVar6;
  size_t sVar7;
  json_error_t err;
  char tmp42 [2048];
  char s [8192];
  
  iVar1 = swork_id;
  swork_id = swork_id + 1;
  sprintf(s,"{\"id\": %d, \"method\": \"mining.authorize\", \"params\": [\"%s\", \"%s\"]}",iVar1,
          pool->rpc_user,pool->rpc_pass);
  sVar3 = strlen(s);
  _Var2 = stratum_send(pool,s,sVar3);
  if (_Var2) {
    while (pcVar4 = recv_line(pool), pcVar4 != (char *)0x0) {
      _Var2 = parse_method(pool,pcVar4);
      if (!_Var2) {
        json = json_loads(pcVar4,0,&err);
        free(pcVar4);
        pjVar5 = json_object_get(json,"result");
        json_00 = json_object_get(json,"error");
        if ((pjVar5 == (json_t *)0x0) || (pjVar5->type == JSON_FALSE)) {
          if (json_00 != (json_t *)0x0) goto LAB_00014ae8;
          pcVar6 = (char *)malloc(0x11);
          pcVar4 = (char *)0x0;
          if (pcVar6 != (char *)0x0) {
            builtin_strncpy(pcVar6,"(unknown reason)",0x11);
            pcVar4 = pcVar6;
          }
        }
        else {
          if ((json_00 == (json_t *)0x0) || (json_00->type == JSON_NULL)) {
            if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
              snprintf(tmp42,0x800,"Stratum authorisation success for pool %d",pool->pool_no);
              _applog(6,tmp42,false);
            }
            pool->probed = true;
            successful_connect = true;
            if (opt_suggest_diff != 0) {
              swork_id = swork_id + 1;
              sprintf(s,"{\"id\": %d, \"method\": \"mining.suggest_difficulty\", \"params\": [%d]}")
              ;
              sVar3 = strlen(s);
              stratum_send(pool,s,sVar3);
            }
            _Var2 = true;
            if (opt_multi_version != 0) {
              _Var2 = true;
              swork_id = swork_id + 1;
              sprintf(s,"{\"id\": %d, \"method\": \"mining.multi_version\", \"params\": [%d]}");
              sVar3 = strlen(s);
              stratum_send(pool,s,sVar3);
            }
            goto LAB_00014b2e;
          }
LAB_00014ae8:
          pcVar4 = json_dumps(json_00,3);
        }
        if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
          snprintf(tmp42,0x800,"pool %d JSON stratum auth failed: %s",pool->pool_no,pcVar4);
          _applog(6,tmp42,false);
        }
        _Var2 = false;
        free(pcVar4);
        suspend_stratum(pool);
LAB_00014b2e:
        if (json == (json_t *)0x0) {
          return _Var2;
        }
        if (json->refcount == 0xffffffff) {
          return _Var2;
        }
        sVar7 = json->refcount - 1;
        json->refcount = sVar7;
        if (sVar7 != 0) {
          return _Var2;
        }
        json_delete(json);
        return _Var2;
      }
      free(pcVar4);
    }
  }
  return false;
}

