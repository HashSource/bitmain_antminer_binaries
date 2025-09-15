
char * get_gost_engine_param(int param_1)

{
  char *str;
  
  if (param_1 != 0) {
    return (char *)0x0;
  }
  if (gost_params == (char *)0x0) {
    str = getenv("CRYPT_PARAMS");
    if (str == (char *)0x0) {
      return (char *)0x0;
    }
    gost_params = BUF_strdup(str);
  }
  return gost_params;
}

