
/* WARNING: Unknown calling convention */

_Bool subscribe_extranonce(pool *pool)

{
  _Bool _Var1;
  size_t len;
  char *pcVar2;
  json_t *json;
  json_t *pjVar3;
  json_t *val;
  int iVar4;
  char *pcVar5;
  size_t sVar6;
  json_error_t err;
  char tmp42 [2048];
  char s [8192];
  
  swork_id = swork_id + 1;
  sprintf(s,"{\"id\": %d, \"method\": \"mining.extranonce.subscribe\", \"params\": []}");
  len = strlen(s);
  _Var1 = stratum_send(pool,s,len);
  if (_Var1) {
    while (_Var1 = socket_full(pool,2), _Var1) {
      pcVar2 = recv_line(pool);
      if (pcVar2 == (char *)0x0) goto LAB_00014cdc;
      _Var1 = parse_method(pool,pcVar2);
      if (!_Var1) {
        json = json_loads(pcVar2,0,&err);
        free(pcVar2);
        pjVar3 = json_object_get(json,"result");
        val = json_object_get(json,"error");
        if ((pjVar3 == (json_t *)0x0) || (pjVar3->type == JSON_FALSE)) {
          if (val != (json_t *)0x0) goto LAB_00014d20;
          pcVar5 = (char *)malloc(0x11);
          pcVar2 = (char *)0x0;
          if (pcVar5 != (char *)0x0) {
            builtin_strncpy(pcVar5,"(unknown reason)",0x11);
            pcVar2 = pcVar5;
          }
LAB_00014d50:
          if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
            snprintf(tmp42,0x800,"Pool %d JSON extranonce subscribe failed: %s",pool->pool_no,pcVar2
                    );
            _applog(6,tmp42,false);
          }
          _Var1 = false;
          free(pcVar2);
        }
        else {
          if ((val == (json_t *)0x0) || (val->type == JSON_NULL)) {
            if ((use_syslog != false) || ((opt_log_output != false || (5 < opt_log_level)))) {
              iVar4 = pool->pool_no;
              pcVar2 = "Stratum extranonce subscribe for pool %d";
LAB_00014db6:
              snprintf(tmp42,0x800,pcVar2,iVar4);
              _Var1 = true;
              _applog(6,tmp42,false);
              goto LAB_00014d86;
            }
          }
          else {
LAB_00014d20:
            pcVar2 = __json_array_string(val,1);
            if (((pcVar2 == (char *)0x0) && (pcVar2 = json_string_value(val), pcVar2 == (char *)0x0)
                ) || ((iVar4 = strcmp(pcVar2,
                                      "Method \'subscribe\' not found for service \'mining.extranonce\'"
                                     ), iVar4 != 0 &&
                      (iVar4 = strcmp(pcVar2,"Unrecognized request provided"), iVar4 != 0)))) {
              pcVar2 = json_dumps(val,3);
              goto LAB_00014d50;
            }
            if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
              iVar4 = pool->pool_no;
              pcVar2 = "Cannot subscribe to mining.extranonce for pool %d";
              goto LAB_00014db6;
            }
          }
          _Var1 = true;
        }
LAB_00014d86:
        if (json == (json_t *)0x0) {
          return _Var1;
        }
        if (json->refcount == 0xffffffff) {
          return _Var1;
        }
        sVar6 = json->refcount - 1;
        json->refcount = sVar6;
        if (sVar6 != 0) {
          return _Var1;
        }
        json_delete(json);
        return _Var1;
      }
      free(pcVar2);
    }
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      builtin_strncpy(tmp42,"Timed out waiting for response extranonce.subscribe",0x34);
      _applog(7,tmp42,false);
    }
    _Var1 = true;
  }
  else {
LAB_00014cdc:
    _Var1 = false;
  }
  return _Var1;
}

