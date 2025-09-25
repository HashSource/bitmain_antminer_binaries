
int ENGINE_set_init_function(ENGINE *e,ENGINE_GEN_INT_FUNC_PTR init_f)

{
  *(ENGINE_GEN_INT_FUNC_PTR *)(e + 0x30) = init_f;
  return 1;
}

