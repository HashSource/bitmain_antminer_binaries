
void strcpy_url(byte *param_1,byte *param_2)

{
  bool bVar1;
  byte bVar2;
  byte *pbVar3;
  
  bVar2 = *param_2;
  if (bVar2 != 0) {
    bVar1 = true;
    pbVar3 = param_1;
    do {
      while (bVar2 != 0x20) {
        if (bVar2 == 0x3f) {
          bVar1 = false;
        }
        else if ((int)((uint)bVar2 << 0x18) < 0) {
          param_1 = pbVar3 + 3;
          curl_msnprintf(pbVar3,4,DAT_0004ae4c);
          goto LAB_0004ae06;
        }
        param_1 = pbVar3 + 1;
        *pbVar3 = bVar2;
LAB_0004ae06:
        param_2 = param_2 + 1;
        bVar2 = *param_2;
        pbVar3 = param_1;
        if (bVar2 == 0) goto LAB_0004ae26;
      }
      if (!bVar1) {
        param_1 = pbVar3 + 1;
        *pbVar3 = 0x2b;
        goto LAB_0004ae06;
      }
      *pbVar3 = 0x25;
      pbVar3[1] = 0x32;
      pbVar3[2] = 0x30;
      param_1 = pbVar3 + 3;
      param_2 = param_2 + 1;
      bVar2 = *param_2;
      pbVar3 = param_1;
    } while (bVar2 != 0);
  }
LAB_0004ae26:
  *param_1 = 0;
  return;
}

