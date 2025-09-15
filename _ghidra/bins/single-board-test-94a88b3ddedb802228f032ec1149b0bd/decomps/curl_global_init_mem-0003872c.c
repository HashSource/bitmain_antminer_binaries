
undefined4
curl_global_init_mem(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  undefined4 uVar1;
  
  if (((param_2 == 0 || param_3 == 0) || (param_4 == 0 || param_5 == 0)) ||
     (uVar1 = 0, param_6 == 0)) {
    uVar1 = 2;
  }
  else {
    if (initialized == 0) {
      Curl_cstrdup = param_5;
      Curl_ccalloc = param_6;
      Curl_cmalloc = param_2;
      Curl_cfree = param_3;
      Curl_crealloc = param_4;
      uVar1 = global_init();
      return uVar1;
    }
    initialized = initialized + 1;
  }
  return uVar1;
}

