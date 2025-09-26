
/* WARNING: Unknown calling convention */

_Bool save_software_commit_id(void)

{
  bool bVar1;
  char time_stamp [48];
  char tmp1 [2048];
  
  zhiju_software_commit_id = (char *)malloc(0x2d);
  bVar1 = zhiju_software_commit_id != (char *)0x0;
  if (bVar1) {
    memset(zhiju_software_commit_id,0,0x2d);
    substr("version: 2cbff4a193ca16eb0aa2363a52d8e76db948458d commit: 2023-08-02 15:03:49 build: 2023-08-02 15:04:56"
           ,9,0x28,zhiju_software_commit_id);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: software_commit_id: %s\n","save_software_commit_id",zhiju_software_commit_id);
    snprintf(tmp1,0x800,"software_commit_id: %s",zhiju_software_commit_id);
    log_to_file(tmp1,time_stamp);
  }
  else {
    lcd_clear_result();
    lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
    lcd_show(1,"malloc for");
    lcd_show(2,"commit id");
    lcd_show(3,"fail");
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: malloc for commit id fail\n","save_software_commit_id");
    builtin_strncpy(tmp1,"malloc for commit id fai",0x18);
    tmp1[0x18] = 'l';
    tmp1[0x19] = '\0';
    log_to_file(tmp1,time_stamp);
  }
  return bVar1;
}

