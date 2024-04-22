
undefined4
Curl_urldecode(undefined4 param_1,byte *param_2,int param_3,int *param_4,int *param_5,byte param_6)

{
  byte *pbVar1;
  byte *pbVar2;
  size_t sVar3;
  int iVar4;
  undefined4 uVar5;
  ushort **ppuVar6;
  undefined uVar7;
  uint uVar8;
  byte bVar9;
  int iVar10;
  uint uVar11;
  byte local_28;
  byte local_27;
  undefined local_26;
  char *pcStack_24;
  
  iVar10 = param_3 + 1;
  if (param_3 == 0) {
    sVar3 = strlen((char *)param_2);
    iVar10 = sVar3 + 1;
  }
  iVar4 = (**DAT_00048474)(iVar10);
  uVar5 = 0x1b;
  if (iVar4 != 0) {
    uVar11 = iVar10 - 1;
    if (uVar11 == 0) {
      iVar10 = 0;
    }
    else {
      iVar10 = 0;
      do {
        uVar8 = (uint)*param_2;
        if (uVar11 < 3 || uVar8 != 0x25) {
          if (uVar8 < 0x20) {
            bVar9 = param_6 & 1;
          }
          else {
            bVar9 = 0;
          }
joined_r0x0004845a:
          uVar7 = (undefined)uVar8;
          if (bVar9 != 0) {
            (**DAT_00048478)(iVar4);
            return 3;
          }
        }
        else {
          ppuVar6 = __ctype_b_loc();
          pbVar2 = param_2 + 1;
          uVar7 = 0x25;
          if (((int)((uint)(*ppuVar6)[*pbVar2] << 0x13) < 0) &&
             (pbVar1 = param_2 + 2, (int)((uint)(*ppuVar6)[*pbVar1] << 0x13) < 0)) {
            param_2 = param_2 + 2;
            local_26 = 0;
            uVar11 = uVar11 - 2;
            local_28 = *pbVar2;
            local_27 = *pbVar1;
            strtoul((char *)&local_28,&pcStack_24,0x10);
            uVar8 = curlx_ultouc();
            if (uVar8 < 0x20) {
              bVar9 = param_6 & 1;
            }
            else {
              bVar9 = 0;
            }
            goto joined_r0x0004845a;
          }
        }
        uVar11 = uVar11 - 1;
        *(undefined *)(iVar4 + iVar10) = uVar7;
        param_2 = param_2 + 1;
        iVar10 = iVar10 + 1;
      } while (uVar11 != 0);
    }
    *(undefined *)(iVar4 + iVar10) = 0;
    if (param_5 != (int *)0x0) {
      *param_5 = iVar10;
    }
    *param_4 = iVar4;
    uVar5 = 0;
  }
  return uVar5;
}

