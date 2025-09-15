
_Bool send_version(pool *pool,json_t *val)

{
  _Bool _Var1;
  json_t *pjVar2;
  size_t len;
  json_int_t jVar3;
  json_t *val_local;
  pool *pool_local;
  char s [8192];
  int id;
  json_t *id_val;
  
  pjVar2 = json_object_get(val,"id");
  if (pjVar2 == (json_t *)0x0) {
    _Var1 = false;
  }
  else {
    pjVar2 = json_object_get(val,"id");
    jVar3 = json_integer_value(pjVar2);
    sprintf(s,"{\"id\": %d, \"result\": \"bmminer/2.0.0\", \"error\": null}",(int)jVar3);
    len = strlen(s);
    _Var1 = stratum_send(pool,s,len);
    if (_Var1) {
      _Var1 = true;
    }
    else {
      _Var1 = false;
    }
  }
  return _Var1;
}

