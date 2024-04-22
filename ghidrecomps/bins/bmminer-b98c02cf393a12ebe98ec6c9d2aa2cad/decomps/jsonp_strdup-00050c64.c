
void jsonp_strdup(char *param_1)

{
  size_t sVar1;
  
  sVar1 = strlen(param_1);
  jsonp_strndup(param_1,sVar1);
  return;
}

