
void call_weak_fn(void)

{
  if (*(int *)(DAT_00010ce4 + 0x10cd8 + DAT_00010ce8) == 0) {
    return;
  }
  (*(code *)PTR___gmon_start___0003016c)();
  return;
}

