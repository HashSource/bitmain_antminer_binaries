
/* WARNING: Unknown calling convention */

json_t * json_loadb(char *buffer,size_t buflen,size_t flags,json_error_t *error)

{
  int iVar1;
  json_t *pjVar2;
  buffer_data_t stream_data;
  lex_t lex;
  
  jsonp_error_init(error,"<buffer>");
  if (buffer == (char *)0x0) {
    error_set(error,(lex_t *)0x0,json_error_invalid_argument,"wrong arguments");
    pjVar2 = (json_t *)0x0;
  }
  else {
    pjVar2 = (json_t *)0x0;
    stream_data.pos = 0;
    stream_data.data = buffer;
    stream_data.len = buflen;
    iVar1 = lex_init(&lex,(get_func)0x1cff95,flags,&stream_data);
    if (iVar1 == 0) {
      pjVar2 = parse_json(&lex,flags,error);
      lex_close(&lex);
    }
  }
  return pjVar2;
}

