
/* WARNING: Unknown calling convention */

int32_t hal_fan_number(void)

{
  int iVar1;
  bitmain_fan_id_e bVar2;
  fan_conf_info *pfVar3;
  
  pfVar3 = fans;
  bVar2 = FAN1;
  iVar1 = 0;
  while( true ) {
    if (bVar2 != ~FAN1) {
      iVar1 = iVar1 + 1;
    }
    if (pfVar3 == fans + 5) break;
    pfVar3 = pfVar3 + 1;
    bVar2 = pfVar3->fan_id;
  }
  return iVar1;
}

