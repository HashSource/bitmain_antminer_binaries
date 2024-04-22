
void software_set_address(void)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  char acStack_820 [2048];
  
  if ((opt_debug != '\0') &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
    snprintf(acStack_820,0x800,"--- %s\n",DAT_00034464);
    _applog(7,acStack_820,0);
  }
  iVar3 = dev;
  uVar4 = 0;
  *(undefined *)(dev + 0x542d) = 3;
  while( true ) {
    if ((*(int *)(iVar3 + (uVar4 + 2) * 4) == 1) && (*(char *)(iVar3 + uVar4 + 0x53ec) != '\0')) {
      uVar5 = uVar4 & 0xff;
      cVar2 = '\0';
      uVar6 = 0;
      chain_inactive(uVar5);
      cgsleep_ms(0x1e);
      chain_inactive(uVar5);
      cgsleep_ms(0x1e);
      chain_inactive(uVar5);
      cgsleep_ms(0x1e);
      do {
        uVar6 = uVar6 + 1;
        set_address(uVar5,0,cVar2);
        cVar2 = *(char *)(dev + 0x542d) + cVar2;
        cgsleep_ms(0x1e);
        uVar1 = __aeabi_idiv(0x100,*(undefined *)(dev + 0x542d));
      } while (uVar6 < uVar1);
    }
    iVar3 = dev;
    if (uVar4 == 0xf) break;
    uVar4 = uVar4 + 1;
    dev = iVar3;
  }
  dev = iVar3;
  return;
}

