
void software_set_address_onChain(undefined param_1)

{
  char cVar1;
  int local_c;
  
  cVar1 = '\0';
  chain_inactive(param_1);
  usleep(5000);
  for (local_c = 0; local_c < 0x80; local_c = local_c + 1) {
    set_address(param_1,0,cVar1);
    cVar1 = cVar1 + '\x02';
    usleep(5000);
  }
  return;
}

