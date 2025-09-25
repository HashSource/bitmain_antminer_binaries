
int tls1_alert_code(uint param_1)

{
  if (param_1 < 0x79) {
    return (int)(char)(&CSWTCH_21)[param_1];
  }
  return -1;
}

