
undefined4 Curl_base64_decode(char *param_1,undefined4 *param_2,int *param_3)

{
  int iVar1;
  undefined1 uVar2;
  size_t sVar3;
  undefined1 *puVar4;
  size_t sVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  size_t sVar10;
  char *pcVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  undefined1 *puVar15;
  uint uVar16;
  
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
      pcVar11 = param_1;
      do {
        pcVar11 = pcVar11 + 1;
        cVar6 = *pcVar11;
        sVar5 = sVar5 + 1;
      } while (cVar6 != '\0' && cVar6 != '=');
    }
    if (cVar6 == '=') {
      sVar10 = sVar5 + 1;
      if (param_1[sVar10] == '=') {
        sVar10 = sVar5 + 2;
        iVar7 = 2;
      }
      else {
        iVar7 = 1;
      }
    }
    else {
      iVar7 = 0;
      sVar10 = sVar5;
    }
    if (sVar3 == sVar10) {
      uVar12 = sVar3 >> 2;
      iVar7 = uVar12 * 3 - iVar7;
      puVar4 = (undefined1 *)(*Curl_cmalloc)(iVar7 + 1);
      if (puVar4 == (undefined1 *)0x0) {
        return 0x1b;
      }
      puVar15 = puVar4;
      if (uVar12 != 0) {
        param_1 = param_1 + 3;
        uVar13 = 0;
        do {
          uVar14 = 0;
          pcVar11 = param_1 + -4;
          uVar16 = 0;
          do {
            pcVar11 = pcVar11 + 1;
            cVar6 = *pcVar11;
            if (cVar6 == '=') {
              uVar16 = uVar16 << 6;
              uVar14 = uVar14 + 1;
            }
            else {
              iVar8 = 0;
              iVar9 = iVar8;
              if (cVar6 != 'A') {
                do {
                  iVar8 = iVar9 + 1;
                  iVar1 = iVar9 + 1;
                  if ("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[iVar1] ==
                      '\0') {
                    if (cVar6 != '\0') goto LAB_0003d4ac;
                    break;
                  }
                  iVar9 = iVar8;
                } while (cVar6 != "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
                                  [iVar1]);
              }
              uVar16 = iVar8 + uVar16 * 0x40;
            }
          } while (param_1 != pcVar11);
          if (uVar14 == 0) {
            uVar2 = curlx_ultouc(uVar16 & 0xff);
            puVar15[2] = uVar2;
LAB_0003d49c:
            uVar2 = curlx_ultouc(uVar16 >> 8 & 0xff);
            puVar15[1] = uVar2;
          }
          else if (uVar14 < 2) goto LAB_0003d49c;
          uVar2 = curlx_ultouc(((uVar16 >> 8) << 0x10) >> 0x18);
          *puVar15 = uVar2;
          if (3 - uVar14 == 0) {
LAB_0003d4ac:
            (*Curl_cfree)(puVar4);
            return 0x3d;
          }
          uVar13 = uVar13 + 1;
          puVar15 = puVar15 + (3 - uVar14);
          param_1 = param_1 + 4;
        } while (uVar13 != uVar12);
      }
      *puVar15 = 0;
      *param_2 = puVar4;
      *param_3 = iVar7;
      return 0;
    }
  }
  return 0x3d;
}

