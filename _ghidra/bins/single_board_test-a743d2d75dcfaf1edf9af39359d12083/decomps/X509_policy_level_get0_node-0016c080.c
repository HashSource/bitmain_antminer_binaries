
X509_POLICY_NODE * X509_policy_level_get0_node(X509_POLICY_LEVEL *level,int i)

{
  X509_POLICY_NODE *pXVar1;
  
  if (level == (X509_POLICY_LEVEL *)0x0) {
    return (X509_POLICY_NODE *)0x0;
  }
  if (*(X509_POLICY_NODE **)(level + 8) != (X509_POLICY_NODE *)0x0) {
    if (i == 0) {
      return *(X509_POLICY_NODE **)(level + 8);
    }
    i = i + -1;
  }
  pXVar1 = (X509_POLICY_NODE *)sk_value(*(_STACK **)(level + 4),i);
  return pXVar1;
}

