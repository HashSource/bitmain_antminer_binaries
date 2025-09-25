
/* WARNING: Unknown calling convention */

int32_t generate_set_address_command(uint32_t which_asic_address,set_address_t *command)

{
  byte bVar1;
  int32_t iVar2;
  
  if (command == (set_address_t *)0x0) {
    iVar2 = -1;
  }
  else {
    iVar2 = 0;
    *(undefined4 *)command = 0;
    command->v[4] = '\0';
    (command->u)._ADDR = (uint8_t)which_asic_address;
    (command->u)._Length = '\x05';
    command->v[0] = '@';
    bVar1 = ASIC_CRC5(command->v,0x20);
    command->v[4] = command->v[4] & 0xe0 | bVar1 & 0x1f;
  }
  return iVar2;
}

