
undefined4 ftp_pl_insert_finfo(int *param_1,int *param_2)

{
  code *pcVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  
  iVar7 = *param_1;
  iVar4 = param_2[0xf];
  piVar8 = *(int **)(iVar7 + 0x86e8);
  iVar9 = *(int *)(iVar7 + 0x86e4);
  iVar5 = *piVar8;
  iVar2 = *(int *)(iVar5 + 0x24);
  *param_2 = iVar4 + *(int *)(iVar5 + 0x1c);
  iVar10 = iVar4 + iVar2;
  if (iVar2 == 0) {
    iVar10 = 0;
  }
  iVar2 = *(int *)(iVar5 + 0x2c);
  param_2[0xc] = iVar10;
  iVar10 = iVar4 + iVar2;
  if (iVar2 == 0) {
    iVar10 = 0;
  }
  iVar2 = *(int *)(iVar5 + 0x30);
  param_2[10] = iVar10;
  iVar10 = iVar4 + iVar2;
  if (iVar2 == 0) {
    iVar10 = 0;
  }
  iVar2 = *(int *)(iVar5 + 0x28);
  iVar5 = *(int *)(iVar5 + 0x20);
  param_2[0xd] = iVar10;
  param_2[9] = iVar4 + iVar2;
  pcVar1 = DAT_0005ea20;
  iVar4 = iVar4 + iVar5;
  if (iVar5 == 0) {
    iVar4 = 0;
  }
  pcVar6 = *(code **)(iVar7 + 0x420);
  param_2[0xb] = iVar4;
  if (pcVar6 == (code *)0x0) {
    pcVar6 = pcVar1;
  }
  iVar10 = (*pcVar6)(*(undefined4 *)(iVar7 + 0x424),*(undefined4 *)(iVar7 + 0x86e0));
  if ((iVar10 == 0) &&
     (((param_2[1] != 2 || ((char *)param_2[0xd] == (char *)0x0)) ||
      (pcVar3 = strstr((char *)param_2[0xd],DAT_0005ea1c), pcVar3 == (char *)0x0)))) {
    iVar10 = Curl_llist_insert_next(iVar9,*(undefined4 *)(iVar9 + 4),param_2);
    if (iVar10 == 0) {
      Curl_fileinfo_dtor(0,param_2);
      *(undefined4 *)(*piVar8 + 0x10) = 0;
      return 0x1b;
    }
  }
  else {
    Curl_fileinfo_dtor(0,param_2);
  }
  *(undefined4 *)(*piVar8 + 0x10) = 0;
  return 0;
}

