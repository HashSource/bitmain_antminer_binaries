
_Bool show_message(pool *pool,json_t *val)

{
  json_t *json;
  char *pcVar1;
  _Bool _Var2;
  json_t *val_local;
  pool *pool_local;
  char tmp42 [2048];
  char *msg;
  
  if ((val == (json_t *)0x0) || (val->type != JSON_ARRAY)) {
    _Var2 = false;
  }
  else {
    json = json_array_get(val,0);
    pcVar1 = json_string_value(json);
    if (pcVar1 == (char *)0x0) {
      _Var2 = false;
    }
    else {
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        snprintf(tmp42,0x800,"Pool %d message: %s",pool->pool_no,pcVar1);
        _applog(5,tmp42,false);
      }
      _Var2 = true;
    }
  }
  return _Var2;
}

