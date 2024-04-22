
void StartHttpThread(void)

{
  pthread_attr_t pStack_38;
  pthread_t pStack_14;
  undefined4 local_10;
  int local_c;
  
  local_c = pthread_attr_init(&pStack_38);
  local_10 = 0x200000;
  local_c = pthread_attr_setstacksize(&pStack_38,0x200000);
  local_c = pthread_create(&pStack_14,&pStack_38,httpListenThread + 1,(void *)0x0);
  printf("httpListenThread start ret=%d\n",local_c);
  return;
}

