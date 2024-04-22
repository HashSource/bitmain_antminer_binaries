
json_t * pack_string(scanner_t *s,va_list *ap)

{
  json_t *pjVar1;
  va_list *ap_local;
  scanner_t *s_local;
  int ours;
  size_t len;
  char *str;
  int nullable;
  
  next_token(s);
  nullable = (int)((s->token).token == '?');
  if (nullable == 0) {
    prev_token(s);
  }
  str = read_string(s,ap,"string",&len,&ours);
  if (str == (char *)0x0) {
    if (nullable == 0) {
      pjVar1 = (json_t *)0x0;
    }
    else {
      pjVar1 = json_null();
    }
  }
  else if (ours == 0) {
    pjVar1 = json_stringn_nocheck(str,len);
  }
  else {
    pjVar1 = jsonp_stringn_nocheck_own(str,len);
  }
  return pjVar1;
}

