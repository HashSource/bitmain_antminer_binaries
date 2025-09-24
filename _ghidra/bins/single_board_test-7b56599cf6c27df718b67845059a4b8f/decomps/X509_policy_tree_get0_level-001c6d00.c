
X509_POLICY_LEVEL * X509_policy_tree_get0_level(X509_POLICY_TREE *tree,int i)

{
  uint uVar1;
  
  uVar1 = (uint)i >> 0x1f;
  if (tree == (X509_POLICY_TREE *)0x0) {
    uVar1 = 1;
  }
  if (uVar1 == 0) {
    if (i < *(int *)(tree + 4)) {
      return (X509_POLICY_LEVEL *)(*(int *)tree + i * 0x10);
    }
    return (X509_POLICY_LEVEL *)0x0;
  }
  return (X509_POLICY_LEVEL *)0x0;
}

