
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
  char *__dest_00;
  char local_83c [2072];
  
  iVar7 = 1;
  do {
    while( true ) {
      iVar3 = iVar7 + 1;
      if (*(int *)(dev + iVar3 * 4) == 0) break;
      __dest_00 = local_83c + 0x14;
      local_83c[0x14] = '{';
      local_83c[0x15] = '\0';
      local_83c[0x16] = '\0';
      local_83c[0x17] = '\0';
      iVar8 = 0;
      memset(local_83c + 0x18,0,0x7fc);
      local_83c[0] = '\0';
      local_83c[1] = '\0';
      local_83c[2] = '\0';
      local_83c[3] = '\0';
      local_83c[4] = '\0';
      local_83c[5] = '\0';
      local_83c[6] = '\0';
      local_83c[7] = '\0';
      local_83c[8] = '\0';
      local_83c[9] = '\0';
      local_83c[10] = '\0';
      local_83c[0xb] = '\0';
      local_83c[0xc] = '\0';
      local_83c[0xd] = '\0';
      local_83c[0xe] = '\0';
      local_83c[0xf] = '\0';
      local_83c[0x10] = '\0';
      local_83c[0x11] = '\0';
      local_83c[0x12] = '\0';
      local_83c[0x13] = '\0';
      sprintf(local_83c,"Chain%d:{",iVar7);
      __dest = stpcpy(local_83c + 0x15,local_83c);
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
      sprintf(local_83c,"N%d=%d",0,iVar8);
      strcpy(__dest,local_83c);
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
          sprintf(local_83c,",N%d=%d",iVar8,iVar1);
          strcat(__dest_00,local_83c);
          iVar8 = iVar8 + 1;
        } while (iVar8 < (int)(uint)*(byte *)(dev + 0x542e));
      }
      sVar2 = strlen(__dest_00);
      (__dest_00 + sVar2)[0] = '}';
      (__dest_00 + sVar2)[1] = ',';
      local_83c[sVar2 + 0x16] = '\0';
      strcat(param_1,__dest_00);
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

