
/* WARNING: Unknown calling convention */

int32_t hal_fan_addr(bitmain_fan_id_e id)

{
  fan_conf_info *pfVar1;
  int iVar2;
  
  pfVar1 = fans;
  iVar2 = 0;
  if (id != FAN1) {
    do {
      iVar2 = iVar2 + 1;
      if (iVar2 == 6) {
        return -2;
      }
      pfVar1 = pfVar1 + 1;
    } while (pfVar1->fan_id != id);
  }
  return fans[iVar2].fan_name;
}

