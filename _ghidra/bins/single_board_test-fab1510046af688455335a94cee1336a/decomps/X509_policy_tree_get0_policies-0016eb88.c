
stack_st_X509_POLICY_NODE * X509_policy_tree_get0_policies(X509_POLICY_TREE *tree)

{
  if (tree != (X509_POLICY_TREE *)0x0) {
    tree = *(X509_POLICY_TREE **)(tree + 0xc);
  }
  return (stack_st_X509_POLICY_NODE *)tree;
}

