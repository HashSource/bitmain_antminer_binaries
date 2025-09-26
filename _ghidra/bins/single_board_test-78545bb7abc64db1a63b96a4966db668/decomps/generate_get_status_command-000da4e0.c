
/* WARNING: Unknown calling convention */

int32_t generate_get_status_command
                  (uint8_t mode,uint32_t which_asic_address,uint32_t register_address,
                  get_status_t *command)

{
  byte bVar1;
  int32_t iVar2;
  
  if (command == (get_status_t *)0x0) {
    iVar2 = -1;
  }
  else {
    if (mode != '\0') {
      mode = 1;
    }
    iVar2 = 0;
    (command->u)._REGADDR = '\0';
    command->v[4] = '\0';
    command->v[0] = (mode & 1) << 4 | 0x42;
    (command->u)._ADDR = (uint8_t)which_asic_address;
    (command->u)._REGADDR = (uint8_t)register_address;
    (command->u)._Length = '\x05';
    bVar1 = ASIC_CRC5(command->v,0x20);
    command->v[4] = command->v[4] & 0xe0 | bVar1 & 0x1f;
  }
  return iVar2;
}

