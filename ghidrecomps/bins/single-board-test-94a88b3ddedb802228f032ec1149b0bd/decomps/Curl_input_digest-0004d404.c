
undefined4 Curl_input_digest(int *param_1,int param_2,int param_3)

{
  int iVar1;
  ushort **ppuVar2;
  undefined4 uVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  
  if (param_2 == 0) {
    iVar6 = *param_1 + 0x85d8;
  }
  else {
    iVar6 = *param_1 + 0x85fc;
  }
  iVar1 = Curl_raw_nequal(DAT_0004d450,param_3,6);
  if (iVar1 == 0) {
    return 0x3d;
  }
  uVar4 = (uint)*(byte *)(param_3 + 6);
  pbVar5 = (byte *)(param_3 + 6);
  if (uVar4 != 0) {
    ppuVar2 = __ctype_b_loc();
    do {
      if (-1 < (int)((uint)(*ppuVar2)[uVar4] << 0x12)) break;
      pbVar5 = pbVar5 + 1;
      uVar4 = (uint)*pbVar5;
    } while (uVar4 != 0);
  }
  uVar3 = Curl_sasl_decode_digest_http_message(pbVar5,iVar6);
  return uVar3;
}

