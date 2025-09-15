
int get_work(int param_1,int param_2)

{
  void *pvVar1;
  uint32_t uVar2;
  char *pcVar3;
  char acStack_41c [1024];
  int *local_1c;
  undefined4 local_18;
  int local_14;
  int local_10;
  char *local_c;
  
  memset(acStack_41c,0,0x400);
  local_10 = 0;
  local_18 = 0;
  local_14 = 0;
  pvVar1 = malloc(param_2 * 0x74);
  *(void **)(cgpu + (param_1 + 0x402a) * 4 + 4) = pvVar1;
  if (*(int *)(cgpu + (param_1 + 0x402a) * 4 + 4) == 0) {
    puts("malloc struct work err");
    local_10 = 0;
  }
  else {
    while( true ) {
      pcVar3 = fgets(acStack_41c,0x3ff,*(FILE **)(cgpu + param_1 * 4));
      if (pcVar3 == (char *)0x0) {
        return local_10;
      }
      if (param_2 <= local_10) {
        return local_10;
      }
      local_1c = (int *)(*(int *)(cgpu + (param_1 + 0x402a) * 4 + 4) + local_10 * 0x74);
      local_c = strstr(acStack_41c,"nonce");
      if (local_c == (char *)0x0) break;
      for (local_c = local_c + 5; *local_c == ' '; local_c = local_c + 1) {
      }
      s2hex(local_1c + 1,local_c,8);
      uVar2 = htonl(local_1c[1]);
      local_1c[1] = uVar2;
      local_c = strstr(acStack_41c,"midstate");
      if (local_c == (char *)0x0) {
        local_c = (char *)0x0;
        goto LAB_0000ef50;
      }
      for (local_c = local_c + 8; *local_c == ' '; local_c = local_c + 1) {
      }
      s2hex(local_1c + 5,local_c,0x40);
      local_c = strstr(acStack_41c,"data");
      if (local_c == (char *)0x0) goto LAB_0000ef50;
      for (local_c = local_c + 4; *local_c == ' '; local_c = local_c + 1) {
      }
      s2hex(local_1c + 2,local_c,0x18);
      for (local_14 = 0; local_14 < 0x10; local_14 = local_14 + 1) {
        local_1c[local_14 + 0xd] = 0;
      }
      *local_1c = local_10;
      local_10 = local_10 + 1;
    }
    local_c = (char *)0x0;
LAB_0000ef50:
    free(local_1c);
    puts("get work err");
  }
  return local_10;
}

