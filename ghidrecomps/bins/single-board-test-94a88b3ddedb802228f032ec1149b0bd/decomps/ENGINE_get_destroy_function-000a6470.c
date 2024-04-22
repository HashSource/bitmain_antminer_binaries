
ENGINE_GEN_INT_FUNC_PTR ENGINE_get_destroy_function(ENGINE *e)

{
  return *(ENGINE_GEN_INT_FUNC_PTR *)(e + 0x34);
}

