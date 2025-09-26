
void lcd_common_show(char *line1,char *line2,char *line3)

{
  char *line3_local;
  char *line2_local;
  char *line1_local;
  
  lcd_clear_result();
  lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
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

