
undefined4 nc_match_single(int param_1,undefined4 *param_2)

{
  char *pcVar1;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  byte *pbVar7;
  char *pcVar8;
  size_t sVar9;
  uint uVar10;
  int iVar11;
  char *pcVar12;
  byte *pbVar13;
  X509_NAME *a;
  char *pcVar14;
  byte *pbVar15;
  char *pcVar16;
  X509_NAME *a_00;
  char *__s2;
  size_t sVar17;
  char *pcVar18;
  void *pvVar19;
  
  switch(*param_2) {
  case 1:
    pcVar16 = *(char **)param_2[1];
    pcVar14 = (char *)((undefined4 *)param_2[1])[2];
    __s2 = (char *)(*(int **)(param_1 + 4))[2];
    if ((int)pcVar16 < 1) {
      if (pcVar16 == (char *)0x0) {
        pcVar18 = (char *)0x0;
      }
      else {
        pcVar18 = pcVar16 + -1 + (int)pcVar14;
      }
    }
    else {
      pcVar18 = pcVar16 + -1 + (int)pcVar14;
      if (pcVar14[(int)(pcVar16 + -1)] != '@') {
        pcVar8 = pcVar16;
        pcVar1 = pcVar16 + -2 + (int)pcVar14;
        do {
          pcVar12 = pcVar1;
          pcVar8 = pcVar8 + -1;
          pcVar18 = pcVar8;
          if (pcVar8 == (char *)0x0) break;
          pcVar1 = pcVar12 + -1;
          pcVar18 = pcVar12;
        } while (*pcVar12 != '@');
      }
    }
    iVar11 = **(int **)(param_1 + 4);
    if (iVar11 < 1) {
      if (iVar11 == 0) {
        return 0x35;
      }
      sVar17 = iVar11 - 1;
      pbVar5 = (byte *)(__s2 + sVar17);
      if (pbVar5 == (byte *)0x0) {
        return 0x35;
      }
    }
    else {
      sVar17 = iVar11 - 1;
      pbVar5 = (byte *)(__s2 + sVar17);
      if (__s2[sVar17] != '@') {
        sVar9 = sVar17;
        pbVar15 = (byte *)(__s2 + iVar11 + -2);
        do {
          pbVar5 = pbVar15;
          sVar17 = sVar9 - 1;
          if (sVar9 == 0) {
            return 0x35;
          }
          sVar9 = sVar17;
          pbVar15 = pbVar5 + -1;
        } while (*pbVar5 != 0x40);
      }
    }
    if (pcVar18 == (char *)0x0) {
      if ((0 < (int)pcVar16) && (*pcVar14 == '.')) {
        if (iVar11 <= (int)pcVar16) {
          return 0x2f;
        }
        iVar11 = ia5ncasecmp(pcVar14,__s2 + (iVar11 - (int)pcVar16),pcVar16);
        break;
      }
      iVar6 = 0;
    }
    else {
      if (pcVar14 != pcVar18) {
        if ((int)pcVar18 - (int)pcVar14 != sVar17) {
          return 0x2f;
        }
        pvVar2 = memchr(pcVar14,0,sVar17);
        if (pvVar2 != (void *)0x0) {
          return 0x35;
        }
        pvVar2 = memchr(__s2,0,sVar17);
        if (pvVar2 != (void *)0x0) {
          return 0x35;
        }
        iVar6 = strncmp(pcVar14,__s2,sVar17);
        if (iVar6 != 0) {
          return 0x2f;
        }
      }
      iVar6 = (int)(pcVar18 + 1) - (int)pcVar14;
      pcVar14 = pcVar18 + 1;
    }
    iVar6 = (int)pcVar16 - iVar6;
    if (iVar6 != iVar11 - (int)(pbVar5 + (1 - (int)__s2))) {
      return 0x2f;
    }
    if (iVar6 == 0) {
      return 0;
    }
    pbVar15 = (byte *)(pcVar14 + -1);
    do {
      pbVar15 = pbVar15 + 1;
      uVar4 = (uint)*pbVar15;
      pbVar5 = pbVar5 + 1;
      uVar10 = (uint)*pbVar5;
      if (uVar4 != uVar10) {
        if (uVar4 - 0x41 < 0x1a) {
          uVar4 = uVar4 + 0x20 & 0xff;
          if (uVar10 - 0x41 < 0x1a) goto LAB_00176358;
        }
        else {
          if (0x19 < uVar10 - 0x41) {
            return 0x2f;
          }
LAB_00176358:
          uVar10 = uVar10 + 0x20 & 0xff;
        }
        if (uVar10 != uVar4) {
          return 0x2f;
        }
      }
      iVar6 = iVar6 + -1;
      if (iVar6 == 0) {
        return 0;
      }
    } while( true );
  case 2:
    iVar11 = *(int *)param_2[1];
    if (iVar11 == 0) {
      return 0;
    }
    iVar6 = **(int **)(param_1 + 4);
    if (iVar6 < iVar11) {
      return 0x2f;
    }
    iVar3 = (*(int **)(param_1 + 4))[2];
    pcVar14 = (char *)((int *)param_2[1])[2];
    if (((iVar11 < iVar6) && (iVar3 = iVar3 + (iVar6 - iVar11), *pcVar14 != '.')) &&
       (*(char *)(iVar3 + -1) != '.')) {
      return 0x2f;
    }
    if (iVar11 == 0) {
      return 0;
    }
    pbVar5 = (byte *)(pcVar14 + -1);
    pbVar15 = (byte *)(iVar3 + -1);
    do {
      pbVar5 = pbVar5 + 1;
      uVar4 = (uint)*pbVar5;
      pbVar15 = pbVar15 + 1;
      uVar10 = (uint)*pbVar15;
      if (uVar4 != uVar10) {
        if (uVar4 - 0x41 < 0x1a) {
          uVar4 = uVar4 + 0x20 & 0xff;
          if (uVar10 - 0x41 < 0x1a) goto LAB_0017645c;
        }
        else {
          if (0x19 < uVar10 - 0x41) {
            return 0x2f;
          }
LAB_0017645c:
          uVar10 = uVar10 + 0x20 & 0xff;
        }
        if (uVar10 != uVar4) {
          return 0x2f;
        }
      }
      iVar11 = iVar11 + -1;
      if (iVar11 == 0) {
        return 0;
      }
    } while( true );
  default:
    return 0x33;
  case 4:
    a_00 = *(X509_NAME **)(param_1 + 4);
    a = (X509_NAME *)param_2[1];
    if (((a_00->modified != 0) && (iVar11 = i2d_X509_NAME(a_00,(uchar **)0x0), iVar11 < 0)) ||
       ((a->modified != 0 && (iVar11 = i2d_X509_NAME(a,(uchar **)0x0), iVar11 < 0)))) {
      return 0x11;
    }
    if (a_00->canon_enclen < a->canon_enclen) {
      return 0x2f;
    }
    iVar11 = memcmp(a->canon_enc,a_00->canon_enc,a->canon_enclen);
    break;
  case 6:
    sVar17 = **(size_t **)(param_1 + 4);
    pvVar19 = (void *)(*(size_t **)(param_1 + 4))[2];
    pvVar2 = memchr(pvVar19,0x3a,sVar17);
    if (pvVar2 == (void *)0x0) {
      return 0x35;
    }
    if ((int)(sVar17 - ((int)pvVar2 - (int)pvVar19)) < 3) {
      return 0x35;
    }
    if (*(char *)((int)pvVar2 + 1) != '/') {
      return 0x35;
    }
    if (*(char *)((int)pvVar2 + 2) != '/') {
      return 0x35;
    }
    pvVar2 = (void *)((int)pvVar2 + 3);
    sVar17 = sVar17 - ((int)pvVar2 - (int)pvVar19);
    pvVar19 = memchr(pvVar2,0x3a,sVar17);
    if ((pvVar19 != (void *)0x0) || (pvVar19 = memchr(pvVar2,0x2f,sVar17), pvVar19 != (void *)0x0))
    {
      sVar17 = (int)pvVar19 - (int)pvVar2;
    }
    if (sVar17 == 0) {
      return 0x35;
    }
    sVar9 = *(size_t *)param_2[1];
    if (((int)sVar9 < 1) || (*(char *)((size_t *)param_2[1])[2] != '.')) {
      if (sVar9 != sVar17) {
        return 0x2f;
      }
      iVar11 = ia5ncasecmp(pvVar2);
    }
    else {
      if ((int)sVar17 <= (int)sVar9) {
        return 0x2f;
      }
      iVar11 = ia5ncasecmp((sVar17 - sVar9) + (int)pvVar2);
    }
    break;
  case 7:
    iVar11 = **(int **)(param_1 + 4);
    if (iVar11 == 4 || iVar11 == 0x10) {
      iVar6 = *(int *)param_2[1];
      if (iVar6 == 8 || iVar6 == 0x20) {
        if (iVar6 != iVar11 * 2) {
          return 0x2f;
        }
        if (0 < iVar11) {
          pbVar7 = (byte *)(*(int **)(param_1 + 4))[2];
          pbVar5 = (byte *)((int *)param_2[1])[2];
          pbVar15 = pbVar5 + iVar11;
          if (((*pbVar5 ^ *pbVar7) & pbVar5[iVar11]) != 0) {
            return 0x2f;
          }
          pbVar13 = pbVar7 + iVar11;
          do {
            pbVar7 = pbVar7 + 1;
            if (pbVar13 == pbVar7) {
              return 0;
            }
            pbVar5 = pbVar5 + 1;
            pbVar15 = pbVar15 + 1;
          } while (((*pbVar5 ^ *pbVar7) & *pbVar15) == 0);
          return 0x2f;
        }
        return 0;
      }
    }
    return 0x35;
  }
  if (iVar11 != 0) {
    return 0x2f;
  }
  return 0;
}

