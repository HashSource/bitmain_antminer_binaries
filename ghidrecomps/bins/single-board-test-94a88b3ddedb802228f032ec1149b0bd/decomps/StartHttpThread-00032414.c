
void StartHttpThread(void)

{
  pthread_attr_t pStack_38;
  pthread_t apStack_14 [3];
  
  apStack_14[2] = pthread_attr_init(&pStack_38);
  apStack_14[1] = 0x200000;
  apStack_14[2] = pthread_attr_setstacksize(&pStack_38,0x200000);
  apStack_14[2] = pthread_create(apStack_14,&pStack_38,(__start_routine *)0x32151,(void *)0x0);
  printf("httpListenThread start ret=%d\n",apStack_14[2]);
  return;
}

