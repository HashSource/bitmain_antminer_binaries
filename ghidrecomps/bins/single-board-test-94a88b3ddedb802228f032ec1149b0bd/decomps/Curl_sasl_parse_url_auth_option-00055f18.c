
undefined4 Curl_sasl_parse_url_auth_option(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int local_1c [2];
  
  if (param_3 != 0) {
    if (*(char *)(param_1 + 0x14) != '\0') {
      *(undefined *)(param_1 + 0x14) = 0;
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    iVar1 = curl_strnequal(param_2,DAT_00055f70,param_3);
    if (iVar1 != 0) {
      *(undefined4 *)(param_1 + 0xc) = 0xffffffdf;
      return 0;
    }
    uVar2 = Curl_sasl_decode_mech(param_2,param_3,local_1c);
    if ((uVar2 != 0) && (local_1c[0] == param_3)) {
      *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | uVar2;
      return 0;
    }
  }
  return 3;
}

