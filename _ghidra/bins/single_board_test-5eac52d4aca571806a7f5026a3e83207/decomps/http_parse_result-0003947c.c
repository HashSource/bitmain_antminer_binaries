
char * http_parse_result(char *lpbuf,_Bool ver1_0,_Bool raw)

{
  char *__src;
  char *pcVar1;
  _Bool raw_local;
  _Bool ver1_0_local;
  char *lpbuf_local;
  char *p_end;
  char *p_start;
  char *response;
  
  response = (char *)0x0;
  __src = strchr(lpbuf,0x7b);
  pcVar1 = strrchr(lpbuf,0x7d);
  if ((__src == (char *)0x0) || (pcVar1 == (char *)0x0)) {
    puts("resp not find {...}");
  }
  else {
    response = (char *)malloc((size_t)(pcVar1 + (2 - (int)__src)));
    memset(response,0,(size_t)(pcVar1 + (2 - (int)__src)));
    strncpy(response,__src,(size_t)(pcVar1 + (1 - (int)__src)));
  }
  return response;
}

