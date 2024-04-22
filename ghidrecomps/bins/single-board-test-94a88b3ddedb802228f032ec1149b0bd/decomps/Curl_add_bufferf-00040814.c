
undefined4
Curl_add_bufferf(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code **ppcVar1;
  char *__s;
  size_t sVar2;
  undefined4 uVar3;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_8 = param_3;
  uStack_4 = param_4;
  __s = (char *)curl_mvaprintf(param_2,&uStack_8);
  ppcVar1 = DAT_00040864;
  if (__s == (char *)0x0) {
    uVar3 = 0x1b;
    (**DAT_00040864)(*param_1);
    (**ppcVar1)(param_1);
  }
  else {
    sVar2 = strlen(__s);
    uVar3 = Curl_add_buffer(param_1,__s,sVar2);
    (**DAT_00040864)(__s);
  }
  return uVar3;
}

