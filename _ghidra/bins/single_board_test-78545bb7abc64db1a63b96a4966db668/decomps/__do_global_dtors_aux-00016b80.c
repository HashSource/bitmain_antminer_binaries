
void __do_global_dtors_aux(void)

{
  if (completed_8986 == '\0') {
    deregister_tm_clones();
    completed_8986 = '\x01';
  }
  return;
}

