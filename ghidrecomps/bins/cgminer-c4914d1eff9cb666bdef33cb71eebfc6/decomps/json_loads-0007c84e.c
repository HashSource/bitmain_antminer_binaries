
json_t * json_loads(char *string,size_t flags,json_error_t *error)

{
  int iVar1;
  json_t *pjVar2;
  json_error_t *error_local;
  size_t flags_local;
  char *string_local;
  string_data_t stream_data;
  lex_t lex;
  json_t *result;
  
  jsonp_error_init(error,"<string>");
  if (string == (char *)0x0) {
    error_set(error,(lex_t *)0x0,"wrong arguments");
    pjVar2 = (json_t *)0x0;
  }
  else {
    stream_data.pos = 0;
    stream_data.data = string;
    iVar1 = lex_init(&lex,string_get + 1,flags,&stream_data);
    if (iVar1 == 0) {
      pjVar2 = parse_json(&lex,flags,error);
      lex_close(&lex);
    }
    else {
      pjVar2 = (json_t *)0x0;
    }
  }
  return pjVar2;
}

