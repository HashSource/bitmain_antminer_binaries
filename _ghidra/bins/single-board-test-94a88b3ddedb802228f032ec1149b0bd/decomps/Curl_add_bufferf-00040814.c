
undefined4
Curl_add_bufferf(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char *__s;
  size_t sVar1;
  undefined4 uVar2;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_8 = param_3;
  uStack_4 = param_4;
  __s = (char *)curl_mvaprintf(param_2,&uStack_8);
  if (__s == (char *)0x0) {
    uVar2 = 0x1b;
    (*Curl_cfree)(*param_1);
    (*Curl_cfree)(param_1);
  }
  else {
    sVar1 = strlen(__s);
    uVar2 = Curl_add_buffer(param_1,__s,sVar1);
    (*Curl_cfree)(__s);
  }
  return uVar2;
}

