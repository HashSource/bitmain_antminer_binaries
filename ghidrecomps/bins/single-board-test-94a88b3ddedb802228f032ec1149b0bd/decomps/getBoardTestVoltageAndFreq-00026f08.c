
undefined4 getBoardTestVoltageAndFreq(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  double dVar2;
  
  switch(param_1) {
  case 0:
    dVar2 = (double)get_fixed_voltage();
    *param_2 = (int)(longlong)(dVar2 * DAT_000270d8);
    *param_3 = 0x5a;
    uVar1 = 0;
    break;
  case 1:
    dVar2 = (double)get_fixed_voltage();
    *param_2 = (int)(longlong)(dVar2 * DAT_000270d8);
    *param_3 = 0x56;
    uVar1 = 0;
    break;
  case 2:
    dVar2 = (double)get_fixed_voltage();
    *param_2 = (int)(longlong)(dVar2 * DAT_000270d8);
    *param_3 = 0x52;
    uVar1 = 0;
    break;
  case 3:
    dVar2 = (double)get_fixed_voltage();
    *param_2 = (int)(longlong)(dVar2 * DAT_000270d8);
    *param_3 = 0x4e;
    uVar1 = 0;
    break;
  case 4:
    dVar2 = (double)get_fixed_voltage();
    *param_2 = (int)(longlong)(dVar2 * DAT_000270d8);
    *param_3 = 0x4a;
    uVar1 = 0;
    break;
  case 5:
    dVar2 = (double)get_fixed_voltage();
    *param_2 = (int)(longlong)(dVar2 * DAT_000270d8);
    *param_3 = 0x46;
    uVar1 = 0;
    break;
  case 6:
    dVar2 = (double)get_fixed_voltage();
    *param_2 = (int)(longlong)(dVar2 * DAT_000270d8);
    *param_3 = 0x42;
    uVar1 = 0;
    break;
  case 7:
    dVar2 = (double)get_fixed_voltage();
    *param_2 = (int)(longlong)(dVar2 * DAT_000270d8);
    *param_3 = 0x3e;
    uVar1 = 0;
    break;
  case 8:
    dVar2 = (double)get_fixed_voltage();
    *param_2 = (int)(longlong)(dVar2 * DAT_000270d8);
    *param_3 = 0x3a;
    uVar1 = 0;
    break;
  case 9:
    dVar2 = (double)get_fixed_voltage();
    *param_2 = (int)(longlong)(dVar2 * DAT_000270d8);
    *param_3 = 0x34;
    uVar1 = 0;
    break;
  default:
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

