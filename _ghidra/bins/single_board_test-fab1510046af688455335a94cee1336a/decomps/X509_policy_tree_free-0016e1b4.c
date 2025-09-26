
void X509_policy_tree_free(X509_POLICY_TREE *tree)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (tree == (X509_POLICY_TREE *)0x0) {
    return;
  }
  sk_free(*(_STACK **)(tree + 0xc));
  sk_pop_free(*(_STACK **)(tree + 0x10),(func *)0x16e1a5);
  if (0 < *(int *)(tree + 4)) {
    iVar2 = 0;
    puVar1 = *(undefined4 **)tree;
    do {
      iVar2 = iVar2 + 1;
      HintPreloadData(puVar1 + 0x15);
      if ((X509 *)*puVar1 != (X509 *)0x0) {
        X509_free((X509 *)*puVar1);
      }
      if ((_STACK *)puVar1[1] != (_STACK *)0x0) {
        sk_pop_free((_STACK *)puVar1[1],policy_node_free);
      }
      if ((void *)puVar1[2] != (void *)0x0) {
        policy_node_free((void *)puVar1[2]);
      }
      puVar1 = puVar1 + 4;
    } while (iVar2 < *(int *)(tree + 4));
  }
  if (*(_STACK **)(tree + 8) != (_STACK *)0x0) {
    sk_pop_free(*(_STACK **)(tree + 8),(func *)0x16e005);
  }
  CRYPTO_free(*(void **)tree);
  CRYPTO_free(tree);
  return;
}

