
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

_Bool parse_extranonce(pool *pool,json_t *val)

{
  _Bool _Var1;
  char *s_00;
  json_t *json;
  size_t sVar2;
  uchar *puVar3;
  json_int_t jVar4;
  json_t *val_local;
  pool *pool_local;
  char tmp42 [2048];
  char s [8192];
  int n2size;
  char *nonce1;
  
  s_00 = json_array_string(val,0);
  _Var1 = _valid_hex(s_00,"util.c","parse_extranonce",0x85c);
  if (_Var1) {
    json = json_array_get(val,1);
    jVar4 = json_integer_value(json);
    if ((uint)jVar4 == 0) {
      if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
        tmp42[0] = s_Failed_to_get_valid_n2size_in_pa_0007b4c8[0];
        tmp42[1] = s_Failed_to_get_valid_n2size_in_pa_0007b4c8[1];
        tmp42[2] = s_Failed_to_get_valid_n2size_in_pa_0007b4c8[2];
        tmp42[3] = s_Failed_to_get_valid_n2size_in_pa_0007b4c8[3];
        tmp42[4] = s_Failed_to_get_valid_n2size_in_pa_0007b4c8[4];
        tmp42[5] = s_Failed_to_get_valid_n2size_in_pa_0007b4c8[5];
        tmp42[6] = s_Failed_to_get_valid_n2size_in_pa_0007b4c8[6];
        tmp42[7] = s_Failed_to_get_valid_n2size_in_pa_0007b4c8[7];
        tmp42[8] = s_Failed_to_get_valid_n2size_in_pa_0007b4c8[8];
        tmp42[9] = s_Failed_to_get_valid_n2size_in_pa_0007b4c8[9];
        tmp42[10] = s_Failed_to_get_valid_n2size_in_pa_0007b4c8[10];
        tmp42[11] = s_Failed_to_get_valid_n2size_in_pa_0007b4c8[11];
        tmp42[12] = s_Failed_to_get_valid_n2size_in_pa_0007b4c8[12];
        tmp42[13] = s_Failed_to_get_valid_n2size_in_pa_0007b4c8[13];
        tmp42[14] = s_Failed_to_get_valid_n2size_in_pa_0007b4c8[14];
        tmp42[15] = s_Failed_to_get_valid_n2size_in_pa_0007b4c8[15];
        tmp42[16] = s_Failed_to_get_valid_n2size_in_pa_0007b4c8[16];
        tmp42[17] = s_Failed_to_get_valid_n2size_in_pa_0007b4c8[17];
        tmp42[18] = s_Failed_to_get_valid_n2size_in_pa_0007b4c8[18];
        tmp42[19] = s_Failed_to_get_valid_n2size_in_pa_0007b4c8[19];
        tmp42[20] = s_Failed_to_get_valid_n2size_in_pa_0007b4c8[20];
        tmp42[21] = s_Failed_to_get_valid_n2size_in_pa_0007b4c8[21];
        tmp42[22] = s_Failed_to_get_valid_n2size_in_pa_0007b4c8[22];
        tmp42[23] = s_Failed_to_get_valid_n2size_in_pa_0007b4c8[23];
        tmp42[24] = s_Failed_to_get_valid_n2size_in_pa_0007b4c8[24];
        tmp42[25] = s_Failed_to_get_valid_n2size_in_pa_0007b4c8[25];
        tmp42[26] = s_Failed_to_get_valid_n2size_in_pa_0007b4c8[26];
        tmp42[27] = s_Failed_to_get_valid_n2size_in_pa_0007b4c8[27];
        tmp42[28] = s_Failed_to_get_valid_n2size_in_pa_0007b4c8[28];
        tmp42[29] = s_Failed_to_get_valid_n2size_in_pa_0007b4c8[29];
        tmp42[30] = s_Failed_to_get_valid_n2size_in_pa_0007b4c8[30];
        tmp42[31] = s_Failed_to_get_valid_n2size_in_pa_0007b4c8[31];
        tmp42[32] = s_Failed_to_get_valid_n2size_in_pa_0007b4c8[32];
        tmp42[33] = s_Failed_to_get_valid_n2size_in_pa_0007b4c8[33];
        tmp42[34] = s_Failed_to_get_valid_n2size_in_pa_0007b4c8[34];
        tmp42[35] = s_Failed_to_get_valid_n2size_in_pa_0007b4c8[35];
        tmp42[36] = s_Failed_to_get_valid_n2size_in_pa_0007b4c8[36];
        tmp42[37] = s_Failed_to_get_valid_n2size_in_pa_0007b4c8[37];
        tmp42[38] = s_Failed_to_get_valid_n2size_in_pa_0007b4c8[38];
        tmp42[39] = s_Failed_to_get_valid_n2size_in_pa_0007b4c8[39];
        tmp42[40] = s_Failed_to_get_valid_n2size_in_pa_0007b4c8[40];
        tmp42[41] = s_Failed_to_get_valid_n2size_in_pa_0007b4c8[41];
        tmp42[42] = s_Failed_to_get_valid_n2size_in_pa_0007b4c8[42];
        tmp42[43] = s_Failed_to_get_valid_n2size_in_pa_0007b4c8[43];
        tmp42._44_2_ = (undefined2)ram0x0007b4f4;
        tmp42[46] = (char)((uint)ram0x0007b4f4 >> 0x10);
        _applog(6,tmp42,false);
      }
      free(s_00);
      _Var1 = false;
    }
    else {
      _cg_wlock(&pool->data_lock,"util.c","parse_extranonce",0x868);
      free(pool->nonce1);
      pool->nonce1 = s_00;
      sVar2 = strlen(s_00);
      pool->n1_len = sVar2 >> 1;
      free(pool->nonce1bin);
      puVar3 = (uchar *)_cgcalloc(pool->n1_len,1,"util.c","parse_extranonce",0x86d);
      pool->nonce1bin = puVar3;
      if (pool->nonce1bin == (uchar *)0x0) {
        snprintf(tmp42,0x800,"Failed to calloc pool->nonce1bin in %s %s():%d","util.c",
                 "parse_extranonce",0x86f);
        _applog(3,tmp42,true);
        _quit(1);
      }
      hex2bin(pool->nonce1bin,pool->nonce1,pool->n1_len);
      pool->n2size = (uint)jVar4;
      _cg_wunlock(&pool->data_lock,"util.c","parse_extranonce",0x872);
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        snprintf(tmp42,0x800,"Pool %d extranonce change requested",pool->pool_no);
        _applog(5,tmp42,false);
      }
      _Var1 = true;
    }
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
      tmp42[0] = s_Failed_to_get_valid_nonce1_in_pa_0007b498[0];
      tmp42[1] = s_Failed_to_get_valid_nonce1_in_pa_0007b498[1];
      tmp42[2] = s_Failed_to_get_valid_nonce1_in_pa_0007b498[2];
      tmp42[3] = s_Failed_to_get_valid_nonce1_in_pa_0007b498[3];
      tmp42[4] = s_Failed_to_get_valid_nonce1_in_pa_0007b498[4];
      tmp42[5] = s_Failed_to_get_valid_nonce1_in_pa_0007b498[5];
      tmp42[6] = s_Failed_to_get_valid_nonce1_in_pa_0007b498[6];
      tmp42[7] = s_Failed_to_get_valid_nonce1_in_pa_0007b498[7];
      tmp42[8] = s_Failed_to_get_valid_nonce1_in_pa_0007b498[8];
      tmp42[9] = s_Failed_to_get_valid_nonce1_in_pa_0007b498[9];
      tmp42[10] = s_Failed_to_get_valid_nonce1_in_pa_0007b498[10];
      tmp42[11] = s_Failed_to_get_valid_nonce1_in_pa_0007b498[11];
      tmp42[12] = s_Failed_to_get_valid_nonce1_in_pa_0007b498[12];
      tmp42[13] = s_Failed_to_get_valid_nonce1_in_pa_0007b498[13];
      tmp42[14] = s_Failed_to_get_valid_nonce1_in_pa_0007b498[14];
      tmp42[15] = s_Failed_to_get_valid_nonce1_in_pa_0007b498[15];
      tmp42[16] = s_Failed_to_get_valid_nonce1_in_pa_0007b498[16];
      tmp42[17] = s_Failed_to_get_valid_nonce1_in_pa_0007b498[17];
      tmp42[18] = s_Failed_to_get_valid_nonce1_in_pa_0007b498[18];
      tmp42[19] = s_Failed_to_get_valid_nonce1_in_pa_0007b498[19];
      tmp42[20] = s_Failed_to_get_valid_nonce1_in_pa_0007b498[20];
      tmp42[21] = s_Failed_to_get_valid_nonce1_in_pa_0007b498[21];
      tmp42[22] = s_Failed_to_get_valid_nonce1_in_pa_0007b498[22];
      tmp42[23] = s_Failed_to_get_valid_nonce1_in_pa_0007b498[23];
      tmp42[24] = s_Failed_to_get_valid_nonce1_in_pa_0007b498[24];
      tmp42[25] = s_Failed_to_get_valid_nonce1_in_pa_0007b498[25];
      tmp42[26] = s_Failed_to_get_valid_nonce1_in_pa_0007b498[26];
      tmp42[27] = s_Failed_to_get_valid_nonce1_in_pa_0007b498[27];
      tmp42[28] = s_Failed_to_get_valid_nonce1_in_pa_0007b498[28];
      tmp42[29] = s_Failed_to_get_valid_nonce1_in_pa_0007b498[29];
      tmp42[30] = s_Failed_to_get_valid_nonce1_in_pa_0007b498[30];
      tmp42[31] = s_Failed_to_get_valid_nonce1_in_pa_0007b498[31];
      tmp42[32] = s_Failed_to_get_valid_nonce1_in_pa_0007b498[32];
      tmp42[33] = s_Failed_to_get_valid_nonce1_in_pa_0007b498[33];
      tmp42[34] = s_Failed_to_get_valid_nonce1_in_pa_0007b498[34];
      tmp42[35] = s_Failed_to_get_valid_nonce1_in_pa_0007b498[35];
      tmp42[36] = s_Failed_to_get_valid_nonce1_in_pa_0007b498[36];
      tmp42[37] = s_Failed_to_get_valid_nonce1_in_pa_0007b498[37];
      tmp42[38] = s_Failed_to_get_valid_nonce1_in_pa_0007b498[38];
      tmp42[39] = s_Failed_to_get_valid_nonce1_in_pa_0007b498[39];
      tmp42[40] = s_Failed_to_get_valid_nonce1_in_pa_0007b498[40];
      tmp42[41] = s_Failed_to_get_valid_nonce1_in_pa_0007b498[41];
      tmp42[42] = s_Failed_to_get_valid_nonce1_in_pa_0007b498[42];
      tmp42[43] = s_Failed_to_get_valid_nonce1_in_pa_0007b498[43];
      tmp42._44_2_ = (undefined2)ram0x0007b4c4;
      tmp42[46] = (char)((uint)ram0x0007b4c4 >> 0x10);
      _applog(6,tmp42,false);
    }
    _Var1 = false;
  }
  return _Var1;
}

