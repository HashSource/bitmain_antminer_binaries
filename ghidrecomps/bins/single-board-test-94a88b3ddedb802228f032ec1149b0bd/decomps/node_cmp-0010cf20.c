
void node_cmp(int **param_1,int **param_2)

{
  OBJ_cmp(*(ASN1_OBJECT **)(**param_1 + 4),*(ASN1_OBJECT **)(**param_2 + 4));
  return;
}

