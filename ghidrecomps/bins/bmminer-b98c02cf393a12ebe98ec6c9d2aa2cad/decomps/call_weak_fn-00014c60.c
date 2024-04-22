
void call_weak_fn(void)

{
  if (*(int *)(DAT_00014c7c + 0x14c70 + DAT_00014c80) == 0) {
    return;
  }
  (*(code *)PTR___gmon_start___0007cf54)();
  return;
}

