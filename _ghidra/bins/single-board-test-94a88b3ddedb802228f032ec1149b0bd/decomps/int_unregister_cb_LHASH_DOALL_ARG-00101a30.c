
void int_unregister_cb_LHASH_DOALL_ARG(int param_1,void *param_2)

{
  int loc;
  
  while (loc = sk_find(*(_STACK **)(param_1 + 4),param_2), -1 < loc) {
    sk_delete(*(_STACK **)(param_1 + 4),loc);
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  if (param_2 != *(void **)(param_1 + 8)) {
    return;
  }
  engine_unlocked_finish(param_2,0);
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}

