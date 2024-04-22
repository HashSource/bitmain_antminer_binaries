
undefined4 Curl_smtp_escape_eob(int *param_1,int param_2)

{
  code **ppcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  bool bVar14;
  int local_30;
  int local_2c;
  
  iVar13 = *param_1;
  iVar10 = *(int *)(iVar13 + 0x14c);
  local_2c = *(int *)(iVar13 + 0x85c4);
  if ((local_2c == 0) || (*(char *)(iVar13 + 0x24e) != '\0')) {
    iVar3 = (**DAT_000529a4)(0x8000);
    local_30 = iVar3;
    if (iVar3 == 0) {
      Curl_failf(iVar13,DAT_000529ac);
      return 0x1b;
    }
  }
  else {
    iVar3 = local_2c;
    local_30 = 0;
    local_2c = 0;
  }
  iVar2 = DAT_000529b0;
  iVar11 = *(int *)(iVar10 + 0xc);
  if (param_2 < 1) {
    iVar8 = 0;
  }
  else {
    iVar8 = 0;
    iVar7 = 0;
    iVar12 = iVar11;
    do {
      while( true ) {
        iVar4 = *(int *)(iVar13 + 0x144);
        cVar5 = *(char *)(iVar4 + iVar7);
        if (*(char *)(iVar2 + iVar11) == cVar5) break;
        if (iVar11 == 0) {
LAB_00052890:
          *(char *)(iVar3 + iVar8) = cVar5;
          iVar8 = iVar8 + 1;
          iVar11 = *(int *)(iVar10 + 0xc);
        }
        else {
          iVar9 = iVar8 - iVar12;
          memcpy((void *)(iVar3 + iVar8),&DAT_001397c4 + iVar12,iVar11 - iVar12);
          iVar4 = *(int *)(iVar13 + 0x144);
          iVar12 = 0;
          iVar6 = *(int *)(iVar10 + 0xc);
          iVar8 = iVar9 + iVar6;
          bVar14 = *(char *)(iVar4 + iVar7) == '\r';
          if (bVar14) {
            iVar6 = 1;
            iVar11 = 0xd;
          }
          else {
            iVar11 = 0;
          }
          if (bVar14) {
            *(int *)(iVar10 + 0xc) = iVar6;
            iVar11 = iVar6;
          }
          if (!bVar14) {
            *(int *)(iVar10 + 0xc) = iVar11;
          }
          *(undefined *)(iVar10 + 0x10) = 0;
LAB_000528c6:
          if (iVar11 == 0) {
            cVar5 = *(char *)(iVar4 + iVar7);
            goto LAB_00052890;
          }
        }
        iVar7 = iVar7 + 1;
        iVar4 = iVar12;
        if (iVar7 == param_2) goto LAB_00052914;
      }
      iVar11 = iVar11 + 1;
      *(int *)(iVar10 + 0xc) = iVar11;
      *(bool *)(iVar10 + 0x10) = iVar11 == 2 || iVar11 == 5;
      if (iVar11 != 3) goto LAB_000528c6;
      iVar7 = iVar7 + 1;
      memcpy((void *)(iVar3 + iVar8),&DAT_00139ab4 + iVar12,4 - iVar12);
      iVar8 = iVar8 - iVar12;
      iVar12 = 0;
      iVar4 = 0;
      iVar8 = iVar8 + 4;
      *(undefined4 *)(iVar10 + 0xc) = 0;
      iVar11 = 0;
    } while (iVar7 != param_2);
LAB_00052914:
    if (iVar4 != iVar11) {
      memcpy((void *)(iVar3 + iVar8),(void *)(iVar2 + iVar4),iVar11 - iVar4);
      iVar8 = (iVar8 - iVar4) + *(int *)(iVar10 + 0xc);
    }
  }
  ppcVar1 = DAT_000529a8;
  if (iVar8 == param_2) {
    (**DAT_000529a8)(local_30);
  }
  else {
    *(int *)(iVar13 + 0x85c4) = iVar3;
    *(int *)(iVar13 + 0x144) = iVar3;
    (**ppcVar1)(local_2c);
    *(int *)(iVar13 + 0x140) = iVar8;
  }
  return 0;
}

