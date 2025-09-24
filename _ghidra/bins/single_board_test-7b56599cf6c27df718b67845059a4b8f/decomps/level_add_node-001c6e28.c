
int * level_add_node(int param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int line;
  
  piVar1 = (int *)CRYPTO_zalloc(0xc,"crypto/x509v3/pcy_node.c",0x42);
  if (piVar1 == (int *)0x0) {
    ERR_put_error(0x22,0xa8,0x41,"crypto/x509v3/pcy_node.c",0x44);
    return (int *)0x0;
  }
  *piVar1 = param_2;
  piVar1[1] = param_3;
  if (param_1 == 0) {
LAB_001c6e6e:
    if (param_4 == 0) goto LAB_001c6e82;
    iVar2 = *(int *)(param_4 + 8);
    if (iVar2 == 0) {
      iVar2 = OPENSSL_sk_new_null();
      *(int *)(param_4 + 8) = iVar2;
      if (iVar2 == 0) {
        line = 0x61;
        goto LAB_001c6ea2;
      }
    }
    iVar2 = OPENSSL_sk_push(iVar2,param_2);
    if (iVar2 != 0) {
LAB_001c6e82:
      if (param_3 != 0) {
        *(int *)(param_3 + 8) = *(int *)(param_3 + 8) + 1;
      }
      return piVar1;
    }
    line = 0x65;
  }
  else {
    iVar2 = OBJ_obj2nid(*(ASN1_OBJECT **)(param_2 + 4));
    if (iVar2 == 0x2ea) {
      if (*(int *)(param_1 + 8) != 0) goto LAB_001c6eae;
      *(int **)(param_1 + 8) = piVar1;
      goto LAB_001c6e6e;
    }
    iVar2 = *(int *)(param_1 + 4);
    if (iVar2 == 0) {
      iVar2 = policy_node_cmp_new();
      line = 0x53;
      *(int *)(param_1 + 4) = iVar2;
      if (iVar2 != 0) goto LAB_001c6e66;
    }
    else {
LAB_001c6e66:
      iVar2 = OPENSSL_sk_push(iVar2,piVar1);
      if (iVar2 != 0) goto LAB_001c6e6e;
      line = 0x57;
    }
  }
LAB_001c6ea2:
  ERR_put_error(0x22,0xa8,0x41,"crypto/x509v3/pcy_node.c",line);
LAB_001c6eae:
  policy_node_free(piVar1);
  return (int *)0x0;
}

