
void DTLS_RECORD_LAYER_clear(int param_1)

{
  pitem *ppVar1;
  undefined4 uVar2;
  void *__s;
  undefined4 uVar3;
  undefined4 uVar4;
  
  __s = *(void **)(param_1 + 0x8e8);
  while (ppVar1 = pqueue_pop(*(pqueue *)((int)__s + 0x20)), ppVar1 != (pitem *)0x0) {
    CRYPTO_free(*(void **)((int)ppVar1->data + 8));
    CRYPTO_free(ppVar1->data);
    pitem_free(ppVar1);
  }
  while (ppVar1 = pqueue_pop(*(pqueue *)((int)__s + 0x28)), ppVar1 != (pitem *)0x0) {
    CRYPTO_free(*(void **)((int)ppVar1->data + 8));
    CRYPTO_free(ppVar1->data);
    pitem_free(ppVar1);
  }
  while (ppVar1 = pqueue_pop(*(pqueue *)((int)__s + 0x30)), ppVar1 != (pitem *)0x0) {
    CRYPTO_free(*(void **)((int)ppVar1->data + 8));
    CRYPTO_free(ppVar1->data);
    pitem_free(ppVar1);
  }
  uVar4 = *(undefined4 *)((int)__s + 0x20);
  uVar3 = *(undefined4 *)((int)__s + 0x28);
  uVar2 = *(undefined4 *)((int)__s + 0x30);
  memset(__s,0,0x44);
  *(undefined4 *)((int)__s + 0x20) = uVar4;
  *(undefined4 *)((int)__s + 0x28) = uVar3;
  *(undefined4 *)((int)__s + 0x30) = uVar2;
  return;
}

