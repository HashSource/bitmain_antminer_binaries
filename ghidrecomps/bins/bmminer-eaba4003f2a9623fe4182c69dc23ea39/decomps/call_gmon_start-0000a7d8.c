
void call_gmon_start(void)

{
  if (*(int *)(DAT_0000a7e8 + 0xa7e0 + DAT_0000a7ec) == 0) {
    return;
  }
  (*(code *)PTR___gmon_start___00085208)();
  return;
}

