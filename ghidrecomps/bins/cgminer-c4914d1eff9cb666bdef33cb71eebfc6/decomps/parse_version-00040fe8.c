
_Bool parse_version(pool *pool,json_t *val)

{
  json_t *pjVar1;
  size_t sVar2;
  json_int_t jVar3;
  json_t *val_local;
  pool *pool_local;
  int i;
  
  i = 0;
  while( true ) {
    sVar2 = json_array_size(val);
    if (sVar2 <= (uint)i) {
      return true;
    }
    pjVar1 = json_array_get(val,i);
    if ((pjVar1 == (json_t *)0x0) || (pjVar1 = json_array_get(val,i), pjVar1->type != JSON_INTEGER))
    break;
    pjVar1 = json_array_get(val,i);
    jVar3 = json_integer_value(pjVar1);
    pool->version[i] = (int)jVar3;
    i = i + 1;
  }
  return false;
}

