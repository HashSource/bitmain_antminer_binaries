
undefined4 getBoardTestVoltageAndFreq(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 extraout_s1;
  undefined4 extraout_s1_00;
  undefined4 extraout_s1_01;
  undefined4 extraout_s1_02;
  undefined4 extraout_s1_03;
  undefined4 extraout_s1_04;
  undefined4 extraout_s1_05;
  undefined4 extraout_s1_06;
  undefined4 extraout_s1_07;
  undefined4 extraout_s1_08;
  
  switch(param_1) {
  case 0:
    uVar1 = get_fixed_voltage();
    *param_2 = (int)(longlong)((double)CONCAT44(extraout_s1_08,uVar1) * 100.0);
    *param_3 = 0x5a;
    uVar1 = 0;
    break;
  case 1:
    uVar1 = get_fixed_voltage();
    *param_2 = (int)(longlong)((double)CONCAT44(extraout_s1_07,uVar1) * 100.0);
    *param_3 = 0x56;
    uVar1 = 0;
    break;
  case 2:
    uVar1 = get_fixed_voltage();
    *param_2 = (int)(longlong)((double)CONCAT44(extraout_s1_06,uVar1) * 100.0);
    *param_3 = 0x52;
    uVar1 = 0;
    break;
  case 3:
    uVar1 = get_fixed_voltage();
    *param_2 = (int)(longlong)((double)CONCAT44(extraout_s1_05,uVar1) * 100.0);
    *param_3 = 0x4e;
    uVar1 = 0;
    break;
  case 4:
    uVar1 = get_fixed_voltage();
    *param_2 = (int)(longlong)((double)CONCAT44(extraout_s1_04,uVar1) * 100.0);
    *param_3 = 0x4a;
    uVar1 = 0;
    break;
  case 5:
    uVar1 = get_fixed_voltage();
    *param_2 = (int)(longlong)((double)CONCAT44(extraout_s1_03,uVar1) * 100.0);
    *param_3 = 0x46;
    uVar1 = 0;
    break;
  case 6:
    uVar1 = get_fixed_voltage();
    *param_2 = (int)(longlong)((double)CONCAT44(extraout_s1_02,uVar1) * 100.0);
    *param_3 = 0x42;
    uVar1 = 0;
    break;
  case 7:
    uVar1 = get_fixed_voltage();
    *param_2 = (int)(longlong)((double)CONCAT44(extraout_s1_01,uVar1) * 100.0);
    *param_3 = 0x3e;
    uVar1 = 0;
    break;
  case 8:
    uVar1 = get_fixed_voltage();
    *param_2 = (int)(longlong)((double)CONCAT44(extraout_s1_00,uVar1) * 100.0);
    *param_3 = 0x3a;
    uVar1 = 0;
    break;
  case 9:
    uVar1 = get_fixed_voltage();
    *param_2 = (int)(longlong)((double)CONCAT44(extraout_s1,uVar1) * 100.0);
    *param_3 = 0x34;
    uVar1 = 0;
    break;
  default:
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

