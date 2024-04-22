
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
              pool->support_vil = true;
              if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
                tmp42[0] = s_Pool_support_multi_version_0007b748[0];
                tmp42[1] = s_Pool_support_multi_version_0007b748[1];
                tmp42[2] = s_Pool_support_multi_version_0007b748[2];
                tmp42[3] = s_Pool_support_multi_version_0007b748[3];
                tmp42[4] = s_Pool_support_multi_version_0007b748[4];
                tmp42[5] = s_Pool_support_multi_version_0007b748[5];
                tmp42[6] = s_Pool_support_multi_version_0007b748[6];
                tmp42[7] = s_Pool_support_multi_version_0007b748[7];
                tmp42[8] = s_Pool_support_multi_version_0007b748[8];
                tmp42[9] = s_Pool_support_multi_version_0007b748[9];
                tmp42[10] = s_Pool_support_multi_version_0007b748[10];
                tmp42[11] = s_Pool_support_multi_version_0007b748[11];
                tmp42[12] = s_Pool_support_multi_version_0007b748[12];
                tmp42[13] = s_Pool_support_multi_version_0007b748[13];
                tmp42[14] = s_Pool_support_multi_version_0007b748[14];
                tmp42[15] = s_Pool_support_multi_version_0007b748[15];
                tmp42[16] = s_Pool_support_multi_version_0007b748[16];
                tmp42[17] = s_Pool_support_multi_version_0007b748[17];
                tmp42[18] = s_Pool_support_multi_version_0007b748[18];
                tmp42[19] = s_Pool_support_multi_version_0007b748[19];
                tmp42[20] = s_Pool_support_multi_version_0007b748[20];
                tmp42[21] = s_Pool_support_multi_version_0007b748[21];
                tmp42[22] = s_Pool_support_multi_version_0007b748[22];
                tmp42[23] = s_Pool_support_multi_version_0007b748[23];
                tmp42._24_2_ = (undefined2)ram0x0007b760;
                tmp42[26] = (char)((uint)ram0x0007b760 >> 0x10);
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

