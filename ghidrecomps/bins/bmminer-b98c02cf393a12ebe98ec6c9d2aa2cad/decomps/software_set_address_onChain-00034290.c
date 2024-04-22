
void software_set_address_onChain(undefined param_1)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  char acStack_818 [2048];
  
  if ((opt_debug != '\0') &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
    snprintf(acStack_818,0x800,"--- %s\n",DAT_00034360);
    _applog(7,acStack_818,0);
  }
  cVar2 = '\0';
  *(undefined *)(dev + 0x542d) = 3;
  uVar3 = 0;
  chain_inactive(param_1);
  cgsleep_ms(0x1e);
  chain_inactive(param_1);
  cgsleep_ms(0x1e);
  chain_inactive(param_1);
  cgsleep_ms(0x1e);
  do {
    uVar3 = uVar3 + 1;
    set_address(param_1,0,cVar2);
    cVar2 = *(char *)(dev + 0x542d) + cVar2;
    cgsleep_ms(0x1e);
    uVar1 = __aeabi_idiv(0x100,*(undefined *)(dev + 0x542d));
  } while (uVar3 < uVar1);
  return;
}

