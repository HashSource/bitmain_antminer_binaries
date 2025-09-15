
/* WARNING: Unknown calling convention */

void tq_freeze(thread_q *tq)

{
  tq_freezethaw(tq,true);
  return;
}

