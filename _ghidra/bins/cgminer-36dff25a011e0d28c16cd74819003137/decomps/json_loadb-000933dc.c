
json_t * json_loadb(char *buffer,size_t buflen,size_t flags,json_error_t *error)

{
  int iVar1;
  json_t *pjVar2;
  json_error_t *error_local;
  size_t flags_local;
  size_t buflen_local;
  char *buffer_local;
  buffer_data_t stream_data;
  lex_t lex;
  json_t *result;
  
  jsonp_error_init(error,"<buffer>");
  if (buffer == (char *)0x0) {
    error_set(error,(lex_t *)0x0,"wrong arguments");
    pjVar2 = (json_t *)0x0;
  }
  else {
    stream_data.pos = 0;
    stream_data.data = buffer;
    stream_data.len = buflen;
    iVar1 = lex_init(&lex,buffer_get,flags,&stream_data);
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

