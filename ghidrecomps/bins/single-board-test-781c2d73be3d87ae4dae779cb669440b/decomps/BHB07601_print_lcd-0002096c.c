
/* WARNING: Unknown calling convention */

void BHB07601_print_lcd(uint result)

{
  int iVar1;
  char *buf;
  bad_chip *pbVar2;
  int iVar3;
  uint uVar4;
  char badchip_info [16];
  
  display_level_result_on_lcd();
  badchip_info._0_4_ = *DAT_00020af4;
  badchip_info._4_4_ = DAT_00020af4[1];
  badchip_info._8_4_ = DAT_00020af4[2];
  badchip_info._12_4_ = DAT_00020af4[3];
  if ((result & 8) == 0) {
    pbVar2 = &gBad_Chip;
    badchip_info[0] = ' ';
    badchip_info[1] = ' ';
    badchip_info[2] = ' ';
    badchip_info[3] = ' ';
    badchip_info[4] = ' ';
    badchip_info[5] = ' ';
    badchip_info[6] = ' ';
    badchip_info[7] = ' ';
    badchip_info[8] = ' ';
    badchip_info[9] = ' ';
    badchip_info[10] = ' ';
    badchip_info[11] = ' ';
    badchip_info[12] = ' ';
    badchip_info[13] = ' ';
    badchip_info[14] = ' ';
    badchip_info[15] = ' ';
    printf("BadChip Num=%2d ",gBad_Chip.total_badchip);
    sprintf(badchip_info,"BadChip Num=%2d ",gBad_Chip.total_badchip);
    write_lcd_no_memset(1,badchip_info,0x10);
    iVar3 = 0;
    do {
      printf("%2d-%4d  %2d-%4d\n",pbVar2->idx[0],pbVar2->nonce_num[0],pbVar2->idx[1],
             pbVar2->nonce_num[1]);
      uVar4 = pbVar2->idx[0];
      badchip_info[0] = ' ';
      badchip_info[1] = ' ';
      badchip_info[2] = ' ';
      badchip_info[3] = ' ';
      badchip_info[4] = ' ';
      badchip_info[5] = ' ';
      badchip_info[6] = ' ';
      badchip_info[7] = ' ';
      badchip_info[8] = ' ';
      badchip_info[9] = ' ';
      badchip_info[10] = ' ';
      badchip_info[11] = ' ';
      badchip_info[12] = ' ';
      badchip_info[13] = ' ';
      badchip_info[14] = ' ';
      badchip_info[15] = ' ';
      if (uVar4 != 0) {
        if (pbVar2->idx[1] == 0) {
          sprintf(badchip_info,"%2d-%4d ",uVar4,pbVar2->nonce_num[0]);
        }
        else {
          sprintf(badchip_info,"%2d-%4d %2d-%4d ",uVar4,pbVar2->nonce_num[0],pbVar2->idx[1],
                  pbVar2->nonce_num[1]);
        }
      }
      iVar1 = iVar3 >> 1;
      iVar3 = iVar3 + 2;
      write_lcd_no_memset(iVar1 + 2,badchip_info,0x10);
      pbVar2 = (bad_chip *)(pbVar2->idx + 1);
    } while (iVar3 != 4);
    pattern_test_time = '\0';
    return;
  }
  puts("Bad Chip Check OK\n");
  if ((int)(result << 0x1f) < 0) {
    write_lcd_no_memset(1,"   Pattern OK   ",0x10);
    pattern_test_time = '\0';
  }
  else {
    write_lcd_no_memset(1,"   Pattern NG   ",0x10);
    pattern_test_time = pattern_test_time + '\x01';
  }
  if ((int)(result << 0x1e) < 0) {
    buf = "   Sensor OK    ";
  }
  else {
    buf = "   Sensor NG    ";
  }
  write_lcd_no_memset(2,buf,0x10);
  if (gEEPROM_error == false) {
    write_lcd_no_memset(3,"   EEPROM OK   ",0x10);
    return;
  }
  write_lcd_no_memset(3,"   EEPROM NG   ",0x10);
  return;
}

