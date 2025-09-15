
void tq_freeze(thread_q *tq)

{
  thread_q *tq_local;
  
  tq_freezethaw(tq,true);
  return;
}

