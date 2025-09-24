
undefined4 dtls1_retransmit_buffered_messages(int param_1)

{
  undefined2 uVar1;
  pitem *ppVar2;
  int iVar3;
  pitem *local_18;
  undefined4 local_14;
  
  local_14 = 0;
  local_18 = pqueue_iterator(*(pqueue *)(*(int *)(param_1 + 0x80) + 0x114));
  ppVar2 = pqueue_next(&local_18);
  while( true ) {
    if (ppVar2 == (pitem *)0x0) {
      return 1;
    }
    uVar1 = dtls1_get_queue_priority
                      (*(undefined2 *)((int)ppVar2->data + 8),
                       *(undefined4 *)((int)ppVar2->data + 0x14));
    iVar3 = dtls1_retransmit_message(param_1,uVar1,&local_14);
    if (iVar3 < 1) break;
    ppVar2 = pqueue_next(&local_18);
  }
  return 0xffffffff;
}

