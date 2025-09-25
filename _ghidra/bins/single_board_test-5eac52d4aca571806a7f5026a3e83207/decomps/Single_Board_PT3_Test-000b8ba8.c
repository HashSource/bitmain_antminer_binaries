
/* WARNING: Unknown calling convention */

int Single_Board_PT3_Test(void)

{
  int iVar1;
  
  set_sweep_err_state(0,true);
  bitmain_power_off();
  Single_Board_PT2_Software_Pattern_Test();
  sleep(2);
  iVar1 = run_sweep_test_after_PT2_test();
  return iVar1;
}

