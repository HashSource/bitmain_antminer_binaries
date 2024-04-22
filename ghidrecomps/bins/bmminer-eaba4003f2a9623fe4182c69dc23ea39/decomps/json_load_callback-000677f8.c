
json_t * json_load_callback(json_load_callback_t callback,void *arg,size_t flags,json_error_t *error
                           )

{
  int iVar1;
  json_t *pjVar2;
  json_error_t *error_local;
  size_t flags_local;
  void *arg_local;
  json_load_callback_t callback_local;
  callback_data_t stream_data;
  lex_t lex;
  json_t *result;
  
  memset(&stream_data,0,0x410);
  stream_data.callback = callback;
  stream_data.arg = arg;
  jsonp_error_init(error,"<callback>");
  if (callback == (json_load_callback_t)0x0) {
    error_set(error,(lex_t *)0x0,"wrong arguments");
    pjVar2 = (json_t *)0x0;
  }
  else {
    iVar1 = lex_init(&lex,callback_get + 1,flags,&stream_data);
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

