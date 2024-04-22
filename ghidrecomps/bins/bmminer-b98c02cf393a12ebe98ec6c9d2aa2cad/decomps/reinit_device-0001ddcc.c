
void reinit_device(int param_1)

{
  if (*(int *)(param_1 + 0x20) != 1) {
    reinit_device_part_38();
    return;
  }
  return;
}

