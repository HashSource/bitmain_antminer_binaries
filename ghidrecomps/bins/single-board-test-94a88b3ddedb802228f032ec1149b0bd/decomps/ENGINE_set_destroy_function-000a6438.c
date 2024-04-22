
int ENGINE_set_destroy_function(ENGINE *e,ENGINE_GEN_INT_FUNC_PTR destroy_f)

{
  *(ENGINE_GEN_INT_FUNC_PTR *)(e + 0x34) = destroy_f;
  return 1;
}

