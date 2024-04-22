
/* WARNING: Unknown calling convention */

int get_works_v2(void)

{
  int iVar1;
  _Bool _Var2;
  uint uVar3;
  void *pvVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  void **ppvVar10;
  int iVar11;
  uint uVar12;
  void **ppvVar13;
  void **ppvVar14;
  char cVar15;
  char strFilePath [256];
  
  memset(strFilePath,0,0x100);
  printf("\n--- %s\n",DAT_00025a98);
  uVar3 = Conf.AsicNum;
  _Var2 = gHashBoard_BHB07601;
  if (Conf.AsicType == 0x1397) {
    if (gHashBoard_BHB07601 == false) {
      write_lcd(1,"   Board Name   ",0x10);
      write_lcd_no_memset(2,"      Error     ",0x10);
      printf("\n!!!%s: Board Name is: %s, error\n",DAT_00025a98,&Conf);
      iVar11 = -1;
    }
    else {
      sprintf(strFilePath,"%s%s.txt",DAT_00025a9c + -0x40);
      cgpu.fps[0] = (FILE *)fopen(strFilePath,"r");
      if (cgpu.fps[0] == (FILE *)0x0) {
        write_lcd(1,"   Get pattern  ",0x10);
        write_lcd_no_memset(2,"      Error     ",0x10);
        printf("%s: Open test file %s error\n",DAT_00025a98,strFilePath);
        iVar11 = -1;
      }
      else if (Conf.pattern_number < 9) {
        if (uVar3 == 0) {
          fclose((FILE *)cgpu.fps[0]);
          iVar9 = 0x330fc4;
          cgpu.min_work_subid = cgpu.subid[0];
          iVar11 = 0;
          uVar12 = cgpu.subid[0];
        }
        else {
          uVar12 = 0;
          ppvVar13 = DAT_00025aa4 + 0x80;
          ppvVar14 = DAT_00025aa4;
          do {
            uVar7 = Conf.pattern_number;
            pvVar4 = malloc(Conf.pattern_number * 0xb280);
            ppvVar14 = ppvVar14 + 1;
            *ppvVar14 = pvVar4;
            if (pvVar4 == (void *)0x0) {
              printf("%s: malloc struct work err!\n",DAT_00025a98);
              return -1;
            }
            iVar11 = 0;
            ppvVar10 = ppvVar13;
            do {
              iVar9 = iVar11 + 1;
              pvVar4 = (void *)get_work_hash_board(uVar12,iVar11,cgpu.fps[0],uVar7);
              uVar7 = Conf.pattern_number;
              ppvVar10 = ppvVar10 + 1;
              *ppvVar10 = pvVar4;
              skip_rows(cgpu.fps[0],8 - uVar7);
              uVar7 = Conf.pattern_number;
              iVar11 = iVar9;
            } while (iVar9 != 0x2a0);
            uVar12 = uVar12 + 1;
            ppvVar13 = ppvVar13 + 0x2a0;
          } while (uVar3 != uVar12);
          fclose((FILE *)cgpu.fps[0]);
          iVar1 = DAT_00025aa0;
          uVar12 = *(uint *)(DAT_00025aa0 + 0x2ac);
          iVar9 = DAT_00025aa0 + 0x80000;
          *(uint *)((int)gAsic_Core_Nonce_Num[0][0x4f] + DAT_00025aa0 + 0x468) = uVar12;
          if ((int)(uVar3 * 0x2a0) < 1) {
            iVar11 = 0;
          }
          else {
            puVar5 = (uint *)(iVar1 + 0x2ac);
            iVar8 = 0;
            iVar11 = 0;
            uVar7 = uVar12;
            cVar15 = '\0';
            while (iVar8 = iVar8 + 1, uVar3 * 0x2a0 - iVar8 != 0) {
              puVar5 = puVar5 + 1;
              uVar6 = *puVar5;
              if ((int)uVar6 < (int)uVar12) {
                uVar12 = uVar6;
                iVar11 = iVar8;
                uVar7 = uVar6;
                cVar15 = _Var2;
              }
            }
            if (cVar15 != '\0') {
              *(uint *)((int)gAsic_Core_Nonce_Num[0][0x4f] + iVar1 + 0x468) = uVar7;
            }
          }
        }
        if (uVar12 < Conf.pattern_number) {
          write_lcd(1,"Get Less Work",0xd);
          printf("%s: cgpu.subid[%d] = %d, is the least pattern number\n",DAT_00025a98,iVar11,
                 *(undefined4 *)(iVar9 + 0x2ac));
          iVar11 = -1;
        }
        else {
          iVar11 = 0;
        }
      }
      else {
        printf("%s: pattern_num %d too large\n",DAT_00025a98,Conf.pattern_number);
        iVar11 = -1;
      }
    }
  }
  else {
    write_lcd(0," AsicType Error ",0x10);
    printf("\n!!!%s: AsicType error\n",DAT_00025a98);
    iVar11 = -1;
  }
  return iVar11;
}

