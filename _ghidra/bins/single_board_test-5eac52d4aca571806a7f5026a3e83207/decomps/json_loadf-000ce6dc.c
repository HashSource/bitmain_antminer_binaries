
/* WARNING: Unknown calling convention */

json_t * json_loadf(FILE *input,size_t flags,json_error_t *error)

{
  int iVar1;
  char *source;
  json_t *pjVar2;
  lex_t lex;
  
  if (input == stdin) {
    source = "<stdin>";
  }
  else {
    source = "<stream>";
  }
  jsonp_error_init(error,source);
  if (input == (FILE *)0x0) {
    error_set(error,(lex_t *)0x0,json_error_invalid_argument,"wrong arguments");
    pjVar2 = (json_t *)0x0;
  }
  else {
    iVar1 = lex_init(&lex,fgetc,flags,input);
    pjVar2 = (json_t *)0x0;
    if (iVar1 == 0) {
      pjVar2 = parse_json(&lex,flags,error);
      lex_close(&lex);
    }
  }
  return pjVar2;
}

