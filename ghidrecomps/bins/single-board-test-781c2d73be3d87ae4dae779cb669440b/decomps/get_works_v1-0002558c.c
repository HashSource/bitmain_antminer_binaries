
/* WARNING: Unknown calling convention */

int get_works_v1(void)

{
  void *pvVar1;
  FILE *stream;
  work *pwVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  cgpu_info *pcVar8;
  int iVar9;
  uint uVar10;
  work **ppwVar11;
  uint uVar12;
  bool bVar13;
  void **local_13c;
  cgpu_info *local_138;
  uint local_12c;
  char strFilePath [256];
  
  memset(strFilePath,0,0x100);
  printf("\n--- %s\n",DAT_00025834);
  if (Conf.AsicType == 0x569) {
    uVar12 = 0x32;
  }
  else if (Conf.AsicType - 0x3657 < 2) {
    uVar12 = 0x100;
  }
  else {
    if (Conf.AsicType != 0x1397) {
      write_lcd(0," AsicType Error ",0x10);
      printf("\n!!!%s: AsicType error\n",DAT_00025834);
      return -1;
    }
    uVar12 = 0x2a0;
  }
  if (gHashBoard_V9 == false) {
    if ((gHashBoard_BHB91601P == false) && (gHashBoard_BHB91601S == false)) {
      if (gHashBoard_BHB07601 == false) {
        write_lcd(1,"   Board Name   ",0x10);
        write_lcd_no_memset(2,"      Error     ",0x10);
        printf("\n!!!%s: Board Name is: %s, error\n",DAT_00025834,&Conf);
        return -1;
      }
      local_12c = BHB07601_ASIC_NUMBER;
    }
    else {
      local_12c = BHB91601_ASIC_NUMBER;
    }
    if (local_12c == 0) goto LAB_0002569e;
  }
  else {
    local_12c = 0x2d;
  }
  uVar10 = 0;
  local_13c = DAT_00025838;
  local_138 = &cgpu;
  do {
    pvVar1 = malloc(uVar12 * Conf.pattern_number * 0x44);
    local_13c = local_13c + 1;
    *local_13c = pvVar1;
    if (pvVar1 == (void *)0x0) {
      printf("%s: malloc struct work err!\n",DAT_00025834);
      return -1;
    }
    ppwVar11 = local_138->works + 0x7f;
    uVar6 = 0;
    pcVar8 = local_138;
    do {
      sprintf(strFilePath,"%s%02i%s%03i.txt",DAT_0002583c + -0x40,uVar10,DAT_0002583c,uVar6);
      stream = fopen(strFilePath,"r");
      pcVar8->fps[0] = (FILE *)stream;
      uVar7 = uVar6 + 1;
      if (stream == (FILE *)0x0) {
        write_lcd(1,"   Get pattern  ",0x10);
        write_lcd_no_memset(2,"      Error     ",0x10);
        printf("%s: Open test file %s error\n",DAT_00025834,strFilePath);
        return -1;
      }
      pwVar2 = (work *)get_work_hash_board(uVar10,uVar6,(FILE *)stream,Conf.pattern_number);
      ppwVar11 = ppwVar11 + 1;
      *ppwVar11 = pwVar2;
      fclose((FILE *)pcVar8->fps[0]);
      uVar6 = uVar7;
      pcVar8 = (cgpu_info *)(pcVar8->fps + 1);
    } while (uVar7 < uVar12);
    uVar10 = uVar10 + 1;
    local_138 = (cgpu_info *)(local_138->fps + uVar12);
  } while (uVar10 < local_12c);
LAB_0002569e:
  iVar3 = DAT_00025840;
  uVar10 = *(uint *)(DAT_00025840 + 0x2ac);
  bVar13 = Conf.AsicNum == 1;
  *(uint *)((int)gAsic_Core_Nonce_Num[0][0x4f] + DAT_00025840 + 0x468) = uVar10;
  if ((bVar13) || ((int)(local_12c * uVar12) < 1)) {
    iVar9 = 0;
  }
  else {
    bVar13 = false;
    puVar4 = (uint *)(iVar3 + 0x2ac);
    iVar5 = 0;
    iVar9 = 0;
    uVar6 = uVar10;
    while (iVar5 = iVar5 + 1, local_12c * uVar12 - iVar5 != 0) {
      puVar4 = puVar4 + 1;
      uVar7 = *puVar4;
      if ((int)uVar7 < (int)uVar10) {
        bVar13 = true;
        uVar10 = uVar7;
        iVar9 = iVar5;
        uVar6 = uVar7;
      }
    }
    if (bVar13) {
      *(uint *)((int)gAsic_Core_Nonce_Num[0][0x4f] + iVar3 + 0x468) = uVar6;
    }
  }
  if (uVar10 < Conf.pattern_number) {
    write_lcd(1,"Get Less Work",0xd);
    printf("%s: cgpu.subid[%d] = %d, is the least pattern number\n",DAT_00025834,iVar9,
           *(undefined4 *)((int)gAsic_Core_Nonce_Num[0][0x4f] + iVar3 + 0x468));
    iVar3 = -1;
  }
  else {
    iVar3 = 0;
  }
  return iVar3;
}

