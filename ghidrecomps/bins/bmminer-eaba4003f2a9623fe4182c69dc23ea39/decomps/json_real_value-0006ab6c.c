
double json_real_value(json_t *json)

{
  json_type jVar1;
  size_t sVar2;
  json_t *json_local;
  
  if ((json == (json_t *)0x0) || (json->type != JSON_REAL)) {
    jVar1 = JSON_OBJECT;
    sVar2 = 0;
  }
  else {
    jVar1 = json[1].type;
    sVar2 = json[1].refcount;
  }
  return (double)CONCAT44(sVar2,jVar1);
}

