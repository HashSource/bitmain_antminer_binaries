
undefined4
Curl_getaddrinfo(undefined4 *param_1,char *param_2,undefined1 *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_c8;
  undefined1 auStack_c4 [12];
  undefined4 local_b8;
  int local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined1 auStack_98 [128];
  
  iVar1 = param_1[0x88];
  iVar3 = 0;
  uVar4 = *param_1;
  *param_4 = 0;
  if (((1 < iVar1 - 1U) || (iVar3 = *(int *)(&CSWTCH_5 + (iVar1 - 1U) * 4), iVar3 != 2)) &&
     (iVar1 = Curl_ipv6works(), iVar1 == 0)) {
    iVar3 = 2;
  }
  local_b0 = param_1[0x23];
  local_b8 = 0;
  local_ac = 0;
  local_a8 = 0;
  local_a4 = 0;
  local_a0 = 0;
  local_9c = 0;
  local_b4 = iVar3;
  iVar1 = inet_pton(2,param_2,auStack_98);
  if ((iVar1 == 1) || (iVar1 = inet_pton(10,param_2,auStack_98), iVar1 == 1)) {
    local_b8 = 4;
  }
  puVar2 = param_3;
  if (param_3 != (undefined1 *)0x0) {
    curl_msnprintf(auStack_c4,0xc,"%d",param_3);
    puVar2 = auStack_c4;
  }
  iVar1 = Curl_getaddrinfo_ex(param_2,puVar2,&local_b8,&local_c8);
  if (iVar1 != 0) {
    Curl_infof(uVar4,"getaddrinfo(3) failed for %s:%d\n",param_2,param_3);
    local_c8 = 0;
  }
  return local_c8;
}

