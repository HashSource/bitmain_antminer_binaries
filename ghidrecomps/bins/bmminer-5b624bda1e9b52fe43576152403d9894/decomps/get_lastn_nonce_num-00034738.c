
/* WARNING: Unknown calling convention */

void get_lastn_nonce_num(char *dest,int n)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  size_t sVar5;
  char *__dest;
  int iVar6;
  int iVar7;
  int iVar8;
  int index;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  char tmp [20];
  char xtime [2048];
  
  piVar3 = DAT_00034900;
  iVar2 = DAT_000348fc;
  iVar9 = DAT_000348fc + 0x680;
  iVar6 = 1;
  do {
    while( true ) {
      iVar4 = iVar6 + 1;
      iVar10 = iVar6 + -1;
      if (*(int *)(*piVar3 + iVar4 * 4) == 0) break;
      iVar11 = 0;
      xtime[0] = '{';
      xtime[1] = '\0';
      xtime[2] = '\0';
      xtime[3] = '\0';
      memset(xtime + 4,0,0x7fc);
      tmp[4] = '\0';
      tmp[5] = '\0';
      tmp[6] = '\0';
      tmp[7] = '\0';
      tmp[8] = '\0';
      tmp[9] = '\0';
      tmp[10] = '\0';
      tmp[11] = '\0';
      tmp[12] = '\0';
      tmp[13] = '\0';
      tmp[14] = '\0';
      tmp[15] = '\0';
      tmp[16] = '\0';
      tmp[17] = '\0';
      tmp[18] = '\0';
      tmp[19] = '\0';
      tmp[0] = '\0';
      tmp[1] = '\0';
      tmp[2] = '\0';
      tmp[3] = '\0';
      sprintf(tmp,DAT_000348f0,iVar6);
      sVar5 = strlen(xtime);
      __dest = stpcpy(xtime + sVar5,tmp);
      if (0 < n) {
        iVar11 = 0;
        iVar8 = *(int *)(iVar2 + 0x678) % 0x3c + -1;
        iVar6 = iVar8 - n;
        do {
          iVar7 = iVar8;
          if (iVar8 < 0) {
            iVar7 = iVar8 + 0x3c;
          }
          iVar8 = iVar8 + -1;
          iVar11 = iVar11 + *(int *)(iVar9 + (iVar7 + iVar10 * 0xf00) * 8);
        } while (iVar8 != iVar6);
      }
      sprintf(tmp,DAT_000348f4,0,iVar11);
      strcpy(__dest,tmp);
      bVar1 = *(byte *)(*piVar3 + 0x2fe9);
      if (1 < bVar1) {
        iVar10 = iVar10 * 0xf;
      }
      if (1 < bVar1) {
        uVar12 = (uint)(1 < bVar1);
        do {
          if (n < 1) {
            iVar6 = 0;
          }
          else {
            iVar6 = 0;
            iVar11 = *(int *)(iVar2 + 0x678) % 0x3c + -1;
            iVar8 = iVar11 - n;
            do {
              index = iVar11;
              if (iVar11 < 0) {
                index = iVar11 + 0x3c;
              }
              iVar11 = iVar11 + -1;
              iVar6 = iVar6 + *(int *)(iVar9 + (index + iVar10 * 0x100 + uVar12 * 0x3c) * 8);
            } while (iVar11 != iVar8);
          }
          uVar13 = uVar12 + 1;
          sprintf(tmp,DAT_000348f8,uVar12,iVar6);
          strcat(xtime,tmp);
          uVar12 = uVar13;
        } while ((int)uVar13 < (int)(uint)*(byte *)(*piVar3 + 0x2fe9));
      }
      sVar5 = strlen(xtime);
      *(undefined2 *)(xtime + sVar5) = DAT_00052854;
      xtime[sVar5 + 2] = DAT_00052856;
      strcat(dest,xtime);
      iVar6 = iVar4;
      if (iVar4 == 0x11) goto LAB_000348cc;
    }
    iVar6 = iVar4;
  } while (iVar4 != 0x11);
LAB_000348cc:
  sVar5 = strlen(dest);
  dest[sVar5 - 1] = '\0';
  return;
}

