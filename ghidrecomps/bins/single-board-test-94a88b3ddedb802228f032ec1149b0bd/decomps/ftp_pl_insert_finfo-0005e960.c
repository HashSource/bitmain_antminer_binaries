
undefined4 ftp_pl_insert_finfo(int *param_1,int *param_2)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  code *pcVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  
  iVar6 = *param_1;
  iVar3 = param_2[0xf];
  piVar7 = *(int **)(iVar6 + 0x86e8);
  iVar8 = *(int *)(iVar6 + 0x86e4);
  iVar4 = *piVar7;
  iVar1 = *(int *)(iVar4 + 0x24);
  *param_2 = iVar3 + *(int *)(iVar4 + 0x1c);
  iVar9 = iVar3 + iVar1;
  if (iVar1 == 0) {
    iVar9 = 0;
  }
  iVar1 = *(int *)(iVar4 + 0x2c);
  param_2[0xc] = iVar9;
  iVar9 = iVar3 + iVar1;
  if (iVar1 == 0) {
    iVar9 = 0;
  }
  iVar1 = *(int *)(iVar4 + 0x30);
  param_2[10] = iVar9;
  iVar9 = iVar3 + iVar1;
  if (iVar1 == 0) {
    iVar9 = 0;
  }
  iVar1 = *(int *)(iVar4 + 0x28);
  iVar4 = *(int *)(iVar4 + 0x20);
  param_2[0xd] = iVar9;
  param_2[9] = iVar3 + iVar1;
  iVar3 = iVar3 + iVar4;
  if (iVar4 == 0) {
    iVar3 = 0;
  }
  pcVar5 = *(code **)(iVar6 + 0x420);
  param_2[0xb] = iVar3;
  if (pcVar5 == (code *)0x0) {
    pcVar5 = (code *)0x601b5;
  }
  iVar9 = (*pcVar5)(*(undefined4 *)(iVar6 + 0x424),*(undefined4 *)(iVar6 + 0x86e0));
  if ((iVar9 == 0) &&
     (((param_2[1] != 2 || ((char *)param_2[0xd] == (char *)0x0)) ||
      (pcVar2 = strstr((char *)param_2[0xd]," -> "), pcVar2 == (char *)0x0)))) {
    iVar9 = Curl_llist_insert_next(iVar8,*(undefined4 *)(iVar8 + 4),param_2);
    if (iVar9 == 0) {
      Curl_fileinfo_dtor(0,param_2);
      *(undefined4 *)(*piVar7 + 0x10) = 0;
      return 0x1b;
    }
  }
  else {
    Curl_fileinfo_dtor(0,param_2);
  }
  *(undefined4 *)(*piVar7 + 0x10) = 0;
  return 0;
}

