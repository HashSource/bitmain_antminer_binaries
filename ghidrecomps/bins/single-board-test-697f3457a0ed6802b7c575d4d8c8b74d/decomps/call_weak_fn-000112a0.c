
void call_weak_fn(void)

{
  if (*(int *)(DAT_000112bc + 0x112b0 + DAT_000112c0) == 0) {
    return;
  }
  (*(code *)PTR___gmon_start___00047924)();
  return;
}

