
X509_POLICY_LEVEL * X509_policy_tree_get0_level(X509_POLICY_TREE *tree,int i)

{
  int iVar1;
  
  iVar1 = 1 - (int)tree;
  if ((X509_POLICY_TREE *)0x1 < tree) {
    iVar1 = 0;
  }
  if (iVar1 == 0 && -1 < i) {
    if (i < *(int *)(tree + 4)) {
      return (X509_POLICY_LEVEL *)(*(int *)tree + i * 0x10);
    }
    return (X509_POLICY_LEVEL *)0x0;
  }
  return (X509_POLICY_LEVEL *)0x0;
}

