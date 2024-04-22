
undefined4 curl_formadd(int *param_1,int **param_2,int *param_3,undefined4 param_4)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  code **ppcVar4;
  code *pcVar5;
  int **ppiVar6;
  size_t sVar7;
  int *piVar8;
  int *piVar9;
  int **ppiVar10;
  size_t sVar11;
  int iVar12;
  int *piVar13;
  int *piVar14;
  int *piVar15;
  int *piVar16;
  int *piVar17;
  int *piVar18;
  int *piVar19;
  int *piVar20;
  int **ppiVar21;
  int *piVar22;
  int **ppiVar23;
  int **ppiVar24;
  code **ppcVar25;
  int *__s;
  char *__s_00;
  undefined4 uVar26;
  int *piVar27;
  int *piVar28;
  int *piVar29;
  int *piVar30;
  int iVar31;
  int iVar32;
  int *local_64;
  int *local_60;
  int *local_8;
  undefined4 local_4;
  
  ppiVar23 = &local_8;
  local_8 = param_3;
  local_4 = param_4;
  ppiVar6 = (int **)(*Curl_ccalloc)(1,0x48);
  ppcVar4 = DAT_0005a990;
  if (ppiVar6 == (int **)0x0) {
    return 1;
  }
  piVar28 = (int *)0x0;
  bVar3 = false;
  piVar22 = (int *)0x0;
  ppiVar24 = ppiVar6;
LAB_0005a708:
  bVar2 = bVar3;
  if (piVar22 == (int *)0x0) {
    bVar2 = false;
  }
joined_r0x0005a714:
  if (bVar2) {
    piVar16 = (int *)*piVar22;
    piVar28 = (int *)piVar22[1];
    piVar22 = piVar22 + 2;
    if (piVar16 == (int *)0x11) {
      bVar3 = false;
      goto LAB_0005a708;
    }
  }
  else {
    piVar16 = *ppiVar23;
    ppiVar23 = ppiVar23 + 1;
    if (piVar16 == (int *)0x11) {
      piVar22 = (int *)0x0;
      ppiVar23 = ppiVar6;
      piVar28 = (int *)0x0;
      goto LAB_0005a96c;
    }
  }
  ppcVar25 = DAT_0005ac7c;
  piVar30 = piVar28;
  ppiVar21 = ppiVar6;
  switch(piVar16) {
  case (int *)0x1:
    goto switchD_0005a72c_caseD_1;
  case (int *)0x2:
    ppiVar24[10] = (int *)((uint)ppiVar24[10] | 4);
switchD_0005a72c_caseD_1:
    if (*ppiVar24 != (int *)0x0) goto LAB_0005a768;
    piVar16 = piVar28;
    if (!bVar3) {
      piVar16 = *ppiVar23;
      ppiVar23 = ppiVar23 + 1;
    }
    if (piVar16 == (int *)0x0) break;
    bVar2 = bVar3;
    if (piVar22 == (int *)0x0) {
      bVar2 = false;
    }
    *ppiVar24 = piVar16;
    goto joined_r0x0005a714;
  case (int *)0x3:
    goto switchD_0005a72c_caseD_3;
  case (int *)0x4:
    goto switchD_0005a72c_caseD_4;
  case (int *)0x5:
    ppiVar24[10] = (int *)((uint)ppiVar24[10] | 8);
switchD_0005a72c_caseD_4:
    if (ppiVar24[3] != (int *)0x0) goto LAB_0005a768;
    if (!bVar3) {
      piVar30 = *ppiVar23;
      ppiVar23 = ppiVar23 + 1;
    }
    if (piVar30 != (int *)0x0) {
LAB_0005abce:
      ppiVar24[3] = piVar30;
      goto LAB_0005a708;
    }
    break;
  case (int *)0x6:
    piVar16 = piVar28;
    if (!bVar3) {
      piVar16 = *ppiVar23;
      ppiVar23 = ppiVar23 + 1;
    }
    ppiVar24[6] = piVar16;
    ppiVar24[7] = (int *)0x0;
    goto LAB_0005a708;
  case (int *)0x7:
    if (((uint)ppiVar24[10] & 10) != 0) goto LAB_0005a768;
    piVar16 = piVar28;
    if (!bVar3) {
      piVar16 = *ppiVar23;
      ppiVar23 = ppiVar23 + 1;
    }
    if (piVar16 != (int *)0x0) {
      piVar16 = (int *)(**ppcVar4)();
      ppiVar24[3] = piVar16;
      if (piVar16 == (int *)0x0) goto LAB_0005ad16;
      *(undefined *)(ppiVar24 + 4) = 1;
      ppiVar24[10] = (int *)((uint)ppiVar24[10] | 2);
      goto LAB_0005a708;
    }
    break;
  case (int *)0x8:
    if (bVar3) {
      uVar26 = 6;
      goto LAB_0005a788;
    }
    piVar22 = *ppiVar23;
    ppiVar23 = ppiVar23 + 1;
    if (piVar22 != (int *)0x0) {
      bVar3 = true;
      goto LAB_0005a708;
    }
    break;
  default:
    uVar26 = 4;
    goto LAB_0005a788;
  case (int *)0xa:
    piVar16 = piVar28;
    if (!bVar3) {
      piVar16 = *ppiVar23;
      ppiVar23 = ppiVar23 + 1;
    }
    if (ppiVar24[3] == (int *)0x0) {
      if (piVar16 != (int *)0x0) {
        piVar16 = (int *)(**ppcVar4)();
        ppiVar24[3] = piVar16;
        if (piVar16 == (int *)0x0) goto LAB_0005ad16;
        *(undefined *)(ppiVar24 + 4) = 1;
        ppiVar24[10] = (int *)((uint)ppiVar24[10] | 1);
        goto LAB_0005a708;
      }
    }
    else {
      if (-1 < (int)ppiVar24[10] << 0x1f) goto LAB_0005a768;
      if (piVar16 != (int *)0x0) {
        local_64 = (int *)(**ppcVar4)();
        if (local_64 == (int *)0x0) goto LAB_0005ad16;
        ppiVar10 = (int **)(*Curl_ccalloc)(1,0x48);
        if (ppiVar10 != (int **)0x0) {
          piVar16 = ppiVar24[0x11];
          ppiVar10[3] = local_64;
          ppiVar10[10] = (int *)0x1;
          ppiVar10[0x11] = piVar16;
          *(undefined *)(ppiVar10 + 4) = 1;
          ppiVar24[0x11] = (int *)ppiVar10;
          ppiVar24 = ppiVar10;
          goto LAB_0005a708;
        }
LAB_0005ad94:
        ppcVar25 = DAT_0005ada0;
        uVar26 = 1;
        (**DAT_0005ada0)(local_64);
        goto LAB_0005a788;
      }
    }
    break;
  case (int *)0xb:
  case (int *)0x10:
    if (bVar3) {
      piVar30 = ppiVar24[0xd];
      piVar16 = piVar28;
    }
    else {
      piVar30 = ppiVar24[0xd];
      piVar16 = *ppiVar23;
      ppiVar23 = ppiVar23 + 1;
    }
    if (piVar30 != (int *)0x0) goto LAB_0005a768;
    piVar16 = (int *)(**ppcVar4)(piVar16);
    ppiVar24[0xd] = piVar16;
    if (piVar16 != (int *)0x0) {
      *(undefined *)(ppiVar24 + 0xe) = 1;
      goto LAB_0005a708;
    }
LAB_0005ad16:
    uVar26 = 1;
    ppcVar25 = DAT_0005ada0;
    goto LAB_0005a788;
  case (int *)0xc:
    ppiVar24[10] = (int *)((uint)ppiVar24[10] | 0x30);
    if (ppiVar24[0xb] == (int *)0x0) {
      if (!bVar3) {
        piVar30 = *ppiVar23;
        ppiVar23 = ppiVar23 + 1;
      }
      if (piVar30 == (int *)0x0) break;
      ppiVar24[0xb] = piVar30;
      goto LAB_0005abce;
    }
    goto LAB_0005a768;
  case (int *)0xd:
    if (ppiVar24[0xc] != (int *)0x0) goto LAB_0005a768;
    piVar16 = piVar28;
    if (!bVar3) {
      piVar16 = *ppiVar23;
      ppiVar23 = ppiVar23 + 1;
    }
    ppiVar24[0xc] = piVar16;
    goto LAB_0005a708;
  case (int *)0xe:
    piVar16 = piVar28;
    if (!bVar3) {
      piVar16 = *ppiVar23;
      ppiVar23 = ppiVar23 + 1;
    }
    if (ppiVar24[8] == (int *)0x0) {
      if (piVar16 != (int *)0x0) {
        piVar16 = (int *)(**ppcVar4)();
        ppiVar24[8] = piVar16;
        if (piVar16 == (int *)0x0) goto LAB_0005ad16;
        *(undefined *)(ppiVar24 + 9) = 1;
        goto LAB_0005a708;
      }
    }
    else {
      if (-1 < (int)ppiVar24[10] << 0x1f) goto LAB_0005a768;
      if (piVar16 != (int *)0x0) {
        local_64 = (int *)(**ppcVar4)();
        if (local_64 == (int *)0x0) goto LAB_0005ad16;
        ppiVar10 = (int **)(*Curl_ccalloc)(1,0x48);
        if (ppiVar10 == (int **)0x0) goto LAB_0005ad94;
        piVar16 = ppiVar24[0x11];
        ppiVar10[8] = local_64;
        ppiVar10[10] = (int *)0x1;
        ppiVar10[0x11] = piVar16;
        *(undefined *)(ppiVar10 + 9) = 1;
        ppiVar24[0x11] = (int *)ppiVar10;
        ppiVar24 = ppiVar10;
        goto LAB_0005a708;
      }
    }
    break;
  case (int *)0xf:
    if (bVar3) {
      piVar30 = ppiVar24[0x10];
      piVar16 = piVar28;
    }
    else {
      piVar30 = ppiVar24[0x10];
      piVar16 = *ppiVar23;
      ppiVar23 = ppiVar23 + 1;
    }
    if (piVar30 != (int *)0x0) goto LAB_0005a768;
    ppiVar24[0x10] = piVar16;
    goto LAB_0005a708;
  case (int *)0x13:
    ppiVar24[10] = (int *)((uint)ppiVar24[10] | 0x40);
    if (ppiVar24[0xf] != (int *)0x0) goto LAB_0005a768;
    piVar16 = piVar28;
    if (!bVar3) {
      piVar16 = *ppiVar23;
      ppiVar23 = ppiVar23 + 1;
    }
    if (piVar16 != (int *)0x0) {
      ppiVar24[0xf] = piVar16;
      ppiVar24[3] = piVar16;
      goto LAB_0005a708;
    }
    break;
  case (int *)0x14:
    ppiVar24[10] = (int *)((uint)ppiVar24[10] | 0x80);
    piVar30 = (int *)0x0;
    piVar16 = piVar28;
    if (!bVar3) {
      ppiVar21 = (int **)((int)ppiVar23 + 7U & 0xfffffff8);
      piVar16 = *ppiVar21;
      ppiVar23 = ppiVar21 + 2;
      piVar30 = ppiVar21[1];
    }
    ppiVar24[6] = piVar16;
    ppiVar24[7] = piVar30;
    goto LAB_0005a708;
  }
  uVar26 = 3;
  ppcVar25 = DAT_0005ac7c;
  goto LAB_0005a788;
LAB_0005a96c:
  do {
    pcVar5 = Curl_cstrdup;
    if ((((((*ppiVar23 == (int *)0x0) || (ppiVar23[3] == (int *)0x0)) && (piVar28 == (int *)0x0)) ||
         ((((uint)ppiVar23[6] | (uint)ppiVar23[7]) != 0 && ((int)ppiVar23[10] << 0x1f < 0)))) ||
        ((piVar16 = ppiVar23[10], ((uint)piVar16 & 9) == 9 ||
         ((ppiVar23[0xb] == (int *)0x0 && (((uint)piVar16 & 0x30) == 0x30)))))) ||
       (((uint)piVar16 & 10) == 10)) {
      uVar26 = 5;
      ppcVar25 = DAT_0005a98c;
      goto LAB_0005a9ac;
    }
    if ((((uint)piVar16 & 0x11) != 0) && (ppiVar23[8] == (int *)0x0)) {
      if ((int)piVar16 << 0x1b < 0) {
        piVar16 = ppiVar23[0xd];
      }
      else {
        piVar16 = ppiVar23[3];
      }
      local_60 = (int *)"application/octet-stream";
      if (piVar22 != (int *)0x0) {
        local_60 = piVar22;
      }
      if (piVar16 != (int *)0x0) {
        iVar31 = 0;
        do {
          sVar7 = strlen((char *)piVar16);
          __s_00 = (char *)(&ctts_22888)[iVar31 * 2];
          iVar32 = iVar31 + 1;
          sVar11 = strlen(__s_00);
          if ((sVar11 <= sVar7) &&
             (iVar12 = curl_strequal((int)piVar16 + (sVar7 - sVar11),__s_00), iVar12 != 0)) {
            local_60 = (int *)(&DAT_0013c050)[iVar31 * 2];
            break;
          }
          iVar31 = iVar32;
        } while (iVar32 != 6);
      }
      piVar16 = (int *)(*pcVar5)(local_60);
      ppiVar23[8] = piVar16;
      if (piVar16 != (int *)0x0) {
        *(undefined *)(ppiVar23 + 9) = 1;
        goto LAB_0005a882;
      }
LAB_0005ad1c:
      uVar26 = 1;
      ppcVar25 = DAT_0005ada0;
      goto LAB_0005a9ac;
    }
LAB_0005a882:
    piVar16 = ppiVar23[10];
    if ((-1 < (int)piVar16 << 0x1d) && (ppiVar6 == ppiVar23)) {
      piVar16 = *ppiVar6;
      if (piVar16 != (int *)0x0) {
        piVar30 = ppiVar6[2];
        if (piVar30 == (int *)0x0) {
          sVar7 = strlen((char *)piVar16);
          piVar30 = (int *)(sVar7 + 1);
        }
        piVar16 = (int *)Curl_memdup(piVar16,piVar30);
        *ppiVar6 = piVar16;
        if (piVar16 != (int *)0x0) {
          piVar16 = ppiVar6[10];
          *(undefined *)(ppiVar6 + 1) = 1;
          goto LAB_0005a890;
        }
      }
      uVar26 = 1;
      ppiVar23 = ppiVar6;
      ppcVar25 = DAT_0005ada0;
      goto LAB_0005a9ac;
    }
LAB_0005a890:
    if (((uint)piVar16 & 0x6b) == 0) {
      piVar30 = ppiVar23[3];
      if (piVar30 == (int *)0x0) {
        piVar30 = (int *)0x0;
      }
      else {
        piVar16 = ppiVar23[6];
        if (piVar16 == (int *)0x0) {
          sVar7 = strlen((char *)piVar30);
          piVar16 = (int *)(sVar7 + 1);
        }
        piVar30 = (int *)Curl_memdup(piVar30,piVar16);
        ppiVar23[3] = piVar30;
        if (piVar30 == (int *)0x0) goto LAB_0005ad1c;
        piVar16 = ppiVar23[10];
        *(undefined *)(ppiVar23 + 4) = 1;
      }
    }
    else {
      piVar30 = ppiVar23[3];
    }
    __s = *ppiVar23;
    piVar27 = ppiVar23[2];
    piVar13 = ppiVar23[6];
    piVar17 = ppiVar23[7];
    piVar29 = ppiVar23[0xc];
    piVar18 = ppiVar23[0xb];
    piVar14 = ppiVar23[8];
    piVar19 = ppiVar23[0x10];
    piVar15 = ppiVar23[0xd];
    piVar20 = ppiVar23[0xf];
    piVar8 = (int *)(*Curl_ccalloc)(1,0x40);
    if (piVar8 == (int *)0x0) goto LAB_0005ad1c;
    piVar8[1] = (int)__s;
    piVar9 = __s;
    if ((__s != (int *)0x0) && (piVar9 = piVar27, piVar27 == (int *)0x0)) {
      piVar9 = (int *)strlen((char *)__s);
    }
    piVar8[2] = (int)piVar9;
    piVar8[5] = (int)piVar18;
    piVar8[10] = (uint)piVar16 | 0x80;
    piVar8[3] = (int)piVar30;
    piVar8[7] = (int)piVar14;
    piVar8[0xe] = (int)piVar13;
    piVar8[0xf] = (int)piVar17;
    piVar8[6] = (int)piVar29;
    piVar8[8] = (int)piVar19;
    piVar8[0xb] = (int)piVar15;
    piVar8[0xc] = (int)piVar20;
    if (piVar28 == (int *)0x0) {
      piVar28 = *param_2;
      if (*param_2 == (int *)0x0) {
        piVar28 = param_1;
      }
      *piVar28 = (int)piVar8;
      *param_2 = piVar8;
    }
    else {
      piVar8[9] = piVar28[9];
      piVar28[9] = (int)piVar8;
    }
    ppiVar24 = ppiVar23 + 8;
    ppiVar23 = (int **)ppiVar23[0x11];
    if (*ppiVar24 != (int *)0x0) {
      piVar22 = *ppiVar24;
    }
    piVar28 = piVar8;
  } while (ppiVar23 != (int **)0x0);
  uVar26 = 0;
  ppcVar25 = DAT_0005ada0;
  goto LAB_0005a7d8;
  while( true ) {
    if (cVar1 != '\0') {
      (**ppcVar25)(ppiVar23[0xd]);
      ppiVar23[0xd] = (int *)0x0;
      *(undefined *)(ppiVar23 + 0xe) = 0;
    }
    ppiVar24 = ppiVar23 + 0x11;
    ppiVar23 = (int **)*ppiVar24;
    if ((int **)*ppiVar24 == (int **)0x0) break;
LAB_0005a9ac:
    if (*(char *)(ppiVar23 + 1) == '\0') {
      if (*(char *)(ppiVar23 + 4) != '\0') goto LAB_0005a9c2;
LAB_0005a998:
      if (*(char *)(ppiVar23 + 9) != '\0') goto LAB_0005a9d4;
LAB_0005a99e:
      cVar1 = *(char *)(ppiVar23 + 0xe);
    }
    else {
      (**ppcVar25)(*ppiVar23);
      *ppiVar23 = (int *)0x0;
      *(undefined *)(ppiVar23 + 1) = 0;
      if (*(char *)(ppiVar23 + 4) == '\0') goto LAB_0005a998;
LAB_0005a9c2:
      (**ppcVar25)(ppiVar23[3]);
      ppiVar23[3] = (int *)0x0;
      *(undefined *)(ppiVar23 + 4) = 0;
      if (*(char *)(ppiVar23 + 9) == '\0') goto LAB_0005a99e;
LAB_0005a9d4:
      (**ppcVar25)(ppiVar23[8]);
      cVar1 = *(char *)(ppiVar23 + 0xe);
      ppiVar23[8] = (int *)0x0;
      *(undefined *)(ppiVar23 + 9) = 0;
    }
  }
  goto LAB_0005a7d8;
switchD_0005a72c_caseD_3:
  if (ppiVar24[2] != (int *)0x0) {
LAB_0005a768:
    uVar26 = 2;
    ppcVar25 = DAT_0005a98c;
    goto LAB_0005a788;
  }
  piVar16 = piVar28;
  if (!bVar3) {
    piVar16 = *ppiVar23;
    ppiVar23 = ppiVar23 + 1;
  }
  ppiVar24[2] = piVar16;
  goto LAB_0005a708;
LAB_0005a788:
  do {
    if (*(char *)(ppiVar21 + 1) == '\0') {
      if (*(char *)(ppiVar21 + 4) != '\0') goto LAB_0005a79e;
LAB_0005a776:
      if (*(char *)(ppiVar21 + 9) != '\0') goto LAB_0005a7b0;
LAB_0005a77c:
      if (*(char *)(ppiVar21 + 0xe) != '\0') goto LAB_0005a7c4;
LAB_0005a782:
      ppiVar23 = ppiVar21 + 0x11;
      ppiVar21 = (int **)*ppiVar23;
      if ((int **)*ppiVar23 == (int **)0x0) break;
      goto LAB_0005a788;
    }
    (**ppcVar25)(*ppiVar21);
    *ppiVar21 = (int *)0x0;
    *(undefined *)(ppiVar21 + 1) = 0;
    if (*(char *)(ppiVar21 + 4) == '\0') goto LAB_0005a776;
LAB_0005a79e:
    (**ppcVar25)(ppiVar21[3]);
    ppiVar21[3] = (int *)0x0;
    *(undefined *)(ppiVar21 + 4) = 0;
    if (*(char *)(ppiVar21 + 9) == '\0') goto LAB_0005a77c;
LAB_0005a7b0:
    (**ppcVar25)(ppiVar21[8]);
    ppiVar21[8] = (int *)0x0;
    *(undefined *)(ppiVar21 + 9) = 0;
    if (*(char *)(ppiVar21 + 0xe) == '\0') goto LAB_0005a782;
LAB_0005a7c4:
    (**ppcVar25)(ppiVar21[0xd]);
    ppiVar21[0xd] = (int *)0x0;
    *(undefined *)(ppiVar21 + 0xe) = 0;
    ppiVar23 = ppiVar21 + 0x11;
    ppiVar21 = (int **)*ppiVar23;
  } while ((int **)*ppiVar23 != (int **)0x0);
LAB_0005a7d8:
  do {
    ppiVar6 = (int **)ppiVar6[0x11];
    (**ppcVar25)();
  } while (ppiVar6 != (int **)0x0);
  return uVar26;
}

