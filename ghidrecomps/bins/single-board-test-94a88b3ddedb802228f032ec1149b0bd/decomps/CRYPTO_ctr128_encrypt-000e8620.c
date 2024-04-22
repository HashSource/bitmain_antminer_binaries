
void CRYPTO_ctr128_encrypt
               (byte *param_1,byte *param_2,uint param_3,undefined4 param_4,char *param_5,
               int param_6,uint *param_7,code *param_8)

{
  char cVar1;
  uint uVar2;
  byte *pbVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  byte *pbVar9;
  byte *pbVar10;
  byte *pbVar11;
  
  uVar8 = *param_7;
  pbVar5 = param_2;
  pbVar3 = param_1;
  if (uVar8 != 0 && param_3 != 0) {
    do {
      pbVar9 = (byte *)(param_6 + uVar8);
      pbVar3 = param_1 + 1;
      uVar2 = uVar8 + 1 & 0xf;
      if (uVar2 != 0) {
        uVar2 = 1;
      }
      param_3 = param_3 - 1;
      uVar8 = uVar8 + 1 & 0xf;
      if (param_3 == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = uVar2 & 1;
      }
      pbVar5 = param_2 + 1;
      *param_2 = *param_1 ^ *pbVar9;
      param_1 = pbVar3;
      param_2 = pbVar5;
    } while (uVar2 != 0);
  }
  if ((((uint)pbVar5 | (uint)pbVar3 | (uint)param_5) & 3) != 0) {
    if (param_3 != 0) {
      uVar2 = 0;
      do {
        if (uVar8 == 0) {
          (*param_8)(param_5,param_6,param_4);
          cVar1 = param_5[0xf];
          param_5[0xf] = cVar1 + '\x01';
          if (((((((char)(cVar1 + '\x01') == '\0') &&
                 (cVar1 = param_5[0xe], param_5[0xe] = cVar1 + '\x01',
                 (char)(cVar1 + '\x01') == '\0')) &&
                (cVar1 = param_5[0xd], param_5[0xd] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0'
                )) && ((cVar1 = param_5[0xc], param_5[0xc] = cVar1 + '\x01',
                       (char)(cVar1 + '\x01') == '\0' &&
                       (cVar1 = param_5[0xb], param_5[0xb] = cVar1 + '\x01',
                       (char)(cVar1 + '\x01') == '\0')))) &&
              ((cVar1 = param_5[10], param_5[10] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0' &&
               ((cVar1 = param_5[9], param_5[9] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0' &&
                (cVar1 = param_5[8], param_5[8] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0'))))
              )) && ((cVar1 = param_5[7], param_5[7] = cVar1 + '\x01',
                     (char)(cVar1 + '\x01') == '\0' &&
                     ((((cVar1 = param_5[6], param_5[6] = cVar1 + '\x01',
                        (char)(cVar1 + '\x01') == '\0' &&
                        (cVar1 = param_5[5], param_5[5] = cVar1 + '\x01',
                        (char)(cVar1 + '\x01') == '\0')) &&
                       (cVar1 = param_5[4], param_5[4] = cVar1 + '\x01',
                       (char)(cVar1 + '\x01') == '\0')) &&
                      (((cVar1 = param_5[3], param_5[3] = cVar1 + '\x01',
                        (char)(cVar1 + '\x01') == '\0' &&
                        (cVar1 = param_5[2], param_5[2] = cVar1 + '\x01',
                        (char)(cVar1 + '\x01') == '\0')) &&
                       (cVar1 = param_5[1], param_5[1] = cVar1 + '\x01',
                       (char)(cVar1 + '\x01') == '\0')))))))) {
            *param_5 = *param_5 + '\x01';
          }
        }
        pbVar9 = (byte *)(param_6 + uVar8);
        uVar8 = uVar8 + 1 & 0xf;
        pbVar5[uVar2] = pbVar3[uVar2] ^ *pbVar9;
        uVar2 = uVar2 + 1;
      } while (uVar2 != param_3);
    }
    *param_7 = uVar8;
    return;
  }
  pbVar9 = pbVar3;
  pbVar10 = pbVar5;
  uVar2 = param_3;
  if (0xf < param_3) {
    do {
      (*param_8)(param_5,param_6,param_4);
      cVar1 = param_5[0xf];
      param_5[0xf] = cVar1 + '\x01';
      if (((((char)(cVar1 + '\x01') == '\0') &&
           (cVar1 = param_5[0xe], param_5[0xe] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0')) &&
          (((cVar1 = param_5[0xd], param_5[0xd] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0' &&
            (((cVar1 = param_5[0xc], param_5[0xc] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0'
              && (cVar1 = param_5[0xb], param_5[0xb] = cVar1 + '\x01',
                 (char)(cVar1 + '\x01') == '\0')) &&
             (cVar1 = param_5[10], param_5[10] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0'))))
           && ((cVar1 = param_5[9], param_5[9] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0' &&
               (cVar1 = param_5[8], param_5[8] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0')))))
          ) && ((cVar1 = param_5[7], param_5[7] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0' &&
                (((cVar1 = param_5[6], param_5[6] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0'
                  && (cVar1 = param_5[5], param_5[5] = cVar1 + '\x01',
                     (char)(cVar1 + '\x01') == '\0')) &&
                 ((cVar1 = param_5[4], param_5[4] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0'
                  && (((cVar1 = param_5[3], param_5[3] = cVar1 + '\x01',
                       (char)(cVar1 + '\x01') == '\0' &&
                       (cVar1 = param_5[2], param_5[2] = cVar1 + '\x01',
                       (char)(cVar1 + '\x01') == '\0')) &&
                      (cVar1 = param_5[1], param_5[1] = cVar1 + '\x01',
                      (char)(cVar1 + '\x01') == '\0')))))))))) {
        *param_5 = *param_5 + '\x01';
      }
      for (; uVar8 < 0x10; uVar8 = uVar8 + 4) {
        *(uint *)(pbVar10 + uVar8) = *(uint *)(pbVar9 + uVar8) ^ *(uint *)(param_6 + uVar8);
      }
      uVar2 = uVar2 - 0x10;
      uVar8 = 0;
      pbVar9 = pbVar9 + 0x10;
      pbVar10 = pbVar10 + 0x10;
    } while (0xf < uVar2);
    uVar8 = param_3 - 0x10;
    param_3 = param_3 & 0xf;
    iVar6 = (uVar8 & 0xfffffff0) + 0x10;
    pbVar5 = pbVar5 + iVar6;
    pbVar3 = pbVar3 + iVar6;
    uVar8 = 0;
  }
  if (param_3 == 0) goto LAB_000e87a0;
  (*param_8)(param_5,param_6,param_4);
  cVar1 = param_5[0xf];
  param_5[0xf] = cVar1 + '\x01';
  if (((((char)(cVar1 + '\x01') == '\0') &&
       (cVar1 = param_5[0xe], param_5[0xe] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0')) &&
      ((cVar1 = param_5[0xd], param_5[0xd] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0' &&
       ((cVar1 = param_5[0xc], param_5[0xc] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0' &&
        (cVar1 = param_5[0xb], param_5[0xb] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0'))))))
     && ((cVar1 = param_5[10], param_5[10] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0' &&
         ((((((cVar1 = param_5[9], param_5[9] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0' &&
              (cVar1 = param_5[8], param_5[8] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0')) &&
             (cVar1 = param_5[7], param_5[7] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0')) &&
            ((cVar1 = param_5[6], param_5[6] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0' &&
             (cVar1 = param_5[5], param_5[5] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0')))) &&
           ((cVar1 = param_5[4], param_5[4] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0' &&
            ((cVar1 = param_5[3], param_5[3] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0' &&
             (cVar1 = param_5[2], param_5[2] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0'))))))
          && (cVar1 = param_5[1], param_5[1] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0'))))))
  {
    *param_5 = *param_5 + '\x01';
  }
  pbVar9 = pbVar5 + uVar8;
  pbVar10 = pbVar3 + uVar8;
  pbVar11 = (byte *)(param_6 + uVar8);
  iVar6 = param_3 - 1;
  uVar4 = param_3 & 0xfffffffc;
  uVar2 = uVar8;
  if (param_3 >> 2 == 0 ||
      ((((uint)pbVar11 | (uint)pbVar10 | (uint)pbVar9) & 3) != 0 ||
      (param_3 < 4 ||
      (pbVar9 < pbVar10 + 4 && pbVar10 < pbVar9 + 4 || pbVar9 < pbVar11 + 4 && pbVar11 < pbVar9 + 4)
      ))) {
LAB_000e8924:
    iVar6 = uVar2 + iVar6;
    do {
      pbVar5[uVar2] = pbVar3[uVar2] ^ *(byte *)(param_6 + uVar2);
      uVar2 = uVar2 + 1;
    } while (uVar2 != iVar6 + 1U);
  }
  else {
    uVar2 = 0;
    iVar7 = 0;
    do {
      uVar2 = uVar2 + 1;
      *(uint *)(pbVar9 + iVar7) = *(uint *)(pbVar11 + iVar7) ^ *(uint *)(pbVar10 + iVar7);
      iVar7 = iVar7 + 4;
    } while (uVar2 < param_3 >> 2);
    iVar6 = iVar6 - uVar4;
    uVar2 = uVar4 + uVar8;
    if (param_3 != uVar4) goto LAB_000e8924;
  }
  uVar8 = uVar8 + param_3;
LAB_000e87a0:
  *param_7 = uVar8;
  return;
}

