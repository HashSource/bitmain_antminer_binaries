
undefined4
getBoardTestVoltageAndFreqForS11LowPowerMode
          (undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  double dVar2;
  
  switch(param_1) {
  case 0:
    dVar2 = (double)get_fixed_voltage();
    *param_2 = (int)(longlong)(dVar2 * DAT_00026f00);
    *param_3 = 0x43;
    uVar1 = 0;
    break;
  case 1:
    dVar2 = (double)get_fixed_voltage();
    *param_2 = (int)(longlong)(dVar2 * DAT_00026f00);
    *param_3 = 0x42;
    uVar1 = 0;
    break;
  case 2:
    dVar2 = (double)get_fixed_voltage();
    *param_2 = (int)(longlong)(dVar2 * DAT_00026f00);
    *param_3 = 0x40;
    uVar1 = 0;
    break;
  case 3:
    dVar2 = (double)get_fixed_voltage();
    *param_2 = (int)(longlong)(dVar2 * DAT_00026f00);
    *param_3 = 0x3f;
    uVar1 = 0;
    break;
  default:
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

