
/* WARNING: Unknown calling convention */

uint8_t fan_get_fan_id_pcb(bitmain_fan_id_e id)

{
  uint8_t uVar1;
  
  uVar1 = hal_get_fan_id_pcb(id);
  return uVar1;
}

