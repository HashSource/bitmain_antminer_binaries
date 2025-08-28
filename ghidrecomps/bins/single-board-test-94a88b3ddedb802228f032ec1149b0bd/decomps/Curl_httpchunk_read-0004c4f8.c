
/* WARNING: Type propagation algorithm not settling */

undefined4 Curl_httpchunk_read(int *param_1,byte *param_2,uint param_3,int *param_4)

{
  int *piVar1;
  uint uVar2;
  uint extraout_r1;
  uint uVar3;
  int iVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  bool bVar10;
  longlong lVar11;
  undefined8 uVar12;
  char *apcStack_2c [2];
  
  iVar8 = *param_1;
  uVar2 = (uint)*(byte *)(iVar8 + 0x330);
  iVar7 = (int)param_3 >> 0x1f;
  *param_4 = 0;
  if ((uVar2 != 0) && (*(char *)(iVar8 + 0x135) == '\0')) {
    uVar12 = Curl_client_write(param_1,1,param_2,param_3);
    uVar2 = (uint)((ulonglong)uVar12 >> 0x20);
    if ((int)uVar12 != 0) {
      return 4;
    }
  }
LAB_0004c52c:
  if (param_3 == 0 && iVar7 == 0) {
    return 0;
  }
switchD_0004c53c_switchD:
  switch(param_1[8]) {
  case 0:
    bVar5 = *param_2;
    uVar3 = (uint)bVar5;
    uVar2 = uVar3 - 0x30;
    bVar9 = 8 < uVar2;
    bVar10 = uVar2 == 9;
    if (9 < uVar2) {
      bVar9 = 4 < uVar3 - 0x41;
      bVar10 = uVar3 - 0x41 == 5;
    }
    if (bVar9 && !bVar10) {
      uVar2 = 0;
    }
    if ((bVar9 && !bVar10) && (5 < uVar3 - 0x61)) {
      if (param_1[7] != 0) {
        *(char *)((int)param_1 + param_1[7] + 8) = (char)uVar2;
        lVar11 = strtoll((char *)(param_1 + 2),apcStack_2c,0x10);
        uVar2 = (uint)((ulonglong)lVar11 >> 0x20);
        *(longlong *)(param_1 + 10) = lVar11;
        if ((lVar11 != 0x7fffffffffffffff) ||
           (piVar1 = __errno_location(), uVar2 = extraout_r1, *piVar1 != 0x22)) {
          param_1[8] = 1;
          goto LAB_0004c52c;
        }
      }
      return 2;
    }
    iVar6 = param_1[7];
    if (0xf < iVar6) {
      return 1;
    }
    uVar2 = (int)param_1 + iVar6;
    bVar10 = param_3 != 0;
    param_3 = param_3 - 1;
    param_2 = param_2 + 1;
    iVar7 = iVar7 + -1 + (uint)bVar10;
    *(byte *)(uVar2 + 8) = bVar5;
    param_1[7] = iVar6 + 1;
    goto LAB_0004c52c;
  case 1:
    if (*param_2 == 10) {
      bVar10 = param_1[10] == 0;
      bVar9 = param_1[0xb] == 0;
      if (bVar10 && bVar9) {
        iVar6 = 0;
        uVar2 = 5;
      }
      else {
        iVar6 = 2;
      }
      if (bVar10 && bVar9) {
        param_1[8] = uVar2;
      }
      if (bVar10 && bVar9) {
        param_1[0xef] = iVar6;
      }
      if (!bVar10 || !bVar9) {
        param_1[8] = iVar6;
      }
    }
    break;
  case 2:
    uVar3 = param_1[10];
    iVar4 = param_1[0xb];
    uVar2 = param_3;
    iVar6 = iVar7;
    if ((int)((iVar4 - iVar7) - (uint)(uVar3 < param_3)) < 0 !=
        (SBORROW4(iVar4,iVar7) != SBORROW4(iVar4 - iVar7,(uint)(uVar3 < param_3)))) {
      uVar2 = uVar3;
      iVar6 = iVar4;
    }
    uVar3 = curlx_sotouz(uVar2,iVar6);
    if (*(char *)(*param_1 + 0x331) == '\0') {
      iVar6 = *(int *)(iVar8 + 0xdc);
      if (iVar6 == 1) {
        *(byte **)(iVar8 + 0xac) = param_2;
        iVar6 = Curl_unencode_deflate_write(param_1,iVar8 + 0x50,uVar3);
      }
      else {
        if (iVar6 != 2) {
          if (iVar6 != 0) {
            Curl_failf(*param_1,
                       "Unrecognized content encoding type. libcurl understands `identity\', `deflate\' and `gzip\' content encodings."
                      );
            return 5;
          }
          goto LAB_0004c62a;
        }
        *(byte **)(iVar8 + 0xac) = param_2;
        iVar6 = Curl_unencode_gzip_write(param_1,iVar8 + 0x50,uVar3);
      }
joined_r0x0004c7ce:
      if (iVar6 != 0) {
        return 4;
      }
    }
    else {
LAB_0004c62a:
      if ((*(char *)(iVar8 + 0x135) == '\0') && (*(char *)(iVar8 + 0x330) == '\0')) {
        iVar6 = Curl_client_write(param_1,1,param_2,uVar3);
        goto joined_r0x0004c7ce;
      }
    }
    param_2 = param_2 + uVar3;
    iVar6 = param_1[10] - uVar3;
    uVar2 = param_1[0xb] - (uint)((uint)param_1[10] < uVar3);
    bVar10 = param_3 < uVar3;
    param_3 = param_3 - uVar3;
    iVar7 = iVar7 - (uint)bVar10;
    iVar4 = *param_4;
    *param_4 = iVar4 + uVar3;
    if (iVar6 == 0 && uVar2 == 0) {
      iVar4 = 3;
    }
    param_1[10] = iVar6;
    param_1[0xb] = uVar2;
    if (iVar6 == 0 && uVar2 == 0) {
      param_1[8] = iVar4;
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
    iVar7 = curlx_sotouz(param_3 - 1,iVar7 + -1 + (uint)(param_3 != 0));
    param_1[0xc] = iVar7;
    return 0xffffffff;
  case 5:
    bVar5 = *param_2;
    if (bVar5 == 0xd || bVar5 == 10) {
      iVar6 = param_1[0xef];
      if (iVar6 == 0) {
        param_1[8] = 7;
        goto LAB_0004c52c;
      }
      *(undefined1 *)(param_1[0xed] + iVar6) = 0xd;
      uVar2 = 0;
      *(undefined1 *)(param_1[0xed] + iVar6 + 1) = 10;
      param_1[0xef] = iVar6 + 2;
      *(undefined1 *)(param_1[0xed] + iVar6 + 2) = 0;
      if (*(char *)(iVar8 + 0x330) == '\0') {
        uVar12 = Curl_client_write(param_1,2,param_1[0xed],param_1[0xef]);
        uVar2 = (uint)((ulonglong)uVar12 >> 0x20);
        if ((int)uVar12 != 0) {
          return 4;
        }
      }
      param_1[0xef] = 0;
      param_1[8] = 6;
      if (*param_2 == 10) goto LAB_0004c52c;
    }
    else {
      iVar4 = param_1[0xef];
      iVar6 = param_1[0xee];
      if (iVar4 < iVar6) {
        iVar6 = param_1[0xed];
      }
      else {
        if (iVar6 == 0) {
          param_1[0xee] = 0x80;
          iVar6 = (*Curl_cmalloc)(0x83);
        }
        else {
          param_1[0xee] = iVar6 * 2;
          iVar6 = (*Curl_crealloc)(param_1[0xed],iVar6 * 2 + 3);
        }
        if (iVar6 == 0) {
          return 6;
        }
        param_1[0xed] = iVar6;
        iVar4 = param_1[0xef];
        bVar5 = *param_2;
      }
      uVar2 = iVar4 + 1;
      *(byte *)(iVar6 + iVar4) = bVar5;
      param_1[0xef] = uVar2;
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
  default:
    goto switchD_0004c53c_switchD;
  }
  bVar10 = param_3 != 0;
  param_3 = param_3 - 1;
  param_2 = param_2 + 1;
  iVar7 = iVar7 + -1 + (uint)bVar10;
  goto LAB_0004c52c;
switchD_0004c53c_caseD_7:
  bVar5 = *param_2;
  if (bVar5 != 10 && bVar5 != 0xd) {
    uVar2 = 5;
  }
  if (bVar5 != 10 && bVar5 != 0xd) {
    param_1[8] = uVar2;
  }
  else {
    if (bVar5 == 0xd) {
      bVar10 = param_3 != 0;
      param_3 = param_3 - 1;
      param_2 = param_2 + 1;
      iVar7 = iVar7 + -1 + (uint)bVar10;
    }
    param_1[8] = 4;
  }
  goto LAB_0004c52c;
}

