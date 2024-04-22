
void call_weak_fn(void)

{
  if (*(int *)(DAT_000109b4 + 0x109a8 + DAT_000109b8) == 0) {
    return;
  }
  (*(code *)PTR___gmon_start___00023d28)();
  return;
}

