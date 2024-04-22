
void __do_global_dtors_aux(void)

{
  char *pcVar1;
  
  pcVar1 = DAT_00009024;
  if (*DAT_00009024 == '\0') {
    deregister_tm_clones();
    *pcVar1 = '\x01';
  }
  return;
}

