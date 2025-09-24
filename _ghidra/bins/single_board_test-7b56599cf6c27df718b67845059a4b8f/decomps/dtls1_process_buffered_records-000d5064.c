
undefined4 dtls1_process_buffered_records(int param_1)

{
  pitem *ppVar1;
  int iVar2;
  int iVar3;
  short *psVar4;
  undefined1 auStack_1c [4];
  
  ppVar1 = pqueue_peek(*(pqueue *)(*(int *)(param_1 + 0xf38) + 0x20));
  if (ppVar1 != (pitem *)0x0) {
    psVar4 = *(short **)(param_1 + 0xf38);
    if ((psVar4[0xe] != *psVar4) || (*(int *)(param_1 + 0x674) != 0)) {
      return 1;
    }
    while (ppVar1 = pqueue_peek(*(pqueue *)(psVar4 + 0x10)), ppVar1 != (pitem *)0x0) {
      dtls1_retrieve_buffered_record(param_1,*(int *)(param_1 + 0xf38) + 0x1c);
      iVar2 = dtls1_get_bitmap(param_1,param_1 + 0x8f8,auStack_1c);
      if (iVar2 == 0) {
        ossl_statem_fatal(param_1,0x50,0x1a8,0x44,"ssl/record/rec_layer_d1.c",0x10b);
        return 0;
      }
      iVar3 = dtls1_record_replay_check(param_1,iVar2);
      if ((iVar3 == 0) || (iVar2 = dtls1_process_record(param_1,iVar2), iVar2 == 0)) {
        iVar2 = ossl_statem_in_error(param_1);
        if (iVar2 != 0) {
          return 0xffffffff;
        }
        *(undefined4 *)(param_1 + 0x900) = 0;
        *(undefined4 *)(param_1 + 0xefc) = 0;
      }
      else {
        iVar2 = dtls1_buffer_record(param_1,*(int *)(param_1 + 0xf38) + 0x24,param_1 + 0x920);
        if (iVar2 < 0) {
          return 0;
        }
      }
      psVar4 = *(short **)(param_1 + 0xf38);
    }
  }
  psVar4 = *(short **)(param_1 + 0xf38);
  psVar4[0x12] = *psVar4;
  psVar4[0xe] = *psVar4 + 1;
  return 1;
}

