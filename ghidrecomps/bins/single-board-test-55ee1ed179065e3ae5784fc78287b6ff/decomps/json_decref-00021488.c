
void json_decref(int param_1)

{
  if ((param_1 != 0) && (*(int *)(param_1 + 4) != -1)) {
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -1;
    if (*(int *)(param_1 + 4) == 0) {
      json_delete(param_1);
    }
  }
  return;
}

