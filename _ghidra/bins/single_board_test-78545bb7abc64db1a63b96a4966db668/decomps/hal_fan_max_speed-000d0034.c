
/* WARNING: Unknown calling convention */

int32_t hal_fan_max_speed(bitmain_fan_id_e id)

{
  bitmain_fan_id_e *pbVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = 0;
  do {
    pbVar1 = (bitmain_fan_id_e *)((int)&fans[0].fan_id + iVar3);
    iVar3 = iVar3 + 0xc;
    if (*pbVar1 == id) {
      return fans[iVar2].max_speed;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 6);
  return -1;
}

