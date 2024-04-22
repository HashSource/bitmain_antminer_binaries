
undefined4 parse_proxy_auth(int param_1,int param_2)

{
  int iVar1;
  undefined4 local_210;
  undefined auStack_20c [251];
  undefined local_111;
  undefined4 local_110;
  undefined auStack_10c [251];
  undefined local_11;
  
  local_210 = 0;
  memset(auStack_20c,0,0xfc);
  local_110 = 0;
  memset(auStack_10c,0,0xfc);
  if (*(char **)(param_1 + 0x3c0) != (char *)0x0) {
    strncpy((char *)&local_210,*(char **)(param_1 + 0x3c0),0x100);
    local_111 = 0;
  }
  if (*(char **)(param_1 + 0x3c4) != (char *)0x0) {
    strncpy((char *)&local_110,*(char **)(param_1 + 0x3c4),0x100);
    local_11 = 0;
  }
  iVar1 = curl_easy_unescape(param_1,&local_210,0,0);
  *(int *)(param_2 + 0x130) = iVar1;
  if (iVar1 != 0) {
    iVar1 = curl_easy_unescape(param_1,&local_110,0,0);
    *(int *)(param_2 + 0x134) = iVar1;
    if (iVar1 != 0) {
      return 0;
    }
  }
  return 0x1b;
}

