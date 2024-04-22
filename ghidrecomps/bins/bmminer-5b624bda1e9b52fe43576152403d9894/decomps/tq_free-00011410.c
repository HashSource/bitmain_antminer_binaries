
/* WARNING: Unknown calling convention */

void tq_free(thread_q *tq)

{
  thread_q *ptVar1;
  thread_q *ptVar2;
  thread_q *ptVar3;
  list_head *plVar4;
  tq_ent *ent;
  tq_ent *iter;
  
  if (tq == (thread_q *)0x0) {
    return;
  }
  ptVar3 = (thread_q *)(tq->q).next;
  ptVar2 = (thread_q *)(ptVar3->q).next;
  while (ptVar1 = ptVar2, tq != ptVar3) {
    plVar4 = (ptVar3->q).prev;
    (ptVar1->q).prev = plVar4;
    plVar4->next = &ptVar1->q;
    (ptVar3->q).prev = (list_head *)0x0;
    (ptVar3->q).next = (list_head *)0x0;
    free((void *)((int)&ptVar3[-1].cond + 0x2c));
    ptVar2 = (thread_q *)(ptVar1->q).next;
    ptVar3 = ptVar1;
  }
  pthread_cond_destroy((pthread_cond_t *)&tq->cond);
  pthread_mutex_destroy((pthread_mutex_t *)&tq->mutex);
  memset(tq,0,0x58);
                    /* WARNING: Could not recover jumptable at 0x0000a260. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_LAB_0005f208)(tq);
  return;
}

