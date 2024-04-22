
void __do_global_dtors_aux(void)

{
  char *pcVar1;
  
  pcVar1 = DAT_0000d16c;
  if (*DAT_0000d16c == '\0') {
    deregister_tm_clones();
    *pcVar1 = '\x01';
  }
  return;
}

