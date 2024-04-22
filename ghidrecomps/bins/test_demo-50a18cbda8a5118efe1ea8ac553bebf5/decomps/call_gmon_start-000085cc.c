
void call_gmon_start(void)

{
  if (*(int *)(DAT_000085dc + 0x85d4 + DAT_000085e0) == 0) {
    return;
  }
  (*(code *)PTR___gmon_start___00011748)();
  return;
}

