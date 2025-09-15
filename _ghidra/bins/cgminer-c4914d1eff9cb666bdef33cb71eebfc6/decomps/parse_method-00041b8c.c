
_Bool parse_method(pool *pool,char *s)

{
  _Bool _Var1;
  json_t *json;
  json_t *json_00;
  json_t *json_01;
  json_t *val_00;
  char *__s1;
  int iVar2;
  char *s_local;
  pool *pool_local;
  char tmp42 [2048];
  json_error_t err;
  char *buf;
  json_t *params;
  json_t *err_val;
  json_t *method;
  json_t *val;
  char *ss;
  _Bool ret;
  
  ret = false;
  if (s != (char *)0x0) {
    json = json_loads(s,0,&err);
    if (json == (json_t *)0x0) {
      if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
        snprintf(tmp42,0x800,"JSON decode failed(%d): %s",err.line,err.text);
        _applog(6,tmp42,false);
      }
    }
    else {
      json_00 = json_object_get(json,"method");
      if (json_00 != (json_t *)0x0) {
        json_01 = json_object_get(json,"error");
        val_00 = json_object_get(json,"params");
        if ((json_01 == (json_t *)0x0) ||
           ((json_01 != (json_t *)0x0 && (json_01->type == JSON_NULL)))) {
          __s1 = json_string_value(json_00);
          if (__s1 != (char *)0x0) {
            iVar2 = strncasecmp(__s1,"mining.multi_version",0x14);
            if (iVar2 == 0) {
              pool->support_ab = true;
              if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
                builtin_strncpy(tmp42,"Pool support multi versi",0x18);
                tmp42[0x18] = 'o';
                tmp42[0x19] = 'n';
                tmp42[0x1a] = '\0';
                _applog(6,tmp42,false);
              }
              ret = parse_version(pool,val_00);
            }
            else {
              iVar2 = strncasecmp(__s1,"mining.notify",0xd);
              if (iVar2 == 0) {
                _Var1 = parse_notify(pool,val_00);
                if (_Var1) {
                  ret = true;
                  pool->stratum_notify = true;
                }
                else {
                  ret = false;
                  pool->stratum_notify = false;
                }
              }
              else {
                iVar2 = strncasecmp(__s1,"mining.set_version_mask",0x17);
                if (iVar2 == 0) {
                  _Var1 = parse_version_mask(pool,val_00);
                  if (_Var1) {
                    ret = true;
                    pool->stratum_notify = true;
                  }
                  else {
                    ret = false;
                    pool->stratum_notify = false;
                  }
                }
                else {
                  iVar2 = strncasecmp(__s1,"mining.set_difficulty",0x15);
                  if (iVar2 == 0) {
                    ret = parse_diff(pool,val_00);
                  }
                  else {
                    iVar2 = strncasecmp(__s1,"mining.set_extranonce",0x15);
                    if (iVar2 == 0) {
                      ret = parse_extranonce(pool,val_00);
                    }
                    else {
                      iVar2 = strncasecmp(__s1,"client.reconnect",0x10);
                      if (iVar2 == 0) {
                        ret = parse_reconnect(pool,val_00);
                      }
                      else {
                        iVar2 = strncasecmp(__s1,"client.get_version",0x12);
                        if (iVar2 == 0) {
                          ret = send_version(pool,json);
                        }
                        else {
                          iVar2 = strncasecmp(__s1,"client.show_message",0x13);
                          if (iVar2 == 0) {
                            ret = show_message(pool,val_00);
                          }
                          else {
                            iVar2 = strncasecmp(__s1,"mining.ping",0xb);
                            if (iVar2 == 0) {
                              if (((use_syslog != false) || (opt_log_output != false)) ||
                                 (5 < opt_log_level)) {
                                snprintf(tmp42,0x800,"Pool %d ping",pool->pool_no);
                                _applog(6,tmp42,false);
                              }
                              ret = send_pong(pool,json);
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        else {
          if (json_01 == (json_t *)0x0) {
            ss = strdup("(unknown reason)");
          }
          else {
            ss = json_dumps(json_01,3);
          }
          if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
            snprintf(tmp42,0x800,"JSON-RPC method decode failed: %s",ss);
            _applog(6,tmp42,false);
          }
          free(ss);
        }
      }
      json_decref(json);
    }
  }
  return ret;
}

