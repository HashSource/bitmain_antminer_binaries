
int X509_policy_level_node_count(X509_POLICY_LEVEL *level)

{
  int iVar1;
  int iVar2;
  
  if (level != (X509_POLICY_LEVEL *)0x0) {
    iVar2 = *(int *)(level + 8);
    if (iVar2 != 0) {
      iVar2 = 1;
    }
    if (*(int *)(level + 4) != 0) {
      iVar1 = OPENSSL_sk_num(*(int *)(level + 4));
      iVar2 = iVar2 + iVar1;
    }
    return iVar2;
  }
  return 0;
}

