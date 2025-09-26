
void tls13_alert_code(int param_1)

{
  if (param_1 == 0x74 || param_1 == 0x6d) {
    return;
  }
  tls1_alert_code();
  return;
}

