
undefined4 Curl_smtp_escape_eob(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  bool bVar12;
  int local_30;
  int local_2c;
  
  iVar11 = *param_1;
  iVar8 = *(int *)(iVar11 + 0x14c);
  local_2c = *(int *)(iVar11 + 0x85c4);
  if ((local_2c == 0) || (*(char *)(iVar11 + 0x24e) != '\0')) {
    iVar1 = (*Curl_cmalloc)(0x8000);
    local_30 = iVar1;
    if (iVar1 == 0) {
      Curl_failf(iVar11,"Failed to alloc scratch buffer!");
      return 0x1b;
    }
  }
  else {
    iVar1 = local_2c;
    local_30 = 0;
    local_2c = 0;
  }
  iVar9 = *(int *)(iVar8 + 0xc);
  if (param_2 < 1) {
    iVar6 = 0;
  }
  else {
    iVar6 = 0;
    iVar5 = 0;
    iVar10 = iVar9;
    do {
      while( true ) {
        iVar2 = *(int *)(iVar11 + 0x144);
        cVar3 = *(char *)(iVar2 + iVar5);
        if ((&DAT_001397c4)[iVar9] == cVar3) break;
        if (iVar9 == 0) {
LAB_00052890:
          *(char *)(iVar1 + iVar6) = cVar3;
          iVar6 = iVar6 + 1;
          iVar9 = *(int *)(iVar8 + 0xc);
        }
        else {
          iVar7 = iVar6 - iVar10;
          memcpy((void *)(iVar1 + iVar6),&DAT_001397c4 + iVar10,iVar9 - iVar10);
          iVar2 = *(int *)(iVar11 + 0x144);
          iVar10 = 0;
          iVar4 = *(int *)(iVar8 + 0xc);
          iVar6 = iVar7 + iVar4;
          bVar12 = *(char *)(iVar2 + iVar5) == '\r';
          if (bVar12) {
            iVar4 = 1;
            iVar9 = 0xd;
          }
          else {
            iVar9 = 0;
          }
          if (bVar12) {
            *(int *)(iVar8 + 0xc) = iVar4;
            iVar9 = iVar4;
          }
          if (!bVar12) {
            *(int *)(iVar8 + 0xc) = iVar9;
          }
          *(undefined1 *)(iVar8 + 0x10) = 0;
LAB_000528c6:
          if (iVar9 == 0) {
            cVar3 = *(char *)(iVar2 + iVar5);
            goto LAB_00052890;
          }
        }
        iVar5 = iVar5 + 1;
        iVar2 = iVar10;
        if (iVar5 == param_2) goto LAB_00052914;
      }
      iVar9 = iVar9 + 1;
      *(int *)(iVar8 + 0xc) = iVar9;
      *(bool *)(iVar8 + 0x10) = iVar9 == 2 || iVar9 == 5;
      if (iVar9 != 3) goto LAB_000528c6;
      iVar5 = iVar5 + 1;
      memcpy((void *)(iVar1 + iVar6),&DAT_00139ab4 + iVar10,4 - iVar10);
      iVar6 = iVar6 - iVar10;
      iVar10 = 0;
      iVar2 = 0;
      iVar6 = iVar6 + 4;
      *(undefined4 *)(iVar8 + 0xc) = 0;
      iVar9 = 0;
    } while (iVar5 != param_2);
LAB_00052914:
    if (iVar2 != iVar9) {
      memcpy((void *)(iVar1 + iVar6),&DAT_001397c4 + iVar2,iVar9 - iVar2);
      iVar6 = (iVar6 - iVar2) + *(int *)(iVar8 + 0xc);
    }
  }
  if (iVar6 == param_2) {
    (*Curl_cfree)(local_30);
  }
  else {
    *(int *)(iVar11 + 0x85c4) = iVar1;
    *(int *)(iVar11 + 0x144) = iVar1;
    (*Curl_cfree)(local_2c);
    *(int *)(iVar11 + 0x140) = iVar6;
  }
  return 0;
}

