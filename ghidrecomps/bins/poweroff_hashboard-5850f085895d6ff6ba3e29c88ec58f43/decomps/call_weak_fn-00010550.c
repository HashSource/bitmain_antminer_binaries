
void call_weak_fn(void)

{
  if (*(int *)(DAT_0001056c + 0x10560 + DAT_00010570) == 0) {
    return;
  }
  (*(code *)PTR___gmon_start___00021024)();
  return;
}

