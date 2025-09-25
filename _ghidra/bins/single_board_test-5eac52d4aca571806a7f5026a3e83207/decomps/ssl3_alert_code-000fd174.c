
int ssl3_alert_code(uint param_1)

{
  if (param_1 < 0x79) {
    return (int)(char)(&CSWTCH_23)[param_1];
  }
  return -1;
}

