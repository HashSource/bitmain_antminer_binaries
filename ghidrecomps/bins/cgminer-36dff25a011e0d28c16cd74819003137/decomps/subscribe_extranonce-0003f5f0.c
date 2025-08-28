
_Bool subscribe_extranonce(pool *pool)

{
  _Bool _Var1;
  size_t len;
  char *s_00;
  json_t *pjVar2;
  json_t *val_00;
  int iVar3;
  pool *pool_local;
  char tmp42 [2048];
  json_error_t err;
  char s [8192];
  json_t *err_val;
  json_t *res_val;
  char *sret;
  char *ss;
  _Bool ret;
  json_t *val;
  
  val = (json_t *)0x0;
  ret = false;
  swork_id = swork_id + 1;
  sprintf(s,"{\"id\": %d, \"method\": \"mining.extranonce.subscribe\", \"params\": []}");
  len = strlen(s);
  _Var1 = stratum_send(pool,s,len);
  if (_Var1) {
    while (_Var1 = socket_full(pool,2), _Var1) {
      s_00 = recv_line(pool);
      if (s_00 == (char *)0x0) {
        return false;
      }
      _Var1 = parse_method(pool,s_00);
      if (!_Var1) {
        val = json_loads(s_00,0,&err);
        free(s_00);
        pjVar2 = json_object_get(val,"result");
        val_00 = json_object_get(val,"error");
        if (((pjVar2 != (json_t *)0x0) &&
            ((pjVar2 == (json_t *)0x0 || (pjVar2->type != JSON_FALSE)))) &&
           ((val_00 == (json_t *)0x0 || ((val_00 != (json_t *)0x0 && (val_00->type == JSON_NULL)))))
           ) {
          ret = true;
          if ((use_syslog != false) || ((opt_log_output != false || (5 < opt_log_level)))) {
            snprintf(tmp42,0x800,"Stratum extranonce subscribe for pool %d",pool->pool_no);
            _applog(6,tmp42,false);
          }
          goto LAB_0003fb8c;
        }
        if (val_00 == (json_t *)0x0) {
          ss = strdup("(unknown reason)");
        }
        else {
          ss = __json_array_string(val_00,1);
          if (ss == (char *)0x0) {
            ss = json_string_value(val_00);
          }
          if ((ss != (char *)0x0) &&
             (iVar3 = strcmp(ss,"Method \'subscribe\' not found for service \'mining.extranonce\'"),
             iVar3 == 0)) {
            if ((use_syslog != false) || ((opt_log_output != false || (5 < opt_log_level)))) {
              snprintf(tmp42,0x800,"Cannot subscribe to mining.extranonce for pool %d",pool->pool_no
                      );
              _applog(6,tmp42,false);
            }
            ret = true;
            goto LAB_0003fb8c;
          }
          if ((ss != (char *)0x0) &&
             (iVar3 = strcmp(ss,"Unrecognized request provided"), iVar3 == 0)) {
            if ((use_syslog != false) || ((opt_log_output != false || (5 < opt_log_level)))) {
              snprintf(tmp42,0x800,"Cannot subscribe to mining.extranonce for pool %d",pool->pool_no
                      );
              _applog(6,tmp42,false);
            }
            ret = true;
            goto LAB_0003fb8c;
          }
          ss = json_dumps(val_00,3);
        }
        if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
          snprintf(tmp42,0x800,"Pool %d JSON extranonce subscribe failed: %s",pool->pool_no,ss);
          _applog(6,tmp42,false);
        }
        free(ss);
        goto LAB_0003fb8c;
      }
      free(s_00);
    }
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      builtin_strncpy(tmp42,"Timed out waiting for response extranonce.subscribe",0x34);
      _applog(7,tmp42,false);
    }
    ret = true;
LAB_0003fb8c:
    json_decref(val);
  }
  else {
    ret = false;
  }
  return ret;
}

