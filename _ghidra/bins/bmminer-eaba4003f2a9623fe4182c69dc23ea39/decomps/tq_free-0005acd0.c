
void tq_free(thread_q *tq)

{
  list_head *plVar1;
  thread_q *tq_local;
  tq_ent *iter;
  tq_ent *ent;
  
  if (tq != (thread_q *)0x0) {
    plVar1 = (tq->q).next;
    ent = (tq_ent *)&plVar1[-1].prev;
    plVar1 = plVar1->next;
    while (iter = (tq_ent *)&plVar1[-1].prev, (thread_q *)&ent->q_node != tq) {
      list_del(&ent->q_node);
      free(ent);
      ent = iter;
      plVar1 = plVar1->next;
    }
    pthread_cond_destroy((pthread_cond_t *)&tq->cond);
    pthread_mutex_destroy((pthread_mutex_t *)&tq->mutex);
    memset(tq,0,0x58);
    free(tq);
  }
  return;
}

