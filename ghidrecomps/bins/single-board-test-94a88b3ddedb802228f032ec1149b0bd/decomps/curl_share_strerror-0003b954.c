
char * curl_share_strerror(uint param_1)

{
  char *pcVar1;
  
  if (param_1 < 6) {
    pcVar1 = *(char **)(CSWTCH_10 + param_1 * 4);
  }
  else {
    pcVar1 = "CURLSHcode unknown";
  }
  return pcVar1;
}

