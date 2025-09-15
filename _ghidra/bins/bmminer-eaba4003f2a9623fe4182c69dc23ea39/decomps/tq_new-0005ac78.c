
/* WARNING: Unknown calling convention */

thread_q * tq_new(void)

{
  thread_q *ptVar1;
  thread_q *tq;
  
  ptVar1 = (thread_q *)_cgcalloc(1,0x58,"util.c","tq_new",0x435);
  (ptVar1->q).next = (list_head *)ptVar1;
  (ptVar1->q).prev = (list_head *)ptVar1;
  pthread_mutex_init((pthread_mutex_t *)&ptVar1->mutex,(pthread_mutexattr_t *)0x0);
  pthread_cond_init((pthread_cond_t *)&ptVar1->cond,(pthread_condattr_t *)0x0);
  return ptVar1;
}

