
void int_unregister_cb(int param_1,int param_2)

{
  int iVar1;
  
  while (iVar1 = OPENSSL_sk_find(*(undefined4 *)(param_1 + 4),param_2), -1 < iVar1) {
    OPENSSL_sk_delete(*(undefined4 *)(param_1 + 4));
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  if (param_2 != *(int *)(param_1 + 8)) {
    return;
  }
  engine_unlocked_finish(param_2,0);
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}

