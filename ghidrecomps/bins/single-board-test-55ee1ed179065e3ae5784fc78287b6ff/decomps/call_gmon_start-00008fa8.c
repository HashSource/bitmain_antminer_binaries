
void call_gmon_start(void)

{
  if (*(int *)(DAT_00008fb8 + 0x8fb0 + DAT_00008fbc) == 0) {
    return;
  }
  (*(code *)PTR___gmon_start___000354ac)();
  return;
}

