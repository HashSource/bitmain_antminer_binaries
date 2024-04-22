
void CRYPTO_ctr128_encrypt_ctr32
               (byte *param_1,byte *param_2,uint param_3,undefined4 param_4,char *param_5,
               void *param_6,uint *param_7,code *param_8)

{
  char cVar1;
  uint uVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  uint uVar8;
  byte *pbVar9;
  uint uVar10;
  uint uVar11;
  byte *pbVar12;
  
  uVar10 = *param_7;
  pbVar3 = param_1;
  pbVar4 = param_2;
  if (uVar10 != 0 && param_3 != 0) {
    do {
      pbVar7 = (byte *)((int)param_6 + uVar10);
      pbVar3 = param_1 + 1;
      uVar2 = uVar10 + 1 & 0xf;
      if (uVar2 != 0) {
        uVar2 = 1;
      }
      param_3 = param_3 - 1;
      uVar10 = uVar10 + 1 & 0xf;
      if (param_3 == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = uVar2 & 1;
      }
      pbVar4 = param_2 + 1;
      *param_2 = *param_1 ^ *pbVar7;
      param_1 = pbVar3;
      param_2 = pbVar4;
    } while (uVar2 != 0);
  }
  uVar2 = (uint)(byte)param_5[0xd] << 0x10 | (uint)(byte)param_5[0xc] << 0x18 |
          (uint)(byte)param_5[0xf] | (uint)(byte)param_5[0xe] << 8;
  for (; 0xf < param_3; param_3 = param_3 + uVar8 * -0x10) {
    uVar8 = param_3 >> 4;
    uVar11 = uVar8 + uVar2;
    if (CARRY4(uVar8,uVar2) == false) {
      (*param_8)(pbVar3,pbVar4,uVar8,param_4,param_5);
      param_5[0xf] = (char)uVar11;
      param_5[0xc] = (char)(uVar11 >> 0x18);
      param_5[0xd] = (char)(uVar11 >> 0x10);
      param_5[0xe] = (char)(uVar11 >> 8);
    }
    else {
      uVar8 = -uVar2;
      (*param_8)(pbVar3,pbVar4,uVar8,param_4,param_5);
      cVar1 = param_5[0xb];
      param_5[0xc] = '\0';
      param_5[0xd] = '\0';
      param_5[0xe] = '\0';
      param_5[0xf] = '\0';
      param_5[0xb] = cVar1 + '\x01';
      if ((char)(cVar1 + '\x01') == '\0') {
        cVar1 = param_5[10];
        param_5[10] = cVar1 + '\x01';
        if ((char)(cVar1 + '\x01') == '\0') {
          cVar1 = param_5[9];
          param_5[9] = cVar1 + '\x01';
          if ((char)(cVar1 + '\x01') == '\0') {
            cVar1 = param_5[8];
            param_5[8] = cVar1 + '\x01';
            if ((char)(cVar1 + '\x01') != '\0') goto LAB_000e8bb8;
            cVar1 = param_5[7];
            param_5[7] = cVar1 + '\x01';
            if ((char)(cVar1 + '\x01') == '\0') {
              cVar1 = param_5[6];
              param_5[6] = cVar1 + '\x01';
              if ((char)(cVar1 + '\x01') != '\0') goto LAB_000e8bb8;
              cVar1 = param_5[5];
              param_5[5] = cVar1 + '\x01';
              if ((char)(cVar1 + '\x01') == '\0') {
                cVar1 = param_5[4];
                param_5[4] = cVar1 + '\x01';
                if ((char)(cVar1 + '\x01') != '\0') goto LAB_000e8bb8;
                cVar1 = param_5[3];
                param_5[3] = cVar1 + '\x01';
                if (((char)(cVar1 + '\x01') != '\0') ||
                   (cVar1 = param_5[2], param_5[2] = cVar1 + '\x01', (char)(cVar1 + '\x01') != '\0')
                   ) goto LAB_000e8bc0;
                cVar1 = param_5[1];
                param_5[1] = cVar1 + '\x01';
                if ((char)(cVar1 + '\x01') == '\0') {
                  *param_5 = *param_5 + '\x01';
                  uVar11 = 0;
                  goto LAB_000e8b64;
                }
              }
            }
          }
          uVar11 = 0;
        }
        else {
LAB_000e8bb8:
          uVar11 = 0;
        }
      }
      else {
LAB_000e8bc0:
        uVar11 = 0;
      }
    }
LAB_000e8b64:
    pbVar4 = pbVar4 + uVar8 * 0x10;
    pbVar3 = pbVar3 + uVar8 * 0x10;
    uVar2 = uVar11;
  }
  if (param_3 == 0) goto LAB_000e8bac;
  memset(param_6,0,0x10);
  (*param_8)(param_6,param_6,1,param_4,param_5);
  iVar5 = uVar2 + 1;
  param_5[0xf] = (char)iVar5;
  param_5[0xc] = (char)((uint)iVar5 >> 0x18);
  param_5[0xd] = (char)((uint)iVar5 >> 0x10);
  param_5[0xe] = (char)((uint)iVar5 >> 8);
  if (((((iVar5 == 0) &&
        (cVar1 = param_5[0xb], param_5[0xb] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0')) &&
       (cVar1 = param_5[10], param_5[10] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0')) &&
      ((((cVar1 = param_5[9], param_5[9] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0' &&
         (cVar1 = param_5[8], param_5[8] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0')) &&
        ((cVar1 = param_5[7], param_5[7] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0' &&
         ((cVar1 = param_5[6], param_5[6] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0' &&
          (cVar1 = param_5[5], param_5[5] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0')))))) &&
       (cVar1 = param_5[4], param_5[4] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0')))) &&
     (((cVar1 = param_5[3], param_5[3] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0' &&
       (cVar1 = param_5[2], param_5[2] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0')) &&
      (cVar1 = param_5[1], param_5[1] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0')))) {
    *param_5 = *param_5 + '\x01';
  }
  pbVar7 = pbVar4 + uVar10;
  pbVar9 = pbVar3 + uVar10;
  pbVar12 = (byte *)((int)param_6 + uVar10);
  uVar8 = param_3 & 0xfffffffc;
  iVar5 = param_3 - 1;
  uVar2 = uVar10;
  if (param_3 >> 2 == 0 ||
      ((((uint)pbVar9 | (uint)pbVar7 | (uint)pbVar12) & 3) != 0 ||
      (param_3 < 4 ||
      (pbVar7 < pbVar12 + 4 && pbVar12 < pbVar7 + 4 || pbVar7 < pbVar9 + 4 && pbVar9 < pbVar7 + 4)))
     ) {
LAB_000e8cfe:
    iVar5 = uVar2 + iVar5;
    do {
      pbVar4[uVar2] = pbVar3[uVar2] ^ *(byte *)((int)param_6 + uVar2);
      uVar2 = uVar2 + 1;
    } while (uVar2 != iVar5 + 1U);
  }
  else {
    uVar2 = 0;
    iVar6 = 0;
    do {
      uVar2 = uVar2 + 1;
      *(uint *)(pbVar7 + iVar6) = *(uint *)(pbVar12 + iVar6) ^ *(uint *)(pbVar9 + iVar6);
      iVar6 = iVar6 + 4;
    } while (uVar2 < param_3 >> 2);
    iVar5 = iVar5 - uVar8;
    uVar2 = uVar8 + uVar10;
    if (param_3 != uVar8) goto LAB_000e8cfe;
  }
  uVar10 = uVar10 + param_3;
LAB_000e8bac:
  *param_7 = uVar10;
  return;
}

