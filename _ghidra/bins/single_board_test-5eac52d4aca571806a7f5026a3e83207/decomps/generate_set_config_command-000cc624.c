
/* WARNING: Unknown calling convention */

int32_t generate_set_config_command
                  (uint8_t mode,uint32_t which_asic_address,uint32_t register_address,
                  uint32_t register_data,set_config_t *command)

{
  byte bVar1;
  int32_t iVar2;
  
  if (command == (set_config_t *)0x0) {
    iVar2 = -1;
  }
  else {
    iVar2 = 0;
    *(undefined4 *)command = 0;
    if (mode != '\0') {
      mode = 1;
    }
    (command->u)._REGDATA[3] = (uint8_t)register_data;
    (command->u)._ADDR = (uint8_t)which_asic_address;
    command->v[0] = (mode & 1) << 4 | 0x41;
    (command->u)._REGDATA[0] = (uint8_t)(register_data >> 0x18);
    (command->u)._REGDATA[2] = (uint8_t)(register_data >> 8);
    command->v[8] = '\0';
    (command->u)._REGADDR = (uint8_t)register_address;
    (command->u)._REGDATA[1] = (uint8_t)(register_data >> 0x10);
    (command->u)._Length = '\t';
    bVar1 = ASIC_CRC5(command->v,0x40);
    command->v[8] = command->v[8] & 0xe0 | bVar1 & 0x1f;
  }
  return iVar2;
}

