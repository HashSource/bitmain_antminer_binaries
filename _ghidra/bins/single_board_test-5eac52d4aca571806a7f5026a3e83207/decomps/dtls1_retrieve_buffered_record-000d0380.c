
undefined4 dtls1_retrieve_buffered_record(int param_1,int param_2)

{
  pitem *item;
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  
  item = pqueue_pop(*(pqueue *)(param_2 + 4));
  if (item != (pitem *)0x0) {
    piVar5 = (int *)item->data;
    SSL3_BUFFER_release(param_1 + 0x664);
    iVar1 = piVar5[1];
    *(int *)(param_1 + 0xef8) = *piVar5;
    *(int *)(param_1 + 0xefc) = iVar1;
    iVar1 = piVar5[2];
    iVar6 = piVar5[4];
    iVar7 = piVar5[5];
    *(int *)(param_1 + 0x668) = piVar5[3];
    *(int *)(param_1 + 0x664) = iVar1;
    *(int *)(param_1 + 0x66c) = iVar6;
    *(int *)(param_1 + 0x670) = iVar7;
    *(int *)(param_1 + 0x674) = piVar5[6];
    piVar2 = (int *)(param_1 + 0x8f8);
    piVar3 = piVar5 + 7;
    do {
      piVar4 = piVar3 + 4;
      iVar7 = piVar3[1];
      iVar1 = piVar3[2];
      iVar6 = piVar3[3];
      *piVar2 = *piVar3;
      piVar2[1] = iVar7;
      piVar2[2] = iVar1;
      piVar2[3] = iVar6;
      piVar2 = piVar2 + 4;
      piVar3 = piVar4;
    } while (piVar4 != piVar5 + 0x13);
    iVar1 = *piVar5;
    *(undefined4 *)(param_1 + 0xf22) = *(undefined4 *)(iVar1 + 5);
    *(undefined2 *)(param_1 + 0xf26) = *(undefined2 *)(iVar1 + 9);
    CRYPTO_free(item->data);
    pitem_free(item);
    return 1;
  }
  return 0;
}

