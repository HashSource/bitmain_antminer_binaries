
void get_lastn_nonce_num(char *param_1,int param_2)

{
  char *__dest;
  int iVar1;
  size_t sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 local_83c;
  undefined4 local_838;
  undefined4 local_834;
  undefined4 local_830;
  undefined4 local_82c;
  undefined4 local_828;
  undefined auStack_824 [2048];
  
  iVar7 = 1;
  do {
    while( true ) {
      iVar3 = iVar7 + 1;
      if (*(int *)(dev + iVar3 * 4) == 0) break;
      local_828 = 0x7b;
      iVar8 = 0;
      memset(auStack_824,0,0x7fc);
      local_83c = 0;
      local_838 = 0;
      local_834 = 0;
      local_830 = 0;
      local_82c = 0;
      sprintf((char *)&local_83c,"Chain%d:{",iVar7);
      __dest = stpcpy((char *)((int)&local_828 + 1),(char *)&local_83c);
      if (0 < param_2) {
        iVar8 = 0;
        iVar6 = nonce_times % 0x3c + -1;
        iVar1 = iVar6 - param_2;
        do {
          iVar4 = iVar6;
          if (iVar6 < 0) {
            iVar4 = iVar6 + 0x3c;
          }
          iVar6 = iVar6 + -1;
          iVar8 = iVar8 + *(int *)(nonce_num + (iVar4 + (iVar7 + -1) * 0x1e00) * 8);
        } while (iVar6 != iVar1);
      }
      sprintf((char *)&local_83c,"N%d=%d",0,iVar8);
      strcpy(__dest,(char *)&local_83c);
      if (1 < *(byte *)(dev + 0x542e)) {
        iVar8 = 1;
        do {
          if (param_2 < 1) {
            iVar1 = 0;
          }
          else {
            iVar1 = 0;
            iVar4 = nonce_times % 0x3c + -1;
            iVar6 = iVar4 - param_2;
            do {
              iVar5 = iVar4;
              if (iVar4 < 0) {
                iVar5 = iVar4 + 0x3c;
              }
              iVar4 = iVar4 + -1;
              iVar1 = iVar1 + *(int *)(nonce_num +
                                      (iVar5 + (iVar7 + -1) * 0x1e00 + iVar8 * 0x3c) * 8);
            } while (iVar6 != iVar4);
          }
          sprintf((char *)&local_83c,",N%d=%d",iVar8,iVar1);
          strcat((char *)&local_828,(char *)&local_83c);
          iVar8 = iVar8 + 1;
        } while (iVar8 < (int)(uint)*(byte *)(dev + 0x542e));
      }
      sVar2 = strlen((char *)&local_828);
      *(undefined2 *)((int)&local_828 + sVar2) = DAT_000634dc;
      auStack_824[sVar2 - 2] = DAT_000634de;
      strcat(param_1,(char *)&local_828);
      iVar7 = iVar3;
      if (iVar3 == 0x11) goto LAB_00034f4a;
    }
    iVar7 = iVar3;
  } while (iVar3 != 0x11);
LAB_00034f4a:
  sVar2 = strlen(param_1);
  param_1[sVar2 - 1] = '\0';
  return;
}

