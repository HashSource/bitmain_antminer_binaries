
json_t * json_loadf(FILE *input,size_t flags,json_error_t *error)

{
  int iVar1;
  json_t *pjVar2;
  json_error_t *error_local;
  size_t flags_local;
  FILE *input_local;
  lex_t lex;
  json_t *result;
  char *source;
  
  if (input == stdin) {
    source = "<stdin>";
  }
  else {
    source = "<stream>";
  }
  jsonp_error_init(error,source);
  if (input == (FILE *)0x0) {
    error_set(error,(lex_t *)0x0,"wrong arguments");
    pjVar2 = (json_t *)0x0;
  }
  else {
    iVar1 = lex_init(&lex,fgetc,flags,input);
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

