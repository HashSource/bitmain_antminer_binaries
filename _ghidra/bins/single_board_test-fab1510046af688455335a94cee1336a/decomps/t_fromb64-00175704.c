
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
  uint uVar9;
  int iVar10;
  uint uVar11;
  size_t sVar12;
  int iVar13;
  undefined4 *puVar14;
  size_t sVar15;
  size_t sVar16;
  undefined4 *puVar17;
  uint uVar18;
  uint uVar19;
  bool bVar20;
  
  cVar1 = *param_2;
  while ((cVar1 != '\0' && ((cVar1 == ' ' || cVar1 == '\t' || (cVar1 == '\n'))))) {
    pcVar7 = param_2 + 1;
    param_2 = param_2 + 1;
    cVar1 = *pcVar7;
  }
  sVar6 = strlen(param_2);
  if (0 < (int)sVar6) {
    sVar12 = 0;
    do {
      pcVar7 = strchr(b64table,(uint)(byte)param_2[sVar12]);
      if (pcVar7 == (char *)0x0) {
        if (sVar12 == 0) {
          return 0;
        }
        break;
      }
      *(char *)((int)param_1 + sVar12) = (char)pcVar7 + -0x38;
      sVar12 = sVar12 + 1;
    } while (sVar6 != sVar12);
    iVar13 = sVar12 - 1;
    iVar10 = (int)param_1 + (sVar12 - 3);
    pcVar7 = (char *)((int)param_1 + sVar12);
    sVar6 = sVar12;
    do {
      bVar2 = pcVar7[-1];
      uVar8 = (uint)bVar2;
      sVar16 = sVar6 - 1;
      sVar15 = sVar6 - 2;
      *(byte *)(iVar10 + 3) = bVar2;
      sVar5 = sVar6;
      if (iVar13 + -1 < 0) {
joined_r0x001758fc:
        sVar6 = sVar5;
        if (uVar8 != 0) goto LAB_001757f2;
        break;
      }
      sVar6 = sVar6 - 3;
      *(byte *)(iVar10 + 3) = bVar2 | pcVar7[-2] << 6;
      uVar8 = ((uint)(byte)pcVar7[-2] << 0x1a) >> 0x1c;
      bVar2 = (byte)(((uint)(byte)pcVar7[-2] << 0x1a) >> 0x18);
      *(byte *)(iVar10 + 2) = bVar2 >> 4;
      sVar5 = sVar16;
      if (iVar13 == 1) goto joined_r0x001758fc;
      bVar20 = iVar13 == 2;
      iVar13 = iVar13 + -4;
      *(byte *)(iVar10 + 2) = bVar2 >> 4 | pcVar7[-3] << 4;
      uVar8 = ((uint)(byte)pcVar7[-3] << 0x1a) >> 0x1e;
      bVar2 = (byte)(((uint)(byte)pcVar7[-3] << 0x1a) >> 0x18);
      *(byte *)(iVar10 + 1) = bVar2 >> 6;
      sVar5 = sVar15;
      if (bVar20) goto joined_r0x001758fc;
      pcVar7 = pcVar7 + -4;
      *(byte *)(iVar10 + 1) = bVar2 >> 6 | *pcVar7 << 2;
      iVar10 = iVar10 + -3;
      *(undefined1 *)((int)param_1 + sVar6) = 0;
    } while (iVar13 != -1);
    if ((int)sVar6 <= (int)sVar12) {
      pcVar7 = (char *)((int)param_1 + sVar6);
      do {
        pcVar7 = pcVar7 + 1;
        sVar6 = sVar6 + 1;
        if (*pcVar7 != '\0') {
LAB_001757f2:
          if ((int)sVar12 < (int)sVar6) {
            return 0;
          }
          puVar17 = (undefined4 *)((int)param_1 + sVar6);
          uVar8 = (sVar12 - sVar6) + 1;
          uVar19 = uVar8 >> 2;
          uVar9 = uVar19 * 4;
          if (uVar19 == 0 ||
              ((((uint)puVar17 | (uint)param_1) & 3) != 0 ||
              (uVar8 < 4 || puVar17 < param_1 + 1 && param_1 < puVar17 + 1))) {
            uVar9 = 0;
          }
          else {
            if (uVar19 < 9) {
              uVar11 = 0;
              puVar14 = param_1;
            }
            else {
              uVar11 = 0;
              puVar4 = param_1 + 8;
              puVar3 = puVar17;
              do {
                puVar14 = puVar4;
                puVar17 = puVar3 + 8;
                uVar18 = uVar11 + 9;
                uVar11 = uVar11 + 8;
                HintPreloadData(puVar3 + 0x1d);
                puVar14[-8] = *puVar3;
                puVar14[-7] = puVar3[1];
                puVar14[-6] = puVar3[2];
                puVar14[-5] = puVar3[3];
                puVar14[-4] = puVar3[4];
                puVar14[-3] = puVar3[5];
                puVar14[-2] = puVar3[6];
                puVar14[-1] = puVar3[7];
                puVar4 = puVar14 + 8;
                puVar3 = puVar17;
              } while (uVar18 < uVar19 - 7);
            }
            puVar17 = puVar17 + -1;
            do {
              puVar17 = puVar17 + 1;
              uVar11 = uVar11 + 1;
              *puVar14 = *puVar17;
              puVar14 = puVar14 + 1;
            } while (uVar11 < uVar19);
            sVar6 = sVar6 + uVar9;
            if (uVar8 == uVar9) {
              return uVar8;
            }
          }
          iVar10 = uVar9 - sVar6;
          do {
            *(undefined1 *)((int)param_1 + sVar6 + iVar10) = *(undefined1 *)((int)param_1 + sVar6);
            sVar6 = sVar6 + 1;
          } while ((int)sVar6 <= (int)sVar12);
          return uVar8;
        }
      } while ((int)sVar6 <= (int)sVar12);
    }
  }
  return 0;
}

