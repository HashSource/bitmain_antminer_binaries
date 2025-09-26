
/* WARNING: Unknown calling convention */

json_t * parse_json(lex_t *lex,size_t flags,json_error_t *error)

{
  bool bVar1;
  json_t *json;
  size_t sVar2;
  size_t *psVar3;
  
  lex->depth = 0;
  lex_scan(lex,error);
  if (((flags & 4) == 0) && ((lex->token & 0xffffffdfU) != 0x5b)) {
    error_set(error,lex,json_error_invalid_syntax,"\'[\' or \'{\' expected");
  }
  else {
    json = parse_value(lex,flags,error);
    if (json != (json_t *)0x0) {
      if (((int)(flags << 0x1e) < 0) || (lex_scan(lex,error), lex->token == 0)) {
        if (error != (json_error_t *)0x0) {
          error->position = (lex->stream).position;
          return json;
        }
        return json;
      }
      error_set(error,lex,json_error_end_of_input_expected,"end of file expected");
      if (json->refcount != 0xffffffff) {
        psVar3 = &json->refcount;
        DataMemoryBarrier(0x1f);
        do {
          ExclusiveAccess(psVar3);
          sVar2 = *psVar3;
          bVar1 = (bool)hasExclusiveAccess(psVar3);
        } while (!bVar1);
        *psVar3 = sVar2 - 1;
        if (sVar2 - 1 == 0) {
          json_delete(json);
          return (json_t *)0x0;
        }
      }
    }
  }
  return (json_t *)0x0;
}

