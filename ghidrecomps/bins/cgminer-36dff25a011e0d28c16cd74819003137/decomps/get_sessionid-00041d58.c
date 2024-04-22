
char * get_sessionid(json_t *val)

{
  byte bVar1;
  json_t *json;
  size_t sVar2;
  json_t *val_00;
  char *pcVar3;
  int iVar4;
  json_t *val_local;
  char *notify;
  json_t *arr;
  int arrsize;
  json_t *arr_val;
  int i;
  char *ret;
  
  json = json_array_get(val,0);
  if (((json != (json_t *)0x0) && (json != (json_t *)0x0)) && (json->type == JSON_ARRAY)) {
    sVar2 = json_array_size(json);
    for (i = 0; i < (int)sVar2; i = i + 1) {
      val_00 = json_array_get(json,i);
      if ((val_00 == (json_t *)0x0) || (val_00->type != JSON_ARRAY)) {
        bVar1 = 1;
      }
      else {
        bVar1 = 0;
      }
      if ((bool)(val_00 == (json_t *)0x0 | bVar1)) {
        return (char *)0x0;
      }
      pcVar3 = __json_array_string(val_00,0);
      if ((pcVar3 != (char *)0x0) && (iVar4 = strncasecmp(pcVar3,"mining.notify",0xd), iVar4 == 0))
      {
        pcVar3 = json_array_string(val_00,1);
        return pcVar3;
      }
    }
  }
  return (char *)0x0;
}

