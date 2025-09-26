
void upload_repaire_info_after_test(uint32_t err_code,char *test_name)

{
  size_t __n;
  int iVar1;
  byte bVar2;
  uint32_t uVar3;
  char *test_name_local;
  uint32_t err_code_local;
  char time_stamp_1 [48];
  repaire_info_t m_repaire_info;
  char tmp1 [256];
  
  if ((Local_Config_Information->Repair_Mode).Enable_Repair != false) {
    print_time_stamp((char *)&m_repaire_info,0x30);
    printf("%s ",&m_repaire_info);
    printf("%s : err_code:%d\n","upload_repaire_info_after_test",err_code);
    snprintf(tmp1,0x100,"err_code:%d",err_code);
    log_to_file(tmp1,(char *)&m_repaire_info);
    lcd_common_show("Now upload","repaire info","pls wait.");
    memset(&m_repaire_info,0,0x88);
    __n = strlen(sn.board_sn);
    memcpy(m_repaire_info.sn,sn.board_sn,__n);
    err_code_local = err_code;
    if (0xfff < err_code) {
      print_time_stamp(time_stamp_1,0x30);
      printf("%s ",time_stamp_1);
      printf("%s : err_code:%d,err_info:%d\n","upload_repaire_info_after_test",err_code & 0xffff,
             err_code >> 0x10);
      snprintf(tmp1,0x100,"err_code:%d,err_info:%d",err_code & 0xffff,err_code >> 0x10);
      log_to_file(tmp1,time_stamp_1);
      err_code_local = err_code & 0xffff;
    }
    uVar3 = err_code_local;
    if (err_code_local != 0) {
      uVar3 = 1;
    }
    bVar2 = (byte)uVar3;
    if (err_code_local == 0) {
      bVar2 = 0;
    }
    m_repaire_info.err = (int)bVar2;
    if (m_repaire_info.err != 0) {
      if ((err_code_local & 0x200) != 0) {
        append_err_code(m_repaire_info.err_code,"FX11");
      }
      if ((err_code_local & 0x400) != 0) {
        append_err_code(m_repaire_info.err_code,"FX16");
      }
      if (((err_code_local & 2) != 0) || ((err_code_local & 4) != 0)) {
        append_err_code(m_repaire_info.err_code,"FX13");
      }
      if (((((err_code_local & 0x20) != 0) || ((err_code_local & 0x40) != 0)) ||
          ((err_code_local & 0x80) != 0)) || ((err_code_local & 0x100) != 0)) {
        append_err_code(m_repaire_info.err_code,"FX13");
      }
    }
    iVar1 = strncmp(test_name,"PT1new",6);
    if (iVar1 == 0) {
      m_repaire_info.test_process = 1;
    }
    else {
      iVar1 = strncmp(test_name,"PT2",3);
      if (((iVar1 == 0) || (iVar1 = strncmp(test_name,"PT3",3), iVar1 == 0)) ||
         (iVar1 = strncmp(test_name,"SWEEP",5), iVar1 == 0)) {
        m_repaire_info.test_process = 2;
      }
    }
    print_time_stamp(time_stamp_1,0x30);
    printf("%s ",time_stamp_1);
    printf("%s : sn:%s\nerr:%d\nerr_code:%s\ntest_name:%d\n\n","upload_repaire_info_after_test",
           m_repaire_info.sn,m_repaire_info.err,m_repaire_info.err_code,m_repaire_info.test_process)
    ;
    snprintf(tmp1,0x100,"sn:%s\nerr:%d\nerr_code:%s\ntest_name:%d\n",m_repaire_info.sn,
             m_repaire_info.err,m_repaire_info.err_code,m_repaire_info.test_process);
    log_to_file(tmp1,time_stamp_1);
    print_time_stamp(time_stamp_1,0x30);
    printf("%s ",time_stamp_1);
    printf("%s : start upload repaire data,\n","upload_repaire_info_after_test");
    builtin_strncpy(tmp1,"start upload repaire dat",0x18);
    tmp1[0x18] = 'a';
    tmp1[0x19] = ',';
    tmp1[0x1a] = '\0';
    log_to_file(tmp1,time_stamp_1);
    iVar1 = upload_repaire_data(&m_repaire_info);
    if (iVar1 == 0) {
      lcd_common_show("Upload fail","pls retry.",(char *)0x0);
    }
    else {
      lcd_common_show("Upload succ","pls check.",(char *)0x0);
    }
  }
  return;
}

