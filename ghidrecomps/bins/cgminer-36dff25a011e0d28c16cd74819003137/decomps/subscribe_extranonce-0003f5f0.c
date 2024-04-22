
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
          goto out;
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
            goto out;
          }
          if ((ss != (char *)0x0) &&
             (iVar3 = strcmp(ss,"Unrecognized request provided"), iVar3 == 0)) {
            if ((use_syslog != false) || ((opt_log_output != false || (5 < opt_log_level)))) {
              snprintf(tmp42,0x800,"Cannot subscribe to mining.extranonce for pool %d",pool->pool_no
                      );
              _applog(6,tmp42,false);
            }
            ret = true;
            goto out;
          }
          ss = json_dumps(val_00,3);
        }
        if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
          snprintf(tmp42,0x800,"Pool %d JSON extranonce subscribe failed: %s",pool->pool_no,ss);
          _applog(6,tmp42,false);
        }
        free(ss);
        goto out;
      }
      free(s_00);
    }
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      tmp42[0] = s_Timed_out_waiting_for_response_e_0009fa10[0];
      tmp42[1] = s_Timed_out_waiting_for_response_e_0009fa10[1];
      tmp42[2] = s_Timed_out_waiting_for_response_e_0009fa10[2];
      tmp42[3] = s_Timed_out_waiting_for_response_e_0009fa10[3];
      tmp42[4] = s_Timed_out_waiting_for_response_e_0009fa10[4];
      tmp42[5] = s_Timed_out_waiting_for_response_e_0009fa10[5];
      tmp42[6] = s_Timed_out_waiting_for_response_e_0009fa10[6];
      tmp42[7] = s_Timed_out_waiting_for_response_e_0009fa10[7];
      tmp42[8] = s_Timed_out_waiting_for_response_e_0009fa10[8];
      tmp42[9] = s_Timed_out_waiting_for_response_e_0009fa10[9];
      tmp42[10] = s_Timed_out_waiting_for_response_e_0009fa10[10];
      tmp42[11] = s_Timed_out_waiting_for_response_e_0009fa10[11];
      tmp42[12] = s_Timed_out_waiting_for_response_e_0009fa10[12];
      tmp42[13] = s_Timed_out_waiting_for_response_e_0009fa10[13];
      tmp42[14] = s_Timed_out_waiting_for_response_e_0009fa10[14];
      tmp42[15] = s_Timed_out_waiting_for_response_e_0009fa10[15];
      tmp42[16] = s_Timed_out_waiting_for_response_e_0009fa10[16];
      tmp42[17] = s_Timed_out_waiting_for_response_e_0009fa10[17];
      tmp42[18] = s_Timed_out_waiting_for_response_e_0009fa10[18];
      tmp42[19] = s_Timed_out_waiting_for_response_e_0009fa10[19];
      tmp42[20] = s_Timed_out_waiting_for_response_e_0009fa10[20];
      tmp42[21] = s_Timed_out_waiting_for_response_e_0009fa10[21];
      tmp42[22] = s_Timed_out_waiting_for_response_e_0009fa10[22];
      tmp42[23] = s_Timed_out_waiting_for_response_e_0009fa10[23];
      tmp42[24] = s_Timed_out_waiting_for_response_e_0009fa10[24];
      tmp42[25] = s_Timed_out_waiting_for_response_e_0009fa10[25];
      tmp42[26] = s_Timed_out_waiting_for_response_e_0009fa10[26];
      tmp42[27] = s_Timed_out_waiting_for_response_e_0009fa10[27];
      tmp42[28] = s_Timed_out_waiting_for_response_e_0009fa10[28];
      tmp42[29] = s_Timed_out_waiting_for_response_e_0009fa10[29];
      tmp42[30] = s_Timed_out_waiting_for_response_e_0009fa10[30];
      tmp42[31] = s_Timed_out_waiting_for_response_e_0009fa10[31];
      tmp42[32] = s_Timed_out_waiting_for_response_e_0009fa10[32];
      tmp42[33] = s_Timed_out_waiting_for_response_e_0009fa10[33];
      tmp42[34] = s_Timed_out_waiting_for_response_e_0009fa10[34];
      tmp42[35] = s_Timed_out_waiting_for_response_e_0009fa10[35];
      tmp42[36] = s_Timed_out_waiting_for_response_e_0009fa10[36];
      tmp42[37] = s_Timed_out_waiting_for_response_e_0009fa10[37];
      tmp42[38] = s_Timed_out_waiting_for_response_e_0009fa10[38];
      tmp42[39] = s_Timed_out_waiting_for_response_e_0009fa10[39];
      tmp42[40] = s_Timed_out_waiting_for_response_e_0009fa10[40];
      tmp42[41] = s_Timed_out_waiting_for_response_e_0009fa10[41];
      tmp42[42] = s_Timed_out_waiting_for_response_e_0009fa10[42];
      tmp42[43] = s_Timed_out_waiting_for_response_e_0009fa10[43];
      tmp42[44] = s_Timed_out_waiting_for_response_e_0009fa10[44];
      tmp42[45] = s_Timed_out_waiting_for_response_e_0009fa10[45];
      tmp42[46] = s_Timed_out_waiting_for_response_e_0009fa10[46];
      tmp42[47] = s_Timed_out_waiting_for_response_e_0009fa10[47];
      tmp42[48] = s_Timed_out_waiting_for_response_e_0009fa10[48];
      tmp42[49] = s_Timed_out_waiting_for_response_e_0009fa10[49];
      tmp42[50] = s_Timed_out_waiting_for_response_e_0009fa10[50];
      tmp42[51] = s_Timed_out_waiting_for_response_e_0009fa10[51];
      _applog(7,tmp42,false);
    }
    ret = true;
out:
    json_decref(val);
  }
  else {
    ret = false;
  }
  return ret;
}

