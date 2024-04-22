
void SCT_LIST_free(_STACK *param_1)

{
  sk_pop_free(param_1,SCT_free + 1);
  return;
}

