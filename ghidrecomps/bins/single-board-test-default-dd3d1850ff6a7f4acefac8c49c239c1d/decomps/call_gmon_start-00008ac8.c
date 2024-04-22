
void call_gmon_start(void)

{
  if (*(int *)(DAT_00008ad8 + 0x8ad0 + DAT_00008adc) == 0) {
    return;
  }
  (*(code *)PTR___gmon_start___0002515c)();
  return;
}

