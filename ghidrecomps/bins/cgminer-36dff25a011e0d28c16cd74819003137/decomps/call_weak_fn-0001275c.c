
void call_weak_fn(void)

{
  if (*(int *)(DAT_00012778 + 0x1276c + DAT_0001277c) == 0) {
    return;
  }
  (*(code *)PTR___gmon_start___000c0138)();
  return;
}

