
void X509_policy_tree_free(X509_POLICY_TREE *tree)

{
  X509 **ppXVar1;
  int iVar2;
  
  if (tree == (X509_POLICY_TREE *)0x0) {
    return;
  }
  sk_free(*(_STACK **)(tree + 0xc));
  sk_pop_free(*(_STACK **)(tree + 0x10),DAT_000cd928);
  if (0 < *(int *)(tree + 4)) {
    iVar2 = 0;
    ppXVar1 = *(X509 ***)tree;
    do {
      iVar2 = iVar2 + 1;
      HintPreloadData(ppXVar1 + 0x15);
      if (*ppXVar1 != (X509 *)0x0) {
        X509_free(*ppXVar1);
      }
      if (ppXVar1[1] != (X509 *)0x0) {
        sk_pop_free((_STACK *)ppXVar1[1],DAT_000cd92c);
      }
      if (ppXVar1[2] != (X509 *)0x0) {
        policy_node_free(ppXVar1[2]);
      }
      ppXVar1 = ppXVar1 + 4;
    } while (iVar2 < *(int *)(tree + 4));
  }
  if (*(_STACK **)(tree + 8) != (_STACK *)0x0) {
    sk_pop_free(*(_STACK **)(tree + 8),DAT_000cd930);
  }
  CRYPTO_free(*(void **)tree);
  CRYPTO_free(tree);
  return;
}

