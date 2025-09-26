
/* WARNING: Unknown calling convention */

int run_sweep_test_after_PT2_test(void)

{
  _Bool _Var1;
  int iVar2;
  char time_stamp [48];
  char tmp1 [2048];
  
  _Var1 = easy_check_base_PT2_result((uint)gPattern_test_counter);
  if (_Var1) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Base PT2 is OK,continue run sweep test...\n","run_sweep_test_after_PT2_test");
    builtin_strncpy(tmp1,"Base PT2 is OK,continue run sweep test...",0x2a);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Base PT2 is ok,still run sweep test to matche lowest level\n",
           "run_sweep_test_after_PT2_test");
    builtin_strncpy(tmp1,"Base PT2 is ok,still run sweep test to matche lowest lev",0x38);
    tmp1[0x38] = 'e';
    tmp1[0x39] = 'l';
    tmp1[0x3a] = '\0';
    log_to_file(tmp1,time_stamp);
    gPattern_test_counter = (char)gTest_loop + 0xff;
    iVar2 = run_sweep_test_after_by_PT2_info(-1);
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Base PT2 is Error, run sweep test to matche lowest level\n",
           "run_sweep_test_after_PT2_test");
    builtin_strncpy(tmp1,"Base PT2 is Error, run sweep test to matche lowest level",0x38);
    tmp1._56_2_ = (ushort)(byte)tmp1[0x39] << 8;
    log_to_file(tmp1,time_stamp);
    gPattern_test_counter = (char)gTest_loop + 0xff;
    iVar2 = run_sweep_test_after_by_PT2_info(-1);
  }
  return iVar2;
}

