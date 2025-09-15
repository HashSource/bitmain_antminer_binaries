
undefined4
getBoardTestVoltageAndFreqForS11LowPowerMode
          (undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 extraout_s1;
  undefined4 extraout_s1_00;
  undefined4 extraout_s1_01;
  undefined4 extraout_s1_02;
  
  switch(param_1) {
  case 0:
    uVar1 = get_fixed_voltage();
    *param_2 = (int)(longlong)((double)CONCAT44(extraout_s1_02,uVar1) * 100.0);
    *param_3 = 0x43;
    uVar1 = 0;
    break;
  case 1:
    uVar1 = get_fixed_voltage();
    *param_2 = (int)(longlong)((double)CONCAT44(extraout_s1_01,uVar1) * 100.0);
    *param_3 = 0x42;
    uVar1 = 0;
    break;
  case 2:
    uVar1 = get_fixed_voltage();
    *param_2 = (int)(longlong)((double)CONCAT44(extraout_s1_00,uVar1) * 100.0);
    *param_3 = 0x40;
    uVar1 = 0;
    break;
  case 3:
    uVar1 = get_fixed_voltage();
    *param_2 = (int)(longlong)((double)CONCAT44(extraout_s1,uVar1) * 100.0);
    *param_3 = 0x3f;
    uVar1 = 0;
    break;
  default:
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

