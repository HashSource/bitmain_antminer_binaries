
/* WARNING: Unknown calling convention */

json_t * json_loadfd(int input,size_t flags,json_error_t *error)

{
  int iVar1;
  json_t *pjVar2;
  char *source;
  int local_5c;
  lex_t lex;
  
  if (input == 0) {
    source = "<stdin>";
  }
  else {
    source = "<stream>";
  }
  local_5c = input;
  jsonp_error_init(error,source);
  if (local_5c < 0) {
    error_set(error,(lex_t *)0x0,json_error_invalid_argument,"wrong arguments");
    pjVar2 = (json_t *)0x0;
  }
  else {
    iVar1 = lex_init(&lex,(get_func)0xcda39,flags,&local_5c);
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

