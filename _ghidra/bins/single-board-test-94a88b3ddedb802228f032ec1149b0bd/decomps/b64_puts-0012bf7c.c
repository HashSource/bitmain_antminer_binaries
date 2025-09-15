
void b64_puts(undefined4 param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  size_t sVar1;
  
  sVar1 = strlen(param_2);
  b64_write(param_1,param_2,sVar1,param_4);
  return;
}

