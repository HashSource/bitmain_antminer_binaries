
/* WARNING: Unknown calling convention */

int32_t generate_chain_inactive_command(chain_inactive_t *command)

{
  byte bVar1;
  int32_t iVar2;
  
  if (command == (chain_inactive_t *)0x0) {
    iVar2 = -1;
  }
  else {
    iVar2 = 0;
    (command->u)._RSVD1 = '\0';
    (command->u)._RSVD2 = '\0';
    command->v[4] = '\0';
    command->v[0] = 'S';
    (command->u)._Length = '\x05';
    bVar1 = ASIC_CRC5(command->v,0x20);
    command->v[4] = command->v[4] & 0xe0 | bVar1 & 0x1f;
  }
  return iVar2;
}

