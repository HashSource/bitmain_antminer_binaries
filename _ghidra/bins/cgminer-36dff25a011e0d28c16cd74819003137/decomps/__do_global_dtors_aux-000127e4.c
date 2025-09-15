
void __do_global_dtors_aux(void)

{
  if (completed_10499 != '\0') {
    return;
  }
  deregister_tm_clones();
  completed_10499 = 1;
  return;
}

