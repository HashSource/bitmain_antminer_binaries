
undefined4 dtls1_retransmit_buffered_messages(int param_1)

{
  pitem *ppVar1;
  int iVar2;
  pitem *local_20;
  int local_1c [2];
  
  local_1c[0] = 0;
  local_20 = pqueue_iterator(*(pqueue *)(*(int *)(param_1 + 0x5c) + 0x248));
  do {
    ppVar1 = pqueue_next(&local_20);
    if (ppVar1 == (pitem *)0x0) {
      return 1;
    }
    iVar2 = dtls1_retransmit_message
                      (param_1,(uint)*(ushort *)((int)ppVar1->data + 8) * 2 -
                               *(int *)((int)ppVar1->data + 0x14) & 0xffff,0,local_1c);
  } while ((0 < iVar2) || (local_1c[0] == 0));
  fwrite(DAT_000791fc,1,0x22,*DAT_000791f8);
  return 0xffffffff;
}

