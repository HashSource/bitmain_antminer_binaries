
_Bool check_pt2_success(eeprom_v1 *efd)

{
  eeprom_v1 *efd_local;
  
  return (efd->data).field_2.raw[0x59] == '\x01';
}

