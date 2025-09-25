
void eeprom_v1_set_sweep_freq(eeprom_v1 *eeprom,uint16_t *freqs,uint8_t num)

{
  byte bVar1;
  int iVar2;
  uint8_t num_local;
  uint16_t *freqs_local;
  eeprom_v1 *eeprom_local;
  uint8_t level;
  uint8_t i_1;
  uint8_t i;
  uint16_t freq_max;
  uint16_t freq_min;
  
  freq_min = 0xffff;
  freq_max = 0;
  for (i = '\0'; i < num; i = i + '\x01') {
    if (freq_max < freqs[i]) {
      freq_max = freqs[i];
    }
    if (freqs[i] < freq_min) {
      freq_min = freqs[i];
    }
  }
  (eeprom->data).field_2.format_v1.sweep.sweep_freq_base = freq_min;
  (eeprom->data).field_2.raw[0x66] = (char)((int)((uint)freq_max - (uint)freq_min) / 0xf) + '\x01';
  (eeprom->data).field_2.format_v1.sweep.sweep_hashrate = 0;
  memset((void *)((int)&(eeprom->data).field_2 + 0x67),0,0x80);
  for (i_1 = '\0'; i_1 < num; i_1 = i_1 + '\x01') {
    bVar1 = __aeabi_idiv(((uint)freqs[i_1] -
                         (uint)(eeprom->data).field_2.format_v1.sweep.sweep_freq_base) +
                         (uint)(eeprom->data).field_2.raw[0x66] + -1,
                         (eeprom->data).field_2.raw[0x66]);
    if ((i_1 & 1) == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = 4;
    }
    (eeprom->data).board_name[(i_1 >> 1) + 0x76] =
         (bVar1 & 0xf) << iVar2 | (eeprom->data).board_name[(i_1 >> 1) + 0x76];
    (eeprom->data).field_2.format_v1.sweep.sweep_hashrate =
         (ushort)(bVar1 & 0xf) * (ushort)(eeprom->data).field_2.raw[0x66] +
         (eeprom->data).field_2.format_v1.sweep.sweep_freq_base +
         (eeprom->data).field_2.format_v1.sweep.sweep_hashrate;
  }
  return;
}

