
ENGINE_CTRL_FUNC_PTR ENGINE_get_ctrl_function(ENGINE *e)

{
  return *(ENGINE_CTRL_FUNC_PTR *)(e + 0x40);
}

