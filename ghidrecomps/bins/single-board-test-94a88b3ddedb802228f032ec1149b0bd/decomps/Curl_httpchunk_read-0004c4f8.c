
/* WARNING: Type propagation algorithm not settling */

undefined4 Curl_httpchunk_read(int *param_1,byte *param_2,uint param_3,int *param_4)

{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  uint extraout_r1;
  uint uVar4;
  int iVar5;
  byte bVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  bool bVar11;
  bool bVar12;
  longlong lVar13;
  undefined8 uVar14;
  char *apcStack_2c [2];
  
  iVar10 = *param_1;
  uVar3 = (uint)*(byte *)(iVar10 + 0x330);
  uVar9 = (int)param_3 >> 0x1f;
  *param_4 = 0;
  if ((uVar3 != 0) && (*(char *)(iVar10 + 0x135) == '\0')) {
    uVar14 = Curl_client_write(param_1,1,param_2,param_3);
    uVar3 = (uint)((ulonglong)uVar14 >> 0x20);
    if ((int)uVar14 != 0) {
      return 4;
    }
  }
LAB_0004c52c:
  if ((param_3 | uVar9) == 0) {
    return 0;
  }
  switch(param_1[8]) {
  case 0:
    bVar6 = *param_2;
    uVar1 = (uint)bVar6;
    uVar3 = uVar1 - 0x30;
    bVar11 = 8 < uVar3;
    bVar12 = uVar3 == 9;
    if (9 < uVar3) {
      bVar11 = 4 < uVar1 - 0x41;
      bVar12 = uVar1 - 0x41 == 5;
    }
    if (bVar11 && !bVar12) {
      uVar3 = 0;
    }
    if ((bVar11 && !bVar12) && (5 < uVar1 - 0x61)) {
      if (param_1[7] != 0) {
        *(char *)((int)param_1 + param_1[7] + 8) = (char)uVar3;
        lVar13 = strtoll((char *)(param_1 + 2),apcStack_2c,0x10);
        uVar3 = (uint)((ulonglong)lVar13 >> 0x20);
        *(longlong *)(param_1 + 10) = lVar13;
        if ((uVar3 != 0x7fffffff || (int)lVar13 != -1) ||
           (piVar2 = __errno_location(), uVar3 = extraout_r1, *piVar2 != 0x22)) {
          param_1[8] = 1;
          goto LAB_0004c52c;
        }
      }
      return 2;
    }
    iVar7 = param_1[7];
    if (0xf < iVar7) {
      return 1;
    }
    uVar3 = (int)param_1 + iVar7;
    bVar12 = param_3 != 0;
    param_3 = param_3 - 1;
    param_2 = param_2 + 1;
    uVar9 = (uVar9 - 1) + (uint)bVar12;
    *(byte *)(uVar3 + 8) = bVar6;
    param_1[7] = iVar7 + 1;
    goto LAB_0004c52c;
  case 1:
    if (*param_2 == 10) {
      bVar12 = (param_1[10] | param_1[0xb]) == 0;
      if (bVar12) {
        iVar7 = 0;
        uVar3 = 5;
      }
      else {
        iVar7 = 2;
      }
      if (bVar12) {
        param_1[8] = uVar3;
      }
      if (bVar12) {
        param_1[0xef] = iVar7;
      }
      if (!bVar12) {
        param_1[8] = iVar7;
      }
    }
    break;
  case 2:
    uVar4 = param_1[10];
    uVar8 = param_1[0xb];
    uVar1 = param_3;
    uVar3 = uVar9;
    if ((int)((uVar8 - uVar9) - (uint)(uVar4 < param_3)) < 0 !=
        (SBORROW4(uVar8,uVar9) != SBORROW4(uVar8 - uVar9,(uint)(uVar4 < param_3)))) {
      uVar1 = uVar4;
      uVar3 = uVar8;
    }
    uVar1 = curlx_sotouz(uVar1,uVar3);
    if (*(char *)(*param_1 + 0x331) == '\0') {
      iVar7 = *(int *)(iVar10 + 0xdc);
      if (iVar7 == 1) {
        *(byte **)(iVar10 + 0xac) = param_2;
        iVar7 = Curl_unencode_deflate_write(param_1,iVar10 + 0x50,uVar1);
      }
      else {
        if (iVar7 != 2) {
          if (iVar7 != 0) {
            Curl_failf(*param_1,DAT_0004c854);
            return 5;
          }
          goto LAB_0004c62a;
        }
        *(byte **)(iVar10 + 0xac) = param_2;
        iVar7 = Curl_unencode_gzip_write(param_1,iVar10 + 0x50,uVar1);
      }
joined_r0x0004c7ce:
      if (iVar7 != 0) {
        return 4;
      }
    }
    else {
LAB_0004c62a:
      if ((*(char *)(iVar10 + 0x135) == '\0') && (*(char *)(iVar10 + 0x330) == '\0')) {
        iVar7 = Curl_client_write(param_1,1,param_2,uVar1);
        goto joined_r0x0004c7ce;
      }
    }
    param_2 = param_2 + uVar1;
    uVar4 = param_1[10] - uVar1;
    uVar3 = param_1[0xb] - (uint)((uint)param_1[10] < uVar1);
    bVar12 = param_3 < uVar1;
    param_3 = param_3 - uVar1;
    uVar9 = uVar9 - bVar12;
    iVar7 = *param_4;
    *param_4 = iVar7 + uVar1;
    bVar12 = (uVar4 | uVar3) == 0;
    if (bVar12) {
      iVar7 = 3;
    }
    param_1[10] = uVar4;
    param_1[0xb] = uVar3;
    if (bVar12) {
      param_1[8] = iVar7;
    }
    goto LAB_0004c52c;
  case 3:
    if (*param_2 == 10) {
      param_1[7] = 0;
      param_1[0xc] = 0;
      param_1[8] = 0;
    }
    else if (*param_2 != 0xd) {
      return 3;
    }
    break;
  case 4:
    if (*param_2 != 10) {
      return 3;
    }
    iVar10 = curlx_sotouz(param_3 - 1,(uVar9 - 1) + (uint)(param_3 != 0));
    param_1[0xc] = iVar10;
    return 0xffffffff;
  case 5:
    bVar6 = *param_2;
    if (bVar6 == 0xd || bVar6 == 10) {
      iVar7 = param_1[0xef];
      if (iVar7 == 0) {
        param_1[8] = 7;
        goto LAB_0004c52c;
      }
      *(undefined *)(param_1[0xed] + iVar7) = 0xd;
      uVar3 = 0;
      *(undefined *)(param_1[0xed] + iVar7 + 1) = 10;
      param_1[0xef] = iVar7 + 2;
      *(undefined *)(param_1[0xed] + iVar7 + 2) = 0;
      if (*(char *)(iVar10 + 0x330) == '\0') {
        uVar14 = Curl_client_write(param_1,2,param_1[0xed],param_1[0xef]);
        uVar3 = (uint)((ulonglong)uVar14 >> 0x20);
        if ((int)uVar14 != 0) {
          return 4;
        }
      }
      param_1[0xef] = 0;
      param_1[8] = 6;
      if (*param_2 == 10) goto LAB_0004c52c;
    }
    else {
      iVar5 = param_1[0xef];
      iVar7 = param_1[0xee];
      if (iVar5 < iVar7) {
        iVar7 = param_1[0xed];
      }
      else {
        if (iVar7 == 0) {
          param_1[0xee] = 0x80;
          iVar7 = (*Curl_cmalloc)(0x83);
        }
        else {
          param_1[0xee] = iVar7 * 2;
          iVar7 = (*Curl_crealloc)(param_1[0xed],iVar7 * 2 + 3);
        }
        if (iVar7 == 0) {
          return 6;
        }
        param_1[0xed] = iVar7;
        iVar5 = param_1[0xef];
        bVar6 = *param_2;
      }
      uVar3 = iVar5 + 1;
      *(byte *)(iVar7 + iVar5) = bVar6;
      param_1[0xef] = uVar3;
    }
    break;
  case 6:
    if (*param_2 != 10) {
      return 3;
    }
    param_1[8] = 7;
    break;
  case 7:
    goto switchD_0004c53c_caseD_7;
  }
  bVar12 = param_3 != 0;
  param_3 = param_3 - 1;
  param_2 = param_2 + 1;
  uVar9 = (uVar9 - 1) + (uint)bVar12;
  goto LAB_0004c52c;
switchD_0004c53c_caseD_7:
  bVar6 = *param_2;
  if (bVar6 != 10 && bVar6 != 0xd) {
    uVar3 = 5;
  }
  if (bVar6 != 10 && bVar6 != 0xd) {
    param_1[8] = uVar3;
  }
  else {
    if (bVar6 == 0xd) {
      bVar12 = param_3 != 0;
      param_3 = param_3 - 1;
      param_2 = param_2 + 1;
      uVar9 = (uVar9 - 1) + (uint)bVar12;
    }
    param_1[8] = 4;
  }
  goto LAB_0004c52c;
}

