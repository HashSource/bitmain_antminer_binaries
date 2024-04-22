
uint get_work(int param_1,int param_2,FILE *param_3,uint param_4)

{
  char *pcVar1;
  char acStack_420 [1024];
  uint *local_20;
  int local_1c;
  uint local_18;
  char *local_14;
  
  memset(acStack_420,0,0x400);
  local_18 = 0;
  local_1c = 0;
  while( true ) {
    pcVar1 = fgets(acStack_420,0x3ff,param_3);
    if (pcVar1 == (char *)0x0) {
      return local_18;
    }
    if (param_4 <= local_18) {
      return local_18;
    }
    local_20 = (uint *)(*(int *)(cgpu + (param_1 + 0x20028) * 4) +
                       (param_4 * param_2 + local_18) * 0xcc);
    local_14 = strstr(acStack_420,"nonce");
    if (local_14 == (char *)0x0) break;
    for (local_14 = local_14 + 5; *local_14 == ' '; local_14 = local_14 + 1) {
    }
    s2hex(local_20 + 1,local_14,8);
    local_14 = strstr(acStack_420,"work");
    if (local_14 == (char *)0x0) goto LAB_000126f6;
    for (local_14 = local_14 + 4; *local_14 == ' '; local_14 = local_14 + 1) {
    }
    s2hex(local_20 + 2,local_14,0x168);
    for (local_1c = 0; local_1c < 4; local_1c = local_1c + 1) {
      local_20[local_1c + 0x2f] = 0;
    }
    *local_20 = local_18;
    local_18 = local_18 + 1;
  }
  local_14 = (char *)0x0;
LAB_000126f6:
  free(local_20);
  puts("get work err");
  return local_18;
}

