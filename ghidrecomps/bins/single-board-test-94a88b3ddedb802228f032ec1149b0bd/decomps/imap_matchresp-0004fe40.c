
bool imap_matchresp(int param_1,int param_2,char *param_3)

{
  byte *pbVar1;
  size_t sVar2;
  ushort **ppuVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  
  pbVar5 = (byte *)(param_1 + param_2);
  pbVar6 = (byte *)(param_1 + 2);
  sVar2 = strlen(param_3);
  if (pbVar6 < pbVar5) {
    ppuVar3 = __ctype_b_loc();
    if ((int)((uint)(*ppuVar3)[*(byte *)(param_1 + 2)] << 0x14) < 0) {
      pbVar1 = (byte *)(param_1 + 3);
      do {
        pbVar6 = pbVar1;
        if (pbVar6 == pbVar5) break;
        pbVar1 = pbVar6 + 1;
      } while ((int)((uint)(*ppuVar3)[*pbVar6] << 0x14) < 0);
      if (pbVar5 == pbVar6) {
        return false;
      }
      if (*pbVar6 != 0x20) {
        return false;
      }
      pbVar6 = pbVar6 + 1;
    }
  }
  if ((pbVar6 + sVar2 <= pbVar5) && (iVar4 = Curl_raw_nequal(pbVar6,param_3,sVar2), iVar4 != 0)) {
    if (pbVar6[sVar2] == 0x20) {
      return true;
    }
    return pbVar5 == pbVar6 + sVar2 + 2;
  }
  return false;
}

