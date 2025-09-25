
void eeprom_v1_get_sweep_freq
               (eeprom_v1 *eeprom,uint16_t *freqs,uint16_t *freq_min,uint16_t *freq_max,uint8_t num)

{
  ushort uVar1;
  int iVar2;
  uint16_t *freq_max_local;
  uint16_t *freq_min_local;
  uint16_t *freqs_local;
  eeprom_v1 *eeprom_local;
  uint16_t freq;
  uint8_t level;
  uint8_t i;
  
  *freq_min = 0xffff;
  *freq_max = 0;
  for (i = '\0'; i < num; i = i + '\x01') {
    if ((i & 1) == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = 4;
    }
    uVar1 = ((ushort)((int)(uint)(byte)(eeprom->data).board_name[(i >> 1) + 0x76] >> iVar2) & 0xf) *
            (ushort)(eeprom->data).field_2.raw[0x66] +
            (eeprom->data).field_2.format_v1.sweep.sweep_freq_base;
    if (*freq_max < uVar1) {
      *freq_max = uVar1;
    }
    if (uVar1 < *freq_min) {
      *freq_min = uVar1;
    }
    freqs[i] = uVar1;
  }
  return;
}

