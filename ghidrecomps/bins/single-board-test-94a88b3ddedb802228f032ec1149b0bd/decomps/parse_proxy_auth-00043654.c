
undefined4 parse_proxy_auth(int param_1,int param_2)

{
  int iVar1;
  char local_210 [255];
  undefined1 local_111;
  char local_110 [255];
  undefined1 local_11;
  
  local_210[0] = '\0';
  local_210[1] = '\0';
  local_210[2] = '\0';
  local_210[3] = '\0';
  memset(local_210 + 4,0,0xfc);
  local_110[0] = '\0';
  local_110[1] = '\0';
  local_110[2] = '\0';
  local_110[3] = '\0';
  memset(local_110 + 4,0,0xfc);
  if (*(char **)(param_1 + 0x3c0) != (char *)0x0) {
    strncpy(local_210,*(char **)(param_1 + 0x3c0),0x100);
    local_111 = 0;
  }
  if (*(char **)(param_1 + 0x3c4) != (char *)0x0) {
    strncpy(local_110,*(char **)(param_1 + 0x3c4),0x100);
    local_11 = 0;
  }
  iVar1 = curl_easy_unescape(param_1,local_210,0,0);
  *(int *)(param_2 + 0x130) = iVar1;
  if (iVar1 != 0) {
    iVar1 = curl_easy_unescape(param_1,local_110,0,0);
    *(int *)(param_2 + 0x134) = iVar1;
    if (iVar1 != 0) {
      return 0;
    }
  }
  return 0x1b;
}

