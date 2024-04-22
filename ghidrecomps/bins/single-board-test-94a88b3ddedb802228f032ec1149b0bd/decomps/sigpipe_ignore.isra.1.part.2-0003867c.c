
void sigpipe_ignore_isra_1_part_2(sigaction *param_1)

{
  sigaction local_9c;
  
  memset(param_1,0,0x8c);
  sigaction(0xd,(sigaction *)0x0,param_1);
  memcpy(&local_9c,param_1,0x8c);
  local_9c.__sigaction_handler = (_union_1051)0x1;
  sigaction(0xd,&local_9c,(sigaction *)0x0);
  return;
}

