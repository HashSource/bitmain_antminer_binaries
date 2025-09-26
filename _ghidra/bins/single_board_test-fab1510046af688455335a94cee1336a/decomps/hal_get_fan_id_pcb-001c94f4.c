
/* WARNING: Unknown calling convention */

uint8_t hal_get_fan_id_pcb(bitmain_fan_id_e id)

{
  return "\x01\x02\x03\x04"[id];
}

