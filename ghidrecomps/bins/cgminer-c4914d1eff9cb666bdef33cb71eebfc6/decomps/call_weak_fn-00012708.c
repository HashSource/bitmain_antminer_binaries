
void call_weak_fn(void)

{
  if (*(int *)(DAT_00012724 + 0x12718 + DAT_00012728) == 0) {
    return;
  }
  (*(code *)PTR___gmon_start___000a8138)();
  return;
}

