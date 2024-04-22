
int Curl_input_ntlm(undefined4 *param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  ushort **ppuVar2;
  uint uVar3;
  byte *pbVar4;
  int *piVar5;
  
  piVar5 = param_1 + 0xa3;
  if (param_2 == 0) {
    piVar5 = param_1 + 0x9d;
  }
  iVar1 = Curl_raw_nequal(DAT_0005458c,param_3,4,param_4,param_4);
  if (iVar1 == 0) {
    return 0;
  }
  uVar3 = (uint)*(byte *)(param_3 + 4);
  pbVar4 = (byte *)(param_3 + 4);
  if (uVar3 != 0) {
    ppuVar2 = __ctype_b_loc();
    do {
      if (-1 < (int)((uint)(*ppuVar2)[uVar3] << 0x12)) {
        iVar1 = Curl_sasl_decode_ntlm_type2_message(*param_1,pbVar4,piVar5);
        if (iVar1 == 0) {
          *piVar5 = 2;
          return 0;
        }
        return iVar1;
      }
      pbVar4 = pbVar4 + 1;
      uVar3 = (uint)*pbVar4;
    } while (uVar3 != 0);
  }
  iVar1 = *piVar5;
  if (iVar1 == 4) {
    Curl_infof(*param_1,DAT_00054598);
    Curl_http_ntlm_cleanup(param_1);
  }
  else {
    if (iVar1 == 3) {
      Curl_infof(*param_1,DAT_00054594);
      Curl_http_ntlm_cleanup(param_1);
      *piVar5 = 0;
      return 9;
    }
    if (iVar1 != 0) {
      Curl_infof(*param_1,DAT_00054590);
      return 9;
    }
  }
  *piVar5 = 1;
  return 0;
}

