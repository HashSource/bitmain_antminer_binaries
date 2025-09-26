
void X509_policy_tree_free(X509_POLICY_TREE *tree)

{
  int iVar1;
  int iVar2;
  
  if (tree != (X509_POLICY_TREE *)0x0) {
    OPENSSL_sk_free(*(undefined4 *)(tree + 0xc));
    OPENSSL_sk_pop_free(*(undefined4 *)(tree + 0x10),0x178acd);
    if (0 < *(int *)(tree + 4)) {
      iVar2 = 0;
      iVar1 = *(int *)tree + 0x54;
      do {
        iVar2 = iVar2 + 1;
        X509_free(*(X509 **)(iVar1 + -0x54));
        HintPreloadData(iVar1);
        OPENSSL_sk_pop_free(*(undefined4 *)(iVar1 + -0x50),(undefined *)0x1d09f1);
        policy_node_free(*(undefined4 *)(iVar1 + -0x4c));
        iVar1 = iVar1 + 0x10;
      } while (iVar2 < *(int *)(tree + 4));
    }
    OPENSSL_sk_pop_free(*(undefined4 *)(tree + 8),0x1788cd);
    CRYPTO_free(*(void **)tree);
    CRYPTO_free(tree);
    return;
  }
  return;
}

