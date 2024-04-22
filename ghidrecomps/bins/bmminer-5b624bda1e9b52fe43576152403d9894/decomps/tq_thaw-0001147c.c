
/* WARNING: Unknown calling convention */

void tq_thaw(thread_q *tq)

{
  tq_freezethaw(tq,false);
  return;
}

