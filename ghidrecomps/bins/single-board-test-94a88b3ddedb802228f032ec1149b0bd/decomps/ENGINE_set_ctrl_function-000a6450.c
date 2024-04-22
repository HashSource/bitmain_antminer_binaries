
int ENGINE_set_ctrl_function(ENGINE *e,ENGINE_CTRL_FUNC_PTR ctrl_f)

{
  *(ENGINE_CTRL_FUNC_PTR *)(e + 0x40) = ctrl_f;
  return 1;
}

