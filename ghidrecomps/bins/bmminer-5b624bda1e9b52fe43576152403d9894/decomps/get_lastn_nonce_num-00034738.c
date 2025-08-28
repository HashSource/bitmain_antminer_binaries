
/* WARNING: Unknown calling convention */

void get_lastn_nonce_num(char *dest,int n)

{
  byte bVar1;
  int iVar2;
  size_t sVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  char tmp [20];
  char xtime [2048];
  
  iVar5 = 1;
  do {
    while( true ) {
      iVar2 = iVar5 + 1;
      iVar8 = iVar5 + -1;
      if (dev->chain_exist[iVar5 + -1] == 0) break;
      iVar9 = 0;
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
      tmp[0xb] = '\0';
      tmp[0xc] = '\0';
      tmp[0xd] = '\0';
      tmp[0xe] = '\0';
      tmp[0xf] = '\0';
      tmp[0x10] = '\0';
      tmp[0x11] = '\0';
      tmp[0x12] = '\0';
      tmp[0x13] = '\0';
      tmp[0] = '\0';
      tmp[1] = '\0';
      tmp[2] = '\0';
      tmp[3] = '\0';
      sprintf(tmp,"Chain%d:{",iVar5);
      sVar3 = strlen(xtime);
      pcVar4 = stpcpy(xtime + sVar3,tmp);
      if (0 < n) {
        iVar9 = 0;
        iVar7 = nonce_times % 0x3c + -1;
        iVar5 = iVar7 - n;
        do {
          iVar6 = iVar7;
          if (iVar7 < 0) {
            iVar6 = iVar7 + 0x3c;
          }
          iVar7 = iVar7 + -1;
          iVar9 = iVar9 + (int)nonce_num[iVar8][0][iVar6];
        } while (iVar7 != iVar5);
      }
      sprintf(tmp,"N%d=%d",0,iVar9);
      strcpy(pcVar4,tmp);
      bVar1 = dev->max_asic_num_in_one_chain;
      if (1 < bVar1) {
        iVar8 = iVar8 * 0xf;
      }
      if (1 < bVar1) {
        uVar10 = (uint)(1 < bVar1);
        do {
          if (n < 1) {
            iVar5 = 0;
          }
          else {
            iVar5 = 0;
            iVar9 = nonce_times % 0x3c + -1;
            iVar7 = iVar9 - n;
            do {
              iVar6 = iVar9;
              if (iVar9 < 0) {
                iVar6 = iVar9 + 0x3c;
              }
              iVar9 = iVar9 + -1;
              iVar5 = iVar5 + *(int *)((int)nonce_num[0] +
                                      (iVar6 + iVar8 * 0x100 + uVar10 * 0x3c) * 8);
            } while (iVar9 != iVar7);
          }
          uVar11 = uVar10 + 1;
          sprintf(tmp,",N%d=%d",uVar10,iVar5);
          strcat(xtime,tmp);
          uVar10 = uVar11;
        } while ((int)uVar11 < (int)(uint)dev->max_asic_num_in_one_chain);
      }
      sVar3 = strlen(xtime);
      pcVar4 = xtime + sVar3;
      pcVar4[0] = '}';
      pcVar4[1] = ',';
      xtime[sVar3 + 2] = '\0';
      strcat(dest,xtime);
      iVar5 = iVar2;
      if (iVar2 == 0x11) goto LAB_000348cc;
    }
    iVar5 = iVar2;
  } while (iVar2 != 0x11);
LAB_000348cc:
  sVar3 = strlen(dest);
  dest[sVar3 - 1] = '\0';
  return;
}

