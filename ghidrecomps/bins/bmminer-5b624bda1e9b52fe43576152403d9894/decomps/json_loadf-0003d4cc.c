
/* WARNING: Unknown calling convention */

json_t * json_loadf(FILE *input,size_t flags,json_error_t *error)

{
  int iVar1;
  json_t *result;
  char *source;
  json_t *pjVar2;
  lex_t lex;
  
  source = DAT_0003d524;
  if (input == *DAT_0003d520) {
    source = DAT_0003d528;
  }
  jsonp_error_init(error,source);
  if (input == (FILE *)0x0) {
    error_set(error,(lex_t *)0x0,DAT_0003d530);
    pjVar2 = (json_t *)0x0;
  }
  else {
    pjVar2 = (json_t *)0x0;
    iVar1 = lex_init(&lex,DAT_0003d52c,input);
    if (iVar1 == 0) {
      pjVar2 = parse_json(&lex,flags,error);
      lex_close(&lex);
    }
  }
  return pjVar2;
}

