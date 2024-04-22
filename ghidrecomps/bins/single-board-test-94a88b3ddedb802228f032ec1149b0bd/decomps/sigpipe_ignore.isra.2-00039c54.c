
void sigpipe_ignore_isra_2(int param_1,sigaction *param_2)

{
  sigaction local_9c;
  
  *(char *)&param_2[1].__sigaction_handler = (char)param_1;
  if (param_1 == 0) {
    memset(param_2,0,0x8c);
    sigaction(0xd,(sigaction *)0x0,param_2);
    memcpy(&local_9c,param_2,0x8c);
    local_9c.__sigaction_handler = (_union_1051)0x1;
    sigaction(0xd,&local_9c,(sigaction *)0x0);
  }
  return;
}

