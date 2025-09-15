
json_t * parse_json(lex_t *lex,size_t flags,json_error_t *error)

{
  json_t *json;
  json_error_t *error_local;
  size_t flags_local;
  lex_t *lex_local;
  json_t *result;
  
  lex->depth = 0;
  lex_scan(lex,error);
  if ((((flags & 4) == 0) && (lex->token != 0x5b)) && (lex->token != 0x7b)) {
    error_set(error,lex,"\'[\' or \'{\' expected");
    json = (json_t *)0x0;
  }
  else {
    json = parse_value(lex,flags,error);
    if (json == (json_t *)0x0) {
      json = (json_t *)0x0;
    }
    else if (((flags & 2) == 0) && (lex_scan(lex,error), lex->token != 0)) {
      error_set(error,lex,"end of file expected");
      json_decref(json);
      json = (json_t *)0x0;
    }
    else if (error != (json_error_t *)0x0) {
      error->position = (lex->stream).position;
    }
  }
  return json;
}

