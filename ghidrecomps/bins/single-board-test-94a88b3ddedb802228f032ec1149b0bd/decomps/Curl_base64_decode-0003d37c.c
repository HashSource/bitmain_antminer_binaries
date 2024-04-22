
undefined4 Curl_base64_decode(char *param_1,undefined4 *param_2,int *param_3)

{
  int iVar1;
  undefined uVar2;
  size_t sVar3;
  undefined *puVar4;
  size_t sVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  size_t sVar9;
  char *pcVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  undefined *puVar14;
  uint uVar15;
  
  *param_2 = 0;
  *param_3 = 0;
  sVar3 = strlen(param_1);
  if ((sVar3 != 0) && ((sVar3 & 3) == 0)) {
    cVar6 = *param_1;
    if (cVar6 == '=' || cVar6 == '\0') {
      sVar5 = 0;
    }
    else {
      sVar5 = 0;
      pcVar10 = param_1;
      do {
        pcVar10 = pcVar10 + 1;
        cVar6 = *pcVar10;
        sVar5 = sVar5 + 1;
      } while (cVar6 != '\0' && cVar6 != '=');
    }
    if (cVar6 == '=') {
      sVar9 = sVar5 + 1;
      if (param_1[sVar9] == '=') {
        sVar9 = sVar5 + 2;
        iVar7 = 2;
      }
      else {
        iVar7 = 1;
      }
    }
    else {
      iVar7 = 0;
      sVar9 = sVar5;
    }
    if (sVar3 == sVar9) {
      uVar11 = sVar3 >> 2;
      iVar7 = uVar11 * 3 - iVar7;
      puVar4 = (undefined *)(**DAT_0003d4bc)(iVar7 + 1);
      iVar1 = DAT_0003d4c4;
      if (puVar4 == (undefined *)0x0) {
        return 0x1b;
      }
      puVar14 = puVar4;
      if (uVar11 != 0) {
        param_1 = param_1 + 3;
        uVar12 = 0;
        do {
          uVar13 = 0;
          pcVar10 = param_1 + -4;
          uVar15 = 0;
          do {
            pcVar10 = pcVar10 + 1;
            cVar6 = *pcVar10;
            if (cVar6 == '=') {
              uVar15 = uVar15 << 6;
              uVar13 = uVar13 + 1;
            }
            else {
              iVar8 = 0;
              if (cVar6 != 'A') {
                do {
                  iVar8 = iVar8 + 1;
                  if (*(char *)(iVar1 + iVar8) == '\0') {
                    if (cVar6 != '\0') goto LAB_0003d4ac;
                    break;
                  }
                } while (cVar6 != *(char *)(iVar1 + iVar8));
              }
              uVar15 = iVar8 + uVar15 * 0x40;
            }
          } while (param_1 != pcVar10);
          if (uVar13 == 0) {
            uVar2 = curlx_ultouc(uVar15 & 0xff);
            puVar14[2] = uVar2;
LAB_0003d49c:
            uVar2 = curlx_ultouc(uVar15 >> 8 & 0xff);
            puVar14[1] = uVar2;
          }
          else if (uVar13 < 2) goto LAB_0003d49c;
          uVar2 = curlx_ultouc(((uVar15 >> 8) << 0x10) >> 0x18);
          *puVar14 = uVar2;
          if (3 - uVar13 == 0) {
LAB_0003d4ac:
            (**DAT_0003d4c0)(puVar4);
            return 0x3d;
          }
          uVar12 = uVar12 + 1;
          puVar14 = puVar14 + (3 - uVar13);
          param_1 = param_1 + 4;
        } while (uVar12 != uVar11);
      }
      *puVar14 = 0;
      *param_2 = puVar4;
      *param_3 = iVar7;
      return 0;
    }
  }
  return 0x3d;
}

