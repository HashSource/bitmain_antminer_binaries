
X509_POLICY_NODE * X509_policy_node_get0_parent(X509_POLICY_NODE *node)

{
  if (node != (X509_POLICY_NODE *)0x0) {
    node = *(X509_POLICY_NODE **)(node + 4);
  }
  return node;
}

