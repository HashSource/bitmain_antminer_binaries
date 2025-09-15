
char * curl_easy_strerror(uint param_1)

{
  char *pcVar1;
  
  if (param_1 < 0x5c) {
    pcVar1 = (&CSWTCH_4)[param_1];
  }
  else {
    pcVar1 = "Unknown error";
  }
  return pcVar1;
}

