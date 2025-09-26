
void tls1_clear(undefined4 *param_1)

{
  ssl3_clear();
  *param_1 = *(undefined4 *)param_1[2];
  return;
}

