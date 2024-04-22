
void call_gmon_start(void)

{
  if (*(int *)(DAT_0000d100 + 0xd0f8 + DAT_0000d104) == 0) {
    return;
  }
  (*(code *)PTR___gmon_start___0005f17c)();
  return;
}

