
undefined4 global_init(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = initialized;
  initialized = initialized + 1;
  if (iVar1 != 0) {
    return 0;
  }
  if (param_2 != 0) {
    Curl_cmalloc = malloc;
    Curl_cfree = free;
    Curl_crealloc = realloc;
    Curl_cstrdup = strdup;
    Curl_ccalloc = calloc;
  }
  if ((param_1 << 0x1f < 0) && (iVar1 = Curl_ssl_init(), iVar1 == 0)) {
    return 2;
  }
  if (param_1 << 0x1d < 0) {
    Curl_ack_eintr = 1;
  }
  init_flags = param_1;
  Curl_version_init();
  return 0;
}

