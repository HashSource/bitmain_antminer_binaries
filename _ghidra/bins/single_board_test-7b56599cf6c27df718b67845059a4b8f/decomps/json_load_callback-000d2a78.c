
/* WARNING: Unknown calling convention */

json_t * json_load_callback(json_load_callback_t callback,void *arg,size_t flags,json_error_t *error
                           )

{
  int iVar1;
  json_t *pjVar2;
  lex_t lex;
  callback_data_t stream_data;
  
  memset(&stream_data,0,0x410);
  stream_data.callback = callback;
  stream_data.arg = arg;
  jsonp_error_init(error,"<callback>");
  if (callback == (json_load_callback_t)0x0) {
    error_set(error,(lex_t *)0x0,json_error_invalid_argument,"wrong arguments");
    pjVar2 = (json_t *)0x0;
  }
  else {
    iVar1 = lex_init(&lex,(get_func)0xd1b59,flags,&stream_data);
    pjVar2 = (json_t *)0x0;
    if (iVar1 == 0) {
      pjVar2 = parse_json(&lex,flags,error);
      lex_close(&lex);
    }
  }
  return pjVar2;
}

