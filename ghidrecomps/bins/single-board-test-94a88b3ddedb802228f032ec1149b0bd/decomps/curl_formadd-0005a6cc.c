
undefined4 curl_formadd(int *param_1,int *param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  code *pcVar4;
  int *piVar5;
  size_t sVar6;
  int iVar7;
  char *pcVar8;
  int *piVar9;
  size_t sVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int *piVar20;
  int *piVar21;
  int *piVar22;
  int *piVar23;
  char *pcVar24;
  undefined4 uVar25;
  char *pcVar26;
  int iVar27;
  int iVar28;
  char *pcVar29;
  int local_64;
  char *local_60;
  int local_8;
  undefined4 uStack_4;
  
  piVar22 = &local_8;
  local_8 = param_3;
  uStack_4 = param_4;
  piVar5 = (int *)(*Curl_ccalloc)(1,0x48);
  if (piVar5 == (int *)0x0) {
    return 1;
  }
  iVar27 = 0;
  bVar3 = false;
  piVar21 = (int *)0x0;
  piVar23 = piVar5;
LAB_0005a708:
  bVar2 = bVar3;
  if (piVar21 == (int *)0x0) {
    bVar2 = false;
  }
joined_r0x0005a714:
  if (bVar2) {
    iVar14 = *piVar21;
    iVar27 = piVar21[1];
    piVar21 = piVar21 + 2;
    if (iVar14 == 0x11) {
      bVar3 = false;
      goto LAB_0005a708;
    }
  }
  else {
    iVar14 = *piVar22;
    piVar22 = piVar22 + 1;
    if (iVar14 == 0x11) {
      pcVar29 = (char *)0x0;
      piVar22 = piVar5;
      iVar27 = 0;
      goto LAB_0005a96c;
    }
  }
  iVar7 = iVar27;
  piVar20 = piVar5;
  switch(iVar14) {
  case 1:
    goto switchD_0005a72c_caseD_1;
  case 2:
    piVar23[10] = piVar23[10] | 4;
switchD_0005a72c_caseD_1:
    if (*piVar23 != 0) goto LAB_0005a768;
    iVar14 = iVar27;
    if (!bVar3) {
      iVar14 = *piVar22;
      piVar22 = piVar22 + 1;
    }
    if (iVar14 == 0) break;
    bVar2 = bVar3;
    if (piVar21 == (int *)0x0) {
      bVar2 = false;
    }
    *piVar23 = iVar14;
    goto joined_r0x0005a714;
  case 3:
    goto switchD_0005a72c_caseD_3;
  case 4:
    goto switchD_0005a72c_caseD_4;
  case 5:
    piVar23[10] = piVar23[10] | 8;
switchD_0005a72c_caseD_4:
    if (piVar23[3] != 0) goto LAB_0005a768;
    if (!bVar3) {
      iVar7 = *piVar22;
      piVar22 = piVar22 + 1;
    }
    if (iVar7 != 0) {
LAB_0005abce:
      piVar23[3] = iVar7;
      goto LAB_0005a708;
    }
    break;
  case 6:
    iVar14 = iVar27;
    if (!bVar3) {
      iVar14 = *piVar22;
      piVar22 = piVar22 + 1;
    }
    piVar23[6] = iVar14;
    piVar23[7] = 0;
    goto LAB_0005a708;
  case 7:
    if ((piVar23[10] & 10U) != 0) goto LAB_0005a768;
    iVar14 = iVar27;
    if (!bVar3) {
      iVar14 = *piVar22;
      piVar22 = piVar22 + 1;
    }
    if (iVar14 != 0) {
      iVar14 = (*Curl_cstrdup)();
      piVar23[3] = iVar14;
      if (iVar14 == 0) goto LAB_0005ad16;
      *(undefined1 *)(piVar23 + 4) = 1;
      piVar23[10] = piVar23[10] | 2;
      goto LAB_0005a708;
    }
    break;
  case 8:
    if (bVar3) {
      uVar25 = 6;
      goto LAB_0005a788;
    }
    piVar21 = (int *)*piVar22;
    piVar22 = piVar22 + 1;
    if (piVar21 != (int *)0x0) {
      bVar3 = true;
      goto LAB_0005a708;
    }
    break;
  default:
    uVar25 = 4;
    goto LAB_0005a788;
  case 10:
    iVar14 = iVar27;
    if (!bVar3) {
      iVar14 = *piVar22;
      piVar22 = piVar22 + 1;
    }
    if (piVar23[3] == 0) {
      if (iVar14 != 0) {
        iVar14 = (*Curl_cstrdup)();
        piVar23[3] = iVar14;
        if (iVar14 == 0) goto LAB_0005ad16;
        *(undefined1 *)(piVar23 + 4) = 1;
        piVar23[10] = piVar23[10] | 1;
        goto LAB_0005a708;
      }
    }
    else {
      if (-1 < piVar23[10] << 0x1f) goto LAB_0005a768;
      if (iVar14 != 0) {
        local_64 = (*Curl_cstrdup)();
        if (local_64 == 0) goto LAB_0005ad16;
        piVar9 = (int *)(*Curl_ccalloc)(1,0x48);
        if (piVar9 != (int *)0x0) {
          iVar14 = piVar23[0x11];
          piVar9[3] = local_64;
          piVar9[10] = 1;
          piVar9[0x11] = iVar14;
          *(undefined1 *)(piVar9 + 4) = 1;
          piVar23[0x11] = (int)piVar9;
          piVar23 = piVar9;
          goto LAB_0005a708;
        }
LAB_0005ad94:
        uVar25 = 1;
        (*Curl_cfree)(local_64);
        goto LAB_0005a788;
      }
    }
    break;
  case 0xb:
  case 0x10:
    if (bVar3) {
      iVar7 = piVar23[0xd];
      iVar14 = iVar27;
    }
    else {
      iVar7 = piVar23[0xd];
      iVar14 = *piVar22;
      piVar22 = piVar22 + 1;
    }
    if (iVar7 != 0) goto LAB_0005a768;
    iVar14 = (*Curl_cstrdup)(iVar14);
    piVar23[0xd] = iVar14;
    if (iVar14 != 0) {
      *(undefined1 *)(piVar23 + 0xe) = 1;
      goto LAB_0005a708;
    }
LAB_0005ad16:
    uVar25 = 1;
    goto LAB_0005a788;
  case 0xc:
    piVar23[10] = piVar23[10] | 0x30;
    if (piVar23[0xb] == 0) {
      if (!bVar3) {
        iVar7 = *piVar22;
        piVar22 = piVar22 + 1;
      }
      if (iVar7 == 0) break;
      piVar23[0xb] = iVar7;
      goto LAB_0005abce;
    }
    goto LAB_0005a768;
  case 0xd:
    if (piVar23[0xc] != 0) goto LAB_0005a768;
    iVar14 = iVar27;
    if (!bVar3) {
      iVar14 = *piVar22;
      piVar22 = piVar22 + 1;
    }
    piVar23[0xc] = iVar14;
    goto LAB_0005a708;
  case 0xe:
    iVar14 = iVar27;
    if (!bVar3) {
      iVar14 = *piVar22;
      piVar22 = piVar22 + 1;
    }
    if (piVar23[8] == 0) {
      if (iVar14 != 0) {
        iVar14 = (*Curl_cstrdup)();
        piVar23[8] = iVar14;
        if (iVar14 == 0) goto LAB_0005ad16;
        *(undefined1 *)(piVar23 + 9) = 1;
        goto LAB_0005a708;
      }
    }
    else {
      if (-1 < piVar23[10] << 0x1f) goto LAB_0005a768;
      if (iVar14 != 0) {
        local_64 = (*Curl_cstrdup)();
        if (local_64 == 0) goto LAB_0005ad16;
        piVar9 = (int *)(*Curl_ccalloc)(1,0x48);
        if (piVar9 == (int *)0x0) goto LAB_0005ad94;
        iVar14 = piVar23[0x11];
        piVar9[8] = local_64;
        piVar9[10] = 1;
        piVar9[0x11] = iVar14;
        *(undefined1 *)(piVar9 + 9) = 1;
        piVar23[0x11] = (int)piVar9;
        piVar23 = piVar9;
        goto LAB_0005a708;
      }
    }
    break;
  case 0xf:
    if (bVar3) {
      iVar7 = piVar23[0x10];
      iVar14 = iVar27;
    }
    else {
      iVar7 = piVar23[0x10];
      iVar14 = *piVar22;
      piVar22 = piVar22 + 1;
    }
    if (iVar7 != 0) goto LAB_0005a768;
    piVar23[0x10] = iVar14;
    goto LAB_0005a708;
  case 0x13:
    piVar23[10] = piVar23[10] | 0x40;
    if (piVar23[0xf] != 0) goto LAB_0005a768;
    iVar14 = iVar27;
    if (!bVar3) {
      iVar14 = *piVar22;
      piVar22 = piVar22 + 1;
    }
    if (iVar14 != 0) {
      piVar23[0xf] = iVar14;
      piVar23[3] = iVar14;
      goto LAB_0005a708;
    }
    break;
  case 0x14:
    piVar23[10] = piVar23[10] | 0x80;
    iVar7 = 0;
    iVar14 = iVar27;
    if (!bVar3) {
      piVar20 = (int *)((int)piVar22 + 7U & 0xfffffff8);
      iVar14 = *piVar20;
      piVar22 = piVar20 + 2;
      iVar7 = piVar20[1];
    }
    piVar23[6] = iVar14;
    piVar23[7] = iVar7;
    goto LAB_0005a708;
  }
  uVar25 = 3;
  goto LAB_0005a788;
LAB_0005a96c:
  do {
    pcVar4 = Curl_cstrdup;
    if ((((((*piVar22 == 0) || (piVar22[3] == 0)) && (iVar27 == 0)) ||
         ((piVar22[6] != 0 || piVar22[7] != 0 && (piVar22[10] << 0x1f < 0)))) ||
        ((uVar15 = piVar22[10], (uVar15 & 9) == 9 ||
         ((piVar22[0xb] == 0 && ((uVar15 & 0x30) == 0x30)))))) || ((uVar15 & 10) == 10)) {
      uVar25 = 5;
      goto LAB_0005a9ac;
    }
    if (((uVar15 & 0x11) != 0) && (piVar22[8] == 0)) {
      if ((int)(uVar15 << 0x1b) < 0) {
        pcVar24 = (char *)piVar22[0xd];
      }
      else {
        pcVar24 = (char *)piVar22[3];
      }
      local_60 = "application/octet-stream";
      if (pcVar29 != (char *)0x0) {
        local_60 = pcVar29;
      }
      if (pcVar24 != (char *)0x0) {
        iVar14 = 0;
        do {
          sVar6 = strlen(pcVar24);
          pcVar26 = (char *)(&ctts_22888)[iVar14 * 2];
          iVar7 = iVar14 + 1;
          sVar10 = strlen(pcVar26);
          if ((sVar10 <= sVar6) &&
             (iVar11 = curl_strequal(pcVar24 + (sVar6 - sVar10),pcVar26), iVar11 != 0)) {
            local_60 = (&PTR_s_image_gif_0013c050)[iVar14 * 2];
            break;
          }
          iVar14 = iVar7;
        } while (iVar7 != 6);
      }
      iVar14 = (*pcVar4)(local_60);
      piVar22[8] = iVar14;
      if (iVar14 != 0) {
        *(undefined1 *)(piVar22 + 9) = 1;
        goto LAB_0005a882;
      }
LAB_0005ad1c:
      uVar25 = 1;
      goto LAB_0005a9ac;
    }
LAB_0005a882:
    uVar15 = piVar22[10];
    if ((-1 < (int)(uVar15 << 0x1d)) && (piVar5 == piVar22)) {
      pcVar24 = (char *)*piVar5;
      if (pcVar24 != (char *)0x0) {
        iVar14 = piVar5[2];
        if (iVar14 == 0) {
          sVar6 = strlen(pcVar24);
          iVar14 = sVar6 + 1;
        }
        iVar14 = Curl_memdup(pcVar24,iVar14);
        *piVar5 = iVar14;
        if (iVar14 != 0) {
          uVar15 = piVar5[10];
          *(undefined1 *)(piVar5 + 1) = 1;
          goto LAB_0005a890;
        }
      }
      uVar25 = 1;
      piVar22 = piVar5;
      goto LAB_0005a9ac;
    }
LAB_0005a890:
    if ((uVar15 & 0x6b) == 0) {
      pcVar24 = (char *)piVar22[3];
      if (pcVar24 == (char *)0x0) {
        iVar14 = 0;
      }
      else {
        iVar14 = piVar22[6];
        if (iVar14 == 0) {
          sVar6 = strlen(pcVar24);
          iVar14 = sVar6 + 1;
        }
        iVar14 = Curl_memdup(pcVar24,iVar14);
        piVar22[3] = iVar14;
        if (iVar14 == 0) goto LAB_0005ad1c;
        uVar15 = piVar22[10];
        *(undefined1 *)(piVar22 + 4) = 1;
      }
    }
    else {
      iVar14 = piVar22[3];
    }
    pcVar24 = (char *)*piVar22;
    pcVar26 = (char *)piVar22[2];
    iVar11 = piVar22[6];
    iVar16 = piVar22[7];
    iVar28 = piVar22[0xc];
    iVar17 = piVar22[0xb];
    iVar12 = piVar22[8];
    iVar18 = piVar22[0x10];
    iVar13 = piVar22[0xd];
    iVar19 = piVar22[0xf];
    iVar7 = (*Curl_ccalloc)(1,0x40);
    if (iVar7 == 0) goto LAB_0005ad1c;
    *(char **)(iVar7 + 4) = pcVar24;
    pcVar8 = pcVar24;
    if ((pcVar24 != (char *)0x0) && (pcVar8 = pcVar26, pcVar26 == (char *)0x0)) {
      pcVar8 = (char *)strlen(pcVar24);
    }
    *(char **)(iVar7 + 8) = pcVar8;
    *(int *)(iVar7 + 0x14) = iVar17;
    *(uint *)(iVar7 + 0x28) = uVar15 | 0x80;
    *(int *)(iVar7 + 0xc) = iVar14;
    *(int *)(iVar7 + 0x1c) = iVar12;
    *(int *)(iVar7 + 0x38) = iVar11;
    *(int *)(iVar7 + 0x3c) = iVar16;
    *(int *)(iVar7 + 0x18) = iVar28;
    *(int *)(iVar7 + 0x20) = iVar18;
    *(int *)(iVar7 + 0x2c) = iVar13;
    *(int *)(iVar7 + 0x30) = iVar19;
    if (iVar27 == 0) {
      piVar21 = (int *)*param_2;
      if ((int *)*param_2 == (int *)0x0) {
        piVar21 = param_1;
      }
      *piVar21 = iVar7;
      *param_2 = iVar7;
    }
    else {
      *(undefined4 *)(iVar7 + 0x24) = *(undefined4 *)(iVar27 + 0x24);
      *(int *)(iVar27 + 0x24) = iVar7;
    }
    piVar21 = piVar22 + 8;
    piVar22 = (int *)piVar22[0x11];
    if ((char *)*piVar21 != (char *)0x0) {
      pcVar29 = (char *)*piVar21;
    }
    iVar27 = iVar7;
  } while (piVar22 != (int *)0x0);
  uVar25 = 0;
  goto LAB_0005a7d8;
  while( true ) {
    if (cVar1 != '\0') {
      (*Curl_cfree)(piVar22[0xd]);
      piVar22[0xd] = 0;
      *(undefined1 *)(piVar22 + 0xe) = 0;
    }
    piVar21 = piVar22 + 0x11;
    piVar22 = (int *)*piVar21;
    if ((int *)*piVar21 == (int *)0x0) break;
LAB_0005a9ac:
    if ((char)piVar22[1] == '\0') {
      if ((char)piVar22[4] != '\0') goto LAB_0005a9c2;
LAB_0005a998:
      if ((char)piVar22[9] != '\0') goto LAB_0005a9d4;
LAB_0005a99e:
      cVar1 = (char)piVar22[0xe];
    }
    else {
      (*Curl_cfree)(*piVar22);
      *piVar22 = 0;
      *(undefined1 *)(piVar22 + 1) = 0;
      if ((char)piVar22[4] == '\0') goto LAB_0005a998;
LAB_0005a9c2:
      (*Curl_cfree)(piVar22[3]);
      piVar22[3] = 0;
      *(undefined1 *)(piVar22 + 4) = 0;
      if ((char)piVar22[9] == '\0') goto LAB_0005a99e;
LAB_0005a9d4:
      (*Curl_cfree)(piVar22[8]);
      cVar1 = (char)piVar22[0xe];
      piVar22[8] = 0;
      *(undefined1 *)(piVar22 + 9) = 0;
    }
  }
  goto LAB_0005a7d8;
switchD_0005a72c_caseD_3:
  if (piVar23[2] != 0) {
LAB_0005a768:
    uVar25 = 2;
    goto LAB_0005a788;
  }
  iVar14 = iVar27;
  if (!bVar3) {
    iVar14 = *piVar22;
    piVar22 = piVar22 + 1;
  }
  piVar23[2] = iVar14;
  goto LAB_0005a708;
LAB_0005a788:
  do {
    if ((char)piVar20[1] == '\0') {
      if ((char)piVar20[4] != '\0') goto LAB_0005a79e;
LAB_0005a776:
      if ((char)piVar20[9] != '\0') goto LAB_0005a7b0;
LAB_0005a77c:
      if ((char)piVar20[0xe] != '\0') goto LAB_0005a7c4;
LAB_0005a782:
      piVar22 = piVar20 + 0x11;
      piVar20 = (int *)*piVar22;
      if ((int *)*piVar22 == (int *)0x0) break;
      goto LAB_0005a788;
    }
    (*Curl_cfree)(*piVar20);
    *piVar20 = 0;
    *(undefined1 *)(piVar20 + 1) = 0;
    if ((char)piVar20[4] == '\0') goto LAB_0005a776;
LAB_0005a79e:
    (*Curl_cfree)(piVar20[3]);
    piVar20[3] = 0;
    *(undefined1 *)(piVar20 + 4) = 0;
    if ((char)piVar20[9] == '\0') goto LAB_0005a77c;
LAB_0005a7b0:
    (*Curl_cfree)(piVar20[8]);
    piVar20[8] = 0;
    *(undefined1 *)(piVar20 + 9) = 0;
    if ((char)piVar20[0xe] == '\0') goto LAB_0005a782;
LAB_0005a7c4:
    (*Curl_cfree)(piVar20[0xd]);
    piVar20[0xd] = 0;
    *(undefined1 *)(piVar20 + 0xe) = 0;
    piVar22 = piVar20 + 0x11;
    piVar20 = (int *)*piVar22;
  } while ((int *)*piVar22 != (int *)0x0);
LAB_0005a7d8:
  do {
    piVar5 = (int *)piVar5[0x11];
    (*Curl_cfree)();
  } while (piVar5 != (int *)0x0);
  return uVar25;
}

