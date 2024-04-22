
void json_string(char *param_1)

{
  size_t sVar1;
  
  if (param_1 != (char *)0x0) {
    sVar1 = strlen(param_1);
    json_stringn(param_1,sVar1);
    return;
  }
  return;
}

