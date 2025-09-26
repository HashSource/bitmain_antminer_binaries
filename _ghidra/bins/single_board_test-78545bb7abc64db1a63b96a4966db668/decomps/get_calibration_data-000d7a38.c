
/* WARNING: Unknown calling convention */

_Bool get_calibration_data(char *bf,int *size)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  bool bVar5;
  bool bVar6;
  
  uVar3 = _g_calibration_data._12_4_;
  uVar2 = _g_calibration_data._8_4_;
  uVar1 = _g_calibration_data._4_4_;
  iVar4 = *size;
  bVar5 = (int)bf < 0;
  bVar6 = bf != (char *)0x0;
  if (bVar6) {
    bVar5 = iVar4 + -0x1f < 0;
  }
  if ((bVar6 && iVar4 != 0x1f) && bVar5 == (bVar6 && SBORROW4(iVar4,0x1f))) {
    *(undefined4 *)bf = _g_calibration_data._0_4_;
    *(undefined4 *)(bf + 4) = uVar1;
    *(undefined4 *)(bf + 8) = uVar2;
    *(undefined4 *)(bf + 0xc) = uVar3;
    uVar3 = _g_calibration_data._28_4_;
    uVar2 = _g_calibration_data._24_4_;
    uVar1 = _g_calibration_data._20_4_;
    *(undefined4 *)(bf + 0x10) = _g_calibration_data._16_4_;
    *(undefined4 *)(bf + 0x14) = uVar1;
    *(undefined4 *)(bf + 0x18) = uVar2;
    *(undefined4 *)(bf + 0x1c) = uVar3;
    *size = 0x20;
    return true;
  }
  return false;
}

