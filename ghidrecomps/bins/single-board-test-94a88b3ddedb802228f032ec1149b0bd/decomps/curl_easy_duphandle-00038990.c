
int curl_easy_duphandle(int param_1)

{
  undefined1 uVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar3 = (*Curl_ccalloc)(1,0x87a0);
  if (iVar3 == 0) {
    return 0;
  }
  iVar4 = (*Curl_cmalloc)(0x100);
  *(int *)(iVar3 + 0x594) = iVar4;
  if (iVar4 != 0) {
    *(undefined4 *)(iVar3 + 0x598) = 0x100;
    iVar4 = Curl_dupset(iVar3,param_1);
    if (iVar4 == 0) {
      uVar5 = *(undefined4 *)(param_1 + 0x4a8);
      uVar1 = *(undefined1 *)(param_1 + 0x4a0);
      iVar4 = *(int *)(param_1 + 0x468);
      *(undefined4 *)(iVar3 + 0x580) = 0;
      *(undefined4 *)(iVar3 + 0x590) = 0;
      *(undefined4 *)(iVar3 + 0x4a8) = uVar5;
      *(undefined1 *)(iVar3 + 0x4a0) = uVar1;
      if (iVar4 != 0) {
        iVar4 = Curl_cookie_init(param_1,*(undefined4 *)(iVar4 + 4),*(undefined4 *)(iVar3 + 0x468),
                                 *(undefined1 *)(param_1 + 0x24d));
        *(int *)(iVar3 + 0x468) = iVar4;
        if (iVar4 == 0) goto LAB_00038a4e;
      }
      if (*(int *)(param_1 + 0x460) != 0) {
        iVar4 = Curl_slist_duplicate();
        *(int *)(iVar3 + 0x460) = iVar4;
        if (iVar4 == 0) goto LAB_00038a52;
      }
      if (*(int *)(param_1 + 0x450) != 0) {
        iVar4 = (*Curl_cstrdup)();
        *(int *)(iVar3 + 0x450) = iVar4;
        if (iVar4 == 0) goto LAB_00038a4e;
        *(undefined1 *)(iVar3 + 0x454) = 1;
      }
      if (*(int *)(param_1 + 0x458) == 0) {
LAB_00038a3a:
        *(undefined4 *)(iVar3 + 0x879c) = 0xc0dedbad;
        return iVar3;
      }
      iVar4 = (*Curl_cstrdup)();
      *(int *)(iVar3 + 0x458) = iVar4;
      if (iVar4 != 0) {
        *(undefined1 *)(iVar3 + 0x45c) = 1;
        goto LAB_00038a3a;
      }
    }
  }
LAB_00038a4e:
  iVar4 = *(int *)(iVar3 + 0x460);
LAB_00038a52:
  curl_slist_free_all(iVar4);
  *(undefined4 *)(iVar3 + 0x460) = 0;
  (*Curl_cfree)(*(undefined4 *)(iVar3 + 0x594));
  *(undefined4 *)(iVar3 + 0x594) = 0;
  (*Curl_cfree)(*(undefined4 *)(iVar3 + 0x450));
  pcVar2 = Curl_cfree;
  *(undefined4 *)(iVar3 + 0x450) = 0;
  (*pcVar2)(*(undefined4 *)(iVar3 + 0x458));
  *(undefined4 *)(iVar3 + 0x458) = 0;
  Curl_freeset(iVar3);
  (*Curl_cfree)(iVar3);
  return 0;
}

