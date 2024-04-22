
void call_weak_fn(void)

{
  if (*(int *)(DAT_00011134 + 0x11128 + DAT_00011138) == 0) {
    return;
  }
  (*(code *)PTR___gmon_start___000473c4)();
  return;
}

