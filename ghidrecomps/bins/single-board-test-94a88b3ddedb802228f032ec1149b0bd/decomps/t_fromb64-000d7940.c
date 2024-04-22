
uint t_fromb64(undefined4 *param_1,char *param_2)

{
  char cVar1;
  byte bVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  size_t sVar5;
  size_t sVar6;
  char *pcVar7;
  uint uVar8;
  char *pcVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  size_t sVar13;
  int iVar14;
  undefined4 *puVar15;
  size_t sVar16;
  size_t sVar17;
  undefined4 *puVar18;
  uint uVar19;
  uint uVar20;
  bool bVar21;
  
  cVar1 = *param_2;
  while ((cVar1 != '\0' && ((cVar1 == ' ' || cVar1 == '\t' || (cVar1 == '\n'))))) {
    pcVar9 = param_2 + 1;
    param_2 = param_2 + 1;
    cVar1 = *pcVar9;
  }
  sVar6 = strlen(param_2);
  pcVar9 = DAT_000d7b48;
  if (0 < (int)sVar6) {
    sVar13 = 0;
    do {
      pcVar7 = strchr(DAT_000d7b48,(uint)(byte)param_2[sVar13]);
      if (pcVar7 == (char *)0x0) {
        if (sVar13 == 0) {
          return 0;
        }
        break;
      }
      *(char *)((int)param_1 + sVar13) = (char)pcVar7 - (char)pcVar9;
      sVar13 = sVar13 + 1;
    } while (sVar6 != sVar13);
    iVar14 = sVar13 - 1;
    iVar11 = (int)param_1 + (sVar13 - 3);
    pcVar9 = (char *)((int)param_1 + sVar13);
    sVar6 = sVar13;
    do {
      bVar2 = pcVar9[-1];
      uVar8 = (uint)bVar2;
      sVar17 = sVar6 - 1;
      sVar16 = sVar6 - 2;
      *(byte *)(iVar11 + 3) = bVar2;
      sVar5 = sVar6;
      if (iVar14 + -1 < 0) {
joined_r0x000d7b38:
        sVar6 = sVar5;
        if (uVar8 != 0) goto LAB_000d7a2e;
        break;
      }
      sVar6 = sVar6 - 3;
      *(byte *)(iVar11 + 3) = bVar2 | pcVar9[-2] << 6;
      uVar8 = ((uint)(byte)pcVar9[-2] << 0x1a) >> 0x1c;
      bVar2 = (byte)(((uint)(byte)pcVar9[-2] << 0x1a) >> 0x18);
      *(byte *)(iVar11 + 2) = bVar2 >> 4;
      sVar5 = sVar17;
      if (iVar14 == 1) goto joined_r0x000d7b38;
      bVar21 = iVar14 == 2;
      iVar14 = iVar14 + -4;
      *(byte *)(iVar11 + 2) = bVar2 >> 4 | pcVar9[-3] << 4;
      uVar8 = ((uint)(byte)pcVar9[-3] << 0x1a) >> 0x1e;
      bVar2 = (byte)(((uint)(byte)pcVar9[-3] << 0x1a) >> 0x18);
      *(byte *)(iVar11 + 1) = bVar2 >> 6;
      sVar5 = sVar16;
      if (bVar21) goto joined_r0x000d7b38;
      pcVar9 = pcVar9 + -4;
      *(byte *)(iVar11 + 1) = bVar2 >> 6 | *pcVar9 << 2;
      iVar11 = iVar11 + -3;
      *(undefined *)((int)param_1 + sVar6) = 0;
    } while (iVar14 != -1);
    if ((int)sVar6 <= (int)sVar13) {
      pcVar9 = (char *)((int)param_1 + sVar6);
      do {
        pcVar9 = pcVar9 + 1;
        sVar6 = sVar6 + 1;
        if (*pcVar9 != '\0') {
LAB_000d7a2e:
          if ((int)sVar13 < (int)sVar6) {
            return 0;
          }
          puVar18 = (undefined4 *)((int)param_1 + sVar6);
          uVar8 = (sVar13 - sVar6) + 1;
          uVar20 = uVar8 >> 2;
          uVar10 = uVar8 & 0xfffffffc;
          if (uVar20 == 0 ||
              ((((uint)puVar18 | (uint)param_1) & 3) != 0 ||
              (uVar8 < 4 || puVar18 < param_1 + 1 && param_1 < puVar18 + 1))) {
            uVar10 = 0;
          }
          else {
            if (uVar20 < 9) {
              uVar12 = 0;
              puVar15 = param_1;
            }
            else {
              uVar12 = 0;
              puVar4 = param_1 + 8;
              puVar3 = puVar18;
              do {
                puVar15 = puVar4;
                puVar18 = puVar3 + 8;
                uVar19 = uVar12 + 9;
                uVar12 = uVar12 + 8;
                HintPreloadData(puVar3 + 0x1d);
                puVar15[-8] = *puVar3;
                puVar15[-7] = puVar3[1];
                puVar15[-6] = puVar3[2];
                puVar15[-5] = puVar3[3];
                puVar15[-4] = puVar3[4];
                puVar15[-3] = puVar3[5];
                puVar15[-2] = puVar3[6];
                puVar15[-1] = puVar3[7];
                puVar4 = puVar15 + 8;
                puVar3 = puVar18;
              } while (uVar19 < uVar20 - 7);
            }
            puVar18 = puVar18 + -1;
            do {
              puVar18 = puVar18 + 1;
              uVar12 = uVar12 + 1;
              *puVar15 = *puVar18;
              puVar15 = puVar15 + 1;
            } while (uVar12 < uVar20);
            sVar6 = sVar6 + uVar10;
            if (uVar8 == uVar10) {
              return uVar8;
            }
          }
          iVar11 = uVar10 - sVar6;
          do {
            *(undefined *)((int)param_1 + sVar6 + iVar11) = *(undefined *)((int)param_1 + sVar6);
            sVar6 = sVar6 + 1;
          } while ((int)sVar6 <= (int)sVar13);
          return uVar8;
        }
      } while ((int)sVar6 <= (int)sVar13);
    }
  }
  return 0;
}

