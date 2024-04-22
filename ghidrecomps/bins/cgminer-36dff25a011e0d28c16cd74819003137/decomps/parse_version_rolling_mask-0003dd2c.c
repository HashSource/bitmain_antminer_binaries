
_Bool parse_version_rolling_mask(pool *pool,char *sret)

{
  json_t *json;
  json_t *json_00;
  json_t *pjVar1;
  void *pvVar2;
  int iVar3;
  size_t sVar4;
  char *mask_00;
  char *sret_local;
  pool *pool_local;
  char tmp42 [2048];
  json_error_t err;
  json_t *value;
  json_t *err_val;
  json_t *res_val;
  json_t *val;
  char *mask;
  char *key;
  _Bool ret;
  
  ret = false;
  json = json_loads(sret,0,&err);
  if (json == (json_t *)0x0) {
    if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
      snprintf(tmp42,0x800,"JSON decode failed(%d): %s",err.line,err.text);
      _applog(6,tmp42,false);
    }
  }
  else {
    json_00 = json_object_get(json,"result");
    pjVar1 = json_object_get(json,"error");
    if (((json_00 != (json_t *)0x0) && ((json_00 == (json_t *)0x0 || (json_00->type != JSON_NULL))))
       && ((pjVar1 == (json_t *)0x0 || ((pjVar1 != (json_t *)0x0 && (pjVar1->type == JSON_NULL))))))
    {
      pvVar2 = json_object_iter(json_00);
      key = json_object_iter_key(pvVar2);
      while (key != (char *)0x0) {
        pvVar2 = json_object_key_to_iter(key);
        pjVar1 = json_object_iter_value(pvVar2);
        if (pjVar1 == (json_t *)0x0) break;
        iVar3 = strcasecmp(key,"version-rolling");
        if ((iVar3 == 0) && (sVar4 = strlen(key), sVar4 == 0xf)) {
          if ((pjVar1 == (json_t *)0x0) || (pjVar1->type != JSON_TRUE)) {
            pool->support_ab = false;
            pool->version_num = 1;
            goto out;
          }
          if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
            snprintf(tmp42,0x800,"POOL %d support ab mode!",pool->pool_no);
            _applog(5,tmp42,false);
          }
        }
        else {
          iVar3 = strcasecmp(key,"version-rolling.mask");
          if (iVar3 == 0) {
            mask_00 = json_string_value(pjVar1);
            process_version_mask(pool,mask_00);
          }
          else if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
            snprintf(tmp42,0x800,"JSON-RPC unexpected mining.configure value: %s",key);
            _applog(3,tmp42,false);
          }
        }
        pvVar2 = json_object_key_to_iter(key);
        pvVar2 = json_object_iter_next(json_00,pvVar2);
        key = json_object_iter_key(pvVar2);
      }
      ret = true;
    }
  }
out:
  json_decref(json);
  return ret;
}

