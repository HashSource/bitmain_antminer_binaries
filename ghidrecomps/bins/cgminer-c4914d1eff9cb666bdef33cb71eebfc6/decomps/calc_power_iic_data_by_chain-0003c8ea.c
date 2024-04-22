
/* WARNING: Variable defined which should be unmapped: target_vol-local */

void calc_power_iic_data_by_chain(power_info_t *power,double target_vol)

{
  uint uVar1;
  char cVar2;
  uint8_t uVar3;
  char cVar4;
  byte bVar5;
  int iVar6;
  double in_d0;
  double target_vol_local;
  power_info_t *power_local;
  uint8_t threshold_iic_data;
  uint8_t target_iic_data;
  uint8_t diff_iic_data;
  uint8_t data;
  int negate;
  int index;
  
  index = 0;
  data = get_power_iic_value_from_voltage(in_d0);
  bVar5 = get_power_iic_value_from_voltage(in_d0);
  uVar1 = (int)((uint)data - (uint)bVar5) >> 0x1f;
  iVar6 = ((uint)data - (uint)bVar5 ^ uVar1) - uVar1;
  cVar2 = (char)((ulonglong)((longlong)iVar6 * 0x2aaaaaab) >> 0x20) - (char)(iVar6 >> 0x1f);
  if (power->current_voltage < in_d0) {
    negate = -1;
  }
  else {
    negate = 1;
  }
  if (negate == -1) {
    power->iic_data[0] = bVar5;
    power->iic_data_index = '\0';
  }
  else {
    for (; cVar4 = (char)negate, index < 5; index = index + 1) {
      data = data + cVar2 * cVar4;
      power->iic_data[index] = data;
      power->iic_data_index = (uint8_t)index;
      if (cVar2 == '\0') break;
    }
    while( true ) {
      while( true ) {
        iVar6 = (uint)data - (uint)bVar5;
        if (iVar6 < 0) {
          iVar6 = -iVar6;
        }
        if ((byte)iVar6 < 0x21) {
          if ((byte)iVar6 < 0x11) {
            diff_iic_data = '\x02';
          }
          else {
            diff_iic_data = '\b';
          }
        }
        else {
          diff_iic_data = '\x10';
        }
        iVar6 = (uint)data - (uint)bVar5;
        if (iVar6 < 0) {
          iVar6 = -iVar6;
        }
        uVar3 = (uint8_t)index;
        if (iVar6 < 3) break;
        data = data + diff_iic_data * cVar4;
        power->iic_data[index] = data;
        power->iic_data_index = uVar3;
        index = index + 1;
      }
      iVar6 = (uint)data - (uint)bVar5;
      if (iVar6 < 0) {
        iVar6 = -iVar6;
      }
      if (iVar6 < 2) break;
      data = data + cVar4;
      power->iic_data[index] = data;
      power->iic_data_index = uVar3;
      index = index + 1;
    }
    power->iic_data[index] = bVar5;
    power->iic_data_index = uVar3;
  }
  return;
}

