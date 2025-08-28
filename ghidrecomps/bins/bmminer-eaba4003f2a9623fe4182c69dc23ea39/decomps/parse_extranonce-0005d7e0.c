
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
        builtin_strncpy(tmp42,"Failed to get valid n2size in parse_extranon",0x2c);
        tmp42[0x2c] = 'c';
        tmp42[0x2d] = 'e';
        tmp42[0x2e] = '\0';
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
      builtin_strncpy(tmp42,"Failed to get valid nonce1 in parse_extranon",0x2c);
      tmp42[0x2c] = 'c';
      tmp42[0x2d] = 'e';
      tmp42[0x2e] = '\0';
      _applog(6,tmp42,false);
    }
    _Var1 = false;
  }
  return _Var1;
}

