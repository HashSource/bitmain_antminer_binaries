
void lcd_common_show(char *line1,char *line2,char *line3)

{
  Hash_Board *pHVar1;
  size_t sVar2;
  char *line3_local;
  char *line2_local;
  char *line1_local;
  int len;
  
  memset(lcd_common_show::version,0,0x10);
  pHVar1 = &Local_Config_Information->Hash_Board;
  sVar2 = strlen((Local_Config_Information->Hash_Board).Board_Name);
  strncpy(lcd_common_show::version,pHVar1->Board_Name,sVar2);
  sVar2 = strlen(lcd_common_show::version);
  (lcd_common_show::version + sVar2)[0] = '-';
  (lcd_common_show::version + sVar2)[1] = '\0';
  sVar2 = strlen(lcd_common_show::version);
  len = 0x10 - sVar2;
  if (6 < len) {
    len = 6;
  }
  sVar2 = strlen(lcd_common_show::version);
  substr("version: b2cb0052105c62c2efac09b2b5bd71d43bfe9a6d commit: 2025-07-16 10:46:54 build: 2025-07-16 10:47:05"
         ,9,len,lcd_common_show::version + sVar2);
  lcd_clear_result();
  lcd_show(0,lcd_common_show::version);
  if (line1 != (char *)0x0) {
    lcd_show(1,line1);
  }
  if (line2 != (char *)0x0) {
    lcd_show(2,line2);
  }
  if (line3 != (char *)0x0) {
    lcd_show(3,line3);
  }
  return;
}

