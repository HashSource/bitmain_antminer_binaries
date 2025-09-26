
/* WARNING: Unknown calling convention */

_Bool check_whether_hashboard_plug_in_again(void)

{
  undefined1 uVar1;
  char time_stamp [48];
  char tmp1 [2048];
  _Bool former_plug_in_status;
  
  former_plug_in_status = check_chain_plug_status();
  if (former_plug_in_status) {
    while (former_plug_in_status != false) {
      former_plug_in_status = check_chain_plug_status();
    }
    while (uVar1 = gHashBoard_plug_in_again, former_plug_in_status != true) {
      former_plug_in_status = check_chain_plug_status();
      gHashBoard_plug_in_again = true;
    }
  }
  else {
    lcd_clear_result();
    lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
    lcd_show(1,"plug off");
    lcd_show(2,"befor test done");
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: plug off hashboard befor test done\n","check_whether_hashboard_plug_in_again");
    builtin_strncpy(tmp1,"plug off hashboard befor test do",0x20);
    tmp1[0x20] = 'n';
    tmp1[0x21] = 'e';
    tmp1[0x22] = '\0';
    log_to_file(tmp1,time_stamp);
    uVar1 = 0;
  }
  return (_Bool)uVar1;
}

