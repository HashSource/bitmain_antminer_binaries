
void call_weak_fn(void)

{
  if (*(int *)(DAT_000111b4 + 0x111a8 + DAT_000111b8) == 0) {
    return;
  }
  (*(code *)PTR___gmon_start___00046e44)();
  return;
}

