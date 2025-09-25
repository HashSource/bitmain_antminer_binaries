
/* WARNING: Unknown calling convention */

int sweep_exit(void)

{
  if (ops.stop != (_func_int_varargs *)0x0) {
    (*ops.stop)();
  }
  return 0;
}

