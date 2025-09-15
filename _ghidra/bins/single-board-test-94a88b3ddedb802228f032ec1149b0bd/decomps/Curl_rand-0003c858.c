
uint Curl_rand(undefined4 param_1)

{
  int iVar1;
  uint local_1c;
  int local_18;
  int local_14;
  
  local_1c = 0;
  iVar1 = Curl_ossl_random(param_1,&local_1c,4);
  if (iVar1 != 0) {
    if (seeded_23150 == '\0') {
      curlx_tvnow(&local_18);
      Curl_infof(param_1,"WARNING: Using weak random seed\n");
      seeded_23150 = '\x01';
      randseed_23149 =
           (((local_14 + local_18 + randseed_23149) * 0x41c64e6d + 0x3039) * 0x41c64e6d + 0x3039) *
           0x41c64e6d + 0x3039;
    }
    randseed_23149 = randseed_23149 * 0x41c64e6d + 0x3039;
    local_1c = randseed_23149 >> 0x10 | randseed_23149 * 0x10000;
  }
  return local_1c;
}

