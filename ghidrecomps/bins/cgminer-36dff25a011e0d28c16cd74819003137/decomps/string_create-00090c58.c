
json_t * string_create(char *value,size_t len,int own)

{
  json_t *json;
  int own_local;
  size_t len_local;
  char *value_local;
  json_string_t *string;
  char *v;
  
  if (value == (char *)0x0) {
    json = (json_t *)0x0;
  }
  else {
    v = value;
    if ((own == 0) && (v = jsonp_strndup(value,len), v == (char *)0x0)) {
      json = (json_t *)0x0;
    }
    else {
      json = (json_t *)jsonp_malloc(0x10);
      if (json == (json_t *)0x0) {
        if (own == 0) {
          jsonp_free(v);
        }
        json = (json_t *)0x0;
      }
      else {
        json_init(json,JSON_STRING);
        json[1].type = (json_type)v;
        json[1].refcount = len;
      }
    }
  }
  return json;
}

