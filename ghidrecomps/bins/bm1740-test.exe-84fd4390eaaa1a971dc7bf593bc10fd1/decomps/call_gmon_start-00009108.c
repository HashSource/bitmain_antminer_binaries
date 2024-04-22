
void call_gmon_start(void)

{
  if (*(int *)(DAT_00009118 + 0x9110 + DAT_0000911c) == 0) {
    return;
  }
  (*(code *)PTR___gmon_start___00030194)();
  return;
}

