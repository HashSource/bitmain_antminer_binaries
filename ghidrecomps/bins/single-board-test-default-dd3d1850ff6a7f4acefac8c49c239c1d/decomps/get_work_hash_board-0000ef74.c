
uint get_work_hash_board(int param_1,int param_2,FILE *param_3,uint param_4)

{
  uint32_t uVar1;
  char *pcVar2;
  char acStack_424 [1024];
  uint *local_24;
  undefined4 local_20;
  int local_1c;
  uint local_18;
  char *local_14;
  
  memset(acStack_424,0,0x400);
  local_18 = 0;
  local_20 = 0;
  local_1c = 0;
  while( true ) {
    pcVar2 = fgets(acStack_424,0x3ff,param_3);
    if (pcVar2 == (char *)0x0) {
      return local_18;
    }
    if (param_4 <= local_18) {
      return local_18;
    }
    local_24 = (uint *)(*(int *)(cgpu + (param_1 + 0x402a) * 4 + 4) +
                       (param_4 * param_2 + local_18) * 0x74);
    local_14 = strstr(acStack_424,"nonce");
    if (local_14 == (char *)0x0) break;
    for (local_14 = local_14 + 5; *local_14 == ' '; local_14 = local_14 + 1) {
    }
    s2hex(local_24 + 1,local_14,8);
    uVar1 = htonl(local_24[1]);
    local_24[1] = uVar1;
    local_14 = strstr(acStack_424,"midstate");
    if (local_14 == (char *)0x0) {
      local_14 = (char *)0x0;
      goto LAB_0000f176;
    }
    for (local_14 = local_14 + 8; *local_14 == ' '; local_14 = local_14 + 1) {
    }
    s2hex(local_24 + 5,local_14,0x40);
    local_14 = strstr(acStack_424,"data");
    if (local_14 == (char *)0x0) goto LAB_0000f176;
    for (local_14 = local_14 + 4; *local_14 == ' '; local_14 = local_14 + 1) {
    }
    s2hex(local_24 + 2,local_14,0x18);
    for (local_1c = 0; local_1c < 0x10; local_1c = local_1c + 1) {
      local_24[local_1c + 0xd] = 0;
    }
    *local_24 = local_18;
    local_18 = local_18 + 1;
  }
  local_14 = (char *)0x0;
LAB_0000f176:
  free(local_24);
  puts("get work err");
  return local_18;
}

