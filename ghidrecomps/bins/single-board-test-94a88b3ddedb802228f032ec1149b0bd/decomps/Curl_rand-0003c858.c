
uint Curl_rand(undefined4 param_1)

{
  char *pcVar1;
  int iVar2;
  uint uVar3;
  uint local_1c;
  int local_18;
  int local_14;
  
  local_1c = 0;
  iVar2 = Curl_ossl_random(param_1,&local_1c,4);
  pcVar1 = DAT_0003c8dc;
  if (iVar2 != 0) {
    if (*DAT_0003c8dc == '\0') {
      curlx_tvnow(&local_18);
      Curl_infof(param_1,DAT_0003c8e0);
      *pcVar1 = '\x01';
      iVar2 = (((local_14 + local_18 + *(int *)(pcVar1 + 4)) * 0x41c64e6d + 0x3039) * 0x41c64e6d +
              0x3039) * 0x41c64e6d + 0x3039;
    }
    else {
      iVar2 = *(int *)(DAT_0003c8dc + 4);
    }
    uVar3 = iVar2 * 0x41c64e6d + 0x3039;
    local_1c = uVar3 >> 0x10 | uVar3 * 0x10000;
    *(uint *)(pcVar1 + 4) = uVar3;
  }
  return local_1c;
}

