
/* WARNING: Unknown calling convention */

_Bool aging_is_ongoing(void)

{
  return !aging_info.is_aging_finished;
}

