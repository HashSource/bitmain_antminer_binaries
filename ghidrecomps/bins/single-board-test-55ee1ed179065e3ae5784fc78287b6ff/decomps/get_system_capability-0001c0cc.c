
void get_system_capability(void *param_1)

{
  if (param_1 != (void *)0x0) {
    memcpy(param_1,capability,0x124);
  }
  return;
}

