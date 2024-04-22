
void check_chain(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  char *pcVar6;
  
  *(undefined *)(dev + 0x53fd) = 0;
  iVar2 = get_hash_on_plug();
  if (iVar2 < 0) {
    if ((opt_debug != '\0') &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      check_chain_part_9();
      return;
    }
  }
  else {
    uVar4 = 0;
    pcVar6 = (char *)(dev + 0x53fd);
    puVar3 = (undefined4 *)(dev + 8);
    puVar5 = (undefined4 *)(dev + 8);
    do {
      uVar1 = uVar4 & 0xff;
      uVar4 = uVar4 + 1;
      if ((iVar2 >> uVar1 & 1U) == 0) {
        *puVar5 = 0;
      }
      else {
        *puVar3 = 1;
        *pcVar6 = *pcVar6 + '\x01';
      }
      puVar3 = puVar3 + 1;
      puVar5 = puVar5 + 1;
    } while (uVar4 != 0x10);
  }
  return;
}

