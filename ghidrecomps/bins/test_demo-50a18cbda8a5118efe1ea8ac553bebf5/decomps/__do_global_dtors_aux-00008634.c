
void __do_global_dtors_aux(void)

{
  if (completed_8605 == '\0') {
    deregister_tm_clones();
    completed_8605 = '\x01';
  }
  return;
}

