
int Curl_protocol_connect(int param_1,undefined *param_2)

{
  int iVar1;
  code *pcVar2;
  
  *param_2 = 0;
  if (*(char *)(param_1 + 0x1f6) == '\0') {
    if (*(char *)(param_1 + 0x1f8) != '\0') {
      return 0;
    }
  }
  else if (*(char *)(param_1 + 0x1f8) != '\0') {
    if (*(int *)(*(int *)(param_1 + 0x218) + 0x18) != 0) {
      return 0;
    }
    *param_2 = 1;
    return 0;
  }
  iVar1 = Curl_proxy_connect(param_1);
  if (iVar1 == 0) {
    if (((*(char *)(param_1 + 0x1fa) != '\0') && (*(char *)(param_1 + 0x1f0) != '\0')) &&
       (*(int *)(param_1 + 0x468) != 2)) {
      return 0;
    }
    pcVar2 = *(code **)(*(int *)(param_1 + 0x218) + 0x14);
    if (pcVar2 == (code *)0x0) {
      *param_2 = 1;
    }
    else {
      iVar1 = (*pcVar2)(param_1,param_2);
      if (iVar1 != 0) {
        return iVar1;
      }
    }
    *(undefined *)(param_1 + 0x1f8) = 1;
    return 0;
  }
  return iVar1;
}

