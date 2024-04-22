
/* WARNING: Unknown calling convention */

json_t * parse_json(lex_t *lex,size_t flags,json_error_t *error)

{
  json_t *json;
  json_t *result;
  size_t sVar1;
  
  lex_scan(lex,error);
  if (((flags & 4) == 0) && ((lex->token & 0xffffffdfU) != 0x5b)) {
    error_set(error,lex,DAT_0003d410);
    return (json_t *)0x0;
  }
  json = parse_value(lex,flags,error);
  if (json != (json_t *)0x0) {
    if (((int)(flags << 0x1e) < 0) || (lex_scan(lex,error), lex->token == 0)) {
      if (error == (json_error_t *)0x0) {
        return json;
      }
      error->position = (lex->stream).position;
      return json;
    }
    error_set(error,lex,DAT_0003d40c);
    if ((json->refcount != 0xffffffff) &&
       (sVar1 = json->refcount - 1, json->refcount = sVar1, sVar1 == 0)) {
      json_delete(json);
      return (json_t *)0x0;
    }
  }
  return (json_t *)0x0;
}

