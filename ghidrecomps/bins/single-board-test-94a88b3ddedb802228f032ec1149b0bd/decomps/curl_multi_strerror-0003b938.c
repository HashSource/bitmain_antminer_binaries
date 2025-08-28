
char * curl_multi_strerror(int param_1)

{
  char *pcVar1;
  
  if (param_1 + 1U < 9) {
    pcVar1 = *(char **)(CSWTCH_7 + (param_1 + 1U) * 4);
  }
  else {
    pcVar1 = "Unknown error";
  }
  return pcVar1;
}

