
void json_string_nocheck(char *param_1)

{
  size_t sVar1;
  
  if (param_1 != (char *)0x0) {
    sVar1 = strlen(param_1);
    string_create(param_1,sVar1,0);
    return;
  }
  return;
}

