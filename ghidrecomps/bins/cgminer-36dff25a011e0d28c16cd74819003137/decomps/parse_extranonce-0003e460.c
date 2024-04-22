
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

_Bool parse_extranonce(pool *pool,json_t *val)

{
  _Bool _Var1;
  char *s;
  json_t *json;
  size_t sVar2;
  uchar *puVar3;
  json_int_t jVar4;
  json_t *val_local;
  pool *pool_local;
  char tmp42 [2048];
  int n2size;
  char *nonce1;
  
  s = json_array_string(val,0);
  _Var1 = _valid_hex(s,"util.c","parse_extranonce",0x900);
  if (_Var1) {
    json = json_array_get(val,1);
    jVar4 = json_integer_value(json);
    if ((uint)jVar4 == 0) {
      if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
        tmp42[0] = s_Failed_to_get_valid_n2size_in_pa_0009f6a4[0];
        tmp42[1] = s_Failed_to_get_valid_n2size_in_pa_0009f6a4[1];
        tmp42[2] = s_Failed_to_get_valid_n2size_in_pa_0009f6a4[2];
        tmp42[3] = s_Failed_to_get_valid_n2size_in_pa_0009f6a4[3];
        tmp42[4] = s_Failed_to_get_valid_n2size_in_pa_0009f6a4[4];
        tmp42[5] = s_Failed_to_get_valid_n2size_in_pa_0009f6a4[5];
        tmp42[6] = s_Failed_to_get_valid_n2size_in_pa_0009f6a4[6];
        tmp42[7] = s_Failed_to_get_valid_n2size_in_pa_0009f6a4[7];
        tmp42[8] = s_Failed_to_get_valid_n2size_in_pa_0009f6a4[8];
        tmp42[9] = s_Failed_to_get_valid_n2size_in_pa_0009f6a4[9];
        tmp42[10] = s_Failed_to_get_valid_n2size_in_pa_0009f6a4[10];
        tmp42[11] = s_Failed_to_get_valid_n2size_in_pa_0009f6a4[11];
        tmp42[12] = s_Failed_to_get_valid_n2size_in_pa_0009f6a4[12];
        tmp42[13] = s_Failed_to_get_valid_n2size_in_pa_0009f6a4[13];
        tmp42[14] = s_Failed_to_get_valid_n2size_in_pa_0009f6a4[14];
        tmp42[15] = s_Failed_to_get_valid_n2size_in_pa_0009f6a4[15];
        tmp42[16] = s_Failed_to_get_valid_n2size_in_pa_0009f6a4[16];
        tmp42[17] = s_Failed_to_get_valid_n2size_in_pa_0009f6a4[17];
        tmp42[18] = s_Failed_to_get_valid_n2size_in_pa_0009f6a4[18];
        tmp42[19] = s_Failed_to_get_valid_n2size_in_pa_0009f6a4[19];
        tmp42[20] = s_Failed_to_get_valid_n2size_in_pa_0009f6a4[20];
        tmp42[21] = s_Failed_to_get_valid_n2size_in_pa_0009f6a4[21];
        tmp42[22] = s_Failed_to_get_valid_n2size_in_pa_0009f6a4[22];
        tmp42[23] = s_Failed_to_get_valid_n2size_in_pa_0009f6a4[23];
        tmp42[24] = s_Failed_to_get_valid_n2size_in_pa_0009f6a4[24];
        tmp42[25] = s_Failed_to_get_valid_n2size_in_pa_0009f6a4[25];
        tmp42[26] = s_Failed_to_get_valid_n2size_in_pa_0009f6a4[26];
        tmp42[27] = s_Failed_to_get_valid_n2size_in_pa_0009f6a4[27];
        tmp42[28] = s_Failed_to_get_valid_n2size_in_pa_0009f6a4[28];
        tmp42[29] = s_Failed_to_get_valid_n2size_in_pa_0009f6a4[29];
        tmp42[30] = s_Failed_to_get_valid_n2size_in_pa_0009f6a4[30];
        tmp42[31] = s_Failed_to_get_valid_n2size_in_pa_0009f6a4[31];
        tmp42[32] = s_Failed_to_get_valid_n2size_in_pa_0009f6a4[32];
        tmp42[33] = s_Failed_to_get_valid_n2size_in_pa_0009f6a4[33];
        tmp42[34] = s_Failed_to_get_valid_n2size_in_pa_0009f6a4[34];
        tmp42[35] = s_Failed_to_get_valid_n2size_in_pa_0009f6a4[35];
        tmp42[36] = s_Failed_to_get_valid_n2size_in_pa_0009f6a4[36];
        tmp42[37] = s_Failed_to_get_valid_n2size_in_pa_0009f6a4[37];
        tmp42[38] = s_Failed_to_get_valid_n2size_in_pa_0009f6a4[38];
        tmp42[39] = s_Failed_to_get_valid_n2size_in_pa_0009f6a4[39];
        tmp42[40] = s_Failed_to_get_valid_n2size_in_pa_0009f6a4[40];
        tmp42[41] = s_Failed_to_get_valid_n2size_in_pa_0009f6a4[41];
        tmp42[42] = s_Failed_to_get_valid_n2size_in_pa_0009f6a4[42];
        tmp42[43] = s_Failed_to_get_valid_n2size_in_pa_0009f6a4[43];
        tmp42._44_2_ = (undefined2)ram0x0009f6d0;
        tmp42[46] = (char)((uint)ram0x0009f6d0 >> 0x10);
        _applog(6,tmp42,false);
      }
      free(s);
      _Var1 = false;
    }
    else {
      _cg_wlock(&pool->data_lock,"util.c","parse_extranonce",0x90d);
      free(pool->nonce1);
      pool->nonce1 = s;
      sVar2 = strlen(s);
      pool->n1_len = sVar2 >> 1;
      free(pool->nonce1bin);
      puVar3 = (uchar *)_cgcalloc(pool->n1_len,1,"util.c","parse_extranonce",0x912);
      pool->nonce1bin = puVar3;
      if (pool->nonce1bin == (uchar *)0x0) {
        snprintf(tmp42,0x800,"Failed to calloc pool->nonce1bin in %s %s():%d","util.c",
                 "parse_extranonce",0x914);
        _applog(3,tmp42,true);
        _quit(1);
      }
      hex2bin(pool->nonce1bin,pool->nonce1,pool->n1_len);
      pool->n2size = (uint)jVar4;
      _cg_wunlock(&pool->data_lock,"util.c","parse_extranonce",0x917);
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        snprintf(tmp42,0x800,"Pool %d extranonce change requested",pool->pool_no);
        _applog(5,tmp42,false);
      }
      opt_work_update = true;
      _Var1 = true;
    }
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
      tmp42[0] = s_Failed_to_get_valid_nonce1_in_pa_0009f674[0];
      tmp42[1] = s_Failed_to_get_valid_nonce1_in_pa_0009f674[1];
      tmp42[2] = s_Failed_to_get_valid_nonce1_in_pa_0009f674[2];
      tmp42[3] = s_Failed_to_get_valid_nonce1_in_pa_0009f674[3];
      tmp42[4] = s_Failed_to_get_valid_nonce1_in_pa_0009f674[4];
      tmp42[5] = s_Failed_to_get_valid_nonce1_in_pa_0009f674[5];
      tmp42[6] = s_Failed_to_get_valid_nonce1_in_pa_0009f674[6];
      tmp42[7] = s_Failed_to_get_valid_nonce1_in_pa_0009f674[7];
      tmp42[8] = s_Failed_to_get_valid_nonce1_in_pa_0009f674[8];
      tmp42[9] = s_Failed_to_get_valid_nonce1_in_pa_0009f674[9];
      tmp42[10] = s_Failed_to_get_valid_nonce1_in_pa_0009f674[10];
      tmp42[11] = s_Failed_to_get_valid_nonce1_in_pa_0009f674[11];
      tmp42[12] = s_Failed_to_get_valid_nonce1_in_pa_0009f674[12];
      tmp42[13] = s_Failed_to_get_valid_nonce1_in_pa_0009f674[13];
      tmp42[14] = s_Failed_to_get_valid_nonce1_in_pa_0009f674[14];
      tmp42[15] = s_Failed_to_get_valid_nonce1_in_pa_0009f674[15];
      tmp42[16] = s_Failed_to_get_valid_nonce1_in_pa_0009f674[16];
      tmp42[17] = s_Failed_to_get_valid_nonce1_in_pa_0009f674[17];
      tmp42[18] = s_Failed_to_get_valid_nonce1_in_pa_0009f674[18];
      tmp42[19] = s_Failed_to_get_valid_nonce1_in_pa_0009f674[19];
      tmp42[20] = s_Failed_to_get_valid_nonce1_in_pa_0009f674[20];
      tmp42[21] = s_Failed_to_get_valid_nonce1_in_pa_0009f674[21];
      tmp42[22] = s_Failed_to_get_valid_nonce1_in_pa_0009f674[22];
      tmp42[23] = s_Failed_to_get_valid_nonce1_in_pa_0009f674[23];
      tmp42[24] = s_Failed_to_get_valid_nonce1_in_pa_0009f674[24];
      tmp42[25] = s_Failed_to_get_valid_nonce1_in_pa_0009f674[25];
      tmp42[26] = s_Failed_to_get_valid_nonce1_in_pa_0009f674[26];
      tmp42[27] = s_Failed_to_get_valid_nonce1_in_pa_0009f674[27];
      tmp42[28] = s_Failed_to_get_valid_nonce1_in_pa_0009f674[28];
      tmp42[29] = s_Failed_to_get_valid_nonce1_in_pa_0009f674[29];
      tmp42[30] = s_Failed_to_get_valid_nonce1_in_pa_0009f674[30];
      tmp42[31] = s_Failed_to_get_valid_nonce1_in_pa_0009f674[31];
      tmp42[32] = s_Failed_to_get_valid_nonce1_in_pa_0009f674[32];
      tmp42[33] = s_Failed_to_get_valid_nonce1_in_pa_0009f674[33];
      tmp42[34] = s_Failed_to_get_valid_nonce1_in_pa_0009f674[34];
      tmp42[35] = s_Failed_to_get_valid_nonce1_in_pa_0009f674[35];
      tmp42[36] = s_Failed_to_get_valid_nonce1_in_pa_0009f674[36];
      tmp42[37] = s_Failed_to_get_valid_nonce1_in_pa_0009f674[37];
      tmp42[38] = s_Failed_to_get_valid_nonce1_in_pa_0009f674[38];
      tmp42[39] = s_Failed_to_get_valid_nonce1_in_pa_0009f674[39];
      tmp42[40] = s_Failed_to_get_valid_nonce1_in_pa_0009f674[40];
      tmp42[41] = s_Failed_to_get_valid_nonce1_in_pa_0009f674[41];
      tmp42[42] = s_Failed_to_get_valid_nonce1_in_pa_0009f674[42];
      tmp42[43] = s_Failed_to_get_valid_nonce1_in_pa_0009f674[43];
      tmp42._44_2_ = (undefined2)ram0x0009f6a0;
      tmp42[46] = (char)((uint)ram0x0009f6a0 >> 0x10);
      _applog(6,tmp42,false);
    }
    _Var1 = false;
  }
  return _Var1;
}

