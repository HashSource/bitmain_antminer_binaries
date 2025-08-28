
void sigpipe_restore(sigaction *param_1)

{
  if (*(char *)&param_1[1].__sigaction_handler == '\0') {
    sigaction(0xd,param_1,(sigaction *)0x0);
    return;
  }
  return;
}

