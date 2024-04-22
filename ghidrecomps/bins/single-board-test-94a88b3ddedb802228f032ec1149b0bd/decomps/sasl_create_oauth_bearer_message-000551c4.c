
undefined4
sasl_create_oauth_bearer_message
          (undefined4 param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
          undefined4 param_6,undefined4 param_7)

{
  char *__s;
  size_t sVar1;
  undefined4 uVar2;
  
  if (param_3 == 0) {
    if (param_4 == 0 || param_4 == 0x50) {
      __s = (char *)curl_maprintf(DAT_00055248,param_2,param_5);
      goto joined_r0x00055228;
    }
  }
  else if (param_4 == 0 || param_4 == 0x50) {
    __s = (char *)curl_maprintf(DAT_0005523c,param_2,param_3,param_5);
    goto joined_r0x00055228;
  }
  __s = (char *)curl_maprintf(DAT_00055244,param_2,param_3,param_4,param_5);
joined_r0x00055228:
  if (__s == (char *)0x0) {
    uVar2 = 0x1b;
  }
  else {
    sVar1 = strlen(__s);
    uVar2 = Curl_base64_encode(param_1,__s,sVar1,param_6,param_7);
    (**DAT_00055240)(__s);
  }
  return uVar2;
}

